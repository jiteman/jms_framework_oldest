#pragma once

#include "../framework/sqc_framework_defs.h"
#include "sqc_social_network_defs.h"

NAMESPACE_SQC_FRAMEWORK

template <class complete_cb_t, class error_cb_t>
class sqc_network_callbacks_t {

public:
    sqc_network_callbacks_t( complete_cb_t compl_callback,
                          error_cb_t err_cb ) 
        : complete_callback( compl_callback )
        , error_callback( err_cb ) {
    }

private:
//    sqc_network_callbacks_t(){}

private:

    complete_cb_t   complete_callback; 
    error_cb_t      error_callback;
};



// complete and error callbacks
typedef std::tr1::function<void()>	sqc_network_complete_callback;
typedef std::tr1::function<void( const sqc_network_error_code error )>
                                        sqc_network_error_callback;

typedef sqc_network_callbacks_t<sqc_network_complete_callback,sqc_network_error_callback>
	sqc_network_callbacks;
typedef std::tr1::shared_ptr<sqc_network_callbacks>	sqc_network_callbacks_ptr;


// complete and error callbacks for users
typedef std::tr1::function<void( sqc_user_profile_list& list )>
									sqc_query_users_complete_callback;
typedef std::tr1::function<void( const sqc_network_error_code error )>
                                        sqc_query_users_error_callback;

typedef sqc_network_callbacks_t<sqc_query_users_complete_callback,sqc_query_users_error_callback>
	sqc_query_users_callbacks;
typedef std::tr1::shared_ptr<sqc_query_users_callbacks>	sqc_query_users_callbacks_ptr;


//
// sqc_social_network interface
//
class sqc_social_network {
public:
    // network type
    virtual sqc_network_type    network_type() const = 0;

    // login to network
    virtual sqc_network_status  login( const sqc_string& authenticate_server,
                                      sqc_network_callbacks& cb ) = 0;
    // Authorized?
    virtual bool                is_logged() const = 0;
    
    // user id (social network id)
    virtual sqc_string          get_user_id() const = 0;
    // network access token(SQC)
    virtual sqc_string          get_access_token() const = 0;
    
    // retrieve user profile
    virtual sqc_user_profile_ptr get_user_profile() const = 0;

    // retrieve friends
    virtual sqc_network_status  query_friends( sqc_network_callbacks& cb ) = 0;
    virtual bool                get_friends( sqc_user_profile_list& list ) const = 0;
    
    // query users, on succsess callback fill profile_user_list
    virtual sqc_network_status  query_users( sqc_query_users_callbacks& cb, sqc_user_id_list& users_id ) = 0;
    
    
    // retrieve network flags
    virtual sqc_network_flags   get_flags() const = 0;
    
    // send message to wall
    virtual sqc_network_status send_to_wall( const sqc_string& message,
                              sqc_network_callbacks& cb ) = 0;
    // invite friend
    virtual sqc_network_status invite_friend( const sqc_string& user_id, 
    							const sqc_string& message,
                                sqc_network_callbacks& cb ) = 0;

    // check country is exist
    virtual bool                is_country_exist() const = 0;
    // deinit (terminate all request, close dialogs, etc)
    virtual void				deinit() = 0;
};

typedef std::tr1::shared_ptr<sqc_social_network>	sqc_social_network_ptr;

//
// sqc_social_networks factory
//
class sqc_social_networks_factory {
public:
    virtual sqc_social_network_ptr create_network( const sqc_network_type network ) = 0;
};


//
// sqc_social_networks implementation
//
class sqc_social_networks {
public:
	sqc_social_networks( sqc_social_networks_factory& factory );
	virtual ~sqc_social_networks();

    // list of available networks
    void                get_available_networks( network_list& list ) const;
    
    // retrieve current network
    sqc_network_type    current_network() const;
    
    // user id (social network id)
    sqc_string          get_user_id() const;
    // network access token (SQ)
    sqc_string          get_access_token() const;
    
    // retrieve network 
    sqc_string          get_network_name( const sqc_network_type network ) const;
    // retrieve network images
    sqc_string          get_network_image( const sqc_network_type network ) const;
    
    // loggin to network
    bool                loggin( const sqc_network_type network,
                               const sqc_string& authenticate_server );
    // is logged?
    bool                is_logged() const;
    // retrieve user profile
    sqc_user_profile_ptr get_user_profile() const;
    
    // retrieve friends
    bool                query_friends();
    bool                get_friends( sqc_user_profile_list& list ) const;
    
    
    //bool                query_userss( const sqc_user_id_list& user_ids );
    
    // network properties
    bool                can_send_to_wall() const;
    bool                can_invite_friends() const;
    bool                can_have_friends() const;
    bool                can_enum_users() const;
    
    // send message to wall
    bool                send_to_wall( const sqc_string& message );
    // invite friend
    bool                invite_friend( const sqc_string& user_id, const sqc_string& message );
    // check country is exist
    bool                is_country_exist() const;

protected:
    // fire notofication event
    void    fire_event( const sqc_string& event_id );
    // login callbacks
    void    on_login_complete();
    void    on_login_error( const sqc_network_error_code error );

    // friends callbacks
    void    on_friends_complete();
    void    on_friends_error( const sqc_network_error_code error );

    // send to wall callbacks
    void    on_send_to_wall_complete();
    void    on_send_to_wall_error( const sqc_network_error_code error );

    // invite friend callbacks
    void    on_invite_friend_complete();
    void    on_invite_friend_error( const sqc_network_error_code error );
    
    // save net info in prefs
    void    save_in_prefs();
    
protected:
    // network factory
	sqc_social_networks_factory& m_factory;
    
    // active network
    sqc_social_network_ptr      m_active_network;
};
	
END_NAMESPACE_SQC_FRAMEWORK
