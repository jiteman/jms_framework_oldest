#include "TextString.h"


#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/Singleton.inl"

#include "jmsf/pointing/ConstantProxy.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/pointing/Reference.inl"

#include "jmsf/memorying/Constructor.inl"

#include "jmsf/typing/Boolean.h"

#include "jmsf/typing/internals/internal_types.h"
//#include "jmsf/debugging/ObjectCreationLogging.h"


namespace jmsf {
namespace texting {


class null_TextString :
	public TextString,
	public ::jmsf::patterning::mixing::mixin_null_Object,
	public ::jmsf::patterning::Singleton< TextString >
{

public:
	// virtuals TextString
	const typing::internals::platform_char *getCtext() const throw() { return ""; }
	typing::Boolean isEqual( const pointing::ConstantProxy< TextString > & ) const throw() { return typing::False; } // other
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_TextString() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< TextString >;
	static memorying::ObjectMemoryPointer< TextString > singletonCreateInstance( memorying::Allocator &objectAllocator ) throw() {
// 		memorying::ObjectMemoryPointer< null_TextString > nullTextString = memorying::Construct< null_TextString >( objectAllocator );
// 		memorying::ObjectMemoryPointer< TextString > textString( nullTextString.takeMemory(), nullTextString.takeAllocator(), nullTextString.getAlignment() );
		return memorying::Constructor< TextString, null_TextString >::construct( objectAllocator );
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< TextString, null_TextString >;
	null_TextString() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	const pointing::ConstantProxy< TextString > createClone( memorying::Allocator & ) const throw() {
		return pointing::ConstantProxy< TextString >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextString >( const_cast< TextString * >( static_cast< const TextString * >( this ) ), nullptr, typing::AlignmentOf< null_TextString >() ) );
	}

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
const pointing::Reference< TextString > &TextString::getNull() throw() {
	return null_TextString::instance();
}

// static
void TextString::createNull( memorying::Allocator &anAllocator ) throw( validating::Exception ) {
	null_TextString::createInstance< null_TextString >( anAllocator );
}

// static
void TextString::destroyNull() throw( validating::Exception ) {
	null_TextString::destroyInstance();
}


// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf
