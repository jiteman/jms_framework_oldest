#pragma once

#include "../Event.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

//#include "jmsf/Pointer.hxx"

#include "ms_windows_MultithreadingControl.hxx"

#include "ms_windows_include.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace osie {
namespace ms_windows {


class JMSF_DLL_INTERFACE ms_windows_Event :
	public Event,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals Event
	void set() throw();
	typing::Boolean isSet() const throw();
	typing::Boolean isNotSet() const throw();
	void reset() throw();
	void wait() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	HANDLE getHandle() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	friend memorying::Destructor< ms_windows_Event >;
	~ms_windows_Event() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_MultithreadingControl;
	ms_windows_Event() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< Event > createClone() const throw();

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
