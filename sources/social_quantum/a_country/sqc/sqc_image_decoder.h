/*
 *  sqc_image_decoder.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_IMAGE_DECODER_H_INCLUDED
#define SQC_IMAGE_DECODER_H_INCLUDED

#include "sqc_defs.h"
#include "sqc_data_stream.h"

NAMESPACE_SQC


struct sqc_image_raw_data {
	sqc_size	size;
	sqc_size_t	bpp;
	sqc_byte*	data;
	sqc_image_raw_data() : data(0){}
	~sqc_image_raw_data() {
		delete [] data;
	}
};

class sqc_image_decoder : public sqc_noncopyable {
public:
	/// decode image from stream to data
	virtual bool decode( sqc_data_stream* stream, sqc_image_raw_data& data, bool info_only , bool reduce_bitdepth=false ) = 0;
};

END_NAMESPACE_SQC

#endif /*SQC_IMAGE_DECODER_H_INCLUDED*/