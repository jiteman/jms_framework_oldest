#pragma once

#include "storage_entry_value.h"
#include <assert.h>

namespace sqc {
namespace named_storing {

// объект фиксированного размера
template < class A_type >
class storage_entry_fixed :
    public storage_entry_value
{
	// получить тип объекта
	virtual entry_type get_type() const;

	// получить размер объекта
	virtual size_t get_size() const;

	// получить данные
	virtual const void *get_data() const;

	// установить значение
	virtual void set( const void *ptr, size_t size_in_bytes );

private:
	A_type _value;

};

template< class A_type >
entry_type storage_entry_fixed< A_type >::get_type() const {
    const entry_type entry_type_for_string = entry_type_identifier::get_type_for( _value );

    assert( entry_type_for_string != entry_type_string && entry_type_for_string != entry_type_wstring );

	return entry_type_for_string;
}

template< class A_type >
size_t storage_entry_fixed< A_type >::get_size() const {
	return sizeof( _value );
}

template< class A_type >
const void *storage_entry_fixed< A_type >::get_data() const {
	return &_value;
}

template< class A_type >
void storage_entry_fixed< A_type >::set( const void *ptr, const size_t size_in_bytes ) {
	// проверяем фиксированный размер
	assert( get_size() == size_in_bytes );

	// копируем значение
	_value = *reinterpret_cast< const A_type * >( ptr );
}

} // namespace named_storing
} // namespace sqc
