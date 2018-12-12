#pragma once

#include "jmsf/patterning/Singleton.hpp"

#include "testing_Pointie.hxx"
#include "testing_Proxie.hxx"
#include "../sensing/sensing_Pointie.hxx"

#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace testing {

class factory_Pointie_and_Proxie :
	public ::jmsf::patterning::Singleton< factory_Pointie_and_Proxie >
{

public:
	virtual ::jmsf::pointing::Pointer< testing_Pointie > createPointie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) const throw() = 0;
	virtual ::jmsf::pointing::Proxy< testing_Proxie > createProxie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_Pointie_and_Proxie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:// friend class ::jmsf::Singleton< factory_Pointie_and_Proxie >;
	static factory_Pointie_and_Proxie *createInstance() throw();

protected:
	factory_Pointie_and_Proxie() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_Pointie_and_Proxie( const factory_Pointie_and_Proxie &other ) throw();
	const factory_Pointie_and_Proxie &operator =( const factory_Pointie_and_Proxie &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
