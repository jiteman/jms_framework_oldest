/*
 *  sqc_game.cpp
 *  aCountry
 *
 *  Created by Andrey Yamov on 6/28/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_framework_base.h"
#include "sqc_file_api.h"
#include "sqc_info_load.h"
#include "sqc_xml.h"
#include "sqc_zorder_sort.h"


NAMESPACE_SQC_FRAMEWORK


using namespace std::tr1::placeholders;

//
// sqc_framework_base
//
sqc_framework_base::sqc_framework_base( 
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
                   sqc_sound_server_ptr sound) 
    : sqc_framework( theme, il, fnt_loader, 
                     string_res, http_service, 
                     networks_factory, preferences, sound )
	, m_server_config( server_config )
    , m_backend_connection( server_config, m_notify_center, 
                           m_networks, m_http_service, 
                           ui, preferences )
	, m_cmd_processor( m_backend_connection, m_notify_center, m_http_service )
    , m_game_controller( m_cmd_processor )
	, m_ui( ui )
    , m_shop( m_class_provider )
    , m_message_queue(message_queue)
    , m_friends( m_notify_center, m_networks, m_game )
{	
    m_notify_connection = notify_center().subscribe( 
        std::tr1::bind( &sqc_framework_base::notify_callback, this, _1, _2 ) );
    
    m_version_provider.reset( new sqc_version_provider() );
}

sqc_framework_base::~sqc_framework_base() {
	notify_center().unsubscribe( m_notify_connection );
}

bool sqc_framework_base::create_game( int width, int height , const sqc_platform_information* platform_info ) {
    if( !sqc_framework::create_game( width, height,platform_info ) ) {
        return false;
    }
    
    m_friends.init();

    on_init();
    return true;
}

void sqc_framework_base::handle_timer() {
    sqc_framework::handle_timer();
    
    m_backend_connection.handle_timer();
    m_game_controller.handle_timer();
    m_message_queue.handle_timer();
    m_cmd_processor.handle_timer();
}

sqc_shop& sqc_framework_base::shop() {
    return m_shop;
}

sqc_game_ptr sqc_framework_base::game()
{
    return m_game;
}

sqc_country_base_ui_face& sqc_framework_base::ui() {
    return m_ui;
}

sqc_object_info_provider_ptr sqc_framework_base::object_factory() {
    return m_class_provider;
}

tools::sqc_tools_controlles& sqc_framework_base::tools() {
    return m_tools;
}

sqc_country_view_ptr sqc_framework_base::country_view() {
    return m_ptr_country_view;
}

sqc_scene_view_ptr sqc_framework_base::scene_view() {
    if ( !m_ptr_country_view ) {
        return sqc_scene_view_ptr();
    }
    
    return m_ptr_country_view->scene_view();
}

sqc_backend_connection& sqc_framework_base::backend_connection() {
    return m_backend_connection;
}

processor::sqc_command_processor& sqc_framework_base::cmd_processor() {
	return m_cmd_processor;
}

sqc_friends& sqc_framework_base::friends() {
    return m_friends;
}

/*
 Application is initialized, we need to start download neccessary configuration files process
 */
void sqc_framework_base::on_init() {
    sqc_info() << "initialize framework";
    
    m_game_controller.init( m_game->get_field() );
    m_backend_connection.connect();
	windows().get_theme().init_metrics();
    return;
}

// load static objects
void sqc_framework_base::on_static_objects_dowload() {

    sqc_info() << "configuration is ready, let's load class factory";
    
    sqc_info() << "load hierarchy";
    // load objects
    info::load_hierarchy( 
    	path::get_yml_full_path( m_server_config, request_type_hierarchy ), 
	    m_class_factory, m_drawing_provider, m_version_provider );

    sqc_info() << "load objects";
    info::read_binary_object_information(
    	path::get_yml_full_path( m_server_config, request_type_binary_objects ),
    	m_class_provider,
        m_class_factory,
        m_drawing_provider
#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
        ,
        path::get_yml_full_path( m_server_config, request_type_object_localization_strings ), m_version_provider );
#else // SQC_ENABLE_EXTERNAL_LOCALIZATION
        , m_version_provider);
#endif // SQC_ENABLE_EXTERNAL_LOCALIZATION
    
    sqc_info() << "load textures";
    texture_proxy().on_description_downloaded( 
    	path::get_yml_full_path( m_server_config, request_type_textures_plist ) );
    
    sqc_info() << "configure downloader";
    downloader().set_download_url(m_server_config.get_static_server_url(m_server_config.get_textures_subfolder()));
    
    sqc_info() << "fire configuration ready event";
    // fire event
	notify_center().fire_event( country_provider_id, country_configuration_ready_event, call_sync );
    sqc_info() << "load complete";
}

// parse XML
void sqc_framework_base::on_xml_received() {

    using namespace xml;
    
    processor::raw_xml xml_cnt;
    m_cmd_processor.get_init_xml( xml_cnt );
    xml::xml_doc    doc( xml_cnt );
    if( !doc.is_valid() ) {
        sqc_error() << "received XML is broken";
        return;
    }
    
    assert( m_game );
    
    xml_node_ptr    country_node = doc.get_root();
    if( !country_node ) {
        sqc_error() << "received XML has invalid format (no country)";
        return;
    }
    m_game->parse_xml( country_node );
    
    m_message_queue.on_xml_received(doc);
    
    m_game_controller.handle_xml_receive();

	notify_center().fire_event( country_provider_id, country_field_changed_event, call_async );
}

// notification callback
void sqc_framework_base::notify_callback( 
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
    
    if ( backend_connection_provider_id == provider_id ) {
        
        //
    	//  backend connection events
        //
        if ( backend_download_static_objects_complete_event == event_id ) {
            
            // load static objects
        	on_static_objects_dowload();
        }
            
    } else if ( processor::command_processor_provider_id == provider_id ) {
        //
    	//  command processor events
        //
        if ( processor::command_processor_initial_xml_complete_event == event_id ) {
            
            // parse XML
        	on_xml_received();
        }
    }
}


/*    
    sqc_string test_xml_path = file_api::append_path( file_api::g_path_to_rsc, "city_sample.xml" );
    sqc_net_data    xml_raw;
    file_api::read_text_file( test_xml_path, xml_raw );
    
    on_xml_received( xml_raw );
    */

END_NAMESPACE_SQC_FRAMEWORK





NAMESPACE_SQC_FRAMEWORK

sqc_game_controller::sqc_game_controller( processor::sqc_command_processor &p ) 
    : command_processor( p )
    , next_tick_scheduled( false )
    , next_tick_time( 0 )
    , next_tick_object_id( 0 )
{
    
}

void sqc_game_controller::init( sqc_field_ptr f ) {
    field = f;
}

void sqc_game_controller::handle_xml_receive() {
    schedule_next_tick();
}

void sqc_game_controller::handle_timer() {
    sqc_ddword  tick = clock_msec();
    field->handle_timer();
    if( next_tick_scheduled ) {
        if( tick >= next_tick_time ) {
            run_tick_command();
            cancel_next_tick_scheduling();
        }
    }
}

void sqc_game_controller::cancel_next_tick_scheduling() {
    next_tick_time = 0;
    next_tick_object_id = 0;
    next_tick_scheduled = false;
}

void sqc_game_controller::run_tick_command() {
    using namespace processor;
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_tick_command( str_user_id, next_tick_object_id ) );
    
    command_processor.schedule( command );
}

void sqc_game_controller::schedule_next_tick() {
    sqc_ddword  next_process_end = 0;
    if( field->calculate_nearest_process_end( next_process_end, next_tick_object_id ) ) {
        next_tick_scheduled = true;
        next_tick_time = clock_msec()+next_process_end;
    }
    else {
        next_tick_scheduled = false;
    }
}


END_NAMESPACE_SQC_FRAMEWORK
