#pragma once


#include "realization_factory_Container.hxx"

#include "../factory_Container.hpp"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_factory_Container :
	public factory_Container< A_type >
{

public:
	// virtuals Container
	::jmsf::pointing::Proxy< Container< A_type > > createArray() const throw();
	::jmsf::pointing::Proxy< Container< A_type > > createDeque() const throw();
	::jmsf::pointing::Proxy< Container< A_type > > createList() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_Container< A_type >;
	realization_factory_Container() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_Container( const realization_factory_Container &other ) throw();
	const realization_factory_Container &operator =( const realization_factory_Container &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
