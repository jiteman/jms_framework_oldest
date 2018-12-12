#pragma once


#include "BaseForConstantPointerAndConstantProxy.hpp"

#include "BaseForPointerAndProxy.hpp"


namespace jmsf {
namespace base_pointing {


// template< class A_type, template< class > class A__deleter >
// const A_type *BaseForConstantPointerAndConstantProxy< Indirector_type >::get() const throw( Exception ) {
// 	return const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->getFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// const A_type *BaseForConstantPointerAndConstantProxy< Indirector_type >::release() const throw( Exception ) {
// 	return const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->releaseFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// void BaseForConstantPointerAndConstantProxy< Indirector_type >::empty() const throw( Exception ) {
// 	const_cast< BaseForBothConstantAndNonconstant< Indirector_type > * >( this )->emptyFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// A_type *BaseForConstantPointerAndConstantProxy< Indirector_type >::get() throw( Exception ) {
// 	Should::neverReachHere();
// 	return A__deleter::getNull();
// }

template< class Indirector_type >
const typename Indirector_type::type_indirected *BaseForConstantPointerAndConstantProxy< Indirector_type >::get() const throw( Exception ) {
	return BaseForBothConstantAndNonconstant< Indirector_type >::get();
}

template< class Indirector_type >
const typename Indirector_type::type_indirected *BaseForConstantPointerAndConstantProxy< Indirector_type >::release() const throw( Exception ) {
	return BaseForBothConstantAndNonconstant< Indirector_type >::release();
}

template< class Indirector_type >
void BaseForConstantPointerAndConstantProxy< Indirector_type >::empty() const throw( Exception ) {
	BaseForBothConstantAndNonconstant< Indirector_type >::empty();
}

template< class Indirector_type >
typename Indirector_type::type_indirected *BaseForConstantPointerAndConstantProxy< Indirector_type >::get() throw( Exception ) {
	validate();
	Should::neverReachHere();
	return nullptr;
}

template< class Indirector_type >
typename Indirector_type::type_indirected *BaseForConstantPointerAndConstantProxy< Indirector_type >::release() throw( Exception ) {
	validate();
	Should::neverReachHere();
	return nullptr;
}

template< class Indirector_type >
void BaseForConstantPointerAndConstantProxy< Indirector_type >::empty() throw( Exception ) {
	validate();
	Should::neverReachHere();
}

template< class Indirector_type >
const typename Indirector_type::type_indirected &BaseForConstantPointerAndConstantProxy< Indirector_type >::operator *() const throw( Exception ) {
	return BaseForBothConstantAndNonconstant< Indirector_type >::operator *();
}

template< class Indirector_type >
const typename Indirector_type::type_indirected *BaseForConstantPointerAndConstantProxy< Indirector_type >::operator ->() const throw( Exception ) {
	return BaseForBothConstantAndNonconstant< Indirector_type >::operator ->();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class Indirector_type >
typename Indirector_type::type_indirected &BaseForConstantPointerAndConstantProxy< Indirector_type >::operator *() throw( Exception ) {
	validate();
	Should::neverReachHere();
	return nullptr;
}

template< class Indirector_type >
typename Indirector_type::type_indirected *BaseForConstantPointerAndConstantProxy< Indirector_type >::operator ->() throw( Exception ) {
	validate();
	Should::neverReachHere();
	return nullptr;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// BaseForConstantPointerAndConstantProxy< Indirector_type >::BaseForConstantPointerAndConstantProxy() throw()
// 	: BaseForBothConstantAndNonconstant()
// {}

template< class Indirector_type >
BaseForConstantPointerAndConstantProxy< Indirector_type >::BaseForConstantPointerAndConstantProxy( const natural_small type, const typename Indirector_type::type_indirected *const pointerToObject ) throw( Exception )
	: BaseForBothConstantAndNonconstant( type, pointerToObject )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// BaseForConstantPointerAndConstantProxy< Indirector_type >::BaseForConstantPointerAndConstantProxy( const BaseForConstantPointerAndConstantProxy< Indirector_type > &other ) throw( Exception )
// 	: BaseForBothConstantAndNonconstant( other )
// {}
// 
// template< class A_type, template< class > class A__deleter >
// const BaseForConstantPointerAndConstantProxy< Indirector_type > &BaseForConstantPointerAndConstantProxy< Indirector_type >::operator =( const BaseForConstantPointerAndConstantProxy< Indirector_type > &other ) throw( Exception ) {
// 	if ( this == &other ) return *this;
// 
// 	BaseForBothConstantAndNonconstant::operator =( other );
// 	return *this;
// }

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
