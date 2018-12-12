/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_windows_factory.h"
#include "framework/sqc_framework.h"

NAMESPACE_SQC_FRAMEWORK

/// silent "declared, but not used" for statics in header
void sqc_layout_warnings_silent_function() {
    (void)layout_alignment_center_top;
    (void)layout_alignment_center_top;
    (void)layout_alignment_top;
    (void)layout_alignment_right_top;
    (void)layout_alignment_left_center;
    (void)layout_alignment_left;
    (void)layout_alignment_center_center;
    (void)layout_alignment_center;
    (void)layout_alignment_right_center;
    (void)layout_alignment_right;
    (void)layout_alignment_left_bottom;
    (void)layout_alignment_center_bottom;
    (void)layout_alignment_bottom;
    (void)layout_alignment_right_bottom;
    (void)layout_alignment_left_fill;
    (void)layout_alignment_right_fill;
    (void)layout_alignment_fill;
}

//
// sqc_window factory_context implementation (cache images, etc)
//
sqc_window_factory_ctx::sqc_window_factory_ctx( 
    surf::surf_graphics_server& graphics )
    : m_graphics( graphics )
    , m_stat_image_calls( 0 )
    , m_stat_image_cached( 0 )
    , m_stat_font_calls( 0 )
    , m_stat_font_cached( 0 ) {
}

sqc_window_factory_ctx::~sqc_window_factory_ctx() {
    sqc_info() 
        << "window factory: images: "
        << m_stat_image_calls
        << "/"
        << m_stat_image_cached
        << " fonts: "
        << m_stat_font_calls
        << ""
        << m_stat_font_cached;

}

// create or reuse image
surf::surf_image_ptr sqc_window_factory_ctx::create_image(
    const sqc_string& image_path ) {
    if (image_path.empty()) return surf::surf_image_ptr();
    m_stat_image_calls++;
    
    map_image::iterator it = m_images.find( image_path );
    if ( m_images.end() != it ) {
        m_stat_image_cached++;
        return it->second;
    }
    
    surf::surf_image_ptr ptr_new_image = m_graphics.create_image( image_path.c_str() );
    m_images[image_path] = ptr_new_image;
    
    return ptr_new_image;
}


// create or reuse font
surf::surf_font_ptr sqc_window_factory_ctx::create_font(
    surf::surf_val face_size, 
    const sqc_string&  face_name ) {
    
    m_stat_font_calls++;
    
    font_cache cache( face_size, face_name );
    
    map_font::iterator it = m_fonts.find( cache );
    if ( m_fonts.end() != it ) {
        m_stat_font_cached++;
        return it->second;
    }
    
    surf::surf_font_ptr ptr_new_font = m_graphics.create_font( face_size, face_name.c_str() );
    m_fonts[cache] = ptr_new_font;
    
    return ptr_new_font;
}


//
// sqc_window factory implementation
//

// init factory
void sqc_window_factory::init_factory( int cx, int cy ) {
    milk::milk_window_server& windows = framework().windows();
    
    m_theme = sqc_theme_small;
    const milk::milk_desktop_ptr ptr_desktop = windows.get_desktop();
    if ( ptr_desktop ) {
        
        surf::surf_rect rc = ptr_desktop->get_client_rect();
        
        std::stringstream dimension;
        dimension 
            << " width=" << rc.cx
            << " height=" << rc.cy;
        
        if ( rc.cx >= themes_size::large::width && 
            rc.cy >= themes_size::large::height ) {
            
            m_theme = sqc_theme_large;
        }
        else if ( rc.cx >= themes_size::normal::width && 
                 rc.cy >= themes_size::normal::height ) {
            
            m_theme = sqc_theme_normal;
        }
        else if ( rc.cx >= themes_size::small::width && 
                 rc.cy >= themes_size::small::height ) {
            
            m_theme = sqc_theme_small;
        } else {
            
            sqc_error() 
                << "Unsupported resolution:"
                << dimension.str();
        }
        
        sqc_info() 
            << "Select " << print_theme_size_name( m_theme )
            << dimension.str();
        
    }
}

// return current theme size
sqc_theme_size sqc_window_factory::get_theme_size() const {
    return m_theme;
}

// create window context
sqc_window_factory_ctx_ptr sqc_window_factory::create_window_ctx()  {
    return sqc_window_factory_ctx_ptr( new sqc_window_factory_ctx( m_graphics ) );
} 


// create label by layout
milk::milk_label_ptr sqc_window_factory::create_label(
    sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
	milk::milk_widget_ptr parent, 
	const label_layout& layout ) {
	
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
									 layout.rects().at( theme_size ), 
									 layout.get_alignments().at( theme_size ) );
				
	milk::milk_label_ptr label =
		parent->create_child<milk::milk_label>( rc );
	
	// create corresponding font
	{
		const font_layout& fnt_layout = layout.fnt_layout();
		
		const layout_font_name& font_name	= fnt_layout.names().at( theme_size );
		const layout_font_size font_size	= fnt_layout.sizes().at( theme_size );
		
		surf::surf_font_ptr font = ptr_wnd_ctx->create_font( font_size, font_name.c_str() );
		if ( font ) {
			label->set_font( font );
		} else {
			sqc_assert( font );
		}
	}

	// set corresponding label draw flags
	{
		const layout_label_draw_flags draw_flags = layout.label_draw_flags();
		if ( draw_flags & surf::draw_string_alignment_mask ) {
			label->set_horizontal_alignment( draw_flags );
		}
		if ( draw_flags & surf::draw_string_valignment_mask ) {
			label->set_vertical_alignment( draw_flags );
		}
		if ( draw_flags & surf::draw_string_lines_mask ) {
			label->set_multiline_enabled( draw_flags );
		}
		if ( draw_flags & surf::draw_string_truncation_mask ) {
			label->set_truncation_mode( draw_flags );
		}
		if ( (draw_flags & surf::draw_string_draw_shadow_mask)==surf::draw_string_draw_shadow_enabled ) {
			label->set_shadow_color( surf::surf_color(layout.shadow_color().r(),
													  layout.shadow_color().g(),
													  layout.shadow_color().b(),
													  layout.shadow_color().a()));
			label->set_shadow_size( surf::surf_size( layout.shadow_offsets().at( theme_size ).x,layout.shadow_offsets().at( theme_size ).y ) );
			label->set_draw_shadow_enabled( true );
		} /*
		if ( draw_flags & surf::draw_string_adjust_font_size_mask ) {
			label->set_horizontal_alignment( draw_flags );
		}*/
	}
    
    //set color 
    label->set_color( surf::surf_color( 
                             layout.color().r(),
                             layout.color().g(), 
                             layout.color().b(),
                             layout.color().a() ) );
	
	// set caption
    if ( layout.string_resource().resource_id().length() ) { 
        label->set_caption( framework().strings().load( 
                                layout.string_resource().resource_id(),
                                layout.string_resource().def_value() ) );
    }

	return label;
}

// create image by layout
milk::milk_image_ptr sqc_window_factory::create_image( 
    sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
	milk::milk_widget_ptr parent, 
	const image_layout& layout )
{    
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_image_ptr();
    }

	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
									 layout.rects().at( theme_size ), 
									 layout.get_alignments().at( theme_size ) );
	
	milk::milk_image_ptr image = 
	parent->create_child<milk::milk_image>( rc );
	
	// load image
	image->set_image( ptr_wnd_ctx->create_image( layout.names().at( theme_size ).c_str() ) );
	
	return image;
}

// Slice image product
milk::milk_slice_image_ptr sqc_window_factory::create_slice_image(
	sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
    milk::milk_widget_ptr parent,
    const slice_image_layout& layout )
{
    
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_slice_image_ptr();
    }

	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// take rectangle relative to the parent
	surf::surf_rect rc = layout_child_rect( parent, 
        layout.rects().at( theme_size ), 
        layout.alignment() );
	
    surf::surf_9way_info gutter_info( layout.offsets().at(m_theme) );
	surf::surf_9way_image_ptr img_gutter_ptr(new surf::surf_9way_image() );
	img_gutter_ptr->create( 
		layout.names().at(m_theme).c_str(),
		gutter_info,
		framework().graphics()
    );

	milk::milk_slice_image_ptr image = 
		parent->create_child<milk::milk_slice_image>( rc );
	
    image->set_image( img_gutter_ptr );
	
	return image;
}

// create background by layout
milk::milk_image_ptr sqc_window_factory::create_background( 
    sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
	milk::milk_widget_ptr parent, 
	const dialog_backgrounds& layout ) {
	
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_image_ptr();
    }
    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	surf::surf_rect rect_background = parent->get_client_rect();
	
	surf::surf_string file = layout.at( theme_size );
	if (file.empty()) return milk::milk_image_ptr();
	
	milk::milk_image_ptr image = 
		parent->create_child<milk::milk_image>( rect_background );
	
	// load image
	image->set_image( ptr_wnd_ctx->create_image( file ) );
	image->set_stretch( true );
	
	return image;
}

//create Image Button by layout
milk::milk_image_button_ptr	sqc_window_factory::create_button( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                                              milk::milk_widget_ptr parent,
                                                              const image_button_layout& layout )
{	
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_image_button_ptr();
    }
    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
									 layout.rects().at( theme_size ), 
									 layout.get_alignments().at( theme_size ) );
	
	milk::milk_image_button_ptr button = 
	parent->create_child<milk::milk_image_button>( rc );
	
	// image names
	layout_string	str_image = layout.names().at( theme_size );
	layout_string	str_image_on = layout.pressed_names().at( theme_size );
	
	// create images for button
    if ( str_image.length() ) {
        button->set_image( ptr_wnd_ctx->create_image( str_image ) );
    }
    
    if ( str_image_on.length() ) {
        button->set_pressed_image( ptr_wnd_ctx->create_image( str_image_on ) );
    }
	
	return button;
}

//create Three State Image Button by layout
milk::milk_image_button_ptr sqc_window_factory::create_deactivable_button( sqc_window_factory_ctx_ptr &ptr_wnd_ctx,
                                                                          milk::milk_widget_ptr parent,
                                                                          const deactivable_image_button_layout &layout )
{
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_image_button_ptr();
    }
    
	// take current theme size
	const sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	const surf::surf_rect rc = layout_child_rect( parent, layout.rects().at( theme_size ), layout.get_alignments().at( theme_size ) );
	
	milk::milk_image_button_ptr button = parent->create_child< milk::milk_image_button >( rc );
	
	// image names
	const layout_string normal_image_name = layout.names().at( theme_size );
	const layout_string pressed_image_name = layout.pressed_names().at( theme_size );
    const layout_string inactive_image_name = layout.get_inactive_image_names().at( theme_size );
	
	// create images for button
    if ( !normal_image_name.empty() ) {
        button->set_image( ptr_wnd_ctx->create_image( normal_image_name ) );
    }
    
    if ( !pressed_image_name.empty() ) {
        button->set_pressed_image( ptr_wnd_ctx->create_image( pressed_image_name ) );
    }
    
    if ( !inactive_image_name.empty() ) {
        button->set_inactive_image( ptr_wnd_ctx->create_image( inactive_image_name ) );
    }
	
	return button;
}

//create Theme Button
milk::milk_theme_button_ptr sqc_window_factory::create_theme_button(
        sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
        milk::milk_widget_ptr parent, 
        const theme_button_layout& layout )
{
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_theme_button_ptr();
    }
    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
									 layout.rects().at( theme_size ), 
									 layout.alignment() );

	milk::milk_theme_button_ptr button = 
		parent->create_child<milk::milk_theme_button>( rc, layout.type() );


	// image names
		//layout_string	str_image = layout.names().at( theme_size );
		//layout_string	str_image_on = layout.press_names().at( theme_size );
	
	// create images for button
    	//if ( str_image.length() ) {
        	//button->set_image( ptr_wnd_ctx->create_image( str_image.c_str() ) );
    	//}
    
    	//if ( str_image_on.length() ) {
            //button->set_pressed_image( ptr_wnd_ctx->create_image( str_image_on.c_str() ) );
    	//}
	
	return button;
}


// create switch
milk::milk_switch_button_ptr sqc_window_factory::create_switch_button( 
    sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
	milk::milk_widget_ptr parent,
	const switch_button_layout& layout ) {
	
    if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_switch_button_ptr();
    }

    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
									 layout.rects().at( theme_size ), 
									 layout.alignment() );
	
	milk::milk_switch_button_ptr button = 
	parent->create_child<milk::milk_switch_button>( rc );
	
	static const image_names on_images(
			"switch_on",
			"switch_on@2x",
			"switch_on_ipad" );
	
	static const image_names off_images(
			"switch_off",
			"switch_off@2x",
			"switch_off_ipad" );
	
	// image names
	surf::surf_image_ptr on_image = ptr_wnd_ctx->create_image( 
										on_images.at( theme_size ) );

	surf::surf_image_ptr off_image = ptr_wnd_ctx->create_image( 
										off_images.at( theme_size ) );
	
	// on/off text
	static const surf::surf_string	on_text = framework().strings().load( 
									 "*SwitchOnText",
									 "ON" );
	static const surf::surf_string	off_text = framework().strings().load( 
									 "*SwitchOffText",
									 "OFF" );

	// text color
	static const surf::surf_color on_text_color( 1., 1., 1., 1. );
	static const surf::surf_color off_text_color( .5, .5, .5, 1. );
	
	// text shadow color
	static const surf::surf_color on_text_shadow_color( 1., 1., 1., 1. );
	static const surf::surf_color off_text_shadow_color( .5, .5, .5, 1. );
	
	// text shadow size
	static const surf::surf_size on_text_shadow_size( 1, 1 );
	static const surf::surf_size off_text_shadow_size( 1, 1 );
	
	// fonts
	static const font_layout on_font_layout (
		   layout_font_name( "Arial-BoldMT.otf" ), //boldSystemFont
		   layout_font_sizes( 16, 2*16, 16 ) );

	static const font_layout off_font_layout (
			layout_font_name( "Arial-BoldMT.otf" ), //boldSystemFont
			layout_font_sizes( 16, 2*16, 16 ) );
	
	surf::surf_font_ptr on_font = ptr_wnd_ctx->create_font( 
									on_font_layout.sizes().at( theme_size ),
									on_font_layout.names().at( theme_size ) );	

	surf::surf_font_ptr off_font = ptr_wnd_ctx->create_font( 
									off_font_layout.sizes().at( theme_size ),
									off_font_layout.names().at( theme_size ) );	
	
	button->set_on_properties( on_text, 
						   on_image,
						   on_font,
						   on_text_color,
						   on_text_shadow_color,
						   on_text_shadow_size );
	
	button->set_off_properties( off_text, 
							  off_image,
							  off_font,
							  off_text_color,
							  off_text_shadow_color,
							  off_text_shadow_size );
	
	return button;
}


/// bevel
milk::milk_bevel_ptr	sqc_window_factory::create_bevel( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
									 milk::milk_widget_ptr parent,
									 const base_bevel_layout& layout ) {
	if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_bevel_ptr();
    }
	
    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
										   layout.rects().at( theme_size ), 
										   layout.alignment() );
	
	milk::milk_bevel_ptr bevel = 
	parent->create_child<milk::milk_bevel>( rc );
	bevel->set_type( layout.type( ) );
	return bevel;
}

/// separator vertical
milk::milk_separator_ptr	sqc_window_factory::create_separator( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
											   milk::milk_widget_ptr parent,
											   const vertical_separator_layout& layout ) {
	if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_separator_ptr();
    }
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();

	surf::surf_point p = layout_position(parent, 
										   surf::surf_point(layout.get_x().at(theme_size),0), 
										   layout_alignment(layout.alignment().mask()&layout_alignment_hmask));
	p.y = layout_position(parent, 
						  surf::surf_point(0,0), 
						  layout_alignment(layout_valignment_center)).y;
	surf::surf_val l = parent->get_rect().cy - layout.get_bottom().at(theme_size) - layout.get_top().at(theme_size);
	p.y+=int(layout.get_bottom().at(theme_size)/2);
	p.y-=int(layout.get_top().at(theme_size)/2);
	surf::surf_rect rc = surf::surf_rect( p, surf::surf_size(1,1) );
	
	milk::milk_separator_ptr separator = parent->create_child<milk::milk_separator,milk::milk_separator_direction>( rc,milk::milk_separator_direction_vertical );
	separator->set_position( p );
	separator->set_length( l );
	separator->set_type( layout.get_type() );
	return separator;
}
/// separator horizontal
milk::milk_separator_ptr	sqc_window_factory::create_separator( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
											   milk::milk_widget_ptr parent,
											   const horizontal_separator_layout& layout ) {
	if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_separator_ptr();
    }
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	surf::surf_point p = layout_position(parent, 
										 surf::surf_point(0,layout.get_y().at(theme_size)), 
										 layout_alignment(layout.alignment().mask()&layout_alignment_vmask));
	p.x = layout_position(parent, 
						  surf::surf_point(0,0), 
						  layout_alignment(layout_halignment_center)).x;
	p.x+=int(layout.get_left().at(theme_size)/2);
	p.x-=int(layout.get_right().at(theme_size)/2);
	surf::surf_val l = parent->get_rect().cx - layout.get_left().at(theme_size) - layout.get_right().at(theme_size);
	surf::surf_rect rc = surf::surf_rect( p, surf::surf_size(1,1) );
	milk::milk_separator_ptr separator = parent->create_child<milk::milk_separator,milk::milk_separator_direction>( rc,milk::milk_separator_direction_horizontal );
	separator->set_position( p );
	separator->set_length( l );
	separator->set_type( layout.get_type() );
	return separator;
}


/// create spinboard pager
milk::milk_spinboard_pager_ptr sqc_window_factory::create_spinboard_pager( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
													  const milk::milk_widget_ptr& parent,
													  const milk::milk_spinboard_ptr& spinboard,
													  const spinboard_pager_layout& layout ) {
	if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
        return milk::milk_spinboard_pager_ptr();
    }
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
										   layout.rects().at( theme_size ), 
										   layout.alignment().mask() );
	
	milk::milk_spinboard_pager_ptr pager = 
		parent->create_child<milk::milk_spinboard_pager>( rc );
	if (spinboard) {
		pager->bind( spinboard );
		pager->set_pages( spinboard->get_pages_count() );
		pager->set_active_page( spinboard->get_active_page() );
	}
	return pager;
}



// layout widget
void sqc_window_factory::layout_widget(
    const milk::milk_widget_ptr parent,
    milk::milk_widget_ptr widget,
    const layout_alignment& alignment,
    const layout_rects& rects ) {
    
    if ( !parent || !widget ) {
        return;
    }
    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	surf::surf_rect rc = layout_child_rect( parent, 
									 rects.at( theme_size ), 
									 alignment );
    widget->set_rect( rc );
}

milk::milk_progress_bar_ptr
sqc_window_factory::create_progress_bar( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                         milk::milk_widget_ptr parent,
                                         const slice_image_layout& layout )
{
	if ( !ptr_wnd_ctx ) {
        sqc_assert( false );
    }

	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// take rectangle relative to the parent
	surf::surf_rect rc = layout_child_rect( parent, 
        layout.rects().at( theme_size ), 
        layout.alignment() );
	
    surf::surf_9way_info info( layout.offsets().at(theme_size) );
	surf::surf_9way_image_ptr img_band_ptr( new surf::surf_9way_image() );
	img_band_ptr->create( 
		layout.names().at(theme_size).c_str(),
		info,
		framework().graphics()
    );

	milk::milk_progress_bar_ptr progress_bar = 
		parent->create_child<milk::milk_progress_bar>( rc );
	
    progress_bar->set_range(0,100);
    progress_bar->set_pos(0);
    progress_bar->set_image( img_band_ptr );
	
	return progress_bar;
}

// layout child
/// Returns the position and size of the window relative to the parent, 
/// given the alignment and platform resolution
surf::surf_rect sqc_window_factory::layout_child_rects(
    const milk::milk_widget_ptr parent, 
    const layout_rects& rects,
    const layout_alignment alignment ) const {
    
	// take current theme size
	sqc_theme_size theme_size = get_theme_size();
	
	// align rect by parent
	return layout_child_rect( parent, 
                        rects.at( theme_size ), 
                        alignment);
    
}

// layout child
/// Returns the position and size of the window relative to the parent, 
/// given the alignment only
surf::surf_rect sqc_window_factory::layout_child_rect(
	const milk::milk_widget_ptr parent, 
	const surf::surf_rect& child_rect,
	const layout_alignment alignment ) const {

	sqc_assert( parent );
	if ( !parent ) {
		return surf::surf_rect();
	}
	
    const layout_alignment_mask mask = alignment.mask();
    
	surf::surf_rect align_rect = child_rect;
	
	surf::surf_rect parent_rect = parent->get_rect();
	
	if ( layout_halignment_left	& mask ) {
		// do nothing
	} 
	if ( layout_halignment_center & mask ) {
		align_rect.x = int( child_rect.x + ( parent_rect.cx - child_rect.cx ) / 2 );
	} 
	if ( layout_halignment_right & mask ) {
		align_rect.x = parent_rect.cx - child_rect.x;
        if ( !( layout_halignment_no_width & mask ) ) {
            align_rect.x -= child_rect.cx;
        }
	} 
	if ( layout_valignment_top & mask ) {
		align_rect.y = parent_rect.cy - child_rect.y;
        if ( !( layout_valignment_no_height & mask ) ) {
            align_rect.y -= child_rect.cy;
        }
            
	} 
	if ( layout_valignment_bottom & mask ) {
		// do nothing
	} 
	if ( layout_valignment_center & mask ) {
		align_rect.y = int( child_rect.y + ( parent_rect.cy - child_rect.cy ) / 2 );
	}
    if ( layout_halignment_fill & mask ) {
        align_rect.x = child_rect.x;
        align_rect.cx = parent_rect.cx - child_rect.x;
    }
    if ( layout_valignment_fill & mask ) {
        align_rect.y = child_rect.y;
        align_rect.cy = parent_rect.cy - child_rect.y;
    }
    
	return align_rect;
}
surf::surf_point sqc_window_factory::layout_position( const surf::surf_rect& parent_rect, 
								 const surf::surf_point& pos,
								 const layout_alignment alignment ) const {

	const layout_alignment_mask mask = alignment.mask();
    
	surf::surf_point align_point = pos;
	
	if ( layout_halignment_left	& mask ) {
		// do nothing
	} 
	if ( layout_halignment_center & mask ) {
		align_point.x = int( pos.x + ( parent_rect.cx ) / 2 );
	} 
	if ( layout_halignment_right & mask ) {
		align_point.x = parent_rect.cx - pos.x;
	} 
	if ( layout_valignment_top & mask ) {
		align_point.y = parent_rect.cy - pos.y;
  	} 
	if ( layout_valignment_bottom & mask ) {
		// do nothing
	} 
	if ( layout_valignment_center & mask ) {
		align_point.y = int( pos.y + ( parent_rect.cy ) / 2 );
	}
 	return align_point;
}
surf::surf_point sqc_window_factory::layout_position( const milk::milk_widget_ptr parent, 
								const surf::surf_point& pos,
								const layout_alignment alignment ) const {
	sqc_assert( parent );
	if ( !parent ) {
		return surf::surf_point();
	}
	
	surf::surf_rect parent_rect = parent->get_rect();
	return layout_position( parent_rect, pos, alignment );
}

END_NAMESPACE_SQC_FRAMEWORK
