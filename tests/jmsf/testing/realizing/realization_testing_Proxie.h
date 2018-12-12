#pragma once

#include "../testing_Proxie.h"

#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/pointing/Pointer.hpp"

#include "../../sensing/sensing_Pointie.hxx"

#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace testing {
namespace realizations {


class realization_factory_Pointie_and_Proxie;


class realization_testing_Proxie :
	public testing_Proxie,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals testing_Proxie
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_testing_Proxie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< testing_Proxie, realization_testing_Proxie >;
	realization_testing_Proxie(
		const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointie ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
//	::jmsf::pointing::Proxy< testing_Proxie > createClone() const throw();

private:
	realization_testing_Proxie( const realization_testing_Proxie &other ) throw();
	const realization_testing_Proxie &operator =( const realization_testing_Proxie &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::pointing::Pointer< sensing::sensing_Pointie > _sensingPointie;
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
