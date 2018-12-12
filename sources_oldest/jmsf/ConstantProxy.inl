#pragma once


#include "ConstantProxy.hpp"

#include "DeleterForProxy.hpp"


namespace jmsf {


template< class A_type >
const ConstantProxy< A_type > ConstantProxy< A_type >::getNonlinked() const throw( Exception ) {
	return createNonlinkedFor( get() );
}

// template< class A_type >
// const ConstantProxy< A_type > ConstantProxy< A_type >::getWeakConstant() const throw( Exception ) {
// 	return ConstantProxy< A_type >::createNonlinkedFor( get() );
// }

template< class A_type >
const ConstantProxy< A_type > ConstantProxy< A_type >::getAsShared() const throw( Exception ) {
	ConstantProxy< A_type > sharedProxy = ConstantProxy< A_type >::createNone();
	static_cast< const base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( sharedProxy ) = createSharedFromThis();
	return sharedProxy;
}

template< class A_type >
// static
ConstantProxy< A_type > ConstantProxy< A_type >::createNone() throw( Exception ) {
	return ConstantProxy< A_type >( type_None, nullptr );
}

template< class A_type >
ConstantProxy< A_type > ConstantProxy< A_type >::createEmpty() throw( Exception ) {
	return ConstantProxy< A_type >( type_Empty, A_type::getNull() );
}

template< class A_type >
// static
ConstantProxy< A_type > ConstantProxy< A_type >::createNonlinkedFor( const A_type *const pointerToObject ) throw( Exception ) {
	if ( pointerToObject == nullptr ) {
		return ConstantProxy< A_type >( type_None, pointerToObject );
	} else if ( pointerToObject->isNull() ) {
		return ConstantProxy< A_type >( type_Empty, pointerToObject );
	} else {
		return ConstantProxy< A_type >( type_Nonlinked, pointerToObject );
	}
}

template< class A_type >
// static
ConstantProxy< A_type > ConstantProxy< A_type >::createUnique( const A_type *const pointerToObject ) throw( Exception ) {
	return ConstantProxy< A_type >( type_Unique, pointerToObject );
}

template< class A_type >
// static
ConstantProxy< A_type > ConstantProxy< A_type >::createShared( const A_type *const pointerToObject ) throw( Exception ) {
	return ConstantProxy< A_type >( type_Shared, pointerToObject );
}

template< class A_type >
ConstantProxy< A_type >::ConstantProxy() throw()
	:
		BaseForConstantPointerAndConstantProxy( type_Empty, A_type::getNull() )
{}

template< class A_type >
ConstantProxy< A_type >::ConstantProxy( const natural_small type, const A_type *const pointerToObject ) throw( Exception )
	:
		BaseForConstantPointerAndConstantProxy( type, pointerToObject )
{}


} // namespace
