#include "factory_MuleAnalyzer.h"
#include "realizations/realization_factory_MuleAnalyzer.h"
#include "jmsf/Should.h"

namespace jmsf {
namespace debugging {
namespace mulan {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
factory_MuleAnalyzer::~factory_MuleAnalyzer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
factory_MuleAnalyzer *factory_MuleAnalyzer::createInstance() throw() {
	return new realizations::realization_factory_MuleAnalyzer;
}

factory_MuleAnalyzer::factory_MuleAnalyzer() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
factory_MuleAnalyzer::factory_MuleAnalyzer( const factory_MuleAnalyzer & ) throw() // other
{}

const factory_MuleAnalyzer &factory_MuleAnalyzer::operator =( const factory_MuleAnalyzer &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "factory_MuleAnalyzer::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace mulan
} // namespace debugging
} // namespace jmsf