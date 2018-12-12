#ifndef __SQC_PNG_INCLUDED_H__
#define __SQC_PNG_INCLUDED_H__

// png
#include "sqc_image_decoder.h"

#define NAMESPACE_SQC_PNG namespace sqc { namespace png {
#define END_NAMESPACE_SQC_PNG }}

NAMESPACE_SQC_PNG

class png_image : public sqc_image_decoder{
public:
 	virtual bool decode( sqc_data_stream* stream, sqc_image_raw_data& data, bool info_only , bool reduce_bitdepth);
};

END_NAMESPACE_SQC_PNG

#endif //__SQC_PNG_INCLUDED_H__