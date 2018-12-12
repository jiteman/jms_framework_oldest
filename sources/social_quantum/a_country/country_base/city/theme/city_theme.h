/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_THEME_H_INCLUDED__
#define __SQC_CITY_THEME_H_INCLUDED__

#include "framework/sqc_framework_defs.h"
#include "surf/surf_9way_image.h"
#include "framework/layout/sqc_windows_factory.h"
#include "framework/theme/sqc_theme_base.h"
#include "sound/sqc_sound.h"

NAMESPACE_SQC_FRAMEWORK


//
// sqc_city_theme implementation
//


class sqc_city_theme : public sqc_theme_base {
public:
	sqc_city_theme( surf::surf_graphics_server& gs );
public:
	/// implement public interface
	virtual void init_metrics();
    virtual void draw_dialog( surf::surf_context_ptr ctx, 
    						surf::surf_rect const &rect, 
                            milk::milk_dialog_draw_arg const &arg );
    virtual void draw_window( surf::surf_context_ptr ctx, milk::milk_window &w );
    virtual void draw_button( surf::surf_context_ptr ctx, milk::milk_theme_button &w );
    virtual void draw_label( surf::surf_context_ptr ctx, milk::milk_label &w );
    virtual void draw_scroller( surf::surf_context_ptr ctx, milk::milk_scroll_area &w );
    virtual void draw_spinboard( surf::surf_context_ptr ctx, milk::milk_spinboard &w );
	virtual void draw_bubble( surf::surf_context_ptr ctx, surf::surf_rect const &rect, milk::milk_bubble_draw_arg const &arg );
	virtual void draw_separator( surf::surf_context_ptr ctx, milk::milk_separator_draw_arg const &arg );
    virtual void draw_bevel( surf::surf_context_ptr ctx, surf::surf_rect const &rect, milk::milk_bevel_draw_arg const &arg );
	
    virtual void on_init_dialog( milk::milk_dialog& dlg, milk::milk_dialog_init_arg const &arg, milk::milk_dialog_draw_arg& draw_arg );
	virtual bool on_end_dialog(  milk::milk_dialog& dlg, milk::milk_dialog_init_arg const &arg  );
	virtual surf::surf_rect get_dialog_content_rect( const surf::surf_rect& rect, const milk::milk_dialog_init_arg& init_arg );
	virtual void init_dialog_tabs( milk::milk_dialog& dlg, const milk::milk_dialog_init_arg& init_arg, 
								  milk::milk_dialog_draw_arg const &draw_arg, 
								  std::vector<milk::milk_dialog_tab_def>& tabs );
	virtual void on_init_spinboard( milk::milk_spinboard& spin , milk::milk_spinboard_theme_flags flags);
	virtual void on_init_pager( milk::milk_spinboard_pager& pager  );
	virtual const milk::milk_bubble_metrics &get_bubble_metrics() const;
private:
    
  	surf::surf_image_ptr	m_dialog_gradient;
	surf::surf_image_ptr	m_dialog_pattern;
	surf::surf_9way_image_ptr	m_dialog_frame;
	surf::surf_9way_image_ptr	m_dialog_left_place;
	surf::surf_9way_image_ptr	m_dialog_right_place;
	surf::surf_font_ptr	m_dialog_title_font;
	surf::surf_font_ptr	m_counter_font;
	surf::surf_image_ptr	m_congratulation_dialog_bg;
	
	surf::surf_9way_image_ptr	m_separator_v_fade;
	surf::surf_9way_image_ptr	m_separator_h_fade;
	surf::surf_9way_image_ptr	m_separator_v_clear;
	surf::surf_9way_image_ptr	m_separator_h_clear;
	
	surf::surf_9way_image_ptr	m_caption_bevel;
	surf::surf_9way_image_ptr	m_tab_inactive_bevel;
	surf::surf_9way_image_ptr	m_caption_counter;
	surf::surf_9way_image_ptr	m_content_bevel;
	surf::surf_9way_image_ptr	m_figure_content_bevel;
	
 	surf::surf_9way_image_ptr			m_bubble_mask;
	surf::surf_9way_image_ptr			m_bubble_frame;
	surf::surf_image_ptr				m_bubble_brush;
	surf::surf_image_ptr				m_bubble_tail;
	
	struct pattern_button {
		surf::surf_image_ptr brush;
		surf::surf_9way_image_ptr mask;
		surf::surf_9way_image_ptr glass;
	};
	
	pattern_button	m_btn_gift_normal;
	pattern_button	m_btn_gift_pressed;
    pattern_button  m_btn_received_normal;
    pattern_button  m_btn_received_pressed;
	pattern_button	m_btn_gift_gray_normal;
	pattern_button	m_btn_gift_gray_pressed;
	bool load_pattern_button( pattern_button& btn ,
							 const layout_strings& brush,
							 const layout_strings& mask,
							 const layout_strings& glass,
							 const slice_offsets& offsets);
	void draw_pattern_button( const surf::surf_context_ptr& ctx,pattern_button& btn, const surf::surf_rect& r );
	
	sqc_window_factory_ctx_ptr		m_windows_ctx;
	bool preload();
	
	milk::milk_label_ptr create_title_label( milk::milk_dialog& dlg, const milk::milk_dialog_init_arg& init_arg, const surf::surf_string& str, surf::surf_val left );
	surf::surf_val calc_title_left(  milk::milk_dialog& dlg, milk::milk_dialog_draw_arg const &draw_arg );
	surf::surf_val calc_title_right(  milk::milk_dialog& dlg, milk::milk_dialog_draw_arg const &draw_arg );
	static void on_tab_activated( const milk::milk_bevel_ptr& bevel, 
								 const milk::milk_button_ptr& button,
								 const std::vector<milk::milk_button_ptr>& buttons ,
								 const std::vector<milk::milk_bevel_ptr>& other_bevels ,
								 const std::tr1::function<void()>& original );
	
	/// spinboards
	surf::surf_image_ptr	m_spin_left;
	surf::surf_image_ptr	m_spin_right;
	surf::surf_image_ptr	m_spin_left_pressed;
	surf::surf_image_ptr	m_spin_right_pressed;
	surf::surf_image_ptr	m_spin_page_bg;
	surf::surf_font_ptr		m_spin_page_font;
	surf::surf_image_ptr	m_pager_btn;
	surf::surf_image_ptr	m_pager_pressed;
    
    sqc_sound_sample_ptr    m_sample_close;
    sqc_sound_sample_ptr    m_sample_open;
};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_FRAMEWORK_H_INCLUDED__


