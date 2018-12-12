/*
 *  city_hall_controller.h
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __CITY_HALL_CONTROLLER_H_INCLUDED__
#define __CITY_HALL_CONTROLLER_H_INCLUDED__

#include "city_hall_delegate.h"
#include "country_base/sqc_game_base.h"
#include "sqc_city_objects.h"
#include "framework/notify_center/sqc_notify_center.h"
#include "country_base/dialogs/select_person/sqc_select_person_controller.h"

NAMESPACE_SQC_FRAMEWORK

enum city_hall_agent_type_t {
    city_hall_fiscal_agent,
    city_hall_municipal_officer,
};

class city_hall_controller : public city_hall_delegate {
    
public:
	city_hall_controller();
    virtual ~city_hall_controller();
    
    virtual void	set_refresh_callback( refresh_callback cb );
    
    virtual void	get_scene_info( sqc_common_scene_info& scene_info );
    
	virtual bool	has_city_hall();
    virtual bool	buy_city_hall( const sqc_string& s );
    
    //
    //	fiscal agent
    //
    virtual bool	get_fiscal_agent( city_hall_agent_info& info );
    virtual bool 	hire_fiscal_agent();
    virtual bool 	fire_fiscal_agent();

	//
    //	municipal oficer
    //    
    virtual bool	get_municipal_officer( city_hall_agent_info& info );
    virtual bool 	hire_municipal_officer();
    virtual bool 	fire_municipal_officer();


	virtual bool 	refill_budget();
    
    static bool		fill_agent_info( const sqc_string agent_id,
    								 const city_hall_agent_type_t type, 
                                     city_hall_agent_info& info );

protected:
	bool			on_fiscal_agent_selected( const sqc_string& agent_id );
    bool			on_municipal_officer_selected( const sqc_string& agent_id );
protected:
	sqc_game_ptr 					get_game();
    sqc::city::sqc_city_hall_ptr	get_city_hall();
    
    sqc_string			get_current_fiscal_agent_id();
    sqc_string			get_current_municipal_officer_id();
    
	bool				run_cmd( const sqc_string& fiscal_agent_id, 
    							 const sqc_string& municipal_oficer_id );
                                 
protected:
	// notification callback
    virtual void notify_callback( const sqc_provider_id& provider_id, 
                         const sqc_event_id& event_id);
private:
    refresh_callback			m_refresh_cb;
    sqc_listener_connection     m_notify_connection;
};

//
//  controller for cityhall agents
//
class city_hall_agents_controller : public sqc_select_person_controller {
public:
    typedef std::tr1::function<bool( const sqc_string& id )> select_person_callback;

	city_hall_agents_controller( city_hall_agent_type_t type, select_person_callback cb );
public:
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
  
    virtual void    	get_persons( sqc_person_info_list_type& persons );
protected:
    select_person_callback		m_callback;
    city_hall_agent_type_t		m_agent_type;
};

typedef std::tr1::shared_ptr<city_hall_agents_controller>	city_hall_agents_controller_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif //__CITY_HALL_CONTROLLER_H_INCLUDED__