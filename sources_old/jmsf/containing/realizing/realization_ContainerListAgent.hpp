#pragma once


#include "realization_ContainerListAgent.hxx"

#include "../ContainerAgent.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_ContainerAgent.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_ContainerListAgent :
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
	~realization_ContainerListAgent() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ContainerAgent< A_type >;
	realization_ContainerListAgent() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< ContainerAgent< A_type > > createClone() const throw();

private:
	realization_ContainerListAgent( const realization_ContainerListAgent &other ) throw();
	const realization_ContainerListAgent &operator =( const realization_ContainerListAgent &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
