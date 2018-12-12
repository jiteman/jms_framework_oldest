#pragma once


#include "ShortestNatural.hxx"


namespace jmsf {
namespace types {


template< class A_type >
class Bitwise {

public:
	A_type getBits( ShortestNatural startBitIndex, ShortestNatural quantityOfBits ) const throw( Exception );
	void setBits( A_type typeValue, ShortestNatural startBitIndex, ShortestNatural quantityOfBits ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type getValue() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Bitwise() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Bitwise() throw();
	static Bitwise create( A_type typeValue ) throw();

private:
	Bitwise( A_type typeValue ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Bitwise( const Bitwise &other ) throw();
	const Bitwise &operator =( const Bitwise &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _typeValue;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static Boolean isInRange( ShortestNatural startBitIndex, ShortestNatural quantityOfBits );
};


} // namespace types
} // namespace jmsf
