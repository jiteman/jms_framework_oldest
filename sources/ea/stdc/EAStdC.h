/////////////////////////////////////////////////////////////////////////////
// EAStdC.h
//
// Copyright (c) 2011, Electronic Arts Inc. All rights reserved.
// Created by Paul Pedriana
/////////////////////////////////////////////////////////////////////////////


#include "EA/StdC/internal/Config.h"


#ifndef EASTDC_EASTDC_H
#define EASTDC_EASTDC_H


namespace EA
{
    namespace StdC
    {
        // Does any startup initialization that EAStdC might need. Usually this
        // means allocating structures that can't otherwise be automatically 
        // auto-initialized (e.g. due to thread safety problems).
        // Memory may be allocated via EASTDC_NEW within this function. 
        EASTDC_API void Init();

        // Undoes any initialization that Init did.
        // Memory may be freed via EASTDC_DELETE within this function.
        EASTDC_API void Shutdown();
    }
}

#endif // Header include guard


