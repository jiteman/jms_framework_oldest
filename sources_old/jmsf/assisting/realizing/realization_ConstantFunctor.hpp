#pragma once


#include "realization_ConstantFunctor.hxx"

#include "../ConstantFunctor.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_flyweight_factory_Functor.hxx"


namespace jmsf {
namespace assisting {
namespace realizing {


template< class A_type >
class realization_ConstantFunctor :
	public ConstantFunctor< A_type >,
	public patterning::mixing::mixin_Object
{
	typedef void ( A_type::the_type:: *type_pointerToMethod )() const;

public:
	// virtuals Functor
	void runMethod( const A_type &indirectedObject ) const throw( validating::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	type_pointerToMethod getPointerToMethod() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< realization_ConstantFunctor >;
	// virtual
	~realization_ConstantFunctor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	realization_ConstantFunctor( type_pointerToMethod pointerToMethod ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< ConstantFunctor< A_type > > createClone() const throw();

private:
	realization_ConstantFunctor( const realization_ConstantFunctor &other ) throw();
	const realization_ConstantFunctor &operator =( const realization_ConstantFunctor &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	type_pointerToMethod _pointerToMethod;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
