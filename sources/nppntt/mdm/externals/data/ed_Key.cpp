#include "ed_Key.h"
#include "../others/abstractKey.h"
#include "jmsf/mixins/mixin_null_Object.h"
#include "jmsf/mixins/mixin_exception_Object.h"
#include "jmsf/Singleton.hpp"
#include "jmsf/PointersAndProxies.hpp"
#include "jmsf/Should.h"

namespace nppntt {
namespace mdm {
namespace externals {
namespace data {

class null_ed_Key :
	public ed_Key,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_ed_Key >
{

public:
	// virtuals ed_Key
	::jmsf::Pointer< KeyData > &takeData() throw() {
		return _keyDataReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< KeyData > &getData() const throw() {
		return _keyDataConstantReferenceToReturn;
	}

	const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw() { // voiceFile
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // serviceFile
		return ::jmsf::False;
	}

	::jmsf::natural_size getIdentifier() const throw() {
		return ::jmsf::natural_size( 0 );
	}

	const ::jmsf::Boolean isEqual( const ::jmsf::ConstantProxy< ed_Key > & ) const throw() { // key
		return ::jmsf::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_ed_Key() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_ed_Key >;
	static null_ed_Key *createInstance() throw() {
		return new null_ed_Key;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_ed_Key() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Key > createClone() const throw() {
		return ::jmsf::Proxy< ed_Key >::createUnique( this );
	}

private:
	null_ed_Key( const null_ed_Key & ) throw() {} // other
	
	const null_ed_Key &operator =( const null_ed_Key &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "null_ed_Key::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< KeyData > _keyDataReferenceToReturn;
	::jmsf::ConstantPointer< KeyData > _keyDataConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


class exception_ed_Key :
	public ed_Key,
	public ::jmsf::mixins::mixin_exception_Object,
	public ::jmsf::Singleton< exception_ed_Key > {

public:
	// virtuals ed_Key
	::jmsf::Pointer< KeyData > &takeData() throw() {
		return _keyDataReferenceToReturn;
	}

	const ::jmsf::ConstantPointer< KeyData > &getData() const throw() {
		return _keyDataConstantReferenceToReturn;
	}

	const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_VoiceFile > & ) const throw() { // voiceFile
		return ::jmsf::False;
	}

	const ::jmsf::Boolean isFileSuitable( const ::jmsf::ConstantProxy< ed_ServiceFile > & ) const throw() { // serviceFile
		return ::jmsf::False;
	}

	::jmsf::natural_size getIdentifier() const throw() {
		return ::jmsf::natural_size( 0 );
	}

	const ::jmsf::Boolean isEqual( const ::jmsf::ConstantProxy< ed_Key > & ) const throw() { // key
		return ::jmsf::False;
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~exception_ed_Key() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< exception_ed_Key >;
	static exception_ed_Key *createInstance() throw() {
		return new exception_ed_Key;
	}

private:
	exception_ed_Key() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::Proxy< ed_Key > createClone() const throw() {
		return ::jmsf::Proxy< ed_Key >::createUnique( this );
	}

private:
	exception_ed_Key( const exception_ed_Key & ) throw() {} // other

	const exception_ed_Key &operator =( const exception_ed_Key &other ) throw( ::jmsf::Exception ) {
		if ( this == &other ) return *this;

		// copy
		::jmsf::Should::neverViolateCopyingProhibition( "exception_ed_Key::operator =()" );
		return *this;
	}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	::jmsf::Pointer< KeyData > _keyDataReferenceToReturn;
	::jmsf::ConstantPointer< KeyData > _keyDataConstantReferenceToReturn;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
ed_Key *ed_Key::getNull() throw() {
	return null_ed_Key::instance();
}

// static
ed_Key *ed_Key::getException() throw() {
	return exception_ed_Key::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace data
} // namespace externals
} // namespace mdm
} // namespace nppntt
