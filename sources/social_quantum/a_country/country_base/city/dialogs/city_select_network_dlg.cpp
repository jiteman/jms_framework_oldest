/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_select_network_dlg.h"
#include "city/city_framework.h"
using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK

//
// city_select_network_dlg implementation
//

city_select_network_dlg::~city_select_network_dlg() {
}

// initialization 
void city_select_network_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_select_network_dlg::on_init_dialog" );
    
	sqc_select_network_dlg::on_init_dialog();

	set_bevel_type( milk::milk_bevel_type_content_scroll );
	
	sqc_window_factory& factory = framework().windows_factory();
	
	using namespace city_dlg_layout::select_network_dlg;
	
	// create title
	{
		set_caption( framework().strings().load( 
                                                common_resources::string_title_choose_net.resource_id(), common_resources::string_title_choose_net.def_value() ) );
	}
	
	// create description label
    factory.create_label( m_window_ctx, shared_from_this(), description_label );
    
    //create spinboard
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           networks_spinboard, 
                                           this );
    factory.create_spinboard_pager( m_window_ctx, shared_from_this(), m_spinboard,  networks_spinboard_pager );                                      
    m_spinboard->set_visible_count(get_visible_count() );
}


bool city_select_network_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
    
    sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
    sqc_word height[] = { 19, 38, 29 };
	a.bevel_bottom = height[theme_size];
    
	return sqc_dialog::get_dialog_init_arg(a);
}



milk::milk_widget_ptr city_select_network_dlg::on_create_cell( 
    const sqc_network_type network_type,
    surf::surf_rect const &rect_cell,
    milk::milk_callback& cell_action,
    sqc_word idx) {
    
    sqc_social_networks& networks = framework().networks();
    const sqc_network_type current_network_type = networks.current_network();
    
    // network name
    sqc_string network_name = networks.get_network_name( network_type );
    // and network images
    sqc_string network_image = networks.get_network_image( network_type );
    
    sqc_window_factory& factory = framework().windows_factory();
    
    // add cell object to spinboard
    milk::milk_widget_ptr ptr_cell = 
        m_spinboard->create_child<milk::milk_widget>( rect_cell );
    
    using namespace city_dlg_layout::select_network_dlg;
    
    // create background image
    milk::milk_theme_button_ptr	ptr_background_btn;
    {
        ptr_background_btn = 
            factory.create_button( m_window_ctx, ptr_cell, spinboard_cell_background_btn );
        
        // set action for this button
        ptr_background_btn->set_action( cell_action );
    }
    
    // create network button
    {
        milk::milk_image_ptr	ptr_network_img = 
            factory.create_image( m_window_ctx, ptr_background_btn, spinboard_cell_network_img );
        
        ptr_network_img->set_image( framework().graphics().create_image( 
                                        network_image.c_str() ) );
    }

    // create network name
    {
        // create label by layout
        milk::milk_label_ptr ptr_label = 
            factory.create_label( m_window_ctx, ptr_cell, spinboard_cell_network_caption );
        
        ptr_label->set_caption( network_name );
    }
    
    // create current network caption
    if ( current_network_type == network_type ) {
        milk::milk_label_ptr ptr_label = 
        factory.create_label( m_window_ctx, ptr_cell, spinboard_cell_current_network_caption );
        sqc_stringstream out;
        out << sqc_text("(")
            << framework().strings().load(  "*CurrentSocnet", "Current Network" )
            << sqc_text(")");
        
        ptr_label->set_caption( out.str() );
    }
    
    // create separator
    if(0 != (idx+1) % /*get_visible_count()*/ m_visible_count) 
        factory.create_separator( m_window_ctx, ptr_cell, spinboard_cell_separator );
    
    return ptr_cell;
}

END_NAMESPACE_SQC_FRAMEWORK