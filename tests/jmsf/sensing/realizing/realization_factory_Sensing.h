#pragma once


#include "../factory_Sensing.h"


namespace jmsf {
namespace sensing {
namespace realizing {


class realization_factory_Sensing :
	public factory_Sensing
{

public:
	// virtuals factory_Sensing
	pointing::Pointer< sensing_Pointie > createPointie( const memorying::Womp< memorying::Allocator > &pointie_allocator ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_Sensing() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_Sensing;
	realization_factory_Sensing() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_Sensing( const realization_factory_Sensing &other ) throw();
	const realization_factory_Sensing &operator =( const realization_factory_Sensing &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
