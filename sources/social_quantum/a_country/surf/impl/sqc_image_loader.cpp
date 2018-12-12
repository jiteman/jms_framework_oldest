#include "sqc_image_loader.h"
#include "../../sqc/sqc_png.h"
#include "../../sqc/sqc_jpeg.h"
#include "../../sqc/sqc_file_api.h"
#include "../../sqc/sqc_file_data_stream.h"

NAMESPACE_SQC 

sqc_image_loader::sqc_image_loader() {
	m_png_reader = new png::png_image();
	m_jpeg_reader = new jpeg::jpeg_image();
}

sqc_image_loader::~sqc_image_loader() {
	delete m_png_reader;
	delete m_jpeg_reader;
}

surf::surf_image_file_type sqc_image_loader::get_type_from_extension( const char* name) const {
	surf::surf_image_file_type result = surf::surf_image_file_type_unknown;
	if (name) {
		size_t len = strlen(name);
		if (len>4) {
			if ( (strcmp(name+len-4, ".png")==0) ||
				(strcmp(name+len-4, ".PNG")==0) ) result = surf::surf_image_file_type_png;
			else if ( (strcmp(name+len-4, ".jpg")==0) ||
					 (strcmp(name+len-4, ".JPG")==0) ) result = surf::surf_image_file_type_jpg;
		} else if (len>5) {
			if ( (strcmp(name+len-5, ".png4")==0) ||
				(strcmp(name+len-5, ".PNG4")==0) ) result = surf::surf_image_file_type_png4;
			else if ( (strcmp(name+len-5, ".jpeg")==0) ||
					 (strcmp(name+len-5, ".JPEG")==0) ) result = surf::surf_image_file_type_jpg;
		}
	}
	return result;
}

sqc_data_stream_ptr sqc_image_loader::open_file( const char *name, surf::surf_create_image_info const &create_info,surf::surf_image_file_type& type) {
	sqc_string postfix = "";
	switch (create_info.file_type) {
		case surf::surf_image_file_type_png: postfix="png"; break;
		case surf::surf_image_file_type_png4: postfix="png4"; break;
		case surf::surf_image_file_type_jpg: postfix="jpg"; break;
		case surf::surf_image_file_type_unknown: {
			/// for first, find extension in name
			type = get_type_from_extension( name );
			if (type!=surf::surf_image_file_type_unknown) {
				return open_file(name,create_info.reading_path,"");
			}
			sqc_data_stream_ptr res;
			type = surf::surf_image_file_type_png;
			res = open_file(name,create_info.reading_path,"png");
			if (res) return res;
			type = surf::surf_image_file_type_jpg;
			res = open_file(name,create_info.reading_path,"jpg");
			if (res) return res;
			type = surf::surf_image_file_type_png4;
			res = open_file(name,create_info.reading_path,"png4");
			if (res) return res;
			return sqc_data_stream_ptr();
		} break;
	};
	return open_file(name,create_info.reading_path,postfix);
}

sqc_data_stream_ptr sqc_image_loader::open_file( const char* name, surf::surf_create_image_info::sqc_reading_path path, const sqc_string& postfix ) {
	sqc_string  resource_path; 
    if (path == surf::surf_create_image_info::from_temp) {
        resource_path = file_api::get_documents_path( name, postfix );
    }
    else {
		resource_path = file_api::get_resource_path( name, postfix );
    }
	
	return sqc_file_data_stream::open( resource_path.c_str() );
}



bool sqc_image_loader::load_image( const char *name, surf::surf_image_info &image_info, surf::surf_image_ready_callback complete_callback, surf::surf_create_image_info const &create_info ) {
	surf::surf_image_file_type type = create_info.file_type;
	sqc_data_stream_ptr stream = open_file(name,create_info,type);
	if (!stream) {
		std::cout << "failed opening file " << name << std::endl;
		return false;
	}
	sqc_image_decoder* decoder = m_png_reader;
	if ( type == surf::surf_image_file_type_jpg) decoder = m_jpeg_reader;
	sqc_image_raw_data data;
	if (!decoder->decode(stream.get(),data,false,create_info.reduce_bitwidth))
		return false;
	
    image_info.size.cx = data.size.cx;
	image_info.size.cy = data.size.cy;
    image_info.bpp = data.bpp;
    image_info.reduced_bitdepth = create_info.reduce_bitwidth;
	
	complete_callback( image_info, create_info, data.data );
	return true;
}

bool sqc_image_loader::load_image_info( const char *name, surf::surf_image_info &image_info, surf::surf_create_image_info const &create_info ) {
	surf::surf_image_file_type type = create_info.file_type;
	sqc_data_stream_ptr stream = open_file(name,create_info,type);
	if (!stream) return false;
	sqc_image_decoder* decoder = m_png_reader;
	if ( type == surf::surf_image_file_type_jpg) decoder = m_jpeg_reader;
	sqc_image_raw_data data;
	if (!decoder->decode(stream.get(),data,true,create_info.reduce_bitwidth))
		return false;
	
    image_info.size.cx = data.size.cx;
	image_info.size.cy = data.size.cy;
    image_info.bpp = data.bpp;
    image_info.reduced_bitdepth = create_info.reduce_bitwidth;
	
	return true;
}


END_NAMESPACE_SQC
