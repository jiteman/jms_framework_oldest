#pragma once

#include "storage_entry_identifier.h"
#include "storage_container.h"

namespace sqc {
namespace named_storing {

    // �����, ����������� �������� storage � �����
class storage_file {

public:
	// �������������, ������������� ��� �����
	storage_file &init( const std::string &path_to_file );
	
	// ������ ������ �� �����
	bool read( bool error_if_not_exist = true );
	
	// ��������� ������ ��������� � ����	
	bool write( bool check_modified = true );

	// �������� storage ��� ��������
	storage_container &get_storage();

private:
	storage_container	_storage_data;
	string_t _path_to_file;

};

} // namespace named_storing
} // namespace sqc
