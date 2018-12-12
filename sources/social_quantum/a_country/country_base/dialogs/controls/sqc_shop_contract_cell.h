/*
 *  city_shop_contract_cell.h
 *  aCountry
 *
 *  Created by Maxim Korolkov on 06.09.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#ifndef __SQC_SHOP_CONTRACT_CELL_H_INCLUDED__
#define __SQC_SHOP_CONTRACT_CELL_H_INCLUDED__

#include "country_base/shop/sqc_shop_defs.h"
#include "sqc_item_buttons.h"
#include "sqc_item_price_widget.h"
#include "sqc_item_property_widget.h"
#include "sqc_proxy_texture_widget.h"

NAMESPACE_SQC_FRAMEWORK

//
// city_shop_contract_cell implementation
//

typedef std::tr1::function<void(const sqc_string& object_type)>
                                                    cell_buy_callback;

class sqc_shop_contract_cell
    : public milk::milk_widget {
public:
    sqc_shop_contract_cell( milk::milk_widget_ptr p,
                       sqc_shop_contract_item_ptr ptr_contract );
    virtual ~sqc_shop_contract_cell();
public:
    void set_callbacks( cell_buy_callback buy_callback );  
    void layout_controls( sqc_window_factory_ctx_ptr window_ctx, 
                          int current_level,
                          bool draw_separator );
                          
protected:
	void	on_buy_pressed();
protected:
    sqc_shop_contract_item_ptr      m_ptr_contract;
    cell_buy_callback             	m_buy_callback;
    
    sqc_string						m_object_type;
        
protected:
    milk::milk_label_ptr            m_name_label;

    sqc_item_property_widget_ptr    m_properties;
    sqc_item_price_widget_ptr       m_price_widget;
    sqc_item_button_ptr             m_buy_button;
        
    // error
    milk::milk_label_ptr    		m_error_label;
};

typedef std::tr1::shared_ptr<sqc_shop_contract_cell>	sqc_shop_contract_cell_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SHOP_CONTRACT_CELL_H_INCLUDED__


