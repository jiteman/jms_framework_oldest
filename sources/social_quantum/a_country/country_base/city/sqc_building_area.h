//
//  sqc_building_area.h
//  aCountry
//
//  Created by Maxim Korolkov on 26.09.11.
//  Copyright 2011 SocialQuantum. All rights reserved.
//

#ifndef SQC_BUILDING_AREA_H
#define SQC_BUILDING_AREA_H

#include "framework/sqc_framework_defs.h"
#include "sqc_city.h"

NAMESPACE_SQC_CITY

class sqc_building_area {
public:
    sqc_building_area();
    void draw( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv );
    bool is_allow_build(sqc_rect rect);
protected:
    const bool *get_allowing_mapping();
protected:
    sqc_rect bounds;
};

typedef std::tr1::shared_ptr<sqc_building_area> sqc_building_area_ptr;

END_NAMESPACE_SQC_CITY

#endif // SQC_BUILDING_AREA_H
