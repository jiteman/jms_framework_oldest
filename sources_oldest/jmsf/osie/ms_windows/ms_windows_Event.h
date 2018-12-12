#pragma once

#include "../Event.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Pointers.hxx"

#include "ms_windows_MultithreadingControl.hxx"

#include "ms_windows_include.h"

#include "../../jmsf.h"


namespace jmsf {
namespace osie {
namespace ms_windows {


class JMSF_DLL_INTERFACE ms_windows_Event :
	public Event,
	public ::jmsf::mixins::mixin_Object
{

public:
	// virtuals Event
	void set() throw();
	Boolean isSet() const throw();
	Boolean isNotSet() const throw();
	void reset() throw();
	void wait() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	HANDLE getHandle() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	friend DeleterForPointer< ms_windows_Event >;
	~ms_windows_Event() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_MultithreadingControl;
	ms_windows_Event() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< Event > createClone() const throw();

private:
	ms_windows_Event( const ms_windows_Event &other ) throw();
	const ms_windows_Event &operator =( const ms_windows_Event &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	HANDLE _handle;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
