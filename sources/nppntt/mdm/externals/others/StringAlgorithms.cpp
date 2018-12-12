#include "StringAlgorithms.h"


std::string getLastFolderName( const std::string &fullPath ) {
	std::string copyOfFullPath = fullPath;

	const char backSlash = '\\';

	if ( copyOfFullPath.back() != backSlash ) {
		copyOfFullPath += backSlash;
	}

	const size_t lastPositionToCopy = copyOfFullPath.find_last_of( backSlash ) - 1;
	const size_t preLastBackSlashPosition = copyOfFullPath.rfind( backSlash, lastPositionToCopy );

	const size_t firstPositionToCopy =
		preLastBackSlashPosition == std::string::npos ?
		lastPositionToCopy - 3 : // dirty hack
		preLastBackSlashPosition + 1;
						
	return std::string( &copyOfFullPath.at( firstPositionToCopy ), &copyOfFullPath.at( lastPositionToCopy ) );
}
