#include "realization_ServiceFileArray.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../../externals/data/ed_FileFilter.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_ServiceFileArray::append( const ::jmsf::Proxy< externals::data::ed_ServiceFile > &serviceFile ) throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > serviceFileIterator = _serviceFileContainer->createForwardIterator();

	for (
		;
		serviceFileIterator->isNotDone();
		serviceFileIterator->advance() )
	{
		if ( serviceFile->isEarly( serviceFileIterator->getContainie().getWeakConstant() ) ) {
			break;
		}		
	}

	serviceFileIterator->insert( serviceFile );
}

::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &realization_ServiceFileArray::takeAccessToServiceFiles() throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );
	return _serviceFileContainer;
}

void realization_ServiceFileArray::clearExpired() throw( ::jmsf::Exception ) {
	::jmsf::Should::alwaysBe( getMutex()->isLocked() );

	for (
		::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > serviceFileIterator = _serviceFileContainer->createForwardIterator();
		serviceFileIterator->isNotDone();
		serviceFileIterator->advance() )
	{
		_fileFilter->takeMutex()->lock();
		const ::jmsf::Boolean isCurrentServiceFileLifeTimeExpired = _fileFilter->isFileLifeTimeExpired( serviceFileIterator->getContainie().getWeakConstant() );
		_fileFilter->takeMutex()->unlock();

		if ( isCurrentServiceFileLifeTimeExpired ) {
			_destinationServiceFileForDeletingQueue->takeMutex()->lock();
			_destinationServiceFileForDeletingQueue->appendBack( serviceFileIterator->withdrawContainie() );
			_destinationServiceFileForDeletingQueue->takeMutex()->unlock();
			continue;
		}
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ServiceFileArray::~realization_ServiceFileArray() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ServiceFileArray::realization_ServiceFileArray(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &serviceFiles,
		const ::jmsf::Proxy< ::jmsf::osie::Mutex > &mutex ) throw()
	:
		mixin_Lockable( mutex ),
		_destinationServiceFileForDeletingQueue( destinationServiceFileForDeletingQueue ),
		_fileFilter( fileFilter ),
		_serviceFileContainer( serviceFiles )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ServiceFileArray > realization_ServiceFileArray::createClone() const throw() {
	return ::jmsf::Proxy< ServiceFileArray >::createUnique( new realization_ServiceFileArray( *this ) );
}

realization_ServiceFileArray::realization_ServiceFileArray( const realization_ServiceFileArray & ) throw() // other
	:
		mixin_Lockable( ::jmsf::Proxy< ::jmsf::osie::Mutex >::createEmpty() )
{}

const realization_ServiceFileArray &realization_ServiceFileArray::operator =( const realization_ServiceFileArray &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
}
