#pragma once

#include "Singleton.hpp"

#include "TextString.hxx"
#include "TextStream.hxx"

#include "Proxies.hxx"

#include "types.h"

#include "jmsf.h"


namespace jmsf {


class JMSF_DLL_INTERFACE factory_TextObject :
	public Singleton< factory_TextObject >
{

public:
	virtual ConstantProxy< TextString > createTextString() const throw() = 0;
	virtual ConstantProxy< TextString > createTextString( const char *c_text ) const throw() = 0;

	virtual ConstantProxy< TextString > createConstantTextString() const throw() = 0;
	virtual ConstantProxy< TextString > createConstantTextString( const char *c_text ) const throw() = 0;

	virtual Proxy< TextStream > createTextStream() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_TextObject() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class Singleton< factory_TextObject >;
	static factory_TextObject *createInstance() throw();

protected:
	factory_TextObject() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_TextObject( const factory_TextObject &other ) throw();
	const factory_TextObject &operator =( const factory_TextObject &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace


namespace jmsf {


ConstantProxy< TextString > JMSF_DLL_INTERFACE TEXT_STRING( const char_type *const c_text );
ConstantProxy< TextString > JMSF_DLL_INTERFACE CONSTANT_TEXT_STRING( const char_type *const constant_c_text );


} // namespace
