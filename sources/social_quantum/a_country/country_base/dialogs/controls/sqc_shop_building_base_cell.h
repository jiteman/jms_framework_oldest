/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_BUILDING_BASE_CELL_H_INCLUDED__
#define __SQC_SHOP_BUILDING_BASE_CELL_H_INCLUDED__

#include "../../shop/sqc_shop_defs.h"
#include "sqc_item_buttons.h"
#include "sqc_item_price_widget.h"
#include "sqc_item_property_widget.h"
#include "sqc_proxy_texture_widget.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_shop_building_base_cell implementation
//

typedef std::tr1::function<void(const sqc_string& object_type)> cell_buy_callback;
typedef std::tr1::function<void(const sqc_string& object_type)> cell_ask_callback;


class sqc_shop_building_base_cell
    : public milk::milk_widget {
public:
    sqc_shop_building_base_cell( milk::milk_widget_ptr p, sqc_string object_type);
    virtual ~sqc_shop_building_base_cell();
public:
    void set_callbacks( cell_buy_callback buy_callback,
                        cell_ask_callback ask_callback );  
    virtual void layout_controls( sqc_window_factory_ctx_ptr window_ctx, bool draw_separator = true);
protected:        
    virtual sqc_shop_building_base_item_ptr get_building_item() = 0;
    void    disable_transparent_layer();
protected:
    void	on_buy_pressed();
    void	on_ask_pressed();
protected:
    cell_buy_callback               m_buy_callback;
    cell_ask_callback               m_ask_callback;
        
protected:
    milk::milk_label_ptr            m_name_label;

    // hole cell
    milk::milk_widget_ptr           m_transparent_layer;
    // transparent backing
    milk::milk_widget_ptr	        m_transparent_backing_layer;
    // non transparent backing
    milk::milk_widget_ptr           m_non_transparent_backing_layer;
            
    sqc_item_property_widget_ptr    m_properties;
    sqc_item_price_widget_ptr       m_price_widget;
    sqc_item_button_buy_ptr         m_buy_button;
    sqc_item_button_ask_ptr         m_ask_button;
        
    sqc_string                      m_object_type;
        
    // error
    milk::milk_label_ptr            m_error_label;
        
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_BUILDING_BASE_CELL_H_INCLUDED__


