#include "TextStream.h"

#include "jmsf/patterning/mixing/mixin_null_Object.h"
#include "jmsf/patterning/Singleton.hpp"

#include "TextString.h"
#include "jmsf/typing/Integer.h"
#include "jmsf/typing/LongInteger.h"
#include "jmsf/typing/Natural.h"
#include "jmsf/typing/LongNatural.h"

#include "jmsf/pointing/ConstantProxy.inl"
#include "jmsf/pointing/Proxy.inl"
#include "jmsf/memorying/Allocator.h"

#include "jmsf/memorying/Constructor.inl"


namespace jmsf {
namespace texting {


class null_TextStream :
	public TextStream,
	public patterning::mixing::mixin_null_Object,
	public patterning::Singleton< TextStream >
{

public:
	// virtuals
	pointing::Proxy< TextStream > put( const pointing::ConstantProxy< TextString > & ) throw() { // textString
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > putInteger( typing::Integer  ) throw() { // value
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > putInteger( typing::LongInteger  ) throw() { // value
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > putNatural( typing::Natural  ) throw() { // value
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > putNatural( typing::LongNatural  ) throw() { // value
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > putReal( const typing::ShortReal & ) throw() {
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > putReal( const typing::Real &  ) throw() { // value
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const pointing::ConstantProxy< TextString > createTextString( memorying::Allocator & ) const throw() {
		return pointing::ConstantProxy< TextString >();
	}

	pointing::Proxy< TextStream > setDecimalBase() throw() {
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > setHexadecimalBase() throw() {
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > setWidth( typing::Natural  ) throw() { // width
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}

	pointing::Proxy< TextStream > setFill( const pointing::ConstantProxy< TextString > & ) throw() { // fill
		return pointing::Proxy< TextStream >::createNonlinkedFor( memorying::ObjectMemoryPointer< TextStream >( this, nullptr, typing::AlignmentOf< null_TextStream >() ) );
	}
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~null_TextStream() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend patterning::Singleton< TextStream >;
	static memorying::ObjectMemoryPointer< TextStream > singletonCreateInstance( memorying::Allocator &objectAllocator ) throw() {
		return memorying::Constructor< TextStream, null_TextStream >::construct( objectAllocator );
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< TextStream, null_TextStream >;
	null_TextStream() throw() {}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< TextStream > null_TextStream::createClone( memorying::Allocator & ) const throw() { // anAllocator
		return pointing::Proxy< TextStream >::createUnique( memorying::ObjectMemoryPointer< TextStream >( const_cast< null_TextStream * >( this ), nullptr, typing::AlignmentOf< null_TextStream >() ) );
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
const pointing::Reference< TextStream > &TextStream::getNull() throw() {
	return null_TextStream::instance();
}

// static
void TextStream::createNull( memorying::Allocator &anAllocator ) throw( validating::Exception ) {
	null_TextStream::createInstance< null_TextStream >( anAllocator );
}

// static
void TextStream::destroyNull() throw( validating::Exception ) {
	null_TextStream::destroyInstance();
}

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


} // namespace texting
} // namespace jmsf
