/*
 *  city_bubble.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef _CITY_BUBBLE_H_INCLUDED_
#define _CITY_BUBBLE_H_INCLUDED_

#include "country_base/view/sqc_bubble.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_city_bubble	: public sqc_bubble {
public:
	sqc_city_bubble( milk::milk_widget_ptr parent);
private:
protected:
};

typedef std::tr1::shared_ptr<sqc_city_bubble>    sqc_city_bubble_ptr;

END_NAMESPACE_SQC_FRAMEWORK


#endif 
