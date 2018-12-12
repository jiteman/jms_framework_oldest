/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_ITEM_PROPERTY_WIDGET_H_INCLUDED__
#define __SQC_ITEM_PROPERTY_WIDGET_H_INCLUDED__

#include "country_base/shop/sqc_shop_defs.h"
#include "framework/layout/sqc_layout_defs.h"

NAMESPACE_SQC_FRAMEWORK

// see enum sqc_shop_item_show_flags in sqc_shop_defs.h
enum sqc_item_property_flags {
    sqc_show_power_property = (1 << 0),
    sqc_show_water_property = (1 << 1),
    sqc_show_population_property = (1 << 2),
    sqc_show_coins_property = (1 << 3),
    sqc_show_experience_property = (1 << 4),
    sqc_show_time_build_property = (1 << 5),
};

typedef unsigned int sqc_item_property_mask;

struct sqc_item_properties {
    sqc_item_properties() 
    : mask( 0 )
    , power( 0 ), water( 0 ), population( 0 )
    , coins( 0 ), experience( 0 ), build_time_sec( 0 ) {
    }
    sqc_item_property_mask  mask;
    int power;
    int water;
    int population;
    int coins;
    int experience;
    int build_time_sec;
};

//
// sqc_item_property_widget implementation
//
class sqc_item_property_widget
    : public milk::milk_widget {
public:
    sqc_item_property_widget( milk::milk_widget_ptr p );
    virtual ~sqc_item_property_widget();
public:
    void layout_controls( sqc_window_factory_ctx_ptr window_ctx, 
                         const sqc_item_properties& prop );
        
    // fill widget properties from shop item
    void fill_item_properties_from_shop_item( const sqc_shop_item_ptr shop_item,
                                             sqc_item_properties& prop );
        
protected:
    void    set_label_int_value( milk::milk_label_ptr ptr_label, int value );
protected:
    // first row
    milk::milk_label_ptr    m_power_change_label;
    milk::milk_label_ptr    m_water_change_label;
    milk::milk_label_ptr    m_population_change_label;
    milk::milk_label_ptr    m_coins_change_label;
        
    // second row
    milk::milk_label_ptr    m_experience_change_label;
    milk::milk_label_ptr    m_time_build_label;
};

typedef std::tr1::shared_ptr<sqc_item_property_widget>	sqc_item_property_widget_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_ITEM_PROPERTY_WIDGET_H_INCLUDED__


