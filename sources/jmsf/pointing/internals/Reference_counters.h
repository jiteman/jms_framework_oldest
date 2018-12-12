#pragma once


#include "jmsf/typing/Naturals.hpp"

#include "jmsf/typing/Boolean.hxx"
#include "jmsf/validating/Exception.hxx"

#include "jmsf/jmsf.h"

#include "jmsf/jmsf_language_support.h"


namespace jmsf {
namespace pointing {
namespace internals {


class JMSF_DLL_INTERFACE Reference_counters {

public:
	~Reference_counters(); // it is bad, but this exception means a failure, not an error.
	Reference_counters() noexept;	

	typing::Boolean is_strong_nill() const noexept;
	typing::Boolean is_weak_nill() const noexept;
	typing::Boolean are_nill() const noexept;

	typing::Memory_size get_connectivity() const noexept;

	void increase_strong() noexept;
	void decrease_strong() noexept;
	void increase_weak() noexept;
	void decrease_weak() noexept;

private:
	typing::Memory_size _strong;
	typing::Memory_size _weak;

};


} // namespace internals
} // namespace pointing
} // namespace jmsf
