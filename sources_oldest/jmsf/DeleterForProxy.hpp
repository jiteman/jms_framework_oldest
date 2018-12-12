#pragma once


#include "BaseTemplates.hpp"


namespace jmsf {


template< class A_type >
class DeleterForProxy :
	public IndirectorBase< A_type >
{

public:
	static void _deleteObject( const A_type *object ) throw();
	static A_type *getNull() throw();

private:
	DeleterForProxy() throw();

};


} // namespace
