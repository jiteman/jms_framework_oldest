#include "Test_stop_watch.h"

#include "to_libs/system/SystemTime.h"

#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/typing/Naturals.inl"
#include "jmsf/memorying/Constructor.inl"


namespace jmsf {
namespace cule {


typing::Natural Test_stop_watch::getGlobalDuration() {
	return _systemTimeDevice->getCurrentTimeInMilliseconds() - _globalAtStart;
}

typing::Natural Test_stop_watch::getLocalDuration() {
	return _systemTimeDevice->getCurrentTimeInMilliseconds() - _localAtStart;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Test_stop_watch::startGlobal() {
	_globalAtStart = _systemTimeDevice->getCurrentTimeInMilliseconds();
}

void Test_stop_watch::startLocal() {
	_localAtStart = _systemTimeDevice->getCurrentTimeInMilliseconds();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void Test_stop_watch::initialize() throw() {
	_globalAtStart = typing::Natural_nill;
	_localAtStart = typing::Natural_nill;
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
Test_stop_watch::~Test_stop_watch() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
memorying::Omp< Test_stop_watch > Test_stop_watch::create_singleton_instance( const memorying::Womp< memorying::Allocator > &object_allocator ) throw() {
	// EIS: rework system time device creation. Reason: this allocator is for Test_stop_watch, not for System_time.
	pointing::Pointer< to_libs::system::SystemTime > system_time =
		pointing::Pointer< to_libs::system::SystemTime >::create_unique(
			memorying::Constructor< to_libs::system::SystemTime, to_libs::system::SystemTime >::construct( object_allocator ) );
	return memorying::Constructor< Test_stop_watch, Test_stop_watch >::construct( object_allocator, system_time );
}

Test_stop_watch::Test_stop_watch( const pointing::Pointer< to_libs::system::SystemTime > &system_time ) throw()
	:
		_systemTimeDevice( system_time )
{
////	debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( _systemTimeDevice.get(), MACROS_FILE_AND_LINE ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
Test_stop_watch::Test_stop_watch( const Test_stop_watch & ) throw() // other
{}

const Test_stop_watch &Test_stop_watch::operator =( const Test_stop_watch &other ) throw() {
	if ( this == &other ) return *this;

	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
}
