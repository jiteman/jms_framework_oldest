/*
 *  sqc_file_data_stream.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_file_data_stream.h"

NAMESPACE_SQC


sqc_file_data_stream::~sqc_file_data_stream() {
	delete m_stream;
}

/// read `size` bytes to buffer, return realy readed bytes
sqc_size_t sqc_file_data_stream::read( sqc_byte* buffer, sqc_size_t size ) {
	m_stream->read( (char*)buffer,size);
	return m_stream->gcount();
}

/// seek to absolute position if from_current==false else to relative from current
bool sqc_file_data_stream::seek( sqc_size_t offset, bool from_current ) {
	return m_stream->seekg( offset, from_current ? std::ios_base::cur : std::ios_base::beg );
}
/// eof indicator
bool sqc_file_data_stream::eof() {
	return m_stream->eof();
}
/// open regular file
sqc_data_stream_ptr sqc_file_data_stream::open( const char* fn ) {
	std::auto_ptr<std::ifstream> in( new std::ifstream( ) );
	in->open(fn , std::ifstream::binary | std::ifstream::in );
	if (!in->good())
		return sqc_data_stream_ptr();
	return sqc_data_stream_ptr( new sqc_file_data_stream(in.release()) );
}


END_NAMESPACE_SQC