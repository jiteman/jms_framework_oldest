#pragma once

#include "storage_entry_identifier.h"
#include <memory>

#include "storage_entry.hxx"

namespace sqc {
namespace named_storing {

class storage_entry {

public:
	virtual entry_type get_type() const = 0;

	virtual ~storage_entry() = 0;

};

} // namespace named_storing
} // namespace sqc
