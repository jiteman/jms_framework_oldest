/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_country_view.h"
#include "city_scene_view.h"
#include "sqc_city_objects.h"

#include "country_base/sqc_framework_base.h"
#include "country_base/tools/sqc_tools_common.h"
#include "city/city_framework.h"
#include "animation/animation_animators.h"
#include "animation/animation_server.h"

#include "city_country_view_layout.h"

using namespace std::tr1::placeholders;


NAMESPACE_SQC_CITY




//
// sqc_city_country_view implementation
//

// create subview
void sqc_city_country_view::on_create() {
    sqc_country_view::on_create();

	sqc_window_factory& factory = city_framework().windows_factory();
    
    //
    // scene view
    //
    std::tr1::shared_ptr<sqc_city_scene_view> scene = create_child<sqc_city_scene_view>( get_rect(), m_game->get_field() );
    m_ptr_scene_view = scene;
	
    if (city_framework().windows_factory().get_theme_size() == sqc_theme_large)
    {
    	m_friends_panel_ptr.reset( new city_common_person_controller( scene, m_window_ctx ) );
        
        /*
        // test friends
        sqc_user_profile_list test_friends_list;
        sqc_user_profile_ptr pup(new sqc_user_profile);
        pup->set_first_name("Alexandr");
        pup->set_last_name("Ivanov");
        pup->set_aliase("Dark Angel");
        pup->set_user_id("123556");
        pup->set_gender(sqc_male);
        pup->set_avatar_url("http://dsfsfsdf");
        pup->set_in_game(true);
        pup->set_have_gift(true);
        pup->set_level(10);

        test_friends_list.push_back(pup);
        */

        m_friends_panel_ptr->set_game_info(m_game);
        m_friends_panel_ptr->set_scene_view(m_ptr_scene_view);
		
        city_framework().networks().query_friends();
        
        m_friends_panel_ptr->instance_view();

        //m_friends_panel_ptr->hide();

        //m_friends_panel.instance_view( m_ptr_scene_view );
        //m_friends_panel.activate( m_window_ctx );
        //m_friends_panel.make_friends_list(test_friends_list);
        //m_friends_button->set_visible(false);
    }
    else {
        // create friends button
        m_friends_button	= factory.create_button( m_window_ctx, scene, city_country_view_layout::friend_button );
        m_friends_button->set_action( std::tr1::bind( &sqc_city_country_view::on_visit_friend_field_pressed, this ) );
        
    }
    
	// create market button
	m_market_button		= factory.create_button( m_window_ctx, scene, city_country_view_layout::market_button );
	m_market_button->set_action( std::tr1::bind( &sqc_city_country_view::on_market_pressed, this ) );
											   
	// create edit button
	m_edit_button		= factory.create_button( m_window_ctx, scene, city_country_view_layout::edit_button );
	m_edit_button->set_action( std::tr1::bind( &sqc_city_country_view::on_edit_pressed, this ) );
											   
	// create menu button
	m_menu_button		= factory.create_button( m_window_ctx, scene, city_country_view_layout::menu_button );
	m_menu_button->set_action( std::tr1::bind( &sqc_city_country_view::on_menu_pressed, this ) );
    
    // !!! tempo
	// create menu button
    
	
    
	m_leave_friend_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::leave_friend_button );
	m_leave_friend_button->set_action( std::tr1::bind( &sqc_city_country_view::on_leave_friend_field_pressed, this ) );
    
    m_achive_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::achive_button );
    m_achive_button->set_action( std::tr1::bind( &sqc_city_country_view::on_achive_button_pressed, this ) );
    
    m_top_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::top_button );
    m_top_button->set_action( std::tr1::bind( &sqc_city_country_view::on_top_button_pressed, this ) );
    
    //-- To Do : quests 
    milk::milk_image_button_ptr m_quest_test_2_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::quest_test_2_button );
    m_quest_test_2_button->set_action( std::tr1::bind( &sqc_city_country_view::on_quest_test_button_pressed, this ) );

    milk::milk_image_button_ptr m_quest_test_1_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::quest_test_1_button );
    m_quest_test_1_button->set_action( std::tr1::bind( &sqc_city_country_view::on_quest_test_button_pressed, this ) );
    //--
    
    // create message and quest button
    {
        sqc_theme_size _theme = factory.get_theme_size();
        sqc_word _mc = get_message_count();
        if(_mc != 0)
        {
            m_message_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::message_button );
            m_message_button->set_action( std::tr1::bind( &sqc_city_country_view::on_message_button_pressed, this ) );
            
            m_quest_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::quest_button );
            m_quest_button->set_action( std::tr1::bind( &sqc_city_country_view::on_quest_button_pressed, this ) );
        }
        else
        {
            m_quest_button = factory.create_button( m_window_ctx, scene, city_country_view_layout::quest_button );
            m_quest_button->set_action( std::tr1::bind( &sqc_city_country_view::on_quest_button_pressed, this ) );
            
            m_quest_button->set_rect(city_country_view_layout::message_and_quest_rects[0].at(_theme));
        }
        
        create_quest_count_label(city_country_view_layout::quest_label_rects);
    }
    
    // create gifts button
	m_gifts_button		= factory.create_button( m_window_ctx, scene, city_country_view_layout::gift_button );
	m_gifts_button->set_action( std::tr1::bind( &sqc_city_country_view::on_gifts_pressed, this ) );
    
    // add coins and megabucks
    m_add_coins_button = factory.create_button( m_window_ctx, scene,city_country_view_layout::add_coins_button  );
    //factory.create_label( m_window_ctx, scene, city_country_view_layout::add_coins_caption );
    ptr_add_coins_caption = 
        city_framework().windows_factory().create_label(
                                                    m_window_ctx, 
                                                    scene,
                                                    city_country_view_layout::add_coins_caption
                                                    );	
                                                    
    m_add_coins_button->set_action( std::tr1::bind( &sqc_city_country_view::on_add_coins_button_pressed, this ) );

    create_tools_toolbar();
    update_toolbar_controls();
    
	create_top_gui();
    update_top_gui();
}


void sqc_city_country_view::on_tools_toolbar_button( sqc_city_tools_toolbar::button_kind kind ) {
    
    tools::sqc_tools_controlles &controller = country_framework().tools();
    
    if (kind == sqc_city_tools_toolbar::cancel_button || kind == sqc_city_tools_toolbar::apply_button) {
        
        if (kind == sqc_city_tools_toolbar::apply_button) {
            controller.process_action( tools::tool_action_apply, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
        }
        else if (kind == sqc_city_tools_toolbar::cancel_button) {
            controller.process_action( tools::tool_action_cancel, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
        }
        
        if ( controller.get_active_tool() != tools::tool_type_buy || kind == sqc_city_tools_toolbar::cancel_button) {
            m_ptr_scene_view->get_tool_context().hide_bubble();
            m_ptr_scene_view->get_tool_context().reset_selected_object();
            
            switch_to_default_tool();
            m_tools_toolbar->hide_toolbar();
        }
    }
    else if (kind == sqc_city_tools_toolbar::move_button) {
        controller.process_action( tools::tool_action_rotate, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
    }
    else if (kind == sqc_city_tools_toolbar::delete_button) {
        controller.process_action( tools::tool_action_delete, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
    }
    else if (kind == sqc_city_tools_toolbar::warehouse_button) {
        controller.process_action( tools::tool_action_warehouse, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
    }
    else if (kind == sqc_city_tools_toolbar::market_button) {
        controller.process_action( tools::tool_action_market, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
    }
}

void sqc_city_country_view::on_quest_test_button_pressed()
{
        sqc_info() << "on_quest_test_button_pressed";
}

void sqc_city_country_view::on_add_coins_button_pressed()
{
    sqc_info() << "on_add_coins_button_pressed";
}

void sqc_city_country_view::gift_quest_message_change_position(bool up)
{
    surf::surf_rect next_quest_rect =  m_quest_button->get_rect();
    surf::surf_rect next_gift_rect  =  m_gifts_button->get_rect();
    
    surf::surf_rect next_message_rect;
    surf::surf_rect now_message_rect;
    
    const sqc_dword _offset = 114;
    
    if(up)
    {
        next_quest_rect.y += _offset;
        next_gift_rect.y += _offset;
    
        if(m_message_button)
        {
            now_message_rect =  m_message_button->get_rect();
        
            next_message_rect = now_message_rect;
            next_message_rect.y += _offset;
        }
    }
    else
    {
        next_quest_rect.y -= _offset;
        next_gift_rect.y -= _offset;
        
        if(m_message_button)
        {
            now_message_rect =  m_message_button->get_rect();
            
            next_message_rect = now_message_rect;
            next_message_rect.y -= _offset;
        }
    }
    
    
    surf::surf_rect now_quest_button_rect = m_quest_button->get_rect();
    surf::surf_rect now_gift_button_rect  = m_gifts_button->get_rect();
    
    using namespace sqc::animation;
    get_server().animation().add_animator(
                                          m_quest_button->transform(),
                                          animation_animator_sequency().add( animation_animator_translate_relative( next_quest_rect.top_left() - now_quest_button_rect.top_left(),0.5) )
                                          .add( animation_animator_event( std::tr1::bind(&milk::milk_widget::set_rect,m_quest_button, next_quest_rect))) 
                                          );
    
    get_server().animation().add_animator(
                                          m_gifts_button->transform(),
                                          animation_animator_sequency().add( animation_animator_translate_relative(next_gift_rect.top_left()-now_gift_button_rect.top_left(),0.5) )
                                          .add( animation_animator_event( std::tr1::bind(&milk::milk_widget::set_rect,m_gifts_button,next_gift_rect))) 
                                          );
    
    
    if(m_message_button)
    {
        get_server().animation().add_animator(
                                              m_message_button->transform(),
                                              animation_animator_sequency().add( animation_animator_translate_relative(next_message_rect.top_left()-now_message_rect.top_left(),0.5) )
                                              .add( animation_animator_event( std::tr1::bind(&milk::milk_widget::set_rect,m_message_button,next_message_rect))) 
                                              );
    }
    
}

void sqc_city_country_view::add_coins_button_change_position()
{
    if(!m_top_gui)
        return;
    
    bool _is_full = m_top_gui->is_full_expanded();
    
    surf::surf_rect button_rect = city_framework().windows_factory().layout_child_rects( 
                                                                                        shared_from_this(), 
                                                                                        _is_full ? city_country_view_layout::add_coins_rect[0].button_rects
                                                                                                   : city_country_view_layout::add_coins_rect[1].button_rects,
                                                                                        layout_alignment( layout_halignment_left | layout_valignment_top ) );
    
    surf::surf_rect caption_rect = city_framework().windows_factory().layout_child_rects( 
                                                                                         shared_from_this(), 
                                                                                         _is_full ? city_country_view_layout::add_coins_rect[0].caption_rects
                                                                                                    : city_country_view_layout::add_coins_rect[1].caption_rects,
                                                                                         layout_alignment( layout_halignment_left | layout_valignment_top ) );
                                                                                         
    //--
    surf::surf_rect now_button_rect = m_add_coins_button->get_rect();
    surf::surf_rect now_caption_rect = ptr_add_coins_caption->get_rect();
    
    using namespace sqc::animation;
    get_server().animation().add_animator(
                                          m_add_coins_button->transform(),
                                          animation_animator_sequency().add( animation_animator_translate_relative(button_rect.top_left()-now_button_rect.top_left(),0.5) )
                                          .add( animation_animator_event( std::tr1::bind(&milk::milk_widget::set_rect,m_add_coins_button,button_rect))) 
                                          );
                                          
    get_server().animation().add_animator(
                                         ptr_add_coins_caption->transform(),
                                         animation_animator_sequency().add( animation_animator_translate_relative(caption_rect.top_left()-now_caption_rect.top_left(),0.5) )
                                         .add( animation_animator_event( std::tr1::bind(&milk::milk_widget::set_rect,ptr_add_coins_caption,caption_rect))) 
                                         );
    //--
}
    
void sqc_city_country_view::create_league_button()
{
    if(m_league_button)
        return;
    
    sqc_dword _level = get_league_level();
    
    if( _level != 0)
    {
        _level = _level - 1; // "-1" becouse used like arrived index
        sqc_theme_size _theme = city_framework().windows_factory().get_theme_size();
        surf::surf_image_ptr _normal = sqc::framework::framework().graphics().create_image(
                                                                                           city_country_view_layout::league_images_button[_level].normal.at(_theme).c_str());
        surf::surf_image_ptr _pressed = sqc::framework::framework().graphics().create_image(
                                                                                            city_country_view_layout::league_images_button[_level].pressed.at(_theme).c_str());
        
        
        m_league_button = city_framework().windows_factory().create_button( m_window_ctx, m_ptr_scene_view, city_country_view_layout::league_button );
        m_league_button->set_image( _normal );
        m_league_button->set_pressed_image( _pressed );    
        m_league_button->set_action( std::tr1::bind( &sqc_city_country_view::on_league_button_pressed, this ) );
    }
}

sqc_dword sqc_city_country_view::get_gift_count()
{
    sqc_received_gift::vector	received_gifts;
    m_game->get_received_gifts( received_gifts );
    
    sqc_available_gift::vector	available_gifts;
    m_game->get_available_gifts( available_gifts );
    
    sqc_wishes::vector	wishess;
    m_game->get_wishes_gifts( wishess );
    
    return (available_gifts.size() + received_gifts.size() + wishess.size());
}

sqc_dword sqc_city_country_view::get_quest_count()
{
    return 0;
}

sqc_word sqc_city_country_view::get_message_count()
{
    return 0;
}

void sqc_city_country_view::create_quest_count_label(image_rects rect)
{
    sqc_dword _count = get_quest_count();
    if(_count != 0)
    {
        sqc_theme_size _theme = city_framework().windows_factory().get_theme_size();
                
        milk::milk_label_ptr ptr_label_quest_count = 
            city_framework().windows_factory().create_label(
                                                        m_window_ctx, 
                                                        m_quest_button,
                                                        city_country_view_layout::label_quest_count);	
        
        ptr_label_quest_count->set_caption(
                                          format(sqc::framework::framework().strings().load(
                                                                                            city_country_view_layout::string_quest_count.resource_id(),
                                                                                            city_country_view_layout::string_quest_count.def_value()),
                                                 _count));
                                                 
        ptr_label_quest_count->set_rect(rect.at(_theme));
    }
}

void sqc_city_country_view::on_message_button_pressed()
{
        sqc_info() << "on_message_button_pressed";
}
    
sqc_dword sqc_city_country_view::get_league_level()
{
    sqc_common_scene_info _ci;
    m_game->fill_common_info(_ci);
    
    if(_ci.league_level <= 0)
        sqc_error() << "league_level incorrect! was changed on level = 1";
    
    return _ci.league_level;
}

void sqc_city_country_view::create_tools_toolbar() {
    
     if ( m_tools_toolbar || !m_edit_button || !m_ptr_scene_view ) {
    	return;
    }
    
    m_tools_toolbar = sqc_city_tools_toolbar_ptr( new sqc_city_tools_toolbar() );
    m_tools_toolbar->create_buttons( m_ptr_scene_view );
    m_tools_toolbar->set_action(std::tr1::bind(&sqc_city_country_view::on_tools_toolbar_button,this,std::tr1::placeholders::_1));
}

bool sqc_city_country_view::create_top_gui() {
    surf::surf_rect rc;
    if ( !m_ptr_scene_view ) {
    	return false;
    }
    
    m_top_gui = m_ptr_scene_view->create_child<sqc_city_top_gui>( rc, m_window_ctx );
    return true;
}

void sqc_city_country_view::update_top_gui() {

	sqc_assert( m_top_gui );
    if ( !m_top_gui || !m_game ) {
    	return;
    }
    
    sqc_city_game_ptr city_game_ptr = 
		    std::tr1::static_pointer_cast<sqc_city_game>( m_game );
    
	sqc::sqc_common_scene_info info;
    city_game_ptr->fill_common_info( info );

	m_top_gui->update_counters( info );
}

void sqc_city_country_view::update_toolbar_controls() {

   if ( !m_tools_toolbar ) {
	    return;
    }
	
    tools::sqc_tools_controlles &controller = city_framework().tools();
	sqc::tools::sqc_tool_type type = controller.get_active_tool();
    
    if( !m_edit_button ) {
        return;
    }
    
    if ( sqc::tools::tool_type_edit == type || sqc::tools::tool_type_buy == type ) {
        m_tools_toolbar->show_toolbar(); 
    } else {
        m_tools_toolbar->hide_toolbar(); 
    } 

    m_edit_button->set_visible( sqc::tools::tool_type_multi == type );
    
    /*
    // To remove ? 
    if(m_friends_button) {
        m_friends_button->set_visible( sqc::tools::tool_type_multi == type ||
                                       sqc::tools::tool_type_visit_field == type );
    }
    
    m_gifts_button->set_visible( sqc::tools::tool_type_multi == type );
    */
    
    m_menu_button->set_visible( sqc::tools::tool_type_multi == type );
    
    m_market_button->set_visible( sqc::tools::tool_type_multi == type );
	
    m_leave_friend_button->set_visible( sqc::tools::tool_type_visit_field == type );
    
    create_league_button();
    
    create_gift_count_label();
}

void sqc_city_country_view::create_gift_count_label()
{
    sqc_dword _count = get_gift_count();
    if(_count != 0)
    {
        city_framework().windows_factory().create_image( m_window_ctx, m_gifts_button/*shared_from_this()*/,city_country_view_layout::gift_number_img );
        
        milk::milk_label_ptr ptr_label_gift_count = 
            city_framework().windows_factory().create_label(
                                                        m_window_ctx, 
                                                        m_gifts_button,
                                                        city_country_view_layout::label_gift_count);	
        
        ptr_label_gift_count->set_caption(
                                          format(sqc::framework::framework().strings().load(
                                                                                            city_country_view_layout::string_gift_count.resource_id(),
                                                                                            city_country_view_layout::string_gift_count.def_value()),
                                                 _count));
    }
}


// gifts button is pressed
void sqc_city_country_view::on_gifts_pressed() {
    // TEMPO
	//city_dialogs& dialogs = city_framework().dialogs();
	//dialogs.show_buy_construction_dialog( shared_from_this(), "Construction" );
    
    city_framework().dialogs().show_gift_wish_dialog();
}

void sqc_city_country_view::on_quest_button_pressed()
{
    sqc_info() << "on_quest_button_pressed";

}

void sqc_city_country_view::on_visit_friend_field_pressed() {

    city_framework().dialogs().show_visit_friend_dialog();
}

void sqc_city_country_view::on_leave_friend_field_pressed() {

    // just activate default tool
    tools::sqc_activate_tool_arg    arg = {};
    
    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.activate_tool( tools::tool_type_multi, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

void sqc_city_country_view::on_achive_button_pressed()
{
    sqc_info() << "on_achive_button_pressed";
}

void sqc_city_country_view::on_top_button_pressed()
{
    sqc_info() << "on_top_button_pressed";
}

void sqc_city_country_view::on_league_button_pressed()
{
    sqc_info() << "on_league_button_pressed";
}

// eugenesh: moved up
// market button is pressed
/*void sqc_city_country_view::on_market_pressed() {
    tools::sqc_activate_tool_arg    arg = {};

    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.activate_tool( tools::tool_type_buy, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}*/

// edit button is pressed
void sqc_city_country_view::on_edit_pressed() {
    
    tools::sqc_activate_tool_arg    arg = {};
    
    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.activate_tool( tools::tool_type_edit, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

// edit button is pressed
void sqc_city_country_view::on_cancel_pressed() {    
    tools::sqc_activate_tool_arg    arg = {};
    
    m_ptr_scene_view->get_tool_context().reset_selected_object();
    
    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.activate_tool( tools::tool_type_multi, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
}

void sqc_city_country_view::on_apply_pressed() {
    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.process_action( tools::tool_action_apply, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
    
}

// eugenesh: moved up
/*void sqc_city_country_view::on_rotate_pressed() {
    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.process_action( tools::tool_action_rotate, m_ptr_scene_view->get_tool_context() );
}
void sqc_city_country_view::on_delete_pressed() {
    tools::sqc_tools_controlles &controller = city_framework().tools();
    controller.process_action( tools::tool_action_delete, m_ptr_scene_view->get_tool_context() );
}*/

// menu button is pressed

void sqc_city_country_view::on_menu_pressed() {
	city_dialogs& dialogs = city_framework().dialogs();
    
    sqc_main_menu_params	params;
    
    params.add_money.add_money_callback = std::tr1::bind(&sqc_city_country_view::on_add_money, this, _1);
	
    params.shop_categories_params.category_params.add_money.add_money_callback = std::tr1::bind(&sqc_city_country_view::on_add_money, this, _1);
    
    params.shop_categories_params.category_params.buy_callback = 
    	std::tr1::bind( &sqc_city_country_view::on_object_purchased, this, _1, sqc_point() );
    params.shop_categories_params.category_params.gift_callback = 
    	std::tr1::bind( &sqc_city_country_view::on_object_gift, this, _1, _2 );
    
    m_game->fill_common_info( params.shop_categories_params.category_params.scene_info );
    
     
	dialogs.show_main_menu_dialog( params );
    
}

bool sqc_city_country_view::on_contract_purchased(int item_id, sqc_string object_type ) {
    using namespace processor;
    
    processor::sqc_command_processor& proc = city_framework().cmd_processor();
    
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_put_command( str_user_id, object_type, item_id ) );
    proc.schedule( command );
    
    return true;
}

bool sqc_city_country_view::on_material_purchased(int item_id, sqc_string object_type ) {
    using namespace processor;
    
    processor::sqc_command_processor& proc = city_framework().cmd_processor();
        
    sqc_string str_user_id = "";
    sqc_command_ptr  command( new sqc_apply_command( str_user_id, object_type, item_id ) );
    proc.schedule( command );
    
    return true;
}

bool sqc_city_country_view::on_construction_purchased( sqc_string object_type, sqc_point object_coords ) {
    using namespace processor;
    
    sqc::info::sqc_object_info_provider_ptr provider = city_framework().object_factory();
    processor::sqc_command_processor& proc = city_framework().cmd_processor();
    
    sqc_city_buildingsite_info *object_info = 
                static_cast<sqc_city_buildingsite_info*>(provider->get_object_info(object_type.c_str()));
    
    sqc_point position;
    position.x = object_info->get_position_x();
    position.y = object_info->get_position_y();
    
    sqc_string str_user_id = "";
    bool rotation = false;
    sqc_command_ptr  command( new sqc_create_command( str_user_id, object_type, position, rotation ) );
    proc.schedule( command );
    
    return true;
}


bool sqc_city_country_view::on_object_purchased( sqc_string object_type, sqc_point object_coords ) {
    //get shop
	sqc_shop shop = city_framework().shop();
	const sqc_object_info *p_obj = city_framework().object_factory()->get_object_info( object_type.c_str() );
    
    sqc_assert(p_obj && "have no object");
    
    if ( p_obj->get_pseudo_item() )
    {
		const sqc_string userid="";
        const sqc_string type_name = p_obj->get_type_name();
        const sqc_point point;
        // const bool rotate = false;

		/* call
            sqc_apply_command( const sqc_string& user_id,
                       const sqc_string &object_type,
                       const int item_id ) 

            sqc_create_command( const sqc_string& user_id,
                                const sqc_string& object_type,
                                const sqc_point& create_point,
                                const bool rotation ) 
                       
        */

        processor::sqc_command_ptr command(
            new sqc::processor::sqc_create_command(
                userid,
                type_name,
                sqc_point(),
                false
            )
        );

        city_framework().cmd_processor().schedule( command );
    }
    else {
        tools::sqc_activate_tool_arg    arg = {};

        arg.operation_coords_defined = true;
        arg.operation_coords = object_coords;
        arg.purchased_object_type = object_type;


        tools::sqc_tools_controlles &controller = city_framework().tools();
        controller.activate_tool( tools::tool_type_buy, arg, m_ptr_scene_view->get_tool_context(), *m_ptr_scene_view.get() );
	}
    
    return true;
}

bool sqc_city_country_view::on_object_gift( sqc_string object_type, sqc_string second_user_id ) {
    
    const sqc_string user_id			= "";

	using namespace processor;
	sqc_command_ptr  command( new sqc_send_shop_gift_command( user_id, object_type, second_user_id ) );
	city_framework().cmd_processor().schedule( command );
    
    return true;
}


void sqc_city_country_view::get_input_fill(sqc_string_map &input_fill, sqc_game_object_ptr object) {
    input_fill = object->get_input_fill();
    
    for (sqc_string_map::iterator it = input_fill.begin(); it != input_fill.end(); ++it) {
        sqc_string first = it->first;
        sqc_string second = it->second;
    }
}

void sqc_city_country_view::show_contracts_shop(int item_id, sqc_string const &type ) {
	using namespace std::tr1::placeholders;
    
    city_dialogs& dialogs = city_framework().dialogs();
    
    sqc_shop_contract_params  params;
    params.buy_callback = std::tr1::bind( &sqc_city_country_view::on_contract_purchased, this, item_id, _1 );
    params.factory_type = type;
    
    m_game->fill_common_info( params.scene_info );
    
    dialogs.show_shop_contracts_dialog( params );
        
}

void sqc_city_country_view::on_add_money(sqc_add_money_enum money) {
	// Handler event add money
    sqc_info() << "Call add money handler with parameter: " << money;
}

void sqc_city_country_view::show_material_shop(sqc_game_object_ptr object ) {
	sqc_buildsite_base_ptr buildsite_object = std::tr1::static_pointer_cast<sqc_buildsite_base>(object);
    
    if (buildsite_object->is_buildsite_produce()) {
        using namespace std::tr1::placeholders;
    
        city_dialogs& dialogs = city_framework().dialogs();
        
        sqc_shop_material_params  params;
        params.buy_callback = std::tr1::bind( &sqc_city_country_view::on_material_purchased, this, object->get_id(), _1 );
        params.input_fill_callback = std::tr1::bind( &sqc_city_country_view::get_input_fill, this, _1, object);
        params.buildsite_type = object->get_type();
        
        m_game->fill_common_info( params.scene_info );
        
        dialogs.show_buy_material_dialog( params );
    }    
}

void sqc_city_country_view::show_construction_shop( sqc_point const &object_coords, sqc_string const &type ) {
	city_dialogs& dialogs = city_framework().dialogs();
    
    sqc_shop_construction_params  params;
    params.buy_callback = std::tr1::bind( &sqc_city_country_view::on_construction_purchased, this, _1, object_coords );
    params.construction_type = type;
     
    m_game->fill_common_info( params.scene_info );
    
	dialogs.show_buy_construction_dialog( params );
    
}

void sqc_city_country_view::show_shop( sqc_point const &object_coords ) {
	city_dialogs& dialogs = city_framework().dialogs();
    
    sqc_shop_categories_params  params;
    params.category_params.buy_callback = std::tr1::bind( &sqc_city_country_view::on_object_purchased, this, _1, object_coords );
    params.category_params.gift_callback = std::tr1::bind( &sqc_city_country_view::on_object_gift, this, _1, _2 );
    params.category_params.add_money.add_money_callback = std::tr1::bind(&sqc_city_country_view::on_add_money, this, _1);
    
    m_game->fill_common_info( params.category_params.scene_info );

	dialogs.show_shop_categories_dialog( params );
    
}

void sqc_city_country_view::notify_callback( 
                                       const sqc_provider_id& provider_id, 
                                       const sqc_event_id& event_id ) {
    
    sqc_country_view::notify_callback( provider_id, event_id );
    
    if ( sqc::tools::tool_provider_id == provider_id ) {
    	
        if ( sqc::tools::object_tool_event == event_id ) {
            tools::sqc_tools_controlles &controller = country_framework().tools();
            
            if (m_tools_toolbar->is_visible()) {
            
                bool enable = true;
                m_tools_toolbar->enable_buttons(sqc_city_tools_toolbar::cancel_button, enable);
                
                enable = controller.is_action_avaible(tools::tool_action_apply, m_ptr_scene_view->get_tool_context());
                m_tools_toolbar->enable_buttons(sqc_city_tools_toolbar::apply_button, enable);
                
                enable = controller.is_action_avaible(tools::tool_action_delete, m_ptr_scene_view->get_tool_context());
                m_tools_toolbar->enable_buttons(sqc_city_tools_toolbar::delete_button, enable);
                
                enable = controller.is_action_avaible(tools::tool_action_rotate, m_ptr_scene_view->get_tool_context());
                m_tools_toolbar->enable_buttons(sqc_city_tools_toolbar::move_button, enable);
                
                enable = controller.is_action_avaible(tools::tool_action_warehouse, m_ptr_scene_view->get_tool_context());
                m_tools_toolbar->enable_buttons(sqc_city_tools_toolbar::warehouse_button, enable);
                
                enable = controller.is_action_avaible(tools::tool_action_market, m_ptr_scene_view->get_tool_context());
                m_tools_toolbar->enable_buttons(sqc_city_tools_toolbar::market_button, enable);
            }
            
        }                    
    }   
    
    if ( sqc::tools::top_gui_provider_id == provider_id ) {
    	
        if ( sqc::tools::top_gui_moved_on == event_id ) {
     
            add_coins_button_change_position();
        }
    }    
    
    if ( friends_panel_provider_id == provider_id ) {
    	
        if ( friends_panel_show_event == event_id ) {
            
          gift_quest_message_change_position(true);                                      
                                                
        }
       
        if ( friends_panel_hide_event == event_id ) {
        
            gift_quest_message_change_position(false);
        
        }
    }
}

// show tooltip
void sqc_city_country_view::show_tooltip( const sqc_string& text ,const surf::surf_point& pos) {
	std::cout << "city: show tooltip : " << text << std::endl;
	milk::milk_label_ptr lbl = create_child<milk::milk_label>(surf::surf_rect(pos,surf::surf_size(100,30)));
	lbl->set_caption( text );
	get_server().animation().add_animator( lbl->transform(), animation::animation_animator_sequency()
																						   .add(animation::animation_animator_translate_relative( surf::surf_point(0,100), 5 ))
																						   .add(animation::animation_animator_event(
																															   std::tr1::bind(&milk::milk_widget::destroy,lbl)
																						   ))
								 );
}

END_NAMESPACE_SQC_FRAMEWORK
