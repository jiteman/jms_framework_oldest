///////////////////////////////////////////////////////////////////////////////
// EAGeneralAllocatorDebugWin64
//
// Copyright (c) 2005, Electronic Arts. All Rights Reserved.
// By Paul Pedriana, Maxis
//
// This module implements a platform-specific call stack functionality. 
///////////////////////////////////////////////////////////////////////////////

#include <PPMalloc/internal/config.h>
#include <PPMalloc/internal/callstack.h>

#if !PPM_USE_EATHREAD_CALLSTACK

#include "EA/StdC/EAFixedPoint.h"
#include <PPMalloc/internal/dllinfo.h>
#include <stddef.h>
#include <stdio.h>


#if defined(_WIN32_WINNT) && (_WIN32_WINNT < 0x0500)
     #undef  _WIN32_WINNT
     #define _WIN32_WINNT 0x0500
#endif


#ifdef _MSC_VER
    #pragma warning(push, 0)
    #include <Windows.h>
    #include <math.h>       // VS2008 has an acknowledged bug that requires math.h (and possibly also string.h) to be #included before intrin.h.
    #include <intrin.h>
    #pragma intrinsic(_ReturnAddress)
    #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
        #include <winternl.h>
    #else
        // Temporary while waiting for formal support:
        extern "C" NTSYSAPI PEXCEPTION_ROUTINE NTAPI RtlVirtualUnwind(DWORD, DWORD64, DWORD64, PRUNTIME_FUNCTION, PCONTEXT, PVOID*, PDWORD64, PKNONVOLATILE_CONTEXT_POINTERS);
        extern "C" WINBASEAPI DWORD WINAPI GetModuleFileNameA(HMODULE, LPSTR, DWORD);
    #endif
    #pragma warning(pop)
#else
    #include <Windows.h>
    #include <winternl.h>
#endif


// Disable optimization of this code under VC++ for x64.
// This is due to some as-yet undetermined crash that happens  
// when compiler optimizations are enabled for this code.
// This function is not performance-sensitive and so disabling 
// optimizations shouldn't matter.
#if defined(_MSC_VER) && (defined(_M_AMD64) || defined(_WIN64))
    #pragma optimize("", off) 
#endif


///////////////////////////////////////////////////////////////////////////////
// Stuff that is supposed to be in windows.h and/or winternl.h but isn't
// consistently present in all versions.
//
#ifndef UNW_FLAG_NHANDLER
    #define UNW_FLAG_NHANDLER 0
#endif

#ifndef UNWIND_HISTORY_TABLE_SIZE
    extern "C"
    {
        #define UNWIND_HISTORY_TABLE_SIZE    12
        #define UNWIND_HISTORY_TABLE_NONE     0
        #define UNWIND_HISTORY_TABLE_GLOBAL   1
        #define UNWIND_HISTORY_TABLE_LOCAL    2

        typedef struct _UNWIND_HISTORY_TABLE_ENTRY
        {
            ULONG64 ImageBase;
            PRUNTIME_FUNCTION FunctionEntry;
        } UNWIND_HISTORY_TABLE_ENTRY, *PUNWIND_HISTORY_TABLE_ENTRY;


        typedef struct _UNWIND_HISTORY_TABLE
        {
            ULONG Count;
            UCHAR Search;
            ULONG64 LowAddress;
            ULONG64 HighAddress;
            UNWIND_HISTORY_TABLE_ENTRY Entry[UNWIND_HISTORY_TABLE_SIZE];
        } UNWIND_HISTORY_TABLE, *PUNWIND_HISTORY_TABLE;


        PVOID WINAPI RtlLookupFunctionEntry(ULONG64 ControlPC, PULONG64 ImageBase, PUNWIND_HISTORY_TABLE HistoryTable);

        #if !defined(_MSC_VER) || (_MSC_VER < 1500) // if earlier than VS2008...
            typedef struct _KNONVOLATILE_CONTEXT_POINTERS
            { 
                PULONGLONG dummy; 
            } KNONVOLATILE_CONTEXT_POINTERS, *PKNONVOLATILE_CONTEXT_POINTERS; 

            typedef struct _FRAME_POINTERS
            {
                ULONGLONG MemoryStackFp;
                ULONGLONG BackingStoreFp;
            } FRAME_POINTERS, *PFRAME_POINTERS;

            ULONGLONG WINAPI RtlVirtualUnwind(ULONG HandlerType, ULONGLONG ImageBase, ULONGLONG ControlPC, 
                                                      PRUNTIME_FUNCTION FunctionEntry, PCONTEXT ContextRecord, PBOOLEAN InFunction, 
                                                      PFRAME_POINTERS EstablisherFrame, PKNONVOLATILE_CONTEXT_POINTERS ContextPointers);
        #endif
    }
#endif
///////////////////////////////////////////////////////////////////////////////


#if defined(EA_PLATFORM_MICROSOFT) && (EA_PLATFORM_PTR_SIZE == 8)


namespace EA
{
    namespace Allocator
    {
        #if !EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
            // GetRSP
            //
            // Returns the RSP of the caller.
            // 
            static EA_NO_INLINE void* GetRSP()
            {
                #if defined(_MSC_VER)
                    uintptr_t ara = (uintptr_t)_AddressOfReturnAddress();
                #else
                    uintptr_t ara = (uintptr_t)__builtin_frame_address();
                #endif
                return (void*)(ara + 8);
            }

            static EA_NO_INLINE void GetInstructionPointer(void*& pInstruction)
            {
                #if defined(_MSC_VER)
                    pInstruction = _ReturnAddress();
                #elif defined(__GNUC__)
                    pInstruction = __builtin_return_address(0);
                #else
                    void* pReturnAddressArray[2] = { 0, 0 };

                    GetCallstack(pReturnAddressArray, 2, NULL);
                    pInstruction = pReturnAddressArray[1]; // This is the address of the caller.
                #endif
            }
        #endif


        PPM_API void InitCallstack()
        {
            // Empty
        }


        PPM_API void ShutdownCallstack()
        {
            // Empty
        }


        // GetCallStack
        // Returns number of non-zero entries written. The return value may be zero.
        // Note that the memory size of the entries is thus the return value * sizeof(void).
        // The first entry in the returned array is the return address of the calling function;
        // the second entry is the returned addess of the first entry's calling function, etc.
        // Due to the complications that are often involved in doing stack traces, this function
        // may return addresses that are invalid (NULL pointers or otherwise). The user should 
        // be prepared for this and gracefully deal with such addresses.
        //
        // See EACallstack/EACallsack_Win64.cpp for a discussion about Win64 stack unwinding.
        //
        PPM_API size_t GetCallStack(void* pReturnAddressArray[], size_t nReturnAddressArrayCapacity)
        {
            CONTEXT           context;
            PRUNTIME_FUNCTION pRuntimeFunction;
            ULONG64           nImageBase;
            size_t            nFrameIndex;

            // To consider: Don't call the RtlCaptureContext function for EA_WINAPI_PARTITION_DESKTOP and 
            // instead use the simpler version below it which writes Rip/Rsp/Rbp. RtlCaptureContext is much 
            // slower. We need to verify that the 'quality' and extent of returned callstacks is good for 
            // the simpler version before using it exclusively.
            #if defined(EA_PLATFORM_WINDOWS) && EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
                // Apparently there is no need to memset the context struct.
                context.ContextFlags = CONTEXT_ALL; // Actually we should need only CONTEXT_INTEGER, so let's test that next chance we get.
                RtlCaptureContext(&context);
            #else
                void* ip = NULL;
                GetInstructionPointer(ip);
                context.Rip          = (uintptr_t)ip;
                context.Rsp          = (uintptr_t)GetRSP();
                context.Rbp          = 0; // RBP isn't actually needed for stack unwinding on x64, and don't typically need to use it in generated code, as the instruction set provides an efficient way to read/write via rsp offsets. Also, when frame pointers are omitted in the compiler settings then ebp won't be used.
                context.ContextFlags = CONTEXT_CONTROL;
            #endif

            // The following loop intentionally skips the first call stack frame because 
            // that frame corresponds this function (GetCallstack).
            for(nFrameIndex = 0; context.Rip && (nFrameIndex < nReturnAddressArrayCapacity); )
            {
                // Try to look up unwind metadata for the current function.
                pRuntimeFunction = (PRUNTIME_FUNCTION)RtlLookupFunctionEntry(context.Rip, &nImageBase, NULL /*&unwindHistoryTable*/);

                if(pRuntimeFunction)
                {
                    #if EA_WINAPI_FAMILY_PARTITION(EA_WINAPI_PARTITION_DESKTOP)
                        #if !defined(_MSC_VER) || (_MSC_VER < 1500) // If earlier than VS2008, we have different code because the VS2005 definition is broken (it defines the IA64 version, not the x64 version).
                            BOOLEAN        handlerData = 0;
                            FRAME_POINTERS establisherFramePointers = { 0, 0 };

                            RtlVirtualUnwind(UNW_FLAG_NHANDLER, nImageBase, context.Rip, pRuntimeFunction, &context, &handlerData, &establisherFramePointers, NULL);
                        #else
                            VOID*          handlerData = NULL;
                            ULONG64        establisherFramePointers[2] = { 0, 0 };

                            RtlVirtualUnwind(UNW_FLAG_NHANDLER, nImageBase, context.Rip, pRuntimeFunction, &context, &handlerData,  establisherFramePointers, NULL);                        
                        #endif
                    #else
                        // RtlVirtualUnwind is not declared in the SDK headers for non-desktop apps, 
                        // but for 64 bit targets it's always present and appears to be needed by the
                        // existing RtlUnwindEx function. If in the end we can't use RtlVirtualUnwind
                        // and Microsoft doesn't provide an alternative, we can implement RtlVirtualUnwind
                        // ourselves manually (not trivial, but has the best results) or we can use
                        // the old style stack frame following, which works only when stack frames are 
                        // enabled in the build, which usually isn't so for optimized builds and for
                        // third party code. 

                        VOID*          handlerData = NULL;
                        ULONG64        establisherFramePointers[2] = { 0, 0 };
                        RtlVirtualUnwind(UNW_FLAG_NHANDLER, nImageBase, context.Rip, pRuntimeFunction, &context, &handlerData,  establisherFramePointers, NULL);                        

                        // In case the above doesn't work, we need to do this:
                        // context.Rip          = NULL;
                        // context.ContextFlags = 0;
                    #endif
                }
                else
                {
                    // If we don't have a RUNTIME_FUNCTION, then we've encountered a leaf function. Adjust the stack appropriately.
                    context.Rip  = (ULONG64)(*(PULONG64)context.Rsp);
                    context.Rsp += 8;
                }

                if(context.Rip)
                {
                    if(nFrameIndex < nReturnAddressArrayCapacity)
                        pReturnAddressArray[nFrameIndex++] = (void*)(uintptr_t)context.Rip;
                }
            }

            return nFrameIndex;
        }

    } // namespace Allocator

} // namespace EA


#if defined(_MSC_VER) && (defined(_M_AMD64) || defined(_WIN64))
    #pragma optimize("", on) // See comments above regarding this optimization change.
#endif


#endif // (platform checks)


#endif

