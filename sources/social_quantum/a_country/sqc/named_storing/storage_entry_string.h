#pragma once

#include "storage_entry_value.h"
#include <assert.h>

namespace sqc {
namespace named_storing {

// указатель на строку
template< class A_type >
class storage_entry_string :
    public storage_entry_value
{

public:	
	// получить тип объекта
	virtual entry_type get_type() const;
	
	// получить размер объекта
	virtual size_t get_size() const;

	// получить данные
	virtual const void *get_data() const;

	// установить значение
	virtual void set( const void *ptr, size_t size_of_string_in_bytes );

private:
	std::basic_string< A_type > _value;

};

template< class A_type >
entry_type storage_entry_string< A_type >::get_type() const {
    const entry_type entry_type_for_string = entry_type_identifier::get_type_for( _value );

    assert( entry_type_for_string == entry_type_string || entry_type_for_string == entry_type_wstring );

	return entry_type_for_string;
}

template< class A_type >
size_t storage_entry_string< A_type >::get_size() const {
	return _value.length() * sizeof( A_type );
}

template< class A_type >
const void *storage_entry_string< A_type >::get_data() const {
	return _value.c_str();
}

template< class A_type >
void storage_entry_string< A_type >::set( const void *ptr, const size_t size_of_string_in_bytes ) {
	if ( size_of_string_in_bytes == 0 ) {
		// пустая строка
		_value.clear();
	} else {
		// копируем строку
		_value.assign( reinterpret_cast< const A_type * >( ptr ), size_of_string_in_bytes / sizeof( A_type ) );
	}
}

} // namespace named_storing
} // namespace sqc
