#pragma once

#include "base_pointing/BaseForPointerAndProxy.hpp"
#include "DeleterForPointer.hxx"
#include "Pointers.hxx"
#include "Exception.hxx"

#include "types.h"


namespace jmsf {


template< class A_type >
class Pointer :
	public base_pointing::BaseForPointerAndProxy< DeleterForPointer< A_type > >
{

public:
	Pointer getNonlinked() const throw( Exception );
	const ConstantPointer< A_type > getNonlinkedConstant() const throw( Exception );
	const ConstantPointer< A_type > takeConstant() const throw( Exception );
	
	const Pointer getAsShared() const throw( Exception );
	Pointer takeAsShared() throw( Exception );

public:
	static Pointer createNone() throw( Exception );
	static Pointer createEmpty() throw( Exception );	
	static Pointer createNonlinkedFor( const A_type *pointerToObject ) throw( Exception );
	static Pointer createUnique( const A_type *pointerToObject ) throw( Exception );
	static Pointer createShared( const A_type *pointerToObject ) throw( Exception );
	
public:
	Pointer() throw();

private:
	Pointer( natural_small type, const A_type *pointerToObject ) throw( Exception );

};


} // namespace
