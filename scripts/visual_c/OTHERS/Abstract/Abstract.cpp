#include "Abstract.h"

#include "nppntt/mdm/interface_MaskDm.h"

static nppntt::mdm::interface_MaskDm *global_interfaceMaskDm = 0;

extern "C" {

int LIBRARY_EXPORT initializeSystem() {
#ifndef _DEBUG_GUI
	if ( global_interfaceMaskDm != 0 ) return 0;

	global_interfaceMaskDm = 0;
	global_interfaceMaskDm = new nppntt::mdm::interface_MaskDm;

	if ( global_interfaceMaskDm == 0 ) return 0;

	return global_interfaceMaskDm->wasInitializedCorrectly() ? 1 : 0;
#else
	return 1;
#endif
}

int LIBRARY_EXPORT releaseSystem() {
#ifndef _DEBUG_GUI
	nppntt::mdm::interface_MaskDm *previous_interfaceMaskDm = global_interfaceMaskDm;
	delete global_interfaceMaskDm;
	global_interfaceMaskDm = 0;
	return previous_interfaceMaskDm == 0 ? 0 : 1;
#else
	return 1;
#endif
}

int LIBRARY_EXPORT startSystem() {
#ifndef _DEBUG_GUI
	if ( global_interfaceMaskDm == 0 ) return 0;
	return global_interfaceMaskDm->startSystem();
#else
	return 1;
#endif
}

int LIBRARY_EXPORT stopSystem() { 
#ifndef _DEBUG_GUI
	if ( global_interfaceMaskDm == 0 ) return 0;
	return global_interfaceMaskDm->stopSystem();
#else
	return 1;
#endif
}

int LIBRARY_EXPORT getStatistics( GlobalStatisticsData *globalStatistics ) {
#ifndef _DEBUG_GUI
	return global_interfaceMaskDm->getStatistics(globalStatistics);
#else
	return 1;
#endif
}

int LIBRARY_EXPORT changeFilter( const FilterData *filter ) {
#ifndef _DEBUG_GUI
    return global_interfaceMaskDm->changeFilter( filter );
#else
	return 1;
#endif
}

int LIBRARY_EXPORT setDecipherTime( const _decipherTimeLimit *time ) {
#ifndef _DEBUG_GUI
	return global_interfaceMaskDm->setDecipherTime( time );
#else
	return 1;
#endif
}

int LIBRARY_EXPORT changeAppenderFolders( const AppenderFoldersList *folderList ) {
    std::list< const std::string > folders;

    for( unsigned int i = 0; i < folderList->foldersCount; i++ ) {
        std::string folderName(folderList->folders[i]);
        folders.push_back(folderName);
    }
#ifndef _DEBUG_GUI
    return global_interfaceMaskDm->setFileAppenderFolders( folders );
#else
	return 1;
#endif
}

int LIBRARY_EXPORT runGarbageCollector(void) {
#ifndef _DEBUG_GUI
	return global_interfaceMaskDm->clearExpiredServiceFiles();
#endif
	return 1;
}

}
