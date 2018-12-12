#include "abstractFileDescriptor.h"
#include "TimeFunctions.h"

/*
	if first_file_time_in_seconds > second_file_time_in_seconds then
		return true;
	else
		return false;
*/

bool compareFileDescriptorTime( const FileDescriptorData *first, const FileDescriptorData *second ) {
	ULONG first_FileTimeInSeconds = ConvertFileTimeToSeconds( first->creationTime );
	ULONG second_FileTimeInSeconds = ConvertFileTimeToSeconds( second->creationTime );
	return first_FileTimeInSeconds < second_FileTimeInSeconds;
}
