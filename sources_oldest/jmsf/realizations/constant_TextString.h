#pragma once


#include "../TextString.h"

#include "../mixins/mixin_Object.h"

#include "../types.h"


namespace jmsf {
namespace realizations {


class realization_factory_TextObject;


class constant_TextString :
	public TextString,
	public mixins::mixin_Object {

public:
	// virtuals
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const char_type *getCtext() const throw();
	Boolean isEqual( const ConstantProxy< TextString > &other ) const throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~constant_TextString() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class realization_factory_TextObject;
	constant_TextString( const char_type *constant_c_text ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	const ConstantProxy< TextString > constant_TextString::createClone() const throw();

private:
	constant_TextString( const constant_TextString &other ) throw();
	const constant_TextString &operator =( const constant_TextString &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

//	static const char_t EMPTY_C_TEXT_STRING; = "\0Empty constant text string";

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	const char_type *const _constant_c_text;

};


} // namespace
}
