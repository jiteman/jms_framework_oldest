#pragma once

#include "../ConstantFunctor.hpp"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_flyweight_factory_Functor.hxx"

#include "../warning_suppressor.h"

namespace jmsf {
namespace assists {
namespace realizations {

template< class A_type >
class realization_ConstantFunctor :
	public ConstantFunctor< A_type >,
	public mixins::mixin_Object
{
	typedef void ( A_type::type_indirected:: *type_pointerToMethod )() const;

public:
	// virtuals Functor
	void runMethod( const A_type &indirectedObject ) const throw( Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	type_pointerToMethod getPointerToMethod() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend DeleterForPointer< realization_ConstantFunctor >;
	// virtual
	~realization_ConstantFunctor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	realization_ConstantFunctor( type_pointerToMethod pointerToMethod ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< ConstantFunctor< A_type > > createClone() const throw();

private:
	realization_ConstantFunctor( const realization_ConstantFunctor &other ) throw();
	const realization_ConstantFunctor &operator =( const realization_ConstantFunctor &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	type_pointerToMethod _pointerToMethod;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


template< class A_type >
void realization_ConstantFunctor< A_type >::runMethod( const A_type &indirectedObject ) const throw( Exception ) {
	( ( *indirectedObject ).*_pointerToMethod )();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typename realization_ConstantFunctor< A_type >::type_pointerToMethod realization_ConstantFunctor< A_type >::getPointerToMethod() const throw() {
	return _pointerToMethod;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_ConstantFunctor< A_type >::~realization_ConstantFunctor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_ConstantFunctor< A_type >::realization_ConstantFunctor(
	typename realization_ConstantFunctor< A_type >::type_pointerToMethod pointerToMethod ) throw()
{
	_pointerToMethod = pointerToMethod;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< ConstantFunctor< A_type > > realization_ConstantFunctor< A_type >::createClone() const throw() {
	return Proxy< ConstantFunctor< A_type > >::createNonlinkedFor( this );
}

template< class A_type >
realization_ConstantFunctor< A_type >::realization_ConstantFunctor( const realization_ConstantFunctor< A_type > & ) throw() // other
{}

template< class A_type >
const realization_ConstantFunctor< A_type > &realization_ConstantFunctor< A_type >::operator =( const realization_ConstantFunctor< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
