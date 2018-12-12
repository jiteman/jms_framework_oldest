#pragma once


#include "realization_Iterator.hxx"

#include "../Iterator.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_Iterator.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_Iterator :
	public Iterator< A_type >,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals Iterator< A_type >
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_Iterator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Iterator< A_type >;
	realization_Iterator() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Iterator< A_type > > createClone() const throw();

private:
	realization_Iterator( const realization_Iterator &other ) throw();
	const realization_Iterator &operator =( const realization_Iterator &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
