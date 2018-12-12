/*
 *  city_daily_gift_dlg.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 22.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_daily_gift_dlg.h"
#include "city/city_framework.h"
 
NAMESPACE_SQC_FRAMEWORK
 
void city_daily_gift_dlg::on_init_dialog()
{
    PROFILE_ENTRY( "city_daily_gift_dlg::on_init_dialog" );
         
    sqc_dialog_with_close::on_init_dialog();
         
    set_bevel_type( milk::milk_bevel_type_none );
    
    sqc_window_factory& factory = framework().windows_factory();
         
    const sqc_theme_size current_theme = factory.get_theme_size();
         
    using namespace city_dlg_layout::daily_gift_layout;
    
    if(m_control->need_wall_button())
    {
        
    }
    
    //-- create images
    factory.create_image( m_window_ctx, shared_from_this(), panel_img );
  	factory.create_image( m_window_ctx, shared_from_this(), suitcase_img );
    factory.create_image( m_window_ctx, shared_from_this(), days_img );
    //--
    
    //-- create lables
    
    milk::milk_label_ptr ptr_label_coins_count = 
    factory.create_label(
                         m_window_ctx, 
                         shared_from_this(),
                         label_coins_count
                         );	
    
    milk::milk_label_ptr ptr_label_bucks_count = 
    factory.create_label(
                         m_window_ctx, 
                         shared_from_this(),
                         label_bucks_count
                         );	                        
                                                                   
    ptr_label_coins_count->set_caption(
                              format(framework().strings().load(
                                                                string_coins_count.resource_id(),
                                                                string_coins_count.def_value()),
                                     m_control->get_bonus())
                                      );
                              
    ptr_label_bucks_count->set_caption(
                             format(framework().strings().load(
                                                               string_bucks_count.resource_id(),
                                                               string_bucks_count.def_value()),
                                     m_control->get_bucks_count())
                                      );
    
    factory.create_label( m_window_ctx, shared_from_this(), label_equal      );             
    factory.create_label( m_window_ctx, shared_from_this(), label_message    );             
    factory.create_label( m_window_ctx, shared_from_this(), label_day_gift   );
    factory.create_label( m_window_ctx, shared_from_this(), label_week_gift  );
    factory.create_label( m_window_ctx, shared_from_this(), label_coins_count);
    factory.create_label( m_window_ctx, shared_from_this(), label_bucks_count);
    factory.create_label( m_window_ctx, shared_from_this(), label_megabucks  );

    //-- create day checkers
    sqc_dword _x = 0;
    surf::surf_rect _rect(rect_days.at(current_theme));
    const sqc_dword _rect_x = _rect.x;
    const sqc_word  _days = m_control->get_day_count();
    
    for(sqc_word i = 0; i < _days; i++ )
    {                                
        _rect.x = _x + _rect_x;
        
        if(current_theme == sqc_theme_large)
        {
            _x += day_offset_x[2];
        }
        else if(current_theme == sqc_theme_normal)
        {
            _x += day_offset_x[1];
        }
        else
        {
            _x += day_offset_x[0];
        }
        
        // drawing
        milk::milk_widget_ptr ptr_cell = shared_from_this()->create_child<milk::milk_widget>( _rect );
        factory.create_image( m_window_ctx, ptr_cell, icon_check_img  );
        
    }// end: for(..)
    //--
}
 
END_NAMESPACE_SQC_FRAMEWORK 
