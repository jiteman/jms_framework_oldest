#pragma once

#include "../framework/sqc_framework.h"
#include "sqc_country_base_ui.h"
#include "../sqc/sqc_base.h"

NAMESPACE_SQC_FRAMEWORK


namespace names {
    static const sqc_string	startup_url = "http://mobile.socialquantum.com/mobile_assets/";
	static const sqc_string	server_cfg_yml = "apps_ios.yml";
};

using namespace framework;
using namespace info;

enum sqc_request_type {
    request_type_server_config,
    request_type_objects,
    request_type_hierarchy,
    request_type_quests,
    request_type_requests,
    request_type_textures_plist,
    request_type_object_localization_strings,
    request_type_quest_localization_strings,
    request_type_binary_objects
};

//
// sqc_server_config
//
class sqc_server_config {
public:
    virtual void init() {} 
    
    virtual void parse_config(sqc_net_data const &data) {}
    virtual void choose_static_server(sqc_net_param const &params = sqc_net_param()) {}
    virtual void choose_game_server(sqc_network_type network_type, sqc_net_param const &params = sqc_net_param()) {}
    
    virtual void handle_timer() {}
    
    virtual sqc_string get_startup_url(sqc_string const &filename) = 0; 
    virtual sqc_string get_static_server_url(sqc_string const &filename) = 0; 
    virtual sqc_string get_game_server_url() = 0;
    virtual sqc_string get_textures_subfolder() = 0;
    
    virtual const char *get_yml_name( sqc_request_type request_type ) const = 0;
};

// full path to yaml files
namespace path {
	sqc_string	get_yml_full_path( const sqc_server_config& cfg, sqc_request_type request_type );
};


//
// sqc_server_config
//
class sqc_server_config_base 
	: public sqc_server_config {
    enum sqc_config_request {
	    config_request_unknown,
        config_request_static_server,
        config_request_game_server,
    };
    
    struct app_info {
        sqc_string app_id;
        sqc_string app_code;
        sqc_string_list servers;
        sqc_string_list servers_statics;
    };

public:
    sqc_server_config_base(sqc_http_service &http_service);
    void reset();
    
    virtual void init();
    
    virtual void parse_config(sqc_net_data const &data);
    virtual void choose_static_server(sqc_net_param const &params = sqc_net_param());
    virtual void choose_game_server(sqc_network_type network_type,
                                    sqc_net_param const &params = sqc_net_param());
    
    virtual void handle_timer();
    
    virtual sqc_string get_startup_url(sqc_string const &filename); 
    virtual sqc_string get_static_server_url(sqc_string const &filename); 
    virtual sqc_string get_game_server_url();
    virtual sqc_string get_textures_subfolder();
protected:
    void on_http_complete(sqc_config_request request_type, sqc_net_path url, sqc_net_data const &raw);
    void on_http_error(sqc_config_request request_type, sqc_net_path url, sqc_net_error const &error);
    
    void check_servers(sqc_config_request request_type, sqc_string_list &servers);
    void set_servers(); 
    
    sqc_string app_code(const sqc_string &net_key);     
protected:
	std::map<sqc_string, app_info>  m_apps_info;
    
    sqc_http_service                &m_http_service;
    
    sqc_string                      m_game_server;
    sqc_string                      m_static_server;
    
    sqc_string_vector               m_live_servers;
    sqc_string_vector               m_live_static_servers;
    
    sqc_string                      m_app_name;
    sqc_string                      m_startup_url;
    
    int                             m_time;
    int                             m_timeout;
    
    sqc_net_param                   m_net_param;
    
    std::map<sqc_network_type, sqc_string> m_network_keys;
    sqc_config_request				m_current_request;
    
    sqc_string                      m_textures_subfolder;
};

//
// sqc_static_objects_downloader
//
class sqc_static_objects_downloader {
public:
    sqc_static_objects_downloader( sqc_server_config& server_config,
                              sqc_http_service& http_service,
                              sqc_notify_center& notify_center );
    
    void			reset();
    void			download();
	    
protected:
    void    on_file_received( sqc_request_type request_type, 
                                     sqc_string const &url, 
                                     sqc_net_data const &raw );
    void   test_all_files_download();
    
protected:
    virtual void	on_http_complete( sqc_request_type request_type, 
                                     sqc_net_path url, 
                                     sqc_net_data const &raw );
    virtual void    on_http_error( sqc_request_type request_type, 
                                  sqc_net_path path, 
                                  sqc_net_error const &error );
protected:
    sqc_server_config&		m_server_config;
	sqc_http_service&		m_http_service;
    sqc_notify_center&		m_notify_center;

    typedef std::list<sqc_request_type>	download_task;
    
    download_task		m_tasks;
    int					m_success_task_count;
    int					m_fail_task_count;
};

//
// sqc_backend_connection 
//
class sqc_backend_connection : public sqc_noncopyable {

	enum msg_box_type {
    	msb_box_server_config_error,
        msb_box_static_server_error,
        msb_box_download_static_object_error,
        msb_box_game_server_error,
        msb_box_socnet_login_error,
    };
    
public:
	sqc_backend_connection(sqc_server_config&   	 server_config,
		                   sqc_notify_center&   	 notify_center,
                           sqc_social_networks& 	 networks, 
                           sqc_http_service&   		 http_service,
                           sqc_country_base_ui_face& ui,
                           sqc_preferences&			 preferences );
    virtual ~sqc_backend_connection();
protected:
    enum connection_type {
        connection_unknown,
        connection_full,
        connection_socnetwork,
    };

    // reset previouse connection
    void			reset();
    void			hide_ui();
    
public:
    // connect
    void    		connect();
    // just connect to social network
    void    		connect_to_social_network();
    
    bool			get_game_server_login_params( sqc_string& game_server,
                                                  sqc_string& user_id,
                                                  sqc_string& access_token );
protected:
	// reconect to new network without full reset()
    void    		reconnect_to_social_network();
    
public:
    virtual void	handle_timer();

protected:
    // first stage
    void			download_servers_config();
    void			on_servers_config_received( sqc_string const &raw );
    void			on_servers_config_received_error();
    
    void			select_static_server();
    void			on_static_server_ready();
    void			on_static_server_error();
    
    // 1-st thread tasks
    void			download_static_objects();
    void			on_download_static_objects_ready();
    void			on_download_static_objects_error();
    // end of 1-st thread tasks
    
    // second stage 
    // 2-nd thread tasks
    void			select_social_network( sqc_network_type prefered_network = sqc_network_none );
    void			on_select_social_network_ready( const sqc_network_type new_network );

    void			select_game_server();
    void			on_game_server_ready();
    void			on_game_server_error();

    void			login_to_social_network();
    void			on_login_to_social_network_ready();
    void			on_login_to_social_network_error();
    // end of 2-nd thread tasks
    
    // all done
    void			analize_all_ready();
    
protected:
	sqc_network_type	load_last_network();
    void				store_last_network( sqc_network_type type );
protected:
    // subscribe for events
    void			subscribe_events();
    // unsubscribe for events
    void			unsubscribe_events();
    // notification callback
    void			notify_callback( const sqc_provider_id& provider_id, 
                         const sqc_event_id& event_id);    
    
protected:
    virtual void	on_http_complete( sqc_net_path url, 
                                     sqc_net_data const &raw );
    virtual void    on_http_error( sqc_net_path url, 
                                  sqc_net_error const &error );
    
protected:
	connection_type					m_connection_type;
    
    bool							m_download_static_objects_done;
    bool							m_login_to_network_done;

    sqc_listener_connection         m_notify_connection;

    sqc_static_objects_downloader	m_static_objects;

    sqc_network_type 				m_current_network;
    
    sqc_server_config&              m_server_config;
    sqc_notify_center&              m_notify_center;
    sqc_social_networks&    		m_networks;
    sqc_http_service&			    m_http_service;
    sqc_country_base_ui_face&		m_ui;
    sqc_preferences&				m_preferences;
    
//
//	progress window
//
protected:
	void					show_progress_window();
    void					hide_progress_window();
    void					on_progress_window_destroy();
    milk::milk_dialog_ptr	m_progress_wnd;
    
protected:
//
// show message box
//
	void					show_message_box( const msg_box_type type,
                                          const sqc_string& str_title,
    									  const sqc_string& str_text,
                                          const sqc_string& str_button_text );
    void					hide_message_box();
    void					on_message_box_destroy( const msg_box_type type );
    milk::milk_dialog_ptr	m_message_box;
    
    
protected:
//
//	show select network dialog
//
	void					show_select_network_dlg();
    void					hide_select_network_dlg();
    void					on_select_network_dlg_destroy();
    void					on_user_close_select_network_dlg();

    milk::milk_dialog_ptr	m_select_network_dlg;

};

//
// backend connection provider events id
//
declare_notification_provider_id( backend_connection_provider_id )

// backend connection notification events id
declare_notification_event_id( backend_download_static_objects_complete_event )
//declare_notification_event_id( backend_download_static_objects_error_event )

declare_notification_event_id( backend_login_to_social_network_complete_event )
//declare_notification_event_id( backend_login_to_social_network_error_event )


END_NAMESPACE_SQC_FRAMEWORK
