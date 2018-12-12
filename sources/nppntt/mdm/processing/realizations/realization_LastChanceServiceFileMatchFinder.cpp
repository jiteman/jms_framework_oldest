#include "realization_LastChanceServiceFileMatchFinder.h"
#include "../../externals/data/ed_ServiceFile.h"
#include "../../externals/data/ed_Key.h"
#include "../../externals/software/es_ServiceFileAndKeyPairMatchChecker.h"
#include "../KeyArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Container.hpp"
#include "jmsf/factory_Pair.hpp"
#include "jmsf/Pair.hpp"
#include "jmsf/Pointers.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void realization_LastChanceServiceFileMatchFinder::run() throw( ::jmsf::Exception ) {
	_sourceServiceFileQueue->takeMutex()->lock();

	if ( _sourceServiceFileQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceServiceFileQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::Proxy< externals::data::ed_ServiceFile > serviceFile = _sourceServiceFileQueue->withdrawFirst();
	_sourceServiceFileQueue->takeMutex()->unlock();

	if ( serviceFile->isNotSuccessfullyProcessed() ) {
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
						::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > checkerIterator = _serviceFileAndKeyPairMatchCheckerArray->createForwardIterator();
						checkerIterator->isNotDone();
						checkerIterator->advance() )
					{
						::jmsf::ConstantProxy< externals::data::ed_Key > key;
			
						while ( keyIterator->isNotDone() ) {
							key = keyIterator->getContainie().getWeak();

							if ( key.getWeak()->isFileSuitable( serviceFile.getWeakConstant() ) ) {
								break;
							} else {
								keyIterator->advance();
							}
						}

						if ( keyIterator->isDone() ) {
							key = ::jmsf::ConstantProxy< externals::data::ed_Key >();
						} else {
							keyIterator->advance();
						}				

						::jmsf::Proxy< ::jmsf::Pair< ::jmsf::Proxy< externals::data::ed_ServiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > > > serviceFileAndKeyPair =
							::jmsf::factory_Pair< ::jmsf::Proxy< externals::data::ed_ServiceFile >, ::jmsf::ConstantProxy< externals::data::ed_Key > >::instance()->createPair( serviceFile.getWeak(), key );

						checkerIterator->takeContainie()->setPair( serviceFileAndKeyPair );
					}
				}

				// search for a match
// 				continueRunningOfNestedRunnables();
// 				waitTillRunningOfNestedRunnablesIsStopped();
		
				// get result
				{			
					for (
						::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > checkerIterator =
							_serviceFileAndKeyPairMatchCheckerArray->createForwardIterator();
						checkerIterator->isNotDone();
						checkerIterator->advance() )
					{
						if ( checkerIterator->getContainie()->isPairMatched() ) {
							isMatchFound = ::jmsf::True;
							const ::jmsf::ConstantProxy< externals::data::ed_Key > foundKey = checkerIterator->getContainie()->getTheKey().getWeak();
							serviceFile->updateKey( foundKey );
							_destinationServiceFileWithMatchFoundQueue->takeMutex()->lock();
							_destinationServiceFileWithMatchFoundQueue->appendBack( serviceFile );
							_destinationServiceFileWithMatchFoundQueue->takeMutex()->unlock();
							return;
						}
					}
				}
			}
		}
	}

	_destinationServiceFileForDeletingQueue->takeMutex()->lock();
	_destinationServiceFileForDeletingQueue->appendBack( serviceFile );
	_destinationServiceFileForDeletingQueue->takeMutex()->unlock();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_LastChanceServiceFileMatchFinder::~realization_LastChanceServiceFileMatchFinder() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_LastChanceServiceFileMatchFinder::realization_LastChanceServiceFileMatchFinder(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &sourceServiceFileQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileWithMatchFoundQueue,
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::Proxy< externals::data::ed_ServiceFile > > > &destinationServiceFileForDeletingQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray,
		const ::jmsf::Proxy< ::jmsf::Container< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > &serviceFileAndKeyPairMatchCheckerArray ) throw()
	:
		_sourceServiceFileQueue( sourceServiceFileQueue ),
		_destinationServiceFileWithMatchFoundQueue( destinationServiceFileWithMatchFoundQueue ),
		_destinationServiceFileForDeletingQueue( destinationServiceFileForDeletingQueue ),
		_keyArray( keyArray ),
		_serviceFileAndKeyPairMatchCheckerArray( serviceFileAndKeyPairMatchCheckerArray )
{
// 	for (
// 		::jmsf::Proxy< ::jmsf::Iterator< ::jmsf::Proxy< externals::software::es_ServiceFileAndKeyPairMatchChecker > > > checkerIterator =
// 			_serviceFileAndKeyPairMatchCheckerArray->createForwardIterator();
// 		checkerIterator->isNotDone();
// 		checkerIterator->advance() )
// 	{
// 		appendNestedRunnable(
// 			::jmsf::Pointer< ::jmsf::osie::runup::Runnable >::createWeakFor(
// 				checkerIterator->getContainie().get() ) );
// 	}
// 
// 	appendWaitableEvent( _sourceServiceFileQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< LastChanceServiceFileMatchFinder > realization_LastChanceServiceFileMatchFinder::createClone() const throw() {
	return ::jmsf::Proxy< LastChanceServiceFileMatchFinder >::createUnique( new realization_LastChanceServiceFileMatchFinder( *this ) );
}

realization_LastChanceServiceFileMatchFinder::realization_LastChanceServiceFileMatchFinder( const realization_LastChanceServiceFileMatchFinder & ) throw() // other
{}

const realization_LastChanceServiceFileMatchFinder &realization_LastChanceServiceFileMatchFinder::operator =( const realization_LastChanceServiceFileMatchFinder &other ) throw() {
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
