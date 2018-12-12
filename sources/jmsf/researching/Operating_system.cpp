#include "Operating_system.h"

#include "temporary_windows_include.h"
//#include <rpc.h>


namespace jmsf {
namespace researching {


// static
std::string Operating_system::generate_UUID() noexept {
	UUID uuid_of_windows = {};
	
	const RPC_STATUS uuid_creation_result_of_windows = ::UuidCreate( &uuid_of_windows );

	const bool is_uuid_creation_successfully_completed =
		uuid_creation_result_of_windows == RPC_S_OK ||
		uuid_creation_result_of_windows == RPC_S_UUID_LOCAL_ONLY ||
		uuid_creation_result_of_windows == RPC_S_UUID_NO_ADDRESS;

	if ( !is_uuid_creation_successfully_completed ) return std::string();

	char *uuid_string_pointer = nullptr;

	const RPC_STATUS uuid_to_string_conversion_result = ::UuidToStringA( &uuid_of_windows, reinterpret_cast< RPC_CSTR * >( &uuid_string_pointer ) );

	if ( uuid_to_string_conversion_result == RPC_S_OK ) {
		std::string resulted_uuid = reinterpret_cast< char * >( uuid_string_pointer );
		::RpcStringFreeA( reinterpret_cast< RPC_CSTR * >( &uuid_string_pointer ) );
		return resulted_uuid;
	} else {
		return std::string();
	}
}



} // namespace researching
} // namespace jmsf
