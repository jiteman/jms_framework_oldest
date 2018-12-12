#include "TextStream.h"
#include "mixins/mixin_null_Object.h"
#include "Singleton.hpp"
#include "TextString.h"
#include "Proxies.hpp"

namespace jmsf {

class null_TextStream :
	public TextStream,
	public mixins::mixin_null_Object,
	public Singleton< null_TextStream >
{

public:
	// virtuals
	Proxy< TextStream > put( const ConstantProxy< TextString > & ) throw() { // textString
		return Proxy< TextStream >::createNonlinkedFor( this );
	}

	Proxy< TextStream > putInteger( integer_big  ) throw() { // value
		return Proxy< TextStream >::createNonlinkedFor( this );
	}

	Proxy< TextStream > putNatural( natural_big  ) throw() { // value
		return Proxy< TextStream >::createNonlinkedFor( this );
	}

	Proxy< TextStream > putReal( const Real &  ) throw() { // value
		return Proxy< TextStream >::createNonlinkedFor( this );
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const ConstantProxy< TextString > createTextString() const throw() {
		return ConstantProxy< TextString >();
	}

	Proxy< TextStream > setDecimalBase() throw() {
		return Proxy< TextStream >::createNonlinkedFor( this );
	}

	Proxy< TextStream > setHexadecimalBase() throw() {
		return Proxy< TextStream >::createNonlinkedFor( this );
	}

	Proxy< TextStream > setWidth( natural_size  ) throw() { // width
		return Proxy< TextStream >::createNonlinkedFor( this );
	}

	Proxy< TextStream > setFill( const ConstantProxy< TextString > & ) throw() { // fill
		return Proxy< TextStream >::createNonlinkedFor( this );
	}
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_TextStream() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class Singleton< null_TextStream >;
	static null_TextStream *createInstance() throw() {
		return new null_TextStream;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	null_TextStream() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< TextStream > null_TextStream::createClone() const throw() {
		return Proxy< TextStream >::createUnique( this );
	}

private:
	null_TextStream( const null_TextStream & ) throw() {}

	const null_TextStream &operator =( const null_TextStream &other ) throw() {
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
TextStream *TextStream::getNull() throw() {
	return null_TextStream::instance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace
