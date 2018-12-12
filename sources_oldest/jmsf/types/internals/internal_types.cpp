#include "internal_types.h"


namespace jmsf {


types::internals::platform_boolean logicalXor( const types::internals::platform_boolean first, const types::internals::platform_boolean second ) throw() {
 	return !first && second || first && !second;
}


} // namespace jmsf
