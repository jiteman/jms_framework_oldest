#pragma once

#include "../Observer.h"

#include "jmsf/Exception.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace mixins {

class JMSF_DLL_INTERFACE mixin_null_Observer :
	public virtual Observer
{

public:
	// virtuals Observer
	void update() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~mixin_null_Observer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Observer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_null_Observer( const mixin_null_Observer &other ) throw();
	const mixin_null_Observer &operator =( const mixin_null_Observer &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mixins
} // namespace jmsf
