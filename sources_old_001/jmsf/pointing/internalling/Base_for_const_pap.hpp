#pragma once

#include "Base_for_const_pap.hxx"


#include "Base_for_canc_pap.hpp"


namespace jmsf {
namespace pointing {
namespace internalling {


template< class A_type >
class Base_for_const_pap :
	public Base_for_canc_cap< A_type >
{

private: // no non constant access methods for constant pointer/proxy
	typename A_type::the_type &operator *();
	typename A_type::the_type *operator ->();

public:
	const typename A_type::the_type &operator *() const;
	const typename A_type::the_type *operator ->() const;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
public:

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
protected:
	~Base_for_const_pap() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_const_pap() noexcept;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
protected:
	Base_for_const_pap( const Base_for_const_pap &another ) noexcept;
	const Base_for_const_pap &operator =( const Base_for_const_pap &another ) noexcept;

protected:
	Base_for_const_pap( Base_for_const_pap &&another ) noexcept;
	Base_for_const_pap &operator =( Base_for_const_pap &&another ) noexcept;

// # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
private:

};


} // namespace internalling
} // namespace pointing
} // namespace jmsf
