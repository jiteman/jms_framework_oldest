#include "realization_VoiceFileDeleter.h"
#include "../../externals/others/abstractFileDescriptor.h"
#include "../../externals/software/es_FileDeleter.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_VoiceFileDeleter::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();

	_fileDeleter->deleteFile(
		voiceFile->takeData().getWeak(),
		voiceFile->takeAppliedData().getWeak() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_VoiceFileDeleter::~realization_VoiceFileDeleter() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_VoiceFileDeleter::realization_VoiceFileDeleter(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< externals::software::es_FileDeleter > &fileDeleter ) throw()
	:
		_sourceVoiceFileQueue( sourceVoiceFileQueue ),
		_fileDeleter( fileDeleter )
{
//	appendWaitableEvent( _sourceVoiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< VoiceFileDeleter > realization_VoiceFileDeleter::createClone() const throw() {
	return ::jmsf::Proxy< VoiceFileDeleter >::createUnique( new realization_VoiceFileDeleter( *this ) );
}

realization_VoiceFileDeleter::realization_VoiceFileDeleter( const realization_VoiceFileDeleter & ) throw() // other
{}

const realization_VoiceFileDeleter &realization_VoiceFileDeleter::operator =( const realization_VoiceFileDeleter &other ) throw() {
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
