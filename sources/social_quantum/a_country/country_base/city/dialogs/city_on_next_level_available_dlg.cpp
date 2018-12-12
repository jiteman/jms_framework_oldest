/*
 *  city_on_next_level_available.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 12.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */
 
#include "city/city_framework.h"
#include "city_on_next_level_available_dlg.h"
#include "city_on_next_level_available_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

void city_on_next_level_dlg::on_init_dialog()
{
  PROFILE_ENTRY( "city_on_next_level_dlg::on_init_dialog" );
  
  sqc_dialog_with_back_and_close::on_init_dialog();
  draw_arg.type = milk::milk_dialog_type( city_dialog_type_congratulation );
  set_bevel_type( milk::milk_bevel_type_content_scroll );
  
  sqc_window_factory& factory = framework().windows_factory();
  
  using namespace city_dlg_layout::next_level_available;

  factory.create_label( m_window_ctx, shared_from_this(), label);
   
  m_items.clear();

  m_params.scene_info.level += 1; //next level
    
  sqc_shop_enum_params enum_params( m_params.scene_info.level, m_params.shop_category, view_only_target );
  city::city_framework().shop().enum_shop_category( enum_params, m_params.scene_info, m_items );
                                                         
  //create spinboard    
  m_spinboard = factory.create_spinboard( m_window_ctx, 
                                          shared_from_this(), 
                                          on_next_level_spinboard_layout, 
                                          this );
	// create pager
	factory.create_spinboard_pager( m_window_ctx,
								   shared_from_this(),
								   m_spinboard,
								   on_next_level_spinboard_pager );
	
  m_spinboard->set_visible_count( city_dlg_layout::next_level_available::cell_count );
    
}

bool city_on_next_level_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
    
    sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
    sqc_word height[] = { 19, 38, 18 };
	sqc_word top[] = { 40, 40*2, 0 };
	a.bevel_bottom = height[theme_size];
	a.bevel_top = top[theme_size];
    
	return sqc_dialog_with_back_and_close::get_dialog_init_arg(a);
}


milk::milk_widget_ptr city_on_next_level_dlg::create_cell(sqc_int idx, surf::surf_rect const &rect)
{
    PROFILE_ENTRY( "on_next_level_dlg::create_cell" );
    
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
    bool draw_separator;
    
    if(0 == (idx+1) % city_dlg_layout::next_level_available::cell_count) 
        draw_separator = false;
    else draw_separator = true;
    
    ptr_cell->layout_controls( m_window_ctx, m_params.scene_info.level, draw_separator );
    
    fill_item_cell( ptr_cell, m_items[idx] );
    
    return ptr_cell;
    
}

sqc_int city_on_next_level_dlg::get_cell_count()
{
       return m_items.size();
}


bool city_on_next_level_dlg::fill_item_cell(
                                       sqc_shop_item_cell_ptr ptr_cell,
                                       const sqc_shop_category_item_ptr item )
{
    if ( !ptr_cell ) 
        return false;
    
    return true;
}
             
                    
END_NAMESPACE_SQC_FRAMEWORK


