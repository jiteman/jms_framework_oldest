#pragma once

#include "../../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_multipart_widget implementation
//
class sqc_multipart_widget : public milk::milk_widget {
public:
	sqc_multipart_widget( milk::milk_widget_ptr p, 
    			sqc_window_factory_ctx_ptr window_ctx );
	virtual ~sqc_multipart_widget();
    
    void			set_part_count( unsigned count );
    unsigned		get_part_count() const;
    void			set_part_endpoint( unsigned part_idx, const surf::surf_val& endpoint );

    void			set_enable_move( bool enable );
    
    void			set_freeze_count( unsigned freeze_parts_count );
    unsigned 		get_freeze_count() const;

	void			set_visible_count( unsigned visible_parts_count );
    unsigned		get_visible_count() const;
    
    void			set_animation_step( surf::surf_val step );
    
    virtual	void	on_visible_count_change();
    
    void			set_active_rect( const surf::surf_rect& rc );
    
    void            set_have_to_hide_invisible_childs( bool have_to_hide_invisible_childs );
protected:
    virtual void	handle_timer( surf::surf_ddword tick );
    virtual bool	handle_touch( milk::milk_touch_info const &info, bool bypass_click );

protected:
    typedef std::vector<surf::surf_val>		endpoints;
    endpoints								m_endpoints;
protected:
    sqc_window_factory_ctx_ptr	m_window_ctx;
    unsigned					m_freeze_parts_count;
    bool						m_enable_move;
    unsigned					m_visible_count;
    bool                        m_have_to_hide_invisible_childs;
    
    surf::surf_rect				m_active_rect;
    surf::surf_point			m_drag_start_point;
    surf::surf_rect				m_drag_start_window_rect;
    bool						m_dragging;
    bool						m_start_in_active_rect;
    
    surf::surf_ddword			m_start_tick;
    surf::surf_val				m_start_x;
    surf::surf_val				m_end_x;
    surf::surf_val				m_animation_step;    
};
                    
END_NAMESPACE_SQC_FRAMEWORK
