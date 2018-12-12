#pragma once


#include "jmsf/osie/UtilityControl.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/validating/Exception.hxx"
#include "../factory_OperatingSystem.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_UtilityControl :
	public UtilityControl,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals UtilityControl
	pointing::Proxy< Stopwatch > createStopwatch() const throw();
	pointing::Proxy< PopUpMessage > createPopUpMessage() const throw();
	pointing::Proxy< PopUpMessage > createPopUpMessage( const pointing::ConstantProxy< texting::TextString > &caption ) const throw();
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
	pointing::Proxy< UtilityControl > createClone() const throw();

private:
	ms_windows_UtilityControl( const ms_windows_UtilityControl &other ) throw();
	const ms_windows_UtilityControl &operator =( const ms_windows_UtilityControl &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
