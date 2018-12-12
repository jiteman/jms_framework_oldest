/*
 *  city_friends_panel.cpp
 *  aCountry
 *
 *  Created by Василий on 29.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "city_friends_panel_dlg.h"
#include "city_friends_panel_dlg_layout.h"
#include "city/city_framework.h"

#include "animation/animation_transformer.h"
#include "animation/animation_server.h"
#include "animation/animation_animators.h"

NAMESPACE_SQC_FRAMEWORK

const int CELL_WIDTH = 82;

using namespace city_dlg_layout;

/****************************************************************************/
// friend_cell

friend_cell::friend_cell(milk::milk_widget_ptr p, sqc_window_factory_ctx_ptr wctx)
    : milk_widget(p)
    , m_parent(p)
    , m_avatar_rect(5, 22, 60, 60) //TODO: recalc size for
    , m_window_ctx(wctx)

	{
	}

void friend_cell::set_user_id(sqc_string uid) {
    m_uid = uid;
}

void friend_cell::set_push_control() {
    m_push_control = framework().windows_factory().create_button( m_window_ctx, 
    	shared_from_this(),  friends_panel::img_selected_cell );
    m_push_control->set_rect( get_rect() );
    m_push_control->set_action(m_action);
    
    // test image
    //m_img_test = framework().windows_factory().create_image( m_window_ctx, shared_from_this(),  friends_panel::img_test );
    //m_img_test->set_rect(m_push_control->get_rect());
    //m_img_test->set_stretch(true);
    
}

void friend_cell::set_avatar(sqc_string url)
{
	if (url == "")
        return;
        
    m_url = url;
    
    // create avatar
    m_avatar = 
    	shared_from_this()->create_child<sqc_proxy_texture_widget>(m_avatar_rect);
    
    bool consider_social_network = true;
    m_avatar->set_remote_texture(url, consider_social_network ); 
}

void friend_cell::set_name(sqc_string s)
{
	sqc_assert(m_window_ctx && "not initializate m_window_ctx");
    milk::milk_label_ptr label_name = 
    	framework().windows_factory().create_label( 
                                                    m_window_ctx, 
                                                    shared_from_this(), 
                                                    friends_panel::lbl_name 
                                                  );
	label_name->set_caption( s );
}

void friend_cell::set_level(int level) {
    
    milk::milk_image_ptr level_img = 
    	framework().windows_factory().create_image(
        	m_window_ctx, shared_from_this(),  friends_panel::img_level );

    milk::milk_label_ptr label_name = 
    	framework().windows_factory().create_label( 
            m_window_ctx, 
            level_img, 
            friends_panel::lbl_level 
        );

	std::stringstream l;
    l << level;
    label_name->set_caption( l.str() );
}

void friend_cell::on_create() {
}

void friend_cell::set_action(milk::milk_callback action)
{
	m_action = action;
}

void friend_cell::fit_to_parent()
{
	surf::surf_rect parent_rect( m_parent->get_rect() );
    set_rect( surf::surf_rect(0,0, parent_rect.cx, parent_rect.cy) );
}

/****************************************************************************/
// city_friends_panel_dlg

city_friends_panel_dlg::city_friends_panel_dlg( milk::milk_widget_ptr p, city_friends_panel_dlg_delegate * delegate, sqc_window_factory_ctx_ptr window_ctx)
	: milk::milk_widget(p)
    , m_pdelegate(delegate)
    , m_layouted(false)
    , m_window_ctx(window_ctx)
    , m_view_mode(VM_EXPAND)
{
}

void city_friends_panel_dlg::layout_controls_collapse()
{
    set_rect(surf::surf_rect(0, 0, 500, 500)); // TODO: calculate

    surf::surf_rect button_rect = friends_panel::rct_btnmode.at(sqc_theme_large);
    button_rect.x = hide_button_offset();
    
    //set_rect( surf::surf_rect(hide_button_offset(), 0, button_rect.cx, button_rect.cy) );
    //set_rect( surf::surf_rect(hide_button_offset(), 0, 200, 200) );
    
    m_exp_button = 
		framework().windows_factory().create_button( 
        	m_window_ctx,
            shared_from_this(),
            friends_panel::btn_show
        );

	m_exp_button->set_rect( button_rect );
    //m_exp_button->set_action( &city_friends_panel_dlg::on_show, this );
    //	std::tr1::bind( &city_friends_panel_dlg_delegate::on_expand, m_pdelegate )
    //);
     
    //m_img_test = framework().windows_factory().create_image( m_window_ctx, shared_from_this(),  friends_panel::img_test );
    //m_img_test->set_rect(m_push_control->get_rect());
    //m_img_test->set_stretch(true);
    
    m_layouted = true;
}

void city_friends_panel_dlg::layout_controls()
{

	if (m_background) {
    	m_background->destroy();
    }
    
    if (m_hide_button) {
    	m_hide_button->destroy();
    }

    if (m_exp_button) {
    	m_exp_button->destroy();
    }
	

/*
	if (m_view_mode == VM_COLLAPSE) {
    	//layout_controls_collapse();
        //return;

		view_rect.y = -view_rect.cy + friends_panel::rct_btnmode.at(sqc_theme_large).cy; 
        //surf::surf_rect r(m_dialog->get_rect());
        //r.y = -r.cy + 23;
        //m_dialog->set_rect(r);
        //m_dialog->set_pos_y(r.y);

    }
*/
    set_rect( m_view_mode == VM_EXPAND ? default_rect_view() : hide_rect_view() );
    
	//sqc_info() << "call city_friends_panel_dlg::layout_controls()";
    //sqc_info() << "rects: " << get_rect().x << ", " << get_rect().y << ", " << get_rect().cx << ", " << get_rect().cy;

    
	m_background = create_background();
	m_background->set_rect( rect_background() );

    //sqc_info() << "m_background->rect: " << m_background->get_rect().x << ", " << m_background->get_rect().y << ", " << m_background->get_rect().cx << ", " << m_background->get_rect().cy;

    // create and set up spinboard
    // parent is m_background
    
    m_spinboard = framework().windows_factory().create_spinboard(
        m_window_ctx,
        m_background,
        layout_spinboard(m_background),
        this );

	m_spinboard->set_left_fade(0);
	m_spinboard->set_right_fade(0);
	
	m_spinboard->set_item_spacing( 0 );
	m_spinboard->set_visible_count( get_cell_count() );

    //sqc_info() << "m_spinboard->rect: " << m_spinboard->get_rect().x << ", " << m_spinboard->get_rect().y << ", " << m_spinboard->get_rect().cx << ", " << m_spinboard->get_rect().cy;
    
	set_current_user();

	m_hide_button =
		framework().windows_factory().create_button( m_window_ctx, 
			shared_from_this(), 
            m_view_mode == VM_EXPAND ? friends_panel::btn_hide : friends_panel::btn_show );
            
	surf::surf_rect hbr_d( friends_panel::rct_btnmode.at(sqc_theme_large) ); //hide buton rectangle default

	surf::surf_rect parent_rect( m_background->get_client_rect() );

	surf::surf_rect hide_button_rect(
    	hide_button_offset(), 
        parent_rect.cy + 3,
        hbr_d.cx,
        hbr_d.cy
    );
        
    m_hide_button->set_rect( hide_button_rect );

    m_hide_button->set_action(
		m_view_mode == VM_EXPAND ? 
        	std::tr1::bind( &city_friends_panel_dlg::on_hide, this ) :
            std::tr1::bind( &city_friends_panel_dlg::on_show, this )
	);

	m_layouted = true;

/*
    // test rect
    milk::milk_image_ptr i = framework().windows_factory().create_image( 
        m_window_ctx,
        m_background,
        image_layout(
        	layout_alignment( layout_halignment_left | layout_valignment_bottom ),
            image_names(
                "",
                "",
                "alert_window_bg@iPad"
            ),
            layout_spinboard(m_background).rects()
        )
    );
    i->set_stretch(true);
	i->set_rect(i->get_rect() + surf::surf_rect(0, 50, 0 ,-40));
*/

}

// calculate rectangle background according friends count
surf::surf_rect city_friends_panel_dlg::rect_background()
{
	surf::surf_rect r = friends_panel::rct_main.at(sqc_theme_large);

	int fc = get_cell_count();
	int right = friends_panel::ofs_bg_slice.at(sqc_theme_large).offset_right;
	int left = friends_panel::ofs_bg_slice.at(sqc_theme_large).offset_left;

	r.cx = CELL_WIDTH * fc + right + left;
    return r;
}

// calculate width spinboard relative amount friends
spinboard_layout city_friends_panel_dlg::layout_spinboard(milk::milk_widget_ptr p)
{
	int fc = get_cell_count();

	surf::surf_rect rect( friends_panel::lt_spinboard.rects().at(sqc_theme_large) );
	rect.cx = fc * CELL_WIDTH;
    
	spinboard_layout l(
    	friends_panel::lt_spinboard.alignment(), 
        layout_rects(
        	friends_panel::lt_spinboard.rects().at(sqc_theme_small),
            friends_panel::lt_spinboard.rects().at(sqc_theme_normal),
            rect
        )
    );

    return l;
}

milk::milk_slice_image_ptr city_friends_panel_dlg::create_background()
{
	return framework().windows_factory().create_slice_image(
    	m_window_ctx,
        shared_from_this(),
        friends_panel::slc_background
    );
}

void city_friends_panel_dlg::set_current_user()
{
    milk::milk_image_ptr image = framework().windows_factory().create_image(
        m_window_ctx, m_background, 
        image_layout(
             layout_alignment( layout_halignment_left | layout_valignment_bottom ),
             friends_panel::nm_cell,
             
             friends_panel::rct_current )
        );

    m_current = image->create_child<friend_cell>( surf::surf_rect(), m_window_ctx );
    m_current->fit_to_parent();
    m_current->set_avatar(current_avatar);
    m_current->set_name(current_name);

    //fc->set_avatar("http://cs10933.vkontakte.ru/u2493588/a_0bad7739.jpg");
    //fc->set_name("foobar");
}


void city_friends_panel_dlg::on_destroy()
{
	m_hide_button->destroy();	
}

int city_friends_panel_dlg::hide_button_offset()
{
	return rect_background().cx/2;
}

void city_friends_panel_dlg::on_hide() {
    using namespace sqc::animation;
    framework().windows().animation().add_animator(
    	transform(),
    	animation_animator_sequency()
            .add(
				animation_animator_translate_relative(
                    surf::surf_point(0, -get_rect().cy + friends_panel::rct_btnmode.at(sqc_theme_large).cy),
                    1.0
                )
            )
            .add(
            	animation_animator_event( 
            		std::tr1::bind( &city_friends_panel_dlg_delegate::on_hide, m_pdelegate )
                )
            )
    );
}

void city_friends_panel_dlg::on_show()
{
    using namespace sqc::animation;

	surf::surf_rect r(default_rect_view());
    framework().windows().animation().add_animator(
    	transform(),
    	animation_animator_sequency()
            .add(
				animation_animator_translate(
                	surf::surf_point(0, 0),
                    surf::surf_point(0, default_rect_view().y-hide_rect_view().y),
                    1.0
                )
            )
            .add(
            	animation_animator_event( 
            		std::tr1::bind( &city_friends_panel_dlg_delegate::on_show, m_pdelegate )
                )
            )
    );
}

surf::surf_rect city_friends_panel_dlg::default_rect_view() {
    
    // 0, 0, calc size x bg, static size y bg
    
    surf::surf_rect rbg( rect_background() );
    surf::surf_rect view_rect;
    view_rect.x=0;
    view_rect.y=0;
    view_rect.cy = rbg.cy + rbg.y + friends_panel::rct_btnmode.at(sqc_theme_large).cy;
    view_rect.cx = rbg.cx + rbg.x;
    return view_rect;
}

surf::surf_rect city_friends_panel_dlg::hide_rect_view() {
    
    surf::surf_rect view_rect( default_rect_view() );
    view_rect.y = -view_rect.cy + friends_panel::rct_btnmode.at(sqc_theme_large).cy; 
    return view_rect;
}


/*********************************************************************/
// Methods of spin board

milk::milk_widget_ptr city_friends_panel_dlg::create_cell( int idx, surf::surf_rect const &rect )
{
    milk::milk_widget_ptr cell = 
		m_spinboard->create_child<milk::milk_widget>( rect );
        
	milk::milk_image_ptr image = framework().windows_factory().create_image(m_window_ctx, cell, friends_panel::img_cell);

    friend_cell_ptr fc = image->create_child<friend_cell>( image->get_rect(), m_window_ctx );
    fc->set_window_ctx( m_window_ctx );
    
    if ( idx < m_pdelegate->get_friend_list().size() ) {
    	fc->set_avatar( m_pdelegate->get_friend_list()[idx].url );
        fc->set_name(m_pdelegate->get_friend_list()[idx].name);
        fc->set_action(
			std::tr1::bind( &city_friends_panel_dlg_delegate::on_change_user, m_pdelegate, m_pdelegate->get_friend_list()[idx].userid )
		);
		fc->set_level(m_pdelegate->get_friend_list()[idx].level);
        fc->set_push_control();
        
    }
    else
    {
		milk::milk_image_button_ptr	b = 
        	framework().windows_factory().create_button( m_window_ctx,
														 image, 
                                                         friends_panel::img_add_friends );
        b->set_action( 
        	std::tr1::bind( &city_friends_panel_dlg_delegate::on_add_friend, 
                            m_pdelegate ) );
    }
   	
    return cell;
}

void foo() {

}

int city_friends_panel_dlg::get_cell_count()
{
	return m_pdelegate->get_friend_list().size() + 1;
}
    
END_NAMESPACE_SQC_FRAMEWORK
