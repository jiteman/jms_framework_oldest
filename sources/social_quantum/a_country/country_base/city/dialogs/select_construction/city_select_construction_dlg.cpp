/*
 *  city_select_construction_dlg.cpp
 *  aCountry
 *
 *  Created by paul on 10/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_select_construction_dlg.h"
#include "country_base/dialogs/controls/sqc_proxy_texture_widget.h"
#include "city/city_framework.h"
#include "city_select_construction_cell.h"


NAMESPACE_SQC_FRAMEWORK

//
// city_select_construction_dlg implementation
//

void city_select_construction_dlg::on_init_dialog() {
    PROFILE_ENTRY( "city_select_construction_dlg::on_init_dialog" );
    
	sqc_dialog_with_close::on_init_dialog();

	if ( !m_delegate ) {
    	sqc_assert( false );
        return;
    }
    
    m_delegate->get_constructions( m_constructions );
    
	sqc_window_factory& factory = framework().windows_factory();

	using namespace city_dlg_layout::select_construction_dlg;
	
	// create dialog title
	{
		set_caption( m_delegate->get_dialog_caption() );
	}
	
	create_separator( shared_from_this(),separator_h1);
	// create item bevel
	factory.create_bevel( m_window_ctx, shared_from_this(), item_bevel );
	
    // create material image
    {
        sqc_proxy_texture_widget_ptr ptr_image = 
        factory.create_child<sqc_proxy_texture_widget>( 
                                                       m_window_ctx, shared_from_this(),
                                                       material_image_rects,
                                                       material_image_alignment );
        
        if ( ptr_image ) {
            ptr_image->set_texture( m_delegate->get_dialog_item_image() );
        }
    }
        
    // create material name label
    {
        milk::milk_label_ptr  ptr_label = 
        factory.create_label( m_window_ctx, shared_from_this(), material_name_label );
        ptr_label->set_caption( m_delegate->get_dialog_item_name() );
    }
    
    // create description text
    {
	    milk::milk_label_ptr  ptr_label = 
	    factory.create_label( m_window_ctx, shared_from_this(), descr_name_label );
        ptr_label->set_caption( m_delegate->get_dialog_item_descr() );
    }
    
    //create spinboard
    m_spinboard = factory.create_spinboard( m_window_ctx, 
                                           shared_from_this(), 
                                           construction_spinboard, 
                                           this );
	/// create pager
    factory.create_spinboard_pager( m_window_ctx, shared_from_this(), m_spinboard,  construction_spinboard_pager );   
    // set cell count
    int cell_count = ( ( sqc_theme_large == factory.get_theme_size() ) ? 5 : 3 );
    m_spinboard->set_visible_count( cell_count );
}	

milk::milk_widget_ptr city_select_construction_dlg::create_cell(
	int idx, surf::surf_rect const &rect ) {

	PROFILE_ENTRY( "city_select_construction_dlg::create_cell" );
        
    if ( idx < 0 || idx >= m_constructions.size() ) {
    	sqc_assert( false );
    	return milk::milk_widget_ptr();	
    }
    
    sqc_assert( m_spinboard );
    
    // add cell object to spinboard
    city_select_construction_cell_ptr ptr_cell = 
        m_spinboard->create_child<city_select_construction_cell>( rect, m_constructions[idx] );
    
    if ( !ptr_cell ) {
        return milk::milk_widget_ptr();
    }
    
    ptr_cell->layout_controls( m_window_ctx );
    
    ptr_cell->set_apply_callbacks(
		std::tr1::bind( &city_select_construction_dlg::on_apply_pressed, this, std::tr1::placeholders::_1 ) );
    
    return ptr_cell;

}

int city_select_construction_dlg::get_cell_count() {
	return m_constructions.size();
}

void city_select_construction_dlg::on_apply_pressed( const sqc_construction_ptr construction ) {

	if ( m_delegate ) { 
    	bool res = m_delegate->on_select_construction( construction );
        if ( res ) {
            get_server().close_modals( 
                std::tr1::static_pointer_cast<milk::milk_dialog>( shared_from_this() ) );
        }
    }
}

bool city_select_construction_dlg::get_dialog_init_arg( milk::milk_dialog_init_arg& a ) {

	sqc_window_factory& factory = framework().windows_factory();
	static const int offsets[] = {20,20*2,28};
	a.bevel_bottom = offsets[factory.get_theme_size()]-city_dlg_layout::content_offset_btm[factory.get_theme_size()];
    
	return sqc_dialog_with_close::get_dialog_init_arg(a);
}

END_NAMESPACE_SQC_FRAMEWORK