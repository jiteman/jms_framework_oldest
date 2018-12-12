/*
 *  sqc_locale.cpp
 *  aCountry
 *
 *  Created by Eugene Shaluhin on 8/8/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#include "sqc_locale_parser.h"

NAMESPACE_SQC

// static
const sqc_string sqc_locale_parser::EMPTY_STRING;

bool sqc_locale_parser::init( sqc_locale_file_loader &loader ) {
	if ( loader.is_end_of_file() ) return false;

	sqc_string key;
	sqc_string value;

	while ( !loader.is_end_of_file() ) {
		if ( loader.get_key_and_value( key, value ) ) {
			append( key, value );
		}
	}
	
	return true;
}

const sqc_string &sqc_locale_parser::get_string( const std::string &key ) {
	const sqc_const_string_map::const_iterator matchedStringIterator = m_strings.find( key );
	
	if ( matchedStringIterator != m_strings.end() ) {
		return matchedStringIterator->second;
	} else {
		return EMPTY_STRING;
	}
}

void sqc_locale_parser::append( const sqc_string &key, const sqc_string &value ) {
	m_strings.insert( sqc_make_pair( key, value ) );
}


//==================================================================================
sqc_locale_file_loader::sqc_locale_file_loader( const sqc_string &pathToFile )
	:
		m_locale_file( pathToFile.c_str() )
{}

bool sqc_locale_file_loader::is_end_of_file() const {
	return !m_locale_file.is_open() || !m_locale_file.good();
}

bool sqc_locale_file_loader::get_key_and_value( sqc_string &out_key, sqc_string &out_value ) {
	if ( is_end_of_file() ) return false;

	const char quotes = '\"';

    sqc_string line_string;
    std::getline( m_locale_file, line_string );

	const size_t keyStartQuotesPosition = line_string.find_first_of( quotes );

	if ( keyStartQuotesPosition == std::string::npos ) return false;

	const size_t keyEndQuotesPosition = line_string.find_first_of( quotes, keyStartQuotesPosition + 1);

	if ( keyEndQuotesPosition == std::string::npos ) return false;

	const size_t valueStartQuotesPosition = line_string.find_first_of( quotes, keyEndQuotesPosition + 1 );

	if ( valueStartQuotesPosition == std::string::npos ) return false;

	const size_t valueEndQuotesPosition = line_string.find_last_of( quotes );

	if ( valueEndQuotesPosition == std::string::npos ) return false;

	out_key = line_string.substr( keyStartQuotesPosition + 1, keyEndQuotesPosition - keyStartQuotesPosition - 1 );
	sqc_string tempo = line_string.substr( valueStartQuotesPosition + 1, valueEndQuotesPosition - valueStartQuotesPosition - 1 );
    
    sqc_string nbsp = "&nbsp;";
    sqc_string no_break_space = "\u00A0";
    
    enum  {
        state_normal,
        state_wait_special
    }
    state = state_normal;
    
    out_value.clear();
    
    for (sqc_string::iterator it = tempo.begin(); it != tempo.end(); ++it) {
        if( state == state_normal ) {
            if( *it == '\\' ) {
                state = state_wait_special;
                continue;
            }
            else if( *it == nbsp[0] 
                      && *(it + 1) == nbsp[1] 
                      && *(it + 2) == nbsp[2] 
                      && *(it + 3) == nbsp[3] 
                      && *(it + 4) == nbsp[4] 
                      && *(it + 5) == nbsp[5] ) {
                it += nbsp.size()-1;
                out_value += no_break_space;
                continue;
            }
            else {
                out_value.push_back( *it );
            }
        }
        else if( state == state_wait_special ) {
            if( *it == '"' ) {
                out_value.push_back( '"' );
            }
            else if( *it == 'n' ) {
                out_value.push_back( 'n' );
            }
            else if( *it == 'L' ) {
                // ???
                // out_value.push_back( 'L' );
            } 
            else if( *it == '\\' ) {
                out_value.push_back( '\\' );
            } 
            else {
                //assert( false );
            }
            state = state_normal;
                
        }
    }
    
	return true;
}

END_NAMESPACE_SQC
