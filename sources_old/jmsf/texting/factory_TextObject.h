#pragma once


#include "jmsf/patterning/Singleton.inl"


#include "TextString.hxx"
#include "TextStream.hxx"

#include "jmsf/pointing/ConstantProxy.hxx"
#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/memorying/Destructor.hxx"
#include "jmsf/memorying/Allocator.hxx"

#include "jmsf/typing/internals/internal_types.h"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace texting {


class JMSF_DLL_INTERFACE factory_TextObject :
	public patterning::Singleton< factory_TextObject >
{

public:
	virtual pointing::ConstantProxy< TextString > createTextString( memorying::Allocator &anAllocator ) const throw() = 0;
	virtual pointing::ConstantProxy< TextString > createTextString( memorying::Allocator &anAllocator, const char *c_text ) const throw() = 0;

	virtual pointing::ConstantProxy< TextString > createConstantTextString( memorying::Allocator &anAllocator ) const throw() = 0;
	virtual pointing::ConstantProxy< TextString > createConstantTextString( memorying::Allocator &anAllocator, const char *c_text ) const throw() = 0;

	virtual pointing::Proxy< TextStream > createTextStream( memorying::Allocator &anAllocator ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_TextObject() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Destructor< factory_TextObject >;
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


} // namespace texting
} // namespace jmsf


namespace jmsf {


pointing::ConstantProxy< texting::TextString > JMSF_DLL_INTERFACE TEXT_STRING( memorying::Allocator &anAllocator, const typing::internals::platform_char *c_text );
pointing::ConstantProxy< texting::TextString > JMSF_DLL_INTERFACE CONSTANT_TEXT_STRING( memorying::Allocator &anAllocator, const typing::internals::platform_char *constant_c_text );


} // namespace jmsf
