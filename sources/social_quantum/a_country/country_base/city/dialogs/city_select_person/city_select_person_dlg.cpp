/*
 *  city_select_person_dlg.cpp
 *  aCountry
 *
 *  Created by Василий on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "city_select_person_dlg.h"
#include "city_select_person_dlg_layout.h"

NAMESPACE_SQC_FRAMEWORK

using namespace city_dlg_layout;

city_select_person_dlg::city_select_person_dlg( 
    milk::milk_widget_ptr p, sqc_select_preson_delegate_ptr delegate )
	: sqc_select_person_dlg( p, select_person::background, select_person::spinboard, delegate
							, framework().windows_factory().get_theme_size() == sqc_theme_large ? 4 : 3)
{
}

void city_select_person_dlg::on_init_dialog()
{
	sqc_select_person_dlg::on_init_dialog();
    set_caption( framework().strings().load( 
        select_person::dialog_title.resource_id(), 
        select_person::dialog_title.def_value() ) );
	set_bevel_type( milk::milk_bevel_type_content_scroll );
	
	sqc_window_factory& factory = framework().windows_factory();

	factory.create_spinboard_pager( m_window_ctx, shared_from_this(), m_spinboard,  select_person::spinboard_pager );   
}

milk::milk_widget_ptr city_select_person_dlg::create_cell( int idx, surf::surf_rect const &rect )
{
    if ( idx >= person_list().size() ) {
        sqc_assert( false );
        return milk::milk_widget_ptr();
    }
    
    milk::milk_widget_ptr ptr_cell = 
    	m_spinboard->create_child<milk::milk_widget>( rect );

	milk::milk_theme_button_ptr	b = 
	framework().windows_factory().create_button(
		m_window_ctx,
		ptr_cell,
		select_person::btn_pers_bg
    );
    b->set_action( std::tr1::bind( &city_select_person_dlg::on_person_selected, this, person_list()[idx].id ) );
    
	milk::milk_label_ptr name_label = framework().windows_factory().create_label( m_window_ctx, ptr_cell, select_person::lbl_pers_name );
    name_label->set_caption(person_list()[idx].name);

	milk::milk_image_ptr asterisk = framework().windows_factory().create_image( m_window_ctx, b, select_person::img_asterisk );
	
	milk::milk_label_ptr level_label = framework().windows_factory().create_label( m_window_ctx, asterisk, select_person::lbl_pers_level );
    std::stringstream strlevel;
    strlevel << person_list()[idx].level;
    level_label->set_caption(strlevel.str());
    
    layout_rect avatar_rect;
    avatar_rect = framework().windows_factory().layout_child_rect(b,
    	 select_person::rct_ava.at( framework().windows_factory().get_theme_size() ),
         layout_alignment( layout_halignment_center | layout_valignment_center )
    );
    
    create_texture_widget( b, idx, avatar_rect, layout_alignment(layout_halignment_center | layout_valignment_center) );
    
    milk::milk_button_ptr button_hire = 
		framework().windows_factory().create_button(
			m_window_ctx,
            ptr_cell,
			select_person::btn_hire
		);
    button_hire->set_action( std::tr1::bind( &city_select_person_dlg::on_person_selected, this, person_list()[idx].id ) );
    
	milk::milk_label_ptr ptr_label = framework().windows_factory().create_label( m_window_ctx, button_hire, select_person::lbl_hire );
    
    if ( m_delegate ) {
        ptr_label->set_caption( m_delegate->get_button_caption() );
    }

	framework().windows_factory().create_separator( m_window_ctx, ptr_cell, select_person::spinboard_cell_separator );
    
    return ptr_cell;
}

void city_select_person_dlg::on_person_selected( const sqc_string& person_id ) {
    if ( m_delegate ) {
        if ( m_delegate->on_person_select( person_id ) ) {
            end_dialog();
        }
    }
}

bool city_select_person_dlg::get_dialog_init_arg(milk::milk_dialog_init_arg& a) {
    
    sqc_theme_size theme_size = framework().windows_factory().get_theme_size();
    sqc_word height[] = { 19, 38, 29 };
	a.bevel_bottom = height[theme_size];
    
	return sqc_select_person_dlg::get_dialog_init_arg(a);
}

END_NAMESPACE_SQC_FRAMEWORK
