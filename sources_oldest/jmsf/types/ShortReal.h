#pragma once


#include "internals/internal_types.h"

#include "Boolean.hxx"
#include "jmsf/Exception.hxx"


namespace jmsf {
namespace types {


class ShortReal {

public:
	ShortReal getAbsolute() const throw();
	Boolean isAboutZero() const throw();

public: // math
	ShortReal operator +( const ShortReal &other ) const throw();
	ShortReal &operator +=( const ShortReal &other ) throw();

	ShortReal operator -( const ShortReal &other ) const throw();
	ShortReal operator -=( const ShortReal &other ) throw();

	ShortReal operator -() const throw();

	ShortReal operator *( const ShortReal &other ) const throw();
	ShortReal &operator *=( const ShortReal &other ) throw();

	ShortReal operator /( const ShortReal &other ) const throw( Exception );
	ShortReal &operator /=( const ShortReal &other ) throw( Exception );

// 	ShortReal operator %( const ShortReal &other ) const throw( Exception );
// 	ShortReal &operator %=( const ShortReal &other ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // bitwise
// 	ShortReal operator ^( const ShortReal &other ) const throw();
// 	ShortReal &operator ^=( const ShortReal &other ) throw();
// 
// 	ShortReal operator &( const ShortReal &other ) const throw();
// 	ShortReal &operator &=( const ShortReal &other ) throw();
// 
// 	ShortReal operator |( const ShortReal &other ) const throw();
// 	ShortReal &operator |=( const ShortReal &other ) throw();
//
//	ShortReal operator ~() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // logical
// 	ShortReal operator !() const throw();
// 	ShortReal operator &&( const ShortReal &other ) const throw();
// 	ShortReal operator ||( const ShortReal &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // comparison
	Boolean operator ==( const ShortReal &other ) const throw();
	Boolean operator !=( const ShortReal &other ) const throw();
	Boolean operator <( const ShortReal &other ) const throw();
	Boolean operator <=( const ShortReal &other ) const throw();
	Boolean operator >( const ShortReal &other ) const throw();
	Boolean operator >=( const ShortReal &other ) const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // shifts
// 	ShortReal operator <<( const ShortestNatural &other ) const throw();
// 	ShortReal &operator <<=( const ShortestNatural &other ) throw();
// 
// 	ShortReal operator >>( const ShortestNatural &other ) const throw();
// 	ShortReal &operator >>=( const ShortestNatural &other ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // increment/decrement
// 	ShortReal &operator ++() throw();
// 	ShortReal operator ++( int ) throw();
// 	ShortReal &operator --() throw();
// 	ShortReal operator --( int ) throw();

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
	internals::platform_short_real getPlatformValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~ShortReal() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortReal() throw();

public:
	static ShortReal create( internals::platform_short_real shortReal = internals::platform_short_real( 0.0f ) );

private:
	ShortReal( internals::platform_short_real shortReal ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	ShortReal( const ShortReal &other ) throw();
	const ShortReal &operator =( const ShortReal &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	internals::platform_short_real _shortReal;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static internals::platform_short_real math_computeAbsolute( internals::platform_short_real theReal ) throw();
	static Boolean math_isAboutZero( internals::platform_short_real theReal ) throw();
	static Boolean math_areAlmostEqual( internals::platform_short_real firstReal, internals::platform_short_real secondReal ) throw();

};


extern const ShortReal ShortRealZero;
extern const ShortReal ShortRealOne;
extern const ShortReal ShortRealTwo;


} // namespace types
} // namespace jmsf
