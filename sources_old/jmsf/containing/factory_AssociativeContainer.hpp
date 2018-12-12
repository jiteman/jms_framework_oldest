#pragma once


#include "factory_AssociativeContainer.hxx"

#include "jmsf/patterning/Singleton.hpp"
#include "AssociativeContainer.hxx"
#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace containing {


template< class A_key, class A_type >
class factory_AssociativeContainer :
	public ::jmsf::patterning::Singleton< factory_AssociativeContainer< A_key, A_type > >
{

public:
	virtual ::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createSet() const throw() = 0;
	virtual ::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createMultiSet() const throw() = 0;
	virtual ::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createMap() const throw() = 0;
	virtual ::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createMultiMap() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< factory_AssociativeContainer< A_key, A_type > >;
	static factory_AssociativeContainer *createInstance() throw();

protected:
	factory_AssociativeContainer() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_AssociativeContainer( const factory_AssociativeContainer &other ) throw();
	const factory_AssociativeContainer &operator =( const factory_AssociativeContainer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace jmsf
