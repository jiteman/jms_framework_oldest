#pragma once

#include "../surf_gl.h"
#include "../../sqc/sqc_defs.h"
#include "../../sqc/sqc_data_stream.h"

NAMESPACE_SQC 

namespace png {
    class png_image;
};

namespace jpeg {
	class jpeg_image;
};


class sqc_image_decoder;

class sqc_image_loader : public surf::surf_image_loader {
public:
	sqc_image_loader();
	~sqc_image_loader();
	
    virtual bool load_image( const char *name, surf::surf_image_info &image_info, surf::surf_image_ready_callback cb, surf::surf_create_image_info const &create_info );
    virtual bool load_image_info( const char *name, surf::surf_image_info &image_info, surf::surf_create_image_info const &create_info );

protected:
	sqc_data_stream_ptr open_file( const char *name, surf::surf_create_image_info const &create_info,surf::surf_image_file_type& type);
	/// replace chis function for reading from custom stream
	virtual sqc_data_stream_ptr open_file( const char* name, surf::surf_create_image_info::sqc_reading_path path, const sqc_string& postfix );
	/// determine file type from extension
	surf::surf_image_file_type get_type_from_extension( const char* name) const;
private:
    //bool read_image( const char *name, surf_create_image_info const &create_info, bool info_only, sqc_image_decoder *decoder, surf_image_info &image_info );
	png::png_image*	m_png_reader;
	jpeg::jpeg_image* m_jpeg_reader;
};

END_NAMESPACE_SQC
