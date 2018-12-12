#pragma once


#include "Automatic_pointer.hxx"
#include "jmsf/validating/Exception.hxx"


namespace jmsf {
namespace temping {


template< class A_type >
class Automatic_pointer {

public:
	A_type &operator *() throw( validating::Exception );
	const A_type &operator *() const throw( validating::Exception );
	A_type *operator->()throw( validating::Exception );
	const A_type *operator->() const throw( validating::Exception );
	A_type *get() noexcept;
	const A_type *get() const noexcept;
	A_type *release() const noexcept;
	void reset( A_type *pointer = nullptr ) noexcept;
	void set( A_type *pointer = nullptr ) throw( validating::Exception );

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	void initialize() noexcept;
	bool is_initialized() const noexcept;

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
public:
	~Automatic_pointer() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	explicit Automatic_pointer() noexcept;
	explicit Automatic_pointer( A_type *pointer ) noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:
	Automatic_pointer( const Automatic_pointer &other ) noexcept;
	Automatic_pointer &operator =( const Automatic_pointer &other ) noexcept;

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


} // namespace temping
} // namespace jmsf
