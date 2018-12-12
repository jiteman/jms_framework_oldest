#pragma once

#include "storage_entry_identifier.h"
#include <map>

namespace sqc {
namespace named_storing {

// строковая карта. по строке возвращается уникальный в рамках карты идентификатор
class storage_names {

	typedef std::pair< std::string, name_id > name_pair;
	typedef std::map< std::string, name_id > name_map;

	// структура для представления при упаковке
#pragma pack( push, 1 )
    struct packed_entry {
        name_id	_id;
        char _name[ 1 ];
    };
#pragma pack( pop )

public:
	storage_names();

	// очистить все
	void clear();

	// получаем идентификатор записи по имени
	name_id	get_name_id( const std::string &name, size_t name_len = -1 ) const;

	// добавляем новое имя
	name_id set_name( const std::string &name, size_t name_len = -1 );

	// упаковываем в массив байт
	bool pack( void *pdest, size_t &cb ) const;

	// распаковываем из массива байт
	bool unpack( const void *pfrom, size_t &cb );

	// получить имя по идентификатору
	bool get_name( name_id id, std::string &name ) const;

private:
	name_map _entries;
	name_id _next_id;

};

} // namespace named_storing
} // namespace sqc
