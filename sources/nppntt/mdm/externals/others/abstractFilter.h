#pragma once

#include "abstractFileDescriptor.h"

#include "abstractApplyKey.h"

#include "temporary_windows_include.h"

#include "abstractEmulationDefines.h"

#define MAX_NETWORK_NAME  50
#define MAX_NETWORK_COUNT 20

struct FilterData {
    BOOL isSetup;
    unsigned int networkCounter;
    unsigned int maxLiveTimeInHours;

    char newtworkList[MAX_NETWORK_COUNT][MAX_NETWORK_NAME];

    unsigned int baseStationCounter;
    char BSList[MAX_NETWORK_COUNT][MAX_NETWORK_NAME];

    BOOL periodActive;
    char periodMin[20];
    char periodMax[20];
};

FilterData *createFilter();
void deleteFilter( FilterData *filter );

void changeFilter( const FilterData *filterIn, FilterData *filterOut );

bool isDecipheredFile( const FileDescriptorData *file, const FilterData *filter );
bool isDeletedFile( const FileDescriptorData *file, const FilterData *filter );
bool deleteFile( FileDescriptorData *file, AppliedData *data );
bool fillFileDescriptor( FileDescriptorData *file );

/*
	if first_file_time_in_seconds > second_file_time_in_seconds then
		return true;
	else
		return false;
*/
