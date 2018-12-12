#include "realization_factory_MuleAnalyzer.h"
#include "realization_MuleAnalyzer.h"
#include "MulanObjectCreationInformation.h"
#include "MulanObjectDeletionInformation.h"
#include "MulanArrayDeletionInformation.h"
#include "MulanArrayCreationInformation.h"
#include "jmsf/factory_Container.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Pointers.hpp"
#include "jmsf/Should.h"

namespace jmsf {
namespace debugging {
namespace mulan {
namespace realizations {

Proxy< MuleAnalyzer > realization_factory_MuleAnalyzer::createMuleAnalyzer() const throw() {
	const Proxy< Container< Pointer< MulanObjectCreationInformation > > > objectCreationContainer = factory_Container< Pointer< MulanObjectCreationInformation > >::instance()->createList();
	const Proxy< Container< Pointer< MulanObjectDeletionInformation > > > objectDeletionContainer = factory_Container< Pointer< MulanObjectDeletionInformation > >::instance()->createList();
	const Proxy< Container< Pointer< MulanArrayCreationInformation > > > arrayCreationContainer = factory_Container< Pointer< MulanArrayCreationInformation > >::instance()->createList();
	const Proxy< Container< Pointer< MulanArrayDeletionInformation > > > arrayDeletionContainer = factory_Container< Pointer< MulanArrayDeletionInformation > >::instance()->createList();

	realization_MuleAnalyzer *muleAnalyzer = new realization_MuleAnalyzer( objectCreationContainer, objectDeletionContainer, arrayCreationContainer, arrayDeletionContainer );
//	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( muleAnalyzer, MACROS_FILE_AND_LINE ) );
	return Proxy< MuleAnalyzer >::createUnique( muleAnalyzer );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_factory_MuleAnalyzer::~realization_factory_MuleAnalyzer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_MuleAnalyzer::realization_factory_MuleAnalyzer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_factory_MuleAnalyzer::realization_factory_MuleAnalyzer( const realization_factory_MuleAnalyzer & ) throw() // other
{}

const realization_factory_MuleAnalyzer &realization_factory_MuleAnalyzer::operator =( const realization_factory_MuleAnalyzer &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "realization_factory_MuleAnalyzer::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace realizations
} // namespace mulan
} // namespace debugging
} // namespace jmsf