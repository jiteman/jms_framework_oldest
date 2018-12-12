/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_command_processor.h"
#include "sqc_xml.h"
#include "sqc_plist.h"

using namespace std::tr1::placeholders;


NAMESPACE_SQC_PROCESSOR

namespace names {
    static const sqc_string stat_server_dir = sqc_text( "get_user_stat" );
    static const sqc_string cmd_server_dir  = sqc_text( "process" );

    static const sqc_string iauth           = sqc_text( "iauth" );
    static const sqc_string user_id         = sqc_text( "user_id" );
    static const sqc_string gift_id   		= sqc_text( "gift_id" );
    
	static const sqc_string command         = sqc_text( "command" );
    
    static const sqc_string item_id         = sqc_text( "item_id" );
    static const sqc_string rotation        = sqc_text( "rotation" );
    static const sqc_string klass           = sqc_text( "klass" );
    
    static const sqc_string x               = sqc_text( "x" );
    static const sqc_string y               = sqc_text( "y" );
    
    static const sqc_string tax             = sqc_text( "new_tax" );
    
    static const sqc_string friend_id       = sqc_text( "view_friend_id" );
    static const sqc_string second_user_id  = sqc_text( "second_user_id" );

    static const sqc_string first_name      = sqc_text( "first_name" );
    static const sqc_string first_request   = sqc_text( "first_request" );

    static const sqc_string quantity        = sqc_text( "quantity" );

    static const sqc_string fiscal_agent_id		= sqc_text( "in" );
    static const sqc_string municipal_oficer_id	= sqc_text( "out" );
    
    static const sqc_string auto_param			= sqc_text( "auto" );
    
    static const sqc_string create_command_name 	= sqc_text( "create" );
    static const sqc_string move_command_name		= sqc_text( "move" );
    static const sqc_string clean_command_name		= sqc_text( "clean" );
    static const sqc_string pick_command_name		= sqc_text( "pick" );
    static const sqc_string sell_command_name		= sqc_text( "sell" );
    static const sqc_string tick_command_name   	= sqc_text( "tick" );
    static const sqc_string apply_command_name 		= sqc_text( "apply" );
    static const sqc_string put_command_name    	= sqc_text( "put" );
    static const sqc_string put_switch_item_name    = sqc_text( "switch_input" );
    static const sqc_string cancel_command_name		= sqc_text( "cancel" );
    static const sqc_string change_tax_command_name	= sqc_text( "change_tax" );
    static const sqc_string sell_gift_command_name  = sqc_text( "sell_gift" );
    static const sqc_string apply_gift_command_name = sqc_text( "apply_gift" );
    static const sqc_string receive_gift_command_name = sqc_text( "receive_gift" );
    static const sqc_string send_gift_command_name	  = sqc_text( "send_gift" );
    static const sqc_string move_to_pen_command_name  = sqc_text( "move_to_pen" );
    static const sqc_string send_shop_gift_command_name	= sqc_text( "gift_from_shop" );
    static const sqc_string ask_gift_command_name   	= sqc_text( "ask_friends" );
    static const sqc_string sell_barn_command_name      = sqc_text( "sell_barn" );
    static const sqc_string set_io_command_name      	= sqc_text( "set_io" );
};

void sqc_command::pack_params( sqc_name_value_list& list ) {
	//list.push_back( sqc_name_value_pair( names::iauth, get_command_name() ) );
    //list.push_back( sqc_name_value_pair( names::user_id, get_command_name() ) );
	list.push_back( sqc_name_value_pair( names::command, get_command_name() ) );
	//sqc_string m_user_id;
}

sqc_string sqc_command::pack_bool( bool b ) {
	return ( b ? sqc_text( "1" ) : sqc_text( "0" ) );
}


sqc_string sqc_command::pack_int( int i ) {
	sqc_stringstream out;
    out << i;
    return out.str();
}

sqc_string sqc_command::get_server_dir() {
    return names::cmd_server_dir;
}

int sqc_command::get_object_id() {
    return 0;
}


sqc_string sqc_create_command::get_command_name() {
	return names::create_command_name;
}

void sqc_create_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    sqc_assert( m_object_type.size() );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( 0 ) ) );
    list.push_back( sqc_name_value_pair( names::klass, m_object_type ) );
    list.push_back( sqc_name_value_pair( names::rotation, pack_bool( m_rotation ) ) );
    list.push_back( sqc_name_value_pair( names::x, pack_int( m_create_point.x) ) );
    list.push_back( sqc_name_value_pair( names::y, pack_int( m_create_point.y) ) );
}

sqc_string sqc_move_command::get_command_name() {
	return names::move_command_name;
}

void sqc_move_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) );
    list.push_back( sqc_name_value_pair( names::rotation, pack_bool( m_rotation ) ) );
    list.push_back( sqc_name_value_pair( names::x, pack_int( m_coords_point.x ) ) );
    list.push_back( sqc_name_value_pair( names::y, pack_int( m_coords_point.y ) ) );
}

sqc_string sqc_clean_command::get_command_name() {
	return names::clean_command_name;
}

int sqc_clean_command::get_object_id() {
    return m_object_id;
}

void sqc_clean_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) );
    if ( m_auto_points ) {
	    list.push_back( sqc_name_value_pair( names::auto_param, pack_int( m_auto_points ) ) );
    }
}

sqc_string sqc_tick_command::get_command_name() {
	return names::tick_command_name;
}

void sqc_tick_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) );
}

sqc_string sqc_pick_command::get_command_name() {
	return names::pick_command_name;
}

int sqc_pick_command::get_object_id() {
    return m_object_id;
}

void sqc_pick_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) );
    if ( m_auto_points ) {
	    list.push_back( sqc_name_value_pair( names::auto_param, pack_int( m_auto_points ) ) );
    }
    
}
    
sqc_string sqc_sell_command::get_command_name() {
	return names::sell_command_name;
}

void sqc_sell_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) );
}

sqc_string sqc_apply_command::get_command_name() {
	return names::apply_command_name;
}

void sqc_apply_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::klass, m_object_type ) );    
}

sqc_string sqc_put_command::get_command_name() {
	return names::put_command_name;
}

void sqc_put_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::klass, m_object_type ) );    
}

sqc_string sqc_switch_item_command::get_command_name() {
	return names::put_switch_item_name;
}

void sqc_switch_item_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) ); 
    list.push_back( sqc_name_value_pair( names::klass, m_type_item ) );
}

sqc_string sqc_put_command_2_params::get_command_name() {
	return names::put_command_name;
}

void sqc_put_command_2_params::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
}

sqc_string sqc_cancel_command::get_command_name() {
	return names::cancel_command_name;
}

void sqc_cancel_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
}

// change tax admin tax
sqc_string sqc_change_tax_command::get_command_name() {
	return names::change_tax_command_name;
}

void sqc_change_tax_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::tax, pack_int( m_tax_value ) ) );
}


// set_io command (set fiscal agent and municipal officer)
sqc_string sqc_io_command::get_command_name() {
	return names::set_io_command_name;
}

void sqc_io_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::fiscal_agent_id, m_fiscal_agent_id ) );
    list.push_back( sqc_name_value_pair( names::municipal_oficer_id, m_municipal_oficer_id ) );
}

// view friend field command
sqc_string sqc_view_friend_field_command::get_command_name() {
    sqc_assert( false );
    return sqc_text( "" );
}

void sqc_view_friend_field_command::pack_params( sqc_name_value_list& list ) {
	//sqc_command::pack_params( list ); - dont call super class to avoid pack command name param
    list.push_back( sqc_name_value_pair( names::friend_id, m_friend_id ) );
}

sqc_string sqc_view_friend_field_command::get_server_dir() {
    return names::stat_server_dir;
}


sqc_string sqc_view_own_field_command::get_command_name() {
    sqc_assert( false );
    return sqc_text( "" );
}

void sqc_view_own_field_command::pack_params( sqc_name_value_list& list ) {
	//sqc_command::pack_params( list ); - dont call super class to avoid pack command name param
    list.push_back( sqc_name_value_pair( names::first_name, "" ) );
    list.push_back( sqc_name_value_pair( names::first_request, pack_bool( true ) ) );
}

sqc_string sqc_view_own_field_command::get_server_dir() {
    return names::stat_server_dir;
}

// sell_gift command
sqc_string sqc_sell_gift_command::get_command_name() {
	return names::sell_gift_command_name;	
}

void sqc_sell_gift_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
}

// apply_gift command
sqc_string sqc_apply_gift_command::get_command_name() {
	return names::apply_gift_command_name;	
}

void sqc_apply_gift_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::gift_id, pack_int( m_gift_id ) ) );
    list.push_back( sqc_name_value_pair( names::klass, m_klass ) );
}

// send_gift command
sqc_string sqc_send_gift_command::get_command_name() {
	return names::send_gift_command_name;	
}

void sqc_send_gift_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::second_user_id, m_second_user_id ) );
}

// ask   
sqc_string sqc_ask_material_gift_command::get_command_name()
{
    return names::ask_gift_command_name;
}

void sqc_ask_material_gift_command::pack_params( sqc_name_value_list& list )
{
    sqc_command::pack_params( list );
    
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
}

// receive
sqc_string sqc_receive_gift_command::get_command_name()
{
	return names::receive_gift_command_name;
}

void sqc_receive_gift_command::pack_params( sqc_name_value_list& list )
{
	sqc_command::pack_params( list );

    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_item_id ) ) );
    list.push_back( sqc_name_value_pair( names::klass, m_klass ) );
    list.push_back( sqc_name_value_pair( names::rotation, pack_int( m_rotation ) ) );
    list.push_back( sqc_name_value_pair( names::x, pack_int( m_x ) ) );
    list.push_back( sqc_name_value_pair( names::y, pack_int( m_y ) ) );
}
    
// move pen command
sqc_string sqc_move_to_pen_command::get_command_name() {
	return names::move_to_pen_command_name;
}

int sqc_move_to_pen_command::get_object_id() {
    return m_object_id;
}

void sqc_move_to_pen_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id, pack_int( m_object_id ) ) );
}


// send gift from shop command - build object
sqc_string sqc_send_shop_gift_command::get_command_name() {
	return names::send_shop_gift_command_name;
}

void sqc_send_shop_gift_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::klass, m_object_type ) );
    list.push_back( sqc_name_value_pair( names::second_user_id, m_second_user_id ) );
}

// sell barn command
sqc_string sqc_sell_barn_command::get_command_name() {
	return names::sell_barn_command_name;
}

void sqc_sell_barn_command::pack_params( sqc_name_value_list& list ) {
	sqc_command::pack_params( list );
    list.push_back( sqc_name_value_pair( names::item_id,  pack_int( m_object_id ) ) );
    list.push_back( sqc_name_value_pair( names::quantity, pack_int( m_quantity ) ) );
}


//
// download initial XML and run commands
//

sqc_command_processor::sqc_command_processor( 
	sqc_backend_connection& backend_connection,
    sqc_notify_center& notify,
    sqc_http_service& http ) 
	: m_backend_connection( backend_connection )
    , m_notify( notify )
    , m_http( http )
    , m_command_delay( 1 )
    , m_last_command_time( 0 ){
        
    m_notify_connection = m_notify.subscribe( 
    	std::tr1::bind( &sqc_command_processor::notify_callback, this, _1, _2 ) );
}

sqc_command_processor::~sqc_command_processor() {
    m_notify.unsubscribe( m_notify_connection );
}

void sqc_command_processor::get_init_xml( raw_xml& xml ) const {
    sstl::sstl_mutex_lock   lock( m_access );
    xml = m_init_xml;
}

int sqc_command_processor::get_command_delay() {
    return m_command_delay;
}

//	request initial xml (after new game server is choosed)
bool sqc_command_processor::request_initial_xml() {
    
    sqc_string game_server, user_id, access_token;
    m_backend_connection.get_game_server_login_params(
								game_server, user_id, access_token );
    
    
    //sqc_net_path url = "http://88.212.222.164/city_server_vk_prod/get_user_stat";
    // format URL
    sqc_net_path url = game_server;
    url += sqc_string( "/get_user_stat" );
    
    // format body
    sqc_net_string body;
    {
        sqc_stringstream out;
        	out << sqc_string( "iauth=" )
        		<< access_token
        		<< sqc_string( "&user_id=" )
        		<< user_id
 		       << sqc_string( "&first_name=&first_request=true" );
	    body = out.str();
    }
    

    sqc_info() 
        << "command_processor: download initial xml from \""
        << game_server
        << "\" body: \""
    	<< body
    	<< "\"";
    
    //sqc_net_string body = "iauth=8df1529477b55575cdd5d0fca3d0eb80&user_id=711853&first_name=&first_request=true";
    
    sqc_net_param   params;
    {
        params.net_metod		= sqc_net_post_metod;
        params.request_params	= body;
        params.complete_callback = std::tr1::bind( 
                        &sqc_command_processor::on_http_complete, this, _1, _2 );
        params.error_callback = std::tr1::bind( 
                        &sqc_command_processor::on_http_error, this, _1, _2 );
    }
    
    m_http.download( url, params );
    
    return true;
}

void sqc_command_processor::on_initial_xml_received( sqc_net_data const &raw ) {
    sqc_info() 
        << "command_processor: download xml complete "
        << raw.size()
        << " bytes";
    sqc_info() 
        << "xml: " << raw;

    {
    	sstl::sstl_mutex_lock   lock( m_access );
        m_init_xml = raw;
    }
    
    {
        using namespace xml;
        
        xml_doc xml( m_init_xml );
        if( !xml.is_valid() ) {
            sqc_info() << "failed to parse initial xml";
            return;
        }
        
        xml_node_list   node_entries;
        xml.get_root()->get_childs( node_entries );
        
        sqc_string error_text;
        
        for( xml_node_list::const_iterator i = node_entries.begin(); i != node_entries.end(); ++i ) {
            xml_node_ptr    node( *i );
            
            if (node->get_name() == "error") {
                error_text = node->get_value();
                break;
            }
        }
        
        if (error_text.size()) {
            // TODO show alert dialog
            sqc_info() << "error message: " << error_text;
        }
    }
    
    m_notify.fire_event( command_processor_provider_id,
                         command_processor_initial_xml_complete_event,
                         call_async );
        
}

void sqc_command_processor::on_initial_xml_error() {
    sqc_error() << "command_processor: download xml failed";
    
    //m_notify.fire_event( command_processor_provider_id, 
      //                   field_downloader_initial_xml_error_event );
    
}


void sqc_command_processor::on_http_complete( 
    sqc_net_path url,
    sqc_net_data const &raw ) {
    
    on_initial_xml_received( raw );
}

void sqc_command_processor::on_http_error( 
    sqc_net_path url,
    sqc_net_error const &error ) {
    
    on_initial_xml_error();
}

void sqc_command_processor::handle_timer() {
    if (m_last_command_time && time(NULL) - m_last_command_time > m_command_delay) {
        next_command();
    }
}

void sqc_command_processor::next_command() {
    sqc_command_vector::iterator it = m_commands.begin();
    
    if (it != m_commands.end()) {
        execute_command(*it);
        it = m_commands.erase(it);
        
        if (it != m_commands.end()) {
            m_notify.fire_event( command_processor_provider_id,
                                command_processor_command_progress_event,
                                call_async,
                                (*it)->get_object_id() );
            
            m_last_command_time = time(NULL);
        }
        else {
            m_last_command_time = 0;
            m_notify.fire_event( command_processor_provider_id,
                                command_processor_command_all_completed_event,
                                call_async );
        }
        
    }
}
 
void sqc_command_processor::schedule( sqc_command_ptr command, sqc_command_priority priority ) {
    
	if ( !command ) {
    	return;
    }
    
	if ( command_priority_now == priority ) {
        execute_command(command);
    }
    else if ( command_priority_idle == priority ) {
        if (!m_last_command_time) {
            m_last_command_time = time(NULL);
        }
        m_commands.push_back(command);
        m_notify.fire_event( command_processor_provider_id,
                            command_processor_command_queued_event,
                            call_async,
                            command->get_object_id() );
        
        if (m_last_command_time == time(NULL)) //this is a first command - push "progress_event" (needs review)
        {
          m_notify.fire_event( command_processor_provider_id,
             command_processor_command_progress_event,
             call_async,
             command->get_object_id() );

        }
    }
}

void sqc_command_processor::execute_command( sqc_command_ptr command ) {
    //
	// request login params
    //
    sqc_string	game_server;
    sqc_string	user_id;
    sqc_string	access_token;
    
    m_backend_connection.get_game_server_login_params( game_server, user_id, access_token );
    
    //
    //  format URL
    //
    sqc_string url = game_server;
    url += sqc_text( "/" );
    url += command->get_server_dir();
    
    
	sqc_server_cmd_type cmd_type = command->get_cmd_type();
    
    //
    //	pack commands oparameters
    //
    sqc_name_value_list pairs;
    pairs.push_back( sqc_name_value_pair( names::iauth, access_token ) );
    pairs.push_back( sqc_name_value_pair( names::user_id, user_id ) );
    
    command->pack_params( pairs );
    
    //
    //	create body from pairs
    //
    sqc_string body;
    create_body( pairs, body );
    
    sqc_info()
    << "command_processor: create command " 
    << print_command_type( cmd_type )
    << " with params: \""
    << body
    << "\"";
    
    //
    //	POST data to server
    //
    sqc_net_param   net_params;
    {
        net_params.net_metod		= sqc_net_post_metod;
        net_params.request_params	= body;
        net_params.complete_callback = std::tr1::bind( 
                                                      &sqc_command_processor::on_post_command_complete, this, cmd_type, _1, _2 );
        net_params.error_callback = std::tr1::bind( 
                                                   &sqc_command_processor::on_post_command_error, this, cmd_type, _1, _2 );
    }
    
    m_http.download( url, net_params );
}

void sqc_command_processor::create_body( 
	const sqc_name_value_list& pairs, 
    sqc_string& body ) {
    
    sqc_stringstream out;
    for ( sqc_name_value_list::const_iterator it = pairs.begin();
    	it != pairs.end(); ++it ) {
        
        if ( it != pairs.begin() ) {
	        out << "&";
        }
        
        out << it->name
        	<< "="
            << it->value;
    }
    
    body = out.str();
}

//
//	post command callbacks
//
void sqc_command_processor::on_post_command_complete( 
    const sqc_server_cmd_type cmd_type,
    sqc_net_path url, 
    sqc_net_data const &raw ) {

    sqc_info() 
        << "command_processor: execute "
        << print_command_type( cmd_type )
        << " command complete. response is "
        << raw.size()
        << " bytes";
    
    m_notify.fire_event( command_processor_provider_id,
                        command_processor_command_successfully_event,
                        call_async,
                        cmd_type );

    on_initial_xml_received( raw );
}

void sqc_command_processor::on_post_command_error( 
    const sqc_server_cmd_type cmd_type,
    sqc_net_path url, 
    sqc_net_error const &error ) {

    sqc_info() 
        << "command_processor: error execute "
        << print_command_type( cmd_type )
        << " command. Error code:" 
        << error;
}


// notification callback
void sqc_command_processor::notify_callback( 
    const sqc_provider_id& provider_id, 
    const sqc_event_id& event_id ) {
    
    if ( backend_connection_provider_id == provider_id ) {
        
        //
    	//  backend connection events
        //
        if ( backend_login_to_social_network_complete_event == event_id ) {

            //download xml after social network is changed
        	request_initial_xml();
        }
    }
}


END_NAMESPACE_SQC_PROCESSOR
