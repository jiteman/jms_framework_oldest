#pragma once


#include "../TextString.h"

#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/typing/Boolean.hxx"
#include "jmsf/memorying/Constructor.hxx"

#include "jmsf/typing/internals/internal_types.h"


namespace jmsf {
namespace texting {
namespace realizations {
	namespace hiddens {
		class hidden_realization_TextString;
	}

class realization_factory_TextObject;


class realization_TextString :
	public TextString,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals
	
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	// virtuals
	const typing::internals::platform_char *getCtext() const throw();
	typing::Boolean isEqual( const pointing::ConstantProxy< TextString > &other ) const throw();
	//~virtuals

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_TextString() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend memorying::Constructor< TextString, realization_TextString >;
	realization_TextString( const typing::internals::platform_char *c_text ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	const pointing::ConstantProxy< TextString > createClone() const throw();

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


} // namespace realizations
} // namespace texting
} // namespace jmsf
