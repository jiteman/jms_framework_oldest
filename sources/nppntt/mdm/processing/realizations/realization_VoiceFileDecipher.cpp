#include "realization_VoiceFileDecipher.h"
#include "../../externals/software/es_Decipher.h"
#include "../../externals/data/ed_FileFilter.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "../../processing/KeyArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointers.hpp"


namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_VoiceFileDecipher::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileQueue->takeMutex()->lock();
	
	if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();
	_sourceVoiceFileQueue->takeMutex()->unlock();
	_fileFilter->takeMutex()->lock();

	if ( _fileFilter->isFileLifeTimeExpired( voiceFile.getWeakConstant() ) ) {
		_fileFilter->takeMutex()->unlock();
		voiceFile->markAsDeletedFromDecipher();
		_destinationVoiceFileForDeletingQueue->takeMutex()->lock();
		_destinationVoiceFileForDeletingQueue->appendBack( voiceFile );
		_destinationVoiceFileForDeletingQueue->takeMutex()->unlock();
		return;
	} else if ( _fileFilter->isFileSuitableForDeciphering( voiceFile.getWeakConstant() ).not() ) {
		_fileFilter->takeMutex()->unlock();
		_destinationNotDecipheredVoiceFileAndKeyPairQueue->takeMutex()->lock();
		_destinationNotDecipheredVoiceFileAndKeyPairQueue->appendBack( voiceFile );
		_destinationNotDecipheredVoiceFileAndKeyPairQueue->takeMutex()->unlock();
		return;
	} else {
		_fileFilter->takeMutex()->unlock();
	}

	::jmsf::ConstantProxy< externals::data::ed_Key > key = _decipher->tryToDecipher( voiceFile.getWeak() ).takeConstant();
	
	if ( key.isEmpty() ) {
		_destinationNotDecipheredVoiceFileAndKeyPairQueue->takeMutex()->lock();
		_destinationNotDecipheredVoiceFileAndKeyPairQueue->appendBack( voiceFile );
		_destinationNotDecipheredVoiceFileAndKeyPairQueue->takeMutex()->unlock();
	} else {
		_keyArray->takeMutex()->lock();
		const ::jmsf::ConstantProxy< externals::data::ed_Key > existentKey = _keyArray->tryToAppendKeyAndGetNewOrExistingKey( key );
		_keyArray->takeMutex()->unlock();

		if ( existentKey.isNotEmpty() ) {
			key = existentKey;
		}

		::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > voiceFileAndKeyPair =
			::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair(
				voiceFile,
				key.getWeak() );

		_destinationDecipheredVoiceFileAndKeyPairQueue->takeMutex()->lock();
		_destinationDecipheredVoiceFileAndKeyPairQueue->appendBack( voiceFileAndKeyPair );
		_destinationDecipheredVoiceFileAndKeyPairQueue->takeMutex()->unlock();

		if ( existentKey.isEmpty() ) {
			_destinationKeyQueue->takeMutex()->lock();
			_destinationKeyQueue->appendBack( key );
			_destinationKeyQueue->takeMutex()->unlock();
		}
	}
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_VoiceFileDecipher::~realization_VoiceFileDecipher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_VoiceFileDecipher::realization_VoiceFileDecipher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationDecipheredVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &destinationKeyQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationNotDecipheredVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::Proxy< processing::KeyArray > &keyArray,
		const ::jmsf::Proxy< externals::software::es_Decipher > &decipher,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter ) throw()
	:
		_sourceVoiceFileQueue( sourceVoiceFileQueue ),
		_destinationDecipheredVoiceFileAndKeyPairQueue( destinationDecipheredVoiceFileAndKeyPairQueue ),
		_destinationKeyQueue( destinationKeyQueue ),
		_destinationNotDecipheredVoiceFileAndKeyPairQueue( destinationNotDecipheredVoiceFileAndKeyPairQueue ),
		_destinationVoiceFileForDeletingQueue( destinationVoiceFileForDeletingQueue ),
		_keyArray( keyArray ),
		_decipher( decipher ),
		_fileFilter( fileFilter )
{
//	appendWaitableEvent( _sourceVoiceFileQueue->getIsObjectAvailableEvent().getWeak() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< VoiceFileDecipher > realization_VoiceFileDecipher::createClone() const throw() {
	return ::jmsf::Proxy< VoiceFileDecipher >::createUnique( new realization_VoiceFileDecipher( *this ) );
}

realization_VoiceFileDecipher::realization_VoiceFileDecipher( const realization_VoiceFileDecipher & ) throw() // other
{}

const realization_VoiceFileDecipher &realization_VoiceFileDecipher::operator =( const realization_VoiceFileDecipher &other ) throw() {
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
