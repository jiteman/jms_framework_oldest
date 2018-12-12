/*
 *  city_friends_panel.h
 *  aCountry
 *
 *  Created by Василий on 29.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_CITY_FRIENDS_PANEL_DLG_H_INCLUDED__
#define __SQC_CITY_FRIENDS_PANEL_DLG_H_INCLUDED__

#include "city/dialogs/city_base_dlg.h"
#include "city_friends_panel_dlg_delegate.h"
#include "country_base/dialogs/controls/sqc_proxy_texture_widget.h"

NAMESPACE_SQC_FRAMEWORK


/// Class for 
//typedef template std::tr1::function<void()> callback_type;

class friend_cell : public milk::milk_widget {
public:
	friend_cell(milk::milk_widget_ptr p, sqc_window_factory_ctx_ptr wctx);
    void set_user_id(sqc_string uid);
    
    void set_avatar(sqc_string url);
    
    void set_level(int level);

    void set_name(sqc_string s);
    
    void set_window_ctx(sqc_window_factory_ctx_ptr wctx) {
    	m_window_ctx = wctx;
    }

    void set_push_control();
    
    void on_create();
    
    void set_action(milk::milk_callback action);
    void fit_to_parent();
    
private:
	
    sqc_string m_uid;
    sqc_string m_url;
    int m_level;
    milk::milk_widget_ptr m_parent;
    surf::surf_rect m_avatar_rect;
    sqc_proxy_texture_widget_ptr m_avatar;
	milk::milk_image_ptr m_img_test;
	milk::milk_image_button_ptr m_push_control;
    sqc_window_factory_ctx_ptr m_window_ctx;
    milk::milk_callback m_action;
};

typedef std::tr1::shared_ptr<friend_cell> friend_cell_ptr;



class test_widget : public milk::milk_widget {

public:

	test_widget(milk::milk_widget_ptr p)
    	: milk_widget(p)
	{
    }
    
    bool on_touch( milk::milk_touch_info const &touch )
    {
    	return true;
    }

private:

};

typedef std::tr1::shared_ptr<test_widget> test_widget_ptr;



enum view_mode_t {
    VM_EXPAND,
    VM_COLLAPSE
};

class city_friends_panel_dlg : public milk::milk_widget, public milk::milk_spinboard_callbacks 
{
public:
	city_friends_panel_dlg( milk::milk_widget_ptr p, city_friends_panel_dlg_delegate * delegate, sqc_window_factory_ctx_ptr window_ctx);

	void on_press( int v );

	//dialog has two modes collapse / expand
    void layout_controls();
  	void layout_controls_collapse();
    
    milk::milk_widget_ptr create_cell( int idx, surf::surf_rect const &rect );
    int get_cell_count();
	
    bool on_touch( milk::milk_touch_info const &touch ) {
    	return true;
    }
    
    void set_current_user();
    void on_destroy();
    
    sqc_string current_avatar;
	sqc_string current_name;
    
    bool layouted() {
    	return m_layouted;
    }
    
    
    void set_window_ctx(sqc_window_factory_ctx_ptr wcx) {
    	m_window_ctx = wcx;
    }
    
    void set_view_mode(view_mode_t vm) {
    	m_view_mode = vm;
    }
    
    view_mode_t view_mode() {
    	return m_view_mode;
    }

    surf::surf_rect default_rect_view();
    surf::surf_rect hide_rect_view();
    
private:
	void on_hide();
    void on_show();
    
    int hide_button_offset();
    void create_current_user(milk::milk_widget_ptr p);
	surf::surf_rect rect_background();
	spinboard_layout layout_spinboard(milk::milk_widget_ptr p);
    milk::milk_slice_image_ptr create_background();
    
	city_friends_panel_dlg_delegate * m_pdelegate;


    
    milk::milk_spinboard_ptr m_spinboard;
	milk::milk_slice_image_ptr m_background;
    
    sqc_window_factory_ctx_ptr m_window_ctx;
    friend_cell_ptr m_current;
    milk::milk_image_button_ptr m_hide_button;
    bool m_layouted; // TODO  remove it
    
    view_mode_t m_view_mode;
	milk::milk_image_button_ptr	m_exp_button;
};

typedef std::tr1::shared_ptr<city_friends_panel_dlg> city_friends_panel_dlg_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif

