//
//  sqc_visit_field_tool.cpp
//  aCountry
//
//  Created by Paul on 9/20/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "sqc_visit_field_tool.h"

NAMESPACE_SQC_TOOLS


sqc_tool_type sqc_visit_field_tool::get_type() const {
    return tool_type_visit_field;
}

bool sqc_visit_field_tool::on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    if (!sqc_tool::on_activate(arg, ctx, coord_onv)) return false;
   ctx.visit_frend_field( arg.user_id );
   return true;
}

void sqc_visit_field_tool::on_deactivate( bool apply_changes, sqc_tool_context &ctx ,sqc_coord_convertor &coord_onv) {
    ctx.leave_frend_field();
}


sqc_action sqc_visit_field_tool::get_object_action( const sqc_game_object_ptr& object ) const {
    (void)object;
    /// for now disable all actions on friends field
    return action_nop;
}

END_NAMESPACE_SQC_TOOLS