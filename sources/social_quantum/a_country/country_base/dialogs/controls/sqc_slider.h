/*
 *  sqc_slider.h
 *  aCountry dialog header
 *
 *  Created by Bacil (albacil@gmail.com) on 16.08.2011.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_SQC_SLIDER_H_INCLUDED__
#define __SQC_SQC_SLIDER_H_INCLUDED__

#include "framework/layout/sqc_layout_defs.h"
#include "surf_9way_image.h"

NAMESPACE_SQC_FRAMEWORK

typedef std::tr1::function<void(float)> on_change;
typedef std::tr1::function<void(int n, float p, int x)> on_draw_label;

class sqc_slider : public milk::milk_widget {

public:
	sqc_slider(milk::milk_widget_ptr p);
    void layout_controls( sqc_window_factory_ctx_ptr window_ctx);
	bool is_pressed() const;
    void render( surf::surf_context_ptr ctx );
    bool on_touch( milk::milk_touch_info const &info );
    
    surf::surf_val x_to_pos(int x);
    surf::surf_val pos_to_x(float pos);
    float pos();
    
    
    void set_pos(float p);
    
    void set_min(int min);
    int min();
    
    void set_max(int max);
    int max();
    
    //void set_step(int step, on_draw_label cb);
	void set_step(int step);
    
    void set_on_change(on_change cb);
    
    static double round(double r);
    
    surf::surf_rect gutter_rect();

private:
	bool m_pressed;
    sqc_window_factory & m_factory;
    surf::surf_image_ptr  m_normal_image;
    surf::surf_image_ptr  m_pressed_image;
    milk::milk_slice_image_ptr m_gutter_image;
    sqc_theme_size m_theme_size;
    surf::surf_val m_touchx;
    surf::surf_val m_dtouchx;
    surf::surf_val m_pinx;
    surf::surf_9way_image_ptr m_img_gutter_ptr;
    int m_max;
    int m_min;
    surf::surf_val m_pos;
    int m_step;
    on_change m_on_change;
};

typedef std::tr1::shared_ptr<sqc_slider> sqc_slider_ptr;

END_NAMESPACE_SQC_FRAMEWORK
#endif
