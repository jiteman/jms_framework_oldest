#pragma once


#include "internals/internal_types.h"

#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class Real {

public:
	Real getAbsolute() const throw();
	Boolean isAboutZero() const throw();

public: // math
	Real operator +( const Real &other ) const throw();
	Real &operator +=( const Real &other ) throw();

	Real operator -( const Real &other ) const throw();
	Real operator -=( const Real &other ) throw();

	Real operator -() const throw();

	Real operator *( const Real &other ) const throw();
	Real &operator *=( const Real &other ) throw();

	Real operator /( const Real &other ) const throw( Exception );
	Real &operator /=( const Real &other ) throw( Exception );

// 	Real operator %( const Real &other ) const throw( Exception );
// 	Real &operator %=( const Real &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
// 	Real operator ^( const Real &other ) const throw();
// 	Real &operator ^=( const Real &other ) throw();
// 
// 	Real operator &( const Real &other ) const throw();
// 	Real &operator &=( const Real &other ) throw();
// 
// 	Real operator |( const Real &other ) const throw();
// 	Real &operator |=( const Real &other ) throw();
//
//	Real operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	Real operator !() const throw();
// 	Real operator &&( const Real &other ) const throw();
// 	Real operator ||( const Real &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const Real &other ) const throw();
	Boolean operator !=( const Real &other ) const throw();
	Boolean operator <( const Real &other ) const throw();
	Boolean operator <=( const Real &other ) const throw();
	Boolean operator >( const Real &other ) const throw();
	Boolean operator >=( const Real &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
// 	Real operator <<( const ShortestNatural &other ) const throw();
// 	Real &operator <<=( const ShortestNatural &other ) throw();
// 
// 	Real operator >>( const ShortestNatural &other ) const throw();
// 	Real &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
// 	Real &operator ++() throw();
// 	Real operator ++( int ) throw();
// 	Real &operator --() throw();
// 	Real operator --( int ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // access
// 	ret_type &operator *() throw();
// 	const ret_type &operator *() const throw();
// 	ret_type *operator ->() throw();
// 	const ret_type *operator ->() const throw();
	
// 	ret_type &operator []( Unsigned index ) throw();
// 	const ret_type &operator []( Unsigned index ) const throw();
		
// 	ret_type operator()( parameters ) const throw();
// 	ret_type operator()( parameters ) throw();

//	operator ->*(); // pointer-to-member selection

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // new/delete
//	void *operator new( Unsigned sizeToAllocate ) throw( Exception );
//	void *operator new[]( Unsigned quantityToAllocate ) throw( Exception );
//	void operator delete( void *memoryToDeallocate );
//	void operator delete[]( void *memoryToDeallocate );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Boolean isNull() const throw();
	Boolean isNotNull() const throw();
	Boolean isPositive() const throw();
	Boolean isNegative() const throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
//	operator internals::platform_template_type() const throw();
	internals::platform_real getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Real() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Real() throw();

public:
	static Real create( internals::platform_real real = internals::platform_real( 0.0f ) );

private:
	Real( internals::platform_real real ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Real( const Real &other ) throw();
	const Real &operator =( const Real &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_real _real;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static internals::platform_real math_computeAbsolute( internals::platform_real theReal );
	static Boolean math_isAboutZero( internals::platform_real theReal );
	static Boolean math_areAlmostEqual( internals::platform_real firstReal, internals::platform_real secondReal );

};


extern const Real RealZero;
extern const Real RealOne;
extern const Real RealTwo;


} // namespace types
} // namespace jmsf
