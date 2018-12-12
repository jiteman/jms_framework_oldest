#pragma once


#include "factory_Container.hxx"

#include "jmsf/patterning/Singleton.hpp"
#include "Container.hxx"
#include "jmsf/pointing/Proxy.hxx"


namespace jmsf {
namespace containing {


template< class A_type >
class factory_Container :
	public ::jmsf::patterning::Singleton< factory_Container< A_type > >
{

public:
	virtual ::jmsf::pointing::Proxy< Container< A_type > > createArray() const throw() = 0;
	virtual ::jmsf::pointing::Proxy< Container< A_type > > createDeque() const throw() = 0;
	virtual ::jmsf::pointing::Proxy< Container< A_type > > createList() const throw() = 0;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	// virtual
	~factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend ::jmsf::patterning::Singleton< factory_Container< A_type > >;
	static factory_Container *createInstance() throw();

protected:
	factory_Container() throw();	

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	factory_Container( const factory_Container &other ) throw();
	const factory_Container &operator =( const factory_Container &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace jmsf
