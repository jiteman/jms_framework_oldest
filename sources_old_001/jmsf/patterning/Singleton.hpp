#pragma once


#include "Singleton.hxx"

//#include "jmsf/memorying/Omp.hpp"
//#include "jmsf/memorying/Womp.hpp"
#include "jmsf/memorying/Owomp.hpp"
//#include "jmsf/memorying/Destructor.hxx"


#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"
#include "jmsf/encodebuba/common_standard_support.h"


#include "jmsf/jmsf.h"


namespace jmsf {
namespace patterning {


template< class A_type >
class Singleton {

public:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: // friend memorying::Destructor< Singleton< A_type > >;
	virtual ~Singleton() noexcept = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static memorying::Womp< A_type > &instance();
	static void set_instance( const memorying::Omp< A_type > &an_instance ) noexcept;
	static memorying::Omp< A_type > &take_instance() noexcept;
	static void destroy_instance();

protected:
	Singleton() noexcept;

// protected:
// 	static A_type *testing_setInstance( A_type *testingInstance );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Singleton( const Singleton &other ) noexcept;
	const Singleton &operator =( const Singleton &other ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	static memorying::Owomp< A_type > _owomp_singleton_instance;

};


} // namespace patterning
} // namespace jmsf
