#pragma once

#include <memory>

namespace sqc {
namespace named_storing {

class storage_access;

typedef std::tr1::shared_ptr< storage_access > storage_access_ptr;

} // namespace named_storing
} // namespace sqc
