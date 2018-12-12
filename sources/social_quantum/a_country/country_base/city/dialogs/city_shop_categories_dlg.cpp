/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_shop_categories_dlg.h"
#include "city/city_framework.h"
#include "city_dialogs.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_categories_dlg implementation
//

// initialization 
void city_shop_categories_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_shop_categories_dlg::on_init_dialog" );
    
	sqc_dialog_with_close::on_init_dialog();
	
	
	using namespace city_dlg_layout::shop_categories_dlg;
	
	// create title
	{
		set_caption( framework().strings().load( 
														   dialog_title.resource_id(), dialog_title.def_value() ) );
	}
	
	create_separator( shared_from_this(), separator_h );
	create_separator( shared_from_this(), separator_v1 );
	create_separator( shared_from_this(), separator_v2 );
	create_separator( shared_from_this(), separator_v3 );
	
    milk::milk_button_ptr add_coins_button_ptr = 
    	framework().windows_factory().create_button( m_window_ctx, shared_from_this(), btn_add_coins );
	
	milk::milk_callback add_money_cb = std::tr1::bind( &city_shop_categories_dlg::on_add_money, this ); 
    add_coins_button_ptr->set_action(add_money_cb);
    
	framework().windows_factory().create_label( m_window_ctx, add_coins_button_ptr, add_coins_caption );
    

    struct table_t {
        const image_button_layout& btn;
        const label_layout& label;
        sqc_shop_category category;
    };
    
    table_t table[] = {
        { houses_button,        houses_caption,     sqc_shop_category_houses },
        { factories_button,     factories_caption,  sqc_shop_category_factories },
        { leisures_button,      leisures_caption,   sqc_shop_category_leisures },
        { terrains_button,      terrains_caption,   sqc_shop_category_terrains },
        { power_button,         power_caption,      sqc_shop_category_power },
        { roads_button,         roads_caption,      sqc_shop_category_roads },
        { materials_button,     materials_caption,  sqc_shop_category_materials },
        { expansions_button,    expans_caption,     sqc_shop_category_expand }
    };
    
    for ( size_t idx = 0; idx < sizeof(table) / sizeof(table[0]); ++idx ) {
        add_button_and_caption( table[idx].btn, table[idx].label, 
                               idx, table[idx].category );
    }
    
    milk::milk_button_ptr find_button_ptr = 
        framework().windows_factory().create_button( m_window_ctx, shared_from_this(), btn_find );
	
    find_button_ptr->set_action( 
                        std::tr1::bind( &city_shop_categories_dlg::on_find_money, this) );
    //find_button_ptr->set_action(city_shop_categories_dlg::on_find_money);
	
	
}

void city_shop_categories_dlg::on_find_money()
{
}

void city_shop_categories_dlg::add_button_and_caption(
	const image_button_layout& button,
	const label_layout& caption,
    const size_t idx,
	const sqc_shop_category category ) {
	
	sqc_window_factory& factory = framework().windows_factory();
    sqc_theme_size current_theme = factory.get_theme_size();
    
    using namespace city_dlg_layout::shop_categories_dlg;
    
    // determine cell rect
    surf::surf_rect rect_cell;
    rect_cell.cx = cell_rects.at( current_theme ).cx;
    rect_cell.cy = cell_rects.at( current_theme ).cy;
    
    layout_point    cell_center = first_cell_center.at( current_theme );
    layout_point    cell_offset = cells_offset.at( current_theme );
    
    layout_point    current_cell_center = layout_point(
                    cell_center.x + ( idx % 4 * cell_offset.x), 
                    cell_center.y + ( idx / 4 * cell_offset.y) );
    
    rect_cell.x = current_cell_center.x - rect_cell.cx / 2;
    rect_cell.y = background.sizes().at(current_theme).cy - 
        current_cell_center.y - rect_cell.cy / 2;
    
    // add cell object
    milk::milk_widget_ptr ptr_cell = 
    shared_from_this()->create_child<milk::milk_widget>( rect_cell );
	
	// add button to cell
    {
        milk::milk_image_button_ptr ptr_btn = 
        factory.create_button( m_window_ctx, ptr_cell, button );
        
        ptr_btn->set_action( 
        std::tr1::bind( &city_shop_categories_dlg::on_shop_button_pressed, this, category ) );
    }
	
	// and caption to cell
    {
        factory.create_label( m_window_ctx, ptr_cell, caption );
    }
}

// shop button is pressed
void city_shop_categories_dlg::on_shop_button_pressed( 
    const sqc_shop_category category ) {
    
    city_dialogs& dialogs = city::city_framework().dialogs();
    
    sqc_shop_category_params	category_params = m_params.category_params;
    category_params.shop_category = category;
    
	dialogs.show_shop_category_dialog( category_params );
    
}

void city_shop_categories_dlg::on_add_money()
{
	sqc_info() << "add money callback " << m_params.category_params.add_money.add_money_callback;
    city::city_framework().dialogs().show_bucks_dialog( shared_from_this(), m_params.category_params.add_money );
}

END_NAMESPACE_SQC_FRAMEWORK