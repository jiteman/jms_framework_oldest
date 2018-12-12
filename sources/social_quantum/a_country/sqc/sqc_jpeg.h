/*
 *  sqc_jpeg.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SQC_JPEG_H_INCLUDED
#define SQC_JPEG_H_INCLUDED

// jpeg
#include "sqc_image_decoder.h"

#define NAMESPACE_SQC_JPEG namespace sqc { namespace jpeg {
#define END_NAMESPACE_SQC_JPEG }}

NAMESPACE_SQC_JPEG

class jpeg_image : public sqc_image_decoder {
public:
  	virtual bool decode( sqc_data_stream* stream, sqc_image_raw_data& data, bool info_only , bool reduce_bitdepth);
};


END_NAMESPACE_SQC_JPEG

#endif /*SQC_JPEG_H_INCLUDED*/