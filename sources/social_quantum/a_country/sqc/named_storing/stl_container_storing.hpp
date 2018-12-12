#pragma once

#include "storage_container.h"
#include "storage_access.h"
#include <string>

namespace sqc {
namespace named_storing {

template< class A_type >
bool store_vector( storage_access *named_section, const std::string &name_of_section, const std::string &name_of_value, const A_type &the_vector ) {
	storage_access *vector_section = named_section->create_section( name_of_section );

	if ( vector_section == nullptr ) return false;

	for ( typename A_type::const_iterator vector_iterator = the_vector.begin(); vector_iterator != the_vector.end(); ++vector_iterator ) {
		if ( !vector_section->store_value( name_of_value, *vector_iterator, true ) ) {
			vector_section->close();
			return false;
		}
	}

	return vector_section->close();
}

template< class A_type >
bool query_vector( storage_access *named_section, const std::string &name_of_section, const std::string &name_of_value, A_type &the_vector ) {
	storage_access *vector_section = named_section->open_section( name_of_section );

	if ( vector_section == nullptr ) return false;

	typename A_type::value_type type_value = typename A_type::value_type();
	storage_access_ptr access_iterator;

	for (
		bool is_found = vector_section->query_value( name_of_value, type_value, access_iterator );
		is_found;
		is_found = vector_section->query_value( "", type_value, access_iterator ) )
	{
		the_vector.push_back( type_value );
	}

	return vector_section->close();
}

template< class A_type >
bool store_pair( storage_access *named_section, const std::string &name_of_section, const std::string &name_of_key_value, const std::string &name_of_mapped_value, const A_type &the_pair ) {
	storage_access *pair_section = named_section->create_section( name_of_section, true );

	if ( pair_section == nullptr ) return false;

	if ( !pair_section->store_value( name_of_key_value, the_pair.first ) ) {
		pair_section->close();
		return false;
	}

	if ( !pair_section->store_value( name_of_mapped_value, the_pair.second ) ) {
		pair_section->close();
		return false;
	}

	return pair_section->close();
}

template< class A_key_type, class A_mapped_type >
bool query_pair( storage_access *named_section, const std::string &name_of_key_value, const std::string &name_of_mapped_value, A_key_type &the_key_value, A_mapped_type &the_mapped_value ) {
	if ( !named_section->query_value( name_of_key_value, the_key_value ) ) return false;

	if ( !named_section->query_value( name_of_mapped_value, the_mapped_value ) ) return false;

	return true;
}

template< class A_type >
bool store_map( storage_access *named_section, const std::string &name_of_section, const std::string &name_of_pair_section, const std::string &name_of_first_value, const std::string &name_of_second_value, const A_type &the_map ) {
	storage_access *map_section = named_section->create_section( name_of_section, true );

	if ( map_section == nullptr ) return false;

	for ( typename A_type::const_iterator map_iterator = the_map.begin(); map_iterator != the_map.end(); ++map_iterator ) {
		if ( !store_pair( map_section, name_of_pair_section, name_of_first_value, name_of_second_value, *map_iterator ) ) {
			map_section->close();
			return false;
		}
	}

	return map_section->close();
}

template< class A_type >
bool query_map( storage_access *named_section, const std::string &name_of_section, const std::string &name_of_pair_section, const std::string &name_of_key_value, const std::string &name_of_mapped_value, A_type &the_map ) {
    storage_access *map_section = name_of_section.empty() ? named_section : named_section->open_section( name_of_section );

    if ( map_section == nullptr ) return false;

	for (
		storage_access *pair_section = map_section->open_section( name_of_pair_section );
		pair_section != nullptr;
		pair_section = pair_section->get_next_section() )
	{
		typename A_type::key_type the_key_value;
		typename A_type::mapped_type the_mapped_value;

		if ( !query_pair( pair_section, name_of_key_value, name_of_mapped_value, the_key_value, the_mapped_value ) ) {
			map_section->close();
			return false;
		}

		the_map.insert( std::make_pair( the_key_value, the_mapped_value ) );
	}

	return name_of_section.empty() ? true : map_section->close();
}

template< class A_type >
bool store_vector_of_maps(
	storage_access *named_section,
	const std::string &name_of_section,
	const std::string &name_of_map_section,
	const std::string &name_of_pair_section,
	const std::string &name_of_first_value,
	const std::string &name_of_second_value,
	const A_type &the_vector_of_maps )
{
	storage_access *vector_of_maps_section = named_section->create_section( name_of_section );

	if ( vector_of_maps_section == nullptr ) return false;

	for ( typename A_type::const_iterator vector_of_maps_iterator = the_vector_of_maps.begin(); vector_of_maps_iterator != the_vector_of_maps.end(); ++vector_of_maps_iterator ) {
		if ( !store_map( vector_of_maps_section, name_of_map_section, name_of_pair_section, name_of_first_value, name_of_second_value, *vector_of_maps_iterator ) ) {
			vector_of_maps_section->close();
			return false;
		}
	}

	return vector_of_maps_section->close();
}

template< class A_type >
bool query_vector_of_maps(
	storage_access *named_section,
	const std::string &name_of_section,
	const std::string &name_of_map_section,
	const std::string &name_of_pair_section,
	const std::string &name_of_first_value,
	const std::string &name_of_second_value,
	A_type &the_vector_of_maps )
{
    storage_access *vector_of_maps_section = named_section->open_section( name_of_section );

    if ( vector_of_maps_section == nullptr ) return false;

	for (
		storage_access *map_section = vector_of_maps_section->open_section( name_of_map_section );
		map_section != nullptr;
		map_section = map_section->get_next_section() )
	{
		typename A_type::value_type map_value;

		if ( !query_map( map_section, std::string(), name_of_pair_section, name_of_first_value, name_of_second_value, map_value ) ) {
			vector_of_maps_section->close();
			return false;
		}

		the_vector_of_maps.push_back( map_value );
	}

	return true;
}

// сохранение массива в хранилище
template< class T >
bool set_to_storage( storage_container &storage, const std::string &entry, storage_access *section, const T &values ) {
	typedef	T	container;

	for( typename container::const_iterator i = values.begin(); i != values.end(); ++i ) {
		storage_access *p = storage.create_section( entry, 0, true );
		i->store( storage, p );
		storage.close_section( p );
	}

	return true;
}

// загрузка массива из хранилища
template< class T >
bool get_from_storage( storage_container &storage, const std::string &entry, storage_access *section, T &values ) {
	typedef	T	container;
	typedef	typename T::value_type	value_type;
	values.clear();

	for( storage_access *p = storage.open_section( entry, section ); p; p = storage.get_next_section( p ) ){
		value_type	new_item;
		new_item.load( storage, p );
		values.push_back( new_item );
	}

	return true;
}

} // namespace named_storing
} // namespace sqc
