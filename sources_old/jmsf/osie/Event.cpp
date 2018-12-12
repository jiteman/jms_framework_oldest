#include "Event.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/Singleton.inl"

#include "jmsf/texting/TextString.h"

#include "jmsf/typing/Boolean.h"
#include "jmsf/pointing/ConstantProxy.inl"
#include "jmsf/pointing/Proxy.inl"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {

	
class null_Event :
	public Event,
	public ::jmsf::patterning::mixing::mixin_null_Object,
	public ::jmsf::patterning::Singleton< null_Event >
{

public:
	// virtuals Event
	void set() throw() {}
	typing::Boolean isSet() const throw() { return typing::False; }
	typing::Boolean isNotSet() const throw() { return typing::True; }
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
private: friend ::jmsf::patterning::Singleton< null_Event >;
	static null_Event *createInstance() throw() {
		null_Event *nullEvent = new null_Event;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullEvent, MACROS_FILE_AND_LINE ) );
		return nullEvent;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_Event() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Event > createClone() const throw() { return ::jmsf::pointing::Proxy< Event >::createUnique( this ); }

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
