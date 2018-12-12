#pragma once

#include "Ansii_text.hxx"


#include "jmsf/memorying/Amp.hpp"
#include "jmsf/typeing/internals/internal_types.h"

#include "jmsf/pointing/Constant_pointer.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/typeing/Boolean.hxx"
#include "jmsf/typeing/Naturals.hxx"


namespace jmsf {
namespace texting {


// SenSEI: nextodo - create null objects
class Ansii_text {

public:
	typeing::Boolean is_empty() const noexcept;
	typeing::Boolean is_not_empty() const noexcept;
	typeing::Memory_natural get_quantity() const noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	typeing::Boolean is_equal( const pointing::Constant_pointer< Ansii_text > &another ) const;
	typeing::Boolean is_not_equal( const pointing::Constant_pointer< Ansii_text > &another ) const;
	typeing::Boolean is_same( const pointing::Constant_pointer< Ansii_text > &another ) const;
	typeing::Boolean is_not_same( const pointing::Constant_pointer< Ansii_text > &another ) const;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Ansii_text >;
	~Ansii_text() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< Ansii_text, Ansii_text >;
	Ansii_text() noexcept;

public:
	static pointing::Constant_pointer< Ansii_text > create();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Ansii_text( const Ansii_text &another ) noexcept;
	const Ansii_text &operator =( const Ansii_text &another ) noexcept;

public:
	Ansii_text( Ansii_text &&another ) noexcept;

private:
	Ansii_text &operator =( Ansii_text && ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	memorying::Amp< typeing::internals::platform_character > _character_array_memory_pointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace texting
} // namespace jmsf
