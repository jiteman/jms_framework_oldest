#pragma once


#include "jmsf/patterning/Singleton.hpp"

#include "jmsf/pointing/Pointer.hpp"
#include "jmsf/typing/Naturals.hpp"
////#include "jmsf/Pointers.hpp"
////#include "jmsf/types.h"

#include "to_libs/system/SystemTime.hxx"
#include "jmsf/memorying/Constructor.hxx"
#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace cule {


class Test_stop_watch :
	public patterning::Singleton< Test_stop_watch >
{

public:
	typing::Natural getGlobalDuration();
	typing::Natural getLocalDuration();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void startGlobal();
	void startLocal();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	void initialize() throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< Test_stop_watch >;
	~Test_stop_watch() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< Test_stop_watch >;
	static memorying::Omp< Test_stop_watch > create_singleton_instance( const memorying::Womp< memorying::Allocator > &object_allocator ) throw();

private: friend memorying::Constructor< Test_stop_watch, Test_stop_watch >;
	Test_stop_watch( const pointing::Pointer< to_libs::system::SystemTime > &system_time ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	Test_stop_watch( const Test_stop_watch &other ) throw();
	const Test_stop_watch &operator =( const Test_stop_watch &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::Natural _globalAtStart;
	typing::Natural _localAtStart;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Pointer< to_libs::system::SystemTime > _systemTimeDevice;

};

} // namespace
}
