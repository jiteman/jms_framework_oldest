/////////////////////////////////////////////////////////////////////////////
// eathread_atomic_x86.h
//
// Copyright (c) 2003, Electronic Arts Inc. All rights reserved.
//
// Defines functionality for threadsafe primitive operations.
//
// Created by Paul Pedriana, Maxis
/////////////////////////////////////////////////////////////////////////////


#ifndef EATHREAD_X86_EATHREAD_ATOMIC_X86_H
#define EATHREAD_X86_EATHREAD_ATOMIC_X86_H


#ifndef INCLUDED_eabase_H
    #include "EA/Basic/eabase.h"
#endif
#include <stddef.h>


#ifdef _MSC_VER
     #pragma warning(push)
     #pragma warning(disable: 4146)  // unary minus operator applied to unsigned type, result still unsigned
     #pragma warning(disable: 4339)  // use of undefined type detected in CLR meta-data
#endif


/////////////////////////////////////////////////////////////////////////////
// InterlockedXXX intrinsics
//
#if defined(EA_PLATFORM_WINDOWS)
    #if defined(EA_COMPILER_MSVC) && (EA_COMPILER_VERSION >= 1300) // VC7+ has an intrinsic
        // VS2005 SP1 has a build-breaking but in <intrin.h>. We try to work around it here.
        #if (_MSC_VER >= 1500) // if VS2008 or later...
            #pragma warning(push, 0)
            #include <intrin.h>
            #pragma warning(pop)
        #endif

        #if EA_COMPILER_VERSION >= 1400 // If VC8 or later
            extern "C" long           _InterlockedIncrement(long volatile* Addend);
            extern "C" long           _InterlockedDecrement(long volatile* Addend);
            extern "C" long           _InterlockedCompareExchange(long volatile* Dest, long Exchange, long Comp);
            extern "C" long           _InterlockedExchange(long volatile* Target, long Value);
            extern "C" long           _InterlockedExchangeAdd(long volatile* Addend, long Value);
            extern "C" int64_t        _InterlockedCompareExchange64(int64_t volatile* Dest, int64_t Exchange, int64_t Comp);

            #pragma intrinsic (_InterlockedCompareExchange)
            #define InterlockedCompareExchangeImp _InterlockedCompareExchange

            #pragma intrinsic (_InterlockedExchange)
            #define InterlockedExchangeImp        _InterlockedExchange 

            #pragma intrinsic (_InterlockedExchangeAdd)
            #define InterlockedExchangeAddImp     _InterlockedExchangeAdd

            #pragma intrinsic (_InterlockedIncrement)
            #define InterlockedIncrementImp       _InterlockedIncrement

            #pragma intrinsic (_InterlockedDecrement)
            #define InterlockedDecrementImp       _InterlockedDecrement

            #pragma intrinsic (_InterlockedCompareExchange64)
            #define InterlockedCompareExchange64Imp _InterlockedCompareExchange64

            inline bool
            InterlockedSetIfEqual(volatile int64_t* dest, int64_t newValue, int64_t condition){
                return (InterlockedCompareExchange64Imp(dest, newValue, condition) == condition);
            }

            inline bool
            InterlockedSetIfEqual(volatile uint64_t* dest, uint64_t newValue, uint64_t condition){
                return (InterlockedCompareExchange64Imp((int64_t volatile*)dest, (int64_t)newValue, (int64_t)condition) == (int64_t)condition);
            }

        #else // VC7.1 or earlier
            extern "C" long __stdcall _InterlockedIncrement(long volatile* Addend);
            extern "C" long __stdcall _InterlockedDecrement(long volatile* Addend);
            extern "C" long __stdcall _InterlockedCompareExchange(long volatile* Dest, long Exchange, long Comp);
            extern "C" long __stdcall _InterlockedExchange(long volatile* Target, long Value);
            extern "C" long __stdcall _InterlockedExchangeAdd(long volatile* Addend, long Value);

            inline bool
            InterlockedSetIfEqual(volatile int64_t* dest, int64_t newValue, int64_t condition){
                //value returned in eax
                __asm {
                    push ebx
                    lea  esi, condition
                    lea  edi, newValue
                    mov  eax, [esi]
                    mov  edx, 4[esi]
                    mov  ebx, [edi]
                    mov  ecx, 4[edi]
                    mov  esi, dest
                    lock cmpxchg8b [esi]        
                    mov  eax, 0
                    pop  ebx
                    setz al
                }
            }

            inline bool
            InterlockedSetIfEqual(volatile uint64_t* dest, uint64_t newValue, uint64_t condition){
                //value returned in eax
                __asm {
                    push ebx
                    lea  esi, condition
                    lea  edi, newValue
                    mov  eax, [esi]
                    mov  edx, 4[esi]
                    mov  ebx, [edi]
                    mov  ecx, 4[edi]
                    mov  esi, dest
                    lock cmpxchg8b [esi]        
                    mov  eax, 0
                    pop  ebx
                    setz al
                }
            }

            #pragma intrinsic (_InterlockedCompareExchange)
            #define InterlockedCompareExchangeImp _InterlockedCompareExchange

            #pragma intrinsic (_InterlockedExchange)
            #define InterlockedExchangeImp        _InterlockedExchange 

            #pragma intrinsic (_InterlockedExchangeAdd)
            #define InterlockedExchangeAddImp     _InterlockedExchangeAdd

            #pragma intrinsic (_InterlockedIncrement)
            #define InterlockedIncrementImp       _InterlockedIncrement

            #pragma intrinsic (_InterlockedDecrement)
            #define InterlockedDecrementImp       _InterlockedDecrement

        #endif

    #endif

    #ifndef InterlockedCompareExchangeImp // If the above intrinsics aren't used... 
        extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile * pAddend);
        extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile * pAddend);
        extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile * pTarget, long value);
        extern "C" __declspec(dllimport) long __stdcall InterlockedExchangeAdd(long volatile * pAddend, long value);
        extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile * pDestination, long value, long compare);


        #define InterlockedCompareExchangeImp InterlockedCompareExchange
        #define InterlockedExchangeImp        InterlockedExchange
        #define InterlockedExchangeAddImp     InterlockedExchangeAdd
        #define InterlockedIncrementImp       InterlockedIncrement
        #define InterlockedDecrementImp       InterlockedDecrement
    #endif

#endif // EA_PLATFORM_WINDOWS




#if defined(EA_PROCESSOR_X86)
    #define EA_THREAD_ATOMIC_IMPLEMENTED

    namespace EA
    {
        namespace Thread
        {
            /* To do
            inline int32_t AtomicGetValue(volatile int32_t*)
                { }
            inline void AtomicSetValue(volatile int32_t*, int32_t value)
                { }
            inline int32_t AtomicIncrement(volatile int32_t*)
                { }
            inline int32_t AtomicDecrement(volatile int32_t*)
                { }
            inline int32_t AtomicAdd(volatile int32_t*, int32_t value)
                { }
            inline int32_t AtomicOr(volatile int32_t*, int32_t value)
                { }
            inline int32_t AtomicAnd(volatile int32_t*, int32_t value)
                { }
            inline int32_t AtomicXor(volatile int32_t*, int32_t value)
                { }
            inline int32_t AtomicSwap(volatile int32_t*, int32_t value)
                { }
            inline bool AtomicSetValueConditional(volatile int32_t*, int32_t value, int32_t condition)
                { }

            inline uint32_t AtomicGetValue(volatile uint32_t*)
                { }
            inline void AtomicSetValue(volatile uint32_t*, uint32_t value)
                { }
            inline uint32_t AtomicIncrement(volatile uint32_t*)
                { }
            inline uint32_t AtomicDecrement(volatile uint32_t*)
                { }
            inline uint32_t AtomicAdd(volatile uint32_t*, uint32_t value)
                { }
            inline uint32_t AtomicOr(volatile uint32_t*, uint32_t value)
                { }
            inline uint32_t AtomicAnd(volatile uint32_t*, uint32_t value)
                { }
            inline uint32_t AtomicXor(volatile uint32_t*, uint32_t value)
                { }
            inline uint32_t AtomicSwap(volatile uint32_t*, uint32_t value)
                { }
            inline bool AtomicSetValueConditional(volatile uint32_t*, uint32_t value, uint32_t condition)
                { }

            inline int64_t AtomicGetValue(volatile int64_t*)
                { }
            inline void AtomicSetValue(volatile int64_t*, int64_t value)
                { }
            inline int64_t AtomicIncrement(volatile int64_t*)
                { }
            inline int64_t AtomicDecrement(volatile int64_t*)
                { }
            inline int64_t AtomicAdd(volatile int64_t*, int64_t value)
                { }
            inline int64_t AtomicOr(volatile int64_t*, int64_t value)
                { }
            inline int64_t AtomicAnd(volatile int64_t*, int64_t value)
                { }
            inline int64_t AtomicXor(volatile int64_t*, int64_t value)
                { }
            inline int64_t AtomicSwap(volatile int64_t*, int64_t value)
                { }
            inline bool AtomicSetValueConditional(volatile int64_t*, int64_t value, int64_t condition)
                { }

            inline uint64_t AtomicGetValue(volatile uint64_t*)
                { }
            inline void AtomicSetValue(volatile uint64_t*, uint64_t value)
                { }
            inline uint64_t AtomicIncrement(volatile uint64_t*)
                { }
            inline uint64_t AtomicDecrement(volatile uint64_t*)
                { }
            inline uint64_t AtomicAdd(volatile uint64_t*, uint64_t value)
                { }
            inline uint64_t AtomicOr(volatile uint64_t*, uint64_t value)
                { }
            inline uint64_t AtomicAnd(volatile uint64_t*, uint64_t value)
                { }
            inline uint64_t AtomicXor(volatile uint64_t*, uint64_t value)
                { }
            inline uint64_t AtomicSwap(volatile uint64_t*, uint64_t value)
                { }
            inline bool AtomicSetValueConditional(volatile uint64_t*, uint64_t value, uint64_t condition)
                { }
            */



            /// class AtomicInt
            /// Actual implementation may vary per platform. May require certain alignments, sizes, 
            /// and declaration specifications per platform.

            template <class T>
            class AtomicInt
            {
            public:
                typedef AtomicInt<T> ThisType;
                typedef T            ValueType;

                /// AtomicInt
                /// Empty constructor. Intentionally leaves mValue in an unspecified state.
                /// This is done so that an AtomicInt acts like a standard built-in integer.
                AtomicInt()
                    {}

                AtomicInt(ValueType n) 
                    { SetValue(n); }

                AtomicInt(const ThisType& x)
                    : mValue(x.GetValue()) {}

                AtomicInt& operator=(const ThisType& x)
                    { mValue = x.GetValue(); return *this; }

                ValueType GetValue() const
                    { return mValue; }

                ValueType GetValueRaw() const
                    { return mValue; }

                ValueType SetValue(ValueType n);
                bool      SetValueConditional(ValueType n, ValueType condition);
                ValueType Increment();
                ValueType Decrement();
                ValueType Add(ValueType n);

                // operators
                inline            operator const ValueType() const { return GetValue(); }
                inline ValueType  operator =(ValueType n)          {        SetValue(n); return n; }
                inline ValueType  operator+=(ValueType n)          { return Add(n);}
                inline ValueType  operator-=(ValueType n)          { return Add(-n);}
                inline ValueType  operator++()                     { return Increment();}
                inline ValueType  operator++(int)                  { return Increment() - 1;}
                inline ValueType  operator--()                     { return Decrement(); }
                inline ValueType  operator--(int)                  { return Decrement() + 1;}

            protected:
                volatile ValueType mValue;
            };

            #if defined(EA_PLATFORM_WINDOWS) && defined(_MSC_VER)

                // 32 bit versions
                template<> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::SetValue(ValueType n)
                    { return (ValueType)InterlockedExchangeImp((long*)&mValue, (long)n); } // Even though we shouldn't need to use InterlockedExchange on x86, the intrinsic x86 InterlockedExchange is at least as fast as C code we would otherwise put here.

                template<> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::SetValue(ValueType n)
                    { return (ValueType)InterlockedExchangeImp((long*)&mValue, (long)n); } // Even though we shouldn't need to use InterlockedExchange on x86, the intrinsic x86 InterlockedExchange is at least as fast as C code we would otherwise put here.

                template<> inline
                bool AtomicInt<int32_t>::SetValueConditional(ValueType n, ValueType condition)
                    { return ((ValueType)InterlockedCompareExchangeImp((long*)&mValue, (long)n, (long)condition) == condition); }

                template<> inline
                bool AtomicInt<uint32_t>::SetValueConditional(ValueType n, ValueType condition)
                    { return ((ValueType)InterlockedCompareExchangeImp((long*)&mValue, (long)n, (long)condition) == condition); }

                template<> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Increment()
                    { return (ValueType)InterlockedIncrementImp((long*)&mValue); }

                template<> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Increment()
                    { return (ValueType)InterlockedIncrementImp((long*)&mValue); }

                template<> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Decrement()
                    { return (ValueType)InterlockedDecrementImp((long*)&mValue); }

                template<> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Decrement()
                    { return (ValueType)InterlockedDecrementImp((long*)&mValue); }

                template<> inline
                AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Add(ValueType n)
                    { return ((ValueType)InterlockedExchangeAddImp((long*)&mValue, (long)n) + n); }

                template<> inline
                AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Add(ValueType n)
                    { return ((ValueType)InterlockedExchangeAddImp((long*)&mValue, (long)n) + n); }



                // 64 bit versions
                template<> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::GetValue() const{
                    int64_t condition, nNewValue;
                    do{
                        nNewValue = condition = mValue; // Todo: This function has a problem unless the assignment of mValue to condition is atomic.
                    } while(!InterlockedSetIfEqual(const_cast<int64_t*>(&mValue), nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::GetValue() const{
                    uint64_t condition, nNewValue;
                    do{
                        nNewValue = condition = mValue; // Todo: This function has a problem unless the assignment of mValue to condition is atomic.
                    } while(!InterlockedSetIfEqual(const_cast<uint64_t*>(&mValue), nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::SetValue(ValueType n){
                    int64_t condition;
                    do{
                        condition = mValue;
                    } while(!InterlockedSetIfEqual(&mValue, n, condition));
                    return condition;
                }

                template<> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::SetValue(ValueType n){
                    uint64_t condition;
                    do{
                        condition = mValue;
                    } while(!InterlockedSetIfEqual(&mValue, n, condition));
                    return condition;
                }

                template<> inline
                bool AtomicInt<int64_t>::SetValueConditional(ValueType n, ValueType condition){
                    return InterlockedSetIfEqual(&mValue, n, condition);
                }

                template<> inline
                bool AtomicInt<uint64_t>::SetValueConditional(ValueType n, ValueType condition){
                    return InterlockedSetIfEqual(&mValue, n, condition);
                }

                template<> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Increment(){
                    int64_t condition, nNewValue;
                    do{
                        condition = mValue;
                        nNewValue = condition + 1;
                    } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Increment(){
                    uint64_t condition, nNewValue;
                    do{
                        condition = mValue;
                        nNewValue = condition + 1;
                    } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Decrement(){
                    int64_t condition, nNewValue;
                    do{
                        condition = mValue;
                        nNewValue = condition - 1;
                    } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Decrement(){
                    uint64_t condition, nNewValue;
                    do{
                        condition = mValue;
                        nNewValue = condition - 1;
                    } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Add(ValueType n){
                    int64_t condition, nNewValue;
                    do{
                        condition = mValue;
                        nNewValue = condition + n;
                    } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                    return nNewValue;
                }

                template<> inline
                AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Add(ValueType n){
                    uint64_t condition, nNewValue;
                    do{
                        condition = mValue;
                        nNewValue = condition + n;
                    } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                    return nNewValue;
                }


            #elif defined(EA_COMPILER_GNUC)

                // Recent versions of GCC have atomic primitives built into the compiler and standard library.
                #if defined(__APPLE__) || (defined(__GNUC__) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 403)) // GCC 4.3 or later

                    template <> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::GetValue() const
                        { return __sync_add_and_fetch(const_cast<ValueType*>(&mValue), 0); }

                    template <> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::GetValue() const
                        { return __sync_add_and_fetch(const_cast<ValueType*>(&mValue), 0); }

                    template <> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::SetValue(ValueType n)
                        { __sync_synchronize(); return __sync_lock_test_and_set(&mValue, n); }

                    template <> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::SetValue(ValueType n)
                        { __sync_synchronize(); return __sync_lock_test_and_set(&mValue, n); }

                    template <> inline
                    bool AtomicInt<int32_t>::SetValueConditional(ValueType n, ValueType condition)
                        { return (__sync_val_compare_and_swap(&mValue, condition, n) == condition); }

                    template <> inline
                    bool AtomicInt<uint32_t>::SetValueConditional(ValueType n, ValueType condition)
                        { return (__sync_val_compare_and_swap(&mValue, condition, n) == condition); }

                    template <> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Increment()
                        { return __sync_add_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Increment()
                        { return __sync_add_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Decrement()
                        { return __sync_sub_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Decrement()
                        { return __sync_sub_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Add(ValueType n)
                        { return __sync_add_and_fetch(&mValue, n); }

                    template <> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Add(ValueType n)
                        { return __sync_add_and_fetch(&mValue, n); }



                    template <> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::GetValue() const
                        { return __sync_add_and_fetch(const_cast<ValueType*>(&mValue), 0); }

                    template <> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::GetValue() const
                        { return __sync_add_and_fetch(const_cast<ValueType*>(&mValue), 0); }

                    template <> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::SetValue(ValueType n)
                        { __sync_synchronize(); return __sync_lock_test_and_set(&mValue, n); }

                    template <> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::SetValue(ValueType n)
                        { __sync_synchronize(); return __sync_lock_test_and_set(&mValue, n); }

                    template <> inline
                    bool AtomicInt<int64_t>::SetValueConditional(ValueType n, ValueType condition)
                        { return (__sync_val_compare_and_swap(&mValue, condition, n) == condition); }

                    template <> inline
                    bool AtomicInt<uint64_t>::SetValueConditional(ValueType n, ValueType condition)
                        { return (__sync_val_compare_and_swap(&mValue, condition, n) == condition); }

                    template <> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Increment()
                        { return __sync_add_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Increment()
                        { return __sync_add_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Decrement()
                        { return __sync_sub_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Decrement()
                        { return __sync_sub_and_fetch(&mValue, 1); }

                    template <> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Add(ValueType n)
                        { return __sync_add_and_fetch(&mValue, n); }

                    template <> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Add(ValueType n)
                        { return __sync_add_and_fetch(&mValue, n); }

                #else

                    // If the above intrinsics aren't used...
                    #ifndef InterlockedCompareExchangeImp
                    namespace
                    {
                        int32_t InterlockedExchange(volatile int32_t* m, int32_t n)
                        {
                            int32_t result;

                            __asm__ __volatile__ (
                                "xchgl %%eax, (%2)" // The xchg instruction does an implicit lock instruction.
                                : "=a" (result)     // outputs
                                : "a" (n), "q" (m)  // inputs
                                : "memory"          // clobbered
                                );

                            return result;
                        }

                        int32_t InterlockedCompareExchange(volatile int32_t* m, int32_t n, int32_t condition)
                        {
                            int32_t result;

                            __asm__ __volatile__(
                                "lock; cmpxchgl %3, (%1) \n"        // Test *m against EAX, if same, then *m = n
                                : "=a" (result), "=q" (m)           // outputs
                                : "a" (condition), "q" (n), "1" (m) // inputs
                                : "memory"                          // clobbered
                                );

                            return result;
                        }

                        #define InterlockedExchangeImp        InterlockedExchange
                        #define InterlockedCompareExchangeImp InterlockedCompareExchange
                    }
                    #endif

                    // 32 bit versions
                    template<> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::SetValue(ValueType n)
                        { return (ValueType)InterlockedExchangeImp(&mValue, n); }

                    template<> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::SetValue(ValueType n)
                        { return (ValueType)InterlockedExchangeImp((int32_t*)&mValue, n); }

                    template<> inline
                    bool AtomicInt<int32_t>::SetValueConditional(ValueType n, ValueType condition)
                        { return ((ValueType)InterlockedCompareExchangeImp(&mValue, n, condition) == condition); }

                    template<> inline
                    bool AtomicInt<uint32_t>::SetValueConditional(ValueType n, ValueType condition)
                        { return ((ValueType)InterlockedCompareExchangeImp((int32_t*)&mValue, n, condition) == condition); }

                    template<> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Increment()
                    {
                        int32_t result;

                        __asm__ __volatile__ ("lock; xaddl %0, %1"
                                            : "=r" (result), "=m" (mValue)
                                            : "0" (1), "m" (mValue)
                                            : "memory"
                                            );
                        return result + 1;
                    }

                    template<> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Increment()
                    {
                        int32_t result;

                        __asm__ __volatile__ ("lock; xaddl %0, %1"
                                            : "=r" (result), "=m" (mValue)
                                            : "0" (1), "m" (mValue)
                                            : "memory"
                                            );
                        return result + 1;
                    }

                    template<> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Decrement()
                    {
                        int32_t result;

                        __asm__ __volatile__ ("lock; xaddl %0, %1"
                                            : "=r" (result), "=m" (mValue)
                                            : "0" (-1), "m" (mValue)
                                            : "memory"
                                            );
                        return result - 1;
                    }

                    template<> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Decrement()
                    {
                        uint32_t result;

                        __asm__ __volatile__ ("lock; xaddl %0, %1"
                                            : "=r" (result), "=m" (mValue)
                                            : "0" (-1), "m" (mValue)
                                            : "memory"
                                            );
                        return result - 1;
                    }

                    template<> inline
                    AtomicInt<int32_t>::ValueType AtomicInt<int32_t>::Add(ValueType n)
                    {
                        int32_t result;

                        __asm__ __volatile__ ("lock; xaddl %0, %1"
                                            : "=r" (result), "=m" (mValue)
                                            : "0" (n), "m" (mValue)
                                            : "memory"
                                            );
                        return result + n;
                    }

                    template<> inline
                    AtomicInt<uint32_t>::ValueType AtomicInt<uint32_t>::Add(ValueType n)
                    {
                        uint32_t result;

                        __asm__ __volatile__ ("lock; xaddl %0, %1"
                                            : "=r" (result), "=m" (mValue)
                                            : "0" (n), "m" (mValue)
                                            : "memory"
                                            );
                        return result + n;
                    }



                    // 64 bit versions

                    inline bool
                    InterlockedSetIfEqual(volatile int64_t* dest, int64_t newValue, int64_t condition)
                    {
                        int64_t oldValue;

                        __asm __volatile ("lock; cmpxchg8b %1"
                                         : "=A" (oldValue), "=m" (*dest)
                                         : "b" (((int32_t) newValue) & 0xffffffff),
                                           "c" ((int32_t)(newValue >> 32)),
                                           "m" (*dest), "a" (((int32_t) condition) & 0xffffffff),
                                           "d" ((int32_t)(condition >> 32)));

                        return oldValue == condition;

                        // Reference non-thread-safe implementation:
                        // if(*dest == condition)
                        // {
                        //     *dest = newValue
                        //     return true;
                        // }
                        // return false;
                    }

                    inline bool
                    InterlockedSetIfEqual(volatile uint64_t* dest, uint64_t newValue, uint64_t condition)
                    {
                        uint64_t oldValue;

                        __asm __volatile ("lock; cmpxchg8b %1"
                                         : "=A" (oldValue), "=m" (*dest)
                                         : "b" (((uint32_t) newValue) & 0xffffffff),
                                           "c" ((uint32_t)(newValue >> 32)),
                                           "m" (*dest), "a" (((uint32_t) condition) & 0xffffffff),
                                           "d" ((uint32_t)(condition >> 32)));

                        return oldValue == condition;

                        // Reference non-thread-safe implementation:
                        // if(*dest == condition)
                        // {
                        //     *dest = newValue
                        //     return true;
                        // }
                        // return false;
                    }

                    template<> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::GetValue() const{
                        int64_t condition, nNewValue;
                        do{
                            nNewValue = condition = mValue; // Todo: This function has a problem unless the assignment of mValue to condition is atomic.
                        } while(!InterlockedSetIfEqual(const_cast<int64_t*>(&mValue), nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::GetValue() const{
                        uint64_t condition, nNewValue;
                        do{
                            nNewValue = condition = mValue; // Todo: This function has a problem unless the assignment of mValue to condition is atomic.
                        } while(!InterlockedSetIfEqual(const_cast<uint64_t*>(&mValue), nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::SetValue(ValueType n){
                        int64_t condition;
                        do{
                            condition = mValue;
                        } while(!InterlockedSetIfEqual(&mValue, n, condition));
                        return condition;
                    }

                    template<> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::SetValue(ValueType n){
                        uint64_t condition;
                        do{
                            condition = mValue;
                        } while(!InterlockedSetIfEqual(&mValue, n, condition));
                        return condition;
                    }

                    template<> inline
                    bool AtomicInt<int64_t>::SetValueConditional(ValueType n, ValueType condition){
                        return InterlockedSetIfEqual(&mValue, n, condition);
                    }

                    template<> inline
                    bool AtomicInt<uint64_t>::SetValueConditional(ValueType n, ValueType condition){
                        return InterlockedSetIfEqual(&mValue, n, condition);
                    }

                    template<> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Increment(){
                        int64_t condition, nNewValue;
                        do{
                            condition = mValue;
                            nNewValue = condition + 1;
                        } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Increment(){
                        uint64_t condition, nNewValue;
                        do{
                            condition = mValue;
                            nNewValue = condition + 1;
                        } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Decrement(){
                        int64_t condition, nNewValue;
                        do{
                            condition = mValue;
                            nNewValue = condition - 1;
                        } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Decrement(){
                        uint64_t condition, nNewValue;
                        do{
                            condition = mValue;
                            nNewValue = condition - 1;
                        } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<int64_t>::ValueType AtomicInt<int64_t>::Add(ValueType n){
                        int64_t condition, nNewValue;
                        do{
                            condition = mValue;
                            nNewValue = condition + n;
                        } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                        return nNewValue;
                    }

                    template<> inline
                    AtomicInt<uint64_t>::ValueType AtomicInt<uint64_t>::Add(ValueType n){
                        uint64_t condition, nNewValue;
                        do{
                            condition = mValue;
                            nNewValue = condition + n;
                        } while(!InterlockedSetIfEqual(&mValue, nNewValue, condition));
                        return nNewValue;
                    }

                #endif

            #elif defined(EA_COMPILER_INTEL) || defined(EA_COMPILER_MSVC) || defined(EA_COMPILER_BORLAND) || defined(EA_COMPILER_METROWERKS)

                // This is won't compile when ValueType is 64 bits.

                template<class T> inline 
                typename AtomicInt<T>::ValueType AtomicInt<T>::SetValue(ValueType n)
                {
                    __asm{
                        mov  ecx, this                 // mValue is expected to be at offset zero of this.
                        mov  eax, n 
                        xchg eax, dword ptr [ecx]      // The xchg instruction does an implicit lock instruction.
                    }
                }

                template<class T> inline 
                bool AtomicInt<T>::SetValueConditional(ValueType n, ValueType condition)
                {
                    __asm{
                        mov  ecx, this                       // mValue is expected to be at offset zero of this.
                        mov  edx, n 
                        mov  eax, condition
                        lock cmpxchg dword ptr [ecx], edx    // Compares mValue to condition. If equal, z flag is set and n is copied into mValue.
                        jz    condition_met
                        xor  eax, eax
                        jmp  end
                        condition_met:
                        mov  eax, 1
                        end:
                    }
                }

                template<class T>  inline 
                bool typename AtomicInt<T>::ValueType AtomicInt<T>::Increment()
                {
                    __asm{
                        mov  ecx, this                 // mValue is expected to be at offset zero of this.
                        mov  eax, 1 
                        lock xadd dword ptr [ecx], eax // Sum goes into [ecx], old mValue goes into eax.
                        inc  eax                       // Increment eax because the return value is the new value.
                    }
                }

                template<class T>  inline 
                bool typename AtomicInt<T>::ValueType AtomicInt<T>::Decrement()
                {
                    __asm{
                        mov  ecx, this                 // mValue is expected to be at offset zero of this.
                        mov  eax, 0xffffffff
                        lock xadd dword ptr [ecx], eax // Sum goes into [ecx], old mValue goes into eax.
                        dec  eax                       // Increment eax because the return value is the new value.
                    }
                }

                template<class T>  inline 
                bool typename AtomicInt<T>::ValueType AtomicInt<T>::Add(ValueType n)
                {
                    __asm{
                        mov  ecx, this                 // mValue is expected to be at offset zero of this.
                        mov  eax, n 
                        lock xadd dword ptr [ecx], eax // Sum goes into [ecx], old mValue goes into eax.
                        add  eax, n
                    }
                }


            #else
                // Compiler not currently supported.

            #endif

        } // namespace Thread

    } // namespace EA


#endif // EA_PROCESSOR_X86


#ifdef _MSC_VER
     #pragma warning(pop)
#endif


#endif // EATHREAD_X86_EATHREAD_ATOMIC_X86_H













