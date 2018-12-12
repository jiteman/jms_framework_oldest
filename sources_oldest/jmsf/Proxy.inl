#pragma once


#include "Proxy.hpp"

#include "ConstantProxy.hpp"
//#include "base_pointing/BaseForPointerAndProxy.hpp"
#include "DeleterForProxy.hpp"


namespace jmsf {


template< class A_type >
Proxy< A_type > Proxy< A_type >::getNonlinked() const throw( Exception ) {
	return createNonlinkedFor( get() );
}

template< class A_type >
const ConstantProxy< A_type > Proxy< A_type >::getNonlinkedConstant() const throw( Exception ) {
	return ConstantProxy< A_type >::createNonlinkedFor( get() );
}

template< class A_type >
const ConstantProxy< A_type > Proxy< A_type >::takeConstant() const throw( Exception ) {
	ConstantProxy< A_type > constantProxy = ConstantProxy< A_type >::createNone();
	static_cast< base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( constantProxy ) = 
		static_cast< const base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( *this );
	return constantProxy;
}

template< class A_type >
const Proxy< A_type > Proxy< A_type >::getAsShared() const throw( Exception ) {
	Proxy< A_type > sharedProxy = Proxy< A_type >::createNone();
	static_cast< base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( sharedProxy ) = createSharedFromThis();
	return sharedProxy;
}

template< class A_type >
Proxy< A_type > Proxy< A_type >::takeAsShared() throw( Exception ) {
	Proxy< A_type > sharedProxy = Proxy< A_type >::createNone();
	static_cast< base_pointing::BaseForBothConstantAndNonconstant< DeleterForProxy< A_type > > & >( sharedProxy ) = createSharedFromThis();
	return sharedProxy;
}

template< class A_type >
// static
Proxy< A_type > Proxy< A_type >::createNone() throw( Exception ) {
	return Proxy< A_type >( type_None, nullptr );
}

template< class A_type >
Proxy< A_type > Proxy< A_type >::createEmpty() throw( Exception ) {
	return Proxy< A_type >( type_Empty, A_type::getNull() );
}

template< class A_type >
// static
Proxy< A_type > Proxy< A_type >::createNonlinkedFor( const A_type *const pointerToObject ) throw( Exception ) {
	if ( pointerToObject == nullptr ) {
		return Proxy< A_type >( type_None, pointerToObject );
	} else if ( pointerToObject->isNull() ) {
		return Proxy< A_type >( type_Empty, pointerToObject );
	} else {
		return Proxy< A_type >( type_Nonlinked, pointerToObject );
	}
}

template< class A_type >
// static
Proxy< A_type > Proxy< A_type >::createUnique( const A_type *const pointerToObject ) throw( Exception ) {
	return Proxy< A_type >( type_Unique, pointerToObject );
}

template< class A_type >
// static
Proxy< A_type > Proxy< A_type >::createShared( const A_type *const pointerToObject ) throw( Exception ) {
	return Proxy< A_type >( type_Shared, pointerToObject );
}

template< class A_type >
Proxy< A_type >::Proxy() throw()
	:
		BaseForPointerAndProxy( type_Empty, A_type::getNull() )
{}

// template< class A_type >
// Proxy< A_type >::Proxy< A_type >( const Proxy< A_type > &other ) throw( Exception ) {
// 
// }
// 
// template< class A_type >
// const Proxy< A_type > &Proxy< A_type >::operator =( const Proxy< A_type > &other ) throw( Exception ) {
// }

template< class A_type >
Proxy< A_type >::Proxy( const natural_small type, const A_type *const pointerToObject ) throw( Exception )
	:
		BaseForPointerAndProxy( type, pointerToObject )
{}


} // namespace
