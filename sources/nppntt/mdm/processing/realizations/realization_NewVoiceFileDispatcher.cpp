#include "realization_NewVoiceFileDispatcher.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_FileFilter.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/debugging/factory_DebuggingObject.h"
#include "jmsf/debugging/Log.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/factory_TextObject.h"
#include "jmsf/TextString.h"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_NewVoiceFileDispatcher::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();

	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	const ::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();
	_fileFilter->takeMutex()->lock();

	if ( _fileFilter->isFileLifeTimeExpired( voiceFile.getWeakConstant() ) ) {
		_fileFilter->takeMutex()->unlock();
		_destinationVoiceFileForDeletingQueue->takeMutex()->lock();
		_destinationVoiceFileForDeletingQueue->appendBack( voiceFile );
		_destinationVoiceFileForDeletingQueue->takeMutex()->unlock();
		return;
	} else if ( _fileFilter->isFileSuitableForDeciphering( voiceFile.getWeakConstant() ) ) {
		_fileFilter->takeMutex()->unlock();
		_realVoiceFileForDecipheringQueue->takeMutex()->lock();

		const ::jmsf::natural_size quantityOfElementsInRealVoiceFileForDecipheringQueue =
			_realVoiceFileForDecipheringQueue->getQuantityOfObjects();

		_realVoiceFileForDecipheringQueue->takeMutex()->unlock();

		_logFile->putNatural( quantityOfElementsInRealVoiceFileForDecipheringQueue )->putEol();

		if ( quantityOfElementsInRealVoiceFileForDecipheringQueue < DECIPHER_QUEUE_THRESHOLD ) {
			_destinationVoiceFileForDecipheringQueue->takeMutex()->lock();
			_destinationVoiceFileForDecipheringQueue->appendBack( voiceFile );
			_destinationVoiceFileForDecipheringQueue->takeMutex()->unlock();
			return;
		}
	} else {
		_fileFilter->takeMutex()->unlock();
	}
	
	_destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue->takeMutex()->lock();
	_destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue->appendBack( voiceFile );
	_destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NewVoiceFileDispatcher::~realization_NewVoiceFileDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NewVoiceFileDispatcher::realization_NewVoiceFileDispatcher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDecipheringQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &realVoiceFileForDecipheringQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw()
	:
		_sourceVoiceFileQueue( sourceVoiceFileQueue.getWeak() ),
		_destinationVoiceFileForDecipheringQueue( destinationVoiceFileForDecipheringQueue.getWeak() ),
		_realVoiceFileForDecipheringQueue( realVoiceFileForDecipheringQueue.getWeak() ),
		_destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue( destinationVoiceFileForPreliminarySearchForAMatchWithKeyQueue.getWeak() ),
		_destinationVoiceFileForDeletingQueue( destinationVoiceFileForDeletingQueue.getWeak() ),
		_fileFilter( fileFilter.getWeak() ),
		_logFile( ::jmsf::debugging::factory_DebuggingObject::instance()->createLog( ::jmsf::CONSTANT_TEXT_STRING( "decipherQueueDepth.txt" ) ) )
{
//	appendWaitableEvent( _sourceVoiceFileQueue->getOneselfIsObjectAvailableEvent() );	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewVoiceFileDispatcher > realization_NewVoiceFileDispatcher::createClone() const throw() {
	return ::jmsf::Proxy< NewVoiceFileDispatcher >::createUnique( new realization_NewVoiceFileDispatcher( *this ) );
}

realization_NewVoiceFileDispatcher::realization_NewVoiceFileDispatcher( const realization_NewVoiceFileDispatcher & ) throw() // other
{}

const realization_NewVoiceFileDispatcher &realization_NewVoiceFileDispatcher::operator =( const realization_NewVoiceFileDispatcher &other ) throw() {
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
