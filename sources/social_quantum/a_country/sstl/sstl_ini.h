/*
 *  sstl_ini.h
 *  aCountry
 *
 *  Created by paul K on 10/27/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __SSTL_INI_H_INCLUDED__
#define __SSTL_INI_H_INCLUDED__

#include "sstl_defs.h"
#include <map>
#include <string>

NAMESPACE_SSTL

typedef std::string sstl_string;
typedef std::string sstl_path;

static const sstl_string empty_string;

class sstl_ini {
public:
	sstl_ini();
    virtual ~sstl_ini();
    
    bool			open( const sstl_path& path );
	
    sstl_string		read_string_value( const sstl_string& section,
                                       const sstl_string& key,
                                       const sstl_string& def = empty_string ) const;
                                       
    int				read_int_value( const sstl_string& section,
    								const sstl_string& key,
                                    const int def = 0 ) const;
    
protected:

    typedef std::map<sstl_string,sstl_string>	value_map;
    
	struct section {
    	sstl_string	name;
        value_map	values;
        void reset() {
        	name.clear();
            values.clear();
        }
    };
    
    typedef std::map<sstl_string,section>	section_map;
    
    section_map	sections;

};

END_NAMESPACE_SSTL

#endif//__SSTL_INI_H_INCLUDED__