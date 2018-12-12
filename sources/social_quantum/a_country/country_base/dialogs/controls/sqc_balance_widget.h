/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_SQC_BALANCE_WIDGET_H_INCLUDED__
#define __SQC_SQC_BALANCE_WIDGET_H_INCLUDED__

#include "../../../../common/framework/sqc_framework_defs.h"
#include "../../../../common/framework/layout/sqc_layout_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_balance_widget
//
class sqc_balance_widget
    : public milk::milk_widget {
public:
    sqc_balance_widget( milk::milk_widget_ptr p );
    virtual ~sqc_balance_widget();
public:
    void layout_controls( sqc_window_factory_ctx_ptr window_ctx );
public:
    void update_coins( int coins );
    void update_bucks( int bucks );
    
protected:
    milk::milk_label_ptr    m_coins_label;
    milk::milk_label_ptr    m_bucks_label;
};

typedef std::tr1::shared_ptr<sqc_balance_widget>	sqc_balance_widget_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SQC_BALANCE_WIDGET_H_INCLUDED__


