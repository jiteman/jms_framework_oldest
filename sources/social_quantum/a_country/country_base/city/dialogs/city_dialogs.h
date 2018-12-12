#pragma once

#include "../../framework/sqc_framework.h"
#include "../../framework/sqc_framework_defs.h"
#include "../../framework/dialogs/sqc_base_dialog.h"
#include "../../shop/sqc_shop_defs.h"
#include "../../sqc_country_base_ui.h"
#include "city_dialogs_params.h"

#include "city_daily_gift_controller.h"

NAMESPACE_SQC_FRAMEWORK

typedef std::tr1::function<void()>	sqc_dialog_update_callback;
typedef std::list<sqc_dialog_update_callback> sqc_update_callback_list;

//
// city_dialogs implementation
//
class city_dialogs : public sqc_country_base_ui_face {
public:
    city_dialogs(sqc_notify_center &notification_center);
    ~city_dialogs();
  
    //
    // sqc_country_base_ui_face interface
    //    
    
	// create simple message box
	virtual milk::milk_dialog_ptr show_message_box( 
    								const sqc_message_box_params& params );
	// create login progress window
    virtual milk::milk_dialog_ptr show_login_progress_window( 
    								const sqc_show_login_progress_params& params );
    
    // show select network dialog
	virtual milk::milk_dialog_ptr show_select_network_dialog( 
    								const sqc_select_network_params& params );

	virtual milk::milk_dialog_ptr  show_visit_friend_dialog();
    
    virtual milk::milk_dialog_ptr  show_select_preson_dialog( 
    									sqc_select_preson_delegate_ptr delegate );
    
	virtual milk::milk_dialog_ptr show_select_construction_dlg(
    									sqc_select_construction_delegate_ptr delegate );

    virtual milk::milk_dialog_ptr show_level_up_dialog( 
                                                       sqc_level_up_params& params );   
                                                       
    virtual milk::milk_dialog_ptr show_on_next_level_dialog( 
                                                       sqc_on_next_level_params& params );
                                                       
    virtual milk::milk_dialog_ptr show_gift_wish_dialog();
                                               
    //-- create dialogs
    // This function create dialogs and return pointer on them.
    // In difference (instead) "showing" function, "create" function doesn't do dialogs modal
                                                               
    virtual milk::milk_dialog_ptr create_level_up_dialog( 
                                                       sqc_level_up_params& params );   
    
    virtual milk::milk_dialog_ptr create_on_next_level_dialog( 
                                                       sqc_on_next_level_params& params );
    
    virtual milk::milk_dialog_ptr create_daily_gift_dialog(daily_dlg_param param);
    
    virtual milk::milk_dialog_ptr create_daily_request_dialog(sqc_daily_gift_param param);
    
    virtual milk::milk_dialog_ptr create_net_changed_dialog();
    
    virtual milk::milk_dialog_ptr create_update_message_dialog(sqc_game_ptr game);
    //--                                                        
                                                                                                                                                                                                        
    //
    // City specific interface
    //    
    
	// show main menu dialog
	void show_main_menu_dialog( const sqc_main_menu_params& params );
	// show game settings dialog
	void show_game_setting_dialog( const sqc_game_setting_params& params );

    // show shop categories dialog
	void show_shop_contracts_dialog( const sqc_shop_contract_params& params );
    // show shop categories dialog
	void show_shop_categories_dialog( const sqc_shop_categories_params& params );
    // show shop categories dialog
	void show_shop_category_dialog( const sqc_shop_category_params& params );
    
    // show shop construction dialog
    void show_buy_construction_dialog( const sqc_shop_construction_params& params );
    // show shop materials dialog
    void show_buy_material_dialog( const sqc_shop_material_params& params );

    // show salary dialog 
	void show_salary_dialog();
    //void show_level_up_dialog( const sqc_level_up_params& params );
    
	// show bucks
	void show_bucks_dialog( milk::milk_widget_ptr p, const sqc_add_money_params& params );

    // show coins
	void show_coins_dialog( milk::milk_widget_ptr p, const sqc_add_money_params& params );
    
    // City Hall
    void show_cityhall_dialog( milk::milk_widget_ptr p );

    // Tax Administration
    void show_tax_administration_dialog( milk::milk_widget_ptr p );
    
protected:
    void notify_callback( const sqc_provider_id& provider_id, const sqc_event_id& event_id);
    void unsubscribe_events();
    void subscribe_events();
    void activate_update_callbacks();
    void destroy_dialog_handler(sqc_update_callback_list::iterator it);

protected:
	milk::milk_widget_ptr       desktop() const;
    sqc_update_callback_list    m_update_callbacks;
    sqc_listener_connection     m_notify_connection;
    sqc_notify_center&          m_notify_center;
};

END_NAMESPACE_SQC_FRAMEWORK
