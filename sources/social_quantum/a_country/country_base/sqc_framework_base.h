#pragma once

#include "../sqc/sqc_base.h"

#include "../framework/sqc_framework.h"
#include "../framework/social_network/sqc_social_network_defs.h"

#include "sqc_country_base_ui.h"
#include "sqc_backend_connection.h"
#include "shop/sqc_shop.h"
#include "tools/sqc_tools.h"
#include "view/sqc_country_view.h"
#include "friends/sqc_friends.h"
#include "commands/sqc_command_processor.h"
#include "message_queue/sqc_message_queue_base.h"

#include "message_queue/sqc_message_queue_base.h"

NAMESPACE_SQC_FRAMEWORK

inline
sqc_ddword clock_msec() {
    sstl::time_mks mks;
    sstl::get_current_time_mks(mks);
    sqc_ddword result = mks/1000;
    return result;
}


class sqc_game_controller {
public:
    sqc_game_controller( processor::sqc_command_processor &p );
    void init( sqc_field_ptr f );
    void handle_xml_receive();
    void handle_timer();
protected:
    void cancel_next_tick_scheduling();
    void run_tick_command();
    void schedule_next_tick();
private:
    sqc_field_ptr   field;
    
    bool    next_tick_scheduled;
    int     next_tick_object_id;
    sqc_ddword next_tick_time;
    
    processor::sqc_command_processor &command_processor;
};

//
// sqc_framework_base
//
class sqc_framework_base : public sqc_framework {
public:
	sqc_framework_base( 
                       milk::milk_theme &theme,
                       surf::surf_image_loader& il, 
					   surf::surf_font_loader& fnt_loader,
					   sqc_string_resources& string_res,
					   sqc_http_service& http_service,
                       sqc_social_networks_factory& networks_factory,
                       sqc_preferences&  preferences,
					   sqc_server_config& server_config,
                       sqc_country_base_ui_face& ui,
                       sqc_message_queue_base& message_queue,
                       sqc_sound_server_ptr sound);
                       
    ~sqc_framework_base();
    
    virtual bool create_game( int width, int height , const sqc_platform_information* platform_info);
    virtual void handle_timer();
        
    sqc_shop&       					shop();
    sqc_country_base_ui_face& 			ui();
    sqc_game_ptr                    	game();
    sqc_object_info_provider_ptr		object_factory();
    tools::sqc_tools_controlles&    	tools();
	sqc_country_view_ptr				country_view();
    sqc_scene_view_ptr                  scene_view();
    sqc_backend_connection&     		backend_connection();
    processor::sqc_command_processor&	cmd_processor();
    sqc_friends&						friends();
    
    
    virtual void    on_init();
    // load static objects
    virtual void	on_static_objects_dowload();
    // parse XML
    virtual void	on_xml_received();
    
    
protected:
    // notification callback
    void			notify_callback( const sqc_provider_id& provider_id, 
                                    const sqc_event_id& event_id);    
    
	sqc_listener_connection m_notify_connection;
    
protected:
    sqc_game_ptr                    m_game;
    sqc_class_factory_ptr           m_class_factory;
    sqc_drawing_provider_ptr        m_drawing_provider;
    sqc_object_info_provider_ptr    m_class_provider;
    
    sqc_server_config&				m_server_config;
    
    tools::sqc_tools_controlles		m_tools;
    sqc_shop                        m_shop;
    sqc_country_base_ui_face&		m_ui;
    sqc_country_view_ptr			m_ptr_country_view;

    sqc_friends						m_friends;
    
    sqc_backend_connection          m_backend_connection;
    processor::sqc_command_processor			m_cmd_processor;
    
    sqc_game_controller              m_game_controller;
    sqc_message_queue_base&          m_message_queue;

    sqc_version_provider_ptr        m_version_provider;

};

// framework provider events id
//
declare_notification_provider_id( country_provider_id )

declare_notification_event_id( country_configuration_ready_event )
declare_notification_event_id( country_field_changed_event )

extern sqc_framework_base &country_framework();

END_NAMESPACE_SQC_FRAMEWORK
