/*
 *  city_salary_delegate.h
 *  aCountry
 *
 *  Created by paul K on 10/24/11.
 *  Copyright 2011 FairPlay. All rights reserved.
 *
 */

#ifndef __CITY_SALARY_DELEGATE_H_INCLUDED__
#define __CITY_SALARY_DELEGATE_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "sqc_base.h"

NAMESPACE_SQC_FRAMEWORK

//--== SALARY DIALOG
enum sqc_salary { sqc_salary_count_30   = 30,   sqc_salary_count_100  = 100,
                  sqc_salary_count_250  = 250,  sqc_salary_count_500  = 500,
                  sqc_salary_count_1000 = 1000, sqc_salary_count_2500 = 2500};

class city_salary_delegate {

public:
	virtual void	get_scene_info( sqc_common_scene_info& scene_info ) = 0;
    
	virtual bool	buy( sqc_salary salary ) = 0;
    virtual bool	gift( sqc_salary salary ) = 0;
};

typedef std::tr1::shared_ptr<city_salary_delegate> city_salary_delegate_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif //__CITY_SALARY_DELEGATE_H_INCLUDED__
