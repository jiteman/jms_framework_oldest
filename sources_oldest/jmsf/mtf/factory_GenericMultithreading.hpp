#pragma once

#include "jmsf/Singleton.hpp"

#include "SynchronizedQueue.hxx"

namespace jmsf {
namespace mtf {

template< class A_type >
class factory_GenericMultithreading :
	public Singleton< factory_GenericMultithreading< A_type > >
{

public:
	virtual Proxy< SynchronizedQueue< A_type > > createSynchronizedQueue() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected: friend DeleterForPointer< factory_GenericMultithreading >;
	~factory_GenericMultithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend Singleton< factory_GenericMultithreading >;
	static factory_GenericMultithreading *createInstance() throw();

protected:
	factory_GenericMultithreading() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	factory_GenericMultithreading( const factory_GenericMultithreading &other ) throw();
	const factory_GenericMultithreading &operator =( const factory_GenericMultithreading &other ) throw( Exception );

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};

} // namespace mtf
} // namespace jmsf


#include "realizations/realization_factory_GenericMultithreading.hpp"
#include "jmsf/Should.h"

namespace jmsf {
namespace mtf {

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
template< class A_type >
factory_GenericMultithreading< A_type >::~factory_GenericMultithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// static
template< class A_type >
factory_GenericMultithreading< A_type > *factory_GenericMultithreading< A_type >::createInstance() throw() {
	return new realizations::realization_factory_GenericMultithreading< A_type >;
}

template< class A_type >
factory_GenericMultithreading< A_type >::factory_GenericMultithreading() throw()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
template< class A_type >
factory_GenericMultithreading< A_type >::factory_GenericMultithreading( const factory_GenericMultithreading< A_type > & ) throw() // other
{}

template< class A_type >
const factory_GenericMultithreading< A_type > &factory_GenericMultithreading< A_type >::operator =( const factory_GenericMultithreading< A_type > &other ) throw( Exception ) {
	if ( this == &other ) return *this;

	// copy
	Should::neverViolateCopyingProhibition( "factory_GenericMultithreading< A_type >::operator =()" );
	return *this;
}

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

} // namespace mtf
} // namespace jmsf
