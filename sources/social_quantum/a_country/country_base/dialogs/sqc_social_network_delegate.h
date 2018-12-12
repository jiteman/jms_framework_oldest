/*
 *  sqc_social_network_delegate.h
 *  aCountry
 *
 *  Created by paul K on 10/11/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __SQC_SQC_SOCIAL_NETWORK_DELEGATE_H_INCLUDED__
#define __SQC_SQC_SOCIAL_NETWORK_DELEGATE_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "framework/social_network/sqc_social_network_defs.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_social_network_delegate {
public:
    typedef std::tr1::function<void()> login_success_callback;

public:
	// network properties
    virtual sqc_network_type current_network() = 0;
    virtual sqc_string get_network_image( sqc_network_type network ) = 0;

	// store callbacks
    virtual void	set_success_login_callback( login_success_callback cb ) = 0;
    // try to login to network
	virtual bool	change_network() = 0;
};

typedef std::tr1::shared_ptr<sqc_social_network_delegate> sqc_social_network_delegate_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_SQC_SOCIAL_NETWORK_DELEGATE_H_INCLUDED__