/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_social_network.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK

using namespace std::tr1::placeholders;

//
//  user profile
//
sqc_user_profile::sqc_user_profile()
	: m_gender( sqc_male )
    , m_in_game( false )
    , m_have_gift( false )
    , m_level( 0 ) {
}

sqc_user_profile::~sqc_user_profile() {
}
    
const sqc_string& sqc_user_profile::get_first_name() const {
    return m_first_name;
}

void sqc_user_profile::set_first_name( const sqc_string& name ) {
    m_first_name = name;
}

const sqc_string& sqc_user_profile::get_last_name() const {
    return m_last_name;
}

void sqc_user_profile::set_last_name( const sqc_string& name ) {
    m_last_name = name;
}

const sqc_string& sqc_user_profile::get_aliase() const {
    return m_user_aliase;
}

void sqc_user_profile::set_aliase( const sqc_string& aliase ) {
    m_user_aliase = aliase;
}

const sqc_user_id& sqc_user_profile::get_user_id() const {
    return m_user_id;
}

void sqc_user_profile::set_user_id( const sqc_user_id& id ) {
    m_user_id = id;
}

const sqc_gender sqc_user_profile::get_gender() const {
    return m_gender;
}

void sqc_user_profile::set_gender( const sqc_gender gender ) {
    m_gender = gender;
}

const sqc_string& sqc_user_profile::get_avatar_url() const {
    return m_avatar_url;
}

void sqc_user_profile::set_avatar_url( const sqc_string& avatar_url ) {
    m_avatar_url = avatar_url;
}

const bool sqc_user_profile::is_in_game() const {
    return m_in_game;
}

void sqc_user_profile::set_in_game( const bool in_game ) {
    m_in_game = in_game;
}

const bool sqc_user_profile::is_have_gift() const {
    return m_have_gift;
}

void sqc_user_profile::set_have_gift( const bool have_gift ) {
    m_have_gift = have_gift;
}

const int sqc_user_profile::get_level() const {
	return m_level;
}

void sqc_user_profile::set_level( int level ) {
	m_level = level;
}


//
// sqc_social_networks implementation
//
sqc_social_networks::sqc_social_networks( 
    sqc_social_networks_factory& factory ) 
        : m_factory( factory ) {
}

sqc_social_networks::~sqc_social_networks() {
}

// list of available networks
void sqc_social_networks::get_available_networks( 
    network_list& list ) const {
    
    // TODO: move to platform-specific factory
    list.push_back( sqc_network_facebook );
#if !defined(__ANDROID__)    
    list.push_back( sqc_network_game_center );
#endif
    list.push_back( sqc_network_moi_mir );
    list.push_back( sqc_network_odnoklassniki );
    list.push_back( sqc_network_open_feint );
    list.push_back( sqc_network_social_quantum );
    list.push_back( sqc_network_vkontakte );
}

sqc_network_type sqc_social_networks::current_network() const {
    
    if ( !m_active_network ) {
        return sqc_network_none;
    }
    return m_active_network->network_type();
}

// retrieve network 
sqc_string sqc_social_networks::get_network_name(
    const sqc_network_type network ) const {

    sqc_string str_name;
    sqc_string_resources& res = framework().strings();

    if ( sqc_network_facebook == network ) {
        str_name = res.load( "*CommonFacebookLabel", "Facebook" );
    } else if ( sqc_network_game_center == network ) {
        str_name = res.load( "*CommonGameCenterLabel", "Game Center" );
    } else if ( sqc_network_moi_mir == network ) {
        str_name = res.load( "*CommonMoiMirLabel", "My World" );
    } else if ( sqc_network_odnoklassniki == network ) {
        str_name = res.load( "*CommonOdnoklassnikiLabel", "Odnoklassniki" );
    } else if ( sqc_network_open_feint == network ) {
        str_name = res.load( "*CommonOpenFeintLabel", "OpenFeint" );
    } else if ( sqc_network_social_quantum == network ) {
        str_name = res.load( "*CommonSocQuaLabel", "Social Quantum" );
    } else if ( sqc_network_vkontakte == network ) {
        str_name = res.load( "*CommonVKontakteLabel", "VKontakte" );
    }
    
    // log error
    if ( str_name.empty() ) {
        sqc_error() 
            << "social_networks error: unable to determine network name: "
            << print_social_network( current_network() );
        str_name = print_social_network( current_network() );
    }
    
    return str_name;
}

// retrieve network images
sqc_string sqc_social_networks::get_network_image(
    const sqc_network_type network ) const {
    
    static const image_names network_facebook_images(
                        "social_net_fb_icon", 
                        "social_net_fb_icon@2x",
                        "social_net_fb_icon_ipad" );
    
    static const image_names network_game_center_images(
                        "social_net_gc_icon", 
                        "social_net_gc_icon@2x",
                        "social_net_gc_icon_ipad" );
    
    static const image_names network_moi_mir_images(
                        "social_net_mm_icon", 
                        "social_net_mm_icon@2x",
                        "social_net_mm_icon_ipad" );
    
    static const image_names network_odnoklassniki_images(
                        "social_net_od_icon", 
                        "social_net_od_icon@2x",
                        "social_net_od_icon_ipad" );
    
    static const image_names network_open_feint_images(
                        "social_net_of_icon", 
                        "social_net_of_icon@2x",
                        "social_net_of_icon_ipad" );
    
    static const image_names network_social_quantum_images(
                        "social_net_sq_icon", 
                        "social_net_sq_icon@2x",
                        "social_net_sq_icon_ipad" );
    
    static const image_names network_vkontakte_images(
                        "social_net_vk_icon", 
                        "social_net_vk_icon@2x",
                        "social_net_vk_icon_ipad" );

    // current theme size
    sqc_window_factory& factory = framework().windows_factory();
    sqc_theme_size theme = factory.get_theme_size();
    
    if ( sqc_network_facebook == network ) {
        return network_facebook_images.at( theme );
    } else if ( sqc_network_game_center == network ) {
        return network_game_center_images.at( theme );
    } else if ( sqc_network_moi_mir == network ) {
        return network_moi_mir_images.at( theme );
    } else if ( sqc_network_odnoklassniki == network ) {
        return network_odnoklassniki_images.at( theme );
    } else if ( sqc_network_open_feint == network ) {
        return network_open_feint_images.at( theme );
    } else if ( sqc_network_social_quantum == network ) {
        return network_social_quantum_images.at( theme );
    } else if ( sqc_network_vkontakte == network ) {
        return network_vkontakte_images.at( theme );
    } else {
        // log error
        sqc_error() 
            << "social_networks error: unable to determine images for network: "
            << print_social_network( current_network() );
        return "";
    }
}

// login to network
bool sqc_social_networks::loggin( const sqc_network_type network,
                                 const sqc_string& authenticate_server ) {
    
    if ( m_active_network ) {
        sqc_info() 
            << "social_networks: reset previouse network";
        m_active_network->deinit();
        m_active_network.reset();
    }
    
    m_active_network = m_factory.create_network( network );
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to create " 
            << print_social_network( network );
        
        on_login_error( sqc_network_error_factory_error );
        return false;
    }
   
    sqc_network_callbacks callbacks(
        std::tr1::bind( &sqc_social_networks::on_login_complete, this ),
        std::tr1::bind( &sqc_social_networks::on_login_error, this, _1 ) );
    
    sqc_network_status status = m_active_network->login( authenticate_server, callbacks );
    if ( is_sqc_network_error( status ) ) {
        sqc_error() 
            << "social_networks login error: unable to connect to " 
            << print_social_network( network )
            << " with status: "
            << print_network_status( status );
        
        on_login_error( sqc_network_error_general_failure );
        return false;
    }

    sqc_info()
        << "social_networks: connect to " 
        << print_social_network( network )
        << " with status: "
        << print_network_status( status );
    
    save_in_prefs();
    
    return true;
}

void sqc_social_networks::save_in_prefs()
{
    sqc_word last_net =  framework().preferences().get_int("socnet", "current", 0); // outdated
    
    framework().preferences().set_int("socnet", "last_net", last_net);
    framework().preferences().set_int("socnet", "current",  m_active_network->network_type());
}

bool sqc_social_networks::is_logged() const {
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to determine logged status, no active network";
        return false;
    }
    bool logged = m_active_network->is_logged();
    sqc_info() 
        << "social_networks: logged status is " 
        << ( logged ? "connected" : "disconected" );

    return logged;
}

// user id (social network id)
sqc_string sqc_social_networks::get_user_id() const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to retrieve user_id, no active network";
        return sqc_string();
    }
    sqc_string user_id = m_active_network->get_user_id();
    sqc_info() 
        << "social_networks: user_id: " << user_id;
    
    return user_id;
}

// network access token (SQ)
sqc_string sqc_social_networks::get_access_token() const {
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to retrieve access token, no active network";
        return sqc_string();
    }
    sqc_string token = m_active_network->get_access_token();
    sqc_info() 
        << "social_networks: access token: " << token;
    
    
    return token;
}

sqc_user_profile_ptr sqc_social_networks::get_user_profile() const {
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to retrieve user profile, no active network";
        return sqc_user_profile_ptr();
    }

    sqc_user_profile_ptr ptr = m_active_network->get_user_profile();
    if ( ptr ) {
        sqc_info()
            << "social_networks: user profile is: " 
            << print_user_profile( *ptr );
    } else {
        sqc_error() 
            << "social_networks error: unable to retrieve user profile";
    }
    
    return ptr;
}

// retrieve friends
bool sqc_social_networks::query_friends() {
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to query friends, no active network";
        return false;
    }
    
    sqc_network_callbacks callbacks(
        std::tr1::bind( &sqc_social_networks::on_friends_complete, this ),
        std::tr1::bind( &sqc_social_networks::on_friends_error, this, _1 ) );
    
    sqc_network_status status = m_active_network->query_friends( callbacks );
    if ( is_sqc_network_error( status ) ) {
        sqc_error() 
            << "social_networks query friends error: status is " 
            << print_network_status( status );
        
        return false;
    }
    
    sqc_info()
        << "social_networks: query friends with status: " 
        << print_network_status( status );
    
    return true;
}

bool sqc_social_networks::get_friends( sqc_user_profile_list& list ) const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to retrieve friends, no active network";
        return false;
    }
    
    if ( !m_active_network->get_friends( list ) ) {
        sqc_info()
            << "social_networks: retrieve friends fail";
        return false;
    }
    
    sqc_info()
        << "social_networks: retrieve"
        << list.size()
        << " friends";
    
    return false;
}

bool sqc_social_networks::can_send_to_wall() const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to call can_send_to_wall, no active network";
        return false;
    }
    
    bool can = (sqc_network_flag_can_send_to_wall & m_active_network->get_flags() );
    
    sqc_info()
        << "social_networks: can_send_to_wall: "
        << ( can ? "true" : "false" );
    
    return can;
}

bool sqc_social_networks::can_invite_friends() const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to call can_invite_friends, no active network";
        return false;
    }
    
    bool can = (sqc_network_flag_can_invite_friends & m_active_network->get_flags() );
    
    sqc_info()
        << "social_networks: can_invite_friends: "
        << ( can ? "true" : "false" );
    
    return can;
}

bool sqc_social_networks::can_have_friends() const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to call can_have_friends, no active network";
        return false;
    }
    
    bool can = (sqc_network_flag_can_have_friends & m_active_network->get_flags() );
    
    sqc_info()
        << "social_networks: can_have_friends: "
        << ( can ? "true" : "false" );
    
    return can;
}


bool sqc_social_networks::can_enum_users() const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to call can_enum_users, no active network";
        return false;
    }
    
    bool can = (sqc_network_flag_can_enum_user & m_active_network->get_flags() );
    
    sqc_info()
        << "social_networks: can_enum_users: "
        << ( can ? "true" : "false" );
    
    return can;
}

// send message to wall
bool sqc_social_networks::send_to_wall( const sqc_string& message ) {
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to send_to_wall, no active network";
        return false;
    }
    
    sqc_network_callbacks callbacks(
        std::tr1::bind( &sqc_social_networks::on_send_to_wall_complete, this ),
        std::tr1::bind( &sqc_social_networks::on_send_to_wall_error, this, _1 ) );
    
    sqc_network_status status = m_active_network->send_to_wall( message, callbacks );
    if ( is_sqc_network_error( status ) ) {
        sqc_error() 
            << "social_networks send_to_wall error: status is " 
            << print_network_status( status );
        
        return false;
    }
    
    sqc_info()
        << "social_networks: send_to_wall with status: " 
        << print_network_status( status );
    
    return true;
}

// invite friend
bool sqc_social_networks::invite_friend( const sqc_string& user_id, const sqc_string& message ) {
    if ( !m_active_network ) {
        sqc_error() 
            << "social_networks error: unable to invite_friend, no active network";
        return false;
    }
    
    sqc_network_callbacks callbacks(
        std::tr1::bind( &sqc_social_networks::on_invite_friend_complete, this ),
        std::tr1::bind( &sqc_social_networks::on_invite_friend_error, this, _1 ) );
    
    sqc_network_status status = m_active_network->invite_friend( user_id, message, callbacks );
    if ( is_sqc_network_error( status ) ) {
        sqc_error() 
            << "social_networks invite_friend error: status is " 
            << print_network_status( status );
        
        return false;
    }
    
    sqc_info()
        << "social_networks: invite_friend with status: " 
        << print_network_status( status );
    
    return true;
}

// check country is exist
bool sqc_social_networks::is_country_exist() const {
    if ( !m_active_network ) {
        sqc_error() 
        << "social_networks error: unable to check country status, no active network";
        return false;
    }
    
    bool exist = m_active_network->is_country_exist();
    
    sqc_info()
        << "social_networks: country is exist: " 
        << ( exist ? "true" : "false" );
    
    return exist;
}

// fire notofication event
void sqc_social_networks::fire_event( 
    const sqc_string& event_id ) {
    framework().notify_center().fire_event( social_networks, event_id, call_async );
}

// login callbacks
void sqc_social_networks::on_login_complete() {
    sqc_info()
        << "social_networks: login complete";
    
    fire_event( network_event_loggin_complete );
}

void sqc_social_networks::on_login_error(
    const sqc_network_error_code error ) {
    sqc_error()
        << "social_networks: login failed with error: " 
        << print_network_error_code( error );
    
    fire_event( network_event_loggin_error );
}


// friends callbacks
void sqc_social_networks::on_friends_complete() {
    sqc_info()
        << "social_networks: query friends complete";
    
    fire_event( network_event_query_friends_complete );
}

void sqc_social_networks::on_friends_error(
    const sqc_network_error_code error ) {
    sqc_error()
        << "social_networks: query friends failed with error: " 
        << print_network_error_code( error );
    
    fire_event( network_event_query_friends_error );
}

// send to wall callbacks
void sqc_social_networks::on_send_to_wall_complete() {
    sqc_info()
        << "social_networks: send_to_wall complete";
    
    fire_event( network_event_send_to_wall_complete );
}

void sqc_social_networks::on_send_to_wall_error(
    const sqc_network_error_code error ) {
    sqc_error()
        << "social_networks: send_to_wall failed with error: " 
        << print_network_error_code( error );
    
    fire_event( network_event_send_to_wall_error );
}

// invite friend callbacks
void sqc_social_networks::on_invite_friend_complete() {
    sqc_info()
        << "social_networks: invite_friend complete";
    
    fire_event( network_event_invite_friend_complete );
}

void sqc_social_networks::on_invite_friend_error(
    const sqc_network_error_code error ) {
    sqc_error()
        << "social_networks: invite_friend failed with error: " 
        << print_network_error_code( error );
    
    fire_event( network_event_invite_friend_error );
}


END_NAMESPACE_SQC_FRAMEWORK