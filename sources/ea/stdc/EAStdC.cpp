/////////////////////////////////////////////////////////////////////////////
// EAStdC.cpp
//
// Copyright (c) 2011, Electronic Arts Inc. All rights reserved.
// Created by Paul Pedriana
/////////////////////////////////////////////////////////////////////////////


#include <EAStdC/EAStdC.h>
#include <EAStdC/internal/SprintfCore.h>


namespace EA
{
    namespace StdC
    {
        EASTDC_API void Init()
        {
            SprintfLocal::EASprintfInit();
        }

        EASTDC_API void Shutdown()
        {
            SprintfLocal::EASprintfShutdown();
        }
    }
}






