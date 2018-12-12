/*
 *  sqc_file_api.cpp
 *  configurator
 *
 *  Created by Andrey Yamov on 5/17/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_file_api.h"
#include <sys/stat.h>

NAMESPACE_SQC_FILE_API

sqc_string append_path( sqc_string const &path, sqc_string const &name ) {
    sqc_string  result( path );
    if( name.empty() ) {
        return path;
    }
    if( result.empty() || *result.rbegin() != '/' ) {
        result += '/';
    }
    if( *name.begin() == '/' ) {
        result += name.c_str()+1;
    }
    else {
        result += name;
    }
    return result;
}

sqc_string get_directory( sqc_string const &path ) {
    size_t idx = path.rfind( '/' );
    if( idx != -1 ) {
        return path.substr( 0, idx );
    }
    else {
        return "/";
    }
}

sqc_string get_filename( sqc_string const &path ) {
    size_t idx = path.rfind( '/' );
    if( idx != -1 ) {
        return path.substr( idx+1, path.size() );
    }
    else {
        return path;
    }
}

bool file_exist( sqc_string const &path ) {
    std::ifstream tester( path.c_str(), std::ifstream::in );
    if( !tester ) {
        return false;
    }
    return true;
}

bool read_text_file( sqc_string const &path, sqc_string &content ) {
    std::string line;
    std::ifstream in( path.c_str(), std::ios_base::binary );
    
    if( !in ) {
        return false;
    }
    
    in.seekg( 0, std::ios_base::end );
    size_t length = in.tellg();
    in.seekg( 0, std::ios_base::beg );
    
    content.resize( length );
    in.read( &content[0], content.size() );
    
    /*
    
    while( std::getline( in, line ) ) {
        if( !content.empty() ) content += "\n";
        content += line;
    }
     */
    
    return true;
}

bool write_text_file( sqc_string const &path, sqc_string const &content ) {
    std::ofstream f( path.c_str(), std::ios_base::binary );
    if( !f ) {
        return false;
    }
    
    f << content;
    return true;
}

sqc_string get_resource_path( sqc_string const &name, sqc_string const &type ) {
    assert( !g_path_to_rsc.empty() );
    sqc_string  path = append_path( g_path_to_rsc, name );
    if( !type.empty() ) {
        path += ".";
        path += type;
    }

    return path;
}

sqc_string get_documents_path( sqc_string const &name, sqc_string const &type ) {
    assert( !g_path_to_doc.empty() );
    sqc_string  path = append_path( g_path_to_doc, name );
    if( !type.empty() ) {
        path += ".";
        path += type;
    }
    
    return path;
}

#if defined( JMSF_WINDOWS )
#else // #ifdef _WIN32
bool create_directory( sqc_string const &path ) {
    return mkdir(path.c_str(), 0777) == 0;
}
#endif // #ifdef _WIN32

sqc_string  g_path_to_app;
sqc_string  g_path_to_rsc;
sqc_string  g_path_to_doc;




END_NAMESPACE_SQC_FILE_API
