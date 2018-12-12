#ifndef __SQC_MOVE_TOOL_H_INCLUDED__
#define __SQC_MOVE_TOOL_H_INCLUDED__

#include "sqc_tools_common.h"

NAMESPACE_SQC_TOOLS

class sqc_edit_tool : public sqc_tool {
public:
    sqc_edit_tool();
protected:
    
    virtual bool on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    virtual void on_deactivate( bool apply_changes, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    
    virtual sqc_tool_type get_type() const;
    virtual bool on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx );
    virtual bool on_timer(sqc_ddword ticks, sqc_tool_context &ctx,  sqc_coord_convertor &coord_conv);
private:
    bool    need_to_delete;
    bool    m_object_changed;

    surf::surf_point  move_delta;
    sqc_point   m_start_position;
    bool        m_start_orientation;
    
    virtual bool	fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv  );
    
    enum state {
        state_idle,
        state_pressed,
        state_move_object
    } m_state;
    sqc_ddword  m_state_time;
    surf::surf_point   m_last_click_coord;
    bool object_place_allowed( sqc_tool_context &ctx );
    void update_object(sqc_tool_context &ctx,sqc_coord_convertor &coord_conv);
};

END_NAMESPACE_SQC_TOOLS

#endif//__SQC_MOVE_TOOL_H_INCLUDED__
