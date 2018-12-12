///////////////////////////////////////////////////////////////////////////////
// eathread_callstack_null.cpp
//
// Copyright (c) 2012 Electronic Arts Inc.
// Created by Paul Pedriana
///////////////////////////////////////////////////////////////////////////////


#include <eathread/eathread_callstack.h>
#include <eathread/eathread_callstack_context.h>
#include <string.h>


namespace EA
{
namespace Thread
{


EATHREADLIB_API void InitCallstack()
{
}

EATHREADLIB_API void ShutdownCallstack()
{
}

EATHREADLIB_API size_t GetCallstack(void* /*callstack*/[], size_t /*maxDepth*/, const CallstackContext* /*pContext*/)
{
    return 0;
}

EATHREADLIB_API bool GetCallstackContext(CallstackContext& /*context*/, intptr_t /*threadId*/)
{
    return false;
}

EATHREADLIB_API bool GetCallstackContextSysThreadId(CallstackContext& /*context*/, intptr_t /*sysThreadId*/)
{
    return false;
}

EATHREADLIB_API void GetCallstackContext(CallstackContext& context, const Context* /*pContext*/)
{
    memset(&context, 0, sizeof(context));
}

EATHREADLIB_API size_t GetModuleFromAddress(const void* /*pAddress*/, char* /*pModuleFileName*/, size_t /*moduleNameCapacity*/)
{
    return 0;
}

EATHREADLIB_API ModuleHandle GetModuleHandleFromAddress(const void* /*pAddress*/)
{
    return (ModuleHandle)0;
}



} // namespace Thread
} // namespace EA



