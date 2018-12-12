#pragma once

#include "../MultithreadingControl.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Exception.hxx"
#include "../factory_OperatingSystem.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {

class ms_windows_MultithreadingControl :
	public MultithreadingControl,
	public mixins::mixin_Object
{

public:
	// virtuals MultithreadingControl
 	Proxy< Event > createEvent() const throw();
 	Proxy< EventArray > createEventArray() const throw();
 	Proxy< Mutex > createMutex() const throw();
	void launchThread( Pointer< osie_Thread > thread, natural_size priorityLevel ) const throw( Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_MultithreadingControl() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_OperatingSystem;
	ms_windows_MultithreadingControl() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< MultithreadingControl > createClone() const throw();

private:
	ms_windows_MultithreadingControl( const ms_windows_MultithreadingControl &other ) throw();
	const ms_windows_MultithreadingControl &operator =( const ms_windows_MultithreadingControl &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	static int getPriorityLevelValue( natural_size priorityLevel ) throw( Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
