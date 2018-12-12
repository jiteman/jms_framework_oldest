#pragma once


#include "../TextString.h"

#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/typing/internals/internal_types.h"

#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace texting {
namespace realizations {


class realization_factory_TextObject;


class constant_TextString :
	public TextString,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const typing::internals::platform_char *getCtext() const throw();
	typing::Boolean isEqual( const pointing::ConstantProxy< TextString > &other ) const throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~constant_TextString() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< TextString, constant_TextString >;
	constant_TextString( const typing::internals::platform_char *constant_c_text ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	const pointing::ConstantProxy< TextString > constant_TextString::createClone( memorying::Allocator &anAllocator ) const throw();

private:
	constant_TextString( const constant_TextString &other ) throw();
	const constant_TextString &operator =( const constant_TextString &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

//	static const char_t EMPTY_C_TEXT_STRING; = "\0Empty constant text string";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const typing::internals::platform_char *const _constant_c_text;

};


} // namespace realizations
} // namespace texting
} // namespace jmsf
