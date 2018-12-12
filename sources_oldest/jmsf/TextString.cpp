#include "TextString.h"
#include "mixins/mixin_null_Object.h"
#include "Singleton.hpp"
#include "Proxies.hpp"
#include "jmsf/debugging/ObjectCreationLogging.h"

namespace jmsf {

class null_TextString :
	public TextString,
	public ::jmsf::mixins::mixin_null_Object,
	public ::jmsf::Singleton< null_TextString >
{

public:
	// virtuals TextString
	const char_type *getCtext() const throw() { return ""; }
	Boolean isEqual( const ConstantProxy< TextString > & ) const throw() { return False; } // other
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_TextString() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::Singleton< null_TextString >;
	static null_TextString *createInstance() throw() {
		null_TextString *nullTextString = new null_TextString;
//		debugging::static_ObjectCreationLogger::registerCreation( debugging::createMulInformationForUnobjectedCreation( nullTextString, MACROS_FILE_AND_LINE ) );
		return nullTextString;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_TextString() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	const ConstantProxy< TextString > createClone() const throw() { return ConstantProxy< TextString >::createUnique( this ); }

private:
	null_TextString( const null_TextString & ) throw() {}
	
	const null_TextString &operator =( const null_TextString &other ) throw() {
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
TextString *TextString::getNull() throw() {
	return null_TextString::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
