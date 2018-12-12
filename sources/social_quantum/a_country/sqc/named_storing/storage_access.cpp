#include "storage_access.h"
#include "storage_container.h"

namespace sqc {
namespace named_storing {

storage_access::storage_access( storage_container *p_storage, storage_section *found_section, storage_entry_ptr found_entry, name_id found_name, const storage_section::entries_map::iterator &i, const bool can_write )
    : 
//		lock( p->access ),
        _entry_i( i )
{
	_magick = 12345;
	_section = found_section;
	_entry = found_entry;
	_name = found_name;
    _storage = p_storage;
}

bool storage_access::verify() {
	if( !this ) {
		return false;
	}
	if( _magick != 12345 ) {
		return false;
	}
	return true;
}

storage_section *storage_access::get_section() const {
	return _section;
}

storage_entry *storage_access::get_entry() const {
	return _entry.get();
}

storage_section *storage_access::get_entry_as_section() const {
	if( _entry->get_type() != entry_type_section ) {
		// тип найденной записи - не секция
		return 0;
	}
	return (storage_section *)get_entry();
}
	
name_id storage_access::get_name_id() const {
	return _name;
}

const storage_section::entries_map::iterator &storage_access::get_entry_i() const {
	return _entry_i;
}

storage_access *storage_access::create_section( const std::string &section_name, const bool create_if_exist ) {
    return _storage->create_section( section_name, this, create_if_exist );
}

storage_access *storage_access::open_section( const std::string &section_name ) {
    return _storage->open_section( section_name, this );
}

storage_access *storage_access::get_next_section( const bool accepted_any_name ) {
    return _storage->get_next_section( this, accepted_any_name );
}

storage_access *storage_access::get_next_section_without_closing_previous( bool accepted_any_name ) {
    return _storage->get_next_section_without_closing_previous( this, accepted_any_name );
}

bool storage_access::store_value( const std::string &entry_name, const std::string &value, const bool create_if_exist ) {
    return _storage->store_value( entry_name, this, value, create_if_exist );
}


//bool storage_access::store_value( const std::string &entry_name, const std::wstring &value, const bool create_if_exist ) {
//    return _storage->store_value( entry_name, this, value, create_if_exist );
//}

bool storage_access::query_value( const std::string &entry_name, std::string &value ) {
	storage_access_ptr dummy;
    return _storage->query_value( entry_name, this, value, dummy );
}

//bool storage_access::query_value( const std::string &entry_name, std::wstring &value ) {
//	storage_access_ptr dummy;
//    return _storage->query_value( entry_name, this, value, dummy );
//}

bool storage_access::query_value( const std::string &entry_name, std::string &value, storage_access_ptr &in_previous_out_current ) {
    return _storage->query_value( entry_name, this, value, in_previous_out_current );
}

//bool storage_access::query_value( const std::string &entry_name, std::wstring &value, storage_access_ptr &in_previous_out_current ) {
//    return _storage->query_value( entry_name, this, value, in_previous_out_current );
//}

bool storage_access::close() {
    return _storage->close_section( this );
}

bool storage_access::clear_values() {
    return _storage->clear_values( this );
}

} // namespace named_storing
} // namespace sqc
