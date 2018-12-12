/*
 *  sqc_data_stream.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_DATA_STREAM_H_INCLUDED
#define SQC_DATA_STREAM_H_INCLUDED

#include "sqc_defs.h"

NAMESPACE_SQC

class sqc_data_stream : public sqc_noncopyable {
public:
	virtual ~sqc_data_stream() {}
	/// read `size` bytes to buffer, return realy readed bytes
	virtual sqc_size_t read( sqc_byte* buffer, sqc_size_t size ) = 0;
	/// seek to absolute position if from_current==false else to relative from current
	virtual bool seek( sqc_size_t offset, bool from_current ) = 0;
	/// eof indicator
	virtual bool eof() = 0;
};
typedef std::tr1::shared_ptr<sqc_data_stream> sqc_data_stream_ptr;

END_NAMESPACE_SQC

#endif /*SQC_DATA_STREAM_H_INCLUDED*/