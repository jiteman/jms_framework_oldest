#pragma once

#include "../../view/sqc_country_view.h"
#include "city_scene_view.h"
#include "../sqc_city.h"
#include "../../../milk/milk_spinboard.h"
#include "city_top_gui.h"
#include "../dialogs/city_dialogs_params.h"
#include "../dialogs/city_dialogs.h"

#include "city/dialogs/city_friends_panel/city_common_friends_controller.h"

#include "city_tools_toolbar.h"

NAMESPACE_SQC_CITY

using namespace framework;

class sqc_friend_view : 
    public milk::milk_spinboard, 
    public milk::milk_spinboard_callbacks 
{
public:
    sqc_friend_view( milk::milk_widget_ptr p ) 
        : milk_spinboard( p, this ) 
    {
    }
    
    virtual milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect ) {
        
        std::stringstream s;
        s << "ID:";
        s << idx;
        
        
        milk::milk_image_button_ptr friends_button = create_child<milk::milk_image_button>( rect );
        friends_button->set_image( get_graphics().create_image( "guiButtonFriends" ) );
        friends_button->set_pressed_image( get_graphics().create_image( "guiButtonFriendsOn" ) );
        friends_button->set_stretch( true );
        friends_button->set_caption( s.str() );
        
        return friends_button;
    }
    virtual int get_cell_count() {
        return 100;
    }
};


//
// sqc_city_country_view implementation
//
class sqc_city_country_view : public sqc_country_view {
public:
	sqc_city_country_view( milk::milk_widget_ptr p, sqc_game_ptr g ) 
		: sqc_country_view( p, g ) 
    {
	}
	virtual ~sqc_city_country_view() {
	}
	
	// create subview
	virtual void on_create();
    void create_tools_toolbar();
    virtual void	update_toolbar_controls();
    
    virtual void    show_contracts_shop( int item_id, sqc_string const &type );
    virtual void	show_material_shop( sqc_game_object_ptr object );
    virtual void	show_construction_shop( sqc_point const &object_coords, sqc_string const &type );
    virtual void	show_shop( sqc_point const &object_coords );
    
    // TODO
    virtual void    show_seeds_shop( sqc_point const &object_coords ) {    
    }
    virtual void    show_animals_shop( sqc_point const &object_coords ) {    
    }

    bool			create_top_gui();
    virtual void	update_top_gui();

    bool on_contract_purchased(int item_id, sqc_string object_type );
    bool on_material_purchased( int item_id, sqc_string object_type );
    bool on_construction_purchased( sqc_string object_type, sqc_point object_coords );
    bool on_object_purchased( sqc_string object_type, sqc_point object_coords );
    bool on_object_gift( sqc_string object_type, sqc_string second_user_id );
    void on_add_money(sqc_add_money_enum money);
    
    virtual void	notify_callback( const sqc_provider_id& provider_id, 
                                    const sqc_event_id& event_id );

protected:

	// gifts button is pressed
    void on_gifts_pressed();
    
	// friends button is pressed
    void on_visit_friend_field_pressed();
    void on_leave_friend_field_pressed();

    void on_achive_button_pressed();
    void on_top_button_pressed();
    void on_league_button_pressed();
    void on_quest_button_pressed();
    void on_message_button_pressed();
    void on_add_coins_button_pressed();
    
    //-- To Do : test only
    void on_quest_test_button_pressed();
    //--
    
	// market button is pressed
// eugenesh: moved up
//    void on_market_pressed();
	// edit button is pressed
    void on_edit_pressed();
	// menu button is pressed
    void on_menu_pressed();
    
    void on_cancel_pressed();
    void on_apply_pressed();
    
// eugenesh: moved up
//    void on_rotate_pressed();
//    void on_delete_pressed();
    
    void get_input_fill(sqc_string_map &input_fill, sqc_game_object_ptr object);
    
    sqc_dword get_gift_count();
    void create_gift_count_label();
    
    
    sqc_dword get_league_level();
    void create_league_button();
    
    sqc_dword get_quest_count();
    void create_quest_count_label(image_rects rects);
    
    sqc_word get_message_count();

    void add_coins_button_change_position();
    void gift_quest_message_change_position(bool up = true);
	
    // show tooltip
	void show_tooltip( const sqc_string& text ,const surf::surf_point& pos);
    
    void on_tools_toolbar_button( sqc_city_tools_toolbar::button_kind kind );
protected:
	milk::milk_image_button_ptr m_gifts_button;
	milk::milk_image_button_ptr m_friends_button;
	milk::milk_image_button_ptr m_market_button;
	milk::milk_image_button_ptr m_edit_button;
	milk::milk_image_button_ptr m_menu_button;
	milk::milk_image_button_ptr m_leave_friend_button;
  	milk::milk_image_button_ptr m_achive_button;
   	milk::milk_image_button_ptr m_top_button;
 	milk::milk_image_button_ptr m_league_button;
  	milk::milk_image_button_ptr m_quest_button;
    milk::milk_image_button_ptr m_message_button;
    milk::milk_image_button_ptr m_add_coins_button;
    
    milk::milk_label_ptr ptr_add_coins_caption;
    
	sqc_city_tools_toolbar_ptr	m_tools_toolbar;
    sqc_city_top_gui_ptr		m_top_gui;
    
    city_common_person_controller_ptr   m_friends_panel_ptr;
};

	
END_NAMESPACE_SQC_CITY
