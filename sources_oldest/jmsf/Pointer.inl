#pragma once


#include "Pointer.hpp"


#include "ConstantPointer.hpp"
//#include "base_pointing/BaseForPointerAndProxy.hpp"
#include "DeleterForPointer.hpp"


namespace jmsf {


template< class A_type >
Pointer< A_type > Pointer< A_type >::getNonlinked() const throw( Exception ) {
	return createNonlinkedFor( get() );
}

template< class A_type >
const ConstantPointer< A_type > Pointer< A_type >::getNonlinkedConstant() const throw( Exception ) {
	return ConstantPointer< A_type >::createNonlinkedFor( get() );
}

template< class A_type >
const ConstantPointer< A_type > Pointer< A_type >::takeConstant() const throw( Exception ) {
	ConstantPointer< A_type > constantPointer;
	static_cast< base_pointing::BaseForBothConstantAndNonconstant< DeleterForPointer< A_type > > & >( constantPointer ) = 
		static_cast< const base_pointing::BaseForBothConstantAndNonconstant< DeleterForPointer< A_type > > & >( *this );
	return constantPointer;
}

template< class A_type >
const Pointer< A_type > Pointer< A_type >::getAsShared() const throw( Exception ) {
	Pointer< A_type > sharedPointer = Pointer< A_type >::createNone();
	static_cast< base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( sharedPointer ) = createSharedFromThis();
	return sharedPointer;
}

template< class A_type >
Pointer< A_type > Pointer< A_type >::takeAsShared() throw( Exception ) {
	Pointer< A_type > sharedPointer = Pointer< A_type >::createNone();
	static_cast< base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( sharedPointer ) = createSharedFromThis();
	return sharedPointer;
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::createNone() throw( Exception ) {
	return Pointer< A_type >( type_None, nullptr );
}

template< class A_type >
Pointer< A_type > Pointer< A_type >::createEmpty() throw( Exception ) {
	return Pointer< A_type >( type_Empty, nullptr );
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::createNonlinkedFor( const A_type *const pointerToObject ) throw( Exception ) {
	return pointerToObject == nullptr ? Pointer< A_type >( type_Empty, pointerToObject ) : Pointer< A_type >( type_Nonlinked, pointerToObject );
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::createUnique( const A_type *const pointerToObject ) throw( Exception ) {
	return Pointer< A_type >( type_Unique, pointerToObject );
}

template< class A_type >
// static
Pointer< A_type > Pointer< A_type >::createShared( const A_type *const pointerToObject ) throw( Exception ) {
	return Pointer< A_type >( type_Shared, pointerToObject );
}

template< class A_type >
Pointer< A_type >::Pointer() throw()
	:
		BaseForPointerAndProxy( type_Empty, nullptr )
{}

template< class A_type >
Pointer< A_type >::Pointer( const natural_small type, const A_type *const pointerToObject ) throw( Exception )
	:
		BaseForPointerAndProxy( type, pointerToObject )
{}


} // namespace
