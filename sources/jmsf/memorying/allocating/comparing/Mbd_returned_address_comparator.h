#pragma once

#include "jmsf/assisting/Comparator.hpp"

#include "../Memory_block_descriptor.hxx"

#include "jmsf/typing/Comparasion_result.hxx"


namespace jmsf {
namespace memorying {
namespace allocating {
namespace comparing {


class Mbd_returned_address_comparator :
	public assisting::Comparator< Memory_block_descriptor >
{

public: 
	// virtuals assisting::Comparator< Memory_block_descriptor >
	typing::Comparasion_result compare( const Memory_block_descriptor &first, const Memory_block_descriptor &second ) const noexept;
	//~virtuals assisting::Comparator< Memory_block_descriptor >

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual assisting::Comparator< Memory_block_descriptor >
	~Mbd_returned_address_comparator() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mbd_returned_address_comparator() noexept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Mbd_returned_address_comparator( const Mbd_returned_address_comparator &another ) noexept;
	const Mbd_returned_address_comparator &operator =( const Mbd_returned_address_comparator &another ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace comparing
} // namespace allocating
} // namespace memorying
} // namespace jmsf
