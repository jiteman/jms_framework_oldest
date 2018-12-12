#pragma once

#include "../testing_Pointie.h"

#include "jmsf/pointing/Pointer.hpp"

#include "realization_factory_Pointie_and_Proxie.hxx"
#include "../../sensing/sensing_Pointie.hxx"

#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace testing {
namespace realizations {


class realization_testing_Pointie :
	public testing_Pointie
{

public:
	// virtuals
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_testing_Pointie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< testing_Pointie, realization_testing_Pointie >;
	realization_testing_Pointie( const ::jmsf::pointing::Pointer< sensing::sensing_Pointie > &sensingPointer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
//	::jmsf::pointing::Pointer< testing_Pointie > createClone() const throw();

private:
	realization_testing_Pointie( const realization_testing_Pointie &other ) throw();
	const realization_testing_Pointie &operator =( const realization_testing_Pointie &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	 ::jmsf::pointing::Pointer< sensing::sensing_Pointie > _sensingPointer;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
