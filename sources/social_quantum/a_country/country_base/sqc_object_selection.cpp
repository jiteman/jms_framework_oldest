/*
 *  sqc_object_selection.cpp
 *  aCountry
 *
 *  Created by Андрей Куницын on 14.09.11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_object_selection.h"
#include "framework/sqc_framework.h"
#include <surf/surf_gl.h>

NAMESPACE_SQC_FRAMEWORK


struct sqc_object_selection::implementation {
	surf::surf_rendertarget_ptr	targets[2];
	surf::surf_nsize targets_size;
	size_t src_index;
	size_t dst_index;
	size_t phase;
	surf::surf_point offset;
	surf::surf_point scale;

	surf::surf_size	 size;
	implementation() {
		targets_size = surf::surf_nsize(256,256);
		reset();
	}
	void reset() {
		src_index = 0;
		dst_index = 1;
		phase = 0;
	}
	surf::surf_rect	object_rect;
	surf::surf_image_ptr	pattern;
};

sqc_object_selection::sqc_object_selection(const char* pattern_name,size_t iterations,int iteration_delta) 
: m_pattern_name(pattern_name),m_max_iterations(iterations),m_iteration_delta(iteration_delta){
	m_impl = new implementation();
    m_selection_type = sqc_game_object_selection_type_none;
    /// green by default
    m_normal_selection_color = surf::surf_color( 0, 1, 0, 1);
    /// red by default
    m_invalid_selection_color = surf::surf_color( 1, 0, 0, 1);
}

sqc_object_selection::~sqc_object_selection() {
	delete m_impl;
}

void sqc_object_selection::set_object( sqc_game_object_ptr object , sqc_game_object_selection_type type) {
	if (m_object!=object) {
		m_impl->reset();
	}
    m_selection_type = type;
	m_object = object;
}

void sqc_object_selection::process_draw(surf::surf_context_ptr ctx) {
	if (m_impl->phase < m_max_iterations) {
		m_impl->targets[m_impl->dst_index]->bind(ctx);
		surf::surf_point scale = m_impl->scale;
		surf::surf_image_ptr img = m_impl->targets[m_impl->src_index]->get_image();
		if ( true /*m_impl->phase % 2 */) {
			img->draw( ctx, surf::surf_point( scale.x*m_iteration_delta, 0 ));
			img->draw( ctx, surf::surf_point( -scale.x*m_iteration_delta, 0 ));	
		/*} else {*/
			img->draw( ctx, surf::surf_point( 0,scale.y*m_iteration_delta ));
			img->draw( ctx, surf::surf_point( 0,-scale.y*m_iteration_delta ));	
		}
		m_impl->targets[m_impl->dst_index]->unbind(ctx);
		std::swap(m_impl->dst_index,m_impl->src_index);
		m_impl->phase++;
	} else if (m_impl->phase==m_max_iterations) {
		m_impl->phase++;
	}
}

bool sqc_object_selection::need_redraw() const {
	return 
		( (m_impl->phase>0) && (m_impl->phase<=m_max_iterations) )||
		(m_object && (m_impl->phase==0));
}

class sqc_coord_convertor_proxy : public sqc_coord_convertor{
private:
	sqc_coord_convertor& original;
	surf::surf_point offset;
public:
	sqc_coord_convertor_proxy( sqc_coord_convertor& original,const surf::surf_point& offset ) : original(original),offset(offset) {
	}
    virtual surf::surf_val      get_zoom() const {
		return original.get_zoom();
	}
    virtual surf::surf_nsize     get_screen_size(bool with_zoom) const {
		return original.get_screen_size(with_zoom);
	}
    virtual surf::surf_point    field_to_screen( sqc_point const &p, sqc_coord_convert_mode mode , bool center ) const {
		return original.field_to_screen(p,mode,center)+offset;
	}
    virtual sqc_point           screen_to_field( surf::surf_point const &pt, bool strong = true ) const {
		return original.screen_to_field(pt+offset, strong);
	}
    virtual surf::surf_size     get_cell_size() const {
        return original.get_cell_size();
    }
};

void sqc_object_selection::render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv , const sqc_game_object_draw_args& in_draw_args) {
	if (m_object) {
        surf::surf_color clr = ctx->get_color();
        if (m_selection_type == sqc_game_object_selection_type_edit) {
            ctx->set_color( clr* m_normal_selection_color );
        } else if (m_selection_type == sqc_game_object_selection_type_invalid) {
            ctx->set_color( clr* m_invalid_selection_color );
        } else if (m_selection_type == sqc_game_object_selection_type_normal) {
            
        
            if (m_impl->phase==0) {
                calculate_size(coord_conv);
                if (!m_impl->targets[0] || !m_impl->targets[1]) {
                    if (!create_targets())
                        m_object = sqc_game_object_ptr();
                    return;
                } else {
                    if (!m_impl->pattern) {
                        surf::surf_graphics_server& gs = ::sqc::framework::framework().graphics();
                        m_impl->pattern = gs.create_image( m_pattern_name );
                    }
                    surf::surf_transform old_tr = ctx->get_transform();
                    ctx->set_brush(m_impl->pattern);
                    sqc_coord_convertor_proxy proxy(coord_conv,m_impl->offset*(-1));
                    m_impl->targets[0]->bind(ctx);
                    m_impl->targets[0]->clear(surf::surf_color(0,0,0,0));
                    surf::surf_rect screen_rect = m_object->get_display_rect( coord_conv );
                    ctx->set_transform( surf::surf_transform().translate(get_space(),get_space()).scale(m_impl->scale) );
                    sqc_game_object_draw_args draw_arg = in_draw_args;
                    draw_arg.mode = sqc_game_object_draw_args::animation_no_ff;
                    draw_arg.tooltip = false;
                    m_object->render( ctx, proxy,draw_arg );
                    m_impl->targets[0]->unbind(ctx);
                    
                    m_impl->targets[1]->bind(ctx);
                    m_impl->targets[1]->clear(surf::surf_color(0,0,0,0));
                    //m_object->render( ctx, proxy , true);
                    m_impl->targets[1]->unbind(ctx);
                    
                    ctx->set_brush(surf::surf_image_ptr());
                    ctx->set_transform( old_tr );
                    m_impl->phase++;
                }
            } 
            
            process_draw(ctx);
            
            if (m_impl->targets[m_impl->dst_index]) {
                surf::surf_image_ptr img = m_impl->targets[m_impl->dst_index]->get_image();
                if (img) {
                    surf::surf_rect screen_rect = m_object->get_display_rect( coord_conv );
                    surf::surf_rect to = screen_rect;
                    surf::surf_point scale = m_impl->scale;
                    to.x-=get_space();
                    to.y-=get_space();
                    to.cx+=get_space()*2;
                    to.cy+=get_space()*2;
                    surf::surf_rect from = m_impl->object_rect;
                    from.x-=scale.x*get_space();
                    from.y-=scale.y*get_space();
                    from.cx+=scale.x*get_space()*2;
                    from.cy+=scale.y*get_space()*2;
                    from.y = m_impl->targets_size.cy-(from.cy+from.y);
                    img->draw( ctx, to, from);
                }
            }
        }
        sqc_game_object_draw_args draw_arg = in_draw_args;
        draw_arg.tooltip = false;
        m_object->render(ctx, coord_conv, draw_arg);
        ctx->set_color( clr );
	}
}

void sqc_object_selection::calculate_size( sqc_coord_convertor &coord_conv ) {
	surf::surf_rect screen_rect = m_object->get_display_rect( coord_conv );
	surf::surf_rect to_target_rect = surf::surf_rect( screen_rect.size() );
	m_impl->offset = screen_rect.bottom_left();
	if (to_target_rect.cx > (m_impl->targets_size.cx - get_space()*2))
		to_target_rect.cx = m_impl->targets_size.cx - get_space()*2;
	if (to_target_rect.cy > (m_impl->targets_size.cy - get_space()*2))
		to_target_rect.cy = m_impl->targets_size.cy - get_space()*2;
	to_target_rect.x = get_space();
	to_target_rect.y = get_space();
	m_impl->object_rect = to_target_rect;
	m_impl->scale.x = to_target_rect.cx / screen_rect.cx;
	m_impl->scale.y = to_target_rect.cy / screen_rect.cy;
}
bool sqc_object_selection::create_targets() {
	surf::surf_graphics_server& gs = ::sqc::framework::framework().graphics();
	m_impl->targets[0] = gs.create_target( m_impl->targets_size.cx,m_impl->targets_size.cy , true);
	m_impl->targets[1] = gs.create_target( m_impl->targets_size.cx,m_impl->targets_size.cy , true);
	return m_impl->targets[0] && m_impl->targets[1];
}


END_NAMESPACE_SQC_FRAMEWORK
