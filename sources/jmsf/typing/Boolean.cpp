#include "Boolean.h"


namespace jmsf {
namespace typing {


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical
Boolean Boolean::operator !() const throw() {
	return Boolean( !_booleanValue );
}

Boolean Boolean::operator &&( const Boolean &other ) const throw() {
	return Boolean( _booleanValue && other._booleanValue );
}

Boolean Boolean::operator ||( const Boolean &other ) const throw() {
	return Boolean( _booleanValue || other._booleanValue );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// logical synonyms
Boolean Boolean::not() const throw() {
	return operator !();
}

Boolean Boolean::equal( const Boolean other ) const throw() {
	return operator ==( other );
}

Boolean Boolean::notEqual( const Boolean other ) const throw() {
	return operator !=( other );
}

Boolean Boolean::and( const Boolean other ) const throw() {
	return operator &&( other );
}

Boolean Boolean::or( const Boolean other ) const throw() {
	return operator ||( other );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// comparison
Boolean Boolean::operator ==( const Boolean &other ) const throw() {
	return Boolean( _booleanValue == other._booleanValue );
}

Boolean Boolean::operator !=( const Boolean &other ) const throw() {
	return operator ==( other ).not();
}

Boolean Boolean::operator <( const Boolean &other ) const throw() {
	return Boolean( _booleanValue < other._booleanValue );
}

Boolean Boolean::operator <=( const Boolean &other ) const throw() {
	return Boolean( _booleanValue <= other._booleanValue );
}

Boolean Boolean::operator >( const Boolean &other ) const throw() {
	return Boolean( _booleanValue > other._booleanValue );
}

Boolean Boolean::operator >=( const Boolean &other ) const throw() {
	return Boolean( _booleanValue >= other._booleanValue );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( validating::Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( validating::Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean::operator internals::platform_boolean() const throw() {
	return _booleanValue;
}

internals::platform_boolean Boolean::getPlatformValue() const throw() {
	return _booleanValue;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Boolean::~Boolean() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean::Boolean() throw() {
	_booleanValue = internals::platform_boolean( 0 );
}

// static
Boolean Boolean::create( const internals::platform_boolean booleanValue /*= default*/ ) {
	return Boolean( booleanValue );
}


Boolean::Boolean( const internals::platform_boolean booleanValue ) throw() {
	_booleanValue = booleanValue;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Boolean::Boolean( const Boolean &other ) throw() {
	_booleanValue = other._booleanValue;
}

const Boolean &Boolean::operator =( const Boolean &other ) throw() {
	if ( &other != this ) {
		_booleanValue = other._booleanValue;
	}

	return *this;	
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


// extern
const Boolean True = Boolean::create( true );

// extern
const Boolean False = Boolean::create( false ); 


} // namespace typing
} // namespace jmsf
