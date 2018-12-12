#pragma once


#include "realization_ContainerArray.hxx"

#include "../Container.hpp"
#include "jmsf/patterning/mixing/mixin_Object.h"

#include "realization_factory_Container.hxx"


namespace jmsf {
namespace containing {
namespace realizing {


template< class A_type >
class realization_ContainerArray :
	public Container< A_type >,
	public ::jmsf::patterning::mixing::mixin_Object
{

public: // common getters
	// virtuals Container
	typing::Boolean isEmpty() const throw();
	typing::Boolean isNotEmpty() const throw();
	typing::Natural getQuantityOfElements() const throw();
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	// virtuals Container
	void appendToBegin( const A_type &object ) throw();
	void appendToEnd( const A_type &object ) throw();
	//~virtuals Container

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	// virtuals Container
	pointing::Proxy< Iterator< A_type > > createIteratorAtBegin() throw();
	pointing::Proxy< Iterator< A_type > > createIteratorAtEnd() throw();
	pointing::Proxy< Iterator< A_type > > createIteratorAt( typing::Natural index ) throw( validating::Exception );

	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtBegin() throw();
	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAtEnd() throw();
	pointing::Proxy< ConstantIterator< A_type > > createConstantIteratorAt( typing::Natural index ) throw( validating::Exception );
	//~virtuals Container

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
private:
	// virtual
	~realization_ContainerArray() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private: friend realization_factory_Container< A_type >;
	realization_ContainerArray() throw( jmsf::validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	// virtual
	::jmsf::pointing::Proxy< Container< A_type > > createClone() const throw();

private:
	realization_ContainerArray( const realization_ContainerArray &other ) throw();
	const realization_ContainerArray &operator =( const realization_ContainerArray &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace realizing
} // namespace containing
} // namespace jmsf
