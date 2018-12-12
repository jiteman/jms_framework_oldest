/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_ITEM_BUTTONS_H_INCLUDED__
#define __SQC_ITEM_BUTTONS_H_INCLUDED__

#include "../../../../common/framework/layout/sqc_layout_defs.h"
#include "sqc_item_buttons_layout.h"


NAMESPACE_SQC_FRAMEWORK

//
// sqc_item_button_base implementation
//
class sqc_item_button_base
    : public milk::milk_widget {
public:
        sqc_item_button_base( milk::milk_widget_ptr p,
                             const sqc_theme_button_layout& button_layout,
                             const label_layout& label_layout );
    virtual ~sqc_item_button_base();
    
public:
    void layout_controls( sqc_window_factory_ctx_ptr window_ctx,
                         milk::milk_callback callback );
        
protected:
    const sqc_theme_button_layout& m_button_layout;
    const label_layout& m_label_layout;
};

typedef std::tr1::shared_ptr<sqc_item_button_base>	sqc_item_button_ptr;

//
// sqc_item_button_buy implementation
//
class sqc_item_button_buy
    : public sqc_item_button_base {
public:
    sqc_item_button_buy( milk::milk_widget_ptr p ) :
        sqc_item_button_base( p,
                        layout::item_buttons::buy_button,
                        layout::item_buttons::buy_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_buy>	sqc_item_button_buy_ptr;

class sqc_item_button_sell
: public sqc_item_button_base {
public:
    sqc_item_button_sell( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::sell_button,
                         layout::item_buttons::sell_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_sell>	sqc_item_button_sell_ptr;

//
// sqc_item_button_buy implementation
//
class sqc_item_button_buy_gray
: public sqc_item_button_base {
public:
    sqc_item_button_buy_gray( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::buy_gray_button,
                         layout::item_buttons::buy_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_buy>	sqc_item_button_buy_ptr;


class sqc_item_button_sell_gray
: public sqc_item_button_base {
public:
    sqc_item_button_sell_gray( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::sell_gray_button,
                         layout::item_buttons::sell_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_sell>	sqc_item_button_sell_ptr;

//
// sqc_item_button_gift implementation
//
class sqc_item_button_gift
: public sqc_item_button_base {
public:
    sqc_item_button_gift( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::gift_button,
                         layout::item_buttons::gift_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_gift>	sqc_item_button_gift_ptr;

//
// sqc_item_button_received implementation
//
class sqc_item_button_received
: public sqc_item_button_base {
public:
    sqc_item_button_received( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::received_button,
                         layout::item_buttons::received_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_received>	sqc_item_button_received_ptr;

//
// sqc_item_button_ask implementation
//
class sqc_item_button_ask
: public sqc_item_button_base {
public:
    sqc_item_button_ask( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::ask_button,
                         layout::item_buttons::ask_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_ask>	sqc_item_button_ask_ptr;

//
// sqc_item_button_apply implementation
//
class sqc_item_button_apply
: public sqc_item_button_base {
public:
    sqc_item_button_apply( milk::milk_widget_ptr p ) :
    sqc_item_button_base( p,
                         layout::item_buttons::apply_button,
                         layout::item_buttons::apply_button_label ){}
};

typedef std::tr1::shared_ptr<sqc_item_button_apply>	sqc_item_button_apply_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_ITEM_BUTTONS_H_INCLUDED__


