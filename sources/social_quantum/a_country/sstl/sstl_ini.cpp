/*
 *  sstl_ini.cpp
 *  aCountry
 *
 *  Created by paul K on 10/27/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "sstl_ini.h"
#include <iostream> 
#include <fstream>
#include <stdlib.h>

NAMESPACE_SSTL

sstl_ini::sstl_ini() {
}

sstl_ini::~sstl_ini() {
}
    
 bool sstl_ini::open( const sstl_path& path ) {
 
	std::ifstream ifs;
    ifs.open( path.c_str(), std::ifstream::in );
	if ( !ifs.good() ) {
    	return false;
    }
    
    sstl_ini::section	section;
    std::string line;
    while ( std::getline( ifs, line ) ) {
    	if ( line.empty() ) {
        	continue;
        }
        
        if ( line[0] == ';' || line[0] == '#' ) {
        	continue;
        }
        
        // next section
        if ( line[0] == '[' ) {
        	
            // store prev section
            if ( !section.name.empty() ) {
            	sections[section.name] = section;
            }
            section.reset();
            
            
            if ( line.size() < 2 ) {
            	continue;
            }
            
            line = line.substr( 1 );
            
            size_t idx = line.find( ']' );
            if ( -1 == idx ) {
            	// wrong section
            	continue;
            }
            line.resize( idx );
            section.name = line;
            continue;
        }
        
        size_t idx = line.find( '=' );
        if ( -1 == idx ) {
        	// wrong key
        	continue;
        }
        sstl_string str_key = line;
        str_key.resize( idx );
        
        sstl_string str_value;
        if ( idx < line.size() ) {
	         str_value = line.substr( idx + 1 );
        }
        
        section.values[str_key] = str_value;
    }
    
    if ( !section.name.empty() ) {
        sections[section.name] = section;
    }
    
	return true;
 }
	
sstl_string	sstl_ini::read_string_value(
	const sstl_string& section_name,
    const sstl_string& key_name,
    const sstl_string& def ) const {

	section_map::const_iterator it_section = sections.find( section_name );
    if ( it_section == sections.end() ) {
    	return def;
    }
    
    const sstl_ini::section& section = it_section->second;
    
    value_map::const_iterator it_value = section.values.find( key_name );
    if ( it_value == section.values.end() ) {
    	return def;
    }
    
    return it_value->second;
}

int	sstl_ini::read_int_value(
	const sstl_string& section_name,
    const sstl_string& key_name,
    const int def ) const {

	section_map::const_iterator it_section = sections.find( section_name );
    if ( it_section == sections.end() ) {
    	return def;
    }
    
    const sstl_ini::section& section = it_section->second;
    
    value_map::const_iterator it_value = section.values.find( key_name );
    if ( it_value == section.values.end() ) {
    	return def;
    }
    
    return atoi( it_value->second.c_str() );
}

END_NAMESPACE_SSTL