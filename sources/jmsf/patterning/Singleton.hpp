#pragma once


#include "Singleton.hxx"

#include "jmsf/memorying/Omp.hpp"
#include "jmsf/memorying/Womp.hpp"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {


template< class A_type >
class Singleton {

public:	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	virtual ~Singleton() noexept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	template< class A_creating_type >
	static void create_instance( const memorying::Womp< memorying::Allocator > &objectAllocator );

	static memorying::Womp< A_type > &instance() noexept;
	static void destroy_instance();

protected:
	Singleton() noexept;

// protected:
// 	static A_type *testing_setInstance( A_type *testingInstance );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Singleton( const Singleton &other ) noexept;
	const Singleton &operator =( const Singleton &other ) noexept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static memorying::Omp< A_type > _singletonInstance;
	static memorying::Womp< A_type > _referenceToReturn;

};


} // namespace patterning
} // namespace jmsf
