//
//  sqc_building_area.cpp
//  aCountry
//
//  Created by Maxim Korolkov on 26.09.11.
//  Copyright 2011 SocialQuantum. All rights reserved.
//

#include "sqc_building_area.h"

NAMESPACE_SQC_CITY

#define BUILDING_AREA_LEFT_BOUND -17
#define BUILDING_AREA_BOTTOM_BOUND 29
#define BIUILDING_AREA_MAX_CX 87
#define BIUILDING_AREA_MAX_CY 41

#define YES true
#define NO false

sqc_building_area::sqc_building_area():
  bounds(BUILDING_AREA_LEFT_BOUND, BUILDING_AREA_BOTTOM_BOUND,
                                              BIUILDING_AREA_MAX_CX, BIUILDING_AREA_MAX_CY) {
}

const bool *sqc_building_area::get_allowing_mapping() {
    static const bool allow_map[] = {
        
        
        // Левый угол ромба карты                            вниз-->>                                                                                                                               Нижний угол ромба карты                             |-> начало  старого города
        /*      0    1    2    3    4    5    6    7    8    9   10    1    2    3    4    5    6    7    8    9   20   1     2    3    4    5    6    7    8    9   30    1    2    3    4    5    6    7    8    9   40      1    2    3    4    5      6    7    8    9   50    1    2    3    4    5    6    7    8    9   60    1    2    3    4    5    6    7    8    9   70    1    2    3    4    5    6    7    8    9   80    1    2    3    4    5    6   */
         /* 0*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  
        /* 1*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  
        /* 2*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  
        /* 3*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  
        /* вверх 4*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  
        /* вправо 5*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  
        /* 6*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES,  NO,  NO,  NO,  NO,  
        /* 7*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  
        /* 8*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  
        /* 9*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  
        /*10*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  
        /*11*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*12*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*13*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*14*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*15*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*16*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*17*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  
        /*18*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  
        /*19*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*20*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO, YES,  NO,  NO, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*21*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO, YES,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*22*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO, YES,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*23*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO, YES,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*24*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO, YES, YES, YES, YES,  NO,  NO,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*25*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*26*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*27*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO, YES, YES,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*28*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*29*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*30*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* Влево 31*/YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* Вниз 32*/ NO,  NO, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /*33*/ NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* В 34*/ NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,    NO,  NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* е 35*/ NO,  NO,  NO,  NO,  NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* р 36*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, 
        /* х 37*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* н 38*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
        /* и 39*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO, YES, YES,    NO,  NO,  NO,  NO,  NO,   YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, 
        /* й 40*/YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  NO,  NO,  NO,  NO,  NO,  NO,  NO, YES,    NO,  NO,  NO,  NO,  NO,    NO, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES, YES,  
    };//   угол ромба карты                           -----> вниз вправо                                                                                            // Правый угол ромба карты     конец нового города ->|                              |-> начало старого города
    return allow_map;
}


bool sqc_building_area::is_allow_build( sqc_rect rect ) 
{
    const bool *field = get_allowing_mapping();
    
    if (!field) 
        return YES;
    
    int   x1 = rect.x;
    int   y1 = rect.y;
    int   x2 = x1 + rect.cx;
    int   y2 = y1 + rect.cy;
    
    if (x1 < bounds.x || y1 < bounds.y || x2 >= bounds.cx + bounds.x || y2 >= bounds.cy + bounds.y  ) {
        return NO;
    }
    
    for (int y = y1; y <= y2 - 1; ++y) {
        for (int x = x1; x <= x2 - 1; ++x) {
            int index = ( x1 - bounds.x ) + ( y1 - bounds.y ) * bounds.cx;
            if (!field[index]) {
                return NO;
            }
        }
    }
    
    return YES;
}

void sqc_building_area::draw( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv ) {
#ifdef DEBUG
    surf::surf_size cell_size = coord_conv.get_cell_size();
    
    ctx->set_color( surf::surf_byte_color( 255, 255, 0, 255 ) );
    ctx->set_width( 4 );
    
    const bool      *field = get_allowing_mapping();
    if( field ) {
        for( int  y = 0; y < bounds.cy; ++y ) {
            bool  const  *row = field+y*bounds.cx;
            for( int  x = 0; x < bounds.cx; ++x, ++row ) {
                if( !*row ) {
                    continue;
                }
                
                surf::surf_curve_ptr    curve = ctx->server().create_curve();                
                
                surf::surf_point   pos1 = coord_conv.field_to_screen( sqc_point( x + bounds.x, y + bounds.y ) );
                surf::surf_point   pos2 = surf::surf_point ( pos1.x + cell_size.cx, pos1.y + cell_size.cy );
                surf::surf_point   pos3 = surf::surf_point ( pos1.x + 2 * cell_size.cx, pos1.y );
                surf::surf_point   pos4 = surf::surf_point ( pos1.x + cell_size.cx, pos1.y - cell_size.cy );
                
                curve->move_to( pos1 );
                curve->line_to( pos2 );
                curve->line_to( pos3 );
                curve->line_to( pos4 );
                curve->line_to( pos1 );
                
                curve->draw( ctx );
            }
        }
    }
        
    ctx->set_color( surf::surf_color( 1, 1, 1, 1 ) );
    ctx->set_width( 1 );
    
#endif //DEBUG
}

END_NAMESPACE_SQC_CITY
