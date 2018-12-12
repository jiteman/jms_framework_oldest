#pragma once


#include "jmsf/typeing/Naturals.hpp"

#include "jmsf/typeing/Boolean.hxx"
#include "jmsf/validating/Exception.hxx"

#include "jmsf/encodebuba/common_suppress_compilation_warnings.h"
#include "jmsf/encodebuba/common_standard_support.h"

#include "jmsf/jmsf.h"


namespace jmsf {
namespace pointing {
namespace internalling {


class JMSF_SHARED_INTERFACE Reference_counters {

public:
	~Reference_counters(); // it is bad, but this exception means a failure, not an error.
	Reference_counters() noexcept;

	typeing::Boolean is_strong_nill() const noexcept;
	typeing::Boolean is_weak_nill() const noexcept;
	typeing::Boolean are_nill() const noexcept;

	typeing::Memory_natural get_connectivity() const noexcept;

	void increase_strong() noexcept;
	void decrease_strong() noexcept;
	void increase_weak() noexcept;
	void decrease_weak() noexcept;

private:
	typeing::Memory_natural _strong;
	typeing::Memory_natural _weak;

};


} // namespace internalling
} // namespace pointing
} // namespace jmsf
