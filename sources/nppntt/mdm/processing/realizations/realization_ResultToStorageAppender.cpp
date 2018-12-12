#include "realization_ResultToStorageAppender.h"
#include "../../externals/software/es_StorageAppender.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

void realization_ResultToStorageAppender::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileAndServiceFilePairQueue->takeMutex()->lock();

	if ( _sourceVoiceFileAndServiceFilePairQueue->getIsObjectAvailableEvent()->isSet() ) {
		::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > voiceFileAndServiceFilePair =
			_sourceVoiceFileAndServiceFilePairQueue->withdrawFirst();

		_sourceVoiceFileAndServiceFilePairQueue->takeMutex()->unlock();

		{
			const ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::ConstantProxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > weakVoiceFileAndServiceFilePair =
				::jmsf::factory_Pair< ::jmsf::ConstantProxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createPair(
					voiceFileAndServiceFilePair->getFirst().getWeakConstant(),
					voiceFileAndServiceFilePair->takeSecond().getWeak() );

			_storageAppender->store( weakVoiceFileAndServiceFilePair );
		}

		_destinationVoiceFileForDeletingQueue->takeMutex()->lock();
		_destinationVoiceFileForDeletingQueue->appendBack( voiceFileAndServiceFilePair->takeFirst() );
		_destinationVoiceFileForDeletingQueue->takeMutex()->unlock();
		_destinationServiceFileForDeletingQueue->takeMutex()->lock();
		_destinationServiceFileForDeletingQueue->appendBack( voiceFileAndServiceFilePair->takeSecond() );
		_destinationServiceFileForDeletingQueue->takeMutex()->unlock();
	} else {
		_sourceVoiceFileAndServiceFilePairQueue->takeMutex()->unlock();
	}

	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet() ) {
		::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
		_sourceVoiceFileQueue->takeMutex()->unlock();
		_storageAppender->store( voiceFile.getWeakConstant() );
		_destinationVoiceFileForDeletingQueue->takeMutex()->lock();
		_destinationVoiceFileForDeletingQueue->appendBack( voiceFile );
		_destinationVoiceFileForDeletingQueue->takeMutex()->unlock();		
	} else {
		_sourceVoiceFileQueue->takeMutex()->unlock();
	}
	
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet() ) {
		::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile = _sourceServiceFileQueue->withdrawFirst();
		_sourceServiceFileQueue->takeMutex()->unlock();

		{
			::jmsf::Proxy< externals::data::ed_ServiceFile > weakServiceFile = serviceFile.getWeak();
			_storageAppender->store( weakServiceFile );
		}

// 		_destinationServiceFileForDeletingQueue->lock();
// 		_destinationServiceFileForDeletingQueue->appendBack( serviceFile );
// 		_destinationServiceFileForDeletingQueue->unlock();
	} else {
		_sourceServiceFileQueue->takeMutex()->unlock();
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ResultToStorageAppender::~realization_ResultToStorageAppender() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ResultToStorageAppender::realization_ResultToStorageAppender(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &sourceVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::Proxy< externals::software::es_StorageAppender > &storageAppender ) throw()
	:
		_sourceVoiceFileAndServiceFilePairQueue( sourceVoiceFileAndServiceFilePairQueue ),
		_sourceVoiceFileQueue( sourceVoiceFileQueue ),
		_sourceServiceFileQueue( sourceServiceFileQueue ),
		_destinationVoiceFileForDeletingQueue( destinationVoiceFileForDeletingQueue ),
		_destinationServiceFileForDeletingQueue( destinationServiceFileForDeletingQueue ),
		_storageAppender( storageAppender )
{
// 	appendWaitableEvent( _sourceVoiceFileAndServiceFilePairQueue->getOneselfIsObjectAvailableEvent() );
// 	appendWaitableEvent( _sourceVoiceFileQueue->getOneselfIsObjectAvailableEvent() );
// 	appendWaitableEvent( _sourceServiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ResultToStorageAppender > realization_ResultToStorageAppender::createClone() const throw() {
	return ::jmsf::Proxy< ResultToStorageAppender >::createUnique( new realization_ResultToStorageAppender( *this ) );
}

realization_ResultToStorageAppender::realization_ResultToStorageAppender( const realization_ResultToStorageAppender & ) throw() // other
{}

const realization_ResultToStorageAppender &realization_ResultToStorageAppender::operator =( const realization_ResultToStorageAppender &other ) throw() {
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
