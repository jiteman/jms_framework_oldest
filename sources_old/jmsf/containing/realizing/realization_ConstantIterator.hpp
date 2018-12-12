#pragma once


#include "realization_ConstantIterator.hxx"

#include "../ConstantIterator.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_ConstantIterator.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_ConstantIterator :
	public ConstantIterator< A_type >,
	public ::jmsf::patterning::mixing::mixin_Object
{

public:
	// virtuals ConstantIterator< A_type >
	//~virtuals

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ConstantIterator() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_ConstantIterator< A_type >;
	realization_ConstantIterator() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< ConstantIterator< A_type > > createClone() const throw();

private:
	realization_ConstantIterator( const realization_ConstantIterator &other ) throw();
	const realization_ConstantIterator &operator =( const realization_ConstantIterator &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
