/*
 *  city_hall_delegate.h
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __CITY_HALL_DELEGATE_H_INCLUDED__
#define __CITY_HALL_DELEGATE_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "sqc_city_objects.h"

NAMESPACE_SQC_FRAMEWORK

struct city_hall_agent_info {
	city_hall_agent_info() 
    	: local_avatar( true ) {
    }
    sqc_string 	agent_id;
    sqc_string	name;
	sqc_string	avatar;
    bool		local_avatar;
    sqc_string	description;
    
    bool		is_hired() const {
    	if ( agent_id.empty() ) {
        	return false;
        }
        
        if ( sqc::city::none_agent_id == agent_id ) {
        	return false;
        }
        
    	return true;
    }
};



class city_hall_delegate {

public:
	typedef std::tr1::function<void()> refresh_callback;
    
    virtual void	set_refresh_callback( refresh_callback cb ) = 0;

	virtual void	get_scene_info( sqc_common_scene_info& scene_info ) = 0;

	virtual bool	has_city_hall() = 0;
    virtual bool	buy_city_hall( const sqc_string& s ) = 0;
    
    //
    //	fiscal agent
    //
    virtual bool	get_fiscal_agent( city_hall_agent_info& info ) = 0;
    virtual bool 	hire_fiscal_agent() = 0;
    virtual bool 	fire_fiscal_agent() = 0;

	//
    //	municipal oficer
    //    
    virtual bool	get_municipal_officer( city_hall_agent_info& info ) = 0;
    virtual bool 	hire_municipal_officer() = 0;
    virtual bool 	fire_municipal_officer() = 0;
    
    virtual bool 	refill_budget() = 0;
    
};

typedef std::tr1::shared_ptr<city_hall_delegate> city_hall_delegate_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif //__CITY_HALL_DELEGATE_H_INCLUDED__
