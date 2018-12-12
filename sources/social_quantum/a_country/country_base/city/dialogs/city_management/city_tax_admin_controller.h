/*
 *  city_tax_admin_controller.h
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __CITY_TAX_ADMIN_CONTROLLER_H_INCLUDED__
#define __CITY_TAX_ADMIN_CONTROLLER_H_INCLUDED__

#include "city_tax_admin_delegate.h"
#include "country_base/sqc_game_base.h"

NAMESPACE_SQC_FRAMEWORK

class city_tax_admin_controller : public city_tax_admin_delegate {
public:
	city_tax_admin_controller();
    virtual ~city_tax_admin_controller();
    
    virtual void	get_scene_info( sqc_common_scene_info& scene_info );

	virtual bool	has_tax_admin();
    virtual bool	buy_tax_admin( const sqc_string& s );
    
    virtual bool	set_tax_rate( const sqc_int tax_rate );
    virtual sqc_int	get_tax_rate();
    
    virtual sqc_int	get_max_population();
    
protected:
	sqc_game_ptr 	get_game();
};

END_NAMESPACE_SQC_FRAMEWORK

#endif //__CITY_TAX_ADMIN_CONTROLLER_H_INCLUDED__
