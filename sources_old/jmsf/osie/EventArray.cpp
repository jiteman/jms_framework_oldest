#include "EventArray.h"

#include "Event.h"
#include "jmsf/patterning/mixing/mixin_null_Object.h"

#include "jmsf/patterning/Singleton.inl"

#include "jmsf/texting/TextString.h"

#include "jmsf/pointing/Proxy.inl"

//#include "jmsf/Proxies.hpp"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace osie {


class null_EventArray :
	public EventArray,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< null_EventArray > {

public:
	// virtuals EventArray
	void appendEvent( const pointing::Proxy< Event > & ) throw( validating::Exception ) {} // theEvent
	void appendEventArray( const pointing::Proxy< EventArray > & ) throw( validating::Exception ) {} // eventArray
	void setAllEvents() throw() {}
	void resetAllEvents() throw() {}
	void waitForAnyEvent() const throw( validating::Exception ) {}
	const pointing::ConstantProxy< Event > waitForAnyEventThenGetIt() const throw( validating::Exception ) { return pointing::ConstantProxy< Event >(); }
	pointing::Proxy< Event > waitForAnyEventThenGetItOneself() throw( validating::Exception ) { return pointing::Proxy< Event >(); }
	void waitForAllEvents() const throw( validating::Exception ) {}
	typing::Boolean isEmpty() const throw() { return typing::True; }
	typing::Natural getQuantityOfEvents() const throw() { return typing::Natural::create( 0 ); }
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_EventArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< null_EventArray >;
		 static null_EventArray *createInstance() throw() {
			 null_EventArray *nullEventArray = new null_EventArray;
//			 debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullEventArray, MACROS_FILE_AND_LINE ) );
			 return nullEventArray;
		 }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_EventArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< EventArray > createClone() const throw() { return pointing::Proxy< EventArray >::createUnique( this ); }

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
