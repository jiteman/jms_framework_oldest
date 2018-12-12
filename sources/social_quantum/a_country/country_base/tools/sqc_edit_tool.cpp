#include "sqc_edit_tool.h"
#include "framework/sqc_framework.h"
#include "country_base/sqc_framework_base.h"

//#define SQC_ENABLE_CENTER_OBJECT

NAMESPACE_SQC_TOOLS

sqc_edit_tool::sqc_edit_tool()
: need_to_delete( false )
, m_object_changed( false )
{
}


bool sqc_edit_tool::on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    if (!sqc_tool::on_activate(arg, ctx, coord_onv)) return false;
    ctx.reset_selected_object();
    m_state = state_idle;
    m_object_changed = false;
    return true;
}

void sqc_edit_tool::on_deactivate( bool apply_changes, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv ) {
    if (apply_changes) {
        process_action(tool_action_apply, ctx, coord_onv );
    } else {
        process_action(tool_action_cancel, ctx, coord_onv);
    }
    m_object_changed = false;
    ctx.reset_selected_object();
    ctx.hide_bubble();
}


sqc_tool_type sqc_edit_tool::get_type() const {
    return tool_type_edit;
}

bool sqc_edit_tool::on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    
    sqc_point   click_coord = coord_conv.screen_to_field( point, true );
    sqc_game_object_ptr old_object = ctx.get_selected_object();
    sqc_game_object_ptr new_object = ctx.get_object_by_screen_point( point );
    
    
    if (new_object && new_object == old_object) {
        
        
        move_delta = point - coord_conv.field_to_screen( new_object->get_position() , sqc_coord_convert_mode_select , true );
		move_delta/=coord_conv.get_zoom();
        
        /// start pressed wait
        m_state = state_pressed;
        m_last_click_coord = point;
        m_state_time = 0;
    }
    else {
        /// place bottom corner at clicked pos
        if (old_object) click_coord.x-=(old_object->get_size().cx-1);
        move_delta = point - coord_conv.field_to_screen( click_coord , sqc_coord_convert_mode_select , true );
		move_delta/=coord_conv.get_zoom();
        m_state = state_idle;
        
        
        /// start pressed wait ( for jump and move )
        m_state = state_pressed;
        m_last_click_coord = point;
        m_state_time = 0;
    }
    
    return false;
}


bool sqc_edit_tool::on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    if (m_state == state_pressed) {
        m_state = state_idle;
    }
    return false;
}

bool sqc_edit_tool::on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    sqc_point   click_coord = coord_conv.screen_to_field( point- move_delta*coord_conv.get_zoom(), true );
    sqc_game_object_ptr old_object = ctx.get_selected_object();
    
    if( !old_object ) {
        return false;
    }
    
    m_last_click_coord = point;
    
    /// wait state
    if (m_state!=state_move_object)
        return false;
    
    if (!is_action_avaible(tool_action_move, ctx)) {
        return  false;
    }
    need_to_delete = false;
    bool    move_performed = ctx.move_object( old_object, click_coord );
    m_object_changed |= move_performed;
    if (move_performed)
        update_object( ctx, coord_conv );
    
    return true;
}

bool sqc_edit_tool::on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    sqc_game_object_ptr old_object = ctx.get_selected_object();
    sqc_game_object_ptr new_object = ctx.get_object_by_screen_point( point );

    /// select new object
    if (m_state!=state_move_object && new_object && new_object!=old_object) {
        
        if (old_object) {
            /// cancel old move
            if ( m_object_changed && !is_action_avaible(tool_action_apply, ctx )) {
                process_action(tool_action_cancel, ctx, coord_conv );
            } else {
                /// apply changes
                if( m_object_changed && is_action_avaible(tool_action_apply, ctx )) {
                    process_action(tool_action_apply, ctx, coord_conv );
                }
            }
        }
        
        m_start_position = new_object->get_position();
        m_start_orientation = new_object->get_orientation();
        
        m_object_changed = false;
        need_to_delete = false;
        
        ctx.set_selected_object( new_object );
        show_object_bubble(new_object, ctx, coord_conv );
        m_state = state_idle;
        return true;
    }
    
    if (m_state==state_pressed) {
         /// apply by fast click on object
         if (new_object && new_object==old_object) {
             /// delete
             if (need_to_delete) {
                 process_action( tool_action_delete, ctx, coord_conv );
                 return true;
             }
            /// rotate on fast click
            if ( is_action_avaible(tool_action_rotate, ctx) ) {
                process_action(tool_action_rotate, ctx, coord_conv );
                return true;
            }
            m_state = state_idle;
         }
    }
    
    if ( !new_object && old_object  && m_state==state_pressed && is_action_avaible(tool_action_move, ctx)) {
        /// jump
        sqc_point   click_coord = coord_conv.screen_to_field( point, true );
        /// place bottom corner at clicked pos
        click_coord.x-=(old_object->get_size().cx-1);
        bool perform_move = ctx.move_object( old_object, click_coord );
        m_object_changed |= perform_move;
        need_to_delete = false;
        if (perform_move) {
            update_object( ctx, coord_conv );
            ctx.scroll_to_object( new_object );
        }
    }
    
    // reset state
    m_state = state_idle; 
    
    
    if (new_object)
        ctx.scroll_to_object( new_object );
    return true;
}

bool sqc_edit_tool::on_timer(sqc_ddword ticks, sqc_tool_context &ctx,  sqc_coord_convertor &coord_conv) {
    if (m_state==state_pressed) {
        m_state_time+=ticks;
        if (m_state_time>ctx.get_second_action_time()*1000) {
            sqc_game_object_ptr object = ctx.get_selected_object();
            if (object) {
                if (is_action_avaible(tool_action_move, ctx)) {
                    sqc_info() << "sqc_edit_tool move by timer" << sqc_endl();
                    m_state = state_move_object;
                    on_touch_move( m_last_click_coord, ctx, coord_conv );
                    ctx.hide_bubble();
                    return true;
                } else {
                    m_state = state_idle;
                }
            }
        }
    }
    return false;
}

bool sqc_edit_tool::process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv ) {
    sqc_game_object_ptr old_object = ctx.get_selected_object();
    if( !old_object ) {
        return false;
    }

    if( action == tool_action_apply ) {
        if( m_object_changed ) {
            if (is_action_avaible(tool_action_move, ctx) || is_action_avaible(tool_action_rotate, ctx)) {
                ctx.apply_move_object( old_object );
                ctx.reset_selected_object();
                ctx.hide_bubble();
            }
        }
        m_object_changed = false;
        m_state = state_idle;
        return true;
    }
    else if( action == tool_action_rotate ) {
        bool rotated = ctx.rotate_object( old_object );
        m_object_changed |= rotated;
        m_state = state_idle;
        if (rotated) update_object(ctx, coord_conv );
        return true;
    }
    else if( action == tool_action_delete ) {
        
        if (!need_to_delete) {
            need_to_delete = true;
            show_object_bubble( old_object, ctx, coord_conv );
            return false;
        }
        
        if( !ctx.delete_object( old_object ) ) {
            return false;
        }
        ctx.reset_selected_object();
        ctx.hide_bubble();
        
        m_object_changed = false;
        need_to_delete = false;
        m_state = state_idle;
        return true;
    }
    else if( action == tool_action_cancel ) {
        ctx.move_object( old_object, m_start_position );
        size_t watch_dog = 0;
        while ( old_object->get_orientation()!=m_start_orientation && (watch_dog++<3) )
            ctx.rotate_object(old_object);
        m_object_changed = false;
        need_to_delete = false;
        m_state = state_idle;
    }
    
    return false;
}

bool	sqc_edit_tool::fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv  ) {
	sqc_country_owner owner = ctx.get_country_owner();
    object->sqc_game_object::fill_bubble_content( content , owner );
    
    if (owner != sqc_country_owner_me) {
        return true;
    }
    
    sqc::framework::sqc_bubble_element element;
	element.tag = "status";
	
    if (need_to_delete) {
        {
            int coins = object->get_object_info()->get_cost_sell_game();
            sqc::framework::sqc_bubble_element element;
            element.tag = "info";
            element.icon = "bubble_icon_money";
            element.text = sqc::framework::framework().formats().format_digit_grouping( coins );
            if (coins>0)
                element.text = element.text;
            if (coins!=0)
                content.elements.push_back(element);
        }
        element.icon = "bubble_sale";
        element.text = framework::framework().strings().load("*CommonClickToKill","Click once again to sale");
        content.elements.push_back( element );
        content.default_action = action_cancel; /// just no nop
        content.action_callback = std::tr1::bind( &sqc_edit_tool::process_action, this,  tool_action_delete, std::tr1::ref( ctx ), std::tr1::ref( coord_conv ) );
    }
    else {
        if (is_action_avaible(tool_action_move, ctx) ) {
            if ( is_action_avaible( tool_action_move, ctx )) {
                element.icon = "bubble_move";
                element.text = framework::framework().strings().load("*CommonDragToMove","Click and drag to move");
                content.elements.push_back( element );
            }
            if ( is_action_avaible( tool_action_rotate, ctx )) {
                element.icon = "bubble_rotate";
                element.text = framework::framework().strings().load("*CommonClickToRotate","Click once again to rotate");
                content.elements.push_back( element );
                content.default_action = action_move; /// just no nop
                content.action_callback = std::tr1::bind( &sqc_edit_tool::process_action, this,  tool_action_rotate, std::tr1::ref( ctx ), std::tr1::ref( coord_conv ) );
            }
        }
    }
    
    return true;
}
bool sqc_edit_tool::object_place_allowed( sqc_tool_context &ctx ) {
    sqc_game_object_ptr object = ctx.get_selected_object();
    if (!object) return false;
    if (!ctx.is_allow_build(sqc_rect(object->get_position(),object->get_size()))) return false;
    return true;
}
void sqc_edit_tool::update_object(sqc_tool_context &ctx,sqc_coord_convertor &coord_conv) {
    sqc_game_object_ptr object = ctx.get_selected_object();
    if (object) {
        if (m_object_changed || m_state == state_move_object) {
            ctx.set_selected_object( object , object_place_allowed(ctx) ? 
                            sqc_game_object_selection_type_edit : 
                            sqc_game_object_selection_type_invalid );
            ctx.hide_bubble();
        } else {
            ctx.set_selected_object( object , sqc_game_object_selection_type_normal );
            show_object_bubble( object, ctx, coord_conv );
        }
            
    }
}

bool sqc_edit_tool::is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx ) {
    sqc_game_object_ptr selected_object = ctx.get_selected_object();
    if (!selected_object) {
        return false;
    }
    
	sqc::framework::sqc_framework_base  &base_framework = 
		static_cast<sqc::framework::sqc_framework_base  &>( sqc::framework::framework() );
    
    info::sqc_object_info_provider_ptr ip = base_framework.object_factory();
    sqc_object_info *object_info = ip->get_object_info(selected_object->get_type().c_str());
    
    if (tool_action_rotate == action) {
        return object_info->get_can_be_rotate();
    }
    
    if (tool_action_delete == action) {
        return object_info->get_sell();
    }
    
    if (tool_action_apply == action) {
        return m_object_changed && object_place_allowed(ctx);
    }
    
    if (tool_action_move == action) {
        return object_info->get_move();
    }
    
    return true;
}

END_NAMESPACE_SQC_TOOLS
