#pragma once


#include "jmsf/osie/hiddens/hidden_Thread.h"
#include "../ms_windows_include.h"

#include "jmsf/pointing/Pointer.hxx"
#include "jmsf/memorying/Destructor.hxx"


namespace jmsf {
namespace osie {
namespace ms_windows {
namespace hiddens {


class ms_windows_hidden_Thread :
	public osie::hiddens::hidden_Thread
{

public:
	// virtuals hidden_Thread
	void setPriority( typing::Natural priorityLevel ) throw( validating::Exception );
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:	

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private: friend memorying::Destructor< osie::hiddens::hidden_Thread >;
	// virtual
	~ms_windows_hidden_Thread() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	static pointing::Pointer< osie::hiddens::hidden_Thread > create( HANDLE threadHandle, DWORD threadId ) throw();

private:
	ms_windows_hidden_Thread( HANDLE threadHandle, DWORD threadId ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	pointing::Pointer< osie::hiddens::hidden_Thread > createClone() const throw();

private:
	ms_windows_hidden_Thread( const ms_windows_hidden_Thread &other ) throw();
	const ms_windows_hidden_Thread &operator =( const ms_windows_hidden_Thread &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	int getPriorityLevelValue( typing::Natural priorityLevel ) throw( validating::Exception );
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	HANDLE _ms_windows_hidden_ThreadHandle;
	const DWORD _ms_windows_hidden_ThreadId;

};


} // namespace hiddens
} // namespace ms_windows
} // namespace osie
} // namespace jmsf
