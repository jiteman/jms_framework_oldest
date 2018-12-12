/*
 *  sqc_file_data_stream.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_FILE_DATA_STREAM_H_INCLUDED
#define SQC_FILE_DATA_STREAM_H_INCLUDED

#include "sqc_data_stream.h"
#include <fstream>

NAMESPACE_SQC

class sqc_file_data_stream : public sqc_data_stream {
public:
	virtual ~sqc_file_data_stream();
	/// read `size` bytes to buffer, return realy readed bytes
	virtual sqc_size_t read( sqc_byte* buffer, sqc_size_t size ) ;
	/// seek to absolute position if from_current==false else to relative from current
	virtual bool seek( sqc_size_t offset, bool from_current ) ;
	/// eof indicator
	virtual bool eof();
	/// open regular file
	static sqc_data_stream_ptr open( const char* fn );
protected:
	explicit sqc_file_data_stream( std::ifstream* stream ) : m_stream(stream) {
	}
private:
	std::ifstream*	m_stream;
};

END_NAMESPACE_SQC

#endif /*SQC_FILE_DATA_STREAM_H_INCLUDED*/