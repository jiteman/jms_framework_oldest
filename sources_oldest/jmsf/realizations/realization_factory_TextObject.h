#pragma once

#include "../factory_TextObject.h"


namespace jmsf {
namespace realizations {


class realization_factory_TextObject :
	public factory_TextObject
{

public:
	// virtuals
	ConstantProxy< TextString > createTextString() const throw();
	ConstantProxy< TextString > createTextString( const char *c_text ) const throw();

	ConstantProxy< TextString > createConstantTextString() const throw();
	ConstantProxy< TextString > createConstantTextString( const char *c_text ) const throw();

	Proxy< TextStream > createTextStream() const throw();
	//~virtuals

private:
	// virtual
	~realization_factory_TextObject() throw();

private: friend class factory_TextObject;
	realization_factory_TextObject() throw();

private:
//	realizationementation_factory_TextString( const realizationementation_factory_TextString & ) throw() {}
	const realization_factory_TextObject &operator =( const realization_factory_TextObject & ) throw() { return *this; }

};


} // namespace
}
