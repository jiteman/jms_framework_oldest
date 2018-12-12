/*
 *  city_update_message_dlg.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 24.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_update_message_dlg.h"
#include "city/city_framework.h"

NAMESPACE_SQC_FRAMEWORK

void city_update_message_dlg::on_init_dialog()
{
    sqc_dialog_with_close::on_init_dialog();
    
    sqc_window_factory& factory = framework().windows_factory();
    
    const sqc_theme_size theme = factory.get_theme_size();
    
    using namespace city_dlg_layout::city_update_message_layout;
	
	create_background( backgrounds );
    
    if(sqc_theme_large == theme)
    {
        factory.create_image( m_window_ctx, shared_from_this(), update_img );
        factory.create_label( m_window_ctx, shared_from_this(), label_title_ipad );
        
        milk::milk_label_ptr ptr_label_title = 
        factory.create_label(
                             m_window_ctx, 
                             shared_from_this(),
                             label_title
                             );	
                             
        ptr_label_title->set_color(surf::surf_color(0,0,0,1));
    }
    else
    {
        factory.create_label( m_window_ctx, shared_from_this(), label_title);
    }
                                   
    //create spinboard    
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                            shared_from_this(), 
                                            layout_spinboard, 
                                            this );
    
    m_spinboard->set_visible_count( m_control->get_visible_cell());
    
    if(theme == sqc_theme_large)
    {
        // create pager
        factory.create_spinboard_pager( m_window_ctx,
                                       shared_from_this(),
                                       m_spinboard,
                                       spinboard_pager );
    }
    
    save_item_in_prefs();
}

void city_update_message_dlg::save_item_in_prefs()
{
    sqc_shop_category_deque_items items = m_control->get_items();
 
    sqc_shop_category_deque_items::iterator it;   
    for(it = items.begin(); it != items.end(); it++)
    {
        framework().preferences().set_bool("update_message_showed", it->get()->name() , true);
    }
            
}


bool city_update_message_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {

    const sqc_theme_size theme = framework().windows_factory().get_theme_size();
    int pager_height[]  = { 0, 0, 16 };
	a.bevel_bottom = pager_height[theme];
    
	return sqc_dialog_with_close::get_dialog_init_arg(a);
}


    
milk::milk_widget_ptr city_update_message_dlg::create_cell( sqc_int idx, surf::surf_rect const &rect )
{
    PROFILE_ENTRY( "city_update_message_dlg::create_cell" );
    
    if ( idx >= m_control->get_items().size() || idx < 0 )
    {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    // add cell object to spinboard
    sqc_shop_item_cell_ptr ptr_cell = 
    m_spinboard->create_child<sqc_shop_item_cell>( rect, m_control->get_items()[idx], shop_target );
    
    if ( !ptr_cell ) 
    {
        return milk::milk_widget_ptr();
    }
    
    
    ptr_cell->set_buy_callback(
                                std::tr1::bind( &city_update_message_dlg::on_buy_pressed, this, m_control->get_items()[idx] ) );
    
    ptr_cell->set_gift_callback(
                                std::tr1::bind( &city_update_message_dlg::on_gift_pressed, this, m_control->get_items()[idx] ) );
    
    
    //-- draw separator
    bool draw_separator;
    
    if(0 == (idx+1) % m_control->get_visible_cell()) 
        draw_separator = false;
    else draw_separator = true;
    
    ptr_cell->layout_controls( m_window_ctx, m_control->get_level(), draw_separator );
    //--
    
    fill_item_cell( ptr_cell, m_control->get_items()[idx] );
    
    return ptr_cell;
}

sqc_int city_update_message_dlg::get_cell_count()
{
    return m_control->get_cell_count();
}

bool city_update_message_dlg::fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                    const sqc_shop_category_item_ptr item )
{
    if ( !ptr_cell ) 
        return false;
        
    return true;
}


void city_update_message_dlg::on_buy_pressed(sqc_shop_category_item_ptr item)
{
    m_control->buy_pressed(item);
    
    // close dialog
    get_server().close_modals( 
                    std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this()));
}

void city_update_message_dlg::on_gift_pressed(sqc_shop_category_item_ptr item)
{
    m_control->gift_pressed(item);
    
    // close dialog
    get_server().close_modals( 
                   std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this()));
}


END_NAMESPACE_SQC_FRAMEWORK