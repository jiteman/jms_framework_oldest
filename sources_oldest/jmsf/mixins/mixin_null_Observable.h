#pragma once

#include "../Observable.h"


#include "../jmsf.h"


namespace jmsf {
namespace mixins {


class JMSF_DLL_INTERFACE mixin_null_Observable :
	public virtual Observable
{

public:
	// virtuals Observable
	void attach( const Pointer< Observer > &observer ) throw();
	void detach( const Pointer< Observer > &observer ) throw();
	void notify() throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~mixin_null_Observable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Observable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_null_Observable( const mixin_null_Observable &other ) throw();
	const mixin_null_Observable &operator =( const mixin_null_Observable &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
