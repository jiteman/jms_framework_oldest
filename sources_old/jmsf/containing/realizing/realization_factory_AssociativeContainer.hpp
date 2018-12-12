#pragma once


#include "realization_factory_AssociativeContainer.hxx"

#include "../factory_AssociativeContainer.hpp"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_key, class A_type >
class realization_factory_AssociativeContainer :
	public factory_AssociativeContainer< A_key, A_type >
{

public:
	// virtuals Container
	::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createSet() const throw();
	::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createMultiSet() const throw();
	::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createMap() const throw();
	::jmsf::pointing::Proxy< AssociativeContainer< A_key, A_type > > createMultiMap() const throw();
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_factory_AssociativeContainer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend factory_AssociativeContainer< A_key, A_type >;
	realization_factory_AssociativeContainer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:
	realization_factory_AssociativeContainer( const realization_factory_AssociativeContainer &other ) throw();
	const realization_factory_AssociativeContainer &operator =( const realization_factory_AssociativeContainer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
