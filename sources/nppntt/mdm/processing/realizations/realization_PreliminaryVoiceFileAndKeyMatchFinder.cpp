#include "realization_PreliminaryVoiceFileAndKeyMatchFinder.h"
#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.h"
#include "../../externals/data/ed_FileFilter.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/ConstantIterator.hpp"
#include "jmsf/factory_TextObject.h"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointer.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_PreliminaryVoiceFileAndKeyMatchFinder::run() throw( ::jmsf::Exception ) {
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
		_destinationVoiceFileForDeletingQueue->takeMutex()->lock();
		_destinationVoiceFileForDeletingQueue->appendBack( voiceFile );
		_destinationVoiceFileForDeletingQueue->takeMutex()->unlock();
	} else {
		_fileFilter->takeMutex()->unlock();
	}

	_keyArray->takeMutex()->lock();

	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > lastAmountOfKeyContainer =
		_keyArray->getLastAmountOfKeys( AMOUNT_OF_LAST_KEYS_TO_APPLY );

	_keyArray->takeMutex()->unlock();

	if ( lastAmountOfKeyContainer.isNotEmpty() ) {
		::jmsf::Proxy< ::jmsf::ConstantIterator< ::jmsf::ConstantProxy< externals::data::ed_Key > > > keyIterator = lastAmountOfKeyContainer->createConstantForwardIterator();	
		::jmsf::Boolean isMatchFound;

		while ( keyIterator->isNotDone() ) {
			// prepare for the search
			{
				for (
					::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > checkerIterator = _voiceFileAndKeyPairMatchCheckerArray->createForwardIterator();
					checkerIterator->isNotDone();
					checkerIterator->advance() )
				{
					::jmsf::ConstantProxy< externals::data::ed_Key > key;
			
					while ( keyIterator->isNotDone() ) {
						key = keyIterator->getContainie().getWeak();

						if ( key.getWeak()->isFileSuitable( voiceFile.getWeakConstant() ) ) {
							break;
						} else {
							keyIterator->advance();
						}
					}

					if ( keyIterator->isDone() ) {
						key = ::jmsf::ConstantProxy< externals::data::ed_Key >();
					} else {
						voiceFile->updateLastAppliedKey( key.getWeak() );
						keyIterator->advance();
					}				

					::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > voiceFileAndKeyPair =
						::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair( voiceFile.getWeak(), key );

					checkerIterator->takeContainie()->setPair( voiceFileAndKeyPair );
				}
			}

			// search for a match
// 			continueRunningOfNestedRunnables();
// 			waitTillRunningOfNestedRunnablesIsStopped();
		
			// get result
			{			
				for (
					::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > checkerIterator = _voiceFileAndKeyPairMatchCheckerArray->createForwardIterator();
					checkerIterator->isNotDone();
					checkerIterator->advance() )
				{
					if ( checkerIterator->getContainie()->isPairMatched() ) {
						isMatchFound = ::jmsf::True;
						const ::jmsf::ConstantProxy< externals::data::ed_Key > foundKey = checkerIterator->getContainie()->getTheKey();

						::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > properVoiceFileAndKeyPair =
							::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair( voiceFile, foundKey );

						_destinationMatchedVoiceFileAndKeyPairQueue->takeMutex()->lock();
						_destinationMatchedVoiceFileAndKeyPairQueue->appendBack( properVoiceFileAndKeyPair );
						_destinationMatchedVoiceFileAndKeyPairQueue->takeMutex()->unlock();
						return;
					}
				}
			}
		}
	}

	_destinationVoiceFileWithNoMatchFoundQueue->takeMutex()->lock();
	_destinationVoiceFileWithNoMatchFoundQueue->appendBack( voiceFile );
	_destinationVoiceFileWithNoMatchFoundQueue->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_PreliminaryVoiceFileAndKeyMatchFinder::~realization_PreliminaryVoiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_PreliminaryVoiceFileAndKeyMatchFinder::realization_PreliminaryVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationMatchedVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileWithNoMatchFoundQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletingQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > &voiceFileAndKeyPairMatchCheckerArray ) throw()
	:
		_sourceVoiceFileQueue( sourceVoiceFileQueue ),
		_destinationMatchedVoiceFileAndKeyPairQueue( destinationMatchedVoiceFileAndKeyPairQueue ),
		_destinationVoiceFileWithNoMatchFoundQueue( destinationVoiceFileWithNoMatchFoundQueue ),
		_destinationVoiceFileForDeletingQueue( destinationVoiceFileForDeletingQueue ),
		_keyArray( keyArray ),
		_fileFilter( fileFilter ),
		_voiceFileAndKeyPairMatchCheckerArray( voiceFileAndKeyPairMatchCheckerArray )
{
// 	for (
// 		::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > voiceFileAndKeyPairMatchCheckerIterator =
// 			_voiceFileAndKeyPairMatchCheckerArray->createForwardIterator();
// 		voiceFileAndKeyPairMatchCheckerIterator->isNotDone();
// 		voiceFileAndKeyPairMatchCheckerIterator->advance() )
// 	{
// 		appendNestedRunnable(
// 			::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor(
// 				voiceFileAndKeyPairMatchCheckerIterator->getContainie().get() ) );
// 	}
// 
// 	appendWaitableEvent( _sourceVoiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder > realization_PreliminaryVoiceFileAndKeyMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< PreliminaryVoiceFileAndKeyMatchFinder >::createUnique( new realization_PreliminaryVoiceFileAndKeyMatchFinder( *this ) );
}

realization_PreliminaryVoiceFileAndKeyMatchFinder::realization_PreliminaryVoiceFileAndKeyMatchFinder( const realization_PreliminaryVoiceFileAndKeyMatchFinder & ) throw() // other
{}

const realization_PreliminaryVoiceFileAndKeyMatchFinder &realization_PreliminaryVoiceFileAndKeyMatchFinder::operator =( const realization_PreliminaryVoiceFileAndKeyMatchFinder &other ) throw() {
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
