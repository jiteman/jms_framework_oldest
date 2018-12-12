/*
 *  city_level_up_dlg.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 08.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_level_up_dlg.h"
#include "city_level_up_dlg_layout.h"
#include "city/city_framework.h"
#include "surf_defs.h"

NAMESPACE_SQC_FRAMEWORK

void city_level_up_dlg::on_init_dialog()
{
    PROFILE_ENTRY( "city_level_up_dlg::on_init_dialog" );
    
    sqc_dialog_with_next::on_init_dialog();
	
	
	sqc_window_factory& factory = framework().windows_factory();
    
    sqc_theme_size current_theme = factory.get_theme_size();
    
    using namespace city_dlg_layout::level_up_dlg;
    
	create_background( backgrounds );
	
    factory.create_image( m_window_ctx, shared_from_this(), hat ); 
   
    
    milk::milk_label_ptr label_up = 
    factory.create_label(
                         m_window_ctx, 
                         shared_from_this(),
                         label
                         );	
    
    milk::milk_label_ptr ptr_level_up = 
    factory.create_label(
                         m_window_ctx, 
                         shared_from_this(),
                         label_level_up
                         );	       

    ptr_level_up->set_caption(
                      format(framework().strings().load(
                                        city_dlg_layout::level_up_dlg::label_level.resource_id(),
                                        city_dlg_layout::level_up_dlg::label_level.def_value()),
                              m_params.scene_info.level)
                              );

    if(sqc_theme_large == current_theme)
    {   
        label_up->set_color(surf::surf_color(0,0,0,1));
        ptr_level_up->set_color(surf::surf_color(1,1,1,1));
    }

    label_up->set_caption(
                 format(framework().strings().load(
                                         city_dlg_layout::level_up_dlg::label_with_string.resource_id(),
                                         city_dlg_layout::level_up_dlg::label_with_string.def_value()), 
                        m_params.received_buks, m_params.received_coins)
                         );                 
    
    m_items.clear();
    
    sqc_shop_enum_params enum_params( 0/*enum all levels*/, m_params.shop_category, shop_target );
    city::city_framework().shop().enum_shop_category( enum_params, m_params.scene_info, m_items );
    
    //create spinboard    
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                            shared_from_this(), 
                                            level_up_spinboard_layout, 
                                            this );
    
	// create pager
	factory.create_spinboard_pager( m_window_ctx,
								   shared_from_this(),
								   m_spinboard,
								   level_up_spinboard_pager );
	
    // set cell count
    m_spinboard->set_visible_count( city_dlg_layout::level_up_dlg::cell_count );
    
}


milk::milk_widget_ptr city_level_up_dlg::create_cell(sqc_int idx, surf::surf_rect const &rect ) 
{
    PROFILE_ENTRY( "level_up_dlg::create_cell" );
    
    if ( idx >= m_items.size() || idx < 0 )
     {
       sqc_assert( false );
       return milk::milk_widget_ptr();
     }
    
    
    // add cell object to spinboard
    sqc_shop_item_cell_ptr ptr_cell = 
                m_spinboard->create_child<sqc_shop_item_cell>( rect, m_items[idx], shop_target );
    
    if ( !ptr_cell ) 
    {
        return milk::milk_widget_ptr();
    }
    
    
    ptr_cell->set_buy_callback(
    	std::tr1::bind( &city_level_up_dlg::on_buy_item_pressed, this, std::tr1::placeholders::_1 ) );

    ptr_cell->set_gift_callback(        
		std::tr1::bind( &city_level_up_dlg::on_gift_item_pressed, this, std::tr1::placeholders::_1 ) );
    
    bool draw_separator;
    
    if(0 == (idx+1) % city_dlg_layout::level_up_dlg::cell_count) 
      draw_separator = false;
    else  draw_separator = true;
    
    ptr_cell->layout_controls( m_window_ctx,  m_params.scene_info.level , draw_separator );
    
    fill_item_cell( ptr_cell, m_items[idx] );
    
    return ptr_cell;
}

// add buttons, captions and image to cell
bool city_level_up_dlg::fill_item_cell(
                                       sqc_shop_item_cell_ptr ptr_cell,
                                       const sqc_shop_category_item_ptr item )
{
    if ( !ptr_cell ) 
        return false;
    
    return true;
}

// user press buy item button
void city_level_up_dlg::on_buy_item_pressed( const sqc_string& object_type )
{
	if ( m_params.buy_callback ) {
    	bool res = m_params.buy_callback( object_type );
    	if ( res ) {
        	get_server().close_modals( 
                                      std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
        }
    }
}

// user press buy item button
void city_level_up_dlg::on_gift_item_pressed( const sqc_string& object_type )
{

}

sqc_int city_level_up_dlg::get_cell_count()
{
    return m_items.size();
}



END_NAMESPACE_SQC_FRAMEWORK