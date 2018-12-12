/*
 *  sqc_locale.h
 *  aCountry
 *
 *  Created by Eugene Shaluhin on 8/8/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */


#ifndef __SQC_LOCALE_PARSER_H_INCLUDED_
#define __SQC_LOCALE_PARSER_H_INCLUDED_

#include "sqc_defs.h"

NAMESPACE_SQC

class sqc_locale_file_loader;

class sqc_locale_parser {

public:
	static const sqc_string EMPTY_STRING;

public:
	bool init( sqc_locale_file_loader &loader );	
	const sqc_string &get_string( const sqc_string &key );

private: friend class sqc_testing_locale_parser_appender;
	void append( const sqc_string &key, const sqc_string &value );
	
private:
	sqc_const_string_map m_strings;

};

class sqc_locale_file_loader {

public:
	sqc_locale_file_loader( const sqc_string &path_to_file );
	bool is_end_of_file() const;
	bool get_key_and_value( sqc_string &key, sqc_string &value );

private:
	sqc_ifstream m_locale_file;
};

END_NAMESPACE_SQC

#endif /*__SQC_LOCALE_PARSER_H_INCLUDED_*/
