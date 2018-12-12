#include "realization_ed_FileFilter.h"
#include "../ed_VoiceFile.h"
#include "../ed_ServiceFile.h"
#include "../../others/abstractFilter.h"

#include "jmsf/osie/Mutex.h"
#include "jmsf/Casts.hpp"
#include "jmsf/factory_TextObject.h"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {
namespace realizations {


void realization_ed_FileFilter::renew( const ::jmsf::ConstantProxy< ed_FileFilter > &fileFilter ) throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	
	if ( fileFilter->isNull() ) return;

	const ::jmsf::ConstantPointer< realization_ed_FileFilter > implementationFileFilter = ::jmsf::constantDowncast< realization_ed_FileFilter >( fileFilter, ::jmsf::CONSTANT_TEXT_STRING( "ed_FileFilter -> imple_ed_FileFilter" ) );
	::changeFilter( implementationFileFilter.get()->_fileFilterData.getWeakConstant().get(), _fileFilterData.get() );
}

const ::jmsf::Boolean realization_ed_FileFilter::isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception ) {
	return ::isDeletedFile( voiceFile->getData().get(), _fileFilterData.getWeakConstant().get() );
}

const ::jmsf::Boolean realization_ed_FileFilter::isFileLifeTimeExpired( const ::jmsf::ConstantProxy< ed_ServiceFile > &serviceFile ) const throw( ::jmsf::Exception ) {
	return ::isDeletedFile( serviceFile->getData().get(), _fileFilterData.getWeakConstant().get() );
}

const ::jmsf::Boolean realization_ed_FileFilter::isFileSuitableForDeciphering( const ::jmsf::ConstantProxy< ed_VoiceFile > &voiceFile ) const throw( ::jmsf::Exception ) {
	return ::isDecipheredFile( voiceFile->getData().get(), _fileFilterData.getWeakConstant().get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ed_FileFilter::~realization_ed_FileFilter() throw() {
	// REFACTOR: remove automatic deleting
//	::deleteFilter( _fileFilterData.get() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ed_FileFilter::realization_ed_FileFilter(
	::jmsf::Pointer< FilterData > fileFilterData,
	::jmsf::Proxy< ::jmsf::osie::Mutex > mutex ) throw()
	:
		mixin_Lockable( mutex ),
		_fileFilterData( fileFilterData )		
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ed_FileFilter > realization_ed_FileFilter::createClone() const throw() {
	return ::jmsf::Proxy< ed_FileFilter >::createUnique( new realization_ed_FileFilter( *this ) );
}

realization_ed_FileFilter::realization_ed_FileFilter( const realization_ed_FileFilter & ) throw( ::jmsf::Exception ) // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >::createNone() )
{
	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_FileFilter::realization_ed_FileFilter()" );
}

const realization_ed_FileFilter &realization_ed_FileFilter::operator =( const realization_ed_FileFilter &other ) throw( ::jmsf::Exception ) {
	if ( this == &other ) return *this;

	::jmsf::Should::neverViolateCopyingProhibition( "realization_ed_FileFilter::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
}
