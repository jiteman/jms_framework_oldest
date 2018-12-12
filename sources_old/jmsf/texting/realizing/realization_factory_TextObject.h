#pragma once


#include "../factory_TextObject.h"


namespace jmsf {
namespace texting {
namespace realizations {


class realization_factory_TextObject :
	public factory_TextObject
{

public:
	// virtuals
	pointing::ConstantProxy< TextString > createTextString( memorying::Allocator &anAllocator ) const throw();
	pointing::ConstantProxy< TextString > createTextString( memorying::Allocator &anAllocator, const char *c_text ) const throw();

	pointing::ConstantProxy< TextString > createConstantTextString( memorying::Allocator &anAllocator ) const throw();
	pointing::ConstantProxy< TextString > createConstantTextString( memorying::Allocator &anAllocator, const char *c_text ) const throw();

	pointing::Proxy< TextStream > createTextStream( memorying::Allocator &anAllocator ) const throw();
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


} // namespace realizations
} // namespace texting
} // namespace jmsf
