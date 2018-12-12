#pragma once


#include "realization_ContainerArrayAgent.hxx"

#include "../ContainerAgent.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_ContainerAgent.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_ContainerArrayAgent :
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
	~realization_ContainerArrayAgent() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ContainerAgent< A_type >;
	realization_ContainerArrayAgent() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< ContainerAgent< A_type > > createClone() const throw();

private:
	realization_ContainerArrayAgent( const realization_ContainerArrayAgent &other ) throw();
	const realization_ContainerArrayAgent &operator =( const realization_ContainerArrayAgent &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
