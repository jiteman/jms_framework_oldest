/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_buy_tool.h"
#include "../sqc_framework_base.h"

NAMESPACE_SQC_TOOLS

bool sqc_buy_tool::on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if (!sqc_tool::on_activate(arg, ctx, coord_conv)) return false;
    m_object = sqc_game_object_ptr();
    object_to_purchase = arg.purchased_object_type;
    
    gift = arg.gift;
    
    if( object_to_purchase.empty() ) {
        ctx.show_shop();
        return false;
    }
    
    surf::surf_nsize screen_size( coord_conv.get_screen_size(false) );
    sqc_point  coords = coord_conv.screen_to_field( surf::surf_point( screen_size.cx/2, screen_size.cy/2 ) , false);
    if( arg.operation_coords_defined ) {
        coords = arg.operation_coords;
    }
    
    m_object = purchase_next_object( ctx, coords , coord_conv);
    if (m_object)
        m_object_size = m_object->get_size();
    update_object(ctx,coord_conv);
    
    m_state = state_idle;
    m_state_time = 0;
    
    return true;
}

bool sqc_buy_tool::on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {

    sqc_point   click_coord = coord_conv.screen_to_field( point, true );
    sqc_game_object_ptr old_object = m_object;
    sqc_game_object_ptr click_object = ctx.get_object_by_screen_point( point );
    
    if (!m_object) {
        if (ctx.is_allow_build( sqc_rect( click_coord,sqc_size(1,1)) )) {
            /// create new object
            old_object = m_object = purchase_next_object( ctx, click_coord ,coord_conv);
            if (old_object) {
                click_object = old_object;
                update_object(ctx,coord_conv);
                /// and move
                m_state = state_move_object;
                m_last_click_coord = point;
            } else 
                return false;
        } else 
            return false;
    } else {
        /// start pressed wait
        m_state = state_pressed;
        m_last_click_coord = point;
        m_state_time = 0;
    }
    
    if( click_object && click_object == old_object ) {
        move_delta = point - coord_conv.field_to_screen( old_object->get_position() ,sqc_coord_convert_mode_select, true );
        move_delta/=coord_conv.get_zoom();
    }
    else {
        /// place bottom corner at clicked pos
        if (old_object) click_coord.x-=(old_object->get_size().cx-1);
        move_delta = point - coord_conv.field_to_screen( click_coord ,sqc_coord_convert_mode_select , true );
        move_delta/=coord_conv.get_zoom();
    }
    
    return false;
}

bool sqc_buy_tool::on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    /// scroll move mode
    if (m_state == state_move_scroll)
        return false;

    m_last_click_coord = point;

    /// wait state
    if (m_state == state_pressed)
        return false;
   
    sqc_point   click_coord = coord_conv.screen_to_field( point - move_delta*coord_conv.get_zoom(), true );
    sqc_game_object_ptr old_object = m_object;
    
    if( !old_object ) {
        return false;
    }
    
    bool    move_performed = ctx.move_object( old_object, click_coord );
    
    if (move_performed) {
        update_object(ctx,coord_conv);
    }
    
    
    
    return true;
}
bool sqc_buy_tool::on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    
    if (m_state != state_pressed && m_state!=state_move_object) {
        m_state = state_idle;
        /// cancel operation
        update_object(ctx,coord_conv);
        return false;
    }
    
    sqc_game_object_ptr old_object = m_object;
    if (!old_object)
        return false;
    
    /// jump object
    if ( m_state == state_pressed ) {
        sqc_point   click_coord = coord_conv.screen_to_field( point, true );
        /// place bottom corner at clicked pos
        click_coord.x-=(old_object->get_size().cx-1);
        bool perform_move = ctx.move_object( old_object, click_coord );
        m_state = state_idle;
        ctx.scroll_to_object( old_object );
        update_object(ctx,coord_conv);
        
        /// not jump, accept
        if (!perform_move ) {
            process_action( tool_action_apply, ctx, coord_conv );
        }
        return true;
    }
    
    /// move complete
    assert( m_state == state_move_object );
    m_state = state_idle;
    update_object(ctx,coord_conv);
    ctx.scroll_to_object( old_object );
    
    return false;
}

bool sqc_buy_tool::object_build_allowed( sqc_tool_context &ctx ) {
    sqc_game_object_ptr object = m_object;
    
    if (!object) return false;
    if (!ctx.is_allow_build(sqc_rect(object->get_position(),object->get_size()))) return false;
    return true;
}

bool sqc_buy_tool::on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if (m_state == state_pressed) {
        m_state = state_move_scroll;
    }
    if (m_state == state_move_scroll ) {
        sqc_game_object_ptr old_object = m_object;
        if( !old_object ) {
            return false;
        }
        
        sqc_size    object_size = old_object->get_size();
        surf::surf_point object_screen_size = coord_conv.field_to_screen( sqc_point( object_size.cx, object_size.cy ), sqc_coord_convert_mode_select_no_scroll );
        
        
        surf::surf_point    point = surf::surf_point( coord_conv.get_screen_size(false).cx/2 - object_screen_size.x/2, 
                                                     coord_conv.get_screen_size(false).cy/2 - object_screen_size.y/2 );
        sqc_point   click_coord = coord_conv.screen_to_field( point );
        
        
        bool perform_move = ctx.move_object( old_object, click_coord );
        if (perform_move) {
            update_object(ctx,coord_conv);
        }
        return true;
    }
    return false;
}


sqc_game_object_ptr sqc_buy_tool::purchase_next_object( sqc_tool_context &ctx, sqc_point const &coords , sqc_coord_convertor &coord_conv) {
    sqc_game_object_ptr new_object = ctx.create_object( coords, object_to_purchase );
    ctx.set_selected_object( new_object );
     m_state = state_idle;
    ctx.scroll_to_object( new_object );
    return new_object;
}

bool sqc_buy_tool::process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv  ) {
    
    sqc_game_object_ptr old_object = m_object;
    
    
    m_state = state_idle;

    if( action == tool_action_apply ) {
        if( !old_object ) {
            return false;
        }
        if (gift) {
            ctx.receive_object(old_object, old_object->get_position());
            m_object = sqc_game_object_ptr();
            ctx.set_selected_object(sqc_game_object_ptr());
            ctx.hide_bubble();
            ctx.close_tool();
        }
        else {
            ctx.build_object( old_object, old_object->get_position());
            m_object = sqc_game_object_ptr();
            ctx.set_selected_object(sqc_game_object_ptr());
            ctx.hide_bubble();
        }
        return true;
    } else if ( action == tool_action_market ) {
        sqc_point position = old_object->get_position();
        ctx.show_shop(&position);
        return true;
    }
    
    return false;
}

void sqc_buy_tool::on_field_changed(sqc_tool_context &ctx, sqc_coord_convertor &coord_conv) {
    sqc_game_object_ptr view_object = ctx.get_selected_object();
    if (!view_object) {
       
    } else {
        assert( m_object == view_object );
    }
    update_object(ctx,coord_conv);
}




bool    sqc_buy_tool::fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv  ) {
    sqc_country_owner owner = ctx.get_country_owner();
    object->sqc_game_object::fill_bubble_content( content , owner );
    
    if (owner != sqc_country_owner_me) {
        return true;
    }
    bool allow_build = object_build_allowed(ctx);
    
    sqc::framework::sqc_bubble_element element;
	element.tag = "status";
    if (allow_build) {
        element.text = framework::framework().strings().load("*CommonClickToBuild","Click here to build"); 
        element.icon = "bubble_apply";
        content.default_action = action_put;
        content.action_callback = std::tr1::bind( &sqc_buy_tool::on_bubble_action, this,  std::tr1::ref( ctx ), std::tr1::placeholders::_1 ,std::tr1::ref( coord_conv ));
    } else {
        element.text = framework::framework().strings().load("*CommonClickFreeToBuild","Click on free place to build"); 
    }
    content.elements.push_back(element);
    return true;
}

void sqc_buy_tool::on_bubble_action( sqc_tool_context &ctx , sqc_action action , sqc_coord_convertor &coord_conv) {
    if (action == action_put ) {
        process_action( tool_action_apply, ctx, coord_conv );
    }
}

void sqc_buy_tool::update_object(sqc_tool_context &ctx,sqc_coord_convertor &coord_conv) {
    if (m_object) {
        ctx.set_selected_object( m_object , object_build_allowed(ctx) ? 
                                sqc_game_object_selection_type_edit : 
                                sqc_game_object_selection_type_invalid );
        if (m_state == state_move_object)
            ctx.hide_bubble();
        else
            show_object_bubble( m_object, ctx, coord_conv );
    }
}

bool sqc_buy_tool::is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx ) {
    if ( action == tool_action_cancel) return true;
    if ( action == tool_action_apply ) return object_build_allowed(ctx);
    if ( action == tool_action_market ) return !gift;
    return false;
}

bool sqc_buy_tool::on_timer(sqc_ddword ticks, sqc_tool_context &ctx,  sqc_coord_convertor &coord_conv) {
    if (m_state==state_pressed) {
        m_state_time+=ticks;
        if (m_state_time>ctx.get_second_action_time()*1000) {
            if (m_object) {
                sqc_info() << "sqc_buy_tool move by timer" << sqc_endl();
                m_state = state_move_object;
                on_touch_move( m_last_click_coord, ctx, coord_conv );
                ctx.hide_bubble();
                return true;
            }
        }
    }
    return false;
}

END_NAMESPACE_SQC_TOOLS