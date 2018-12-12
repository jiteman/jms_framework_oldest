#include "interface_MaskDm.h"
#include "externals/others/abstractFilter.h"
#include "externals/others/abstractDecipher.h"
#include "externals/others/abstractStatistics.h"

#include "externals/data/ed_FileFilter.h"
#include "externals/data/factory_ExternalData.h"

#include "externals/data/statistics/ed_Summary.h"
#include "externals/data/statistics/factory_ed_Statistics.h"

#include "factory_MaskDm.h"
#include "MaskDm.h"

#include "jmsf/osie/factory_OperatingSystem.h"
#include "jmsf/osie/UtilityControl.h"
#include "jmsf/osie/PopUpMessage.h"
#include "jmsf/Exception.h"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextString.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Boolean.h"


namespace nppntt {
namespace mdm {


bool interface_MaskDm::wasInitializedCorrectly() const throw() {
	return _implementation.getWeakConstant()->wasInitializedCorrectly();
}

int interface_MaskDm::startSystem() throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {

// 		::jmsf::Proxy< ::jmsf::Container< ::jmsf::ConstantProxy, ::jmsf::TextString > > pathToDataFolders =
// 			::jmsf::factory_Container< ::jmsf::ConstantProxy, ::jmsf::TextString >::instance()->createArray();
// 
// 		pathToDataFolders->appendBack( ::jmsf::CONSTANT_TEXT_STRING( "c:\\MDM_test_files\\" ) );
// 		_implementation->changeFileAppenderFolders( pathToDataFolders );
		_implementation->continueDecipchering();
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::startSystem()" ) );
	}
	
	return 1;
}

int interface_MaskDm::stopSystem() throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {
		_implementation->stopDecipchering();
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::stopSystem()" ) );
	}
	
	return 1;
}

int interface_MaskDm::changeFilter( const FilterData *filter ) throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {
		_implementation->updateFileFilter( externals::data::factory_ExternalData::instance()->createFileFilter( ::jmsf::Pointer< FilterData >::createWeakFor( filter ) ).takeConstant() );
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::changeFilter()" ) );
	}
	
	return 1;
}

int interface_MaskDm::setDecipherTime( const _decipherTimeLimit *time ) throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {
		_implementation->setDecipheringTimeLimit( ::jmsf::ConstantPointer< _decipherTimeLimit >::createWeakFor( time ) );
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::setDecipherTime()" ) );
	}
	
	return 1;
}

int interface_MaskDm::getStatistics( GlobalStatisticsData *globalStatistics ) throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {

// 		::jmsf::Proxy< externals::data::statistics::ed_Summary > summary = externals::data::statistics::factory_ed_Statistics::instance()->createSummary();
// 		_implementation->getStatistics( summary.getWeak() );
// 		::copyGlobalStatistics( summary->getData().get(), globalStatistics );
		const ::jmsf::ConstantProxy< externals::data::statistics::ed_Summary > summary = _implementation->getStatistics();
		::copyGlobalStatistics( summary->getData().get(), globalStatistics );
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::getStatistics()" ) );
	}
	
	return 1;
}

int interface_MaskDm::setFileAppenderFolders( const std::list< const std::string > &folderNameList ) throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {
		::jmsf::Proxy< ::jmsf::Container< ::jmsf::ConstantProxy< ::jmsf::TextString > > > folderNameContainer =
			::jmsf::factory_Container< ::jmsf::ConstantProxy< ::jmsf::TextString > >::instance()->createArray();

		for ( std::list< const std::string >::const_iterator folderIterator = folderNameList.begin(); folderIterator != folderNameList.end(); ++folderIterator ) {
			folderNameContainer->appendBack( ::jmsf::TEXT_STRING( folderIterator->c_str() ) );
		}

		_implementation->changeFileAppenderFolders( folderNameContainer.takeConstant() );
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::setFileAppenderFolders()" ) );
	}
	
	return 1;
}

int interface_MaskDm::clearExpiredServiceFiles() throw() {
	if ( _implementation->wasInitializedCorrectly().not() ) return 0;

	try {
		_implementation->clearExpiredServiceFiles();
	} catch ( ... ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::getStatistics()" ) );
	}
	
	return 1;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
interface_MaskDm::~interface_MaskDm() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
interface_MaskDm::interface_MaskDm() throw() {
	

	try {
		_implementation = factory_MaskDm::instance()->createMaskDm();
	} catch ( const ::jmsf::Exception &catched ) {
		::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( catched.getReason() );
	} catch ( ... ) {
				::jmsf::Proxy< ::jmsf::osie::PopUpMessage > exceptionPopUpMessage =
			::jmsf::osie::factory_OperatingSystem::instance()->getUtilityControl()->createPopUpMessage( ::jmsf::CONSTANT_TEXT_STRING( "Exception inside MaskDm" ) );

		exceptionPopUpMessage->showOk( ::jmsf::CONSTANT_TEXT_STRING( "Unknown exception catched in interface_MaskDm::interface_MaskDm()" ) );
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
interface_MaskDm::interface_MaskDm( const interface_MaskDm & ) throw() // other
{}

const interface_MaskDm &interface_MaskDm::operator =( const interface_MaskDm &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
