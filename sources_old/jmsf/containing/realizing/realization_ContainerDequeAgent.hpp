#pragma once


#include "realization_ContainerDequeAgent.hxx"

#include "../ContainerAgent.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_ContainerAgent.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_ContainerDequeAgent :
	public ContainerAgent< A_type >,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals ContainerAgent< A_type >
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ContainerDequeAgent() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ContainerAgent< A_type >;
	realization_ContainerDequeAgent() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< ContainerAgent< A_type > > createClone() const throw();

private:
	realization_ContainerDequeAgent( const realization_ContainerDequeAgent &other ) throw();
	const realization_ContainerDequeAgent &operator =( const realization_ContainerDequeAgent &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
