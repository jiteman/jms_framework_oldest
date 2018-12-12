/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_formats.h"

NAMESPACE_SQC_FRAMEWORK

sqc_formats::sqc_formats() {
}

sqc_formats::~sqc_formats() {
}

// format as 1 000
sqc_string sqc_formats::format_digit_grouping( const sqc_ddword size ) const {
	sqc_string		tempo;
	{
		sqc_stringstream tempo_stream;
		tempo_stream << size;
		tempo = tempo_stream.str();
	}
    
	sqc_string out;
	int i = 0;
	for ( sqc_string::reverse_iterator it = tempo.rbegin();
		 it != tempo.rend(); ++it ) {
		
		out.push_back( *it );
		
		if ( i++ == 2 && it != --tempo.rend() ) {
			out.push_back( sqc_text(' ') );
			i = 0;
		}
	}
	
	std::reverse( out.begin(), out.end() );
    return out;
}


// format as 1K, 1M, etc
sqc_string sqc_formats::format_digit_compact( const sqc_ddword val ) const {
 	sqc_string	metric;
	sqc_ddword res = val;
    
    if ( res < 1000 ) {
    	//do nothing
    } else if ( res < 1000*1000 ) {
    	res /= 1000;
        metric = sqc_text("K");
    } else if ( res < 1000*1000*1000 ) { 
    	res /= 1000 * 1000;
        metric = sqc_text("M");
    }

	sqc_stringstream out;
	out << res << metric;
	return out.str();
};


// 
// format as percent
sqc_string sqc_formats::format_percent( const int percent ) const {
    sqc_stringstream    out;
	out << percent << sqc_text( "%" );
    return out.str();
}

// format quantity
sqc_string sqc_formats::format_quantity( const int count, const int total ) const {
    sqc_stringstream    out;
	out << count
        << sqc_text( " / " )
        << total;
    return out.str();
}

// format time
sqc_string sqc_formats::format_time( int seconds ) {
	sqc_stringstream    out;
	int hours = seconds / ( 60*60 );
	if (hours)
		out << hours << "h ";
	int minutes = ( seconds / 60 ) % 60;
	if (minutes || hours)
		out << minutes << "m";
	if (!hours) {
		if (minutes) out << " ";
	    out << seconds%60 << sqc_text( "s" );
	} 
    return out.str();
}

// format time
sqc_string sqc_formats::format_time_colon( int seconds ) {
	sqc_string s;
    int days = seconds / (60*60*24);
    if (days) {
    	return format("%d d", days);
    }
    int hours = days > 0 ? seconds % ( (60*60*24)*days) : seconds / (60*60); 
    int min = ( seconds - ( days*(60*60*24) + hours*(60*60) ) ) / 60;
    if (days) {
		s = format("%02d:%02d:%02d", days, hours, min);
    }
    else {
		s = format("%02d:%02d", hours, min);
    }
	return s;    
}


/// time mask
sqc_string sqc_formats::get_time_mask() const {
	return "00h 00m 00s";
}

END_NAMESPACE_SQC_FRAMEWORK