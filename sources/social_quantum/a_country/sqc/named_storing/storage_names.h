#pragma once

#include "storage_entry_identifier.h"
#include <map>

namespace sqc {
namespace named_storing {

// ��������� �����. �� ������ ������������ ���������� � ������ ����� �������������
class storage_names {

	typedef std::pair< std::string, name_id > name_pair;
	typedef std::map< std::string, name_id > name_map;

	// ��������� ��� ������������� ��� ��������
#pragma pack( push, 1 )
    struct packed_entry {
        name_id	_id;
        char _name[ 1 ];
    };
#pragma pack( pop )

public:
	storage_names();

	// �������� ���
	void clear();

	// �������� ������������� ������ �� �����
	name_id	get_name_id( const std::string &name, size_t name_len = -1 ) const;

	// ��������� ����� ���
	name_id set_name( const std::string &name, size_t name_len = -1 );

	// ����������� � ������ ����
	bool pack( void *pdest, size_t &cb ) const;

	// ������������� �� ������� ����
	bool unpack( const void *pfrom, size_t &cb );

	// �������� ��� �� ��������������
	bool get_name( name_id id, std::string &name ) const;

private:
	name_map _entries;
	name_id _next_id;

};

} // namespace named_storing
} // namespace sqc
