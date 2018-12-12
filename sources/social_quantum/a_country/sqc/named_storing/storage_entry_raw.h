#pragma once

#include "storage_entry_value.h"
#include <vector>

namespace sqc {
namespace named_storing {

// ������������ ���������
class storage_entry_raw :
    public storage_entry_value
{

public:
    // virtuals storage_entry_value
	// �������� ��� �������
	virtual entry_type get_type() const;

	// �������� ������ �������
	virtual size_t get_size() const;

	// �������� ������
	virtual const void *get_data() const;

	// ���������� ��������
	virtual void set( const void *ptr, size_t cb );
    //~virtuals storage_entry_value

private:
	std::vector< byte_t > _value;

};

} // namespace named_storing
} // namespace sqc
