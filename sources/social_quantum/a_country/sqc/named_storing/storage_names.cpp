#include "storage_names.h"

namespace sqc {
namespace named_storing {

storage_names::storage_names() {
    _next_id = 0;
}

// очистить все
void storage_names::clear() {
	_entries.clear();
	_next_id = 0;
}

// получаем идентификатор записи по имени
name_id	storage_names::get_name_id( const std::string &name, const size_t p_name_len ) const {
    size_t name_len = p_name_len;

	// если длина не задана, рассчитаем ее
	if( name_len == -1 ) {
		name_len = strlen( name.c_str() );
	}

	std::string	key;
	if( name_len == -1 )	key = name;
	else					key.assign( name.c_str(), name_len );

	name_map::const_iterator i = _entries.find( key );
	if( i != _entries.end() ) return i->second;
	return NO_NAME;
}

// добавляем новое имя
name_id storage_names::set_name( const std::string &name, const size_t name_len ) {	
	// сначала попробуем найти существующий идентификатор
	name_id	id = get_name_id( name, name_len );
	if( id != NO_NAME ) {
		// нашлося 
		return id;
	}

	id = ++_next_id;
	
	if( name_len == -1 ) {
		_entries[name] = id;
	}
	else {
		_entries[std::string(name.c_str(), name_len)] = id;
	}

	return id;
}

// упаковываем в массив байт
bool storage_names::pack( void *pdest, size_t &cb ) const {

	packed_entry	*p = (packed_entry*)pdest;

	// проходим все значения
	for( name_map::const_iterator i = _entries.begin(); i != _entries.end(); ++i ) {
		size_t	cb_entry = sizeof( packed_entry );
		cb_entry += i->first.length();

		if( p ) {
			// если передан реальный массив байт, то копируем данные
			p->_id = i->second;
			strcpy( p->_name, i->first.c_str() );
		}

		cb += cb_entry;
		if( p ) {
			p = (packed_entry*)((char*)p + cb_entry);
		}
	}

	// завершающий 0
	cb += sizeof( *p );
	if( p ) {
		// записываем признак окончания
		p->_id = NO_NAME;
		*p->_name = 0;
	}

	return true;
}

// распаковываем из массива байт
bool storage_names::unpack( const void *pfrom, size_t &cb ) {
	clear();

	if( !pfrom ) {
		return false;
	}

	if( cb < sizeof( packed_entry ) ) {
		return false;
	}

	const packed_entry	*p = (const packed_entry*)pfrom;
	
	while( p->_id != NO_NAME )  {
				// добавляем
		// обнавляем next_id
		_next_id = std::max( static_cast< short >( p->_id + 1 ), _next_id );

		size_t	cb_entry = sizeof( *p ) + strlen( p->_name );

		_entries[p->_name] = p->_id;
		
		cb -= cb_entry;

		p = (const packed_entry*)((const char*)p + cb_entry);

		if( cb < sizeof( packed_entry ) ) {
			return false;
		}
	}

	// последняя прочитанная запись
	cb -= sizeof( packed_entry );

	// успешно дошли до конца
	return true;
}

// получить имя по идентификатору
bool storage_names::get_name( name_id id, std::string &name ) const {
	for( name_map::const_iterator i = _entries.begin(); i != _entries.end(); ++i ) {
		if( i->second == id ) {
			name = i->first;
			return true;
		}
	}
	return false;
}

} // namespace named_storing
} // namespace sqc
