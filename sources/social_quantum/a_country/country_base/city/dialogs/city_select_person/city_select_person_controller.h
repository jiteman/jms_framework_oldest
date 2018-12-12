/*
 *  city_select_person_controller.h
 *  aCountry
 *
 *  Created by paul K on 9/19/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */
 
 
#ifndef CITY_SELECT_PERSON_CONTROLLER_H_INCLUDED
#define CITY_SELECT_PERSON_CONTROLLER_H_INCLUDED

#include "framework/sqc_framework_defs.h"
#include "country_base/dialogs/select_person/sqc_select_person_controller.h"

NAMESPACE_SQC_FRAMEWORK

//
//  controller for visit friends field
//
class city_visit_friend_field_controller : public sqc_select_person_controller {
public:
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
};


//
//  controller for invite friend
//
class city_invite_friend_controller : public sqc_select_person_controller {
public:
    typedef std::tr1::function<void()> invite_complete_callback;
    typedef std::tr1::function<void()> invite_error_callback;

public:
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
    
    virtual bool        can_invite_friend();
    virtual bool        invite_friend( const sqc_string& id,
                                       const sqc_string& msg,
                                       invite_complete_callback cb,
                                       invite_error_callback cb_err );
protected:
    // notification callback
    virtual void notify_callback( const sqc_provider_id& provider_id, 
                         const sqc_event_id& event_id);    
    
private:
    invite_complete_callback    m_complete_cb;
    invite_error_callback       m_error_cb;
    
};

//
//  controller for municipality officer
//
class city_municipality_officer_controller : public sqc_select_person_controller {
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
};


//
//  controller for fiscal agent
//
class city_fiscal_agent_controller : public sqc_select_person_controller {
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
};


END_NAMESPACE_SQC_FRAMEWORK

#endif /*CITY_SELECT_PERSON_CONTROLLER_H_INCLUDED*/