#pragma once

#include "jmsf/patterning/Singleton.hpp"

#include "sensing_Pointie.hxx"

#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/memorying/Womp.hxx"
#include "jmsf/memorying/Allocator.hxx"


namespace jmsf {
namespace sensing {


class factory_Sensing :
	public ::jmsf::patterning::Singleton< factory_Sensing >
{

public:
	virtual pointing::Pointer< sensing_Pointie > createPointie( const memorying::Womp< memorying::Allocator > &pointie_allocator ) const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_Sensing() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< factory_Sensing >;
	static factory_Sensing *create_singleton_instance() throw();
//	static factory_Sensing *createInstance() throw();

protected:
	factory_Sensing() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_Sensing( const factory_Sensing &other ) throw();
	const factory_Sensing &operator =( const factory_Sensing &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
