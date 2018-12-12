#pragma once

#include "../factory_Pointie_and_Proxie.h"


namespace jmsf {
namespace testing {
namespace realizations {


class realization_factory_Pointie_and_Proxie :
	public factory_Pointie_and_Proxie
{

public:
	// virtuals factory_Testing
	::jmsf::pointing::Pointer< testing_Pointie > createPointie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) const throw();
	::jmsf::pointing::Proxy< testing_Proxie > createProxie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_Pointie_and_Proxie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_Pointie_and_Proxie;
	realization_factory_Pointie_and_Proxie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_Pointie_and_Proxie( const realization_factory_Pointie_and_Proxie &other ) throw();
	const realization_factory_Pointie_and_Proxie &operator =( const realization_factory_Pointie_and_Proxie &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
