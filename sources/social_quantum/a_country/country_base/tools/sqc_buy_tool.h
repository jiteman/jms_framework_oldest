#ifndef __SQC_BUY_TOOL_H_INCLUDED__
#define __SQC_BUY_TOOL_H_INCLUDED__

#include "sqc_tools_common.h"

NAMESPACE_SQC_TOOLS

class sqc_buy_tool : public sqc_tool {
    virtual sqc_tool_type get_type() const {
        return tool_type_buy;
    }
    
    virtual bool on_activate( sqc_activate_tool_arg const &arg, sqc_tool_context &ctx, sqc_coord_convertor &coord_onv );
    virtual bool on_touch_down( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_touch_move( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_touch_up( surf::surf_point const &point, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool on_scroll( surf::surf_point const &scroll_pos, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv );
    virtual bool process_action( sqc_tool_action action, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv  );
    virtual void on_field_changed(sqc_tool_context &ctx, sqc_coord_convertor &coord_onv);

    virtual bool	fill_bubble_content( sqc_game_object_ptr object, sqc::framework::sqc_bubble_content& content, sqc_tool_context &ctx, sqc_coord_convertor &coord_conv  );
    
    virtual bool is_action_avaible( sqc_tool_action action, sqc_tool_context &ctx );
    virtual bool on_timer(sqc_ddword ticks, sqc_tool_context &ctx,  sqc_coord_convertor &coord_conv);
private:
    sqc_game_object_ptr purchase_next_object( sqc_tool_context &ctx, sqc_point const &coords , sqc_coord_convertor &coord_conv);
    void on_bubble_action( sqc_tool_context &ctx , sqc_action action , sqc_coord_convertor &coord_conv);
    
    bool object_build_allowed( sqc_tool_context &ctx );
                              
    sqc_string object_to_purchase;
    sqc_size    m_object_size;
    
    sqc_game_object_ptr m_object;
    
    surf::surf_point    move_delta;
    
    bool	gift;
    
    void update_object(sqc_tool_context &ctx,sqc_coord_convertor &coord_conv);
    
    enum tool_state {
        state_idle,
        state_pressed,
        state_move_scroll,
        state_move_object
    } m_state;
 
    sqc_ddword  m_state_time;
    surf::surf_point   m_last_click_coord;
};

END_NAMESPACE_SQC_TOOLS


#endif//__SQC_BUY_TOOL_H_INCLUDED__
