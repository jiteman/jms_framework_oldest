#pragma once

#include "../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

typedef std::string		sqc_net_data;
typedef std::string		sqc_net_path;
typedef std::string		sqc_net_string;
typedef unsigned int	sqc_net_error;

enum sqc_net_metod {
    sqc_net_get_metod,
    sqc_net_post_metod,
};

typedef std::tr1::function<void( const sqc_net_path& path, const sqc_net_data& data )>   
					downloader_complete_callback;

typedef std::tr1::function<void( const sqc_net_path& path, const sqc_net_error error )>   
					downloader_error_callback;

struct sqc_net_param {
    sqc_net_param() {
        net_metod = sqc_net_get_metod;
    }
    sqc_net_metod					net_metod;
    sqc_net_string					request_params;
	downloader_complete_callback	complete_callback;
	downloader_error_callback		error_callback;
};

//
// sqc_http_service implementation
//
class sqc_http_service {
public:
	virtual void download( const sqc_net_path& path, const sqc_net_param& param ) = 0;
    virtual void handle_timer(){}
	
};

END_NAMESPACE_SQC_FRAMEWORK
