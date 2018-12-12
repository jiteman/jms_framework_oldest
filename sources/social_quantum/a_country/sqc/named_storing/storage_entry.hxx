#pragma once

#if defined( JMSF_WINDOWS )
	#include <memory>
#else
	#include <tr1/memory>
#endif

namespace sqc {
namespace named_storing {

class storage_entry;

typedef std::tr1::shared_ptr< storage_entry > storage_entry_ptr;

} // namespace named_storing
} // namespace sqc
