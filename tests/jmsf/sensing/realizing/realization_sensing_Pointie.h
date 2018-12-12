#pragma once

#include "../sensing_Pointie.h"


#include "realization_factory_Sensing.hxx"

////#include "jmsf/Pointer.hxx"

#include "jmsf/typing/Naturals.hpp"

#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace sensing {
namespace realizing {


class realization_sensing_Pointie :
	public sensing_Pointie
{

public:
	// virtuals
	void registerDestruction() throw();
	void registerConstruction() throw();

	typing::Memory_size getDestrutionCounter() const throw();
	typing::Memory_size getConstructionCounter() const throw();	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_sensing_Pointie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< sensing_Pointie, realization_sensing_Pointie >;
	realization_sensing_Pointie() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Pointer< sensing_Pointie > createClone() const throw();

private:
	realization_sensing_Pointie( const realization_sensing_Pointie &other ) throw();
	const realization_sensing_Pointie &operator =( const realization_sensing_Pointie &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::Memory_size _constructionCounter;
	typing::Memory_size _destructionCounter;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
