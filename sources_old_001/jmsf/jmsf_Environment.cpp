#include "jmsf_Environment.h"


#include "jmsf/realizing/realizing_jmsf_Allocators.h"
#include "jmsf/memorying/realizing/realizing_Subsystem_allocator.h"
#include "jmsf/memorying/realizing/realizing_Application_allocator.h"
#include "jmsf/memorying/realizing/realizing_System_allocator.h"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Owomp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Womp.hin"
//


namespace jmsf {


const memorying::Womp< memorying::Allocator > &jmsf_Environment::get_application_allocator() const noexcept {
	return _application_allocator.get_womp();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
const jmsf_Environment *jmsf_Environment::instance() noexcept {
	static jmsf_Environment environment_instance;
	return &environment_instance;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
void jmsf_Environment::initialize_status_text_messages() {
}

int jmsf_Environment::initialize_environment() {
	_system_allocator = memorying::Owomp< memorying::Allocator >::create( memorying::realizing::realizing_System_allocator::create() );

	_application_allocator =
		memorying::Owomp< memorying::Allocator >::create(
			memorying::realizing::realizing_Application_allocator::create( _system_allocator.get_womp() ) );

	realizing::realizing_jmsf_Allocators::set_instance(
		memorying::Constructor< jmsf_Allocators, realizing::realizing_jmsf_Allocators >::construct(
			_application_allocator.get_womp(),
			memorying::realizing::realizing_Subsystem_allocator::create( _application_allocator.get_womp() ) ) );

//	_jmsf_allocators = memorying::Owomp< jmsf_Allocators >::create( realizing::realizing_jmsf_Allocators::create() );
	return 0;
}

void jmsf_Environment::terminate_environment() noexcept {
	memorying::Destructor< memorying::Allocator >::destruct( _application_allocator.get_omp()  );
	_application_allocator = memorying::Owomp< memorying::Allocator >();
	memorying::Destructor< memorying::Allocator >::destruct( _system_allocator.get_omp()  );
	_system_allocator = memorying::Owomp< memorying::Allocator >();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
jmsf_Environment::~jmsf_Environment() noexcept {
	terminate_whole_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
jmsf_Environment::jmsf_Environment() noexcept
	:
		mixin_Environment()
{
	initialize_whole_environment();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
jmsf_Environment::jmsf_Environment( const jmsf_Environment &another ) noexcept // another
	:
		mixin_Environment( another )
{}

const jmsf_Environment &jmsf_Environment::operator =( const jmsf_Environment &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace jmsf
