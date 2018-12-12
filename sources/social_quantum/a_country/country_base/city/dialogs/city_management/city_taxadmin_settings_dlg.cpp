/*
 *  city_taxadmin_settings_dlg.cpp
 *  aCountry dialog implementation
 *
 *  Created by Bacil on 15.08.2011.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "city_taxadmin_settings_dlg.h"


NAMESPACE_SQC_FRAMEWORK

struct tax_admin_options {
	tax_admin_options(int c, int p, int r)
    	: coins(c), pop(p), rel(r)
    {}
	int coins;
    int pop;
    int rel;
};

static const tax_admin_options tax_admin_options_list[] = {
	tax_admin_options(-15, 7, -7),
	tax_admin_options(-10, 5, -5),
	tax_admin_options(-5, 2, -2),
	tax_admin_options(0, 0, 0),
	tax_admin_options(5, -2, 2),
	tax_admin_options(10, -5, 5),
	tax_admin_options(15, -7, 7)
};

using namespace city_dlg_layout;
using namespace std::tr1::placeholders;

void city_taxadmin_settings_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_taxadmin_settings_dlg::on_init_dialog" );
    
    sqc_dialog_with_close::on_init_dialog();

	sqc_assert( m_delegate );
        
	/// dialog title
	set_caption(framework().strings().load( 
										   taxadmin_settings_dlg::dialog_title.resource_id(), taxadmin_settings_dlg::dialog_title.def_value() ));
	
	
	
    m_factory.create_image( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::img_icon );
	m_factory.create_label( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::lbl_description );
	m_lbl_population = m_factory.create_label( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::lbl_population_value );
    
    m_factory.create_image( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::img_big_coins );
    m_factory.create_image( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::img_small_coins );

    m_factory.create_image( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::img_high_population );
    m_factory.create_image( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::img_low_population );
    

    m_slider = m_factory.create_child<sqc_slider>(
    	m_window_ctx,
    	shared_from_this(), 
		taxadmin_settings_dlg::rct_slider,
		taxadmin_settings_dlg::alg_slider
    );
    

	int init_slider_pos = -1;
    {
    	sqc_int tax_rate = m_delegate->get_tax_rate();
		for( int i=0; i < sizeof(tax_admin_options_list)/sizeof(tax_admin_options_list[0]); ++i ) {
        	tax_admin_options opt = tax_admin_options_list[i];
            if ( opt.coins == tax_rate ) {
        		init_slider_pos = i;
                break;    	
            }
        }
        
        if ( -1 == init_slider_pos ) {
        	sqc_assert( false );
            init_slider_pos = 3;
        }
    }
    
    // set up slider
    m_slider->set_min(0);
    m_slider->set_max(6);
    m_slider->set_step(1);
    m_slider->set_pos( init_slider_pos );

    m_slider->layout_controls(m_window_ctx);
    m_slider->set_on_change( std::tr1::bind( &city_taxadmin_settings_dlg::on_slider_change, this, _1) );
    
    surf::surf_rect rect(
        taxadmin_settings_dlg::lbl_slider_value.rects().at(
            m_factory.get_theme_size()
        )
    );

    layout_font_size font_size = taxadmin_settings_dlg::lbl_slider_value.fnt_layout().sizes().at( m_factory.get_theme_size() );
    layout_font_name font_name = taxadmin_settings_dlg::lbl_slider_value.fnt_layout().names().at( m_factory.get_theme_size() );

    for( int i=0; i < sizeof(tax_admin_options_list)/sizeof(tax_admin_options_list[0]); ++i)
	{
        
        milk::milk_label_ptr label_up = 
			m_factory.create_label(
            	m_window_ctx, 
				shared_from_this(),
                taxadmin_settings_dlg::lbl_slider_value
            );	

        sqc_string s = format("%s%d%%", tax_admin_options_list[i].coins > 0 ? "+" : "", tax_admin_options_list[i].coins );
        label_up->set_caption( s );

        // calculate font draw size in px
        surf::surf_font_ptr font = m_window_ctx->create_font( font_size, font_name.c_str() );
        
        sqc_assert(font);
        
        surf::surf_context_ptr ctx;
		surf::surf_size lsize = font->calc_size( ctx, s, surf::surf_size(1024, 1024),
        	surf::draw_string_alignment_left | surf::draw_string_valignment_center );

        // begin + pos_to_x(i)
        int posx = m_slider->pos_to_x(i);
        rect.x = m_slider->get_rect().x + posx - lsize.cx/2;
        rect.cx = lsize.cx+1;
        rect.cy = lsize.cy+1;
        rect.y = taxadmin_settings_dlg::labels_up[ m_factory.get_theme_size() ];

        label_up->set_rect( rect );

    	milk::milk_label_ptr label_bottom = 
        	m_factory.create_label( 
            	m_window_ctx, 
            	shared_from_this(), taxadmin_settings_dlg::lbl_slider_value
            );	
		s = format( "%s%d%%", tax_admin_options_list[i].pop > 0 ? "+" : "", tax_admin_options_list[i].pop );
        label_bottom->set_caption( s );
        
		lsize = font->calc_size( ctx, s, surf::surf_size(1024, 1024),
        	surf::draw_string_alignment_left | surf::draw_string_valignment_center );

        rect.cx = lsize.cx+1;
        rect.cy = lsize.cy+1;
        rect.y = taxadmin_settings_dlg::labels_bottom[ m_factory.get_theme_size() ];

        label_bottom->set_rect( rect );
    }
    
    
    int quot = tax_admin_options_list[init_slider_pos].rel;
    float v = m_delegate->get_max_population() * 1. / (100 + quot) * 100;
    m_base_max_pop_value = round(v);
    
    m_lbl_population->set_caption(
    	format(
            framework().strings().load( 
                taxadmin_settings_dlg::str_pop_limit.resource_id(),
                taxadmin_settings_dlg::str_pop_limit.def_value()
            ),
            round(m_base_max_pop_value)
        )
    );
    
    milk::milk_button_ptr b_ok = 
    	m_factory.create_button( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::btn_ok );
    m_factory.create_label( m_window_ctx, shared_from_this(), taxadmin_settings_dlg::lbl_ok );
    b_ok->set_action( std::tr1::bind( &city_taxadmin_settings_dlg::on_ok, this) );


}


void city_taxadmin_settings_dlg::on_slider_change(float p)
{
	float quot = tax_admin_options_list[ int(p) ].rel / 100.;		
	float v = m_base_max_pop_value - (m_base_max_pop_value * quot);

    m_lbl_population->set_caption(
    	format(
            framework().strings().load( 
                taxadmin_settings_dlg::str_pop_limit.resource_id(),
                taxadmin_settings_dlg::str_pop_limit.def_value()
            ),
            round(v)
        )
    );
}


void city_taxadmin_settings_dlg::on_ok()
{
	if ( !m_slider || !m_delegate ) {
    	assert( false );
    	return;
    }
    
    
	int pos = m_slider->pos();
    if ( pos < 0 || pos >= sizeof(tax_admin_options_list)/sizeof(tax_admin_options_list[0]) ) {
    	assert( false );
    	return;
    } 
    
	tax_admin_options opt = tax_admin_options_list[pos];
    m_delegate->set_tax_rate( opt.coins );
    
    // close dialog
    end_dialog();
}


END_NAMESPACE_SQC_FRAMEWORK

