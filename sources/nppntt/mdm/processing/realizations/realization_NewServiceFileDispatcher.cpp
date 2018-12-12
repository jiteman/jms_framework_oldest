#include "realization_NewServiceFileDispatcher.h"
#include "../../externals/data/ed_FileFilter.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../ServiceFileArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_NewServiceFileDispatcher::run() throw( ::jmsf::Exception ) {
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceServiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile = _sourceServiceFileQueue->withdrawFirst();
	_sourceServiceFileQueue->takeMutex()->unlock();
	_fileFilter->takeMutex()->lock();
	
	if ( _fileFilter->isFileLifeTimeExpired( serviceFile.getWeakConstant() ) ) {
		_fileFilter->takeMutex()->unlock();
		_destinationServiceFileForDeletionQueue->takeMutex()->lock();
		_destinationServiceFileForDeletionQueue->appendBack( serviceFile );
		_destinationServiceFileForDeletionQueue->takeMutex()->unlock();
		return;
	} else {
		_fileFilter->takeMutex()->unlock();
	}

	_serviceFileArray->takeMutex()->lock();
	_serviceFileArray->append( serviceFile );
	_serviceFileArray->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NewServiceFileDispatcher::~realization_NewServiceFileDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NewServiceFileDispatcher::realization_NewServiceFileDispatcher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletionQueue,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw()
	:
		_sourceServiceFileQueue( sourceServiceFileQueue ),
		_destinationServiceFileForDeletionQueue( destinationServiceFileForDeletionQueue ),
		_serviceFileArray( serviceFileArray ),
		_fileFilter( fileFilter )
{
//	appendWaitableEvent( _sourceServiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewServiceFileDispatcher > realization_NewServiceFileDispatcher::createClone() const throw() {
	return ::jmsf::Proxy< NewServiceFileDispatcher >::createUnique( new realization_NewServiceFileDispatcher( *this ) );
}

realization_NewServiceFileDispatcher::realization_NewServiceFileDispatcher( const realization_NewServiceFileDispatcher & ) throw() // other
{}

const realization_NewServiceFileDispatcher &realization_NewServiceFileDispatcher::operator =( const realization_NewServiceFileDispatcher &other ) throw() {
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
