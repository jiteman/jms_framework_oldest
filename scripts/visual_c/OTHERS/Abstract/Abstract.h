#pragma once

#include <windows.h>

#include "nppntt/mdm/externals/others/abstractStatistics.h"
#include "nppntt/mdm/externals/others/abstractFilter.h"
#include "nppntt/mdm/externals/others/abstractDecipher.h"

#include "nppntt/mdm/externals/others/abstractEmulationDefines.h"

#define LIBRARY_EXPORT __declspec(dllexport) __cdecl

extern "C" {

    int LIBRARY_EXPORT initializeSystem();
    int LIBRARY_EXPORT releaseSystem();

    int LIBRARY_EXPORT startSystem();
    int LIBRARY_EXPORT stopSystem();

    int LIBRARY_EXPORT changeFilter( const FilterData *filter );

    int LIBRARY_EXPORT setDecipherTime( const _decipherTimeLimit *time );

    int LIBRARY_EXPORT getStatistics( GlobalStatisticsData *globalStatistics );

    int LIBRARY_EXPORT changeAppenderFolders( const AppenderFoldersList *folderList );

	int LIBRARY_EXPORT runGarbageCollector(void);
}
