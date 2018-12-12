#pragma once

#include "../Observable.h"
#include "../Container.hpp"
#include "../Proxy.hpp"

#include "../Observer.hxx"

#include "../jmsf.h"


namespace jmsf {
namespace mixins {


class JMSF_DLL_INTERFACE mixin_Observable :
	public virtual Observable
{

public:
	// virtuals
	void attach( const Pointer< Observer > &observer ) throw();
	void detach( const Pointer< Observer > &observer ) throw();
	void notify() throw();	
	//~virtuals	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	// virtual
	~mixin_Observable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Observable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Observable( const mixin_Observable &other ) throw();
	const mixin_Observable &operator =( const mixin_Observable &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	Proxy< Container< Pointer< Observer > > > _observers;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
