#pragma once

#include "jmsf/osie/UtilityControl.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Exception.hxx"
#include "../factory_OperatingSystem.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {

class ms_windows_UtilityControl :
	public UtilityControl,
	public mixins::mixin_Object
{

public:
	// virtuals UtilityControl
	Proxy< Stopwatch > createStopwatch() const throw();
	Proxy< PopUpMessage > createPopUpMessage() const throw();
	Proxy< PopUpMessage > createPopUpMessage( const ConstantProxy< TextString > &caption ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_UtilityControl() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_OperatingSystem;
	ms_windows_UtilityControl() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< UtilityControl > createClone() const throw();

private:
	ms_windows_UtilityControl( const ms_windows_UtilityControl &other ) throw();
	const ms_windows_UtilityControl &operator =( const ms_windows_UtilityControl &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
