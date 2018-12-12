#pragma once

#include "storage_file.h"
#include "storage_container.h"
#include "storage_access.h"
#include "stl_container_storing.hpp"

namespace sqc {
namespace named_storing {

class test_data {

public:
	test_data() {
		value = 0;
	}

	test_data( const wchar_t *sz, int n ) {
		text = sz;
		value = n;
	}

	bool store( storage_container &storage, storage_access *section ) const {
        storage.store_value( "text", section, text );
        storage.store_value( "value", section, value );
//      set_string_value( storage, "text", section, text );
// 		set_value( storage, "value", section, value );
		return true;
	}

	bool load( storage_container &storage, storage_access *section ) {
        storage.query_value( "text", section, text );
        storage.query_value( "value", section, value );
// 		get_string_value( storage, "text", section, text, storage_access_ptr() );
// 		get_value( storage, "value", section, value, storage_access_ptr() );
		return true;
	}

	bool operator == ( const test_data &o ) const {
		if( value != o.value )return false;
		if( text != o.text )return false;
		return true;
	}
	bool operator != ( const test_data &o ) const {
		return !(*this == o);
	}
private:
	std::wstring	text;
	int				value;
};

// тест на карту строк
inline long test_names() {
	storage_names names;
	name_id	id1 = names.set_name( "abc" );
	name_id	id2 = names.set_name( "bcd" );
	name_id	id3 = names.set_name( "abc" );

	if( id1 == id2 )
		return 1;
	if( id1 != id3 )
		return 2;

	name_id	id4 = names.get_name_id( "bcd" );
	if( id4 != id2 )
		return 3;

	name_id	id5 = names.get_name_id( "cde" );
	if( id5 != NO_NAME )
		return 4;

	return 0;
}

// тест на карту строк
inline long test_names_len() {
	storage_names	names;
	name_id	id1  = names.set_name( "object" );
	name_id	id2  = names.set_name( "object2nd" );

	if( id1 == id2 )
		return 1;

	name_id	id1f = names.get_name_id( "object" );
	if( id1f != id1 ) 
		return 2;

	name_id	id2f = names.get_name_id( "object2nd" );
	if( id2f != id2 ) 
		return 3;

	return 0;
}

inline long test_sections() {
	storage_container storage;

	storage_access *psect = storage.open_section( "section1", 0 );
	if( psect )return 1;

	storage_access *psect2 = storage.create_section( "section1", 0 );
	if( !psect2 )return 2;

	storage_access *psect3 = storage.create_section( "section2", psect2 );
	if( !psect3 )return 3;

	storage.close_section( psect2 );
	storage.close_section( psect3 );

	psect = storage.open_section( "section1/section2", 0 );
	if( !psect )return 4;
	storage.close_section( psect );

	psect = storage.open_section( "section1", 0 );
	if( !psect )return 5;

	psect2 = storage.open_section( "section2", psect );
	if( !psect2 )return 6;

	storage.close_section( psect2 );
	storage.close_section( psect );

	return 0;
}

inline long test_multi_section() {
	storage_container storage;

	storage_access *p1 = storage.create_section( "a1", 0, true );
	storage_access *p2 = storage.create_section( "a1", 0, true );
	storage_access *p3 = storage.create_section( "a1", 0, true );

	storage.close_section( p1 );
	storage.close_section( p2 );
	storage.close_section( p3 );

	int	count = 0;

	for ( storage_access *paccess = storage.open_section( "a1", 0 ); paccess; paccess = paccess->get_next_section() ) {
		count++;
	}

	if ( count != 3 )
		return 1;

	return 0;
}

inline long test_set_value() {
	const std::wstring www = L"123";
	if ( www != L"123" ) return -1000;

	storage_container storage;

	storage_access	*p = storage.create_section( "aaa", 0 );
	if ( !p->store_value( "bool", bool( true ) ) )return 1;
	if ( !p->store_value( "byte", byte_t( 2 ) ) )return 2;
	if ( !p->store_value( "word", short int( 3 ) ) )return 3;
	if ( !p->store_value( "dword", unsigned int( 4 ) ) )return 4;
	if ( !p->store_value( "long", long int( 5 ) ) )return 5;
	if ( !p->store_value( "string", std::string( "qwe" ) ) )return 6;
	if ( !p->store_value( "wstring", std::wstring( L"qwe1" ) ) )return 7;

	bool val1 = bool();
	byte_t val2 = byte_t();
	short val3 = short();
	unsigned int val4 = unsigned int();
	long int val5 = long int();
	std::string val6;
	std::wstring val7;

	if( !p->query_value( "bool", val1 ) ) return 11;
	if( !p->query_value( "byte", val2 ) ) return 12;
	if( !p->query_value( "word", val3 ) ) return 13;
	if( !p->query_value( "dword", val4 ) ) return 14;
	if( !p->query_value( "long", val5 ) ) return 15;
	if( !p->query_value( "string", val6 ) ) return 16;
	if( !p->query_value( "wstring", val7 ) ) return 17;

	if( val1 != true )return 21;
	if( val2 != 2 )return 22;
	if( val3 != 3 )return 23;
	if( val4 != 4 )return 24;
	if( val5 != 5 )return 25;
	if( val6 != "qwe" )	return 26;
	if( val7 != L"qwe1" )	return 27;


	storage.close_section( p );

	return 0;
}

inline long test_multi_value() {
	storage_container storage;
	storage_access *p = storage.create_section( "aaa", 0 );

	std::string	value( "1" );
	p->store_value( "val", value, true ); 

	value += "2";
	p->store_value( "val", value, true ); 
	
	value += "3";
	p->store_value( "val", value, true ); 

	storage.close_section( p );

	storage_access *pr = storage.create_section( "aaa", 0 );

	std::string str;

	int n = 0;
	storage_access_ptr access_iterator;
	for ( bool read = pr->query_value( "val", str, access_iterator ); read; read = pr->query_value( "", str, access_iterator ) ) {
		str = str;
		n++;
	}

	storage.close_section( pr );

	if( n != 3 )return 1;

	return 0;
}


long test_load_store() {
	storage_container storage;

	std::vector<test_data>	arr, arr_load;
	arr.push_back( test_data( L"test1", 111 ) );
	arr.push_back( test_data( L"test2", 112 ) );
	arr.push_back( test_data( L"test3", 113 ) );
	arr.push_back( test_data( L"test4", 114 ) );
	arr.push_back( test_data( L"test5", 115 ) );

	set_to_storage( storage, "aaa", 0, arr );

	get_from_storage( storage, "aaa", 0, arr_load );

	if( arr != arr_load ) return 1;

	return 0;
}

inline long test_pack_unpack() {
	std::vector< byte_t > out;
	std::vector< test_data > arr;
    std::vector< test_data > arr_load;
	arr.push_back( test_data( L"test1", 111 ) );
	arr.push_back( test_data( L"test2", 112 ) );
	arr.push_back( test_data( L"test3", 113 ) );
	arr.push_back( test_data( L"test4", 114 ) );
	arr.push_back( test_data( L"test5", 115 ) );

	{
		storage_container storage;

		if( !set_to_storage( storage, "aaa", 0, arr ) )return 1;

		if( !storage.pack( out ) ) return 2;
	}

	{
		storage_container storage;

		if( !storage.unpack( &out[0], out.size() ) ) return 10;

		if( !get_from_storage( storage, "aaa", 0, arr_load ) )return 11;

		if( arr != arr_load ) return 12;
	}

	return 0;
}

inline long test_file_storage() {
	std::vector< byte_t > out;
	std::vector< test_data > arr;
    std::vector< test_data > arr_load;
	arr.push_back( test_data( L"test1", 111 ) );
	arr.push_back( test_data( L"test2", 112 ) );
	arr.push_back( test_data( L"test3", 113 ) );
	arr.push_back( test_data( L"test4", 114 ) );
	arr.push_back( test_data( L"test5", 115 ) );

	{
		storage_file file;
		file.init( "test1.bin" );

		if( !set_to_storage( file.get_storage() , "aaa", 0, arr ) )return 1;

		if( !file.write() ) {
			return 2;
		}
	}

	{
		storage_file	file;
		file.init( "test1.bin" );

		if( !file.read() ) {
			return 10;
		}


		if( !get_from_storage( file.get_storage(), "aaa", 0, arr_load ) ) {
			return 11;
		}

		if( arr != arr_load ) {
			return 12;
		}
	}

	return 0;
}

} // namespace named_storing
} // namespace sqc
