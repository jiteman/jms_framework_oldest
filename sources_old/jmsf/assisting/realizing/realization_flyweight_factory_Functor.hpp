#pragma once


#include "realization_flyweight_factory_Functor.hxx"

#include "../flyweight_factory_Functor.hpp"

#include "jmsf/validating/Should.h"

#include "jmsf/pointing/Proxy.hpp"

#include "jmsf/containing/Container.hxx"
#include "jmsf/pointing/ConstantProxy.hxx"


namespace jmsf {
namespace assisting {
namespace realizing {


template< class A_type >
class realization_flyweight_factory_Functor :
	public flyweight_factory_Functor< A_type >
{

public:
	// virtuals flyweight_factory_Functor
	pointing::Proxy< Functor< A_type > > createFunctor( void ( A_type::containing_type_data::the_type:: *pointerToMethod )() ) throw();
	const pointing::ConstantProxy< ConstantFunctor< A_type > > createConstantFunctor( void ( A_type::containing_type_data::the_type:: *pointerToMethod )() const ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend flyweight_factory_Functor;
	realization_flyweight_factory_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_flyweight_factory_Functor( const realization_flyweight_factory_Functor &other ) throw();
	const realization_flyweight_factory_Functor &operator =( const realization_flyweight_factory_Functor &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	pointing::Proxy< containing::Container< pointing::Proxy< Functor< A_type > > > > _functorContainer;
	pointing::Proxy< containing::Container< pointing::ConstantProxy< ConstantFunctor< A_type > > > > _constantFunctorContainer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace assists
} // jmsf
