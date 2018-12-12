/*
 *  city_gift_wish_dlg.cpp
 *  aCountry
 *
 *  Created by Paul K on 11.10.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_gift_wish_dlg.h"
#include "city/city_framework.h"
 
NAMESPACE_SQC_FRAMEWORK


//
// Pages
//



city_abstract_page_dlg::city_abstract_page_dlg(sqc_dialog_ptr p,sqc_gift_delegate_ptr gift_delegate )
: sqc_dialog_page( p )
, m_gift_delegate(gift_delegate)
, m_cell_visible_count(3)
, m_dialog(p)
{

}

void city_abstract_page_dlg::on_init()
{
    PROFILE_ENTRY( "city_abstract_page_dlg::on_init_dialog" );
    
	sqc_window_factory& factory = framework().windows_factory();
    
    using namespace city_dlg_layout::gift_wish_layout;
    
    m_items.clear();
    m_gift_delegate->get_scene_info( m_scene_info );
        
    get_items();
    
    //create spinboard    
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           daily_request_spinboard_layout, 
                                           this );
    
	// create pager
	factory.create_spinboard_pager( m_window_ctx,
								   shared_from_this(),
								   m_spinboard,
								   daily_request_spinboard_pager );
    // set cell visible count
    m_cell_visible_count = ( ( sqc_theme_large == factory.get_theme_size() ) ? 5 : 3 );
    m_spinboard->set_visible_count( m_cell_visible_count );
}

bool city_abstract_page_dlg::fill_item_cell(
                                            sqc_shop_item_cell_ptr ptr_cell,
                                            const sqc_shop_category_item_ptr item )
{
    if ( !ptr_cell ) 
        return false;
    
    return true;
}


//
// Wish
//

city_wish_dlg::city_wish_dlg(sqc_dialog_ptr p,sqc_gift_delegate_ptr gift_delegate )
: city_abstract_page_dlg(p, gift_delegate)
{
    
}

void city_wish_dlg::get_items()
{
    m_gift_delegate->get_wishes_gifts( m_wishes_gifts );
    sqc_info() << "city_wish_dlg: received wishes gifts count: " << m_wishes_gifts.size();   
    
    sqc_shop_enum_params enum_params( m_scene_info.level, sqc_shop_category_all, wishes_target );
    city::city_framework().shop().enum_shop_category( enum_params, m_scene_info, m_items );
}

milk::milk_widget_ptr city_wish_dlg::create_cell( sqc_int idx, surf::surf_rect const &rect )
{
    PROFILE_ENTRY( "city_wish_dlg::create_cell" );
    
    
    if ( idx >= m_wishes_gifts.size() )
    {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    sqc_shop_category_item_ptr    ptr_shop_item = 
    m_gift_delegate->convert_wishes_gift( m_wishes_gifts[idx] );
    
    if(!ptr_shop_item)
    {
       	sqc_error() << "city_wish_dlg: unable to construct shop item";
	    //sqc_assert( false );
    	return milk::milk_widget_ptr();
    }
    
    sqc_shop_item_cell_ptr ptr_cell = 
        m_spinboard->create_child<sqc_shop_item_cell>( rect,
                                                      ptr_shop_item,
                                                      wishes_target) ;
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    
    ptr_cell->set_gift_callback(
                                std::tr1::bind( &city_wish_dlg::on_gift_button_pressed, this, m_wishes_gifts[idx] ) );
    
    //-- draw separator
    
    bool draw_separator = ( idx != m_wishes_gifts.size() - 1 );
    ptr_cell->layout_controls( m_window_ctx, m_scene_info.level, draw_separator );
    
    
    return ptr_cell;
}

sqc_int city_wish_dlg::get_cell_count()
{
    return m_wishes_gifts.size();
}
        
void city_wish_dlg::on_gift_button_pressed(sqc_wishes::sptr ptr)
{
    m_gift_delegate->send_gift( ptr );
}

//
// Received
// 

city_received_dlg::city_received_dlg(sqc_dialog_ptr p, sqc_gift_delegate_ptr gift_delegate)
: city_abstract_page_dlg(p, gift_delegate)
{
    
}

void city_received_dlg::get_items()
{
    m_gift_delegate->get_received_gifts( m_received_gifts );
    sqc_info() << "city_received_dlg: received gifts count: " << m_received_gifts.size();   
    
    sqc_shop_enum_params enum_params( m_scene_info.level, sqc_shop_category_all, received_gift_target );
    city::city_framework().shop().enum_shop_category( enum_params, m_scene_info, m_items );
}

sqc_int city_received_dlg::get_cell_count()
{
   return m_received_gifts.size();
}

milk::milk_widget_ptr city_received_dlg::create_cell( sqc_int idx, surf::surf_rect const &rect )
{
    PROFILE_ENTRY( "city_received_dlg::create_cell" );
    
    
    if ( idx >= m_received_gifts.size() )
    {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    sqc_shop_category_item_ptr    ptr_shop_item = 
                    m_gift_delegate->convert_received_gift( m_received_gifts[idx] );
                    
    if(!ptr_shop_item)
    {
       	sqc_error() << "city_received_dlg: unable to constuct shop item";
	    //sqc_assert( false );
    	return milk::milk_widget_ptr();
    }
    
    sqc_shop_item_cell_ptr ptr_cell = 
        m_spinboard->create_child<sqc_shop_item_cell>( rect,
                                                       ptr_shop_item,
                                                       received_gift_target) ;
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
         
     ptr_cell->set_receive_callback(
                std::tr1::bind( &city_received_dlg::on_received_button_pressed, this, m_received_gifts[idx] ) );
                
     ptr_cell->set_sell_callback(
                std::tr1::bind( &city_received_dlg::on_sell_button_pressed, this, m_received_gifts[idx] ) );
                
    //-- draw separator
    
    bool draw_separator = ( idx != m_received_gifts.size() - 1 );
        ptr_cell->layout_controls( m_window_ctx, m_scene_info.level, draw_separator );
    
    
    return ptr_cell;
}

void city_received_dlg::on_received_button_pressed(sqc_received_gift::sptr ptr)
{
    if (m_gift_delegate->receive_gift( ptr ))
    {
    	m_dialog->end_dialog();
    }
}

void city_received_dlg::on_sell_button_pressed(sqc_received_gift::sptr ptr)
{
     m_gift_delegate->sell_gift(  ptr );
}

//
// Available
//

city_available_dlg::city_available_dlg(sqc_dialog_ptr p, sqc_gift_delegate_ptr gift_delegate )
: city_abstract_page_dlg(p, gift_delegate)
{
    
}

void city_available_dlg::get_items()
{
    m_gift_delegate->get_available_gifts( m_available_gifts );
        sqc_info() << "city_available_dlg: received gifts count: " << m_available_gifts.size();   
    
    sqc_shop_enum_params enum_params( m_scene_info.level, sqc_shop_category_all, available_gift_target );
    city::city_framework().shop().enum_shop_category( enum_params, m_scene_info, m_items ); 
}

sqc_int city_available_dlg::get_cell_count()
{
    return m_available_gifts.size();
}

milk::milk_widget_ptr city_available_dlg::create_cell( sqc_int idx, surf::surf_rect const &rect )
{
    PROFILE_ENTRY( "city_available_dlg::create_cell" );
    
    
    if ( idx >= m_available_gifts.size() )
    {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    sqc_shop_category_item_ptr	ptr_shop_item =
    m_gift_delegate->convert_available_gift( m_available_gifts[idx] );
    
    if ( !ptr_shop_item )
    {
    	sqc_error() << "city_available_dlg: unable to constuct shop item";
	    sqc_assert( false );
    	return milk::milk_widget_ptr();
    }
    
    sqc_shop_item_cell_ptr ptr_cell = 
        m_spinboard->create_child<sqc_shop_item_cell>( rect,
                                                  ptr_shop_item, 
                                                  available_gift_target) ;
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    
    ptr_cell->set_gift_callback(
                                   std::tr1::bind( &city_available_dlg::on_gift_button_pressed, this, m_available_gifts[idx] ) );
    
    //-- draw separator
    
    bool draw_separator = ( idx != m_available_gifts.size() - 1 );
        ptr_cell->layout_controls( m_window_ctx, m_scene_info.level, draw_separator );
    
    
    return ptr_cell;
    
}

void city_available_dlg::on_gift_button_pressed(sqc_available_gift::sptr ptr )
{
    m_gift_delegate->send_gift(  ptr );
}

 
void city_gift_wish_dlg::on_init_dialog() {

    PROFILE_ENTRY( "city_gift_wish_dlg::on_init_dialog" );
    
    sqc_dialog_with_close::on_init_dialog();
	
	set_bevel_type( milk::milk_bevel_type_content_scroll );
    
    if ( !m_gift_delegate ) {
    	sqc_assert( false );
        return;
    }
    
    {
        using namespace city_dlg_layout::gift_wish_layout;
        
        sqc_string a_str = framework().strings().load(string_available_title.resource_id(),string_available_title.def_value());
        sqc_string r_str = framework().strings().load(string_received_title.resource_id(),string_received_title.def_value());
        sqc_string w_str = framework().strings().load(string_wish_title.resource_id(), string_wish_title.def_value());
        
        m_available_page = add_tab<city_available_dlg>(a_str, true, m_gift_delegate );                     
        m_received_page  = add_tab<city_received_dlg>( r_str, true, m_gift_delegate ); 
        m_wish_page      = add_tab<city_wish_dlg>( w_str, true, m_gift_delegate );
    }
                                              
}


//
//  Gift_wish dialog
//

void city_gift_wish_dlg::on_post_init_dialog() {
	sqc_dialog_with_close::on_post_init_dialog();

	activate_tab( 0 );
	set_tab_counter( 0, get_availabel_cell_count());
    set_tab_counter( 1, get_received_cell_count());
    set_tab_counter( 2, get_wish_cell_count());
}

sqc_word city_gift_wish_dlg::get_availabel_cell_count()
{
    sqc_available_gift::vector	available_gifts;
    m_gift_delegate->get_available_gifts( available_gifts );
    
    return available_gifts.size();
}

sqc_word city_gift_wish_dlg::get_received_cell_count()
{
    sqc_received_gift::vector	received_gifts;
    m_gift_delegate->get_received_gifts( received_gifts );
    
    return received_gifts.size();
}

sqc_word city_gift_wish_dlg::get_wish_cell_count()
{
    sqc_wishes::vector	wishes_gifts;
    m_gift_delegate->get_wishes_gifts( wishes_gifts );
    
    return wishes_gifts.size();
}

bool city_gift_wish_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
	sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
    sqc_word height[] = { 19, 38, 29 };
	a.bevel_bottom = height[theme_size];
    
	return sqc_dialog_with_close::get_dialog_init_arg(a);
}

END_NAMESPACE_SQC_FRAMEWORK 
