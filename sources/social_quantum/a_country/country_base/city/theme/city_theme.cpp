/*
 *  city_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_theme.h"
#include "city/dialogs/city_base_dlg_layout.h"
#include "city/dialogs/city_theme_elements.h"

#include "framework/sqc_framework.h"


#include "animation/animation_transformer.h"
#include "animation/animation_server.h"
#include "animation/animation_animators.h"

NAMESPACE_SQC_FRAMEWORK


static const milk::milk_bubble_metrics city_bubble_metrics[] = {
	// iPhone
	{
		10,		/// left
		10,		/// right
		12,		///	top
		26,		/// bottom
		surf::surf_point(7,0)		///	tail
	},
	// iPhoneHD
	{
		20,		/// left
		20,		/// right
		24,		///	top
		26*2,		/// bottom
		surf::surf_point(14,0)		///	tail
	},
	// iPad
	{
		12,		/// left
		12,		/// right
		14,		///	top
		32,		/// bottom
		surf::surf_point(7,0)		///	tail
	}
};



sqc_city_theme::sqc_city_theme( surf::surf_graphics_server& gs ) 
	: sqc_theme_base( gs ) {
		
		
		
		set_button_def( static_cast<milk::theme_button_type>(city_theme_button_tab), 
					   theme_button_def( 
										image_names("tab_glass_deselect","tab_glass_deselect@2x","tab_glass_deselect_ipad"),
										slice_offsets(slice_offset( 8,8,8,2 ),slice_offset(10,10,10,4),slice_offset(8,8,8,2)) ));
                                        
		set_button_def( static_cast<milk::theme_button_type>(sqc_theme_button_buy), 
					   theme_button_def( 
										image_names("button_green_normal","button_green_normal@2x","button_green_normal_ipad"),
										image_names("button_green_selected","button_green_selected@2x","button_green_selected_ipad"),
										slice_offsets(slice_offset(4,2,4,4, surf::tile_flag_none ),
													  slice_offset(10,8,10,14, surf::tile_flag_none),
													  slice_offset(4,4,4,9, surf::tile_flag_none)) ));
                                                      
        set_button_def( static_cast<milk::theme_button_type>(sqc_theme_button_sell), 
					   theme_button_def( 
										image_names("button_green_normal","button_green_normal@2x","button_green_normal_ipad"),
										image_names("button_green_selected","button_green_selected@2x","button_green_selected_ipad"),
										slice_offsets(slice_offset(4,2,4,4, surf::tile_flag_none ),
													  slice_offset(10,8,10,14, surf::tile_flag_none),
													  slice_offset(4,4,4,9, surf::tile_flag_none)) ));
                                                      
		set_button_def( static_cast<milk::theme_button_type>(sqc_theme_button_buy_gray), 
					   theme_button_def( 
										image_names("button_gray_normal","button_gray_normal@2x","button_gray_normal_ipad"),
										image_names("button_gray_selected","button_gray_selected@2x","button_gray_selected_ipad"),
										slice_offsets(slice_offset(4,2,4,4 , surf::tile_flag_none),
													  slice_offset(10,8,10,14, surf::tile_flag_none),
													  slice_offset(4,4,4,9, surf::tile_flag_none)) ));
                                                      
        set_button_def( static_cast<milk::theme_button_type>(sqc_theme_button_sell_gray), 
					   theme_button_def( 
										image_names("button_gray_normal","button_gray_normal@2x","button_gray_normal_ipad"),
										image_names("button_gray_selected","button_gray_selected@2x","button_gray_selected_ipad"),
										slice_offsets(slice_offset(4,2,4,4 , surf::tile_flag_none),
													  slice_offset(10,8,10,14, surf::tile_flag_none),
													  slice_offset(4,4,4,9, surf::tile_flag_none)) ));
                                                      
		set_button_def( static_cast<milk::theme_button_type>(sqc_theme_button_shop_item), 
					   theme_button_def( 
										image_names("item_back","item_back@2x","item_back_ipad"),
										image_names("gray_item_plate","gray_item_plate@2x","gray_item_plate_ipad"),
										slice_offsets(slice_offset(12,12,12,14 , surf::tile_flag_none),
													  slice_offset(18,18,18,24, surf::tile_flag_none),
													  slice_offset(14,14,14,18, surf::tile_flag_none)) ));
		
		set_button_def( static_cast<milk::theme_button_type>(sqc_theme_button_apply), 
					   theme_button_def( 
										image_names("button_green_normal","button_green_normal@2x","button_green_normal_ipad"),
										image_names("button_green_selected","button_green_selected@2x","button_green_selected_ipad"),
										slice_offsets(slice_offset(4,2,4,4, surf::tile_flag_none ),
													  slice_offset(10,8,10,14, surf::tile_flag_none),
													  slice_offset(4,4,4,9, surf::tile_flag_none)) ));

}

void sqc_city_theme::init_metrics() {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme = factory.get_theme_size();
	
	metrics.spinboard_fade = metrics.spinboard_item_spacing_cx = layout_vals(5,5*2,5).at(theme);
}

bool sqc_city_theme::load_pattern_button( pattern_button& btn ,
						 const layout_strings& brush,
						 const layout_strings& mask,
						 const layout_strings& glass,
						 const slice_offsets& offsets) {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme = factory.get_theme_size();
	btn.brush = graphics().create_image( brush.at(theme).c_str() );
	if (!btn.brush) return false;
	btn.mask = create_9way_image( mask , offsets );
	if (!btn.mask) return false;
	btn.glass = create_9way_image( glass , offsets );
	if (!btn.glass) return false;
	return true;
}

static const font_layout title_font(
									layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
									layout_font_sizes( 17, 2*17, 30 ) );
static const font_layout counter_font(
									layout_font_name( "Arial-BoldMT.otf" ), 
									layout_font_sizes( 12, 12*2, 24 ) );
static const font_layout page_font(
									  layout_font_names( "Arial.otf","Arial.otf","Arial-BoldMT.otf" ), 
									  layout_font_sizes( 11, 11*2, 16 ) );
bool sqc_city_theme::preload() {
	{

        m_sample_close = framework().sound().load_sample("cancel");
        m_sample_open = framework().sound().load_sample("enter");
		
		sqc_window_factory& factory = framework().windows_factory();
		sqc_theme_size theme = factory.get_theme_size();
		
		m_dialog_title_font = graphics().create_font( title_font.sizes().at(theme),title_font.names().at(theme).c_str() );
		m_counter_font = graphics().create_font( counter_font.sizes().at(theme),counter_font.names().at(theme).c_str() );
		m_spin_page_font = graphics().create_font( page_font.sizes().at(theme),page_font.names().at(theme).c_str() );
		
		metrics.separator_size = layout_vals(2,4,4).at(theme);

		static const dialog_backgrounds mask_image( "icity_mask_bubble", 
												   "icity_mask_bubble@2x",
												   "icity_mask_bubble_ipad" );
		
		static const dialog_backgrounds frame_image( "icity_bubble", 
													"icity_bubble@2x",
													"icity_bubble_ipad" );
		
		static const dialog_backgrounds brush_image( "icity_pattern_bubble", 
													"icity_pattern_bubble@2x",
													"icity_pattern_bubble_ipad" );
		
		static const dialog_backgrounds tail_image( "icity_tail_bubble", 
												   "icity_tail_bubble@2x",
												   "icity_tail_bubble_ipad" );
		
		sqc_string brush_name = brush_image.at( theme );
		sqc_string tail_name = tail_image.at( theme );
		{
			static const slice_offsets offsets( slice_offset( 18,33,18,15 ),
											  slice_offset(18*2,33*2,18*2,15*2),
											  slice_offset(20,34,20,14) );
			m_bubble_mask = create_9way_image(mask_image, offsets);
			m_bubble_frame = create_9way_image(frame_image, offsets);
		}
		m_bubble_brush = graphics().create_image( brush_name.c_str() );
		m_bubble_tail = graphics().create_image( tail_name.c_str() );
		
		static const image_names parrern_image( "bg_pattern", 
												   "bg_pattern@2x",
												   "bg_pattern_ipad" );
		sqc_string pattern_name = parrern_image.at( theme );
		static const image_names gradient_image( "bg_gradient", 
													  "bg_gradient@2x",
													  "bg_gradient_ipad" );
		sqc_string gradient_name = gradient_image.at( theme );
		m_dialog_pattern = graphics().create_image( pattern_name.c_str() );
		m_dialog_gradient = graphics().create_image( gradient_name.c_str() );
		m_congratulation_dialog_bg = graphics().create_image("bg_boom" );
	
		{
			static const image_names bg_frame_image( "icity_frame", 
													   "icity_frame@2x",
													   "icity_frame_ipad" );
			static const slice_offsets offsets( slice_offset( 10,10,10,10 ),slice_offset(16,16,16,16),slice_offset(10,10,10,10) );
			m_dialog_frame = create_9way_image(bg_frame_image, offsets, false );
		}
		
		m_separator_v_fade = create_9way_image( image_names("separator_vert_transparent","separator_vert_transparent@2x","separator_vert_transparent_ipad" ),
											   slice_offsets(slice_offset( 0,60,0,60 ),slice_offset(0,60,0,60),slice_offset(0,60,0,60)));
	
		m_separator_h_fade = create_9way_image( image_names("separator_horisont_transparent","separator_horisont_transparent@2x","separator_horisont_transparent_ipad" ),
											   slice_offsets(slice_offset( 60,0,60,0 ),slice_offset(60,0,60,0),slice_offset(60,0,60,0)));
		
		m_separator_v_clear = create_9way_image( image_names("separator_vert","separator_vert@2x","separator_vert_ipad" ),
											   slice_offsets(slice_offset( 0,10,0,10 ),slice_offset(0,10,0,10),slice_offset(0,10,0,10)));
		
		m_separator_h_clear = create_9way_image( image_names("separator_horisont","separator_horisont@2x","separator_horisont_ipad" ),
											   slice_offsets(slice_offset( 10,0,10,0 ),slice_offset(10,0,10,0),slice_offset(10,0,10,0)));
		
		m_caption_bevel = create_9way_image(image_names("tab_glass_selected","tab_glass_selected@2x","tab_glass_selected_ipad"),
											slice_offsets(slice_offset( 8,8,8,2 ),slice_offset(8,8,8,2),slice_offset(8,8,8,2)));
		m_caption_counter = create_9way_image(image_names("tab_mark","tab_mark@2x","tab_mark_ipad"),
											  slice_offsets(slice_offset( 8,8,8,2 ),slice_offset(8,8,8,2),slice_offset(8,8,8,2)));
		{
			static const image_names image( "glass", 
													   "glass@2x",
													   "glass_ipad" );
			static const slice_offsets offsets( slice_offset( 49,49,49,49 ),slice_offset(97,97,97,97),slice_offset(49,49,49,49) );
			m_content_bevel = create_9way_image(image, offsets);
		}
		{
			static const image_names image( "figure_glass", 
										   "figure_glass@2x",
										   "figure_glass_ipad" );
			static const slice_offsets offsets( slice_offset( 49,49,49,49 ),slice_offset(97,97,97,97),slice_offset(49,49,49,49) );
			m_figure_content_bevel = create_9way_image(image, offsets);
		}
		m_dialog_left_place = create_9way_image(image_names( "icity_angles_back", 
															"icity_angles_back@2x",
															"icity_angles_back_ipad" ), slice_offsets(
												slice_offset( 10,10,10,10 ),slice_offset(16,16,16,16),slice_offset(10,10,10,10)));
		m_dialog_right_place = create_9way_image(image_names( "icity_angles_close", 
															"icity_angles_close@2x",
															"icity_angles_close_ipad" ), slice_offsets(
												slice_offset( 10,10,10,10 ),slice_offset(16,16,16,16),slice_offset(10,10,10,10)));
		// gift button
		{
			if (!load_pattern_button(m_btn_gift_normal,
									 image_names( "pattern_gift_normal", 
												 "pattern_gift_normal@2x",
												"pattern_gift_normal_ipad" ),
									 image_names( "mask_gift_normal", 
												 "mask_gift_normal@2x",
												 "mask_gift_normal_ipad" ),
									 image_names( "button_giftshop_normal", 
												 "button_giftshop_normal@2x",
												 "button_giftshop_normal_ipad" ),
									 slice_offsets(
												   slice_offset(4,2,4,4 ),
												   slice_offset(10,8,10,14),
												   slice_offset(4,4,4,9)))) return false;
			if (!load_pattern_button(m_btn_gift_pressed,
									 image_names( "pattern_gift_selected", 
												 "pattern_gift_selected@2x",
												 "pattern_gift_selected_ipad" ),
									 image_names( "mask_gift_selected", 
												 "mask_gift_selected@2x",
												 "mask_gift_selected_ipad" ),
									 image_names( "button_giftshop_selected", 
												 "button_giftshop_selected@2x",
												 "button_giftshop_selected_ipad" ),
									 slice_offsets(
												   slice_offset(4,2,4,4 ),
												   slice_offset(10,8,10,14),
												   slice_offset(4,4,4,9)))) return false;
			if (!load_pattern_button(m_btn_gift_gray_normal,
									 image_names( "pattern_giftgray_normal", 
												 "pattern_giftgray_normal@2x",
												 "pattern_giftgray_normal_ipad" ),
									 image_names( "mask_giftgray_normal", 
												 "mask_giftgray_normal@2x",
												 "mask_giftgray_normal_ipad" ),
									 image_names( "button_giftgray_normal", 
												 "button_giftgray_normal@2x",
												 "button_giftgray_normal_ipad" ),
									 slice_offsets(
												   slice_offset(4,2,4,4 ),
												   slice_offset(10,8,10,14),
												   slice_offset(4,4,4,9)))) return false;
			if (!load_pattern_button(m_btn_gift_gray_pressed,
									 image_names( "pattern_giftgray_selected", 
												 "pattern_giftgray_selected@2x",
												 "pattern_giftgray_selected_ipad" ),
									 image_names( "mask_giftgray_selected", 
												 "mask_giftgray_selected@2x",
												 "mask_giftgray_selected_ipad" ),
									 image_names( "button_giftgray_selected", 
												 "button_giftgray_selected@2x",
												 "button_giftgray_selected_ipad" ),
									 slice_offsets(
												   slice_offset(4,2,4,4 ),
												   slice_offset(10,8,10,14),
												   slice_offset(4,4,4,9)))) return false;
		}
		
		/// spinboard
		{
			m_spin_left = graphics().create_image( image_names("arrow_scroll_left_normal",
															   "arrow_scroll_left_normal@2x",
															   "arrow_scroll_left_normal_ipad").at(theme).c_str() );
			m_spin_right = graphics().create_image( image_names("arrow_scroll_right_normal",
																"arrow_scroll_right_normal@2x",
																"arrow_scroll_right_normal_ipad").at(theme).c_str() );
			m_spin_left_pressed = graphics().create_image( image_names("arrow_scroll_left_selected",
															   "arrow_scroll_left_selected@2x",
															   "arrow_scroll_left_selected_ipad").at(theme).c_str() );
			m_spin_right_pressed = graphics().create_image( image_names("arrow_scroll_right_selected",
																"arrow_scroll_right_selected@2x",
																"arrow_scroll_right_selected_ipad").at(theme).c_str() );
			m_spin_page_bg = graphics().create_image( image_names("page_counter",
																  "page_counter@2x",
																  "page_counter_ipad").at(theme).c_str() );
			
			m_pager_btn = graphics().create_image(image_names("pager_normal",
															  "pager_normal@2x",
															  "pager_normal_ipad").at(theme).c_str());
			m_pager_pressed = graphics().create_image(image_names("pager_selected",
																  "pager_selected@2x",
																  "pager_selected_ipad").at(theme).c_str());
		}
	}
    
    // received button
    {
        if (!load_pattern_button(m_btn_received_normal,
                                 image_names( "pattern_gift_normal", 
                                             "pattern_gift_normal@2x",
                                             "pattern_gift_normal_ipad" ),
                                 image_names( "mask_gift_normal", 
                                             "mask_gift_normal@2x",
                                             "mask_gift_normal_ipad" ),
                                 image_names( "button_giftshop_normal", 
                                             "button_giftshop_normal@2x",
                                             "button_giftshop_normal_ipad" ),
                                 slice_offsets(
                                               slice_offset(4,2,4,4 ),
                                               slice_offset(10,8,10,14),
                                               slice_offset(4,4,4,9)))) return false;
        if (!load_pattern_button(m_btn_received_pressed,
                                 image_names( "pattern_gift_selected", 
                                             "pattern_gift_selected@2x",
                                             "pattern_gift_selected_ipad" ),
                                 image_names( "mask_gift_selected", 
                                             "mask_gift_selected@2x",
                                             "mask_gift_selected_ipad" ),
                                 image_names( "button_giftshop_selected", 
                                             "button_giftshop_selected@2x",
                                             "button_giftshop_selected_ipad" ),
                                 slice_offsets(
                                               slice_offset(4,2,4,4 ),
                                               slice_offset(10,8,10,14),
                                               slice_offset(4,4,4,9)))) return false;
        /*
        if (!load_pattern_button(m_btn_gift_gray_normal,
                                 image_names( "pattern_giftgray_normal", 
                                             "pattern_giftgray_normal@2x",
                                             "pattern_giftgray_normal_ipad" ),
                                 image_names( "mask_giftgray_normal", 
                                             "mask_giftgray_normal@2x",
                                             "mask_giftgray_normal_ipad" ),
                                 image_names( "button_giftgray_normal", 
                                             "button_giftgray_normal@2x",
                                             "button_giftgray_normal_ipad" ),
                                 slice_offsets(
                                               slice_offset(4,2,4,4 ),
                                               slice_offset(10,8,10,14),
                                               slice_offset(4,4,4,9)))) return false;
        if (!load_pattern_button(m_btn_gift_gray_pressed,
                                 image_names( "pattern_giftgray_selected", 
                                             "pattern_giftgray_selected@2x",
                                             "pattern_giftgray_selected_ipad" ),
                                 image_names( "mask_giftgray_selected", 
                                             "mask_giftgray_selected@2x",
                                             "mask_giftgray_selected_ipad" ),
                                 image_names( "button_giftgray_selected", 
                                             "button_giftgray_selected@2x",
                                             "button_giftgray_selected_ipad" ),
                                 slice_offsets(
                                               slice_offset(4,2,4,4 ),
                                               slice_offset(10,8,10,14),
                                               slice_offset(4,4,4,9)))) return false;
         */
    }
	
	
	

    
	return true;
}


static const int title_y_[] = { 8,8*2,11};
static const int title_h_[] = { 44,44*2-1,62};

void sqc_city_theme::draw_dialog( 
	surf::surf_context_ptr ctx, 
    surf::surf_rect const &rect, 
    milk::milk_dialog_draw_arg const &arg ) {
 
	if (!load_all() || !ctx )
		return;
    
   if (arg.type==milk::milk_dialog_type_alert) {
		surf::surf_image_ptr old_brush = ctx->get_brush();
		ctx->set_brush( m_bubble_brush );
		if ( m_bubble_mask )
        	m_bubble_mask->draw( ctx, rect );
		ctx->set_brush( old_brush );
        if ( m_bubble_frame )
			m_bubble_frame->draw( ctx, rect );
   } else if ( arg.type == milk::milk_dialog_type(city_dialog_type_congratulation) ) {
	   ctx->set_brush( m_dialog_pattern, surf::surf_brush_mode_additive );
	   if ( m_congratulation_dialog_bg )
		   m_congratulation_dialog_bg->draw( ctx, rect );
	   ctx->set_brush( surf::surf_image_ptr() );
	   if ( m_dialog_frame )
		   m_dialog_frame->draw( ctx, rect );
	} else {
		ctx->set_brush( m_dialog_pattern, surf::surf_brush_mode_additive );
        if ( m_dialog_gradient )
			m_dialog_gradient->draw( ctx, rect );
		ctx->set_brush( surf::surf_image_ptr() );
        if ( m_dialog_frame )
			m_dialog_frame->draw( ctx, rect );
	}
	if (arg.has_left_button) {
    	if ( m_dialog_left_place )
			m_dialog_left_place->draw( ctx, arg.left_rect );
	}
	if (arg.has_right_button) {
    	if ( m_dialog_right_place )
			m_dialog_right_place->draw( ctx, arg.right_rect );
	}
}



void sqc_city_theme::draw_window( surf::surf_context_ptr ctx, milk::milk_window &w ) {
}

void sqc_city_theme::draw_pattern_button( const surf::surf_context_ptr& ctx,pattern_button& btn, const surf::surf_rect& r ) {
	surf::surf_image_ptr old_brush = ctx->get_brush();
	ctx->set_brush( btn.brush );
    if ( btn.mask )
		btn.mask->draw( ctx, r );
	ctx->set_brush( old_brush );
	btn.glass->draw( ctx, r );
}
void sqc_city_theme::draw_button( surf::surf_context_ptr ctx, milk::milk_theme_button &w ) {
	if (w.get_button_type()==milk::theme_button_type(sqc_theme_button_gift)) {
		if (!load_all()) return;
		if (w.is_pressed() || w.is_checked())
			draw_pattern_button(ctx, m_btn_gift_pressed, w.get_client_rect() );
		else
			draw_pattern_button(ctx, m_btn_gift_normal, w.get_client_rect() );
	} else if (w.get_button_type()==milk::theme_button_type(sqc_theme_button_gift_gray)) {
		if (!load_all()) return;
		if (w.is_pressed() || w.is_checked())
			draw_pattern_button(ctx, m_btn_gift_gray_pressed, w.get_client_rect() );
		else
			draw_pattern_button(ctx, m_btn_gift_gray_normal, w.get_client_rect() );
	}else if (w.get_button_type()==milk::theme_button_type(sqc_theme_button_received)) {
		if (!load_all()) return;
		if (w.is_pressed() || w.is_checked())
			draw_pattern_button(ctx, m_btn_received_pressed, w.get_client_rect() );
		else
			draw_pattern_button(ctx, m_btn_received_normal, w.get_client_rect() );
    }else {
		sqc_theme_base::draw_button(ctx,w);
	}
}

void sqc_city_theme::draw_label( surf::surf_context_ptr ctx, milk::milk_label &w ) {
}

void sqc_city_theme::draw_scroller( surf::surf_context_ptr ctx, milk::milk_scroll_area &w ) {
}

void sqc_city_theme::draw_spinboard( surf::surf_context_ptr ctx, milk::milk_spinboard &w ) {
}

void sqc_city_theme::draw_bubble( surf::surf_context_ptr ctx, surf::surf_rect const &rect, 
								 milk::milk_bubble_draw_arg const &arg ) {
	if (!load_all()) return;
	sqc_window_factory& factory = framework().windows_factory();
	
	if( !m_bubble_frame || !m_bubble_mask || !m_bubble_tail ) {
		return;
	}
	static const layout_vals bottom_offsets( 18, 18*2-3, 20 );
    const surf::surf_val bottom_offset = bottom_offsets.at (factory.get_theme_size());
	surf::surf_rect bubble_rect = surf::surf_rect( rect.x, rect.y+bottom_offset , rect.cx, rect.cy-bottom_offset );
	surf::surf_image_ptr old_brush = ctx->get_brush();
	ctx->set_brush( m_bubble_brush );
	m_bubble_mask->draw( ctx, bubble_rect );
	ctx->set_brush( old_brush );
	m_bubble_frame->draw( ctx, bubble_rect );
	static const layout_vals tail_offsets( -23+7, (-23+7)*2, -23+7 );
	 const surf::surf_val tail_offset = tail_offsets.at (factory.get_theme_size());
	m_bubble_tail->draw( ctx, surf::surf_point( rect.cx/2+tail_offset, rect.y) );	
}

void sqc_city_theme::draw_separator( surf::surf_context_ptr ctx, milk::milk_separator_draw_arg const &arg ) {
	if (!load_all()) return;
	if (arg.direction==milk::milk_separator_direction_horizontal) {
		(arg.type==milk::milk_separator_type_basic ?  m_separator_h_fade : m_separator_h_clear)->
			draw( ctx, surf::surf_rect( arg.center.x - arg.length/2, int(arg.center.y-metrics.separator_size/2), arg.length, metrics.separator_size ));
	} else if (arg.direction==milk::milk_separator_direction_vertical) {
		(arg.type==milk::milk_separator_type_basic ?  m_separator_v_fade : m_separator_v_clear)->
			draw( ctx, surf::surf_rect( int(arg.center.x - metrics.separator_size/2), arg.center.y-arg.length/2, metrics.separator_size, arg.length ));
	}
}

void sqc_city_theme::draw_bevel( surf::surf_context_ptr ctx, surf::surf_rect const &rect, milk::milk_bevel_draw_arg const &arg ) {
	if (!load_all()) return;
	if (arg.type==milk::milk_bevel_type_caption) {
    	if ( m_caption_bevel )
			m_caption_bevel->draw( ctx, rect );
	} else if (arg.type==milk::milk_bevel_type_counter) {
    	if ( m_caption_counter )
			m_caption_counter->draw( ctx, rect );
	}else if (arg.type==milk::milk_bevel_type_content) {
    	if ( m_content_bevel )
			m_content_bevel->draw( ctx, rect );
	} else if (arg.type==milk::milk_bevel_type_content_scroll) {
    	if ( m_figure_content_bevel )
			m_figure_content_bevel->draw( ctx, rect );
	} else if (arg.type==milk::milk_bevel_type(sqc_bevel_type_shop_item)) {
		surf::surf_9way_image_ptr img = get_button_skin( milk::theme_button_type( sqc_theme_button_shop_item), theme_button_def::button_skin_normal);
		if (img) {
			img->draw( ctx, rect );
		}
	} 
}

const milk::milk_bubble_metrics &sqc_city_theme::get_bubble_metrics() const {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size size = factory.get_theme_size();
	return city_bubble_metrics[size];
}

static const surf::surf_draw_string_flags title_draw_flags = 
surf::draw_string_alignment_center|
surf::draw_string_valignment_center|
surf::draw_string_draw_shadow_enabled|
surf::draw_string_truncation_disabled|
surf::draw_string_single_line;

static const surf::surf_val sc_animationValuesScale[]   = { 0.4, 0.6,  1.0, 1.08, 1.1, 0.98, 0.91, 0.92, 0.96, 0.99, 1.0 };
static surf::surf_val show_scale_func( surf::surf_val k ) {
	return sqc::animation::animation_keyframe_func( sc_animationValuesScale, sizeof(sc_animationValuesScale)/sizeof(sc_animationValuesScale[0]), k );
}
static const surf::surf_val sc_animationValuesOpacity[] = { 0.1, 0.15, 0.3, 0.45, 0.5, 0.7,  0.85, 0.9,  0.95, 1.0,  1.0 };
static surf::surf_val show_alpha_func( surf::surf_val k ) {
	return sqc::animation::animation_keyframe_func( sc_animationValuesOpacity, sizeof(sc_animationValuesOpacity)/sizeof(sc_animationValuesOpacity[0]), k );
}


void sqc_city_theme::on_init_dialog( milk::milk_dialog& dlg, milk::milk_dialog_init_arg const &arg , milk::milk_dialog_draw_arg& draw_arg ) {
	if (!load_all()) return;
	sqc_window_factory& factory = framework().windows_factory();
    
    if ( !m_windows_ctx ) {
    	m_windows_ctx = sqc_window_factory_ctx_ptr( 
        			new sqc_window_factory_ctx( graphics() ) );
        if ( !m_windows_ctx ) {
        	return;
        }
    }
	// create close button
	if ( arg.has_close ) {

		milk::milk_image_button_ptr ptr_button = 
		factory.create_button( m_windows_ctx, dlg.shared_from_this(), city_dlg_layout::close_button );
		
		ptr_button->set_action( std::tr1::bind( 
							&milk::milk_dialog::on_close_button_pressed, &dlg ) );
		draw_arg.right_rect = factory.layout_child_rects( dlg.shared_from_this(), city_dlg_layout::close_button_bg, city_dlg_layout::close_button.alignment() );
		draw_arg.has_right_button = true;
	}
	
	// create back button
	if ( arg.has_back ) {
		
		milk::milk_image_button_ptr ptr_button = 
		factory.create_button( m_windows_ctx, dlg.shared_from_this(), city_dlg_layout::back_button );
		
		ptr_button->set_action( std::tr1::bind( 
							&milk::milk_dialog::on_back_button_pressed, &dlg ) );
		
		factory.create_label( m_windows_ctx, ptr_button, city_dlg_layout::back_button_caption );
		draw_arg.left_rect = factory.layout_child_rects( dlg.shared_from_this(), city_dlg_layout::back_button_bg, city_dlg_layout::back_button.alignment() );	
		draw_arg.has_left_button = true;
	}
    
    // create next button
	if ( arg.has_next ) {
		
		milk::milk_image_button_ptr ptr_button = 
		factory.create_button( m_windows_ctx, dlg.shared_from_this(), city_dlg_layout::next_button );
		
		ptr_button->set_action( std::tr1::bind( 
                                               &milk::milk_dialog::on_next_button_pressed, &dlg ) );
		
		factory.create_label( m_windows_ctx, dlg.shared_from_this(), city_dlg_layout::next_button_caption );
		draw_arg.right_rect = factory.layout_child_rects( dlg.shared_from_this(), city_dlg_layout::next_button_bg, city_dlg_layout::back_button.alignment() );
		draw_arg.has_right_button = true;
	}
	// create title
	
	// start animation
	sqc::animation::animation_transformer_ptr transforer = dlg.transform();
	if (arg.center_dialog) {
		transforer->set_anchor( surf::surf_point( dlg.get_client_rect().size().cx/2, dlg.get_client_rect().size().cy/2 ) );
	}
	framework().windows().animation().add_animator( transforer ,
										  sqc::animation::animation_animator_alpha(0.,1.,0.75,&show_alpha_func) );
	framework().windows().animation().add_animator( transforer ,
										  sqc::animation::animation_animator_scale(0.0,1.,0.75,&show_scale_func) );
	if (m_sample_open)
        m_sample_open->play();
    
	/// bevel
	if (arg.bevel!=milk::milk_bevel_type_none) {
		milk::milk_bevel_ptr bevel = milk::milk_bevel_ptr( new milk::milk_bevel( dlg.shared_from_this() ));
		bevel->set_type(  arg.bevel );
		dlg.add_child_front( bevel,get_dialog_content_rect(dlg.get_client_rect(),arg) );
	}
	/// caption
	if (!arg.title.empty()) {
		
		surf::surf_val left = calc_title_left( dlg, draw_arg );
		milk::milk_label_ptr label = create_title_label( dlg, arg,arg.title, left );
		
		milk::milk_bevel_ptr bevel = milk::milk_bevel_ptr( new milk::milk_bevel( dlg.shared_from_this() ));
		bevel->set_type(  milk::milk_bevel_type_caption );
		dlg.add_child_front( bevel,label->get_rect() );
	}
}

surf::surf_val sqc_city_theme::calc_title_left(  milk::milk_dialog& dlg, milk::milk_dialog_draw_arg const &draw_arg ) {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme = factory.get_theme_size();

	/// left offset if no left button
	static const int title_l_[] = { 44,44*2-1,62};
	/// left offset if left button
	static const int title_lb_[] = { 8,8*2,11 };

	 const int title_l = title_l_[theme];
	 const int title_lb = title_lb_[theme];

	surf::surf_val left = title_l;
	if (draw_arg.has_left_button)
		left = draw_arg.left_rect.size().cx+title_lb;
	return left;
}

surf::surf_val sqc_city_theme::calc_title_right(  milk::milk_dialog& dlg, milk::milk_dialog_draw_arg const &draw_arg ) {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme = factory.get_theme_size();
	
	/// rifht offset if no right button
	static const int title_l_[] = { 44,44*2-1,62};
	/// rifht offset if right button
	static const int title_lb_[] = { 8,8*2,11 };
	
	 const int title_l = title_l_[theme];
	 const int title_lb = title_lb_[theme];
	
	surf::surf_val right = dlg.get_rect().cx - title_l;
	if (draw_arg.has_right_button)
		right = dlg.get_rect().cx - (draw_arg.right_rect.size().cx+title_lb);
	return right;
}


milk::milk_label_ptr sqc_city_theme::create_title_label( milk::milk_dialog& dlg, const milk::milk_dialog_init_arg& init_arg, const surf::surf_string& str, surf::surf_val left ) {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme = factory.get_theme_size();

	
	/// left and right panel space
	static const int title_o_[] = { 20,20*2,25};
	/// minimal width
	static const int title_min_w_[] = { 150,150*2,170};
	
	 const int title_o = title_o_[theme];
	 const int title_min_w = title_min_w_[theme];
	
	
	 const int title_y = title_y_[theme];
	 const int title_h = title_h_[theme];

	surf::surf_color color = surf::surf_color(1,1,1,1);
	if (init_arg.title_args.flags & milk::milk_font_modify_color )
		color = init_arg.title_args.color;
	
	surf::surf_font_ptr font = m_dialog_title_font;
	if (init_arg.title_args.flags & (milk::milk_font_modify_face|milk::milk_font_modify_size)) {
		const char* face = title_font.names().at(theme).c_str();
		if (init_arg.title_args.flags & milk::milk_font_modify_face)
			face = init_arg.title_args.face.c_str();
		surf::surf_val size = title_font.sizes().at(theme);
		if (init_arg.title_args.flags & milk::milk_font_modify_size)
			size = init_arg.title_args.size;
		font = graphics().create_font( size, face );
	}
	
	surf::surf_size text_size = font->calc_size( surf::surf_context_ptr(), str, dlg.get_client_rect().size(), title_draw_flags );
	text_size.cx+=2;
	
	surf::surf_val width = text_size.cx + title_o*2;
	if (width<title_min_w)
		width=title_min_w;
	
	
	 const surf::surf_size shadow_offset = layout_sizes(layout_size(-1,1),layout_size(-2,2),layout_size(-1,1)).at(theme);
	
	surf::surf_rect title_rect(left, dlg.get_client_rect().cy-title_h-title_y, width, title_h);

	milk::milk_label_ptr label = milk::milk_label_ptr( new milk::milk_label( dlg.shared_from_this() ) );
	dlg.add_child_front( label,title_rect );
	label->set_font( font );
	label->set_color( color );
	label->set_draw_flags( title_draw_flags );
	label->set_caption( str );
	label->set_shadow_color( surf::surf_color(0,0,0,0.29) );
	label->set_shadow_size( shadow_offset );
	return label;
}
void sqc_city_theme::on_tab_activated( const milk::milk_bevel_ptr& bevel,
									  const milk::milk_button_ptr& button,
									  const std::vector<milk::milk_button_ptr>& other_buttons ,
									  const std::vector<milk::milk_bevel_ptr>& other_bevels ,
									  const std::tr1::function<void()>& original ) {
	bevel->set_visible(true);
	button->set_visible(false);
	for (size_t i=0;i<other_buttons.size();i++) {
		other_buttons[i]->set_visible(true);
	}
	for (size_t i=0;i<other_bevels.size();i++) {
		other_bevels[i]->set_visible(false);
	}
	original();
}
static void set_counter_caption_proxy( const milk::milk_label_ptr& lbl, int value ) {
	char buf[32];
	::snprintf( buf,32,"%i",value );
	lbl->set_caption( buf );
}
void sqc_city_theme::init_dialog_tabs( milk::milk_dialog& dlg, const milk::milk_dialog_init_arg& init_arg,milk::milk_dialog_draw_arg const &draw_arg,  std::vector<milk::milk_dialog_tab_def>& tabs ) {
	sqc_window_factory& factory = framework().windows_factory();
	sqc_theme_size theme = factory.get_theme_size();

	/// tabs space
	static const int tab_offset_[] = { 5,5*2,8};
	static const int tab_counter_width[] = { 32,32*2,48 };
	
	surf::surf_val x = calc_title_left( dlg, draw_arg );
	std::vector<milk::milk_button_ptr> buttons;
	std::vector<milk::milk_bevel_ptr> bevels;
	std::vector<milk::milk_bevel_ptr> cntr_bevels;
	std::vector<milk::milk_label_ptr> cntr_label;
	std::vector<milk::milk_label_ptr> labels;
	for (size_t i=0;i<tabs.size();i++) {
		milk::milk_label_ptr label = create_title_label( dlg, init_arg,tabs[i].title, x);
		labels.push_back( label );
		x+=label->get_rect().cx + tab_offset_[theme];
		milk::milk_button_ptr button =  milk::milk_button_ptr( new milk::milk_theme_button(dlg.shared_from_this(),milk::theme_button_type(city_theme_button_tab)) );
		
		milk::milk_bevel_ptr bevel = milk::milk_bevel_ptr( new milk::milk_bevel( dlg.shared_from_this() ));
		bevel->set_type(  milk::milk_bevel_type_caption );
		surf::surf_rect button_rect = label->get_rect();
		if (tabs[i].with_counter) {
			
			surf::surf_rect counter_rect = surf::surf_rect(button_rect.bottom_right(),surf::surf_size(tab_counter_width[theme],button_rect.cy));
			x+=counter_rect.cx;
			milk::milk_label_ptr label = milk::milk_label_ptr( new milk::milk_label( dlg.shared_from_this() ) );
			dlg.add_child_front( label,counter_rect );
			label->set_font( m_counter_font );
			label->set_color( surf::surf_color(0,0,0,1) );
			label->set_draw_flags( title_draw_flags );
			label->set_caption( "" );
			label->set_shadow_color( surf::surf_color(1,1,1,0.60) );
			 const surf::surf_size shadow_offset = layout_sizes(layout_size(1,-1),layout_size(2,-2),layout_size(2,-2)).at(theme);
			label->set_shadow_size( shadow_offset );
			tabs[i].set_counter = std::tr1::bind(&set_counter_caption_proxy,label,std::tr1::placeholders::_1);
			milk::milk_bevel_ptr bevel = milk::milk_bevel_ptr( new milk::milk_bevel( dlg.shared_from_this() ));
			bevel->set_type(  milk::milk_bevel_type( milk::milk_bevel_type_counter ) );
			dlg.add_child_front( bevel, counter_rect  );
			button_rect.cx+=tab_counter_width[theme];
			cntr_bevels.push_back( bevel );
			cntr_label.push_back(label);
		} else {
			cntr_bevels.push_back(milk::milk_bevel_ptr());
			cntr_label.push_back(milk::milk_label_ptr());
		}
		dlg.add_child_front( button,button_rect );
		dlg.add_child_front( bevel,button_rect);
		buttons.push_back(button);
		bevels.push_back(bevel);
		bevel->set_visible(false);
	}
	/// refix widthes
	if (tabs.size()>1) {
		surf::surf_val width = calc_title_right(dlg, draw_arg) - calc_title_left( dlg, draw_arg );
		width-=tab_offset_[theme]*tabs.size();
		width/=tabs.size();
		surf::surf_val x = calc_title_left( dlg, draw_arg );
		for (size_t i=0;i<tabs.size();i++) {
			surf::surf_rect rect = bevels[i]->get_rect();
			surf::surf_val delta = rect.cx-width;
			rect.cx = width;
			rect.x = x;
			bevels[i]->set_rect(rect);
			buttons[i]->set_rect(rect);
			surf::surf_rect lbl_rect = labels[i]->get_rect();
			lbl_rect.x = x;
			lbl_rect.cx-=delta;
			labels[i]->set_rect(lbl_rect);
			if (tabs[i].with_counter) {
				surf::surf_rect counter_rect = surf::surf_rect(rect.bottom_right(),surf::surf_size(tab_counter_width[theme],rect.cy));
				counter_rect.x-=tab_counter_width[theme];
				cntr_bevels[i]->set_rect( counter_rect );
				cntr_label[i]->set_rect( counter_rect );
			}
			x+=width+tab_offset_[theme];
		}
	}
	for (size_t i=0;i<tabs.size();i++){
		std::vector<milk::milk_button_ptr> active_buttons;
		std::vector<milk::milk_bevel_ptr> inactive_bevels;
		for (size_t j=0;j<buttons.size();j++) {
			if (i!=j) {
				active_buttons.push_back(buttons[j]);
				inactive_bevels.push_back(bevels[j]);
			}
		}
		std::tr1::function<void()> callback = std::tr1::bind(&sqc_city_theme::on_tab_activated,bevels[i],buttons[i],active_buttons,inactive_bevels,tabs[i].activate);
		buttons[i]->set_action( callback );
		tabs[i].activate = callback;
	}
}

surf::surf_rect sqc_city_theme::get_dialog_content_rect( const surf::surf_rect& rect, const milk::milk_dialog_init_arg& init_arg) {
	surf::surf_rect res = sqc_theme_base::get_dialog_content_rect( rect, init_arg );
	if (init_arg.bevel!=milk::milk_bevel_type_none) {
		sqc_window_factory& factory = framework().windows_factory();
		sqc_theme_size theme = factory.get_theme_size();
		res.cy-=city_dlg_layout::content_offset_top[theme];
		if (init_arg.bevel==milk::milk_bevel_type_content) {
			 const surf::surf_val bottom = city_dlg_layout::content_offset_btm[theme];
			res.cy-=bottom;
			res.y+=bottom;
			 const surf::surf_val lr = city_dlg_layout::content_offset_lr[theme];
			res.x+=lr;
			res.cx-=lr+lr;
		} else if (init_arg.bevel==milk::milk_bevel_type_content_scroll) {
			 const surf::surf_val bottom = layout_vals(7,7*2,20).at(theme);
			res.cy-=bottom;
			res.y+=bottom;
			 const surf::surf_val lr = layout_vals(5,5*2,7).at(theme);
			res.x+=lr;
			res.cx-=lr+lr;
		}
	}
	return res;
}

bool sqc_city_theme::on_end_dialog( milk::milk_dialog& dlg, milk::milk_dialog_init_arg const &arg ) {
	framework().windows().animation().add_animator( dlg.transform() ,
									  sqc::animation::animation_animator_sequency()
									  .add( sqc::animation::animation_animator_alpha_from_current(0.,0.5))
									  .add( sqc::animation::animation_animator_event(std::tr1::bind(&milk::milk_dialog::destroy,
																									/// some tr1 magick, function hodl dialog
																									std::tr1::static_pointer_cast<milk::milk_dialog>(dlg.shared_from_this())))));
	if (m_sample_close)
        m_sample_close->play();
    return false;
}


static void on_spinboard_left_pressed(  milk::milk_spinboard* spinboard ) {
	spinboard->set_active_page( spinboard->get_active_page()-1, false );
}
static void on_spinboard_right_pressed(  milk::milk_spinboard* spinboard ) {
	spinboard->set_active_page( spinboard->get_active_page()+1, false );
}


static void on_spinboard_page_changed(  milk::milk_spinboard* spinboard, 
									  const milk::milk_widget_ptr& left,
									  const milk::milk_widget_ptr& right,
									  const milk::milk_label_ptr& label,
									  int page  ) {
	if (left) left->set_visible( page > 0 );
	if (right) right->set_visible( page < (spinboard->get_pages_count()-1) );
	if (label) {
		char buf[256];
		sqc_string format = framework().strings().load("*CityPageCounter", "Страница %d из %d" );
		snprintf(buf, 256, format.c_str(),page+1,spinboard->get_pages_count());
		label->set_caption(buf);
	}
}
static void on_spinboard_page_changed_iphone(  milk::milk_spinboard* spinboard, 
									  const milk::milk_widget_ptr& left,
									  const milk::milk_widget_ptr& right,
									  const milk::milk_label_ptr& label,
									  int page  ) {
	if (left) left->set_visible( page > 0 );
	if (right) right->set_visible( page < (spinboard->get_pages_count()-1) );
	if (label) {
		char buf[256];
		snprintf(buf, 256, "%d/%d",page+1,spinboard->get_pages_count());
		label->set_caption(buf);
	}
}
static void on_spinboard_pages_count_change( const milk::milk_widget_ptr& cntr, int pages ) {
	cntr->set_visible( pages>1 );
}

void sqc_city_theme::on_init_spinboard( milk::milk_spinboard& spin  , milk::milk_spinboard_theme_flags flags) {
	if (!load_all()) return;
	milk::milk_widget_ptr parent = spin.get_parent();
	spin.set_small_scroll_enabled( false );
	if (parent) {
		if ( !m_windows_ctx ) {
			m_windows_ctx = sqc_window_factory_ctx_ptr( 
													   new sqc_window_factory_ctx( graphics() ) );
			if ( !m_windows_ctx ) {
				return;
			}
		}
		sqc_window_factory& factory = framework().windows_factory();
		sqc_theme_size theme = factory.get_theme_size();

		// create left button
		milk::milk_image_button_ptr ptr_button_left;
		if (flags & milk::milk_spinboard_themed_left_right )
		{
			 surf::surf_rect rect; 
			 rect.x = spin.get_rect().x-m_spin_left->get_size().cx;
			 rect.y = spin.get_rect().y+(spin.get_client_rect().cy - m_spin_left->get_size().cy)/2;
			 rect.cx = m_spin_left->get_size().cx+1;
			 rect.cy = m_spin_left->get_size().cy;
			 ptr_button_left = parent->create_child<milk::milk_image_button>( rect );
			 ptr_button_left->set_image( m_spin_left );
			 ptr_button_left->set_pressed_image( m_spin_left_pressed );
			 ptr_button_left->set_action( std::tr1::bind( &on_spinboard_left_pressed, &spin ) );
		}
		// create right button
		milk::milk_image_button_ptr ptr_button_right;
		if (flags & milk::milk_spinboard_themed_left_right )
		{
			surf::surf_rect rect; 
			rect.x = spin.get_rect().x+spin.get_rect().cx;
			rect.y = spin.get_rect().y+(spin.get_client_rect().cy - m_spin_right->get_size().cy)/2;
			rect.cx = m_spin_right->get_size().cx+1;
			rect.cy = m_spin_right->get_size().cy;
			ptr_button_right = parent->create_child<milk::milk_image_button>( rect );
			ptr_button_right->set_image( m_spin_right );
			ptr_button_right->set_pressed_image( m_spin_right_pressed );
			ptr_button_right->set_action( std::tr1::bind( &on_spinboard_right_pressed, &spin ) );
		}
		// current page label
		milk::milk_label_ptr label;
		if (flags & milk::milk_spinboard_themed_pages)
		{
			surf::surf_rect rect;
			surf::surf_val width = m_spin_page_bg->get_size().cx;
			surf::surf_val height = m_spin_page_bg->get_size().cy;
			if (theme==sqc_theme_large) {
				rect.x = spin.get_rect().x+(spin.get_rect().cx-width)/2;
				rect.y = spin.get_rect().y-height;
			} else if (theme==sqc_theme_small) {
				rect.x = 5;
				rect.y = 5;
			} else if (theme==sqc_theme_normal) {
				rect.x = 5*2;
				rect.y = 5*2;
			}
			rect.cx = width;
			rect.cy = height;
			milk::milk_image_ptr img = parent->create_child<milk::milk_image>( rect );
			img->set_image( m_spin_page_bg );
			if (theme==sqc_theme_small) {
				rect.x += 12;
				rect.cx -= 12;
			} else if (theme==sqc_theme_normal) {
				rect.x += 12*2+1;
				rect.cx -= 12*2;
				rect.cy-=2;
			}
			label = img->create_child<milk::milk_label>( img->get_client_rect() );
			if (theme==sqc_theme_large) 
				label->set_caption("page 1 of 100");
			else
				label->set_caption("1/100");
			label->set_font(m_spin_page_font);
			if (theme==sqc_theme_large) {
				label->set_shadow_color( surf::surf_color(0,0,0,0.29) );
				label->set_shadow_size( layout_sizes(surf::surf_size(-2,2),surf::surf_size(-2,2),surf::surf_size(-2,2)).at(theme) );
				label->set_draw_flags( surf::draw_string_alignment_center|
										   surf::draw_string_valignment_center|
										   surf::draw_string_draw_shadow_enabled|
										   surf::draw_string_truncation_disabled|
										   surf::draw_string_single_line );
			} else {
				label->set_draw_flags( surf::draw_string_alignment_center|
									  surf::draw_string_valignment_center|
									  surf::draw_string_draw_shadow_disabled|
									  surf::draw_string_truncation_disabled|
									  surf::draw_string_single_line );
			}
			spin.set_on_pages_count_change( std::tr1::bind( &on_spinboard_pages_count_change, img, std::tr1::placeholders::_1 ) );
		}
		if (flags) {
			if (theme==sqc_theme_large) {
				spin.set_on_page_change( std::tr1::bind(&on_spinboard_page_changed,&spin,ptr_button_left,ptr_button_right,label,std::tr1::placeholders::_1) );
			} else {
				spin.set_on_page_change( std::tr1::bind(&on_spinboard_page_changed_iphone,&spin,ptr_button_left,ptr_button_right,label,std::tr1::placeholders::_1) );
			}
		}
		
	}
}

void sqc_city_theme::on_init_pager( milk::milk_spinboard_pager& pager ) {
	pager.set_small_scroll_enabled( false );
	pager.set_normal_image( m_pager_btn );
	pager.set_active_image( m_pager_pressed );
	pager.set_one_page_visible( false );
	pager.set_centered( true );
	pager.set_step( layout_vals(22,22*2,25).at( framework().windows_factory().get_theme_size() ) );
}

END_NAMESPACE_SQC_FRAMEWORK