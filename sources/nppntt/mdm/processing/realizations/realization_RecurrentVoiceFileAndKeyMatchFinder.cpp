#include "realization_RecurrentVoiceFileAndKeyMatchFinder.h"
#include "../../externals/software/es_VoiceFileAndKeyPairMatchChecker.h"
#include "../../externals/data/ed_FileFilter.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "jmsf/osie/Event.h"
#include "jmsf/osie/EventArray.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
//#include "jmsf/DynamicCast.hpp"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/Iterator.hpp"
#include "jmsf/PointersAndProxies.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_RecurrentVoiceFileAndKeyMatchFinder::run() throw( ::jmsf::Exception ) {
	if ( _voiceFileIterator->isDone() ) {
		_areAllAvailableVoiceFilesAndKeysProcessed = _wasAtLeastOneKeySelected.not();
		_wasAtLeastOneKeySelected = ::jmsf::False;
		// get new files from the source queue
		_sourceVoiceFileQueue->takeMutex()->lock();

		// if there is no new source voice file and no key was selected...
		if ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isNotSet().and( _areAllAvailableVoiceFilesAndKeysProcessed ) ) {
			_sourceVoiceFileQueue->takeMutex()->unlock();

			// ...wait for new source voice file or new key
			if ( _voiceFileContainer->isEmpty() ) {
				_objectAvailableAndContinueRunningAndFinalizeRunningEvents->waitForAnyEvent();
			} else {
				::jmsf::Proxy< ::jmsf::osie::Event > lastOccuredEvent = _objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents->waitForAnyEventThenGetItOneself();

				if ( lastOccuredEvent == _keyArray->getIsNewKeyAvailableEvent() ) {
					_keyArray->takeIsNewKeyAvailableEvent()->reset();
				}
			}

//			_areAllAvailableVoiceFilesAndKeysProcessed = ::jmsf::False;
			return;
		} else {
			while ( _sourceVoiceFileQueue->getIsObjectAvailableEvent()->isSet() ) {			
				::jmsf::Proxy< externals::data::ed_VoiceFile > voiceFile = _sourceVoiceFileQueue->withdrawFirst();			
				_voiceFileContainer->appendFront( voiceFile );
			}
//			_areAllAvailableVoiceFilesAndKeysProcessed = ::jmsf::False;
			_sourceVoiceFileQueue->takeMutex()->unlock();
		}		

		_voiceFileIterator = _voiceFileContainer->createForwardIterator();

		// if there is still no file...
		if ( _voiceFileIterator->isDone() ) {
			// ...wait for a new one
			_objectAvailableAndContinueRunningAndFinalizeRunningEvents->waitForAnyEvent();
			return;
		}
	}

	{
		_fileFilter->takeMutex()->lock();

		const ::jmsf::Boolean isCurrentFileLifeTimeExpired =
			_fileFilter->isFileLifeTimeExpired( _voiceFileIterator->getContainie().getWeakConstant() );

		_fileFilter->takeMutex()->unlock();

		if ( isCurrentFileLifeTimeExpired ) {
			_destinationVoiceFileForDeletionQueue->takeMutex()->lock();
			_destinationVoiceFileForDeletionQueue->appendBack( _voiceFileIterator->withdrawContainie() );
			_destinationVoiceFileForDeletionQueue->takeMutex()->unlock();
			return;
		}
	}

	// OPTIMIZE: create internal array with appropriate size to get keys
	_keyArray->takeMutex()->lock();
	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > lastAmountOfKeyContainer = _keyArray->getLastAmountOfKeys();
	_keyArray->takeMutex()->unlock();

	if ( lastAmountOfKeyContainer.isEmpty() ) {
		_voiceFileIterator->advance();
		return;
	}

	if ( _voiceFileIterator->getContainie()->getLastAppliedKey().isNotEmpty() ) {
		if ( lastAmountOfKeyContainer->getLastContainie()->getIdentifier() <= _voiceFileIterator->getContainie()->getLastAppliedKey()->getIdentifier() ) {
			// skip current file
			_voiceFileIterator->advance();
			return;
		}
	}

	::jmsf::Proxy< ::jmsf::ConstantIterator< ::jmsf::ConstantProxy< externals::data::ed_Key > > > keyIterator = lastAmountOfKeyContainer->createConstantForwardIterator();

	if ( _voiceFileIterator->getContainie()->getLastAppliedKey().isNotEmpty() ) {
		while (
			::jmsf::Boolean( keyIterator->isNotDone() ).and(
			keyIterator->getContainie()->getIdentifier() <= _voiceFileIterator->getContainie()->getLastAppliedKey()->getIdentifier() ) )
		{
			keyIterator->advance();
		}
	}

	if ( keyIterator->isNotDone() ) {
		_wasAtLeastOneKeySelected = ::jmsf::True;
	}
	
	while ( keyIterator->isNotDone() ) {
		// prepare data for a search
		{
			for (
				::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > checkerIterator =
					_voiceFileAndKeyPairMatchCheckerArray->createForwardIterator();
				checkerIterator->isNotDone();
				checkerIterator->advance() )
			{
				::jmsf::ConstantProxy< externals::data::ed_Key > key;
			
				while ( keyIterator->isNotDone() ) {
					key = keyIterator->getContainie();

					if ( key.getWeak()->isFileSuitable( _voiceFileIterator->getContainie().getWeakConstant() ) ) {
						break;
					} else {
						keyIterator->advance();
					}
				}

				if ( keyIterator->isDone() ) {
					key = ::jmsf::ConstantProxy< externals::data::ed_Key >();
				} else {
					_voiceFileIterator->takeContainie()->updateLastAppliedKey( key.getWeak() );
					keyIterator->advance();
				}

				::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > voiceFileAndKeyPair =
					::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair( 
						_voiceFileIterator->takeContainie().getWeak(),
						key.getWeak() );
				
				checkerIterator->takeContainie()->setPair( voiceFileAndKeyPair );
			}
		}

		// search for a match
// 		continueRunningOfNestedRunnables();
// 		waitTillRunningOfNestedRunnablesIsStopped();
		
		// get the result
		{
			for (
				::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > checkerIterator =
					_voiceFileAndKeyPairMatchCheckerArray->createForwardIterator();
				checkerIterator->isNotDone();
				checkerIterator->advance() )
			{
				if ( checkerIterator->getContainie()->isPairMatched() ) {
					::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > properVoiceFileAndKeyPair =
						::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair(
							_voiceFileIterator->withdrawContainie(),
							checkerIterator->getContainie()->getTheKey() );

					_destinationMatchedVoiceFileAndKeyPairQueue->takeMutex()->lock();
					_destinationMatchedVoiceFileAndKeyPairQueue->appendBack( properVoiceFileAndKeyPair );
					_destinationMatchedVoiceFileAndKeyPairQueue->takeMutex()->unlock();
					return;
				}
			}			
		}
	}

	_voiceFileIterator->advance();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_RecurrentVoiceFileAndKeyMatchFinder::~realization_RecurrentVoiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_RecurrentVoiceFileAndKeyMatchFinder::realization_RecurrentVoiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &sourceVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &destinationMatchedVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileForDeletionQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_VoiceFileAndKeyPairMatchChecker > > > &voiceFileAndKeyPairMatchCheckerArray,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &voiceFileContainer,
		const ::jmsf::Proxy< ::jmsf::osie::EventArray > &firstEventArray,
		const ::jmsf::Proxy< ::jmsf::osie::EventArray > &secondEventArray ) throw()
	:
		_sourceVoiceFileQueue( sourceVoiceFileQueue ),
		_destinationMatchedVoiceFileAndKeyPairQueue( destinationMatchedVoiceFileAndKeyPairQueue ),
		_destinationVoiceFileForDeletionQueue( destinationVoiceFileForDeletionQueue ),
		_keyArray( keyArray ),
		_fileFilter( fileFilter ),
		_voiceFileAndKeyPairMatchCheckerArray( voiceFileAndKeyPairMatchCheckerArray ),
		_voiceFileContainer( voiceFileContainer ),
		_voiceFileIterator( _voiceFileContainer->createForwardIterator() ),
		_objectAvailableAndContinueRunningAndFinalizeRunningEvents( firstEventArray ),
		_objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents( secondEventArray )
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

	_objectAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( _sourceVoiceFileQueue->takeIsObjectAvailableEvent().getWeak() );
// 	_objectAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( getOneselfStopRunningEvent() );
// 	_objectAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( getOneselfFinalizeRunningEvent() );

	_objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( _sourceVoiceFileQueue->takeIsObjectAvailableEvent().getWeak() );
	_objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( _keyArray->takeIsNewKeyAvailableEvent().getWeak() );
// 	_objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( getOneselfStopRunningEvent() );
// 	_objectAvailableAndNewKeyAvailableAndContinueRunningAndFinalizeRunningEvents->appendEvent( getOneselfFinalizeRunningEvent() );

	_areAllAvailableVoiceFilesAndKeysProcessed = ::jmsf::True;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder > realization_RecurrentVoiceFileAndKeyMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< RecurrentVoiceFileAndKeyMatchFinder >::createUnique( new realization_RecurrentVoiceFileAndKeyMatchFinder( *this ) );
}

realization_RecurrentVoiceFileAndKeyMatchFinder::realization_RecurrentVoiceFileAndKeyMatchFinder( const realization_RecurrentVoiceFileAndKeyMatchFinder & ) throw() // other
{}

const realization_RecurrentVoiceFileAndKeyMatchFinder &realization_RecurrentVoiceFileAndKeyMatchFinder::operator =( const realization_RecurrentVoiceFileAndKeyMatchFinder &other ) throw() {
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
