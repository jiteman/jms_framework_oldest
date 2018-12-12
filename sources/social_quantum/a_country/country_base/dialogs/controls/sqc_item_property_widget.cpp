/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_item_property_widget.h"
#include "sqc_item_property_widget_layout.h"
#include "../../../../common/framework/sqc_framework.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_item_property_widget
//

sqc_item_property_widget::sqc_item_property_widget(
    milk::milk_widget_ptr p )
    : milk::milk_widget( p ) {
}

sqc_item_property_widget::~sqc_item_property_widget() {
}

void sqc_item_property_widget::layout_controls( 
    sqc_window_factory_ctx_ptr window_ctx,
    const sqc_item_properties& prop ) {

    sqc_window_factory& factory = framework().windows_factory();

    using namespace layout::item_property_widget;

    // power
    if ( sqc_show_power_property & prop.mask ) {
        factory.create_image( window_ctx, shared_from_this(), cell_power_change_image );
        
        m_power_change_label =
        factory.create_label( window_ctx, shared_from_this(), cell_power_change_label );
        
        set_label_int_value( m_power_change_label, prop.power );
    }

    // water change
    if ( sqc_show_water_property & prop.mask ) {
        milk::milk_image_ptr ptr_water_change_image =
        factory.create_image( window_ctx, shared_from_this(), cell_water_change_image );
        
        m_water_change_label =
        factory.create_label( window_ctx, shared_from_this(), cell_water_change_label );

        // change rect to power (move from 1-st to 0 row )
        if ( !(sqc_show_power_property & prop.mask ) ) {
            factory.layout_widget( shared_from_this(),
                                  ptr_water_change_image,
                                  power_change_image_alignment,
                                  power_change_image_rect );
            
            factory.layout_widget( shared_from_this(),
                                  m_water_change_label,
                                  power_change_label_alignment,
                                  power_change_label_rect );
        }
        
        set_label_int_value( m_water_change_label, prop.water );
    }

    // population change
    if ( sqc_show_population_property & prop.mask ) {
        
        milk::milk_image_ptr ptr_population_change_image =
        factory.create_image( window_ctx, shared_from_this(), cell_population_change_image );
        
        m_population_change_label =
        factory.create_label( window_ctx, shared_from_this(), cell_population_change_label );
        
        // change rect to coins_change (move from 2-nd to 3-d row )
        if ( !(sqc_show_coins_property & prop.mask ) ) {
            factory.layout_widget( shared_from_this(),
                          ptr_population_change_image,
                          coins_change_image_alignment,
                          coins_change_image_rect );
            
            factory.layout_widget( shared_from_this(),
                          m_population_change_label,
                          coins_change_label_alignment,
                          coins_change_label_rect );
        }
        
        set_label_int_value( m_population_change_label, prop.population );
    }

    // coins change
    if ( sqc_show_coins_property & prop.mask ) {
        factory.create_image( window_ctx, shared_from_this(), cell_coins_change_image );

        m_coins_change_label = 
        factory.create_label( window_ctx, shared_from_this(), cell_coins_change_label );
        
        set_label_int_value( m_coins_change_label, prop.coins );
    }

    // experience change
    if ( sqc_show_experience_property & prop.mask ) {
        factory.create_image( window_ctx, shared_from_this(), cell_experience_change_image );

        m_experience_change_label = 
        factory.create_label( window_ctx, shared_from_this(), cell_experience_change_label );
        
        set_label_int_value( m_experience_change_label, prop.experience );
    }

    // time build
    if ( sqc_show_time_build_property & prop.mask ) {
        factory.create_image( window_ctx, shared_from_this(), cell_time_build_image );

        m_time_build_label = 
        factory.create_label( window_ctx, shared_from_this(), cell_time_build_label );
        
        //m_time_build_label->set_caption( framework().formats().format_time( prop.build_time_sec ) );
        m_time_build_label->set_caption( framework().formats().format_time_colon( prop.build_time_sec / 1000) );
    }        
}

void sqc_item_property_widget::set_label_int_value(
    milk::milk_label_ptr ptr_label,
    int value ) {
    if ( !ptr_label ) {
        return;
    }
    sqc_string str_value = framework().formats().format_digit_grouping( value );
    ptr_label->set_caption( str_value );
}


// fill widget properties from shop item
void sqc_item_property_widget::fill_item_properties_from_shop_item( 
    const sqc_shop_item_ptr ptr_shop_item,
    sqc_item_properties& prop ) {
    
    if ( !ptr_shop_item ) {
        sqc_assert( false );
        return;
    }
    
    sqc_shop_item_show_mask show_mask = ptr_shop_item->show_mask();
    
    // power
    if ( sqc_shop_item_show_power_change & show_mask ) {
        prop.mask |= sqc_show_power_property;
        prop.power = ptr_shop_item->power_change();
    }
    
    // water change
    if ( sqc_shop_item_show_water_change & show_mask ) {
        prop.mask |= sqc_show_water_property;
        prop.water = ptr_shop_item->water_change();
    }
    
    // population change
    if ( sqc_shop_item_show_population_change & show_mask ) {
        prop.mask |= sqc_show_population_property;
        prop.population = ptr_shop_item->population_change();
    }
    
    // coins change
    if ( sqc_shop_item_show_coins_change & show_mask ) {
        prop.mask |= sqc_show_coins_property;
        prop.coins = ptr_shop_item->coins_change();
    }
    
    // experience change
    if ( sqc_shop_item_show_experience_change & show_mask ) {
        prop.mask |= sqc_show_experience_property;
        prop.experience = ptr_shop_item->experience_change();
    }
    
    // time build
    if ( sqc_shop_item_show_time_build & show_mask ) {
        prop.mask |= sqc_show_time_build_property;
        prop.build_time_sec = ptr_shop_item->build_time_sec();
    }
}


END_NAMESPACE_SQC_FRAMEWORK