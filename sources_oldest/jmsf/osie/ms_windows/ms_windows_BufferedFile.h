#pragma once

#include "../File.h"
#include "jmsf/mixins/mixin_Object.h"

#include "ms_windows_factory_OperatingSystem.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_BufferedFile :
	public File,
	public mixins::mixin_Object
{

public:
	// virtuals File
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_BufferedFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_factory_OperatingSystem;
	ms_windows_BufferedFile() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< File > createClone() const throw();

private:
	ms_windows_BufferedFile( const ms_windows_BufferedFile &other ) throw();
	const ms_windows_BufferedFile &operator =( const ms_windows_BufferedFile &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
