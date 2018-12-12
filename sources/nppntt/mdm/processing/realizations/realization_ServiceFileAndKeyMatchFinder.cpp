#include "realization_ServiceFileAndKeyMatchFinder.h"
#include "../../externals/software/es_ServiceFileAndKeyPairMatchChecker.h"
#include "../../externals/data/ed_FileFilter.h"
#include "../../externals/data/ed_VoiceFile.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "../ServiceFileArray.h"
//#include "jmsf/osie/runup/Thread.h"
//#include "jmsf/osie/runup/EventArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/debugging/factory_DebuggingObject.h"
#include "jmsf/debugging/Log.h"
#include "jmsf/Container.hpp"
#include "jmsf/Iterator.hpp"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Casts.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

void realization_ServiceFileAndKeyMatchFinder::run() throw( ::jmsf::Exception ) {
	_sourceVoiceFileAndKeyPairQueue->takeMutex()->lock();

	if ( _sourceVoiceFileAndKeyPairQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceVoiceFileAndKeyPairQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > voiceFileAndKeyPair =
		_sourceVoiceFileAndKeyPairQueue->withdrawFirst();

	_sourceVoiceFileAndKeyPairQueue->takeMutex()->unlock();

	_serviceFileArray->takeMutex()->lock();
	::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &serviceFiles = _serviceFileArray->takeAccessToServiceFiles();
	
	::jmsf::Boolean isVoiceFileAndSmsPairFound;
	::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFileForMatchedPair;

	::jmsf::natural_size quantityOfServiceFilesInRange = 0;
	::jmsf::natural_size quantityOfSuitableServiceFilesInRange = 0;
	::jmsf::Boolean isRangeStarted;
	::jmsf::Boolean isRangeEnded;

	for (
		::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > serviceFileIterator = serviceFiles->createForwardIterator();
		serviceFileIterator->isNotDone().and( isRangeEnded.not() );
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

		if ( voiceFileAndKeyPair->getFirst()->isServiceFileSuitable( serviceFileIterator->getContainie().getWeakConstant() ).not() ) {
			if ( isRangeStarted ) {
				isRangeEnded = ::jmsf::True;
			}

			continue;
		}

		if ( isRangeStarted.not() ) {
			isRangeStarted = ::jmsf::True;
		}

		quantityOfServiceFilesInRange += 1;

		if ( voiceFileAndKeyPair->getSecond()->isFileSuitable( serviceFileIterator->getContainie().getWeakConstant() ).not() ) {
			continue;
		}

		quantityOfSuitableServiceFilesInRange += 1;

		if ( serviceFileIterator->getContainie()->isSuccessfullyProcessed() ) {
			if ( isVoiceFileAndSmsPairFound.not() ) {
				if ( voiceFileAndKeyPair->getSecond()->isEqual( serviceFileIterator->getContainie()->getKey().getWeak() ) ) {
					serviceFileForMatchedPair = serviceFileIterator->withdrawContainie();
					isVoiceFileAndSmsPairFound = ::jmsf::True;
				}
			}
		} else {
			::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_ServiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > serviceFileAndKeyPair =
				::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_ServiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair(
					serviceFileIterator->getContainie().getWeak(),
					voiceFileAndKeyPair->getSecond().getWeak() );

			_serviceFileAndKeyPairMatchChecker->setPair( serviceFileAndKeyPair.getWeak() );

// 			continueRunningOfNestedRunnables();
// 			waitTillRunningOfNestedRunnablesIsStopped();

			if ( _serviceFileAndKeyPairMatchChecker->isPairMatched() ) {
				serviceFileIterator->takeContainie()->updateKey( voiceFileAndKeyPair->getSecond().getWeak() );

				if ( isVoiceFileAndSmsPairFound ) {
					serviceFileIterator->takeContainie()->markAsSuccessfullyProcessed();					
					_destinationServiceFileQueue->takeMutex()->lock();
					_destinationServiceFileQueue->appendBack( serviceFileIterator->takeContainie() );
					_destinationServiceFileQueue->takeMutex()->unlock();					
				} else {
					serviceFileForMatchedPair = serviceFileIterator->withdrawContainie();
					isVoiceFileAndSmsPairFound = ::jmsf::True;
				}
			}
		}
	}

	_serviceFileArray->takeMutex()->unlock();

	if ( isVoiceFileAndSmsPairFound ) {
		::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > voiceFileAndSmsFilePair =
			::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > >::instance()->createPair(
				voiceFileAndKeyPair->takeFirst(),
				serviceFileForMatchedPair );

		_destinationVoiceFileAndServiceFilePairQueue->takeMutex()->lock();
		_destinationVoiceFileAndServiceFilePairQueue->appendBack( voiceFileAndSmsFilePair );
		_destinationVoiceFileAndServiceFilePairQueue->takeMutex()->unlock();
	} else {
		_destinationVoiceFileQueue->takeMutex()->lock();
		_destinationVoiceFileQueue->appendBack( voiceFileAndKeyPair->takeFirst() );
		_destinationVoiceFileQueue->takeMutex()->unlock();
	}

	_logFile->putNatural( quantityOfServiceFilesInRange )->put( ::jmsf::CONSTANT_TEXT_STRING( " " ) )->putNatural( quantityOfSuitableServiceFilesInRange )->putEol();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_ServiceFileAndKeyMatchFinder::~realization_ServiceFileAndKeyMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_ServiceFileAndKeyMatchFinder::realization_ServiceFileAndKeyMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > > > &sourceVoiceFileAndKeyPairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_VoiceFile >, ::jmsf::Proxy< externals::data::ed_ServiceFile > > > > > &destinationVoiceFileAndServiceFilePairQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_VoiceFile > > > &destinationVoiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::ConstantProxy< externals::data::ed_FileFilter > &fileFilter,
		const ::jmsf::Proxy< ServiceFileArray > &serviceFileArray,
		const ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > &serviceFileAndKeyPairMatchChecker ) throw()
	:
		_sourceVoiceFileAndKeyPairQueue( sourceVoiceFileAndKeyPairQueue ),
		_destinationVoiceFileAndServiceFilePairQueue( destinationVoiceFileAndServiceFilePairQueue ),
		_destinationVoiceFileQueue( destinationVoiceFileQueue ),
		_destinationServiceFileQueue( destinationServiceFileQueue ),
		_destinationServiceFileForDeletingQueue( destinationServiceFileForDeletingQueue ),
		_fileFilter( fileFilter ),
		_serviceFileArray( serviceFileArray ),
		_serviceFileAndKeyPairMatchChecker( serviceFileAndKeyPairMatchChecker ),
		_logFile( ::jmsf::debugging::factory_DebuggingObject::instance()->createLog( ::jmsf::CONSTANT_TEXT_STRING( "serviceFileRangeQuatity.txt" ) ) )
{
// 	appendWaitableEvent( _sourceVoiceFileAndKeyPairQueue->getOneselfIsObjectAvailableEvent() );
// 	appendNestedRunnable( ::jmsf::adjacentCast< ::jmsf::osie::runup::Runnable >( _serviceFileAndKeyPairMatchChecker.getWeak() ) );	
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< ServiceFileAndKeyMatchFinder > realization_ServiceFileAndKeyMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< ServiceFileAndKeyMatchFinder >::createUnique( new realization_ServiceFileAndKeyMatchFinder( *this ) );
}

realization_ServiceFileAndKeyMatchFinder::realization_ServiceFileAndKeyMatchFinder( const realization_ServiceFileAndKeyMatchFinder & ) throw() // other
{}

const realization_ServiceFileAndKeyMatchFinder &realization_ServiceFileAndKeyMatchFinder::operator =( const realization_ServiceFileAndKeyMatchFinder &other ) throw() {
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
