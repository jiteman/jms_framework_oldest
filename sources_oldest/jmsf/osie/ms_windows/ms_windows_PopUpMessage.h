#pragma once

#include "../PopUpMessage.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Proxies.hpp"

#include "jmsf/Exception.hxx"
#include "ms_windows_UtilityControl.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {

class ms_windows_PopUpMessage :
	public PopUpMessage,
	public mixins::mixin_Object
{

public:
	// virtuals PopUpMessage
	void showOk( const ConstantProxy< TextString > &message ) const throw();
	const Boolean showOkCancel( const ConstantProxy< TextString > &message ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_PopUpMessage() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_UtilityControl;
	ms_windows_PopUpMessage() throw();
	ms_windows_PopUpMessage( const ConstantProxy< TextString > &caption ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< PopUpMessage > createClone() const throw();

private:
	ms_windows_PopUpMessage( const ms_windows_PopUpMessage &other ) throw();
	const ms_windows_PopUpMessage &operator =( const ms_windows_PopUpMessage &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const ConstantProxy< TextString > _caption;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
