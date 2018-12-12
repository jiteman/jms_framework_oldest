#pragma once


#include "../TextString.h"

#include "../mixins/mixin_Object.h"

#include "../types.h"


namespace jmsf {
namespace realizations {
	namespace hiddens {
		class hidden_realization_TextString;
	}

class realization_factory_TextObject;


class realization_TextString :
	public TextString,
	public mixins::mixin_Object
{

public:
	// virtuals
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const char_type *getCtext() const throw();
	Boolean isEqual( const ConstantProxy< TextString > &other ) const throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_TextString() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class realization_factory_TextObject;
	realization_TextString( const char_type *c_text ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	const ConstantProxy< TextString > createClone() const throw();

private:
	realization_TextString( const realization_TextString &other ) throw();
	const realization_TextString &operator =( const realization_TextString &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

private: friend class realization_TextStream;
	hiddens::hidden_realization_TextString *_hidden_realizationementation_TextString;

};


} // namespace
}
