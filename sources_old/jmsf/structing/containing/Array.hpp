#pragma once


#include "Array.hxx"

#include "../traversing/ArrayTraverser.hxx"


namespace jmsf {
namespace sructing {
namespace containing {


template< class A_type >
class Array {

public: // common getters
	typing::Boolean isEmpty() const throw();
	typing::Boolean isNotEmpty() const throw();
	typing::Natural getQuantityOfElements() const throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // appending modifiers
	void appendToBegin( const A_type &object ) throw();
	void appendToEnd( const A_type &object ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public: // factories
	pointing::Pointer< traversing::ArrayTraverser< A_type > > createTraverserAtBegin() throw();
	pointing::Pointer< traversing::ArrayTraverser< A_type > > createIteratorAtEnd() throw();
	pointing::Pointer< traversing::ArrayTraverser< A_type > > createIteratorAt( typing::Natural index ) throw( validating::Exception );

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Array() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Array() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Array( const Array &other ) throw();
	const Array &operator =( const Array &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	typing::Asd _quantityOfElements;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace containing
} // namespace sructing
} // namespace jmsf
