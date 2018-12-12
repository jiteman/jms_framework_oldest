#pragma once

#include "base_pointing/BaseForConstantPointerAndConstantProxy.hpp"
#include "DeleterForProxy.hxx"
#include "Proxies.hxx"
#include "Exception.hxx"

#include "types.h"


namespace jmsf {


template< class A_type >
class ConstantProxy :
	public base_pointing::BaseForConstantPointerAndConstantProxy< DeleterForProxy< A_type > >
{

public:
	const ConstantProxy getNonlinked() const throw( Exception );
	const ConstantProxy getAsShared() const throw( Exception );

public:
	static ConstantProxy createNone() throw( Exception );
	static ConstantProxy createEmpty() throw( Exception );	
	static ConstantProxy createNonlinkedFor( const A_type *pointerToObject ) throw( Exception );
	static ConstantProxy createUnique( const A_type *pointerToObject ) throw( Exception );
	static ConstantProxy createShared( const A_type *pointerToObject ) throw( Exception );

public:
	ConstantProxy() throw();

private:
	ConstantProxy( natural_small type, const A_type *pointerToObject ) throw( Exception );

};


} // namespace
