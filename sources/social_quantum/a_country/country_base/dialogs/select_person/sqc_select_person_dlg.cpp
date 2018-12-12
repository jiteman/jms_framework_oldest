/*
 *  sqc_select_person_dlg.h
 *  aCountry
 *	The file contains a base class for select people dialog
 *  Created by Vasily Alioshechkin (albacil@gmail.com) on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "sqc_select_person_dlg.h"
using namespace std::tr1::placeholders;


NAMESPACE_SQC_FRAMEWORK

sqc_select_person_dlg::sqc_select_person_dlg( 
    milk::milk_widget_ptr p, 
    const dialog_layout& dialog_layout, 
    const spinboard_layout& spinboard_layout,
    sqc_select_preson_delegate_ptr delegate ,
	int visible_cell)
                                             
	: sqc_dialog( p, dialog_layout, dialog_has_close_button | dialog_has_back_button )
    , m_theme_size( framework().windows_factory().get_theme_size() )
    , m_spinboard_layout(spinboard_layout)
    , m_delegate(delegate)
	, m_visible_count( visible_cell )
{
}

sqc_select_person_dlg::~sqc_select_person_dlg()
{
}
	
void sqc_select_person_dlg::on_init_dialog()
{
	sqc_dialog::on_init_dialog();
	m_spinboard = create_spinboard();
    
    m_delegate->set_persons_ready_callback(
        std::tr1::bind( &sqc_select_person_dlg::on_persons_ready, this ) );

}

milk::milk_spinboard_ptr sqc_select_person_dlg::create_spinboard()
{
	milk::milk_spinboard_ptr s = framework().windows_factory().create_spinboard(
																				m_window_ctx,
																				shared_from_this(),
																				m_spinboard_layout,
																				this );
	
	s->set_visible_count(m_visible_count);
	s->set_item_spacing( 0 );
	return s;
}


int sqc_select_person_dlg::get_cell_count()
{
	return m_person_list.size();
}

sqc_proxy_texture_widget_ptr 
sqc_select_person_dlg::create_texture_widget(
    milk::milk_widget_ptr p, 
    int idx, 
    layout_rect rect, 
    layout_alignment alignment )
{
    sqc_proxy_texture_widget_ptr w = 
    	p->create_child<sqc_proxy_texture_widget>(rect);
	
    if ( idx < 0 || idx >= m_person_list.size() ) 
    {
		sqc_error() << "index " << idx << " is outside the array m_person_list";
        return w;
    }

    bool consider_social_network = true;
    
    if ( m_person_list[idx].local_avatar ) {
	    w->set_local_image( m_person_list[idx].avatar ); 
    } else {
    	w->set_remote_texture( m_person_list[idx].avatar, consider_social_network ); 
    }
    return w;
}

sqc_person_info_list_type& sqc_select_person_dlg::person_list()
{
	return m_person_list;
}

void sqc_select_person_dlg::on_persons_ready()
{
	// update code
    m_delegate->get_persons( person_list() );

    if (m_spinboard) {
        remove_child(m_spinboard);
        m_spinboard = create_spinboard(); 
    }
}

END_NAMESPACE_SQC_FRAMEWORK