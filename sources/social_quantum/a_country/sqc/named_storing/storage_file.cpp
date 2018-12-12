#include "storage_file.h"
#include <assert.h>
#include <fstream>

namespace sqc {
namespace named_storing {

storage_file &storage_file::init( const std::string &path_to_file ) {
	_path_to_file = path_to_file;
	return *this;
}

bool storage_file::read( const bool error_if_not_exist ) {
	assert( !_path_to_file.empty() );

    size_t size_of_file = 0;
    {
        std::ifstream file( _path_to_file.c_str(), std::ios_base::in | std::ios_base::binary );

	    if ( !file.is_open() ) {
// 		    if ( error_if_not_exist ) {
// 			    errors() << "can't open file \"" << path_name << "\"";
// 		    } else {
// 			    warnings() << "can't open file \"" << path_name << "\"";
// 		    }

		    return false;
	    }

        file.seekg( 0, std::ios_base::end );
        size_of_file = static_cast< size_t >( file.tellg() );

        if ( size_of_file == 0 ) return false;
    }

    std::vector< char > buffer( size_of_file );
    {
        std::ifstream file( _path_to_file.c_str(), std::ios_base::in | std::ios_base::binary );
        file.read( &buffer[ 0 ], size_of_file );
    }

	// распаковываем прочитанные данные
	if( !_storage_data.unpack( &buffer[ 0 ], size_of_file ) ) {
//		errors() << "can't unpack storage from \"" << path_name << "\"";
		return false;
	}

	return true;
}

bool storage_file::write( const bool check_modified ) {
	assert( !_path_to_file.empty() );

	if( check_modified && !_storage_data.is_modified() ) {
		// ничего не менялось - писать не будем
		return true;
	}

	std::vector< byte_t > data_to_write;

	// запаковываем 
	if( !_storage_data.pack( data_to_write ) ) {
//		errors() << "can't pack data for \"" << path_name << "\"";
		return false;
	}

    {
        std::ofstream file( _path_to_file.c_str(), std::ios_base::out | std::ios_base::binary );

	    if ( !file.is_open() ) {
//		    errors() << "can't create file \"" << path_name << "\"";
		    return false;
	    }
        
        file.write( reinterpret_cast< const char * >( &data_to_write[ 0 ] ), data_to_write.size() );

	    if( !file.good() ) {
//		    errors() << "error writing \"" << path_name << "\", err = " << file.rdstate();
		    return false;
	    }

// 	    if( cb_file != cb_write ) {
// 		    errors() << "can't write all data to \"" << path_name << "\", err = " << GetLastError() << ", wrote " << cb_write;
// 		    return false;
// 	    }
    }

	_storage_data.set_modified( false );
	return true;
}

storage_container &storage_file::get_storage() {
    return _storage_data;
}

} // namespace named_storing
} // namespace sqc
