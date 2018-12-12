#pragma once

#include "storage_entry_identifier.h"
#include "storage_container.h"

namespace sqc {
namespace named_storing {

    // класс, реализующий хранение storage в файле
class storage_file {

public:
	// инициализирем, устанавливаем имя файла
	storage_file &init( const std::string &path_to_file );
	
	// читаем данные из файла
	bool read( bool error_if_not_exist = true );
	
	// записывем данные хранилища в файл	
	bool write( bool check_modified = true );

	// получить storage для операций
	storage_container &get_storage();

private:
	storage_container	_storage_data;
	string_t _path_to_file;

};

} // namespace named_storing
} // namespace sqc
