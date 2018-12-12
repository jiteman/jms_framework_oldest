#pragma once

#include "../../framework/notify_center/sqc_notify_center.h"
#include "../../framework/http_service/sqc_http_service.h"
#include "../sqc_backend_connection.h"


NAMESPACE_SQC_PROCESSOR

struct sqc_name_value_pair {
	sqc_name_value_pair( const sqc_string& n,
    					const sqc_string& v ) 
		: name( n )
        , value( v ) {
        }
        
	sqc_string	name;
    sqc_string	value;
};

typedef std::list<sqc_name_value_pair>		sqc_name_value_list;

enum sqc_server_cmd_type {
	server_cmd_create,
	server_cmd_move,
	server_cmd_clean,
	server_cmd_pick,
	server_cmd_sell,
    server_cmd_apply,
    server_cmd_put,
    server_cmd_cancel,
    server_cmd_change_tax,
    server_cmd_view_friend_field,
    server_cmd_view_own_field,
	server_cmd_sell_gift,
    server_cmd_apply_gift,
    server_cmd_receive_gift,
    server_cmd_send_gift,
    server_cmd_send_shop_gift,
    server_cmd_ask_material_gift,
    server_cmd_set_io,
};

inline sqc_string 
print_command_type( const sqc_server_cmd_type type ) {
	if ( server_cmd_create == type ) 				 return "CREATE";
	else if ( server_cmd_move == type ) 			 return "MOVE";
	else if ( server_cmd_clean == type ) 			 return "CLEAN";
	else if ( server_cmd_pick == type ) 			 return "PICK";
	else if ( server_cmd_sell == type ) 			 return "SELL";
    else if ( server_cmd_apply == type )    		 return "APPLY";
    else if ( server_cmd_put == type )      		 return "PUT";
    else if ( server_cmd_cancel == type )   		 return "CANCEL";
    else if ( server_cmd_change_tax == type )   	 return "CHANGE_TAX";
    else if ( server_cmd_view_friend_field == type ) return "VIEW_FRIEND_FIELD";
    else if ( server_cmd_view_own_field == type )  	 return "VIEW_OWN_FIELD";
    else if ( server_cmd_sell_gift == type )  		 return "SELL_GIFT";
    else if ( server_cmd_apply_gift == type )  		 return "APPLY_GIFT";
    else if ( server_cmd_send_gift == type )  		 return "SEND_GIFT";
    else if ( server_cmd_send_shop_gift == type )	 return "SEND_SHOP_GIFT";
    else if ( server_cmd_receive_gift == type )      return "RECEIVE_GIFT";
    else if ( server_cmd_ask_material_gift == type ) return "ASK_GIFT";
    else if ( server_cmd_set_io == type )			 return "SET_IO";
       
    sqc_assert( false );
    return "UNK_COMMAND";
}

enum sqc_command_priority {
    command_priority_now,
    command_priority_idle,
};

// base command
class sqc_command {
public:
    sqc_command( const sqc_server_cmd_type type,
    			 const sqc_string& user_id )
    	: m_server_cmd_type( type )
        , m_user_id( user_id ) {
    }
    virtual ~sqc_command() {
    }
    
    virtual sqc_server_cmd_type get_cmd_type() const {
    	return m_server_cmd_type;
    }
    virtual sqc_string get_command_name() = 0;
    virtual sqc_string get_server_dir();
    virtual void pack_params( sqc_name_value_list& list );
    
    virtual int get_object_id();
    
protected:
	sqc_string	pack_bool( bool b );
    sqc_string	pack_int( int i );
    
private:
	sqc_string			m_user_id;
    sqc_server_cmd_type	m_server_cmd_type;
};

typedef std::tr1::shared_ptr<sqc_command>   sqc_command_ptr;

// create command - build object
class sqc_create_command : public sqc_command {
public:
    sqc_create_command( const sqc_string& user_id,
					    const sqc_string& object_type,
                        const sqc_point& create_point,
                        const bool rotation ) 
        : sqc_command ( server_cmd_create, user_id )
        , m_object_type( object_type )
        , m_rotation( rotation )
        , m_create_point( create_point ) {
    }
    
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );

private:
	sqc_string	m_object_type;
    bool		m_rotation;
    sqc_point	m_create_point;
};

// move and rotate command
class sqc_move_command : public sqc_command {
public:
    sqc_move_command( const sqc_string& user_id,
                      const int object_id,
                      const sqc_point& coords_point,
                      const bool rotation ) 
    	: sqc_command ( server_cmd_move, user_id )
        , m_object_id( object_id )
        , m_rotation( rotation )
        , m_coords_point( coords_point ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_object_id;
    bool		m_rotation;
    sqc_point	m_coords_point;
};

// process timeout
class sqc_tick_command : public sqc_command {
public:
    sqc_tick_command( const sqc_string& user_id,
                     const int object_id ) 
    : sqc_command ( server_cmd_pick, user_id )
    , m_object_id( object_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
protected:
    int			m_object_id;
};

// sell command (delete)



// gather tax
class sqc_clean_command : public sqc_command {
public:
    sqc_clean_command( const sqc_string& user_id,
                      const int object_id,
                      const int auto_points = 0 ) 
    	: sqc_command ( server_cmd_clean, user_id )
        , m_object_id( object_id )
        , m_auto_points( auto_points ) {
    }
    virtual sqc_string get_command_name();
    virtual int get_object_id();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_object_id;
    int			m_auto_points;
};


// gather people
class sqc_pick_command : public sqc_command {
public:
    sqc_pick_command( const sqc_string& user_id,
                      const int object_id,
                      const int auto_points = 0 ) 
    	: sqc_command ( server_cmd_pick, user_id )
        , m_object_id( object_id )
        , m_auto_points( auto_points ) {
    }
    virtual sqc_string get_command_name();
    virtual int get_object_id();
    virtual void pack_params( sqc_name_value_list& list );
protected:
    int			m_object_id;
    int			m_auto_points;
};

// sell command (delete)
class sqc_sell_command : public sqc_command {
public:
    sqc_sell_command( const sqc_string& user_id,
                      const int object_id ) 
    	: sqc_command ( server_cmd_sell, user_id )
        , m_object_id( object_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_object_id;
};

// apply command 
class sqc_apply_command : public sqc_command {
public:
    sqc_apply_command( const sqc_string& user_id,
                       const sqc_string &object_type,
                       const int item_id ) 
    : sqc_command ( server_cmd_apply, user_id )
    , m_item_id( item_id )
    , m_object_type ( object_type ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_item_id;
    sqc_string  m_object_type;
};

// put command 
class sqc_put_command : public sqc_command {
public:
    sqc_put_command( const sqc_string& user_id,
                    const sqc_string &object_type,
                    const int item_id ) 
    : sqc_command ( server_cmd_put, user_id )
    , m_item_id( item_id )
    , m_object_type( object_type ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
    virtual int get_object_id() { return m_item_id; }
private:
    int            m_item_id;
    sqc_string  m_object_type;
};

// change item nedded for multifactory
class sqc_switch_item_command : public sqc_command {
public:
    sqc_switch_item_command( const sqc_string& user_id,
                    const int object_id, const sqc_string& type_item ) 
    : sqc_command ( server_cmd_put, user_id )
    , m_object_id( object_id )
    , m_type_item(type_item) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
    virtual int get_object_id() { return m_object_id; }
private:
    int             m_object_id;
    sqc_string      m_type_item;    /// type of item which will changed
};

// put command for 2 params
class sqc_put_command_2_params : public sqc_command {
public:
    sqc_put_command_2_params( const sqc_string& user_id,
                    const int item_id ) 
    : sqc_command ( server_cmd_put, user_id )
    , m_item_id( item_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
    virtual int get_object_id() { return m_item_id; }
private:
    int			m_item_id;
};

// cancel command 
class sqc_cancel_command : public sqc_command {
public:
    sqc_cancel_command( const sqc_string& user_id,
                        const int item_id ) 
    : sqc_command ( server_cmd_cancel, user_id )
    , m_item_id( item_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_item_id;
};

// change_tax
class sqc_change_tax_command : public sqc_command {
public:
    sqc_change_tax_command( const sqc_string& user_id,
                        	const int item_id,
                            const int tax_value ) 
    : sqc_command ( server_cmd_change_tax, user_id )
    , m_item_id( item_id )
    , m_tax_value( tax_value ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_item_id;
    int			m_tax_value;
};

// set_io command (set fiscal agent and municipal officer)
class sqc_io_command : public sqc_command {
public:
    sqc_io_command( const sqc_string& user_id,
                        	const int item_id,
                            const sqc_string& fiscal_agent_id,
						    const sqc_string& municipal_oficer_id ) 
    : sqc_command ( server_cmd_set_io, user_id )
    , m_item_id( item_id )
    , m_fiscal_agent_id( fiscal_agent_id )
    , m_municipal_oficer_id( municipal_oficer_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
    int			m_item_id;
    sqc_string	m_fiscal_agent_id;
    sqc_string	m_municipal_oficer_id;
};


// view friend field command
class sqc_view_friend_field_command : public sqc_command {
public:
    sqc_view_friend_field_command( const sqc_string& user_id,
                            const sqc_string& friend_id ) 
    : sqc_command ( server_cmd_view_friend_field, user_id )
    , m_friend_id( friend_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
    virtual sqc_string get_server_dir();
private:
    sqc_string  m_friend_id;
};

// return to own field command
class sqc_view_own_field_command : public sqc_command {
public:
    sqc_view_own_field_command( const sqc_string& user_id ) 
    : sqc_command ( server_cmd_view_own_field, user_id ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
    virtual sqc_string get_server_dir();
};

class sqc_move_to_pen_command : public sqc_command {
public:
    sqc_move_to_pen_command( const sqc_string& user_id,
                     const int object_id ) 
    : sqc_command ( server_cmd_pick, user_id )
    , m_object_id( object_id ) {
    }
    virtual sqc_string get_command_name();
    virtual int get_object_id();
    virtual void pack_params( sqc_name_value_list& list );
protected:
    int			m_object_id;
};

class sqc_sell_gift_command : public sqc_command {

public:
	sqc_sell_gift_command( const sqc_string& user_id, const int item_id )
    : sqc_command( server_cmd_sell_gift, user_id)
    , m_item_id(item_id)
    {
    }
    
    virtual sqc_string get_command_name();
	virtual void pack_params( sqc_name_value_list& list );

private:
	int m_item_id;
};

class sqc_apply_gift_command : public sqc_command {
public:
	sqc_apply_gift_command( const sqc_string& user_id, const int item_id, 
    						const int gift_id,
                            const sqc_string& klass )
    : sqc_command( server_cmd_apply_gift, user_id)
    , m_item_id(item_id)
    , m_gift_id(gift_id)
    , m_klass(klass)
    {
    }
    
    virtual sqc_string get_command_name();
	virtual void pack_params( sqc_name_value_list& list );

private:
	int m_item_id;
    int m_gift_id;
	sqc_string m_klass;
};

class sqc_send_gift_command : public sqc_command {
public:
	sqc_send_gift_command( const sqc_string& user_id, 
    						const int item_id, 
                            const sqc_string& second_user_id )
    : sqc_command( server_cmd_send_gift, user_id)
    , m_item_id( item_id )
    , m_second_user_id( second_user_id ) {
    }
    
    virtual sqc_string get_command_name();
	virtual void pack_params( sqc_name_value_list& list );

private:
	int			m_item_id;
	sqc_string	m_second_user_id;
};

// send gift from shop command - build object
class sqc_send_shop_gift_command : public sqc_command {
public:
    sqc_send_shop_gift_command( const sqc_string& user_id,
					    const sqc_string& object_type,
                        const sqc_string& second_user_id ) 
        : sqc_command ( server_cmd_send_shop_gift, user_id )
        , m_object_type( object_type )
        , m_second_user_id( second_user_id ){
    }
    
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );

private:
	sqc_string	m_object_type;
	sqc_string	m_second_user_id;
};

// receive command 
class sqc_receive_gift_command : public sqc_command {
public:
    sqc_receive_gift_command( const sqc_string& user_id,
                         const int item_id,
                         const sqc_string &klass,
                         const int rotation,
                         const int x,
                         const int y
                	   ) 
    : sqc_command ( server_cmd_receive_gift, user_id )
	, m_item_id(item_id)
	, m_klass(klass)
    , m_rotation(rotation)
    , m_x(x)
	, m_y(y)
	{
    }

    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
private:
	int m_item_id;
	sqc_string m_klass;
    int m_rotation;
    int m_x;
	int m_y;
};

// ask user to make a gift
class sqc_ask_material_gift_command : public sqc_command {
public:
    sqc_ask_material_gift_command( const sqc_string& user_id,
                               sqc_int item_id ) 
    : sqc_command ( server_cmd_ask_material_gift, user_id )
    , m_item_id( item_id ){
    }
    
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
    
private:
	sqc_int     m_item_id;
};

class sqc_sell_barn_command : public sqc_command {
public:
    sqc_sell_barn_command( const sqc_string& user_id,
                           const int object_id,
                           const int quantity ) 
    : sqc_command ( server_cmd_pick, user_id )
    , m_object_id( object_id )
    , m_quantity( quantity ) {
    }
    virtual sqc_string get_command_name();
    virtual void pack_params( sqc_name_value_list& list );
protected:
    int			m_object_id;
    int			m_quantity;
};


typedef sqc_string		raw_xml;

//
// download initial XML and run commands
//
using namespace framework;

class sqc_command_processor {
public:
	sqc_command_processor( sqc_backend_connection& backend_connection,
                           sqc_notify_center& notify,
                           sqc_http_service& http );
	virtual ~sqc_command_processor();
    
    void	get_init_xml( raw_xml& xml ) const;
    
    void    handle_timer();
    void	schedule( sqc_command_ptr command, sqc_command_priority priority = command_priority_now );
    int     get_command_delay();
protected:
    void    execute_command( sqc_command_ptr command );
    void    next_command();
protected:
    //
    //	request initial xml (after new game server is choosed)
    //
    bool	request_initial_xml();
    void	on_initial_xml_received( sqc_net_data const &raw );
    void	on_initial_xml_error();
protected:
    // notification callback
    void			notify_callback( const sqc_provider_id& provider_id, 
                                    const sqc_event_id& event_id);    

    virtual void	on_http_complete( sqc_net_path url, 
                                     sqc_net_data const &raw );
    virtual void    on_http_error( sqc_net_path url, 
                                  sqc_net_error const &error );
    
protected:

	void			create_body( const sqc_name_value_list& pairs, sqc_string& body );		
	//
    //	post command callbacks
    //
    virtual void	on_post_command_complete( const sqc_server_cmd_type cmd_type,
    										sqc_net_path url, 
                                     		sqc_net_data const &raw );
    virtual void    on_post_command_error( const sqc_server_cmd_type cmd_type,
    										sqc_net_path url, 
                                  			sqc_net_error const &error );
    
protected:
    sqc_listener_connection			m_notify_connection;
    
    sqc_backend_connection& 		m_backend_connection;
    sqc_notify_center&				m_notify;
    sqc_http_service&				m_http;
    
    // xml
    mutable sstl::sstl_mutex m_access;
    raw_xml					m_init_xml;
    
    // commands queue
    typedef std::vector<sqc_command_ptr> sqc_command_vector;
    sqc_command_vector  m_commands;
    const int           m_command_delay;
    int                 m_last_command_time;
};
	

//
// command processor provider events id
//
declare_notification_provider_id( command_processor_provider_id )

// field downloader notification events id
declare_notification_event_id( command_processor_initial_xml_complete_event )
//declare_notification_event_id( command_processor_initial_xml_error_event )
declare_notification_event_id( command_processor_command_queued_event )
declare_notification_event_id( command_processor_command_progress_event )
declare_notification_event_id( command_processor_command_all_completed_event )
declare_notification_event_id( command_processor_command_successfully_event )

END_NAMESPACE_SQC_PROCESSOR

