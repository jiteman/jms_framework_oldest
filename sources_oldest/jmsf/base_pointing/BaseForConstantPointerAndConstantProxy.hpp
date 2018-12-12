#pragma once


#include "BaseForBothConstantAndNonconstant.hpp"

#include "jmsf/types/ShortestNatural.hxx"
#include "../Should.h"


namespace jmsf {
namespace base_pointing {


template< class Indirector_type >
class BaseForConstantPointerAndConstantProxy
	: public BaseForBothConstantAndNonconstant< Indirector_type >
{

// public:
// 	const A_type *get() const throw( Exception );
// 	const A_type *release() const throw( Exception );
// 	void empty() const throw( Exception );
// 
// private:
// 	A_type *get() throw( Exception );

public:
	const typename Indirector_type::type_indirected *get() const throw( Exception );
	const typename Indirector_type::type_indirected *release() const throw( Exception );
	void empty() const throw( Exception );

private: // hiding non constant methods
	typename Indirector_type::type_indirected *get() throw( Exception );
	typename Indirector_type::type_indirected *release() throw( Exception );
	void empty() throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	const typename Indirector_type::type_indirected &operator *() const throw( Exception );
	const typename Indirector_type::type_indirected *operator ->() const throw( Exception );

private: // hiding non constant methods again
	typename Indirector_type::type_indirected &operator *() throw( Exception );
	typename Indirector_type::type_indirected *operator ->() throw( Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
//protected:
// 	BaseForConstantPointerAndConstantProxy() throw();

protected:
	BaseForConstantPointerAndConstantProxy( types::ShortestNatural type, const typename Indirector_type::type_indirected *pointerToObject ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
// 	BaseForConstantPointerAndConstantProxy( const BaseForConstantPointerAndConstantProxy &other ) throw( Exception );
// 	const BaseForConstantPointerAndConstantProxy &operator =( const BaseForConstantPointerAndConstantProxy &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
