#pragma once

#include "storage_entry_value.h"
#include <vector>

namespace sqc {
namespace named_storing {

// произвольный указатель
class storage_entry_raw :
    public storage_entry_value
{

public:
    // virtuals storage_entry_value
	// получить тип объекта
	virtual entry_type get_type() const;

	// получить размер объекта
	virtual size_t get_size() const;

	// получить данные
	virtual const void *get_data() const;

	// установить значение
	virtual void set( const void *ptr, size_t cb );
    //~virtuals storage_entry_value

private:
	std::vector< byte_t > _value;

};

} // namespace named_storing
} // namespace sqc
