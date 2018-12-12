#pragma once

#include "../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

// social networks
enum sqc_network_type {
    sqc_network_none,
    sqc_network_facebook,
    sqc_network_game_center,
    sqc_network_moi_mir,
    sqc_network_odnoklassniki,
    sqc_network_open_feint,
    sqc_network_social_quantum,
    sqc_network_vkontakte,
    sqc_network_countof,
};
typedef std::list<sqc_network_type> network_list;

inline std::string
print_social_network( const sqc_network_type network ) {
    if ( sqc_network_none == network )              return "none_network";
    if ( sqc_network_facebook == network )          return "facebook_network";
    if ( sqc_network_game_center == network )       return "game_center_network";
    if ( sqc_network_moi_mir == network )           return "moi_mir_network";
    if ( sqc_network_odnoklassniki == network )     return "odnoklassniki_network";
    if ( sqc_network_open_feint == network )        return "open_feint_network";
    if ( sqc_network_social_quantum == network )    return "social_quantum_network";
    if ( sqc_network_vkontakte == network )         return "vkontakte_network";
    else {
        std::stringstream out;
        out << "unknown_network " << network;
        return out.str();
    }
}

// network status
enum sqc_network_status {
    sqc_network_status_success,
    sqc_network_status_error,
    sqc_network_status_pending,
    sqc_network_status_not_implemented,
};

inline bool
is_sqc_network_error( const sqc_network_status status ) {
    return ( sqc_network_status_error == status || 
            sqc_network_status_not_implemented == status );
}

inline std::string
print_network_status( const sqc_network_status status ) {
    if ( sqc_network_status_success == status )         return "status_success";
    if ( sqc_network_status_error == status )           return "status_error";
    if ( sqc_network_status_pending == status )         return "status_pending";
    if ( sqc_network_status_not_implemented == status ) return "status_not_implemented";
    else {
        std::stringstream out;
        out << "unknown_status" << status;
        return out.str();
    }
}


// network error code
typedef int sqc_network_error_code;

enum sqc_network_error_codes {
	sqc_network_error_no_error           =  0,
    sqc_network_error_general_failure    = -1,
    sqc_network_error_no_active_network  = -2,
    sqc_network_error_factory_error      = -3,
    sqc_network_error_facebook_error	 = -4,
    sqc_network_error_dialog_error		 = -5,
    sqc_network_error_dialog_canceled	 = -6,
    sqc_network_error_dialog_malformedurl= -7,
    sqc_network_error_dialog_ioerror     = -8,
    sqc_network_error_dialog_protocol_error = -9,
	sqc_network_error_json_parse_error = -10
};


inline std::string
print_network_error_code( const sqc_network_error_code error ) {
    std::stringstream out;
    out << error;
    return out.str();
}

// network flags
enum sqc_network_flag {
    sqc_network_flag_can_send_to_wall   = 1 << 0,
    sqc_network_flag_can_invite_friends = 1 << 1,
    sqc_network_flag_can_have_friends   = 1 << 2,
    sqc_network_flag_can_enum_user   	= 1 << 3,
};
typedef unsigned sqc_network_flags;


enum sqc_gender {
	sqc_male,
    sqc_female,
};

typedef sqc_string	sqc_user_id;

//
//  user profile
//
class sqc_user_profile {
public:
    sqc_user_profile();
    virtual ~sqc_user_profile();

    const sqc_string&   get_first_name() const;
    void                set_first_name( const sqc_string& name );

    const sqc_string&   get_last_name() const;
    void                set_last_name( const sqc_string& name );

    const sqc_string&   get_aliase() const;
    void                set_aliase( const sqc_string& aliase );
    
    const sqc_user_id&   get_user_id() const;
    void                set_user_id( const sqc_user_id& id );

    const sqc_gender    get_gender() const;
    void                set_gender( const sqc_gender gender );

    const sqc_string&   get_avatar_url() const;
    void                set_avatar_url( const sqc_string& avatar_url );

    const bool          is_in_game() const;
    void                set_in_game( const bool in_game );

    const bool          is_have_gift() const;
    void                set_have_gift( const bool have_gift );
    
	const int      		get_level() const;
    void           		set_level( int level );


protected:
    sqc_string  m_first_name;
    sqc_string  m_last_name;
    sqc_string  m_user_aliase;      // ник
    sqc_gender  m_gender;
    sqc_string  m_avatar_url;         // адрес аватары
    sqc_user_id m_user_id;
    bool        m_in_game;         // в игре или нет
    bool        m_have_gift;       // дата, когда последний раз дарили подарок этому юзеру
    int			m_level;
};

typedef std::tr1::shared_ptr<sqc_user_profile>	sqc_user_profile_ptr;
typedef std::list<sqc_user_profile_ptr>         sqc_user_profile_list;

typedef std::list<sqc_user_id>					sqc_user_id_list;


inline std::string print_user_profile( const sqc_user_profile& profile ) {
    std::stringstream out;
    out << "fname: " << profile.get_first_name() 
        << " lname: " << profile.get_last_name() 
        << " aliase: " << profile.get_aliase()
        << " ID: " << profile.get_user_id()
        << " in_game: " << ( profile.is_in_game() ? "true" : "false" )
        << " have_gift: " << ( profile.is_have_gift() ? "true" : "false" )
        << " avatar: " << profile.get_avatar_url()
        << " level: " << profile.get_level();
    
    return out.str();
}

// provider events id
declare_notification_provider_id( social_networks )

// notification events id
declare_notification_event_id( network_event_loggin_complete )
declare_notification_event_id( network_event_loggin_error )

declare_notification_event_id( network_event_query_friends_complete )
declare_notification_event_id( network_event_query_friends_error )

declare_notification_event_id( network_event_send_to_wall_complete )
declare_notification_event_id( network_event_send_to_wall_error )

declare_notification_event_id( network_event_invite_friend_complete )
declare_notification_event_id( network_event_invite_friend_error )

//declare_notification_event_id( network_event_query_users_complete )
//declare_notification_event_id( network_event_query_users_error )

END_NAMESPACE_SQC_FRAMEWORK
