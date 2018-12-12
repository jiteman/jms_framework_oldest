#ifndef __SQC_FILE_API_INCLUDED__
#define __SQC_FILE_API_INCLUDED__

#include "sqc_defs.h"

#define NAMESPACE_SQC_FILE_API namespace sqc { namespace file_api {
#define END_NAMESPACE_SQC_FILE_API }}

NAMESPACE_SQC_FILE_API

sqc_string append_path( sqc_string const &path, sqc_string const &name );
sqc_string get_filename( sqc_string const &path );
bool file_exist( sqc_string const &path );
bool read_text_file( sqc_string const &path, sqc_string &content );
bool write_text_file( sqc_string const &path, sqc_string const &content );
sqc_string get_resource_path( sqc_string const &name, sqc_string const &type );
sqc_string get_documents_path( sqc_string const &name, sqc_string const &type );
bool create_directory( sqc_string const &path ); 


// should be initialized
extern sqc_string g_path_to_app;
extern sqc_string g_path_to_rsc;
extern sqc_string g_path_to_doc;

END_NAMESPACE_SQC_FILE_API

#endif //__SQC_FILE_API_INCLUDED__
