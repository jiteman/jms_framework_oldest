#include "storage_container.h"
#include "find_section_arguments.h"
#include "storage_entry_value.h"
#include "storage_access.h"
#include <assert.h>

namespace sqc {
namespace named_storing {

storage_container::~storage_container()
{}

storage_container::storage_container()
    :
        _modified( false )
{}

void storage_container::clear() {
//	awin::sync::reenterable_locker	locker( access );
	
	_names.clear();
	_root.clear();

	set_modified( false );
}

storage_access *storage_container::create_section( const std::string &section_name, storage_access *parent, const bool create_if_exist ) {
	// формируем параметры запроса
	find_section_arg arg = { true };
	arg.new_entry.force_add = create_if_exist;
	
	// открываем секцию.
	storage_access *pa = _create_accessor( section_name, parent, arg );

	if ( !pa ) return 0;

	set_modified();
	return pa;
}

storage_access *storage_container::open_section( const std::string &section_name, storage_access *parent ) {
//	awin::sync::reenterable_locker	locker( access );

	// формируем параметры запроса
	find_section_arg arg = { false };

	if ( section_name.empty() ) {
		arg.existing.accepted_any_name = true;
	}

	// открываем секцию.
	return _create_accessor( section_name, parent, arg );
}

storage_access *storage_container::get_next_section( storage_access *prev, const bool accepted_any_name ) {
	if( !prev ) {
		return 0;
	}

	if( !prev->verify() ) {
		// типичная ошибка - обращение к закрытой секции
		assert( false );
		return 0;
	}

	storage_access	*to_delete = prev;

	// формируем параметры запроса
	find_section_arg	arg;
	arg.create_new = false;
	arg.existing.look_after_defined = true;
	arg.existing.look_after = prev->get_entry_i();
	arg.existing.look_parent = prev->get_section();
	arg.existing.look_name = accepted_any_name ? NO_NAME: prev->get_name_id();
	arg.existing.accepted_any_name = accepted_any_name;


	storage_access *paccess = _create_accessor( "", 0, arg );

	close_section( to_delete );

	return paccess;
}

storage_access *storage_container::get_next_section_without_closing_previous( storage_access *prev, const bool accepted_any_name ) {
	if( !prev ) {
		return 0;
	}

	if( !prev->verify() ) {
		// типичная ошибка - обращение к закрытой секции
		assert( false );
		return 0;
	}

//	storage_access	*to_delete = prev;

	// формируем параметры запроса
	find_section_arg	arg;
	arg.create_new = false;
	arg.existing.look_after_defined = true;
	arg.existing.look_after = prev->get_entry_i();
	arg.existing.look_parent = prev->get_section();
	arg.existing.look_name = accepted_any_name ? NO_NAME: prev->get_name_id();
	arg.existing.accepted_any_name = accepted_any_name;


	storage_access *paccess = _create_accessor( 0, 0, arg );

	return paccess;
}

storage_access *storage_container::_create_accessor( const std::string &section_name, storage_access *parent, const find_section_arg &arg ) {	
	// получаем секцию для относительного пути
	storage_section	*pfrom = &_root;

	if ( parent ) {
		pfrom = parent->get_entry_as_section();
	}

	if ( !arg.create_new ) {
		// ищем непервый элемент - секция уже известна
		if ( arg.existing.look_parent ) {
			pfrom = arg.existing.look_parent;
		}
	}

	storage_section	*found_section = 0;
	name_id found_id = NO_NAME;
	storage_section::entries_map::iterator found_i;
	storage_entry_ptr found_entry = pfrom->find_element( section_name, _names, arg, found_section, found_id, found_i );

	if ( !found_entry ) {
		// не нашлось
		return 0;
	}
	
	storage_access *pnew = new storage_access( this, found_section, found_entry, found_id, found_i, true );
	return pnew;
}

bool storage_container::close_section( storage_access *paccess ) {
	if( !paccess ) {
		// нулевой указатель
		assert( false );
		return false;
	}

	if( !paccess->verify() ) {
		// неправильный указатель
		assert( false );
		return false;
	}


	delete paccess;
	return true;
}

bool storage_container::store_value_detailed( const std::string &entry_name, storage_access *const parent, const void *const ptr, const size_t cb, const entry_type type, const bool create_if_exist ) {
	find_section_arg arg = { true };
	arg.new_entry.force_add = create_if_exist;
	arg.new_entry.type = type;

	storage_access_ptr pacc( _create_accessor( entry_name, parent, arg ) );

	if ( !pacc ) {
		// не удалось открыть аксессор
		return false;
	}

	storage_entry *p = pacc->get_entry();

	if ( p->get_type() != type ) {
		// вернулся не тот тип записи
		return false;
	}

	storage_entry_value	*pentry = static_cast< storage_entry_value * >( p );
	pentry->set( ptr, cb );	
	set_modified();
	return true;
}

bool storage_container::store_value_detailed( storage_access *const target_accessor, const void *const ptr, const size_t cb, const entry_type type ) {
	storage_entry *p = target_accessor->get_entry();

	if ( p->get_type() != type ) {
		// вернулся не тот тип записи
		return false;
	}

	storage_entry_value	*pentry = static_cast< storage_entry_value * >( p );
	pentry->set( ptr, cb );
	set_modified();
	return true;
}

bool storage_container::query_value_detailed( const std::string &entry_name, storage_access *parent, void *ptr, size_t cb, size_t &cb_out, entry_type type, storage_access_ptr &found_access ) {
	// в found_access возможно были переданы данные для поиска непервого значения
//	storage_access_ptr prev( found_access );

	find_section_arg arg = { false };

	if ( found_access ) {
		arg.existing.look_after_defined = true;
		arg.existing.look_after = found_access->get_entry_i();
		arg.existing.look_parent = found_access->get_section();
		arg.existing.look_name = found_access->get_name_id();
	}

    found_access.reset( _create_accessor( entry_name, parent, arg ) );

	if ( !found_access ) {
		// значение не нашлось
		return false;
	}

	storage_entry *p = found_access->get_entry();

	// сверяет типы - смотрим что собственно нашли
	if ( type != entry_type_raw ) {
		// если мы запрашиваем конкретный тип то нужно проверить строгое совпадение
		if( p->get_type() != type ) {
			return false;
		}
	} else {
		// если мы запрашиваем тип raw, то не важно какой тип у найденной записи - главное чтобы не секция
		if( p->get_type() == entry_type_section ) { 
			return false;
		}
	}

	storage_entry_value *pentry = static_cast<storage_entry_value*>( p );
	cb_out = pentry->get_size();

	if ( !ptr ) {
		// просто спрашивали размер 
		return true;
	}

	if ( cb_out > cb ) {
		// буфер слишком мал
		return false;
	}

	memcpy( ptr, pentry->get_data(), cb_out );
	return true;
}

bool storage_container::pack( std::vector< byte_t> &out ) const {
//	awin::sync::reenterable_locker	locker( access );

	// подсчет размера
	size_t cb = sizeof( packed_header );

	if( !_names.pack( 0, cb ) ) {
		return false;
	}

	if( !_root.pack( 0, cb ) ) {
		return false;
	}

	out.resize( cb );
	cb = 0;

	byte_t *ptr_to = &out[ 0 ];

	packed_header *phdr = reinterpret_cast< packed_header * >( ptr_to );
	phdr->_signature = *reinterpret_cast< const unsigned int * >( "abba" );
	phdr->_version = 1;

	ptr_to += sizeof( *phdr );
	cb += sizeof( *phdr );
	
	size_t	cb_before = cb;
	if( !_names.pack( ptr_to, cb ) ) {
		return false;
	}
	ptr_to += cb-cb_before;

	if( !_root.pack( ptr_to, cb ) ) {
		return false;
	}

	return true;
}

bool storage_container::unpack( const void *const ptr, const size_t p_cb ) {
    size_t cb = p_cb;

//	awin::sync::reenterable_locker	locker( access );

	clear();
	
	// сначала получаем заголовок 
	const byte_t *ptr_to = reinterpret_cast< const byte_t * >( ptr );
	const packed_header *const phdr = reinterpret_cast< const packed_header * >( ptr_to );

	// проверяем версию
	if( phdr->_version != 1 ) {
		return false;
	}

	if( phdr->_signature != *(unsigned*)"abba" ) {
		return false;
	}

	cb -= sizeof( *phdr );
	ptr_to += sizeof( *phdr );

	// распаковывем карту имен
	size_t	cb_before = cb;
	if( !_names.unpack( ptr_to, cb ) ) {
		_names.clear();
		return false;
	}
	
	// распаковываем дерево секций
	ptr_to += cb_before-cb;
	if( !_root.unpack( ptr_to, cb ) ) {
		_names.clear();
		_root.clear();
		return false;
	}

	if( cb ) {
		// какие-то неучтенные данные
		_names.clear();
		_root.clear();

		return false;
	}

	// все OK!
	return true;
}

bool storage_container::is_modified() const {

	return _modified;
}

void storage_container::set_modified( const bool set ) {
	_modified = set;
}

bool storage_container::clear_values( storage_access *paccess ) {
	if( !paccess ) {
		// нулевой указатель
		assert( false );
		return false;
	}

	if( !paccess->verify() ) {
		// неправильный указатель
		assert( false );
		return false;
	}

	storage_section	*psect = paccess->get_entry_as_section();
	psect->clear();

	return true;
}

bool storage_container::store_value( const std::string &entry_name, storage_access *parent, const std::string &value, const bool create_if_exist ) {
    const entry_type entry_type_for_value = entry_type_identifier::get_type_for( value );

    assert( entry_type_for_value == entry_type_string );

	return store_value_detailed( entry_name, parent, value.c_str(), value.length() * sizeof( value[ 0 ] ), entry_type_identifier::get_type_for( value ), create_if_exist );
}

//bool storage_container::store_value( const std::string &entry_name, storage_access *parent, const std::wstring &value, const bool create_if_exist ) {
//    const entry_type entry_type_for_value = entry_type_identifier::get_type_for( value );
//
//    assert( entry_type_for_value == entry_type_wstring );
//
//	return store_value_detailed( entry_name, parent, value.c_str(), value.length() * sizeof( value[ 0 ] ), entry_type_identifier::get_type_for( value ), create_if_exist );
//}

bool storage_container::query_value( const std::string &entry_name, storage_access *parent, std::string &value ) {
    storage_access_ptr dummy;
    return query_value( entry_name, parent, value, dummy );
}

//bool storage_container::query_value( const std::string &entry_name, storage_access *parent, std::wstring &value ) {
//    storage_access_ptr dummy;
//    return query_value( entry_name, parent, value, dummy );
//}

bool storage_container::query_value( const std::string &entry_name, storage_access *parent, std::string &value, storage_access_ptr &in_previous_out_current ) {
    const entry_type entry_type_for_value = entry_type_identifier::get_type_for( value );

    assert( entry_type_for_value == entry_type_string );

    size_t size_of_readed_data = 0;

	if ( !query_value_detailed( entry_name, parent, nullptr, 0, size_of_readed_data, entry_type_for_value, in_previous_out_current ) ) return false;

    const size_t quantity_of_characters = size_of_readed_data / sizeof( value[ 0 ] );

    storage_entry_string< char > *entry_pointer =
        static_cast< storage_entry_string< char > * >( in_previous_out_current->get_entry() );

    value.assign( reinterpret_cast< const char * >( entry_pointer->get_data() ), quantity_of_characters );
    return true;
}

//bool storage_container::query_value( const std::string &entry_name, storage_access *parent, std::wstring &value, storage_access_ptr &in_previous_out_current ) {
//    const entry_type entry_type_for_value = entry_type_identifier::get_type_for( value );
//
//    assert( entry_type_for_value == entry_type_wstring );
//
//    size_t size_of_readed_data = 0;
//
//	if ( !query_value_detailed( entry_name, parent, nullptr, 0, size_of_readed_data, entry_type_for_value, in_previous_out_current ) ) return false;
//
//    const size_t quantity_of_characters = size_of_readed_data / sizeof( value[ 0 ] );
//
//    storage_entry_string< wchar_t > *entry_pointer =
//        static_cast< storage_entry_string< wchar_t > * >( in_previous_out_current->get_entry() );
//
//    value.assign( reinterpret_cast< const wchar_t * >( entry_pointer->get_data() ), quantity_of_characters );
//    return true;
//}

std::string storage_container::get_name_by_id( name_id id ) {
	std::string	s;
	bool ret = _names.get_name( id, s );

	if( !ret ) {
		assert( ret );
		return s;
	}
	
	return s;
}

} // namespace named_storing
} // namespace sqc
