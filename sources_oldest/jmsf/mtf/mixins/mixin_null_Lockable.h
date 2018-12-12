#pragma once

#include "../Lockable.h"

#include "jmsf/Proxies.hpp"

#include "jmsf/Exception.hxx"

#include "../../jmsf.h"

namespace jmsf {
namespace mtf {
namespace mixins {

class JMSF_DLL_INTERFACE mixin_null_Lockable :
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
	~mixin_null_Lockable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Lockable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_null_Lockable( const mixin_null_Lockable &other ) throw();
	const mixin_null_Lockable &operator =( const mixin_null_Lockable &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable Proxy< osie::Mutex > _mixin_null_LockableMutex;
	ConstantProxy< osie::Mutex > _mixin_null_LockableConstantMutex;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mixins
} // namespace mtf
} // namespace jmsf
