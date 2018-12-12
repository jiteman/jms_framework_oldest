#pragma once

#include "../Functor.hpp"
#include "jmsf/mixins/mixin_Object.h"

#include "realization_flyweight_factory_Functor.hxx"

#include "../warning_suppressor.h"

namespace jmsf {
namespace assists {
namespace realizations {

template< class A_type >
class realization_Functor :
	public Functor< A_type >,
	public mixins::mixin_Object
{
	typedef void ( A_type::type_indirected:: *type_pointerToMethod )();

public:
	// virtuals Functor
	void runMethod( A_type &indirectedObject ) throw( Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	type_pointerToMethod getPointerToMethod() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend DeleterForPointer< realization_Functor >;
	// virtual
	~realization_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	realization_Functor( type_pointerToMethod pointerToMethod ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Functor< A_type > > createClone() const throw();

private:
	realization_Functor( const realization_Functor &other ) throw();
	const realization_Functor &operator =( const realization_Functor &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	type_pointerToMethod _pointerToMethod;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


template< class A_type >
void realization_Functor< A_type >::runMethod( A_type &indirectedObject ) throw( Exception ) {
	( ( *indirectedObject ).*_pointerToMethod )();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
typename realization_Functor< A_type >::type_pointerToMethod realization_Functor< A_type >::getPointerToMethod() throw() {
	return _pointerToMethod;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
realization_Functor< A_type >::~realization_Functor() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
realization_Functor< A_type >::realization_Functor(
	 typename realization_Functor< A_type >::type_pointerToMethod pointerToMethod ) throw()
{
	_pointerToMethod = pointerToMethod;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
Proxy< Functor< A_type > > realization_Functor< A_type >::createClone() const throw() {
	return Proxy< Functor< A_type > >::createNonlinkedFor( this );
}

template< class A_type >
realization_Functor< A_type >::realization_Functor( const realization_Functor< A_type > & ) throw() // other
{}

template< class A_type >
const realization_Functor< A_type > &realization_Functor< A_type >::operator =( const realization_Functor< A_type > &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
}
