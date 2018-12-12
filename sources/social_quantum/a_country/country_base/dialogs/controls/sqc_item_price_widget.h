/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_ITEM_PRICE_WIDGET_H_INCLUDED__
#define __SQC_ITEM_PRICE_WIDGET_H_INCLUDED__

#include "country_base/shop/sqc_shop_defs.h"
#include "framework/layout/sqc_layout_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_item_price_widget implementation
//
class sqc_item_price_widget
    : public milk::milk_widget {
enum price_in_t {
    price_in_coins,
    //price_in_bucks,
    price_in_megabucks
};
public:
    sqc_item_price_widget( milk::milk_widget_ptr p );
    virtual ~sqc_item_price_widget();
        
    void set_price_in_coins( sqc_window_factory_ctx_ptr window_ctx, int coins );
    //void set_price_in_bucks( sqc_window_factory_ctx_ptr window_ctx, int bucks );
    void set_price_in_megabucks( sqc_window_factory_ctx_ptr window_ctx, int megabucks );
        
protected:
    void    layout_controls( sqc_window_factory_ctx_ptr window_ctx, price_in_t price );
    void    set_label_int_value( milk::milk_label_ptr ptr_label, int value );
protected:
    milk::milk_label_ptr m_coins_label;
//    milk::milk_label_ptr m_bucks_label;
    milk::milk_label_ptr m_megabucks_label;
};

typedef std::tr1::shared_ptr<sqc_item_price_widget>	sqc_item_price_widget_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_ITEM_PRICE_WIDGET_H_INCLUDED__


