#pragma once


#include "../PopUpMessage.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/pointing/ConstantProxy.hpp"

#include "jmsf/pointing/Proxy.hxx"
#include "jmsf/validating/Exception.hxx"
#include "ms_windows_UtilityControl.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_PopUpMessage :
	public PopUpMessage,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals PopUpMessage
	void showOk( const pointing::ConstantProxy< texting::TextString > &message ) const throw();
	const typing::Boolean showOkCancel( const pointing::ConstantProxy< texting::TextString > &message ) const throw();
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
	ms_windows_PopUpMessage( const pointing::ConstantProxy< texting::TextString > &caption ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< PopUpMessage > createClone() const throw();

private:
	ms_windows_PopUpMessage( const ms_windows_PopUpMessage &other ) throw();
	const ms_windows_PopUpMessage &operator =( const ms_windows_PopUpMessage &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	const pointing::ConstantProxy< texting::TextString > _caption;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
