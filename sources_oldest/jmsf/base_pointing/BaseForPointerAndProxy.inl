#pragma once


#include "BaseForPointerAndProxy.hpp"


namespace jmsf {
namespace base_pointing {


// template< class A_type, template< class > class A__deleter >
// A_type *BaseForPointerAndProxy< A_type, A__deleter >::get() throw( Exception ) {
// 	return getFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// const A_type *BaseForPointerAndProxy< A_type, A__deleter >::get() const throw( Exception ) {
// 	return const_cast< BaseForPointerAndProxy< A_type, A__deleter > * >( this )->getFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// A_type *BaseForPointerAndProxy< A_type, A__deleter >::release() throw( Exception ) {
// 	return releaseFromBase();
// }
// 
// template< class A_type, template< class > class A__deleter >
// void BaseForPointerAndProxy< A_type, A__deleter >::empty() throw( Exception ) {
// 	emptyFromBase();
// }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// BaseForPointerAndProxy< A_type, A__deleter >::BaseForPointerAndProxy() throw()
// 	: BaseForBothConstantAndNonconstant()
// {}

template< class Indirector_type >
BaseForPointerAndProxy< Indirector_type >::BaseForPointerAndProxy( const natural_small type, const typename Indirector_type::type_indirected *const pointerToObject ) throw( Exception )
	: BaseForBothConstantAndNonconstant( type, pointerToObject )
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template< class A_type, template< class > class A__deleter >
// BaseForPointerAndProxy< A_type, A__deleter >::BaseForPointerAndProxy( const BaseForPointerAndProxy< A_type, A__deleter > &other ) throw( Exception )
// 	: BaseForBothConstantAndNonconstant( other )
// {}
// 
// template< class A_type, template< class > class A__deleter >
// BaseForPointerAndProxy< A_type, A__deleter > &BaseForPointerAndProxy< A_type, A__deleter >::operator =( const BaseForPointerAndProxy< A_type, A__deleter > &other ) throw( Exception ) {
// 	if ( this == &other ) return *this;
// 
// 	BaseForBothConstantAndNonconstant::operator =( other );
// 	return *this;
// }

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
