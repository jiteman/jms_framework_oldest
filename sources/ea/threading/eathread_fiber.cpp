/////////////////////////////////////////////////////////////////////////////
// eathread_fiber.cpp
//
// Copyright (c) 2008, Electronic Arts Inc. All rights reserved.
//
// Created by Stuart Riffle
/////////////////////////////////////////////////////////////////////////////


#include "EABase/eabase.h"
#include "eathread/eathread.h"
#include "eathread/eathread_fiber.h"


#if defined( EATHREAD_FIBERS_AVAILABLE )

    #if defined( EA_PLATFORM_WIN32 )

        EATHREADLIB_API void CallWithStack( void (*func)( void* ), void* info, void* stackBase, int stackSize )
        {
            __asm
            {
                mov     edi, stackBase
                add     edi, stackSize

                mov     eax, esp        
                mov     esp, edi   
                push    eax     

                push    info
                call    func

                mov     esp, [esp + 4]
            }
        }

    #elif defined( EA_PLATFORM_PS3_SPU )

        extern "C" void CallWithStack( void (*func)( void* ), void* info, void* stackBase, int stackSize )
        {
            stackSize -= sizeof( vec_uint4 ); // LR save slot
            stackSize -= sizeof( vec_uint4 ); // SP backchain

            register vec_uint4* backChain = (vec_uint4*) (((intptr_t) stackBase) + stackSize);
            register vec_uint4  userStack = spu_insert( (uint32_t) stackSize, spu_splats( (uint32_t) backChain ), 1 );

            __asm__ volatile
            (
            "   stqd $1, 0(%0)  \n" 
            "   ai   $1, %1, 0  \n" 
            "   ai   $2, %2, 0  \n" 
            "   ai   $3, %3, 0  \n" 
            "   bisl $0, $2     \n" 
            "   lqd  $1, 0($1)  \n" 
            :
            :   "r"( backChain ), "r"( userStack ), "r"( func ), "r"( info ) 
            :   "0", "1", "2", "3" 
            );
        }

    #endif

#endif








