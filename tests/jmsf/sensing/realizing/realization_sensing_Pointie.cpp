#include "realization_sensing_Pointie.h"

////#include "jmsf/Pointer.hpp"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/typing/Naturals.inl"

#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/temporary_Allocator.h"


namespace jmsf {
namespace sensing {
namespace realizing {


void realization_sensing_Pointie::registerDestruction() throw() {
	_destructionCounter += typing::Memory_size_one;
}

void realization_sensing_Pointie::registerConstruction() throw() {
	_constructionCounter += typing::Memory_size_one;
}

typing::Memory_size realization_sensing_Pointie::getDestrutionCounter() const throw() {
	return _destructionCounter;
}

typing::Memory_size realization_sensing_Pointie::getConstructionCounter() const throw() {
	return _constructionCounter;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realization_sensing_Pointie::~realization_sensing_Pointie() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realization_sensing_Pointie::realization_sensing_Pointie() throw() {
	_constructionCounter = typing::Memory_size_nill;
	_destructionCounter = typing::Memory_size_nill;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
pointing::Pointer< sensing_Pointie > realization_sensing_Pointie::createClone() const throw() {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	return
		pointing::Pointer< sensing_Pointie >::create_unique(
			memorying::Constructor< sensing_Pointie, realization_sensing_Pointie >::construct( the_temporary_allocator ) );

////	sensing_Pointie *sensingPointie = new realization_sensing_Pointie( *this );
////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForObjectedCreation( sensingPointie, MACROS_FILE_AND_LINE ) );
////	return ::jmsf::pointing::Pointer< sensing_Pointie >::create_unique( sensingPointie );
}

realization_sensing_Pointie::realization_sensing_Pointie( const realization_sensing_Pointie & ) throw() // other
{}

const realization_sensing_Pointie &realization_sensing_Pointie::operator =( const realization_sensing_Pointie &other ) throw() {
	if ( this == &other ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
}
