/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_ITEM_CELL_H_INCLUDED__
#define __SQC_SHOP_ITEM_CELL_H_INCLUDED__

#include "country_base/shop/sqc_shop_defs.h"
#include "sqc_item_buttons.h"
#include "sqc_item_price_widget.h"
#include "sqc_item_property_widget.h"
#include "sqc_proxy_texture_widget.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_category_dlg implementation
//

typedef std::tr1::function<void(const sqc_string& object_type)>
                                                    cell_buy_callback;
typedef std::tr1::function<void(const sqc_string& object_type)>
                                                    cell_gift_callback;
typedef std::tr1::function<void(const sqc_string& object_type)>
                                                    cell_sell_callback;
typedef std::tr1::function<void(const sqc_string& object_type)>
                                                    cell_receive_callback;

class sqc_shop_item_cell
    : public milk::milk_widget {
public:
    sqc_shop_item_cell( milk::milk_widget_ptr p,
                       sqc_shop_category_item_ptr ptr_item,
                       sqc_shop_target shop_target );
    virtual ~sqc_shop_item_cell();
public:
    void set_buy_callback( cell_buy_callback cb );  
    void set_gift_callback( cell_buy_callback cb );  
    void set_sell_callback( cell_buy_callback cb );  
    void set_receive_callback( cell_buy_callback cb );  

    void layout_controls( sqc_window_factory_ctx_ptr window_ctx,
                          int current_level,
                          bool draw_separator );                      
                          
protected:
	enum action_position {
    	action_position_left,
        action_position_right,
        action_position_center,
    };
    
	sqc_item_button_ptr create_action_button(  
    							sqc_window_factory_ctx_ptr window_ctx,
    							milk::milk_widget_ptr parent,
    							const sqc_shop_action action, 
                                const bool disabled,
    							const action_position position );
                                
	bool	preprocess_action( const sqc_shop_action action );
                          
protected:
	void	on_buy_pressed();
    void	on_gift_pressed();
    void    on_received_pressed();
    void    on_sell_pressed();
protected:
    sqc_shop_category_item_ptr      m_ptr_shop_item;
    sqc_shop_target					m_shop_target;
    
    cell_buy_callback             	m_buy_callback;
    cell_gift_callback             	m_gift_callback;
    cell_sell_callback              m_sell_callback;
    cell_receive_callback           m_receive_callback;
    
    sqc_string						m_object_type;
        
protected:
    milk::milk_label_ptr            m_name_label;

    sqc_item_property_widget_ptr    m_properties;
    sqc_item_price_widget_ptr       m_price_widget;
    sqc_item_button_ptr             m_buy_button;
    sqc_item_button_ptr             m_gift_button;
    sqc_item_button_ptr             m_sell_button;
    sqc_item_button_ptr             m_received_button;
        
    // error
    milk::milk_label_ptr    		m_error_label;
};

typedef std::tr1::shared_ptr<sqc_shop_item_cell>	sqc_shop_item_cell_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_ITEM_CELL_H_INCLUDED__


