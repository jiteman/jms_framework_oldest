#pragma once

#include "../Lockable.h"

#include "jmsf/Proxies.hpp"

#include "jmsf/Exception.hxx"

#include "../../jmsf.h"

namespace jmsf {
namespace mtf {
namespace mixins {

class JMSF_DLL_INTERFACE mixin_Lockable :
	public virtual Lockable
{

public:
	// virtuals Lockable
	Proxy< osie::Mutex > &takeMutex() const throw();
	const ConstantProxy< osie::Mutex > &getMutex() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~mixin_Lockable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_Lockable( Proxy< osie::Mutex > mutex ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_Lockable( const mixin_Lockable &other ) throw( Exception );
	const mixin_Lockable &operator =( const mixin_Lockable &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable Proxy< osie::Mutex > _mixin_Lockable_mutex;
	ConstantProxy< osie::Mutex > _mixin_Lockable_constantMutex;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mixins
} // namespace mtf
} // namespace jmsf
