#pragma once


#include "realization_ContainerDeque.hxx"

#include "../Container.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_Container.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_ContainerDeque :
	public Container< A_type >,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals Container< A_type >
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ContainerDeque() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Container< A_type >;
	realization_ContainerDeque() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Container< A_type > > createClone() const throw();

private:
	realization_ContainerDeque( const realization_ContainerDeque &other ) throw();
	const realization_ContainerDeque &operator =( const realization_ContainerDeque &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
