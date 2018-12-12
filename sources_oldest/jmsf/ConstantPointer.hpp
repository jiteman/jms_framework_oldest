#pragma once


#include "base_pointing/BaseForConstantPointerAndConstantProxy.hpp"

#include "DeleterForPointer.hxx"
#include "Pointers.hxx"
#include "Exception.hxx"

#include "types.h"


namespace jmsf {


template< class A_type >
class ConstantPointer :
	public base_pointing::BaseForConstantPointerAndConstantProxy< DeleterForPointer< A_type > >
{

public:
	const ConstantPointer getNonlinked() const throw( Exception );
	const ConstantPointer getAsShared() const throw( Exception );
	
public:
	static const ConstantPointer createNone() throw( Exception );
	static const ConstantPointer createEmpty() throw( Exception );	
	static const ConstantPointer createNonlinkedFor( const A_type *pointerToObject ) throw( Exception );
	static const ConstantPointer createUnique( const A_type *pointerToObject ) throw( Exception );
	static const ConstantPointer createShared( const A_type *pointerToObject ) throw( Exception );

public:
	ConstantPointer() throw();

private:
	ConstantPointer( natural_small type, const A_type *pointerToObject ) throw( Exception );

};


} // namespace
