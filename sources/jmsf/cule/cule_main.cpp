#include "cule_main.h"

#include "execution/TestRunner.h"
#include "user_interfaces/UiOutput.h"
#include "user_interfaces/DebugOutputUi.h"
#include "user_interfaces/TextOutputUi.h"
#include "Test_stop_watch.h"

////#include "jmsf/Pointers.hpp"

#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/Pointer.inl"
#include "jmsf/memorying/Constructor.inl"
#include "jmsf/memorying/temporary_Allocator.h"
#include "jmsf/memorying/Allocator.h"


namespace jmsf {
namespace cule {


int cule_real_main( const pointing::Pointer< user_interfaces::UiOutput > &uiOutput ) {
	memorying::temporary_Allocator temporary_allocator;
	{
		memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );
		Test_stop_watch::create_instance< Test_stop_watch >( the_temporary_allocator );
	}

	execution::TestRunner testRunner( uiOutput );
	testRunner.run();

	Test_stop_watch::destroy_instance();
	return 0;
}

int cule_main_console() {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	pointing::Pointer< user_interfaces::UiOutput > ui_output =
		pointing::Pointer< user_interfaces::UiOutput >::create_unique(
		memorying::Constructor< user_interfaces::UiOutput, user_interfaces::TextOutputUi >::construct( the_temporary_allocator ) );

	return cule_real_main( ui_output );
}

int cule_main_visual_studio() {
	memorying::temporary_Allocator temporary_allocator;
	memorying::Womp< memorying::Allocator > the_temporary_allocator = memorying::Womp< memorying::Allocator >::create_from_pointer( &temporary_allocator );

	pointing::Pointer< user_interfaces::UiOutput > ui_output =
		pointing::Pointer< user_interfaces::UiOutput >::create_unique(
		memorying::Constructor< user_interfaces::UiOutput, user_interfaces::DebugOutputUi >::construct( the_temporary_allocator ) );

	return cule_real_main( ui_output );
}


} // namespace cule
} // namespace jmsf
