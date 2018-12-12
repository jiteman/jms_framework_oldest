#pragma once


#include <typeinfo>


// a_type parameter left without parentheses intentionally
#define JMSF_TYPE_NAME( a_type ) \
	( typeid( a_type ).name() )

//#define JMSF_TYPE_NAME( a_type )
//	"default_type"
