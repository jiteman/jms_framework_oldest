#pragma once


#include "../MultithreadingControl.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/validating/Exception.hxx"
#include "../factory_OperatingSystem.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_MultithreadingControl :
	public MultithreadingControl,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals MultithreadingControl
 	pointing::Proxy< Event > createEvent() const throw();
 	pointing::Proxy< EventArray > createEventArray() const throw();
 	pointing::Proxy< Mutex > createMutex() const throw();
	void launchThread( pointing::Pointer< osie_Thread > aThread, typing::Natural priorityLevel ) const throw( validating::Exception );
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
	pointing::Proxy< MultithreadingControl > createClone() const throw();

private:
	ms_windows_MultithreadingControl( const ms_windows_MultithreadingControl &other ) throw();
	const ms_windows_MultithreadingControl &operator =( const ms_windows_MultithreadingControl &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
//	static int getPriorityLevelValue( natural_size priorityLevel ) throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
