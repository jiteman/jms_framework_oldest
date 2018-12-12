#pragma once

#include "../factory_Multithreading.h"


namespace jmsf {
namespace mtf {
namespace realizations {


class realization_factory_Multithreading :
	public factory_Multithreading
{

public:
	// virtuals factory_Multithreading
	Proxy< Thread > createThread( natural_size priorityLevel, Boolean isAutostopEnable ) const throw();
	Proxy< Thread > createContinuousThread() const throw();
	Proxy< Thread > createContinuousThread( natural_size priorityLevel ) const throw();
	Proxy< Thread > createAutostopableThread() const throw();
	Proxy< Thread > createAutostopableThread( natural_size priorityLevel ) const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_Multithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend class factory_Multithreading;
	realization_factory_Multithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_Multithreading( const realization_factory_Multithreading &other ) throw();
	const realization_factory_Multithreading &operator =( const realization_factory_Multithreading &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace
}
}
