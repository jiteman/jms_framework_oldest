#ifndef __SQC_UTILS_INCLUDED__
#define __SQC_UTILS_INCLUDED__

#include "sqc_defs.h"

#define NAMESPACE_SQC_UTILS namespace sqc { namespace utils {
#define END_NAMESPACE_SQC_UTILS }}

NAMESPACE_SQC_UTILS

sqc_string format_string_by_values( sqc_string const &s, std::map<sqc_string, int> const &values );

// как пользоваться функцией format_string_by_values
// задаем мэп - ключ / индекс варианта
// ищем в исходной строке блоки на замену вида [key:value_0|value_1|.....|value_n]
// если в мэпе есть нужный ключ, то выбирается вариант с заданным индексом
// если в мэпе ключа нет, то весь блок вырезается
// также он вырезается, когда вариантов меньше заданного индекса
//
//    std::map<sqc_string, int> values;
//    values["sex"] = 1;
//    values["phrase"] = 2;
//
//    sqc_string str = "Ура, я [sex:получил|получила] новый уровень, [phrase:а ты так сможешь?|появилась куча новых объектов.|играть стало веселее!]";
//    sqc_string res = sqc::utils::format_string_by_values(str, values);
// 
// т.е. в данном примере результатом будет "Ура, я получила новый уровень, играть стало веселее!"

void process_description_string( sqc_string &description );

void parse_map_string_into_map( sqc_string const &s, sqc_string_map &m );

// парсинг строк вида {type: field, klass: warehouse, count: 1, min_stage: 60} в map

void get_values_list( sqc_string const &s, size_t s_from, size_t s_to, const char* delimiter, std::vector<sqc_string> &values );

// разбивка строки на подстроки по разделителю

END_NAMESPACE_SQC_UTILS

#endif //__SQC_UTILS_INCLUDED__
