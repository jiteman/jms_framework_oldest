#include "null_es_ServiceFileAndKeyPairMatchChecker.h"
#include "../../data/ed_Key.h"
#include "../../data/ed_ServiceFile.h"
#include "jmsf/Pairs.hpp"
#include "jmsf/Proxies.hpp"


namespace nppntt {
namespace mdm {
namespace externals {
namespace software {
namespace nulls {


void null_es_ServiceFileAndKeyPairMatchChecker::setPair( ::jmsf::Pointer< ::jmsf::VariousPair< ::jmsf::Proxy, data::ed_ServiceFile, ::jmsf::ConstantProxy, data::ed_Key > > ) throw() // serviceFileAndKeyPair
{}

const ::jmsf::Boolean &null_es_ServiceFileAndKeyPairMatchChecker::isPairMatched() const throw() {
	return _boolean;
}

const ::jmsf::ConstantProxy< data::ed_Key > null_es_ServiceFileAndKeyPairMatchChecker::getTheKey() const throw() {
	return _key.getWeak();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
null_es_ServiceFileAndKeyPairMatchChecker::~null_es_ServiceFileAndKeyPairMatchChecker() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
null_es_ServiceFileAndKeyPairMatchChecker *null_es_ServiceFileAndKeyPairMatchChecker::createInstance() throw() {
	return new null_es_ServiceFileAndKeyPairMatchChecker;
}

null_es_ServiceFileAndKeyPairMatchChecker::null_es_ServiceFileAndKeyPairMatchChecker() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker > null_es_ServiceFileAndKeyPairMatchChecker::createClone() const throw() {
	return ::jmsf::Proxy< es_ServiceFileAndKeyPairMatchChecker >::createUnique( this );
}

null_es_ServiceFileAndKeyPairMatchChecker::null_es_ServiceFileAndKeyPairMatchChecker( const null_es_ServiceFileAndKeyPairMatchChecker & ) throw() // other
{}

const null_es_ServiceFileAndKeyPairMatchChecker &null_es_ServiceFileAndKeyPairMatchChecker::operator =( const null_es_ServiceFileAndKeyPairMatchChecker &other ) throw() {
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
}
