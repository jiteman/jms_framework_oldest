#pragma once

#include "../framework/sqc_framework_defs.h"
#include "../framework/social_network/sqc_social_network.h"
#include "shop/sqc_shop_defs.h"
#include "sqc_country_common.h"
#include "../country_base/sqc_game_base.h"
#include "../country_base/dialogs/select_person/sqc_select_person_delegate.h"
#include "../country_base/dialogs/select_construction/sqc_select_construction_delegate.h"

NAMESPACE_SQC_FRAMEWORK


struct sqc_message_box_params {
	sqc_string			  	dlg_title;
    sqc_string				dlg_text;
    sqc_string				button_text;
};

struct sqc_show_login_progress_params {
};

struct sqc_select_network_params {
	typedef std::tr1::function<void(const sqc_network_type network)>
    													select_network_callback;

	sqc_select_network_params() {
	    user_can_close_dialog       = true;
    }
    // dialog has close and back button
    bool						user_can_close_dialog;
    select_network_callback		callback;
    
};

/// Parameters for Select person dialog
struct  sqc_select_person_params {
    
    sqc_string  button_caption;
    sqc_string  avatar_prefix;
    /// Callback filling person list.
    /// Parameters: list person, caller id
    typedef std::tr1::function<void(sqc_person_info_list_type &input_fill)> input_fill_callback_t;
    
    /// Callback select person
    typedef std::tr1::function<bool(sqc_string id)> select_callback_t;

    input_fill_callback_t   input_fill_callback;
    select_callback_t		select_callback;
};

struct sqc_on_next_level_params
{
    sqc_on_next_level_params():
    shop_category(sqc_shop_category_all)
    {}
    
    sqc_shop_category       shop_category;
    sqc_common_scene_info   scene_info;
};

struct sqc_level_up_params
{
  	typedef std::tr1::function<bool(const sqc_string& object_type)>
    buy_callback_t;
    
    sqc_level_up_params():
    shop_category(sqc_shop_category_all)
    ,received_buks(0)
    ,received_coins(0)
    {}
    
    buy_callback_t           buy_callback;
    buy_callback_t           gift_callback;
    sqc_common_scene_info    scene_info;
    sqc_shop_category        shop_category;
    sqc_on_next_level_params on_next_level; 
    unsigned int             received_buks;
    unsigned int             received_coins;
};

struct daily_dlg_param 
{
    sqc_dword bonus;
    sqc_dword day;
    sqc_dword bucks;
    
    daily_dlg_param()
        : bonus(0)
        , day(0)
        , bucks(0)
    {}
};


struct sqc_update_message_param
{
    sqc_update_message_param(sqc_game_ptr game)
    : m_game(game)
    {}
    
    sqc_game_ptr m_game;
    sqc_shop_category_deque_items  m_items;
};


//-- Daily request params
struct sqc_daily_gift_param
{   
    struct received_object
    {
        sqc_string m_item_name;
        sqc_dword  m_id;
        sqc_dword  m_from_user_id;
        sqc_dword  m_quantity;
        
    };
    
    
    struct wish_object
    {
        sqc_dword  m_friend_id;
        std::list<sqc_string> m_wishes_list;
    };
    
    
    std::list<received_object> m_received_objs;
    std::list<wish_object>     m_wish_objs;
    sqc_game_ptr m_game;
    
    sqc_daily_gift_param(sqc_game_ptr game)
    : m_game(game)
    {}
};
//--

//
// sqc_country_base_ui interface
//
class sqc_country_base_ui_face {
public:
	virtual ~sqc_country_base_ui_face(){}

	// create simple message box
	virtual milk::milk_dialog_ptr show_message_box( 
                                const sqc_message_box_params& params ) = 0;
	// create login progress window
    virtual milk::milk_dialog_ptr show_login_progress_window( 
    							const sqc_show_login_progress_params& params ) = 0;
    
    // show select network dialog
	virtual milk::milk_dialog_ptr show_select_network_dialog( 
    							const sqc_select_network_params& params ) = 0;
                                    
	virtual milk::milk_dialog_ptr  show_visit_friend_dialog() = 0;
    virtual milk::milk_dialog_ptr  show_select_preson_dialog( 
    									sqc_select_preson_delegate_ptr delegate ) = 0;
	
	virtual milk::milk_dialog_ptr show_select_construction_dlg(
    									sqc_select_construction_delegate_ptr delegate ) = 0;
                                        
    virtual milk::milk_dialog_ptr create_level_up_dialog( 
                                        sqc_level_up_params& params )      = 0;   
    
    virtual milk::milk_dialog_ptr create_on_next_level_dialog( 
                                        sqc_on_next_level_params& params ) = 0;
    
    virtual milk::milk_dialog_ptr create_daily_gift_dialog(daily_dlg_param param)   = 0;
    
    virtual milk::milk_dialog_ptr create_daily_request_dialog(sqc_daily_gift_param param) = 0;
        
    virtual milk::milk_dialog_ptr create_net_changed_dialog() = 0;
        
    virtual milk::milk_dialog_ptr create_update_message_dialog(sqc_game_ptr game) = 0;
};

END_NAMESPACE_SQC_FRAMEWORK
