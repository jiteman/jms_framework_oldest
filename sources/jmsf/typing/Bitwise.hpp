#pragma once


#include "Naturals.hxx"
#include "Boolean.hxx"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace typing {


template< class A_type >
class Bitwise {

public:
	A_type get_bits( Memory_size source_start_bit, Memory_size a_quantity ) const;
	Bitwise &set_bits( Memory_size destination_start_bit, Memory_size a_quantity );
	Bitwise &reset_bits( Memory_size destination_start_bit, Memory_size a_quantity );

	Bitwise &copy_bits_from( Memory_size destination_start_bit, A_type a_value, Memory_size source_start_bit, Memory_size a_quantity );

	Boolean is_set( Memory_size bit_index ) const;
	Bitwise &set( Memory_size bit_index );
	Boolean is_reset( Memory_size bit_index ) const;
	Bitwise &reset( Memory_size bit_index );
	Boolean get_status( Memory_size bit_index ) const;
	Bitwise &set_status( Memory_size bit_index, Boolean a_status ) const;

	Memory_size get_first_set_bit_index() const noexept;
	Memory_size get_last_set_bit_index() const noexept;
	Memory_size get_first_reset_bit_index() const noexept;
	Memory_size get_last_reset_bit_index() const noexept;

	Memory_size get_quantity_of_bits() const noexept;

	Bitwise &clear() noexept;
	Bitwise &fill() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	A_type get_value() const noexept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Bitwise() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Bitwise() noexept;
	static Bitwise create( A_type a_value ) noexept;

private:
	Bitwise( A_type a_value ) noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Bitwise( const Bitwise &another ) noexept;
	const Bitwise &operator =( const Bitwise &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	A_type _the_value;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static Boolean isInRange( Memory_size start_bit_index, Memory_size a_qiantity ) noexept;
	static A_type create_value_mask( Memory_size a_quantity ) noexept;
	static A_type create_bit_mask_from_value_mask( A_type a_value, Memory_size start_bit_index ) noexept;
};


} // namespace typing
} // namespace jmsf
