#pragma once


#include "../File.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/validating/Exception.hxx"
#include "ms_windows_factory_OperatingSystem.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_UnbufferedFile :
	public File,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals File
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_UnbufferedFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_factory_OperatingSystem;
	ms_windows_UnbufferedFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< File > createClone() const throw();

private:
	ms_windows_UnbufferedFile( const ms_windows_UnbufferedFile &other ) throw();
	const ms_windows_UnbufferedFile &operator =( const ms_windows_UnbufferedFile &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
