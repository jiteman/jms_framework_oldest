#pragma once

#include "../Singleton.hpp"

#include "Thread.hxx"

#include "../jmsf.h"

namespace jmsf {
namespace mtf {

class JMSF_DLL_INTERFACE factory_Multithreading :
	public Singleton< factory_Multithreading >
{

public:
	virtual Proxy< Thread > createThread( natural_size priorityLevel, Boolean isAutostopEnable ) const throw() = 0;
	virtual Proxy< Thread > createContinuousThread() const throw() = 0;
	virtual Proxy< Thread > createContinuousThread( natural_size priorityLevel ) const throw() = 0;
	virtual Proxy< Thread > createAutostopableThread() const throw() = 0;
	virtual Proxy< Thread > createAutostopableThread( natural_size priorityLevel ) const throw() = 0;	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_Multithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< factory_Multithreading >;
	static factory_Multithreading *createInstance() throw();

protected:
	factory_Multithreading() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_Multithreading( const factory_Multithreading &other ) throw();
	const factory_Multithreading &operator =( const factory_Multithreading &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace
}
