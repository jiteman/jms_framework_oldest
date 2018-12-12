/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_top_gui.h"
#include "city_top_gui_layout.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK


//
// sqc_city_top_gui implementation
//
sqc_city_top_gui::sqc_city_top_gui(
	milk::milk_widget_ptr p,
    sqc_window_factory_ctx_ptr window_ctx)
	: sqc_multipart_widget( p, window_ctx ){
}

sqc_city_top_gui::~sqc_city_top_gui() {
}

void sqc_city_top_gui::on_create() {
    sqc_multipart_widget::on_create();
    
    set_part_count( top_gui_part_countof );

	layout_controls();
    
    update_manage_button();
    
    if ( m_left_arrow_ptr ) {
    	set_active_rect( m_left_arrow_ptr->get_rect() );
    }
}

void sqc_city_top_gui::layout_controls() {
    milk::milk_widget_ptr parent_ptr = shared_from_this();
    
	sqc_window_factory& factory = framework().windows_factory();
    sqc_theme_size theme = factory.get_theme_size();

    surf::surf_rect rc_desktop = framework().windows().get_desktop()->get_client_rect();
    surf::surf_rect top_gui_rect = rc_desktop;

    top_gui_rect.cy = layout::top_gui::panel_height[theme];
    top_gui_rect.y = rc_desktop.cy - layout::top_gui::panel_height[theme];
    
	// and set rect!!!
	set_rect( top_gui_rect );

    using namespace layout::top_gui;
    
    set_animation_step( animation_step[theme] );
    
    // manage buttons
    if ( sqc_theme_large != theme ) {
        m_right_arrow_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              right_arrow_button_image );
                                              
        m_left_arrow_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              left_arrow_button_image );

        set_part_endpoint( top_gui_part_button,
        			 		m_right_arrow_ptr->get_rect().x + 
        					m_right_arrow_ptr->get_rect().cx );
                                        
		set_enable_move( true );
    	set_freeze_count( 1 );
		//set_visible_count( top_gui_part_countof );
	} else {
		set_enable_move( false );
    } 
    
    
    // coins
    {
        milk::milk_image_ptr	coins_back_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              coins_background );
        
        m_coins_label_ptr = factory.create_label( m_window_ctx,
                                              coins_back_ptr, 
                                              coins_label );
    }
    
    // bucks
    {
        milk::milk_image_ptr	bucks_back_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              bucks_background );

        m_bucks_label_ptr = factory.create_label( m_window_ctx,
                                              bucks_back_ptr, 
                                              bucks_label );
                                              
        set_part_endpoint( top_gui_part_prices,
        					bucks_back_ptr->get_rect().x + 
        					bucks_back_ptr->get_rect().cx );
    }

	// experience
	{
        milk::milk_image_ptr	expr_back_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              expr_background );
        
		m_progress_bar = factory.create_progress_bar(m_window_ctx, expr_back_ptr, slc_exp_band);

        milk::milk_image_ptr	star_ptr = factory.create_image( m_window_ctx,
                                              expr_back_ptr, expr_start);
                                              /*
                                              sqc_theme_large == theme ? 
                                              expr_start_hd : expr_start );*/

        m_level_label_ptr = factory.create_label( m_window_ctx,
                                              expr_back_ptr, 
                                              sqc_theme_large == theme ? 
                                              expr_level_label_hd : expr_level_label );

        m_descr_label_ptr = factory.create_label( m_window_ctx,
                                              expr_back_ptr, 
                                              sqc_theme_large == theme ? 
                                              expr_descr_label_hd : expr_descr_label );
                                              
        set_part_endpoint( top_gui_part_experience,
        					expr_back_ptr->get_rect().x + 
                            expr_back_ptr->get_rect().cx );
    }
    
	// water
	{
	    m_subpanel_water = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              maxp_background );
        shift_control_left( m_subpanel_water, water_shift[theme] );
                                              
        m_max_water_label_ptr = factory.create_label( m_window_ctx,
                                              m_subpanel_water, 
                                              maxp_label );
        
	    milk::milk_image_ptr	water_back_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              water_background );
        shift_control_left( water_back_ptr, water_shift[theme] );
                                              
        m_water_label_ptr = factory.create_label( m_window_ctx,
                                              water_back_ptr, 
                                              water_label );
                                              
        add_transparent_button( m_subpanel_water->get_rect(), 
        						water_back_ptr->get_rect(), 
                                button_water );
    }

	// power
	{
	    m_subpanel_power = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              maxp_background );
        shift_control_left( m_subpanel_power, power_shift[theme] );
                                              
        m_max_power_back_ptr = factory.create_label( m_window_ctx,
                                              m_subpanel_power, 
                                              maxp_label );
        
	    milk::milk_image_ptr	power_back_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              power_background );
        shift_control_left( power_back_ptr, power_shift[theme] );
                                              
        m_power_back_ptr = factory.create_label( m_window_ctx,
                                              power_back_ptr, 
                                              power_label );
                                              
        add_transparent_button( m_subpanel_power->get_rect(), 
        						power_back_ptr->get_rect(), 
                                button_power );
    }

	// population
	{
	    m_subpanel_popul = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              maxp_background );
        shift_control_left( m_subpanel_popul, population_shift[theme] );
                                              
        m_max_population_label_ptr = factory.create_label( m_window_ctx,
                                              m_subpanel_popul, 
                                              maxp_label );
        
	    milk::milk_image_ptr	population_back_ptr = factory.create_image( m_window_ctx,
                                              parent_ptr, 
                                              population_background );
        shift_control_left( population_back_ptr, population_shift[theme] );
                                              
        m_population_label_ptr = factory.create_label( m_window_ctx,
                                              population_back_ptr, 
                                              population_label );
                                              
        add_transparent_button( m_subpanel_popul->get_rect(), 
        						population_back_ptr->get_rect(), 
                                button_population );
                                              
        
        if ( sqc_theme_large != theme ) {
		    factory.create_image( m_window_ctx,
                                              population_back_ptr, 
                                              population_image );
        }
      
        set_part_endpoint( top_gui_part_counters,
        					population_back_ptr->get_rect().x + 
                            population_back_ptr->get_rect().cx );
    }
}

void sqc_city_top_gui::update_manage_button() {
	if ( !m_right_arrow_ptr || !m_left_arrow_ptr ) {
    	return;
    }
    
    if ( 1 == get_visible_count() ) {
    	m_left_arrow_ptr->set_visible( true );	
        m_right_arrow_ptr->set_visible( false );	
    } else {
    	m_left_arrow_ptr->set_visible( false );	
        m_right_arrow_ptr->set_visible( true );	
    }
}

void sqc_city_top_gui::update_counters( 
	const sqc_common_scene_info& info ) {

    sqc_formats& f = framework().formats();
    
    m_progress_bar->set_range(info.min_experience, info.max_experience);
    m_progress_bar->set_pos(info.experience - info.min_experience);
    
	if ( m_coins_label_ptr ) {
    	m_coins_label_ptr->set_caption( f.format_digit_compact( info.coins ) );
    }
    
    if ( m_bucks_label_ptr ) {
	    m_bucks_label_ptr->set_caption( f.format_digit_compact( info.bucks ) );
    }
    
    if ( m_level_label_ptr ) {
    	m_level_label_ptr->set_caption( f.format_digit_compact( info.level ) );
    }
    
    if ( m_descr_label_ptr ) {
        sqc_stringstream    out;
        out << f.format_digit_compact( info.experience )
            << sqc_text( "/" )
            << f.format_digit_compact( info.max_experience );
    	m_descr_label_ptr->set_caption( out.str() );
    }
    
    if ( m_water_label_ptr && m_max_water_label_ptr ) {
    	m_water_label_ptr->set_caption( f.format_digit_compact( info.water ) );
	    m_max_water_label_ptr->set_caption( f.format_digit_compact( info.max_water ) );
    }
    
    if ( m_power_back_ptr && m_max_power_back_ptr ) {
	    m_power_back_ptr->set_caption( f.format_digit_compact( info.power ) );
	    m_max_power_back_ptr->set_caption( f.format_digit_compact( info.max_power ) );
    }
    
    if ( m_population_label_ptr && m_max_population_label_ptr ) {
	    m_population_label_ptr->set_caption( f.format_digit_compact( info.population ) );
	    m_max_population_label_ptr->set_caption( f.format_digit_compact( info.max_population ) );
    }
}

bool sqc_city_top_gui::shift_control_left( 
    milk::milk_widget_ptr p, 
    const int offset ) {
    
    if ( !p ) {
    	return false;
    }
    
    surf::surf_rect rc_ctrl = p->get_rect();
    rc_ctrl.x -= offset;
    p->set_rect( rc_ctrl );
    return true;
}

void sqc_city_top_gui::on_visible_count_change() {
	sqc_multipart_widget::on_visible_count_change();
	update_manage_button();
    
    framework().notify_center().fire_event( top_gui_provider_id,
                                           top_gui_moved_on,
                                           call_async );
}


void sqc_city_top_gui::add_transparent_button(
    const surf::surf_rect& rc0, 
    const surf::surf_rect& rc1,
    const top_button_t button_type ) {

	surf::surf_rect rc_button;
    rc_button.x = std::min( rc0.x, rc1.x );
    rc_button.y = std::min( rc0.y, rc1.y );
    rc_button.cx = std::max( rc0.x + rc0.cx, rc1.x + rc1.cx ) - rc_button.x;
    rc_button.cy = std::max( rc0.y + rc0.cy, rc1.y + rc1.cy ) - rc_button.y;
    
	milk::milk_button_ptr ptr_button = 
    		shared_from_this()->create_child<milk::milk_button>( rc_button );
    if ( !ptr_button ) {
    	return;
    }
    
    ptr_button->set_action( 
    		std::tr1::bind( &sqc_city_top_gui::on_top_button_pressed, this, button_type ) );
}

void sqc_city_top_gui::on_top_button_pressed(
	const top_button_t button_type ) {
    
    milk::milk_widget_ptr ctrl;
    
    /*
    if ( button_type == button_water  ) {
    	ctrl = m_subpanel_popul;//m_max_water_label_ptr;
    } else if ( button_type == button_power ) {
	    ctrl = m_max_power_back_ptr;
    } else if ( button_type == button_population ) {
    	ctrl = m_max_population_label_ptr;
    }
     */
    if ( button_type == button_water  ) {
    	ctrl = m_subpanel_water;
    } else if ( button_type == button_power ) {
    	ctrl = m_subpanel_power;
    } else if ( button_type == button_population ) {
    	ctrl = m_subpanel_popul;
    }
    
    
    if ( !ctrl ) {
    	sqc_assert( false );
        return;
    }

    ctrl->set_visible( !ctrl->is_visible() );
}


bool sqc_city_top_gui::is_full_expanded() {
    return get_part_count() == get_visible_count();
}

END_NAMESPACE_SQC_FRAMEWORK
