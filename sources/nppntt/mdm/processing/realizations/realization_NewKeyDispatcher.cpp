#include "realization_NewKeyDispatcher.h"
#include "../../externals/data/ed_Key.h"
#include "../KeyArray.h"
#include "jmsf/osie/Event.h"
#include "jmsf/mtf/SynchronizedQueue.hpp"
#include "jmsf/Proxies.hpp"

namespace nppntt {
namespace mdm {
namespace processing {
namespace realizations {


void realization_NewKeyDispatcher::run() throw( ::jmsf::Exception ) {
	_sourceKeyQueue->takeMutex()->lock();

	if ( _sourceKeyQueue->getIsObjectAvailableEvent()->isSet().not() ) {
		_sourceKeyQueue->takeMutex()->unlock();
		return;
	}

	::jmsf::ConstantProxy< externals::data::ed_Key > key = _sourceKeyQueue->withdrawFirst();
	_sourceKeyQueue->takeMutex()->unlock();
// 	_keyArray->takeMutex()->lock();
// 	_keyArray->append( key );
// 	_keyArray->takeMutex()->unlock();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_NewKeyDispatcher::~realization_NewKeyDispatcher() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_NewKeyDispatcher::realization_NewKeyDispatcher(
		const ::jmsf::Proxy< ::jmsf::mtf::SynchronizedQueue< ::jmsf::ConstantProxy< externals::data::ed_Key > > > &sourceKeyQueue,
		const ::jmsf::Proxy< KeyArray > &keyArray ) throw()
	:
		_sourceKeyQueue( sourceKeyQueue ),
		_keyArray( keyArray )
{
//	appendWaitableEvent( _sourceKeyQueue->getOneselfIsObjectAvailableEvent() );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< NewKeyDispatcher > realization_NewKeyDispatcher::createClone() const throw() {
	return ::jmsf::Proxy< NewKeyDispatcher >::createUnique( new realization_NewKeyDispatcher( *this ) );
}

realization_NewKeyDispatcher::realization_NewKeyDispatcher( const realization_NewKeyDispatcher & ) throw() // other
{}

const realization_NewKeyDispatcher &realization_NewKeyDispatcher::operator =( const realization_NewKeyDispatcher &other ) throw() {
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
