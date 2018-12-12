#pragma once

#include "../FileSystemControl.h"
#include "jmsf/mixins/mixin_Object.h"

#include "jmsf/Exception.hxx"
#include "../factory_OperatingSystem.hxx"

namespace jmsf {
namespace osie {
namespace ms_windows {

class ms_windows_FileSystemControl :
	public FileSystemControl,
	public mixins::mixin_Object
{

public:
	// virtuals FileSystemControl
	Proxy< File > createBufferedFileForInput();
	Proxy< File > createBufferedFileForOutput();
	Proxy< File > createBufferedFileForInputAndOutput();

	Proxy< File > createNonbufferedFileForInput();
	Proxy< File > createNonbufferedFileForOutput();
	Proxy< File > createNonbufferedFileForInputAndOutput();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~ms_windows_FileSystemControl() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_OperatingSystem;
	ms_windows_FileSystemControl() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	Proxy< FileSystemControl > createClone() const throw();

private:
	ms_windows_FileSystemControl( const ms_windows_FileSystemControl &other ) throw();
	const ms_windows_FileSystemControl &operator =( const ms_windows_FileSystemControl &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
