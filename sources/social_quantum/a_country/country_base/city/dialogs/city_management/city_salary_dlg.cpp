/*
 *  city_salary_dlg.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 02.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_salary_dlg.h"
#include "city/dialogs/city_money_dlg.h"
#include "city_salary_dlg_layout.h"
#include "city/city_framework.h"

NAMESPACE_SQC_FRAMEWORK

enum e_money { e_coins, e_bucks }; // money types
enum e_count {eCount_30  = 30,  eCount_100  = 100,  eCount_250  = 250,
    eCount_500 = 500, eCount_1000 = 1000, eCount_2500 = 2500}; // 

enum e_cost  {eCost_1 = 1, eCost_3  = 3,  eCost_5  = 5,
    eCost_7 = 7, eCost_10 = 10, eCost_15 = 15}; //

struct cost_count
{
    e_count count;
    e_cost  cost;
    cost_count(e_count ecnt,e_cost e_cst)     
    :count(ecnt),
    cost(e_cst)
    {}
};


void city_salary_base_dlg::on_init_dialog() 
{
    PROFILE_ENTRY( "city_salary_dlg::on_init_dialog" );

    sqc_dialog_with_close::on_init_dialog();
    
    sqc_window_factory& factory = framework().windows_factory();
    
    sqc_theme_size current_theme = factory.get_theme_size();
    
    using namespace city_dlg_layout::salary_dlg;
    // create title
    
	{
		set_caption( framework().strings().load( title.resource_id(), title.def_value() ) );
	}
	
	// create bevel
	create_separator(  shared_from_this(),separator_v1 );
	create_separator(  shared_from_this(),separator_v2 );
	create_separator(  shared_from_this(),separator_h );
	
    //Main label
    factory.create_label( m_window_ctx, shared_from_this(), text_label);
    
    
    
    //add coins button
    milk::milk_button_ptr ptr_add_button = factory.create_button( m_window_ctx, shared_from_this(), add_button );
    
    factory.create_label( m_window_ctx, shared_from_this(), add_caption );
    {
      milk::milk_callback cb_add = std::tr1::bind(&city_salary_base_dlg::add_button_click, this);
      ptr_add_button->set_action( cb_add );
    }
    
    //create button =BUY=
    surf::surf_rect cell_rect( cell_rects.at(current_theme));
        
    
        
    // Cell like table
    
    struct table_t
    {
        sqc_salary salary;
        sqc_word   cost;
    };
    
    table_t table[] = { {sqc_salary_count_30,  salary_cost[0]},    {sqc_salary_count_100, salary_cost[1]}
                       ,{sqc_salary_count_250, salary_cost[2]},    {sqc_salary_count_500, salary_cost[3]} 
                       ,{sqc_salary_count_1000,salary_cost[4]},    {sqc_salary_count_2500,salary_cost[5]} };

    sqc_dword _x = 0;
    for(sqc_word i_cell = 0; i_cell < sizeof(table)/sizeof(table[0]); i_cell++)
    {
        
        if(sqc_theme_small == current_theme)
        {
            cell_rect.x = _x + cell_rect_x[0] ;
            _x += offset_x[0];
        }
        else if (sqc_theme_normal == current_theme)
        {
            cell_rect.x = _x + cell_rect_x[1];
            _x += offset_x[1]; 
        }
        else if(sqc_theme_large == current_theme)
        {
           cell_rect.x = _x + cell_rect_x[2] ;
           _x += offset_x[2]; 
        }
      
        
    
      // Create a cell for each item
      milk::milk_widget_ptr ptr_cell = shared_from_this()->create_child<milk::milk_widget>( cell_rect );
                          
      //-- create buttons                      
      milk::milk_button_ptr ptr_buy_button  = factory.create_button( m_window_ctx, ptr_cell, buy_button );
      milk::milk_button_ptr ptr_gift_button = factory.create_button( m_window_ctx, ptr_cell, gift_button );

      //callback binding
        {
            milk::milk_callback cb_b = std::tr1::bind(&city_salary_base_dlg::on_buy, this, table[i_cell].salary);
            ptr_buy_button->set_action( cb_b );     
           

            milk::milk_callback cb_g = std::tr1::bind(&city_salary_base_dlg::on_gift, this, table[i_cell].salary);
            ptr_gift_button->set_action( cb_g ); 
        }
      
      milk::milk_label_ptr ptr_label_count = 
      factory.create_label(
                           m_window_ctx, 
                           ptr_cell,
                           label_count
                           );	  
                             
      milk::milk_label_ptr ptr_label_cost = 
      factory.create_label(
                           m_window_ctx, 
                           ptr_cell,
                           label_cost
                           );	  
                             
      sqc_string str_count = format("%d", table[i_cell].salary );
      ptr_label_count->set_caption( str_count );
        
      str_count = format("%d", table[i_cell].cost );
      ptr_label_cost->set_caption( str_count );
      
      //-- create captions
      factory.create_label( m_window_ctx, ptr_cell, buy_caption );
      factory.create_label( m_window_ctx, ptr_cell, gift_caption );
      
      //-- enveloupe and biks images
      factory.create_image( m_window_ctx, ptr_cell, salary_envelope_image );
      factory.create_image( m_window_ctx, ptr_cell, salary_buks_image );
       
       
      if(2 == i_cell)
      {
        if(sqc_theme_large == current_theme)
            cell_rect.y -= offset_y[2];
        else if (sqc_theme_normal == current_theme)
            cell_rect.y -= offset_y[1];
        else
            cell_rect.y -= offset_y[0];
        
        _x = 0;
      }
       
    }//END: for(...)
    
}// END: city_salary_dlg::on_init()

void city_salary_base_dlg::on_buy( sqc_salary salary ) {
	sqc_assert( m_delegate );
    if ( m_delegate ) {
    	if ( m_delegate->buy( salary ) ) {
	        end_dialog();
        }
    }
}

void city_salary_base_dlg::on_gift( sqc_salary salary ) {
	sqc_assert( m_delegate );
    if ( m_delegate ) {
    	m_delegate->gift( salary );
    }
}

void city_salary_base_dlg::add_button_click()
{
	surf::surf_rect rect;
    sqc_add_money_params params; // TODO: take parameters!
	money_dlg_ptr dlg = framework().windows().get_desktop()->create_child<money_dlg>(rect, params);
	dlg->switch_megabucks();
}


END_NAMESPACE_SQC_FRAMEWORK

