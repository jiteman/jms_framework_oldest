/*
 *  city_daily_gift_controller.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 22.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#ifndef __SQC_CITY_DAILY_GIFT_CONTROLLER_H_INCLUDED__
#define __SQC_CITY_DAILY_GIFT_CONTROLLER_H_INCLUDED__

#include "city_base_dlg.h"
#include "sqc_xml.h"

NAMESPACE_SQC_FRAMEWORK


class daily_gift_controller_face
{
public:
    daily_gift_controller_face();
    virtual ~daily_gift_controller_face();
    
    //-- get
    virtual sqc_dword get_bonus()       = 0;
    virtual sqc_dword get_day_count()   = 0;
    virtual sqc_dword get_bucks_count() = 0;   
    //--
    
    //-- wall
    virtual bool need_wall_button() = 0;
    virtual void send_to_wall(const sqc_string message) = 0;
    //--
    
};

typedef std::tr1::shared_ptr<daily_gift_controller_face> daily_gift_controller_face_ptr;


class daily_gift_controller : public daily_gift_controller_face
{
public:
    //-- get
    sqc_dword get_bonus();
    sqc_dword get_day_count();
    sqc_dword get_bucks_count();
    //--
    
    //-- wall
    bool need_wall_button();
    void send_to_wall(const sqc_string message);
    //--
    
    void update();
    
    //-- Constructor
    daily_gift_controller(daily_dlg_param param );
    
protected:
    sqc_dword m_bonus;
    sqc_dword m_day;
    sqc_dword m_bucks;
};


END_NAMESPACE_SQC_FRAMEWORK


#endif // FILE_ALREADY_INCLUDED
