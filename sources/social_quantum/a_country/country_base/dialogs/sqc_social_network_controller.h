/*
 *  sqc_social_network_controller.h
 *  aCountry
 *
 *  Created by paul K on 10/11/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __SQC_SQC_SOCIAL_NETWORK_CONTROLLER_H_INCLUDED__
#define __SQC_SQC_SOCIAL_NETWORK_CONTROLLER_H_INCLUDED__

#include "sqc_social_network_delegate.h"
#include "framework/notify_center/sqc_notify_center.h"

NAMESPACE_SQC_FRAMEWORK


class sqc_social_network_controller
    : public sqc_noncopyable
    , public sqc_social_network_delegate {
public:
    sqc_social_network_controller();
    virtual ~sqc_social_network_controller();

	// network properties
    virtual sqc_network_type current_network();
    virtual sqc_string get_network_image( sqc_network_type network );

	// store callbacks
    virtual void	set_success_login_callback( login_success_callback cb );
    // try to login to network
	virtual bool	change_network();


protected:
    // notification callback
    virtual void notify_callback( const sqc_provider_id& provider_id, 
                         const sqc_event_id& event_id);    
                          
private:
    sqc_listener_connection     m_notify_connection;
    login_success_callback 		m_login_success_callback;
};

END_NAMESPACE_SQC_FRAMEWORK

#endif /*__SQC_SQC_SOCIAL_NETWORK_CONTROLLER_H_INCLUDED__*/