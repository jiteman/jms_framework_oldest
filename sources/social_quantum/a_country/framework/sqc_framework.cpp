/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_framework.h"
#include "sqc_platform_information.h"
#include "sound/sqc_sound.h"

NAMESPACE_SQC_FRAMEWORK

static sqc_string format_memory( sqc_dword val ) {
	sqc_string	metric;
	sqc_dword res = val;
    
    if ( res < 1024 ) {
    	//do nothing
    } else if ( res < 1024*1024 ) {
    	res /= 1024;
        metric = sqc_text("Kb");
    } else if ( res < 1024*1024*1024 ) { 
    	res /= 1024 * 1024;
        metric = sqc_text("Mb");
    } else {
		res /= 1024 * 1024 * 1024;
        metric = sqc_text("Gb");
	}
	
	sqc_stringstream out;
	out << res << metric;
	return out.str();
}

bool sqc_framework::create_game( int width, int height , const sqc_platform_information* platform_info) {
	
	sqc_info() << "framework create_game platform: '" << platform_info->platform_name << "' device: '" << platform_info->device_model << "'" << sqc_endl();
	sqc_info() << "total_mem : " << format_memory(platform_info->total_memory) << sqc_endl();
	sqc_info() << "free_mem : " << format_memory(platform_info->free_memory) << sqc_endl();
	sqc_info() << "used_mem : " << format_memory(platform_info->used_memory) << sqc_endl();
	sqc_info() << "video_mem : " << format_memory(platform_info->video_memory) << sqc_endl();
	
    {
        std::string path = sqc::file_api::g_path_to_doc;
        path += "/settings.ini";
        if ( !m_ini.open( path ) ) {
        	sqc_info() << "unable to open ini: " << path;
        } else {
        	sqc_info() << "open ini: " << path;
        }
    }
    
	// create desktop
	windows().init_desktop();
	milk::surf_rect rect = milk::surf_rect( 0, 0, width, height );
	windows().get_desktop()->set_rect( rect );
	
    
	// init window factory
	windows_factory().init_factory( width, height );
	
	{
		sqc_downloader_init init;
		init.http = &http_service();
		init.download_path = file_api::append_path( file_api::g_path_to_doc, "cache" );
		init.max_download_queue_size = 5;
		downloader().init( init );
	}
	
	{
		sqc_texture_proxy_init  init;
		init.memory_limit = calculate_texture_manager_memory_limit(platform_info);
		sqc_info() << "framework create_game textures_limit set to:" <<format_memory(init.memory_limit) << sqc_endl();
		init.resource_path = file_api::g_path_to_rsc;
		init.downloader = &downloader();
		init.image_loader = &m_image_loader;
		
		texture_proxy().init( init );
	}
	sstl::get_current_time_mks(m_last_time);
    
    sound().set_sound_enabled(preferences().get_bool("settings", "sound_enabled", true));
        
	return create_country_view( rect );
}

sqc_dword sqc_framework::calculate_texture_manager_memory_limit( const sqc_platform_information* platform_info) {
	static const sqc_dword minimum = 1024*1024*10;	/// < minimum texture cache memeory
	static const sqc_dword maximum = 1024*1024*64;	/// < maximum texture cache memory
	static const sqc_dword always_free = 1024*1024*32;	/// < minimum free memory 
	sqc_dword result = minimum;
	if (platform_info->video_memory) {
		if (platform_info->video_memory>always_free) {
			result = platform_info->video_memory-always_free;
		}
	}
	static const int strategy = 1;
	switch (strategy) {
		case 1:
			result = platform_info->free_memory / 2;
			break;
		case 2:
			if (platform_info->free_memory>always_free)
				result = platform_info->free_memory - always_free;
			break;
		default:
			break;
	}
	
	result+=texture_proxy().get_memory_used();
	if (result<minimum) {
		result=minimum;
	} 
	if (result>maximum) {
		result=maximum;
	}
	return result;
}

void sqc_framework::on_memory_warning(const sqc_platform_information* platform_info) {
	sqc_warning() << "framework on_memory_warning " << sqc_endl();
	sqc_warning() << "free_mem : " << format_memory(platform_info->free_memory) << sqc_endl();
	sqc_warning() << "used_mem : " << format_memory(platform_info->used_memory) << sqc_endl();
	texture_proxy().set_memory_limit(calculate_texture_manager_memory_limit(platform_info));
}
void sqc_framework::on_suspend(const sqc_platform_information* platform_info) {
	sqc_info() << "framework on_suspend free_mem : " << format_memory(platform_info->free_memory) << sqc_endl();
	texture_proxy().free_memory();
}
void sqc_framework::on_resume(const sqc_platform_information* platform_info) {
	sqc_info() << "framework on_resume free_mem : " << format_memory(platform_info->free_memory) << sqc_endl();
	sqc_dword limit = calculate_texture_manager_memory_limit(platform_info);
	sqc_info() << "framework on_resume textures_limit set to:" <<format_memory(limit) << sqc_endl();
	texture_proxy().set_memory_limit(limit);
    sstl::get_current_time_mks(m_last_time);
}

void sqc_framework::handle_timer()
{
    sstl::time_mks	now;
    sstl::get_current_time_mks(now);
	sqc_ddword delta = (now - m_last_time);
	m_last_time = now;
	m_ticks+=delta;
	
	
	m_windows.handle_timer( m_ticks / 1000 );
	m_http_service.handle_timer();
	m_traverser.handle_timer();
	downloader().on_idle();
}

END_NAMESPACE_SQC_FRAMEWORK