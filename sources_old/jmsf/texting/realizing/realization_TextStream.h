#pragma once


#include "../TextStream.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/typing/Natural.h"

#include "jmsf/memorying/Constructor.hxx"


namespace jmsf {
namespace texting {
namespace realizations {
	namespace hiddens {
		class hidden_realization_TextStream;
	}

class realization_factory_TextObject;


class realization_TextStream :
	public TextStream,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals
	pointing::Proxy< TextStream > put( const pointing::ConstantProxy< TextString > &textString ) throw();
	pointing::Proxy< TextStream > putInteger( typing::Integer value ) throw();
	pointing::Proxy< TextStream > putInteger( typing::LongInteger value ) throw();
	pointing::Proxy< TextStream > putNatural( typing::Natural value ) throw();
	pointing::Proxy< TextStream > putNatural( typing::LongNatural value ) throw();
	pointing::Proxy< TextStream > putReal( const typing::ShortReal &value ) throw();
	pointing::Proxy< TextStream > putReal( const typing::Real &value ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const pointing::ConstantProxy< TextString > createTextString( memorying::Allocator &anAllocator ) const throw();
	pointing::Proxy< TextStream > setDecimalBase() throw();
	pointing::Proxy< TextStream > setHexadecimalBase() throw();
	pointing::Proxy< TextStream > setWidth( typing::Natural width ) throw();
	pointing::Proxy< TextStream > setFill( const pointing::ConstantProxy< TextString > &fill ) throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_TextStream() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< TextStream, realization_TextStream >;
	realization_TextStream() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual
	pointing::Proxy< TextStream > createClone( memorying::Allocator &anAllocator ) const throw();

private:
	realization_TextStream( const realization_TextStream &other ) throw();
	const realization_TextStream &operator =( const realization_TextStream &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::ShortestNatural _base;
	typing::Natural _width;
	typing::internals::platform_char _fill;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	hiddens::hidden_realization_TextStream *_hidden_realization_TextStream;

};


} // namespace realizations
} // namespace texting
} // namespace jmsf
