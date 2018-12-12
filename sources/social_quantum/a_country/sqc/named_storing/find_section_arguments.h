#pragma once

#include "storage_entry_identifier.h"
#include "storage_section.h"

namespace sqc {
namespace named_storing {

//-------------------------------------------------------------------------------------------------
// внутренн€€ структура - описание параметров поиска - создани€ секции
//-------------------------------------------------------------------------------------------------
struct find_section_arg {
	// признак - создаем новую секцию или ищем существующую
	bool create_new;

	//union {
		struct{
			// добавл€ем секцию даже в случае если она ранее найдена
			bool force_add;

			// тип новой записи
			entry_type type;
		}

		new_entry;

		struct {
			// если указано, то ищем секцию вслед на указанной
			bool look_after_defined;
			storage_section::entries_map::iterator look_after;

			// если указана look_after, мы также должны указать name_id дл€ дальнейшего поиска
			name_id look_name;

			// если указана look_after, мы также должны указать look_parent
			storage_section *look_parent;

			// признак что нас не волнует название
			bool accepted_any_name;
		}

		existing;
	//};
};

} // namespace named_storing
} // namespace sqc
