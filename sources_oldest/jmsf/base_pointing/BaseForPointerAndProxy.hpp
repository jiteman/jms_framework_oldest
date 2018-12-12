#pragma once


#include "BaseForBothConstantAndNonconstant.hpp"

#include "jmsf/types/ShortestNatural.hxx"

#include "BaseForConstantPointerAndConstantProxy.hxx"


namespace jmsf {
namespace base_pointing {


template< class Indirector_type >
class BaseForPointerAndProxy :
	public BaseForBothConstantAndNonconstant< Indirector_type >
{

public:
// 	A_type *get() throw( Exception );
// 	const A_type *get() const throw( Exception );
// 	A_type *release() throw( Exception );
// 	void empty() throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// protected:
// 	BaseForPointerAndProxy() throw();

protected:
	BaseForPointerAndProxy( const types::ShortestNatural type, const typename Indirector_type::type_indirected *const pointerToObject ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// protected:
// 	BaseForPointerAndProxy( const BaseForPointerAndProxy &other ) throw( Exception );
// 	BaseForPointerAndProxy &operator =( const BaseForPointerAndProxy &other ) throw( Exception );


// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
