#pragma once


#include "internals/internal_types.h"

#include "jmsf/validating/Exception.hxx"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace typing {


class JMSF_DLL_INTERFACE Boolean {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
	Boolean operator !() const throw();
	Boolean operator &&( const Boolean &other ) const throw();
	Boolean operator ||( const Boolean &other ) const throw();

public: // logical synonyms
	Boolean not() const throw();
	Boolean equal( Boolean other ) const throw();
	Boolean notEqual( Boolean other ) const throw();
	Boolean and( Boolean other ) const throw();
	Boolean or( Boolean other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Boolean &other ) const throw();
	Boolean operator !=( const Boolean &other ) const throw();
	Boolean operator <( const Boolean &other ) const throw();
	Boolean operator <=( const Boolean &other ) const throw();
	Boolean operator >( const Boolean &other ) const throw();
	Boolean operator >=( const Boolean &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( validating::Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( validating::Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	operator internals::platform_boolean() const throw();
	internals::platform_boolean getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Boolean() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean() throw();

public:
	static Boolean create( internals::platform_boolean booleanValue = internals::platform_boolean( 0 ) );

private:
	Boolean( internals::platform_boolean booleanValue ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean( const Boolean &other ) throw();
	const Boolean &operator =( const Boolean &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_boolean _booleanValue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


JMSF_DLL_INTERFACE extern const Boolean True;
JMSF_DLL_INTERFACE extern const Boolean False; 


} // namespace typing
} // namespace jmsf
