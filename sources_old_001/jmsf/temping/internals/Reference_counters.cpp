#include "Reference_counters.h"


#include "jmsf/typeing/Naturals.hin"
#include "jmsf/typeing/Boolean.h"
#include "jmsf/validating/Should.h"


namespace jmsf {
namespace temping {
namespace internals {


Reference_counters::~Reference_counters() {
	jmsf_Should_always_be( are_nill() );
}

Reference_counters::Reference_counters() noexcept
{}

typeing::Boolean Reference_counters::is_strong_nill() const noexcept {
	return _strong.is_nill();
}

typeing::Boolean Reference_counters::is_weak_nill() const noexcept {
	return _weak.is_nill();
}

typeing::Boolean Reference_counters::are_nill() const noexcept {
	return is_strong_nill() && is_weak_nill();
}

typeing::Memory_natural Reference_counters::get_connectivity() const noexcept {
	return _strong; // + _weak;
}

void Reference_counters::increase_strong() noexcept {
	++_strong;
}

void Reference_counters::decrease_strong() noexcept {
	--_strong;
}

void Reference_counters::increase_weak() noexcept {
	++_weak;
}

void Reference_counters::decrease_weak() noexcept {
	--_weak;
}


} // namespace internals
} // namespace temping
} // namespace jmsf
