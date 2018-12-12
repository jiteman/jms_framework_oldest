/*
 *  sqc_bubble_def.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/2/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_bubble_def.h"

NAMESPACE_SQC_FRAMEWORK

void sqc_bubble_element::map_insert(const sqc_string& key, const sqc_string& value) {
    sqc_string_map::iterator lb = values.lower_bound(key);
    
    if(lb != values.end() && !(values.key_comp()(key, (*lb).first))) {
        (*lb).second = value;
    }
    else {
        values.insert(lb, sqc_string_map::value_type(key, value));
    }
}

void sqc_bubble_element::convert(const sqc_string& strval, sqc_string& val) {
    val = strval;
}

END_NAMESPACE_SQC_FRAMEWORK