#pragma once


#include "jmsf/osie/File.h"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "ms_windows_include.h"

#include "ms_windows_FileSystemControl.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {


class ms_windows_File :
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
	~ms_windows_File() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ms_windows_FileSystemControl;
	ms_windows_File() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	pointing::Proxy< File > createClone() const throw();

private:
	ms_windows_File( const ms_windows_File &other ) throw();
	const ms_windows_File &operator =( const ms_windows_File &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	HANDLE _fileHandle;

};

} // namespace ms_windows
} // namespace osie
} // namespace jmsf
