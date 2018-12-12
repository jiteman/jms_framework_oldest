/*
 *  city_tax_admin_delegate.h
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __CITY_TAX_ADMIN_DELEGATE_H_INCLUDED__
#define __CITY_TAX_ADMIN_DELEGATE_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "sqc_base.h"

NAMESPACE_SQC_FRAMEWORK

class city_tax_admin_delegate {

public:
	virtual void	get_scene_info( sqc_common_scene_info& scene_info ) = 0;
	virtual bool	has_tax_admin() = 0;
    virtual bool	buy_tax_admin( const sqc_string& s ) = 0;
    
    virtual bool	set_tax_rate( const sqc_int tax_rate ) = 0;
    virtual sqc_int	get_tax_rate() = 0;
    
    virtual sqc_int	get_max_population() = 0;
};

typedef std::tr1::shared_ptr<city_tax_admin_delegate> city_tax_admin_delegate_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif //__CITY_TAX_ADMIN_DELEGATE_H_INCLUDED__
