#pragma once

#include "checkKeyStruct.h"
#include "abstractFileDescriptor.h"

#include "jmsf/stdal/stdal_stl.h"

#include "abstractEmulationDefines.h"

#ifdef _DEBUG
template < typename Type >
std::string convertAnyDigitsToString( Type in ) {
	std::ostringstream o;
    o << in;
    return o.str();
}
#endif

//bool loadDataBaseDll();
//void unloadDataBaseDll();

void initializeDataBase(const std::string &workDir);
bool connectToDataBase(const std::string &IP, const std::string &dataBaseName, const std::string &User, const std::string &Password);

bool sendFilesToDataBase( const FileDescriptorData *voiceFile, FileDescriptorData *sdcFile,  
                          const AppliedData *voiceDataToSend, const AppliedData *serviceDataToSend );
void disconnectFromDataBase();
void releaseDataBase();

