#include "sqc_font_loader.h"
#include "../../sqc/sqc_file_api.h"
#include "../../sqc/sqc_file_data_stream.h"

NAMESPACE_SQC 

bool sqc_font_loader::load_font( const char *name, surf_font_content& font_content ) {
	sqc_data_stream_ptr file = open_file(name);
	if (!file) {
		return false;
	}
	static const size_t buffer_size = 1024*4;
	font_content.clear();
	size_t readed = 0;
	do {
		size_t size = font_content.size();
		/// @todo optimize this
		font_content.resize( size + buffer_size );
		readed = file->read( (sqc_byte*)&(font_content[size]),buffer_size);
		font_content.resize( size+readed );
	} while (readed>0);
	return true;
}

sqc_data_stream_ptr sqc_font_loader::open_file( const char* name ) {
	sqc_string  font_path = sqc::file_api::get_resource_path( name, "" );
	return sqc_file_data_stream::open( font_path.c_str() );
}

END_NAMESPACE_SQC
