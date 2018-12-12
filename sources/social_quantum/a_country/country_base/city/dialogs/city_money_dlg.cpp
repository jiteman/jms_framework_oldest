/*
 *  city_add_money.cpp
 *  aCountry
 *
 *  Created by Василий on 27.07.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "city/city_framework.h"
#include "city_money_dlg.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK


city_buy_money_base_page::city_buy_money_base_page( sqc_dialog_ptr p, 
                                                 city_money_t dlg_kind,
                                                 const sqc_add_money_params &params )
	: sqc_dialog_page( p )
    , m_money(dlg_kind)
    , m_add_money_params(params)

{
}

void city_buy_money_base_page::on_init() {
    
   using namespace city_dlg_layout;

   sqc_window_factory& factory = framework().windows_factory();
	
    sqc_theme_size current_theme = factory.get_theme_size();
    
  	
	create_separator( shared_from_this(), money_dlg_layout::separator );
	create_separator( shared_from_this(), money_dlg_layout::separator_h1 );
	create_separator( shared_from_this(), money_dlg_layout::separator_h2 );
    
    const int Items = 6;
    
    sqc_add_money_enum bucks[Items] = { 
    	sqc_megabucks_5,
        sqc_megabucks_15,
        sqc_megabucks_40,
        sqc_megabucks_55,
        sqc_megabucks_80,
        sqc_megabucks_100
    };
    
    sqc_add_money_enum coins[Items] = {
        sqc_coins_12,
        sqc_coins_20,
        sqc_coins_30,
        sqc_coins_60,
        sqc_coins_100,
        sqc_coins_140
    };
    
    // arrangement money cells
    money_barter barter;
    for ( int i=0; i < Items; ++i ) {
		
        layout_point first_cell_offset = money_dlg_layout::first_cell_offset.at( current_theme );
        
        const int row = i < 3 ? i : i - (Items-3);
        const int col = i < 3 ? 0 : 1;

    	surf::surf_rect cell_rect( money_dlg_layout::cell_rects.at(current_theme) );
        
        cell_rect.x = first_cell_offset.x + col * cell_rect.cx;
        cell_rect.y = first_cell_offset.y + row * cell_rect.cy;
        
        // Create a cell for each item
        milk::milk_widget_ptr ptr_cell = 
			shared_from_this()->create_child<milk::milk_widget>( cell_rect );


		// set backround image 
        {
                milk::milk_button_ptr ptr_background_button = 
                	factory.create_button( m_window_ctx, ptr_cell, money_dlg_layout::item_background_button );
                    
                factory.create_image( m_window_ctx,
                                      ptr_background_button,
                                      m_money == city_coins ? 
                                      				money_dlg_layout::coins_image :
                                      				money_dlg_layout::bucks_image );
	    }            
        
        milk::milk_label_ptr ptr_alot = factory.create_label( m_window_ctx, ptr_cell, money_dlg_layout::alot_layout );
        
		// set caption
        sqc_string str_num = framework().formats().format_digit_grouping(
			barter.get_item( m_money == city_coins ? coins[i] : bucks[i] ).get_amount() );
		
        ptr_alot->set_caption( str_num );
        
        // set description
        {
	        milk::milk_label_ptr ptr_descr = factory.create_label( m_window_ctx, ptr_cell, money_dlg_layout::descr_layout );

            int amount = barter.get_item( m_money == city_coins ? coins[i] : bucks[i] ).get_amount();
            sqc_string str_money_name;
            	
            str_money_name = amount == 1 ? common_resources::string_message_megabucks.def_value()  :
                	amount < 5 ? common_resources::string_message_megabucks.def_value()  :
                    framework().strings().load("*CityMegabucksManyUppercase", "Megabucks");
			
            sqc_string str_for = framework().strings().load( "*CityCoinsFor", "for" );

			sqc_stringstream out;

			if ( m_money == city_coins ) {
				out << str_for << sqc_text( " " )
					<< barter.get_item( m_money == city_coins ? coins[i] : bucks[i] ).get_price()
					<< sqc_text( " " )
					<< str_money_name;
			}
			else {
				out << str_money_name << sqc_text( " " ) << str_for << sqc_text( " " )
				<< barter.get_item( m_money == city_coins ? coins[i] : bucks[i] ).get_price() << sqc_text( "$" );
			}

			ptr_descr->set_caption( out.str() );
		}

        milk::milk_button_ptr ptr_buy_button = factory.create_button( m_window_ctx, ptr_cell, money_dlg_layout::buy_button );
		factory.create_label( m_window_ctx, ptr_cell, money_dlg_layout::buy_caption );

     
// macros sketch
//#define SOFT_ASSERT(arg) { if ( !(arg) ) { sqc_assert(!"#arg"); sqc_error() << __FILE__ << ":" << __LINE__ << ": Not initialize " << #arg; } }	
// usage: SOFT_ASSERT(m_add_money_params.add_money_callback);

        if (!m_add_money_params.add_money_callback) {
        	sqc_assert(!"not intialize buy callback");
            sqc_error() << __FILE__ << ":" << __LINE__ << ": Not initialize m_add_money_params.add_money_callback";
        }
        else {
        	
            ptr_buy_button->set_action( 
                std::tr1::bind(
                	m_add_money_params.add_money_callback, 
                    m_money == city_coins ? coins[i] : bucks[i]
                ) );

        }
    }

   return;
}



void city_buy_money_base_page::on_buy_item_pressed(sqc_add_money_enum item)
{
	sqc_info() << "press " << item;
}

void city_buy_money_base_page::on_end()
{
}


/*****************************************************************************
//  money_sheet

using:
  money_dlg_ptr dlg = desktop()->create_child<money_dlg>(rect);
  dlg->switch_megabucks();
  dlg->switch_coins();
**/

money_dlg::money_dlg( milk::milk_widget_ptr p,  const sqc_add_money_params &params ) 
	: sqc_dialog( p, city_dlg_layout::money_dlg_layout::dlg_bg,dialog_has_close_button  )
    , m_modal(false)
    , m_params(params)
{ 
}

bool money_dlg::get_dialog_init_arg( milk::milk_dialog_init_arg &arg ) {
	arg.title_args.flags |= milk::milk_font_modify_size;
	arg.title_args.size = layout_vals(17,17*2,24).at( framework().windows_factory().get_theme_size() );
    
    sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
    sqc_word height[] = { 16, 32, 18 };
	arg.bevel_bottom = height[theme_size];
    
	return sqc_dialog::get_dialog_init_arg( arg );
}

void money_dlg::on_init_dialog() {
	sqc_dialog::on_init_dialog();
	m_bucks_page = add_tab<city_buy_bucks_page,const sqc_add_money_params &>(framework().strings().load( 
									   city_dlg_layout::money_dlg_layout::caption_layout_bucks.resource_id(), city_dlg_layout::money_dlg_layout::caption_layout_bucks.def_value() ),
																			 false,m_params);
	m_coins_page = add_tab<city_buy_coins_page,const sqc_add_money_params &>(framework().strings().load( 
									   city_dlg_layout::money_dlg_layout::caption_layout_coins.resource_id(), city_dlg_layout::money_dlg_layout::caption_layout_coins.def_value() ),
																			 false,m_params);
	
}

void money_dlg::switch_coins()
{
	if (!m_modal) {
    	do_modal();
    }
	activate_tab(m_coins_page);
}

void money_dlg::switch_megabucks()
{
	if (!m_modal) {
    	do_modal();
    }
	activate_tab(m_bucks_page);
}


void money_dlg::do_modal() {
	sqc_dialog::do_modal();
    m_modal = true;
}

END_NAMESPACE_SQC_FRAMEWORK
