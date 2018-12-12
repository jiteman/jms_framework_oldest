#include "storage_section.h"
#include "storage_entry_fixed.h"
#include "storage_entry_string.h"
#include "storage_entry_raw.h"
#include "find_section_arguments.h"
#include "storage_names.h"
#include <assert.h>

namespace sqc {
namespace named_storing {

void storage_section::clear() {
	_entries.clear();
}
// получить тип объекта
entry_type storage_section::get_type() const {
	return entry_type_section;
}
// получить размер объекта
size_t storage_section::get_size() const {
	return _entries.size();
}

// создаем запись по описанию типа
storage_entry *storage_section::create_entry_by_type( const entry_type type ) {
	storage_entry *p = 0;

	if ( type == entry_type_section ) p = new storage_section();
	else if ( type == entry_type_bool ) p = new storage_entry_fixed< bool >();
	else if ( type == entry_type_byte ) p = new storage_entry_fixed< byte_t >();
	else if ( type == entry_type_word ) p = new storage_entry_fixed< word_t >();
	else if ( type == entry_type_dword ) p = new storage_entry_fixed< dword_t >();
	else if ( type == entry_type_qword ) p = new storage_entry_fixed< qword_t >();
//	else if ( type == entry_type_guid ) p = new storage_entry_fixed< GUID >();
	else if ( type == entry_type_string ) p = new storage_entry_string< char >();
	else if ( type == entry_type_wstring ) p = new storage_entry_string< wchar_t >();
	else if ( type == entry_type_raw ) p = new storage_entry_raw();
	else return 0;

	if ( ( size_t )p == 0x00000000020B24F0 ) {	
		assert( true );
	}

	return p;
}

// является ли запись данного типа значением
// static
bool storage_section::is_value( const entry_type type ) {
	return 
		type == entry_type_bool ||
		type == entry_type_byte ||
		type == entry_type_word ||
		type == entry_type_dword ||
		type == entry_type_qword ||
		type == entry_type_guid ||
		type == entry_type_string ||
		type == entry_type_wstring ||
		type == entry_type_raw;
}

// является ли запись данного типа значением фиксированного размера
// static
bool storage_section::is_fixed( const entry_type type ) {
	return 
		type == entry_type_bool ||
		type == entry_type_byte ||
		type == entry_type_word ||
		type == entry_type_dword ||
		type == entry_type_qword ||
		type == entry_type_guid;
}

// копмактная упаковка размера и типа в массив байт
// static
bool storage_section::pack_size_type( void *ptr, size_t &cb, const entry_type type, size_t size ) {
	byte_t *ptr_out = ( byte_t * )ptr;
	packed_size_type options;
	options.type = type;

	if ( is_fixed( type ) ) {
		options.size_code = size_code_fixed;
	} else {
		options.size_code = size_code_byte;
		if ( size >= ( 1 << 8 ) ) {
            options.size_code = size_code_word;
        }

		if ( size >= ( 1 << 16 ) ) {
            options.size_code = size_code_dword;
        }
	}

	packed_size_type *p = ( packed_size_type * )ptr_out;

	cb += sizeof( options );

	if ( p != NULL ) {
		*p = options;
		ptr_out += sizeof( options );
	}

	if ( options.size_code == size_code_byte ) {
		if ( ptr != NULL ) {
			*( byte_t * )ptr_out = static_cast< byte_t >( size );
			ptr_out += sizeof( byte_t );
		}

		cb += sizeof( byte_t );
	} else if ( options.size_code == size_code_word ) {
		if ( ptr != NULL ) {
			*( word_t * )ptr_out = static_cast< word_t >( size );
			ptr_out += sizeof( word_t );
		}

		cb += sizeof( word_t );
	} else if ( options.size_code == size_code_dword ) {
		if ( ptr != NULL ) {
			*( dword_t * )ptr_out = static_cast< dword_t >( size );
			ptr_out += sizeof( dword_t );
		}

		cb += sizeof( dword_t );
	}
	return true;
}

// распаковка размера и типа из массива байт
// static
bool storage_section::unpack_size_type( const void *ptr, size_t &cb, entry_type &type, size_t &size ) {
	// проверяем на корректность
	if ( ptr == NULL ) {
		return false;
	}

	if ( cb < sizeof( packed_size_type ) ) {
		return false;
	}

	const byte_t *ptr_in = reinterpret_cast< const byte_t * >( ptr );
	// читаем заголовок
	packed_size_type options = *reinterpret_cast< const packed_size_type * >( ptr_in );
	ptr_in += sizeof( options );
	cb -= sizeof( options );

	// читаем тип и размер
	type = static_cast< entry_type >( options.type );
	size = 0;

	if ( options.size_code == size_code_byte ) {
		if ( cb < sizeof( byte_t ) ) return false;
		size = *reinterpret_cast< const byte_t * >( ptr_in );
		ptr_in += sizeof( byte_t );
		cb -= sizeof( byte_t );
	} else if ( options.size_code == size_code_word ) {
		if ( cb < sizeof( word_t ) ) return false;

		size = *reinterpret_cast< const word_t * >( ptr_in );
		ptr_in += sizeof( word_t );
		cb -= sizeof( word_t );
	} else if ( options.size_code == size_code_dword ) {
		if ( cb < sizeof( dword_t ) )return false;

		size = *reinterpret_cast< const dword_t * >( ptr_in );
		ptr_in += sizeof( dword_t );
		cb -= sizeof( dword_t );
	}

	return true;
}

// сохранить запись в массив байт
bool storage_section::pack( void *pdest, size_t &cb ) const {
	byte_t *ptr_to = reinterpret_cast< byte_t * >( pdest );
	size_t cb_used = 0;

	if ( !pack_size_type( ptr_to, cb_used, entry_type_section, _entries.size() ) ) {
		return false;
	}

	cb += cb_used;

	if ( ptr_to != NULL ) {
		ptr_to = ptr_to + cb_used;
	}

	return pack_section( ptr_to, cb );
}
	
// распаковываем из массива байт
bool storage_section::unpack( const void *pfrom, size_t &cb ) {
	const byte_t *ptr_from = reinterpret_cast< const byte_t * >( pfrom );
	entry_type type = entry_type();
	size_t count = 0;
	size_t cb_before = cb;

	if ( !unpack_size_type( ptr_from, cb, type, count ) ) {
		return false;
	}

	ptr_from += cb_before - cb;

	if ( type != entry_type_section ) {
		// поскольку мы читаем про сами себя, мы должны прочитать именно секцию
		return false;
	}

	return unpack_section( ptr_from, cb, count );
}
	
// найти элемент в записях. метод неконстантный - поскольку возвращаем неконстантный результат
storage_entry_ptr storage_section::find_element(
    const std::string &name,
    storage_names &names,
    const find_section_arg &arg,
    storage_section *&found_parent,
    name_id &found_id,
    storage_section::entries_map::iterator &found_i )
{
	found_i = storage_section::entries_map::iterator();
	bool	last_path = false;
	name_id	id = NO_NAME;

	const char *end = 0;

	if ( !arg.create_new && arg.existing.look_name ) {
		// ищем непервый элемент - имя и секция для поиска уже известны
		assert( arg.existing.look_parent == this );
		assert( arg.existing.accepted_any_name || arg.existing.look_name != NO_NAME );

		id =  arg.existing.look_name;
		last_path = true;
	} else if ( !name.empty() ) {
		// для начала определим длинну той части строки которую ищем
		for ( end = name.c_str(); *end; end++ ) {
			if ( *end == '\\' || *end == '/' ) {
				break;
			}
		}

		// рассчитаем длинну
		size_t name_len = end - name.c_str();
		last_path = *end == 0;

		if( !last_path || !arg.create_new ) {
			// если мы в середине пути или открываем для чтения, запись должна существовать
			// имя соответственно тоже
			id = names.get_name_id( name, name_len );
		}
		else {
			// в противном случае добавляем имя в карту
			id = names.set_name( name, name_len );
		}
	}
	else if( !arg.create_new && arg.existing.accepted_any_name ) {
		// нас интересует первое попавшееся имя
		last_path = true;
	}
		
	if( last_path ) {
		found_parent = this;
		found_id = id;
	}
	
	if( id == NO_NAME ) {
		if( arg.create_new || !arg.existing.accepted_any_name ) {
			// возвращаем ошибку если мы создаем новую запись и не указали имя или если
			// мы ищем существующую, имя не указали а первая попавшаяся запись нас не интересует
			return storage_entry_ptr();
		}
	}

	// при форсировании создания на последнем участке поиск не осуществляем
	if( !last_path || !( arg.create_new && arg.new_entry.force_add ) ) {
		// ищем в карте
		entries_map::iterator i = _entries.begin();

		if( last_path && arg.existing.look_after_defined ) {
			i = arg.existing.look_after;
			++i;
		}


		for( ; i != _entries.end(); ++i ) {
			if( 
				// нашли запись с заданным ID
				i->first == id || 

				// нам пофигу какой ID искать - берем первый попавшийся
				id == NO_NAME 
				) {
				if( last_path ) {
					// нашли искомое
					found_i = i;
					found_id = i->first;
					return i->second;
				}
				else {
					storage_entry_ptr	pentry = i->second;

					if( pentry->get_type() != entry_type_section ) {
						// нашли запись, но она не секция, а нам еще идти вглубь
						return storage_entry_ptr();
					}

					storage_section *psect = static_cast<storage_section*>( pentry.get() );

					assert( end );
					return psect->find_element( end+1, names, arg, found_parent, found_id, found_i );
				}
			}
		}
	} 

	if( last_path ) {
		if( arg.create_new ) {
			// в случае создания записи создаем новую секцию
			storage_entry_ptr	new_ptr( create_entry_by_type( arg.new_entry.type ) );
			_entries.push_back( entries_pair( id, new_ptr ) );

			return new_ptr;
		}
	}

	return storage_entry_ptr();
}

size_t storage_section::get_count() const {
	return _entries.size();
}

bool storage_section::pack_section( void *pdest, size_t &cb ) const {
	byte_t *ptr_to = reinterpret_cast< byte_t * >( pdest );

	for ( entries_map::const_iterator i = _entries.begin(); i != _entries.end(); ++i ) {
		// сохраняем идентификатор имени
		cb += sizeof( i->first );

		if ( ptr_to ) {
			*reinterpret_cast< name_id * >( ptr_to ) = i->first;
			ptr_to += sizeof( i->first );
		}

		entry_type	type = i->second->get_type();
		size_t	entry_size = 0;

		storage_section	*psect = 0;
		storage_entry_value *pval = 0;

		if( type == entry_type_section ) {
			// у нас секция
			psect = (storage_section *)i->second.get();
			entry_size = psect->get_count();
		}
		if( is_value( type ) ) {

			// у нас значение
			pval = (storage_entry_value *)i->second.get();
			entry_size = pval->get_size();
		}

		{
			size_t	cb_used = 0;
			if( !pack_size_type( ptr_to, cb_used, type, entry_size ) ) {
				return false;
			}
			cb+= cb_used;
			if( ptr_to ) {
				ptr_to += cb_used;
			}
		}


		if( psect ) {
			// упаковываем секцию

			size_t	cb_used = 0;
			if( !psect->pack_section( ptr_to, cb_used ) ) {
				// внутри что-то обломилось
				return false;
			}
			cb += cb_used;
			if( ptr_to ) {
				ptr_to += cb_used;
			}

		}
		if( pval ) {
			// упаковываем значение
			cb += entry_size;
			
			if( ptr_to && entry_size ) {
				memcpy( ptr_to, pval->get_data(), entry_size );
				ptr_to += entry_size;
			}
		}
	}

	return true;
}

bool storage_section::unpack_section( const void *pfrom, size_t &cb, const size_t p_count ) {
	const byte_t *ptr_from = reinterpret_cast< const byte_t * >( pfrom );
	size_t cb_before = 0;
    size_t counter = p_count;

	for ( ; counter; --counter ) {

		// читаем идентификатор имени
		name_id	id = NO_NAME;

		if( cb <= sizeof( name_id ) ) {
			return false;
		}

		id = *(name_id*)ptr_from;
		ptr_from += sizeof( name_id );
		cb -= sizeof( name_id );


		// читаем тип и рамзем объекта
		entry_type	type = entry_type();
		size_t		size_entry = 0;

		cb_before = cb;
		if( !unpack_size_type( ptr_from, cb, type, size_entry ) ){
			return false;
		}
		ptr_from += cb_before - cb;

		// создаем запись
		if( type == entry_type_section ) {
			storage_section	*psect = new storage_section;
			
			cb_before = cb;
			if( !psect->unpack_section( ptr_from, cb, size_entry ) ) {
				delete psect;
				return false;
			}

			_entries.push_back( entries_pair(id, storage_entry_ptr(psect)) );

			ptr_from += cb_before - cb;
		}
		if( is_value( type ) ) {
			if( cb < size_entry ) {
				return false;
			}

			storage_entry_value *pval = (storage_entry_value *)create_entry_by_type( type );
			if( !pval ) {
				return false;
			}

			if( is_fixed( type ) ) {
				// если запись фиксированного типа, то размер не читается, а предполагается исходя из
				// типа записи
				size_entry = pval->get_size();
			}
			else if( !size_entry ) {
				//assert( false );

				//delete pval;
				//return false;
			}


			if( cb < size_entry ) {

				delete pval;
				return false;
			}

			pval->set( ptr_from, size_entry );
			
			_entries.push_back( entries_pair(id, storage_entry_ptr(pval)) );
			
			ptr_from += size_entry;
			cb -= size_entry;
		}
	}
	return true;
}

} // namespace named_storing
} // namespace sqc
