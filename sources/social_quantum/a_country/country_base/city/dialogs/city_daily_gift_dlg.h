/*
 *  city_daily_gift_dlg.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 20.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */
 
#ifndef __SQC_CITY_DAILY_GIFT_DLG_H_INCLUDED__
#define __SQC_CITY_DAILY_GIFT_DLG_H_INCLUDED__
 
#include "city_base_dlg.h"
#include "city_daily_gift_dlg_layout.h"
#include "city_daily_gift_controller.h"
 
NAMESPACE_SQC_FRAMEWORK
 
class city_daily_gift_dlg
        : public sqc_dialog_with_close 
{
    public:
        city_daily_gift_dlg( milk::milk_widget_ptr p,daily_gift_controller_face_ptr control)
        : sqc_dialog_with_close(p, city_dlg_layout::daily_gift_layout::background)
        , m_control(control)
        {}
         
        virtual void on_init_dialog();
         
         
    protected:
        //sqc_daily_gift_params          m_params;
        daily_gift_controller_face_ptr m_control;
};
 
typedef std::tr1::shared_ptr<city_daily_gift_dlg>     city_daily_gift_dlg_ptr;
 
END_NAMESPACE_SQC_FRAMEWORK
 
#endif 
