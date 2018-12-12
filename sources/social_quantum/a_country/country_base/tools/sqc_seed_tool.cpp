/*
 *  sqc_seed_tool.cpp
 *  aFarm
 *
 *  Created by Ilya Radinsky on 24.10.11.
 *  Copyright 2011 SocialQuantum. All rights reserved.
 *
 */

#include "sqc_seed_tool.h"
#include "country_base/commands/sqc_command_processor.h"
#include "country_base/sqc_framework_base.h"

NAMESPACE_SQC_TOOLS

bool sqc_seed_tool::on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    object_to_purchase = arg.purchased_object_type;
    return true;
}

bool sqc_seed_tool::on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    sqc_game_object_ptr new_object = ctx.get_object_by_screen_point( point );
    
    if( new_object ) {
        processor::sqc_command_processor &processor = country_framework().cmd_processor();
        sqc_string str_user_id = "";
        int item_id = new_object->get_id();
        processor::sqc_command_ptr  command( new sqc::processor::sqc_apply_command( str_user_id, object_to_purchase, item_id) );
        processor.schedule( command );
    }
    
    return true;
}

sqc_tool_type sqc_seed_tool::get_type() const {
    return tool_type_seed;
}

END_NAMESPACE_SQC_TOOLS