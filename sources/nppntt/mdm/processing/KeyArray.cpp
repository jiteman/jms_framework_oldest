#include "KeyArray.h"
#include "../externals/data/ed_Key.h"
#include "jmsf/mtf/mixins/mixin_null_Lockable.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/osie/Event.h"
#include "jmsf/Container.hpp"
#include "jmsf/Singleton.hpp"
#include "jmsf/Proxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace processing {

class null_KeyArray :
	public KeyArray,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_KeyArray >
{

public:
	// virtuals KeyArray
	const ::jmsf::ConstantProxy< externals::data::ed_Key > &tryToAppendKeyAndGetNewOrExistingKey( const ::jmsf::ConstantProxy< externals::data::ed_Key > & ) throw( ::jmsf::Exception ) { // newKey
		return _keyCrtr;
	}

	void append( const ::jmsf::ConstantProxy< externals::data::ed_Key > & ) throw( ::jmsf::Exception ) {} // key

	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > getLastAmountOfKeys( ::jmsf::natural_size  ) const throw( ::jmsf::Exception ) { // quantity
		return ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > >();
	}

	::jmsf::Proxy< ::jmsf::osie::Event > &takeIsNewKeyAvailableEvent() throw() {
		return _eventRtr;
	}

	const ::jmsf::ConstantProxy< ::jmsf::osie::Event > &getIsNewKeyAvailableEvent() const throw() {
		return _eventCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_KeyArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_KeyArray >;
	static null_KeyArray *createInstance() throw() {
		return new null_KeyArray;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_KeyArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< KeyArray > createClone() const throw() {
		return ::jmsf::Proxy< KeyArray >::createUnique( this );
	}

private:
	null_KeyArray( const null_KeyArray & ) throw() {} // other
	
	const null_KeyArray &operator =( const null_KeyArray &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_KeyArray::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< externals::data::ed_Key > _keyCrtr;
	::jmsf::Proxy< ::jmsf::osie::Event > _eventRtr;
	::jmsf::ConstantProxy< ::jmsf::osie::Event > _eventCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_KeyArray :
	public KeyArray,
	public ::jmsf::mtf::mixins::mixin_null_Lockable,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_KeyArray >
{

public:
	// virtuals KeyArray
	const ::jmsf::ConstantProxy< externals::data::ed_Key > &tryToAppendKeyAndGetNewOrExistingKey( const ::jmsf::ConstantProxy< externals::data::ed_Key > & ) throw( ::jmsf::Exception ) { // newKey
		return _keyCrtr;
	}

	void append( const ::jmsf::ConstantProxy< externals::data::ed_Key > & ) throw( ::jmsf::Exception ) {} // key

	const ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > > getLastAmountOfKeys( ::jmsf::natural_size  ) const throw( ::jmsf::Exception ) { // quantity
		return ::jmsf::ConstantProxy< ::jmsf::Container< ::jmsf::ConstantProxy< externals::data::ed_Key > > >();
	}

	::jmsf::Proxy< ::jmsf::osie::Event > &takeIsNewKeyAvailableEvent() throw() {
		return _eventRtr;
	}

	const ::jmsf::ConstantProxy< ::jmsf::osie::Event > &getIsNewKeyAvailableEvent() const throw() {
		return _eventCrtr;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_KeyArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_KeyArray >;
	static exception_KeyArray *createInstance() throw() {
		return new exception_KeyArray;
	}

private:
	exception_KeyArray() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< KeyArray > createClone() const throw() {
		return ::jmsf::Proxy< KeyArray >::createUnique( this );
	}

private:
	exception_KeyArray( const exception_KeyArray & ) throw() {} // other

	const exception_KeyArray &operator =( const exception_KeyArray &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_KeyArray::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::ConstantProxy< externals::data::ed_Key > _keyCrtr;
	::jmsf::Proxy< ::jmsf::osie::Event > _eventRtr;
	::jmsf::ConstantProxy< ::jmsf::osie::Event > _eventCrtr;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
KeyArray *KeyArray::getNull() throw() {
	return null_KeyArray::instance();
}

// static
KeyArray *KeyArray::getException() throw() {
	return exception_KeyArray::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace processing
} // namespace mdm
} // namespace nppntt
