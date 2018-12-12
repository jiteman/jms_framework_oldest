#include "EventArray.h"
#include "Event.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {
namespace osie {
	
class null_EventArray :
	public EventArray,
	public mixins::mixin_null_Object,
	public Singleton< null_EventArray > {

public:
	// virtuals EventArray
	void appendEvent( const Proxy< Event > & ) throw( Exception ) {} // theEvent
	void appendEventArray( const Proxy< EventArray > & ) throw( Exception ) {} // eventArray
	void setAllEvents() throw() {}
	void resetAllEvents() throw() {}
	void waitForAnyEvent() const throw( Exception ) {}
	const ConstantProxy< Event > waitForAnyEventThenGetIt() const throw( Exception ) { return ConstantProxy< Event >(); }
	Proxy< Event > waitForAnyEventThenGetItOneself() throw( Exception ) { return Proxy< Event >(); }
	void waitForAllEvents() const throw( Exception ) {}
	Boolean isEmpty() const throw() { return True; }
	natural_size getQuantityOfEvents() const throw() { return 0; }
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_EventArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class Singleton< null_EventArray >;
		 static null_EventArray *createInstance() throw() {
			 null_EventArray *nullEventArray = new null_EventArray;
			 debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullEventArray, MACROS_FILE_AND_LINE ) );
			 return nullEventArray;
		 }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_EventArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< EventArray > createClone() const throw() { return Proxy< EventArray >::createUnique( this ); }

private:
	null_EventArray( const null_EventArray & ) throw() {}

	const null_EventArray &operator =( const null_EventArray &other ) throw() {
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
EventArray *EventArray::getNull() throw() {
	return null_EventArray::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace
}
