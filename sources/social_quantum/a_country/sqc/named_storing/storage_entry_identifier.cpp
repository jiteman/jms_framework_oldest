#include "storage_entry_identifier.h"

namespace sqc {
namespace named_storing {

// static
entry_type entry_type_identifier::get_type_for( const bool ) {
    return entry_type_bool;
}

// static
entry_type entry_type_identifier::get_type_for( const byte_t ) {
    return entry_type_byte;
}

// static
entry_type entry_type_identifier::get_type_for( const signed char ) {
    return entry_type_byte;
}

// static
entry_type entry_type_identifier::get_type_for( const word_t ) {
    return entry_type_word;
}

// static
entry_type entry_type_identifier::get_type_for( const signed short int ) {
    return entry_type_word;
}

// static
entry_type entry_type_identifier::get_type_for( const dword_t ) {
    return entry_type_dword;
}

// static
entry_type entry_type_identifier::get_type_for( const signed int ) {
    return entry_type_dword;
}

// static
entry_type entry_type_identifier::get_type_for( const unsigned long int ) {
    return entry_type_dword;
}

// static
entry_type entry_type_identifier::get_type_for( const signed long int ) {
    return entry_type_dword;
}

// static
entry_type entry_type_identifier::get_type_for( const qword_t ) {
    return entry_type_qword;
}

// static
entry_type entry_type_identifier::get_type_for( const integer_64 ) {
    return entry_type_qword;
}

/* // static
entry_type entry_type_identifier::get_type_for( const GUID & ) {
    return entry_type_guid;
} */

// static
entry_type entry_type_identifier::get_type_for( const std::string & ) {
    return entry_type_string;
}

// static
//entry_type entry_type_identifier::get_type_for( const std::wstring & ) {
//    return entry_type_wstring;
//}

} // namespace named_storing
} // namespace sqc
