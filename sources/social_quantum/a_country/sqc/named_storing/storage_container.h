#pragma once

#include "storage_entry_identifier.h"
#include "storage_names.h"
#include "storage_entry_string.h"
#include "storage_section.h"

#include <vector>
#include <assert.h>

#include "find_section_arguments.hxx"
#include "storage_access.hxx"

namespace sqc {
namespace named_storing {

// именованное хранилище объектов
class storage_container {
	friend class storage_access;

	struct packed_header {
		// сигнатура
		unsigned int _signature;

		// верси€ запаковки
		byte_t _version;
	};

public:
    virtual ~storage_container();
	storage_container();

	// очищаем содержимое storage
	virtual void clear();

	// создать новую секцию. также открываем существующую секцию, если не задан флаг create_if_exist
	virtual storage_access *create_section( const std::string &section_name, storage_access *parent, bool create_if_exist = false );

	// открываем секцию с указанными именем. если указана секци€ prev, то открываем следующую за ней секцию с тем-же
	// названием
	virtual storage_access *open_section( const std::string &section_name, storage_access *parent );

	// открыть следующую секцию на чтение !!! внимание! prev access закрываетс€ 
	// специальный параметр accepted_any_name - если true то проверка по имени не об€зательна
	virtual storage_access *get_next_section( storage_access *prev, bool accepted_any_name = false );

	// открыть следующую секцию на чтение !!! внимание! prev access Ќ≈ закрываетс€ 
	// специальный параметр accepted_any_name - если true то проверка по имени не об€зательна
	virtual storage_access *get_next_section_without_closing_previous( storage_access *prev, bool accepted_any_name = false );

	// закрываем секцию
	virtual bool close_section( storage_access *paccess );

	// удал€ем все значени€ в секции
	virtual bool clear_values( storage_access *paccess );

    bool store_value( const std::string &entry_name, storage_access *parent, const std::string &value, const bool create_if_exist = false );
    //bool store_value( const std::string &entry_name, storage_access *parent, const std::wstring &value, const bool create_if_exist = false );

    template< class A_type >
    bool store_value( const std::string &entry_name, storage_access *parent, const A_type &value, const bool create_if_exist = false );

    bool query_value( const std::string &entry_name, storage_access *parent, std::string &value );
    //bool query_value( const std::string &entry_name, storage_access *parent, std::wstring &value );

    template< class A_type >
    bool query_value( const std::string &entry_name, storage_access *parent, A_type &value );

    bool query_value( const std::string &entry_name, storage_access *parent, std::string &value, storage_access_ptr &in_previous_out_current );
    //bool query_value( const std::string &entry_name, storage_access *parent, std::wstring &value, storage_access_ptr &in_previous_out_current );

    template< class A_type >
    bool query_value( const std::string &entry_name, storage_access *parent, A_type &value, storage_access_ptr &in_previous_out_current );

	// устанавливаем значение в хранилище (создаем секцию указанного типа)
	virtual bool store_value_detailed( const std::string &entry_name, storage_access *parent, const void *ptr, size_t cb, entry_type type, bool create_if_exist = false );

	// устанавливаем значение в хранилище в конкретный аксессор
	virtual bool store_value_detailed(storage_access *target_accessor, const void *ptr, size_t cb, entry_type type);

	// получаем значение из хранилища
	virtual bool query_value_detailed( const std::string &entry_name, storage_access *parent, void *ptr, size_t cb, size_t &cb_out, entry_type type, storage_access_ptr &prev );
	
	// упаковать хранилище в массив байтов
	// этот метод нельз€ делать виртуальным, поскольку он размещает пам€ть в векторе 
	// - могут быть проблемы при статической линковке runtime
	/*virtual */ bool pack( std::vector< byte_t > &out ) const;


	// распаковать хранилище из массива байтов
	virtual bool unpack( const void *ptr, size_t cb );

	// получаем признак, было ли модифицировано хранилище
	virtual bool is_modified() const;

	// устанавливаем признак модификации
	virtual void set_modified( bool set = true );

	// возвратить отображаемое им€
	std::string get_name_by_id( name_id id );

private:
	// открываем секцию.
	storage_access *_create_accessor( const std::string &section_name, storage_access *parent, const find_section_arg &arg );

private:
	storage_section	_root;
	storage_names _names;
//	mutable awin::sync::reenterable_lock	access;
    bool _modified;

};


// } // namespace named_storing
// } // namespace sqc
// 
// 
// #include "storage_access.h"
// 
// namespace sqc {
// namespace named_storing {

template< class A_type >
bool storage_container::store_value( const std::string &entry_name, storage_access *parent, const A_type &value, const bool create_if_exist ) {
    const entry_type entry_type_for_value = entry_type_identifier::get_type_for( value );

    assert( entry_type_for_value != entry_type_string && entry_type_for_value != entry_type_wstring );

	return store_value_detailed( entry_name, parent, &value, sizeof( value ), entry_type_for_value, create_if_exist );
}

template< class A_type >
bool storage_container::query_value( const std::string &entry_name, storage_access *parent, A_type &value ) {
    return query_value( entry_name, parent, value, storage_access_ptr() );
}

template< class A_type >
bool storage_container::query_value( const std::string &entry_name, storage_access *parent, A_type &value, storage_access_ptr &in_previous_out_current ) {
    const entry_type entry_type_for_value = entry_type_identifier::get_type_for( value );

    assert( entry_type_for_value != entry_type_string && entry_type_for_value != entry_type_wstring );

    size_t size_of_readed_data = 0;

	if ( !query_value_detailed( entry_name, parent, &value, sizeof( value ), size_of_readed_data, entry_type_for_value, in_previous_out_current ) ) return false;

    if ( size_of_readed_data != sizeof( value ) ) return false;

    return true;
}

} // namespace named_storing
} // namespace sqc
