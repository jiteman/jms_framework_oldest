/*
 *  sqc_name_formatter.cpp
 *  configurator
 *
 *  Created by Lin on 6/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_name_formatter.h"
#include "sqc/farm_name_farmatter.h"



void formattingString(std::string &textureName ,std::string formaterType,bool delete_enumirate)
{
    if (formaterType=="farm") {
        farmformattingString(textureName,delete_enumirate);
               
    }
};