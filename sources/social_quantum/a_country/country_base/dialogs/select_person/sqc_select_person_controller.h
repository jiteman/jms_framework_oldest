/*
 *  city_select_person_controller.h
 *  aCountry
 *
 *  Created by paul K on 9/19/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */
 
 
#ifndef SQC_SELECT_PERSON_CONTROLLER_H_INCLUDED
#define SQC_SELECT_PERSON_CONTROLLER_H_INCLUDED

#include "framework/sqc_framework_defs.h"
#include "framework/notify_center/sqc_notify_center.h"
#include "country_base/sqc_country_base_ui.h"
#include "country_base/friends/sqc_friends.h"
#include "sqc_select_person_delegate.h"

NAMESPACE_SQC_FRAMEWORK


class sqc_select_person_controller
    : public sqc_noncopyable
    , public sqc_select_preson_delegate {
public:
	sqc_select_person_controller();
	virtual ~sqc_select_person_controller();

    virtual void    set_persons_ready_callback( persons_ready_callback cb );
    virtual void    get_persons( sqc_person_info_list_type& persons );
protected:
	void            on_query_friends_complete();

protected:
    // notification callback
    virtual void notify_callback( const sqc_provider_id& provider_id, 
                         const sqc_event_id& event_id);    
                          
private:
	sqc_listener_connection     m_notify_connection;
    persons_ready_callback      m_ready_callback;
};

//
//  controller for send_gift
//
class sqc_send_gift_to_friend_controller : public sqc_select_person_controller {
public:
	typedef std::tr1::function<bool( const sqc_string& id )> select_person_callback;
public:
    virtual bool        on_person_select( const sqc_string& id );
    virtual sqc_string  get_button_caption();
    
    void				set_select_person_callback( select_person_callback cb );
protected:
	select_person_callback	m_callback;
};

typedef std::tr1::shared_ptr<sqc_send_gift_to_friend_controller> sqc_send_gift_to_friend_controller_ptr;


//
//  controller for send_gift from shop
//
class sqc_send_shop_gift_to_friend_controller : public sqc_send_gift_to_friend_controller {
public:
};

typedef std::tr1::shared_ptr<sqc_send_shop_gift_to_friend_controller> sqc_send_shop_gift_to_friend_controller_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif /*SQC_SELECT_PERSON_CONTROLLER_H_INCLUDED*/