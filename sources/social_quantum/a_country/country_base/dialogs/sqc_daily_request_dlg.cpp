/*
 *  sqc_daily_request_dlg.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 28.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "sqc_daily_request_dlg.h"

NAMESPACE_SQC_FRAMEWORK
    
void sqc_daily_request_dlg::on_init_dialog()
{

    PROFILE_ENTRY( "sqc_daily_request_dlg::on_init_dialog" );
    
    sqc_dialog_with_close::on_init_dialog();
	set_bevel_type(milk::milk_bevel_type_content_scroll);
    
    sqc_window_factory& factory = framework().windows_factory();
    
    //create spinboard    
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           daily_request_layout::daily_request_spinboard_layout, 
                                           this );
     
    m_spinboard->set_visible_count( m_control->get_visible_cell());
    
	add_tab<sqc_dialog_page>(framework().strings().load(
															   common_resources::string_title_message.resource_id(),
															   common_resources::string_title_message.def_value()), true);
}

void sqc_daily_request_dlg::on_post_init_dialog() {
	sqc_dialog_with_close::on_post_init_dialog();
	activate_tab(0);
	set_tab_counter(0,m_control->get_message_count());
}



milk::milk_widget_ptr sqc_daily_request_dlg::create_cell( sqc_int idx, surf::surf_rect const &rect )
{
    PROFILE_ENTRY( "sqc_daily_request_::create_cell" );
    
    if ( idx >= m_control->get_shop_category_items().size() || idx < 0 )
    {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    // add cell object to spinboard
    sqc_shop_item_cell_ptr ptr_cell = 
    m_spinboard->create_child<sqc_shop_item_cell>( rect, m_control->get_shop_category_items()[idx], received_gift_target );
    
    if ( !ptr_cell ) 
    {
        return milk::milk_widget_ptr();
    }
    
    
    ptr_cell->set_sell_callback(
		std::tr1::bind( &sqc_daily_request_dlg::on_sell_pressed, this, std::tr1::placeholders::_1 ) );

    ptr_cell->set_receive_callback(
		std::tr1::bind( &sqc_daily_request_dlg::on_received_pressed, this, std::tr1::placeholders::_1 ) );
    
    
    //-- draw separator
    bool draw_separator;
    
    if(0 == (idx+1) % m_control->get_visible_cell()) 
        draw_separator = false;
    else draw_separator = true;
    
    ptr_cell->layout_controls( m_window_ctx, m_control->get_level(), draw_separator );
    //--
    
    fill_item_cell( ptr_cell, m_control->get_shop_category_items()[idx] );
    
    return ptr_cell;
    
}

sqc_int sqc_daily_request_dlg::get_cell_count()
{
       return m_control->get_cell_count();
}
    
bool sqc_daily_request_dlg::fill_item_cell( sqc_shop_item_cell_ptr ptr_cell,
                        const sqc_shop_category_item_ptr item )
{
    if ( !ptr_cell ) 
        return false;

    return true;
}
    
void sqc_daily_request_dlg::on_sell_pressed( const sqc_string& object_type )
{
	processor::sqc_command_processor p = country_framework().cmd_processor();
    processor::sqc_sell_gift_command *psell_gift_command = new processor::sqc_sell_gift_command( "foo", 1 );
    processor::sqc_command_ptr sp_sell_gift(psell_gift_command);
	p.schedule( sp_sell_gift );
}

void sqc_daily_request_dlg::on_received_pressed( const sqc_string& object_type )
{
}
 

END_NAMESPACE_SQC_FRAMEWORK