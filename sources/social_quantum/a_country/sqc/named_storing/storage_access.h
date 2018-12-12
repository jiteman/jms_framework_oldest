#pragma once

#include "storage_entry.h"
#include "storage_section.h"
#include "storage_container.h"

#include "storage_entry.hxx"
#include "storage_access.hxx"

namespace sqc {
namespace named_storing {

// класс доступа к именованному хранилищу.
class storage_access {

public:
	storage_access( storage_container *p_storage, storage_section *found_section, storage_entry_ptr found_entry, name_id found_name, const storage_section::entries_map::iterator &i, bool can_write );

	// провер€ем данный экземпл€р объекта на корректность
	bool verify();

	// получить секцию
	storage_section *get_section() const;

	// получаем запись
	storage_entry *get_entry() const;

	// получаем найденную запись в предположении, что это сеци€
	storage_section *get_entry_as_section() const;
	
	// получаем идентификатор имени
	name_id get_name_id() const;

	// получаем итератор записи
	const storage_section::entries_map::iterator &get_entry_i() const;

    storage_access *create_section( const std::string &section_name, bool create_if_exist = false );
    storage_access *open_section( const std::string &section_name );
    storage_access *get_next_section( bool accepted_any_name = false );
    storage_access *get_next_section_without_closing_previous( bool accepted_any_name = false );

    bool store_value( const std::string &entry_name, const std::string &value, const bool create_if_exist = false );
    //bool store_value( const std::string &entry_name, const std::wstring &value, const bool create_if_exist = false );

    template< class A_type >
    bool store_value( const std::string &entry_name, const A_type &value, const bool create_if_exist = false );

    bool query_value( const std::string &entry_name, std::string &value );
    //bool query_value( const std::string &entry_name, std::wstring &value );

    template< class A_type >
    bool query_value( const std::string &entry_name, A_type &value );

    bool query_value( const std::string &entry_name, std::string &value, storage_access_ptr &in_previous_out_current );
    //bool query_value( const std::string &entry_name, std::wstring &value, storage_access_ptr &in_previous_out_current );

    template< class A_type >
    bool query_value( const std::string &entry_name, A_type &value, storage_access_ptr &in_previous_out_current );

	bool close();
	bool clear_values();

private:
	unsigned _magick;
	bool _can_write;
	storage_section	*_section;
	storage_entry_ptr _entry;
	storage_section::entries_map::iterator _entry_i;
	name_id _name;
    storage_container *_storage;
//	awin::sync::reenterable_locker	lock;

};

template< class A_type >
bool storage_access::store_value( const std::string &entry_name, const A_type &value, const bool create_if_exist ) {
    return _storage->store_value( entry_name, this, value, create_if_exist );
}

template< class A_type >
bool storage_access::query_value( const std::string &entry_name, A_type &value ) {
	storage_access_ptr dummy;
    return _storage->query_value( entry_name, this, value, dummy );
}

template< class A_type >
bool storage_access::query_value( const std::string &entry_name, A_type &value, storage_access_ptr &in_previous_out_current ) {
    return _storage->query_value( entry_name, this, value, in_previous_out_current );
}

} // namespace named_storing
} // namespace sqc
