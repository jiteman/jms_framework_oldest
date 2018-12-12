#include "Reference_counters.h"


#include "jmsf/validating/Should.h"
#include "jmsf/validating/File_and_line.h"
#include "jmsf/typing/Boolean.h"


namespace jmsf {
namespace pointing {
namespace internals {


Reference_counters::~Reference_counters() {
	validating::Should::always_be( are_nill(), FILE_AND_LINE );
}

Reference_counters::Reference_counters() noexept
{}

typing::Boolean Reference_counters::is_strong_nill() const noexept {
	return _strong.is_nill();
}

typing::Boolean Reference_counters::is_weak_nill() const noexept {
	return _weak.is_nill();
}

typing::Boolean Reference_counters::are_nill() const noexept {
	return is_strong_nill() && is_weak_nill();
}

typing::Memory_size Reference_counters::get_connectivity() const noexept {
	return _strong;// + _weak;
}

void Reference_counters::increase_strong() noexept {
	++_strong;
}

void Reference_counters::decrease_strong() noexept {
	--_strong;
}

void Reference_counters::increase_weak() noexept {
	++_weak;
}

void Reference_counters::decrease_weak() noexept {
	--_weak;
}


} // namespace internals
} // namespace pointing
} // namespace jmsf
