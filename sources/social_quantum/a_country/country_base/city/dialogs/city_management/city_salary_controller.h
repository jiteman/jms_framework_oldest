/*
 *  city_salary_controller.h
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __CITY_SALARY_CONTROLLER_H_INCLUDED__
#define __CITY_SALARY_CONTROLLER_H_INCLUDED__

#include "city_salary_delegate.h"
#include "country_base/sqc_game_base.h"
#include "country_base/dialogs/select_person/sqc_select_person_controller.h"

NAMESPACE_SQC_FRAMEWORK

class city_salary_controller : public city_salary_delegate {
public:
	city_salary_controller();
    virtual ~city_salary_controller();
    
    virtual void	get_scene_info( sqc_common_scene_info& scene_info );
    
	virtual bool	buy( sqc_salary salary );
    virtual bool	gift( sqc_salary salary );
    
protected:
	bool			on_friend_selected( const sqc_string& friend_id, const sqc_salary salary );
    sqc_string		get_object_type( const sqc_salary salary );
protected:
	sqc_game_ptr 	get_game();
};

//
//  controller for salary friends
//
class city_gift_salary_controller : public sqc_select_person_controller {
public:
    typedef std::tr1::function<bool( const sqc_string& id )> select_person_callback;

	city_gift_salary_controller( select_person_callback cb );
public:
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
  
protected:
    select_person_callback		m_callback;
};

typedef std::tr1::shared_ptr<city_gift_salary_controller>	city_gift_salary_controller_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif //__CITY_SALARY_CONTROLLER_H_INCLUDED__