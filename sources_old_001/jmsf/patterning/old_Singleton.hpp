#pragma once


#include "old_Singleton.hxx"

#include "jmsf/memorying/Omp.hpp"
#include "jmsf/memorying/Womp.hpp"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {


template< class A_type >
class old_Singleton {

public:	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	virtual ~old_Singleton() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	template< class A_creating_type >
	static void create_instance( const memorying::Womp< memorying::Allocator > &objectAllocator );

	static memorying::Womp< A_type > &instance() noexcept;
	static void destroy_instance();

protected:
	old_Singleton() noexcept;

// protected:
// 	static A_type *testing_setInstance( A_type *testingInstance );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	old_Singleton( const old_Singleton &other ) noexcept;
	const old_Singleton &operator =( const old_Singleton &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static memorying::Omp< A_type > _singletonInstance;
	static memorying::Womp< A_type > _referenceToReturn;

};


} // namespace patterning
} // namespace jmsf
