#pragma once

#include "sqc_framework_defs.h"
#include "../sqc/sqc_file_api.h"

// milk & surface
#include "../milk/milk_server.h"
#include "../surf/surf_gl.h"

// framework components
#include "layouts/sqc_windows_factory.h"
#include "animator/sqc_animator.h"
#include "http_service/sqc_http_service.h"
#include "texture/sqc_texture_builder.h"
#include "resource/sqc_string_resource.h"
#include "social_network/sqc_social_network.h"
#include "notify_center/sqc_notify_center.h"
#include "formats/sqc_formats.h"

NAMESPACE_SQC
class sqc_sound_server;
typedef std::tr1::shared_ptr<sqc_sound_server> sqc_sound_server_ptr;
sqc_sound_server_ptr sqc_create_stub_sound_server();
sqc_sound_server_ptr sqc_create_sound_server();

END_NAMESPACE_SQC

NAMESPACE_SQC_FRAMEWORK

class sqc_preferences { 
public:
	~sqc_preferences(){}
    
	virtual sqc_bool	get_bool( const sqc_string& key, const sqc_string& value, const sqc_bool def ) = 0;
    virtual sqc_int		get_int( const sqc_string& key, const sqc_string& value, const sqc_int def ) = 0;
    virtual sqc_string  get_string( const sqc_string& key, const sqc_string& value, const sqc_string& def ) = 0;

	virtual sqc_bool	set_bool( const sqc_string& key, const sqc_string& value, const sqc_bool v ) = 0;
    virtual sqc_bool	set_int( const sqc_string& key, const sqc_string& value, const sqc_int v ) = 0;
    virtual sqc_bool    set_string( const sqc_string& key, const sqc_string& value, const sqc_string& v ) = 0;
};


struct sqc_platform_information;


//
// sqc_framework implementation
//
class sqc_framework {
public:
	sqc_framework( milk::milk_theme& milk_theme 
				  ,surf::surf_image_loader& il
				  ,surf::surf_font_loader& fnt_loader
				  ,sqc_string_resources& string_res
				  ,sqc_http_service& http_service
                  ,sqc_social_networks_factory& networks_factory
                  ,sqc_preferences&  preferences
                  ,sqc_sound_server_ptr sound) 
		: m_image_loader( il )
        , m_graphics( il, fnt_loader )
		, m_windows( m_graphics, milk_theme )
		, m_texture_proxy( m_graphics ) 
        , m_downloader()
		, m_window_factory( m_graphics ) 
		, m_strings( string_res ) 
		, m_http_service( http_service )
        , m_networks( networks_factory )
        , m_preferences( preferences )
		, m_ticks(0)
        , m_sound(sound)
    {
	}
	virtual ~sqc_framework() {
	}

	// create game
	virtual bool create_game( int width, int height , const sqc_platform_information* platform_info);    
    virtual void handle_timer();    
	virtual void on_memory_warning(const sqc_platform_information* platform_info);
	virtual void on_suspend(const sqc_platform_information* platform_info);
	virtual void on_resume(const sqc_platform_information* platform_info);
	
protected:
    // create country view
    virtual bool create_country_view( const milk::surf_rect& rect ) = 0;
	
	virtual sqc_dword calculate_texture_manager_memory_limit( const sqc_platform_information* platform_info);
	
public:
	milk::milk_window_server&	windows() {
		return m_windows;
	}
	surf::surf_graphics_server&	graphics() {
		return m_graphics;
	}
	sqc_window_factory&			windows_factory() {
		return m_window_factory;
	}
	sqc_animator&				animator() {
		return m_animator;
	}
	sqc_http_service&			http_service() {
		return m_http_service;
	}
	sqc_texture_proxy&			texture_proxy() {
		return m_texture_proxy;
	};
	sqc_downloader&				downloader() {
		return m_downloader;
	};
	sqc_string_resources&		strings() {
		return m_strings;
	}
    sqc_social_networks&        networks() {
        return m_networks;
    }
    sqc_notify_center&          notify_center() {
        return m_notify_center;
    }
    sqc_formats&                formats() {
        return m_formats;
    }
    sqc_traverser &traverser() {
        return m_traverser;
    }
    sqc_preferences&			preferences() {
    	return m_preferences;
    }
    
	sqc_sound_server&	sound() {
		return *m_sound;
	}
    
    sstl::sstl_ini		ini() {
    	return m_ini;
    }
 	
protected:
	milk::milk_window_server		m_windows;
	surf::surf_graphics_server		m_graphics;
	sqc_window_factory				m_window_factory;
	
	sqc_animator					m_animator;
	sqc_http_service&				m_http_service;
	sqc_texture_proxy				m_texture_proxy;
    sqc_downloader              	m_downloader;
	sqc_string_resources&			m_strings;
    sqc_social_networks         	m_networks;
    sqc_notify_center           	m_notify_center;
    sqc_formats                 	m_formats;
    sqc_traverser               	m_traverser;
    surf::surf_image_loader&    	m_image_loader;
    sqc_preferences&				m_preferences;
	/// time meter
	sstl::time_mks	m_last_time;
	/// active time (ms)
	sqc_ddword	m_ticks;
	sqc_sound_server_ptr			m_sound;
    sstl::sstl_ini					m_ini;
};

typedef std::tr1::shared_ptr<sqc_framework>	sqc_framework_ptr;

extern sqc::framework::sqc_framework& framework();

END_NAMESPACE_SQC_FRAMEWORK
