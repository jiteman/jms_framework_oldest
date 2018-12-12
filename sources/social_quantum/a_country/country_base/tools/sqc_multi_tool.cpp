/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_multi_tool.h"

NAMESPACE_SQC_TOOLS

sqc_tool_type sqc_multi_tool::get_type() const {
    return tool_type_multi;
}

bool sqc_multi_tool::on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    sqc_point   click_coord = coord_onv.screen_to_field( point );
    sqc_game_object_ptr old_object = ctx.get_selected_object();
    sqc_game_object_ptr new_object = ctx.get_object_by_screen_point( point );
    
    sqc_info() << "sqc_multi_tool::on_touch_up( " << click_coord.x << "," << click_coord.y << sqc_endl();
    
    if( old_object ) {
        sqc_info() << "sqc_multi_tool::on_touch_up have old object" << sqc_endl();
        if( old_object == new_object ) {
            sqc_action  action = get_object_action( new_object );
            if (action == action_nop || !ctx.run_action( new_object, action )) {
                /// hide buble and selection by second click
                ctx.reset_selected_object();
                ctx.hide_bubble();
            }
            return true;
        }
        else {
            if (!new_object) {
                sqc_info() << "sqc_multi_tool::on_touch_up not new object, reset selection" << sqc_endl();
                ctx.reset_selected_object();
                ctx.hide_bubble();
                return true;
            }
        }
    }
    
    if( new_object ) {
        
        sqc_action  action = get_object_action( new_object );
        if( action!= action_nop && new_object->is_single_click_action( action ) ) {
            if (!ctx.run_action( new_object, action )) {
     		}
        } else {
            if (old_object) {
                /// first click on another object clear selection
                ctx.reset_selected_object();
                ctx.hide_bubble();
            } else {
                ctx.set_selected_object( new_object );
                show_object_bubble( new_object, ctx, coord_onv );
            }
      	}
        return true;
    }
    else {
        
        if( old_object ) {
            return true;
        }

#ifdef SQC_FARM_GAME
        sqc_size    object_size( 4, 4 );
#else
        sqc_size    object_size( 1, 1 );
#endif 

        if(
           !ctx.is_allow_build( sqc_rect(click_coord,object_size) ) ) {
            return false;
        }
        sqc_point   object_coords( click_coord.x - object_size.cx/2, click_coord.y - object_size.cy/2 );

        
        new_object = ctx.create_build_object( object_coords, object_size );
        ctx.set_selected_object( new_object );
        show_object_bubble( new_object, ctx, coord_onv );
        return true;
    }
    return false;
}


bool sqc_multi_tool::fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv  ) {
    if (!need_show_bubble(object)) return false;
	content.default_action = get_object_action(object);
	content.action_callback = std::tr1::bind( &sqc_multi_tool::on_bubble_action, this,  std::tr1::ref( ctx ), std::tr1::placeholders::_1, std::tr1::placeholders::_2 );
	return object->fill_bubble_content( content , ctx.get_country_owner() );
}

void sqc_multi_tool::on_field_changed(sqc_tool_context &ctx, sqc_coord_convertor &coord_onv) {
    sqc_game_object_ptr object = ctx.get_selected_object();
	if ( need_show_bubble(object) ) {
		show_object_bubble( object, ctx, coord_onv );
	}
    else
        ctx.hide_bubble();
}

void sqc_multi_tool::on_bubble_action( sqc_tool_context &ctx , sqc_action action, const sqc_action_params_ptr& params ) {
    if (action==action_pick)
        ctx.hide_bubble();
	if (!ctx.run_action( ctx.get_selected_object(), action, params )) {
	}
}

bool sqc_multi_tool::need_show_bubble( const sqc_game_object_ptr& object ) const {
    if (!object) return false;
    sqc_object_state state = object->get_object_state();
    if ( state == object_state_progress ) return false;
    if ( state == object_state_queued ) return false;
    if ( state == object_state_wait_update ) return false;
    return true;
}

sqc_action sqc_multi_tool::get_object_action( const sqc_game_object_ptr& object ) const {
    return object->get_default_action();
}



END_NAMESPACE_SQC_TOOLS

