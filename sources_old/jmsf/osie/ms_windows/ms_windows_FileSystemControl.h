#pragma once


#include "../FileSystemControl.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "jmsf/validating/Exception.hxx"
#include "../factory_OperatingSystem.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_FileSystemControl :
	public FileSystemControl,
	public patterning::mixing::mixin_Object
{

public:
	// virtuals FileSystemControl
	pointing::Proxy< File > createBufferedFileForInput();
	pointing::Proxy< File > createBufferedFileForOutput();
	pointing::Proxy< File > createBufferedFileForInputAndOutput();

	pointing::Proxy< File > createNonbufferedFileForInput();
	pointing::Proxy< File > createNonbufferedFileForOutput();
	pointing::Proxy< File > createNonbufferedFileForInputAndOutput();
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
	pointing::Proxy< FileSystemControl > createClone() const throw();

private:
	ms_windows_FileSystemControl( const ms_windows_FileSystemControl &other ) throw();
	const ms_windows_FileSystemControl &operator =( const ms_windows_FileSystemControl &other ) throw( validating::Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace ms_windows
} // namespace osie
} // namespace jmsf
