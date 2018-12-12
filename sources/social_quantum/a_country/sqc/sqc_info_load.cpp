/*
 *  sqc_info_load.cpp
 *  configurator
 *
 *  Created by Andrey Yamov on 5/17/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_info_load.h"

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
#include "sqc/sqc_locale_parser.h"
#endif

#include "sqc/named_storing/storage_container.h"
#include "sqc/named_storing/storage_file.h"
#include "sqc/named_storing/storage_access.h"

NAMESPACE_SQC_INFO
//
// load class factory 
//
bool load_hierarchy( sqc_string const &path, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, sqc_version_provider_ptr version_provider ) {
    try {
        std::cout << "loading class hierarchy... from path " << path << std::endl;
        
        using namespace yaml;
        
        sqc_yaml_doc    doc;
        if( !doc.parse( path.c_str() ) ) {
            std::cout << "Error load hierarchy: no file found or failed to parse" << std::endl;
            return false;
        }
        
        sqc_yaml_node_ptr   root_node = doc.get_root();
        if( !root_node ) {
            std::cout << "Error load hierarchy: file is empty" << std::endl;
            return false;
        }
        
        sqc_yaml_node_ptr   hierarchy = root_node->find( "hierarchy" );
        if( hierarchy ) {
            class_factory->load( hierarchy );
        }
        
        sqc_yaml_node_ptr   drawing = root_node->find( "drawing" );
        if( drawing ) {
            drawing_provider->load( drawing );
        }
        
        version_provider->load(root_node);
        
        std::cout << "OK!" << std::endl;
    } 
    catch(std::exception const &e) {
        std::cerr << "FAILED" << std::endl;
        std::cerr << e.what() << "\n";
        
        return false;
    }
    
    return true;
}

//
// load the items information
//
#if defined SQC_CONFIGURATOR
bool compare_binary_object_information( sqc_object_info_provider_ptr first_object_information_provider, sqc_object_info_provider_ptr second_object_information_provider ) {
    const sqc_string_list first_object_name_list = first_object_information_provider->get_object_names();
    const sqc_string_list second_object_name_list = second_object_information_provider->get_object_names();

    for ( sqc_string_list::const_iterator second_object_name_iterator = second_object_name_list.begin(); second_object_name_iterator != second_object_name_list.end(); ++second_object_name_iterator ) {
        if ( !first_object_information_provider->get_object_info( second_object_name_iterator->c_str() )->is_equal_to( *second_object_information_provider->get_object_info( second_object_name_iterator->c_str() ) ) ) {
            return false;
        }
    }

    return true;
}

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
bool load_objects( sqc_string const &path, sqc_object_info_provider_ptr class_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, const sqc_string &path_to_object_descriptions ) {
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
bool load_objects( sqc_string const &path, sqc_object_info_provider_ptr class_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider ) {
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
    try {
        std::cout << "loading objects... from path " << path << std::endl;
        
        using namespace yaml;
        
        sqc_yaml_doc    doc;
        if( !doc.parse( path.c_str() ) ) {
            std::cout << "Error load objects: no file found or failed to parse" << std::endl;
            return false;
        }
        
        sqc_yaml_node_ptr   root_node = doc.get_root();
        if( !root_node ) {
            std::cout << "Error load objects: file is empty" << std::endl;
            return false;
        }

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
		sqc::sqc_locale_file_loader locale_file_loader( path_to_object_descriptions );
		sqc::sqc_locale_parser locale_parser;
		locale_parser.init( locale_file_loader );        
        class_provider->load( root_node, class_factory, drawing_provider, locale_parser );
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
        class_provider->load( root_node, class_factory, drawing_provider );
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
        std::cout << "OK!" << std::endl;
    } 
    catch(std::exception const &e) {
        std::cerr << "FAILED" << std::endl;
        std::cerr << e.what() << "\n";
        
        return false;
    }
    
    return true;
}

bool write_binary_object_information( const sqc_string &path_to_file, sqc_object_info_provider_ptr object_information_provider ) {
    named_storing::storage_file named_storage_file;
    named_storage_file.init( path_to_file );
    const sqc_string_list object_name_list = object_information_provider->get_object_names();
    named_storing::storage_container &named_storage = named_storage_file.get_storage();
    
    for ( sqc_string_list::const_iterator object_name_iterator = object_name_list.begin(); object_name_iterator != object_name_list.end(); ++object_name_iterator ) {
        const sqc_object_info *object_information = object_information_provider->get_object_info( object_name_iterator->c_str() );
        named_storing::storage_access *named_section = named_storage.create_section( "object_entry", 0, true );

        if ( named_section == nullptr ) return false;

        // writing object type name
        if ( !named_section->store_value( "name_of_class", object_information->get_type_name() ) ) return false;

        // writing object superclass name
        if ( !named_section->store_value( "name_of_superclass", object_information->get_superclass_name() ) ) return false;

        if ( !object_information->write_to( named_section ) ) return false;

        if ( !named_storage.close_section( named_section ) ) return false;
    }

    return named_storage_file.write();
}
#endif // #if defined SQC_CONFIGURATOR

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
bool read_binary_object_information( const sqc_string &path_to_file, sqc_object_info_provider_ptr object_information_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, const sqc_string &path_to_object_descriptions, sqc_version_provider_ptr version_provider ) {
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
bool read_binary_object_information( const sqc_string &path_to_file, sqc_object_info_provider_ptr object_information_provider, sqc_class_factory_ptr class_factory, sqc_drawing_provider_ptr drawing_provider, sqc_version_provider_ptr version_provider ) {
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
    named_storing::storage_file named_storage_file;
    named_storage_file.init( path_to_file );

    if ( !named_storage_file.read( true ) ) return false;

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
		sqc::sqc_locale_file_loader locale_file_loader( path_to_object_descriptions );
		sqc::sqc_locale_parser locale_parser;
		locale_parser.init( locale_file_loader );        
		if ( !object_information_provider->read_from( named_storage_file.get_storage(), class_factory, drawing_provider, locale_parser, version_provider ) ) return false;
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
		if ( !object_information_provider->read_from( named_storage_file.get_storage(), class_factory, drawing_provider, version_provider ) ) return false;
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION

    return true;
}

END_NAMESPACE_SQC_INFO
