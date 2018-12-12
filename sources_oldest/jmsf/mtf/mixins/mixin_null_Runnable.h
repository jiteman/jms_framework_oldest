#pragma once

#include "../Runnable.h"

#include "jmsf/Exception.hxx"

#include "../../jmsf.h"

namespace jmsf {
namespace mtf {
namespace mixins {

class JMSF_DLL_INTERFACE mixin_null_Runnable :
	public virtual Runnable
{

public:
	// virtuals Runnable
	void run() throw( Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~mixin_null_Runnable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	mixin_null_Runnable() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	mixin_null_Runnable( const mixin_null_Runnable &other ) throw( Exception );
	const mixin_null_Runnable &operator =( const mixin_null_Runnable &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mixins
} // namespace mtf
} // namespace jmsf
