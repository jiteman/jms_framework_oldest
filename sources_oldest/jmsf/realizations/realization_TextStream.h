#pragma once

#include "../TextStream.h"

#include "../mixins/mixin_Object.h"

#include "../Proxy.hpp"


namespace jmsf {
namespace realizations {
	namespace hiddens {
		class hidden_realization_TextStream;
	}

class realization_factory_TextObject;


class realization_TextStream :
	public TextStream,
	public mixins::mixin_Object
{

public:
	// virtuals
	Proxy< TextStream > put( const ConstantProxy< TextString > &textString ) throw();
	Proxy< TextStream > putInteger( integer_big value ) throw();
	Proxy< TextStream > putNatural( natural_big value ) throw();
	Proxy< TextStream > putReal( const Real &value ) throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const ConstantProxy< TextString > createTextString() const throw();
	Proxy< TextStream > setDecimalBase() throw();
	Proxy< TextStream > setHexadecimalBase() throw();
	Proxy< TextStream > setWidth( natural_size width ) throw();
	Proxy< TextStream > setFill( const ConstantProxy< TextString > &fill ) throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_TextStream() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class realization_factory_TextObject;
	realization_TextStream() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtual
	Proxy< TextStream > createClone() const throw();

private:
	realization_TextStream( const realization_TextStream &other ) throw();
	const realization_TextStream &operator =( const realization_TextStream &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	natural _base;
	natural_size _width;
	char_type _fill;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	hiddens::hidden_realization_TextStream *_hidden_realization_TextStream;

};


} // namespace
}
