#pragma once

//#include "types.h"

#include "jmsf/types/Boolean.hxx"
#include "jmsf/debugging/FileAndLine.hxx"
#include "jmsf/TextString.hxx"
#include "jmsf/Proxies.hxx"
#include "jmsf/Exception.hxx"

#include "jmsf/jmsf.h"


namespace jmsf {


class JMSF_DLL_INTERFACE Should {

public:
	static void alwaysBe( types::Boolean expression, const debugging::FileAndLine &fileAndLine ) throw( Exception );
	static void neverBe( types::Boolean expression, const debugging::FileAndLine &fileAndLine ) throw( Exception );

	static void alwaysBeNull( const void *pointer, const debugging::FileAndLine &fileAndLine ) throw( Exception );
	static void neverBeNull( const void *pointer, const debugging::FileAndLine &fileAndLine ) throw( Exception );

	template< class A_type >
	static void alwaysBeNullObject( const A_type *pointer, const debugging::FileAndLine &fileAndLine ) throw( Exception );

	template< class A_type >
	static void neverBeNullObject( const A_type *pointer, const debugging::FileAndLine &fileAndLine ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
	static void _neverReachHere( const ConstantProxy< TextString > &reason, const debugging::FileAndLine &fileAndLine ) throw( Exception );
	static void neverViolateCopyingProhibition( const ConstantProxy< TextString > &place, const debugging::FileAndLine &fileAndLine ) throw( Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	~Should() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Should( const Should &other ) throw();
	const Should &operator =( const Should &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

};

} // namespace jmsf


#include "jmsf/debugging/FileAndLine.h"


namespace jmsf {


template< class A_type >
void Should::alwaysBeNullObject( const A_type *pointer, const debugging::FileAndLine &fileAndLine ) throw( Exception ) {
	if ( pointer == nullptr ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::alwaysBeNullObject( nullptr )" ), fileAndLine );
	}

	if ( pointer->isNull().not() ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::alwaysBeNullObject( not NullObject )" ), fileAndLine );
	}
}

template< class A_type >
void Should::neverBeNullObject( const A_type *pointer, const debugging::FileAndLine &fileAndLine ) throw( Exception ) {
	if ( pointer == nullptr ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::neverBeNullObject( nullptr )" ), fileAndLine );
	}

	if ( pointer->isNull() ) {
		throw realizations::exception_Should( CONSTANT_TEXT_STRING( "Should::neverBeNullObject( NullObject )" ), fileAndLine );
	}
}


} // namespace
