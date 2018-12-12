#pragma once


#include "Automatic_pointer.hxx"
#include "jmsf/validating/Exception.hxx"


namespace jmsf {
namespace pointing {


template< class A_type >
class Automatic_pointer {

public:
	A_type &operator *() throw( validating::Exception );
	const A_type &operator *() const throw( validating::Exception );
	A_type *operator->()throw( validating::Exception );
	const A_type *operator->() const throw( validating::Exception );
	A_type *get() throw();
	const A_type *get() const throw();
	A_type *release() const throw();
	void reset( A_type *pointer = nullptr ) throw();
	void set( A_type *pointer = nullptr ) throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void initialize() throw();
	bool is_initialized() const throw();

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Automatic_pointer() throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	explicit Automatic_pointer() throw();
	explicit Automatic_pointer( A_type *pointer ) throw();

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Automatic_pointer( const Automatic_pointer &other ) throw();
	Automatic_pointer &operator =( const Automatic_pointer &other ) throw();

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:
	mutable A_type *_pointer;
	int _first;
	int _second;
	int _third;
	int _fifth;
	int _sixth;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace pointing
} // namespace jmsf
