#include "sqc_backend_connection.h"
#include "../sqc/sqc_file_api.h"
#include "../sqc/sqc_info_load.h"
#include "../sqc/sqc_xml.h"
#include "sqc_framework_base.h"

using namespace std::tr1::placeholders;

/*
 
 load sequence:
 
 1. load plist, get initial server
 2. download apps_ios.yml from initial server
 3. parse apps_ios.yml, select static server
 4. download city_items.yml, city_hierarchy.yml
 5. init object factory
 6. load stored social network or choose it using choose network algorithm
 7. logon to network
 8. check the network game server
 9. download initial XML from game server
 
 */

NAMESPACE_SQC_FRAMEWORK

// full path to yaml files
namespace path {
	sqc_string	get_yml_full_path( const sqc_server_config& cfg, sqc_request_type request_type ) {
        sqc_string  filename = file_api::get_filename( cfg.get_yml_name( request_type ) );
        return file_api::append_path( file_api::g_path_to_doc, filename );
    }
};

//
// server config provider events id
//
declare_notification_provider_id( server_config_provider_id )

// server config notification events id
declare_notification_event_id( server_config_game_server_ready_event )
declare_notification_event_id( server_config_no_game_servers_event )

declare_notification_event_id( server_config_static_server_ready_event )
declare_notification_event_id( server_config_no_static_servers_event )



//
// static objects provider events id
//
declare_notification_provider_id( remote_static_objects_id )

// static objects notification events id
declare_notification_event_id( remote_static_objects_ready_event )
declare_notification_event_id( remote_static_objects_error_event )


using namespace sqc::framework;
using namespace info;

//
// sqc_server_config
//
sqc_server_config_base::sqc_server_config_base(sqc_http_service &http_service) 
	: m_http_service(http_service), m_time(0), m_timeout(5), m_current_request( config_request_unknown ) {
    m_startup_url = names::startup_url;
    
    m_network_keys[sqc_network_none]           = "common";
    m_network_keys[sqc_network_facebook]       = "fb";
    m_network_keys[sqc_network_game_center]    = "gc";
    m_network_keys[sqc_network_moi_mir]        = "mm";
    m_network_keys[sqc_network_odnoklassniki]  = "od";
    m_network_keys[sqc_network_open_feint]     = "of";
    m_network_keys[sqc_network_social_quantum] = "sq";
    m_network_keys[sqc_network_vkontakte]      = "vk";
}

void sqc_server_config_base::init() {
}

sqc_string sqc_server_config_base::get_startup_url(sqc_string const &filename) {
	sqc_assert( m_startup_url.length() );
    return sqc_string(m_startup_url) + filename;
}

sqc_string sqc_server_config_base::get_static_server_url( sqc_string const &filename ) {
	sqc_assert( m_static_server.length() );
    return sqc_string(m_static_server + "/") + filename;
}

sqc_string sqc_server_config_base::get_game_server_url() {
	sqc_assert( m_game_server.length() );
    return m_game_server;
}

sqc_string sqc_server_config_base::get_textures_subfolder() {
    return m_textures_subfolder + "/";
}

sqc_string sqc_server_config_base::app_code(const sqc_string &net_code) {

    static sqc_string prod_postfix = ".prod";
    static sqc_string dev_postfix = ".dev";
  
  	int use_dev = country_framework().ini().read_int_value( 
    							"network", "use_dev_server", 0 );
      
    sqc_string app_full_code(m_app_name); 
    app_full_code += net_code;
    app_full_code += ( use_dev ? dev_postfix : prod_postfix );
    
    return app_full_code;
}

void sqc_server_config_base::handle_timer() {
    if (m_time && (time(NULL) - m_time) > m_timeout) {
        set_servers();
    }
}

void sqc_server_config_base::choose_static_server(sqc_net_param const &params ) {
    sqc_info() << "sqc_server_config: choosing static server";

    m_net_param = params;

    sqc_network_type network_key_for_static = sqc_network_none;
    m_live_servers.clear();
    m_live_static_servers.clear();
    m_time = time(NULL);
    sqc_assert( m_time );
    m_timeout = 5;
    
    check_servers(config_request_static_server, m_apps_info[app_code(m_network_keys[network_key_for_static])].servers_statics);
}

void sqc_server_config_base::choose_game_server( sqc_network_type network_type,
                                sqc_net_param const &params ) {
    sqc_info() << "sqc_server_config: choosing game servers for network: " << print_social_network(network_type);
    
    m_net_param = params;
    sqc_network_type network_key_for_static = sqc_network_none;
    
    m_live_servers.clear();
    m_live_static_servers.clear();
    m_time = time(NULL);
    sqc_assert( m_time );
    m_timeout = 5;
    
    if (network_type != sqc_network_none) {
        
        if (m_apps_info[app_code(m_network_keys[network_type])].servers_statics.size()) {
            network_key_for_static = network_type;
        }
        
        check_servers(config_request_game_server, m_apps_info[app_code(m_network_keys[network_type])].servers);
    }
}

void sqc_server_config_base::check_servers(sqc_config_request request_type, sqc_string_list &servers) {
    m_current_request = request_type;
    for (sqc_string_list::iterator it = servers.begin(); it != servers.end(); ++it) {
        
        sqc_net_param   params;
        params.complete_callback = std::tr1::bind(&sqc_server_config_base::on_http_complete, this, request_type, *it, _2);
        params.error_callback = std::tr1::bind(&sqc_server_config_base::on_http_error, this, request_type, *it, _2);
        
        sqc_string server_postfix;
        if (request_type == config_request_game_server) {
            server_postfix = "/assets/i_animations";
        }
        server_postfix += "/apps_ios.yml";
        
        m_http_service.download( "http://" + (*it) + server_postfix, params );
    }           
}

void sqc_server_config_base::set_servers() {
    
    sqc_config_request request = m_current_request;
    
    m_time = 0;
    m_current_request = config_request_unknown;
  
    
    if ( config_request_game_server == request ) {
    
        m_game_server = sqc_string();
            
        if (m_live_servers.size() > 0) {
            m_game_server = "http://" + m_live_servers[ ::rand() % m_live_servers.size() ];
            
            sqc_info() << "sqc_server_config: game_server_ready url=" << m_game_server;
            sqc::framework::framework().notify_center().fire_event(
                            server_config_provider_id, 
                            server_config_game_server_ready_event,
                            call_sync );
        }
        else {
            sqc_warning() << "sqc_server_config: no game server"; 
            sqc::framework::framework().notify_center().fire_event(
                            server_config_provider_id, 
                            server_config_no_game_servers_event,
                            call_sync );
        }
        
    } else if ( config_request_static_server == request ) {
    
	    m_static_server = sqc_string();
    
        if (m_live_static_servers.size() > 0) {
            m_static_server = "http://" + m_live_static_servers[ ::rand() % m_live_static_servers.size() ];
            
            if (m_net_param.complete_callback) {
                m_net_param.complete_callback(m_static_server, sqc_net_data());
            }
            
            sqc_info() << "sqc_server_config: static_server_ready url=" << m_static_server;
            sqc::framework::framework().notify_center().fire_event(
                            server_config_provider_id,
                            server_config_static_server_ready_event,
                            call_sync );
        }
        else {
            sqc_error() << "sqc_server_config: no static server"; 
            sqc::framework::framework().notify_center().fire_event(
                            server_config_provider_id, 
                            server_config_no_static_servers_event,
                            call_sync );
        }
    } else {
    	sqc_assert( false );
    }
    
}

void sqc_server_config_base::on_http_complete(sqc_config_request request_type, sqc_net_path url, sqc_net_data const &raw) {
    
    if (request_type == config_request_static_server) {
        m_live_static_servers.push_back(url);
	    sqc_info() << "sqc_server_config: static server - " << url <<  " status - up!";
    }
    else if (request_type == config_request_game_server) {
        m_live_servers.push_back(url);
        sqc_info() << "sqc_server_config: game server - " << url <<  " status - up!";
    } else {
    	sqc_info() << "sqc_server_config: lost server - " << url <<  " status - up!";
    }
    
    // to avoid reset timeout by slow static server response
    if ( request_type == m_current_request ) {
	    m_timeout = 0; // now don't wait all servers, set first answered
    }
}

void sqc_server_config_base::on_http_error(sqc_config_request request_type, sqc_net_path url, sqc_net_error const &error) {

    if (request_type == config_request_static_server) {
	    sqc_warning() << "sqc_server_config: static server - " << url << " status - down!";
    }
    else if (request_type == config_request_game_server) {
        sqc_warning() << "sqc_server_config: game server - " << url << " status - down!";
    } else {
    	sqc_warning() << "sqc_server_config: lost server - " << url << " status - down!";
    }
}

void sqc_server_config_base::parse_config(sqc_net_data const &data) {
    typedef std::map<sqc_network_type, sqc_string>::const_iterator iterator;
    
    try {
        sqc_info() << "sqc_server_config: parsing servers configuration... ";
        
        if ( !data.size() ) {
            sqc_error()  << "sqc_server_config: yml is empty";
            return;
        }
        
        using namespace yaml;
        
        sqc_yaml_doc    doc;
        if( !doc.parse( &data[0], data.size() ) ) {
            sqc_warning()  << "sqc_server_config: failed to parse yml";
            return;
        }
        
        sqc_yaml_node_ptr   root_node = doc.get_root();
        if( !root_node ) {
            sqc_warning()  << "sqc_server_config: yml is empty";
            return;
        }
        
        
        for (iterator it = m_network_keys.begin(); it != m_network_keys.end(); ++it) {
            
            sqc_string entry = app_code(it->second);
            
            sqc_yaml_node_ptr   node = root_node->find( entry.c_str() );
            
            if (!node) {
                sqc_warning()  << "sqc_server_config: entry not found for: " <<  entry;
                continue;
            }
            
            app_info current_app_info;
            
            current_app_info.app_id = yaml::get_yaml_val<std::string>( node, "app_id" );
            current_app_info.app_code = entry;
            
            yaml::get_yaml_vals( node, "servers", current_app_info.servers );
            yaml::get_yaml_vals( node, "servers_statics", current_app_info.servers_statics );
            
            m_apps_info[entry] = current_app_info;
            
            if (current_app_info.servers.empty()) {
                sqc_warning() << "sqc_server_config: no server entry is found for: " << it->second;
            }
            
            if (current_app_info.servers_statics.empty()) {
                sqc_warning() << "sqc_server_config: no static_server entry is found for: " << it->second;
            }
        }
        
        sqc_info() << "sqc_server_config: parsed successfully.";
    } 
    catch(std::exception const & e) {
        sqc_error() << "sqc_server_config: error parsing yaml!";
        sqc_error() << e.what();
    }
}

//
// sqc_static_objects_downloader
//
sqc_static_objects_downloader::sqc_static_objects_downloader( 
    sqc_server_config& server_config,
    sqc_http_service& http_service,
    sqc_notify_center& notify_center ) 
		: m_server_config( server_config )
        , m_http_service( http_service )
        , m_notify_center( notify_center )
        , m_success_task_count( 0 )
        , m_fail_task_count( 0 )
{        
    m_tasks.push_back( request_type_objects );
    m_tasks.push_back( request_type_hierarchy );
    m_tasks.push_back( request_type_quests );
    m_tasks.push_back( request_type_requests );
    m_tasks.push_back( request_type_textures_plist );
#ifdef SQC_CITY_GAME
    m_tasks.push_back( request_type_object_localization_strings );
    m_tasks.push_back( request_type_quest_localization_strings );
#endif
	m_tasks.push_back( request_type_binary_objects );
}
    
void sqc_static_objects_downloader::reset() {
    // TODO: terminate downloader
    m_success_task_count = 0;
    m_fail_task_count = 0;
}

void sqc_static_objects_downloader::download() {

    reset();
    
    sqc_info() << "static_objects_downloader: start download...";
    
    for ( download_task::const_iterator it = m_tasks.begin();
         it != m_tasks.end(); ++it ) {
        
        sqc_net_param   params;
        sqc_request_type request_type = *it;
        
        params.complete_callback = std::tr1::bind( 
        &sqc_static_objects_downloader::on_http_complete, this,request_type, _1, _2 );
        
        params.error_callback = std::tr1::bind( 
        &sqc_static_objects_downloader::on_http_error, this, request_type, _1, _2 );
        
        sqc_string url = m_server_config.get_static_server_url( m_server_config.get_yml_name( request_type ) );
        m_http_service.download( url, params );
    }
}
    
void sqc_static_objects_downloader::on_file_received( 
    sqc_request_type request_type, 
    sqc_string const &url, 
    sqc_net_data const &raw ) {
    
    sqc_string  path = path::get_yml_full_path( m_server_config, request_type );
    file_api::write_text_file( path, raw );    
    
    sqc_info() << "static_objects_downloader: write " << path;
}
    
void sqc_static_objects_downloader::on_http_complete( 
    sqc_request_type request_type, 
    sqc_net_path url, 
    sqc_net_data const &raw ) {
    
    on_file_received( request_type, url, raw );
    
    sqc_info() << "static_objects_downloader: received " << url;
    
    m_success_task_count++;
    test_all_files_download();
}

void sqc_static_objects_downloader::on_http_error( 
    sqc_request_type request_type, 
    sqc_net_path path, 
    sqc_net_error const &error ) {

    sqc_error() << "static_objects_downloader: unable to download " << path;
    m_fail_task_count++;
    test_all_files_download();
}

void sqc_static_objects_downloader::test_all_files_download() {

	if ( m_tasks.size() != m_success_task_count + m_fail_task_count ) {
        return;
    }
    
    bool success = ( m_tasks.size() == m_success_task_count );
    if ( success ) {
        sqc_info() << "static_objects_downloader: all objects received. finish.";
        m_notify_center.fire_event( remote_static_objects_id, 
        							remote_static_objects_ready_event,
                                    call_async );
    } else {
	    sqc_info() << "static_objects_downloader: error: unable to receive all objects. cancel.";
    	m_notify_center.fire_event( remote_static_objects_id, 
                                    remote_static_objects_error_event,
                                    call_async );
    }
}

//
//	sqc_backend_connection
//
sqc_backend_connection::sqc_backend_connection(
    sqc_server_config &server_config,
    sqc_notify_center &notify_center,
    sqc_social_networks &networks,
    sqc_http_service &http_service,
    sqc_country_base_ui_face &ui,
    sqc_preferences &preferences ) 
	:
		m_server_config( server_config ),
		m_notify_center( notify_center ),
		m_networks( networks ),
		m_http_service( http_service ),
		m_ui( ui ),
		m_preferences( preferences ),
		m_static_objects( server_config, http_service, notify_center ),
//		m_notify_connection( sqc_listener_connection() ),
		m_connection_type( connection_unknown ),
		m_download_static_objects_done( false ),
		m_login_to_network_done( false ),
		m_current_network( sqc_network_none )
{        
    subscribe_events();
}

sqc_backend_connection::~sqc_backend_connection() {
    unsubscribe_events();
}

void sqc_backend_connection::handle_timer() {
    m_server_config.handle_timer();
}


void sqc_backend_connection::hide_ui() {
    hide_message_box();
    hide_select_network_dlg();
    hide_progress_window();
}

void sqc_backend_connection::reset() {
    m_connection_type				= connection_unknown;
    m_current_network				= sqc_network_none;
    
    m_download_static_objects_done	= false;
    m_login_to_network_done			= false;
    
    hide_ui();
    
    // TODO: terminate prev connection's
}

// connect
void sqc_backend_connection::connect() {
    
    reset();


    show_progress_window();
    
    m_connection_type = connection_full;
    
    sqc_info() << "back-end: start connection...";
    
    // download server config
    download_servers_config();

}

// just connect to social network
void sqc_backend_connection::connect_to_social_network() {
    
    reset();

    show_progress_window();
    
    m_connection_type = connection_socnetwork;
    
    sqc_info() << "back-end: start connection to social network...";
    select_social_network( sqc_network_none );
}

// reconect to new network without full reset()
void sqc_backend_connection::reconnect_to_social_network() {

	//	don't call reset() here to prevent reset of m_download_static_objects_done
    m_login_to_network_done = false;
    hide_ui();
    show_progress_window();
    
    sqc_info() << "back-end: start reconnect to social network...";
    select_social_network( sqc_network_none );
}

bool sqc_backend_connection::get_game_server_login_params( 
    sqc_string& game_server,
    sqc_string& user_id,
    sqc_string& access_token ) {
    
    game_server 	= m_server_config.get_game_server_url();
    user_id			= m_networks.get_user_id();
    access_token	= m_networks.get_access_token();
    
    return true;
}


///////////////////////////////////////////////////////////////////
//
//	first stage
//
void sqc_backend_connection::download_servers_config() {
    sqc_net_param   params;
    params.complete_callback = std::tr1::bind( &sqc_backend_connection::on_http_complete, this, _1, _2 );
    params.error_callback = std::tr1::bind( &sqc_backend_connection::on_http_error, this, _1, _2 );

    sqc_string url = m_server_config.get_startup_url( names::server_cfg_yml );
    sqc_info() 
    	<< "back-end: download servers config from " 
    	<< url
    	<< "...";
    
    m_http_service.download( url, params );
}

void sqc_backend_connection::on_servers_config_received( 
    sqc_string const &raw ) {

    sqc_info() << "back-end: servers config received " << raw.size() << " bytes";
    
    m_server_config.parse_config( raw );
    
    select_static_server();
}

void sqc_backend_connection::on_servers_config_received_error() {
    sqc_error() << "back-end: unable to download server config";
    show_message_box( msb_box_server_config_error, 
    				"Error", "unable to download server config", "OK" );
}

void sqc_backend_connection::select_static_server() {
    sqc_info() << "back-end: select static server...";
    // if sqc_network_none then choose only static server
    m_server_config.choose_static_server();
}

void sqc_backend_connection::on_static_server_ready() {
    sqc_info() << "back-end: static server ready";
    
    // here we start 2 paralels threads
    
#ifndef OFFLINE_ACCESS
    // 1. download static objects 
    download_static_objects();
#else
    on_download_static_objects_ready();
#endif//#OFFLINE_ACCESS
	
    // 2. connect to social network
 	select_social_network( load_last_network() );
}

void sqc_backend_connection::on_static_server_error() {
    sqc_error() << "back-end error: no static server";
    show_message_box( msb_box_static_server_error, 
    							"Error", "no static server", "OK" );
}


void sqc_backend_connection::download_static_objects() {
    sqc_info() << "back-end: download static objects...";
    
    m_static_objects.download();
}

void sqc_backend_connection::on_download_static_objects_ready() {
    sqc_info() << "back-end: download static objects complete (1-st thread)";

    m_download_static_objects_done = true;

    // all done!!! (2-nd thread)
    analize_all_ready();
}

void sqc_backend_connection::on_download_static_objects_error() {
    sqc_error() << "back-end error: unable to download static objects";
    
    show_message_box( msb_box_download_static_object_error,
    					"Error", "unable to download static objects", "OK" );
}

///////////////////////////////////////////////////////////////////
//
//	second stage
//
void sqc_backend_connection::select_social_network( sqc_network_type prefered_network ) {
    sqc_info() 
    	<< "back-end: select social network " 
    	<< print_social_network( prefered_network )
    	<< "...";
                              
    if ( sqc_network_none == prefered_network ) {
 	    show_select_network_dlg();
    } else {
        on_select_social_network_ready( prefered_network );
    }
}

void sqc_backend_connection::on_select_social_network_ready( sqc_network_type new_network ) {
    sqc_info() << "back-end: select social network ready";
    m_current_network = new_network;
    hide_select_network_dlg();
    
    select_game_server();
}

void sqc_backend_connection::select_game_server() {

	if ( !m_progress_wnd ) {
    	show_progress_window();
    }
    
    sqc_info() << "back-end: select game server...";
    m_server_config.choose_game_server( m_current_network );
}

void sqc_backend_connection::on_game_server_ready() {
    sqc_info() << "back-end: select game server complete";
    login_to_social_network();
}

void sqc_backend_connection::on_game_server_error() {
    sqc_error() << "back-end error: no game servers";
    
    show_message_box( msb_box_game_server_error, 
    					"Error", "no game servers", "OK" );
    
}

void sqc_backend_connection::login_to_social_network() {
    sqc_info() 
    	<< "back-end: login to social network "
    	<< print_social_network( m_current_network )
    	<< "...";
    m_networks.loggin( m_current_network, m_server_config.get_game_server_url() );
}

void sqc_backend_connection::on_login_to_social_network_ready() {
    sqc_info() << "back-end: login to social network complete (2-nd thread)";
    
    m_login_to_network_done = true;
    
    store_last_network( m_current_network );
    
    // all done!!! (2-nd thread)
    analize_all_ready();
}

void sqc_backend_connection::on_login_to_social_network_error() {
    sqc_error() << "back-end error: unable to loggin to social network.";
    show_message_box( msb_box_socnet_login_error,
    				"Error", "unable to loggin to social network", "OK" );
}

void sqc_backend_connection::analize_all_ready() {
    
    bool ready = false;
    
    typedef std::list<sqc_event_id> event_to_fire;
    event_to_fire   events;
    
	if ( connection_full == m_connection_type ) {
    	// 
        //	full connection
        //
        ready = ( m_download_static_objects_done && m_login_to_network_done	);
        
        if ( ready ) {
            events.push_back( backend_download_static_objects_complete_event );
            events.push_back( backend_login_to_social_network_complete_event );
        }
        
        
    } else if ( connection_socnetwork == m_connection_type ) {
        ready = ( m_login_to_network_done );
    
        //
        //  connect to social network only
        //
            
        if ( ready ) {
            events.push_back( backend_login_to_social_network_complete_event );
        }
    }
    
    if ( ready ) {
        sqc_info() 
        	<< "back-end: all ready. finish.";
        hide_progress_window();
    } else {
        sqc_info() 
        	<< "back-end: analyze all ready: not all threads are finished";
    }
    
    // fire collected events
    for ( event_to_fire::const_iterator it = events.begin();
        it != events.end(); ++it ) {
        m_notify_center.fire_event( backend_connection_provider_id, 
                           *it,
                           call_async );
    }
}

sqc_network_type sqc_backend_connection::load_last_network() {
	sqc_int val = m_preferences.get_int( "backend", "last_network", sqc_network_none );
    if ( val < 0 || val >= sqc_network_countof ) {
        sqc_info() 
        	<< "back-end: unable to load last network from prefs";
	    return sqc_network_none;
    }
    
    sqc_network_type type = (sqc_network_type)val;
    sqc_info() 
        << "back-end: load last network from prefs: "
        << print_social_network( type );
        
    return type;
}

void sqc_backend_connection::store_last_network( sqc_network_type type ) {
	m_preferences.set_int( "backend", "last_network", type );
    sqc_info() 
        << "back-end: store last network to prefs: "
        << print_social_network( type );
}

// subscribe for events
void sqc_backend_connection::subscribe_events() {
    m_notify_connection = m_notify_center.subscribe( 
            std::tr1::bind( &sqc_backend_connection::notify_callback, this, _1, _2 ) );
}

// unsubscribe for events
void sqc_backend_connection::unsubscribe_events() {
    m_notify_center.unsubscribe( m_notify_connection );
}

// notification callback
void sqc_backend_connection::notify_callback( 
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
    
    if ( server_config_provider_id == provider_id ) {
     
        //
    	// config provider events
        //
        if ( server_config_game_server_ready_event == event_id ) {
        	on_game_server_ready();
        }
        else if ( server_config_static_server_ready_event == event_id ) {
            on_static_server_ready();
        }
        else if ( server_config_no_static_servers_event == event_id ) {
            on_static_server_error();
        }
        else if ( server_config_no_game_servers_event == event_id ) {
            on_game_server_error();
        }
        
    } else if ( social_networks == provider_id ) {
     
        //
        // social networks events
        //
        if ( network_event_loggin_complete == event_id ) {
            on_login_to_social_network_ready();
        } else if ( network_event_loggin_error == event_id ) {
            on_login_to_social_network_error();
        }
        
    } else if ( remote_static_objects_id == provider_id ) {
     
        //
        // remote static objects downloader
        //
        if ( remote_static_objects_ready_event == event_id ) {
            on_download_static_objects_ready(); // (2 process done)
			            
        } else if ( remote_static_objects_error_event == event_id ) {
            on_download_static_objects_error();
        }
    }
}

void sqc_backend_connection::on_http_complete( 
    sqc_net_path url, 
    sqc_net_data const &raw ) {
    
    on_servers_config_received( raw );
}

void sqc_backend_connection::on_http_error( 
    sqc_net_path path, 
    sqc_net_error const &error ) {
    
    on_servers_config_received_error();
}

//
//	progress window
//

void sqc_backend_connection::show_progress_window() {
    
	if ( m_progress_wnd ) {
	    return;
    }
    
    sqc_show_login_progress_params params;
    m_progress_wnd = m_ui.show_login_progress_window( params );
    if ( !m_progress_wnd ) {
        sqc_error() << "back-end: unable to create progress window";
        return;
    }
    
    m_progress_wnd->set_destroy_handler( 
    	std::tr1::bind( &sqc_backend_connection::on_progress_window_destroy, this ) );

    
    sqc_info() << "back-end: show progress window";
}

void sqc_backend_connection::hide_progress_window() {
	if ( !m_progress_wnd ) {
	    return;
    }
    
    sqc_info() << "back-end: hide progress window";
	m_progress_wnd->end_dialog();
}

void sqc_backend_connection::on_progress_window_destroy() {
	m_progress_wnd.reset();
}

//
// show message box
//
void sqc_backend_connection::show_message_box( 
	const msg_box_type type,
    const sqc_string& str_title,
    const sqc_string& str_text,
    const sqc_string& str_button_text ) {
    
    hide_message_box();
    
    sqc_message_box_params params;
    params.dlg_title	= str_title;
    params.dlg_text		= str_text;
    params.button_text	= str_button_text;
    
    m_message_box = m_ui.show_message_box( params );
    if ( !m_message_box ) {
        sqc_error() << "back-end: unable to create message box";
        return;
    }
    
    m_message_box->set_destroy_handler( 
    	std::tr1::bind( &sqc_backend_connection::on_message_box_destroy, this, type ) );
        
    sqc_info() << "back-end: show message box: " << "\"" << str_text << "\"";
}

void sqc_backend_connection::hide_message_box() {
    if ( m_message_box ) {
        sqc_info() << "back-end: hide message box";
    	m_message_box->end_dialog();
        m_message_box.reset();
    }
}

// when user close error msg_box, try to perfome some operation depend of error code
void sqc_backend_connection::on_message_box_destroy(
	const msg_box_type type ) {
	m_message_box.reset();
    
    if ( msb_box_server_config_error == type ) {
	    sqc_info() << "back-end: msb_box_server_config_error close";
    	// try full reconect
    	connect();
    }
    else if ( msb_box_static_server_error == type ) {
	    sqc_info() << "back-end: msb_box_static_server_error close";
    	// try full reconect
        connect();
    }
    else if ( msb_box_download_static_object_error == type ) {
    	// try to download again
        // TODO: download only specific objects
        sqc_info() << "back-end: msb_box_download_static_object_error close";
        download_static_objects();
    }
    else if ( msb_box_game_server_error == type ) {
    	// select new social network
        sqc_info() << "back-end: msb_box_game_server_error close";
        reconnect_to_social_network();
    }
    else if ( msb_box_socnet_login_error == type ) {
    	// select new social network
        sqc_info() << "back-end: msb_box_socnet_login_error close";
        reconnect_to_social_network();
    } else {
    	sqc_assert( false );
    }
}

//
//	show select network dialog
//
void sqc_backend_connection::show_select_network_dlg() {

	hide_select_network_dlg();
    
    sqc_select_network_params params;
    params.user_can_close_dialog = ( connection_socnetwork == m_connection_type );
    params.callback = 
	    std::tr1::bind( &sqc_backend_connection::on_select_social_network_ready, this, _1 );
    
    m_select_network_dlg = m_ui.show_select_network_dialog( params );
    if ( !m_select_network_dlg ) {
        sqc_error() << "back-end: unable show select network dialog";
        return;
    }
    
    m_select_network_dlg->set_destroy_handler( 
    	std::tr1::bind( &sqc_backend_connection::on_select_network_dlg_destroy, this ) );
    
    m_select_network_dlg->set_close_button_action( 
    	std::tr1::bind( &sqc_backend_connection::on_user_close_select_network_dlg, this ) );
    m_select_network_dlg->set_back_button_action( 
    	std::tr1::bind( &sqc_backend_connection::on_user_close_select_network_dlg, this ) );

    sqc_info() << "back-end: show select network dialog";
}

void sqc_backend_connection::hide_select_network_dlg() {
    if ( m_select_network_dlg ) {
        sqc_info() << "back-end: select network dialog";
    	m_select_network_dlg->end_dialog();
        m_select_network_dlg.reset();
    }
}

void sqc_backend_connection::on_select_network_dlg_destroy() {
    m_select_network_dlg.reset();
}

void sqc_backend_connection::on_user_close_select_network_dlg() {
    // hide progress window
    if ( connection_socnetwork == m_connection_type ) {
        sqc_info() << "back-end: select_network_dlg_close - hide progress window";
        hide_progress_window();
    }
}

END_NAMESPACE_SQC_FRAMEWORK
