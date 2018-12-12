/*
 *  city_daily_gift_controller.cpp
 *  aCountry
 *
 *  Created by Ivan Konnov on 22.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *
 */

#include "city_daily_gift_controller.h"

NAMESPACE_SQC_FRAMEWORK

//-- daily_gift_controller_face
daily_gift_controller_face::daily_gift_controller_face()
{

}

daily_gift_controller_face::~daily_gift_controller_face()
{

}

//--


//-- Constructor
daily_gift_controller::daily_gift_controller(daily_dlg_param param )
    : m_bonus(param.bonus)
    , m_day(param.day)
    , m_bucks(param.bucks)
{
}


void daily_gift_controller::update()
{
  // update m_bonus, m_day, m_bucks
}


//-- get
sqc_dword daily_gift_controller::get_bonus()
{   
    return m_bonus;
}

sqc_dword daily_gift_controller::get_day_count()
{
    return m_day;
}

sqc_dword daily_gift_controller::get_bucks_count()
{
    return m_bucks;
}
//--

//-- wall
bool daily_gift_controller::need_wall_button()
{
    return false;
}
void daily_gift_controller::send_to_wall(const sqc_string message)
{

}
//--

END_NAMESPACE_SQC_FRAMEWORK
