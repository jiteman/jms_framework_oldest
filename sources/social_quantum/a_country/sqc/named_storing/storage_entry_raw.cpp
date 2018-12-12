#include "storage_entry_raw.h"

namespace sqc {
namespace named_storing {

entry_type storage_entry_raw::get_type() const {
	return entry_type_raw;
}

size_t storage_entry_raw::get_size() const {
	return _value.size();
}

const void *storage_entry_raw::get_data() const {
	return &_value[ 0 ];
}

void storage_entry_raw::set( const void *ptr, const size_t cb ) {
	if( !cb ) {
		// пустая строка
		_value.clear();
	} else {
		// копируем строку
		_value.resize( cb );
		memcpy( &_value[ 0 ], ptr, cb );
	}
}

} // namespace named_storing
} // namespace sqc
