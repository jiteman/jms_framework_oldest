#pragma once

#if !defined( JMSF_WINDOWS )
#if !defined nullptr
#define nullptr NULL
#endif // #if !defined nullptr
#endif // #if !defined _WIN32

#include <string>
//#include <guiddef.h>

namespace sqc {
namespace named_storing {

#if defined( JMSF_WINDOWS )
	typedef __int64 integer_64;
	typedef unsigned __int64 unsigned_integer_64;
#else
	typedef long long integer_64;
	typedef unsigned long long unsigned_integer_64;
#endif
	
    
typedef	unsigned char byte_t;
typedef unsigned short int word_t;
typedef unsigned int dword_t;
typedef unsigned_integer_64 qword_t;    
typedef char char_t;
typedef std::string string_t;


typedef	short name_id;
const name_id NO_NAME = (name_id)-1;

// тип записи хранилища
enum entry_type {
	// неизвестный тип записи
	entry_type_unknown = 0xFF,

	// секция
	entry_type_section = 0,

	// булевское значение
	entry_type_bool,

	// байт
	entry_type_byte,

	// слово
	entry_type_word,

	// двойное слово
	entry_type_dword,

	// 64-битное значение
	entry_type_qword,

	// GUID
	entry_type_guid,

	// обычная строка
	entry_type_string,

	// unicode строка
	entry_type_wstring,

	// неизвестный указатель
	entry_type_raw,
};

class entry_type_identifier {

public:
    static entry_type get_type_for( const bool );
    static entry_type get_type_for( const byte_t );
    static entry_type get_type_for( const signed char );
    static entry_type get_type_for( const word_t );
    static entry_type get_type_for( const signed short int );
    static entry_type get_type_for( const dword_t );
    static entry_type get_type_for( const signed int );
    static entry_type get_type_for( const unsigned long int );
    static entry_type get_type_for( const signed long int );
    static entry_type get_type_for( const qword_t );
    static entry_type get_type_for( const integer_64 );
//    static entry_type get_type_for( const GUID & );
    static entry_type get_type_for( const std::string & );
//    static entry_type get_type_for( const std::wstring & );

    template< class A_type >
    static entry_type get_type_for( const A_type &value );

private:
    entry_type_identifier() {}
};

template< class A_type >
// static
entry_type entry_type_identifier::get_type_for( const A_type &value ) {
    return entry_type_raw;
}


} // namespace named_storing
} // namespace sqc
