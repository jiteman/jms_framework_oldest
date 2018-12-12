#pragma once

#include "storage_entry.h"

namespace sqc {
namespace named_storing {

class storage_entry_value :
    public storage_entry
{

public:
	// получить размер объекта
	virtual size_t get_size() const = 0;
	
	// получить данные
	virtual const void *get_data() const = 0;

	// установить значение
	virtual void set( const void *pointer_to_data, size_t size_of_value ) = 0;
};

} // namespace named_storing
} // namespace sqc
