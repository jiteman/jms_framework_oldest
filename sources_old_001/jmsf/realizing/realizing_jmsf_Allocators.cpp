#include "realizing_jmsf_Allocators.h"


#include "jmsf/memorying/realizing/realizing_System_allocator.h"
#include "jmsf/memorying/realizing/realizing_Application_allocator.h"
#include "jmsf/memorying/realizing/realizing_Subsystem_allocator.h"

#include "jmsf/patterning/Singleton.hin"
#include "jmsf/memorying/Constructor.hin"
#include "jmsf/memorying/Destructor.hin"
#include "jmsf/memorying/Womp.hin"
#include "jmsf/memorying/Omp.hin"
#include "jmsf/memorying/Owomp.hin"


namespace jmsf {
namespace realizing {


//const memorying::Womp< memorying::Allocator > &realizing_jmsf_Allocators::get_application_allocator() const noexcept {
//	return _application_allocator.get_womp();
//}

const memorying::Womp< memorying::Allocator > &realizing_jmsf_Allocators::get_subsystem_allocator() const noexcept {
	return _subsystem_allocator.get_womp();
}

const memorying::Womp< memorying::Allocator > &realizing_jmsf_Allocators::get_character_array_allocator() const noexcept {
	return _subsystem_allocator.get_womp();
}

const memorying::Womp< memorying::Allocator > &realizing_jmsf_Allocators::get_list_node_allocator() const noexcept {
	return _subsystem_allocator.get_womp();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
realizing_jmsf_Allocators::~realizing_jmsf_Allocators() noexcept {
	memorying::Destructor< memorying::Allocator >::destruct( _subsystem_allocator.get_omp() );
	_subsystem_allocator = memorying::Owomp< memorying::Allocator >();
//	memorying::Destructor< memorying::Allocator >::destruct( _application_allocator.get_omp() );
//	_application_allocator = memorying::Owomp< memorying::Allocator >();
//	memorying::Destructor< memorying::Allocator >::destruct( _system_allocator.get_omp() );
//	_system_allocator = memorying::Owomp< memorying::Allocator >();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_jmsf_Allocators::realizing_jmsf_Allocators(
//	const memorying::Omp< memorying::Allocator > &system_allocator,
//	const memorying::Omp< memorying::Allocator > &application_allocator,
	const memorying::Omp< memorying::Allocator > &subsystem_allocator) noexcept
	:
//		_system_allocator( memorying::Owomp< memorying::Allocator >::create( system_allocator ) ),
//		_application_allocator( memorying::Owomp< memorying::Allocator >::create( application_allocator ) ),
		_subsystem_allocator( memorying::Owomp< memorying::Allocator >::create( subsystem_allocator ) )
{}

// static
void realizing_jmsf_Allocators::create_instance(
	const memorying::Womp< memorying::Allocator > &application_allocator,
	const memorying::Omp< memorying::Allocator > &subsystem_allocator ) noexcept
{
	set_instance( memorying::Constructor< jmsf_Allocators, realizing_jmsf_Allocators >::construct( application_allocator, subsystem_allocator ) );
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
realizing_jmsf_Allocators::realizing_jmsf_Allocators( const realizing_jmsf_Allocators &/*another*/ ) noexcept {
}

const realizing_jmsf_Allocators &realizing_jmsf_Allocators::operator =( const realizing_jmsf_Allocators &another ) noexcept {
	if ( &another == this ) return *this;

	// copy
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace realizing
} // namespace jmsf
