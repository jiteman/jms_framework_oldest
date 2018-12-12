#pragma once


#include "base_pointing/BaseForPointerAndProxy.hpp"

#include "DeleterForProxy.hxx"
#include "Proxies.hxx"
#include "Exception.hxx"


namespace jmsf {


template< class A_type >
class Proxy :
	public base_pointing::BaseForPointerAndProxy< DeleterForProxy< A_type > >
{

public:
	Proxy getNonlinked() const throw( Exception );
	const ConstantProxy< A_type > getNonlinkedConstant() const throw( Exception );
	const ConstantProxy< A_type > takeConstant() const throw( Exception );

	const Proxy getAsShared() const throw( Exception );
	Proxy takeAsShared() throw( Exception );
	
public:
	static Proxy createNone() throw( Exception );
	static Proxy createEmpty() throw( Exception );	
	static Proxy createNonlinkedFor( const A_type *pointerToObject ) throw( Exception );
	static Proxy createUnique( const A_type *pointerToObject ) throw( Exception );
	static Proxy createShared( const A_type *pointerToObject ) throw( Exception );

public:
	Proxy() throw();

// public:
// 	Proxy( const Proxy &other ) throw( Exception );
// 	const Proxy &operator =( const Proxy &other ) throw( Exception );

private:
	Proxy( types::ShortestNatural type, const A_type *pointerToObject ) throw( Exception );	

};


} // namespace
