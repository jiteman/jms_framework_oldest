#include "realization_ServiceFileDeleter.h"
#include "../../externals/others/abstractFileDescriptor.h"
#include "../../externals/software/es_FileDeleter.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_ServiceFileDeleter::run() throw( ::jmsf::Exception ) {
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceServiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_ServiceFile > voiceFile = _sourceServiceFileQueue->withdrawFirst();
	_sourceServiceFileQueue->takeMutex()->unlock();

	_fileDeleter->deleteFile(
		voiceFile->takeData().getWeak(),
		voiceFile->takeAppliedData().getWeak() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ServiceFileDeleter::~realization_ServiceFileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ServiceFileDeleter::realization_ServiceFileDeleter(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_FileDeleter > &fileDeleter ) throw()
	:
		_sourceServiceFileQueue( sourceServiceFileQueue ),
		_fileDeleter( fileDeleter )
{
//	appendWaitableEvent( _sourceServiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ServiceFileDeleter > realization_ServiceFileDeleter::createClone() const throw() {
	return ::jmsf::Proxy< ServiceFileDeleter >::createUnique( new realization_ServiceFileDeleter( *this ) );
}

realization_ServiceFileDeleter::realization_ServiceFileDeleter( const realization_ServiceFileDeleter & ) throw() // other
{}

const realization_ServiceFileDeleter &realization_ServiceFileDeleter::operator =( const realization_ServiceFileDeleter &other ) throw() {
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
