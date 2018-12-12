#pragma once


#include "realization_Functor.hxx"

#include "../Functor.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_flyweight_factory_Functor.hxx"


namespace jmsf {
namespace assisting {
namespace realizing {


template< class A_type >
class realization_Functor :
	public Functor< A_type >,
	public patterning::mixing::mixin_Object
{
	typedef void ( A_type::the_type:: *type_pointerToMethod )();

public:
	// virtuals Functor
	void runMethod( A_type &indirectedObject ) throw( validating::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	type_pointerToMethod getPointerToMethod() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< realization_Functor >;
	// virtual
	~realization_Functor() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_flyweight_factory_Functor< A_type >;
	realization_Functor( type_pointerToMethod pointerToMethod ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Functor< A_type > > createClone() const throw();

private:
	realization_Functor( const realization_Functor &other ) throw();
	const realization_Functor &operator =( const realization_Functor &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	type_pointerToMethod _pointerToMethod;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
