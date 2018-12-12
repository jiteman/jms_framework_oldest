#pragma once

#include "storage_entry.h"
#include <list>

#include "storage_names.hxx"
#include "find_section_arguments.hxx"

namespace sqc {
namespace named_storing {

// class storage_names;
// struct find_section_arg;

class storage_section :
    public storage_entry
{

public:
	typedef std::pair< name_id, storage_entry_ptr >	entries_pair;
	typedef std::list< entries_pair > entries_map;

#pragma pack( push, 1 )
		struct packed_size_type {
			byte_t	type : 6;
			byte_t	size_code : 2; // 0 - fixed; 1 - 1 byte; 2 - 2 bytes; 3 - 4 bytes
		};

		enum size_code {
			size_code_fixed = 0,
			size_code_byte = 1,
			size_code_word = 2,
			size_code_dword = 3,
		};
#pragma pack( pop )

public:
	// ������� ���������� ������
	void clear();

	// �������� ��� �������
	virtual entry_type get_type() const;

	// �������� ������ �������
	virtual size_t get_size() const;

	// ������� ������ �� �������� ����
	static storage_entry *create_entry_by_type( entry_type type );

	// �������� �� ������ ������� ���� ���������
	static bool is_value( entry_type type );

	// �������� �� ������ ������� ���� ��������� �������������� �������
	static bool is_fixed( entry_type type );

	// ���������� �������� ������� � ���� � ������ ����
	static bool pack_size_type( void *ptr, size_t &cb, entry_type type, size_t size );

	// ���������� ������� � ���� �� ������� ����
	static bool unpack_size_type( const void *ptr, size_t &cb, entry_type &type, size_t &size );

	// ��������� ������ � ������ ����
	virtual bool pack( void *pdest, size_t &cb ) const;
	
	// ������������� �� ������� ����
	virtual bool unpack( const void *pfrom, size_t &cb );
	
	// ����� ������� � �������. ����� ������������� - ��������� ���������� ������������� ���������
	storage_entry_ptr find_element( const std::string &name, storage_names &names, const find_section_arg &arg, 
												storage_section *&found_parent, name_id &found_id,
												storage_section::entries_map::iterator &found_i );

	// �������� ����� ������� � ������
	size_t get_count() const;

protected:
	// ����������� ������
	virtual bool pack_section( void *pdest, size_t &cb ) const;

	// ��������� ������ � �������� ������ �������
	virtual bool unpack_section( const void *pfrom, size_t &cb, size_t count );

private:
	entries_map	_entries;

};

} // namespace named_storing
} // namespace sqc
