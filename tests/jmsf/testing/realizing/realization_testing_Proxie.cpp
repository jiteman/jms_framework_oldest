#include "realization_testing_Proxie.h"
#include "../../sensing/sensing_Pointie.h"

#include "jmsf/pointing/Proxy.inl"
////#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace testing {
namespace realizations {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_testing_Proxie::~realization_testing_Proxie() throw() {
	_sensingPointie->registerDestruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_testing_Proxie::realization_testing_Proxie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointie ) throw()
	:
		_sensingPointie( sensingPointie )
{
	_sensingPointie->registerConstruction();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// ::jmsf::pointing::Proxy< testing_Proxie > realization_testing_Proxie::createClone() const throw() {
// 	testing_Proxie *testingProxie = new realization_testing_Proxie( *this );
// 	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( testingProxie, MACROS_FILE_AND_LINE ) );
// 	return ::jmsf::Proxy< testing_Proxie >::createUnique( testingProxie );
// }

realization_testing_Proxie::realization_testing_Proxie( const realization_testing_Proxie & ) throw() // other
{}

const realization_testing_Proxie &realization_testing_Proxie::operator =( const realization_testing_Proxie &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
