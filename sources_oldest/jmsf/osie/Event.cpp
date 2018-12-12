#include "Event.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
	
class null_Event :
	public Event,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_Event >
{

public:
	// virtuals Event
	void set() throw() {}
	Boolean isSet() const throw() { return False; }
	Boolean isNotSet() const throw() { return True; }
	void reset() throw() {}
	void wait() const throw() {}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_Event() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_Event >;
	static null_Event *createInstance() throw() {
		null_Event *nullEvent = new null_Event;
		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullEvent, MACROS_FILE_AND_LINE ) );
		return nullEvent;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Event() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< Event > createClone() const throw() { return ::jmsf::Proxy< Event >::createUnique( this ); }

private:
	null_Event( const null_Event & ) throw() {}

	const null_Event &operator =( const null_Event &other ) throw() {
		if ( this == &other ) return *this;

		// copy
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
Event *Event::getNull() throw() {
	return null_Event::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
