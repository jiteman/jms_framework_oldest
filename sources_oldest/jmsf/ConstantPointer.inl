#pragma once

#include "ConstantPointer.hpp"


#include "base_pointing/BaseForConstantPointerAndConstantProxy.hpp"
#include "DeleterForPointer.hpp"


namespace jmsf {


template< class A_type >
const ConstantPointer< A_type > ConstantPointer< A_type >::getNonlinked() const throw( Exception ) {
	return createNonlinkedFor( get() );
}

// template< class A_type >
// const ConstantPointer< A_type > ConstantPointer< A_type >::getWeakConstant() const throw( Exception ) {
// 	return ConstantPointer< A_type >( getWeak() );
// }

template< class A_type >
const ConstantPointer< A_type > ConstantPointer< A_type >::getAsShared() const throw( Exception ) {
	ConstantPointer< A_type > sharedPointer = ConstantPointer< A_type >::createNone();
	static_cast< const base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( sharedPointer ) = createSharedFromThis();
	return sharedPointer;
}

template< class A_type >
// static
const ConstantPointer< A_type > ConstantPointer< A_type >::createNone() throw( Exception ) {
	return ConstantPointer< A_type >( type_None, nullptr );
}

template< class A_type >
const ConstantPointer< A_type > ConstantPointer< A_type >::createEmpty() throw( Exception ) {
	return ConstantPointer< A_type >( type_Empty, nullptr );
}

template< class A_type >
// static
const ConstantPointer< A_type > ConstantPointer< A_type >::createNonlinkedFor( const A_type *const pointerToObject ) throw( Exception ) {
	return pointerToObject == nullptr ? ConstantPointer< A_type >( type_Empty, pointerToObject ) : ConstantPointer< A_type >( type_Nonlinked, pointerToObject );
}

template< class A_type >
// static
const ConstantPointer< A_type > ConstantPointer< A_type >::createUnique( const A_type *const pointerToObject ) throw( Exception ) {
	return ConstantPointer< A_type >( type_Unique, pointerToObject );
}

template< class A_type >
// static
const ConstantPointer< A_type > ConstantPointer< A_type >::createShared( const A_type *const pointerToObject ) throw( Exception ) {
	return ConstantPointer< A_type >( type_Shared, pointerToObject );
}

template< class A_type >
ConstantPointer< A_type >::ConstantPointer() throw()
	:
		BaseForConstantPointerAndConstantProxy( type_Empty, nullptr )
{}

template< class A_type >
ConstantPointer< A_type >::ConstantPointer( const natural_small type, const A_type *const pointerToObject ) throw( Exception )
	:
		BaseForConstantPointerAndConstantProxy( type, pointerToObject )
{}


} // namespace
