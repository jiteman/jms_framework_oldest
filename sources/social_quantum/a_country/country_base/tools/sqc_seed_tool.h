/*
 *  sqc_seed_tool.h
 *  aFarm
 *
 *  Created by Ilya Radinsky on 24.10.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#ifndef __SQC_SEED_TOOL_H_INCLUDED__
#define __SQC_SEED_TOOL_H_INCLUDED__

#include "sqc_tools_common.h"

NAMESPACE_SQC_TOOLS

class sqc_seed_tool : public sqc_tool {
    
public:
    virtual bool on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    virtual bool on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );   
    virtual sqc_tool_type get_type() const;
private:
    sqc_string object_to_purchase;
};
    

END_NAMESPACE_SQC_TOOLS

#endif//__SQC_SEED_TOOL_H_INCLUDED__
