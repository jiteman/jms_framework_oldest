#pragma once

#include "storage_entry_identifier.h"
#include "storage_section.h"

namespace sqc {
namespace named_storing {

//-------------------------------------------------------------------------------------------------
// ���������� ��������� - �������� ���������� ������ - �������� ������
//-------------------------------------------------------------------------------------------------
struct find_section_arg {
	// ������� - ������� ����� ������ ��� ���� ������������
	bool create_new;

	//union {
		struct{
			// ��������� ������ ���� � ������ ���� ��� ����� �������
			bool force_add;

			// ��� ����� ������
			entry_type type;
		}

		new_entry;

		struct {
			// ���� �������, �� ���� ������ ����� �� ���������
			bool look_after_defined;
			storage_section::entries_map::iterator look_after;

			// ���� ������� look_after, �� ����� ������ ������� name_id ��� ����������� ������
			name_id look_name;

			// ���� ������� look_after, �� ����� ������ ������� look_parent
			storage_section *look_parent;

			// ������� ��� ��� �� ������� ��������
			bool accepted_any_name;
		}

		existing;
	//};
};

} // namespace named_storing
} // namespace sqc
