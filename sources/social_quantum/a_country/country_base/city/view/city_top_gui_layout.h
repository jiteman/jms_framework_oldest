/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_CITY_TOP_GUI_LAYOUT_H_INCLUDED__
#define __SQC_CITY_TOP_GUI_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace top_gui {
	
    static const int panel_height[] = { 72, 2*72, 100 };
    // labels font
    static const font_layout 
    label_font( 
        layout_font_name( "Arial-BoldMT.otf" ), //Arial-BoldMT
        layout_font_sizes( 10, 2*10, 15 ) ); 
        
	static int top_row[] = { 1, 2, 3 };
	
    // 
    //	manage buttons - layout by parent
    //
    static const image_layout
	left_arrow_button_image(
        layout_alignment( layout_halignment_left |
                     layout_valignment_top),
        image_names( "statusBarLeftArrowButton",
                 "statusBarLeftArrowButton@2x",
                 "" ),
        layout_rects(
            layout_rect( 3, top_row[0], 27, 27 ),
            layout_rect( 2*3, top_row[1], 54, 54 ),
            layout_rect( 0, 0, 0, 0 ) ) );
    
    static const image_layout
	right_arrow_button_image(
        layout_alignment( layout_halignment_left |
                     layout_valignment_top),
        image_names( "statusBarRightArrowButton",
                 "statusBarRightArrowButton@2x",
                 "" ),
        layout_rects(
            layout_rect( 3, top_row[0], 27, 27 ),
            layout_rect( 2*3, top_row[1], 54, 54 ),
            layout_rect( 0, 0, 0, 0 ) ) );
            
    // 
    //	coins - layout by parent
    //
    
    static const image_layout
    coins_background(
        layout_alignment( layout_halignment_left |
                     layout_valignment_top),
        image_names( "statusBarCoinsBackground",
                 "statusBarCoinsBackground_HD",
                 "statusBarCoinsBackground_iPad" ),
        layout_rects(
            layout_rect( 33, top_row[0], 64, 25 ),
            layout_rect( 2*33, top_row[1], 128, 48 ),
            layout_rect( 8, top_row[2], 104, 42 ) ) );

    static const label_layout  
    coins_label( // layout by coins_background
        layout_alignment( layout_halignment_fill |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        layout_rects(
            layout_rect( 20, 0, 0, 0 ),
            layout_rect( 2*20, 0, 0, 0 ),
            layout_rect( 40, 0, 0, 0 ) ) );


    // 
    //	bucks - layout by parent
    //
    
    static const image_layout
    bucks_background(
        layout_alignment( layout_halignment_left |
                     layout_valignment_top),
        image_names( "statusBarGoldBackground",
                 "statusBarGoldBackground_HD",
                 "statusBarGoldBackground_iPad" ),
        layout_rects(
            layout_rect( 97, top_row[0], 64, 25 ),
            layout_rect( 2*97, top_row[1], 128, 48 ),
            layout_rect( 120, top_row[2], 104, 42 ) ) );

    static const label_layout
    bucks_label( // layout by bucks_background
        layout_alignment( layout_halignment_fill |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        layout_rects(
            layout_rect( 20, 0, 0, 0 ),
            layout_rect( 2*20, 0, 0, 0 ),
            layout_rect( 40, 0, 0, 0 ) ) );
            
            
    // 
    //	expr - layout by parent
    //
    
    static const image_layout
    expr_background(
        layout_alignment( layout_halignment_center |
                     layout_valignment_top),
        image_names( "bg_level",
                 "bg_level@2x",
                 "bg_level_ipad" ),
        layout_rects(
            layout_rect( -15, top_row[0]+3, 127, 28 ),
            layout_rect( -2*15, top_row[1], 254, 56 ),
            layout_rect( 0, top_row[2], 302, 45 ) ) );

	static const slice_image_layout
    slc_exp_band(
        layout_alignment( layout_halignment_left | layout_valignment_bottom ),
        image_names(
        	"progressbar_level",
            "progressbar_level@2x",
            "progress_bar_ipad"
        ),
		slice_offsets(
        	slice_offset(3,0,3,0, surf::tile_flag_none),
            slice_offset(7,0,7,0, surf::tile_flag_none),
            slice_offset(4,0,4,0, surf::tile_flag_none)
        ),
        image_rects(
            layout_rect( 9, 11, 109, 14 ),
            layout_rect( 5, 12, 210, 28 ),
            layout_rect( 36, 16, 260, 16 ) )
    );
    	
    
    static const image_layout
    expr_start_hd( // layout by expr_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_bottom),
        image_names( "",
                 "",
                 "exp_star_iPad" ),
        layout_rects(
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 2, 53, 45 ) ) );

    static const image_layout
    expr_start( 
        layout_alignment( layout_halignment_left |
                     layout_valignment_top),
        image_names( "icon_level_star",
                 "exp_star_HD",
                 "exp_star_iPad" ),
        layout_rects(
            layout_rect( 104, -3, 26, 25 ),
            layout_rect( 197, 4, 26*2, 25*2 ),
            layout_rect( 0, 0, 53, 45) ) );


    static const label_layout
    expr_level_label_hd( // layout by expr_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        layout_rects(
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 45, 0 ) ) );   //start width         
        

    static const label_layout
    expr_level_label( // layout by expr_background
        layout_alignment( layout_halignment_right |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        layout_rects(
            layout_rect( -5, 6, 30, 0 ), // star width
            layout_rect( 6, -8, 50, 0 ), // star width
            layout_rect( 0, 0, 0, 0 ) ) );            

    static const label_layout
    expr_descr_label_hd( // layout by expr_background
        layout_alignment( layout_halignment_right |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        layout_rects(
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 0, 0, 0, 0 ),
            layout_rect( 5, 0, 250, 0 ) ) );            
        

    static const label_layout
    expr_descr_label( // layout by expr_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        layout_rects(
            layout_rect( 3, 6, 100, 0 ),
            layout_rect( 3, 0, 2*100, 0 ),
            layout_rect( 0, 0, 0, 0 ) ) );            


	static const int wpe_label_offset[] = { 20, 2*20, 40 };
	static const int wpe_width[] = { 64, 121, 92 };
	static const int wpe_height[] = { 28, 50, 42 };

	static const int maxp_width[] = { 64, 121, 92 };
	static const int maxp_height[] = { 28, 53, 34 };
	static const int maxp_label_offset[] = { 20, 2*20, 40 };
  
    static const layout_rects wpe_image_rects( 
            layout_rect( 0, top_row[0], wpe_width[0], wpe_height[0] ),
            layout_rect( 0, top_row[1], wpe_width[1], wpe_height[1] ),
            layout_rect( 0, top_row[2], wpe_width[2], wpe_height[2] ) );
    
    static const layout_rects wpe_label_rects( 
            layout_rect( wpe_label_offset[0], 0, wpe_width[0] - wpe_label_offset[0], 0 ),
            layout_rect( wpe_label_offset[1], 0, wpe_width[1] - wpe_label_offset[1], 0 ),
            layout_rect( wpe_label_offset[2], 0, wpe_width[2] - wpe_label_offset[2], 0 ) );

    static const layout_rects maxp_image_rects( 
            layout_rect( 0, 20, maxp_width[0], maxp_height[0] ),
            layout_rect( 0, 2*20, maxp_width[1], maxp_height[1] ),
            layout_rect( 0, 30, maxp_width[2], maxp_height[2] ) );
    
    static const layout_rects maxp_label_rects( 
            layout_rect( maxp_label_offset[0], 7, maxp_width[0] - maxp_label_offset[0], maxp_height[0] ),
            layout_rect( maxp_label_offset[1], 2*7, maxp_width[1] - maxp_label_offset[1], maxp_height[1] ),
            layout_rect( maxp_label_offset[2], 10, maxp_width[2] - maxp_label_offset[2], maxp_height[2] ) );


    // 
    //	maximum subpanel - layout by parent
    //
    static const image_layout
    maxp_background(
        layout_alignment( layout_halignment_right |
                     layout_valignment_top),
        image_names( "max_subpanel",
                 "max_subpanel_HD",
                 "max_subpanel_iPad" ),
        maxp_image_rects );

    static const label_layout
    maxp_label( // layout by maxp_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_bottom),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vbottom,
        label_font,
        maxp_label_rects );

    // 
    //	water - layout by parent
    //
    
    static const image_layout
    water_background(
        layout_alignment( layout_halignment_right |
                     layout_valignment_top),
        image_names( "statusBarWaterBackground",
                 "statusBarWaterBackground_HD",
                 "statusBarWaterBackground_iPad" ),
        wpe_image_rects );

    static const label_layout
    water_label( // layout by water_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        wpe_label_rects );

    // 
    //	power - layout by parent
    //
    
    static const image_layout
    power_background(
        layout_alignment( layout_halignment_right |
                     layout_valignment_top),
        image_names( "statusBarPowerBackground",
                 "statusBarPowerBackground_HD",
                 "statusBarPowerBackground_iPad" ),
        wpe_image_rects );

    static const label_layout
    power_label( // layout by power_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        wpe_label_rects );

    // 
    //	population - layout by parent
    //
    
    static const image_layout
    population_background(
        layout_alignment( layout_halignment_right |
                     layout_valignment_top),
        image_names( "statusBarPopBackground",
                 "statusBarPopBackground_HD",
                 "statusBarPopBackground_iPad" ),
        wpe_image_rects );

    static const label_layout
    population_label( // layout by population_background
        layout_alignment( layout_halignment_left |
                     layout_valignment_fill),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        label_font,
        wpe_label_rects );


   static const layout_rects population_image_rects( 
            layout_rect( 5, 5, 13, 17 ),
            layout_rect( 2*5, 2*5, 27, 34 ),
            layout_rect( 2*5, 2*5, 27, 34 ) );
   static const layout_alignment population_image_aligment( 
   		layout_halignment_left | layout_valignment_bottom);

    static const image_layout
    population_image( // layout by population_background
        population_image_aligment,
        image_names( "population_ico_1",
                 "population_ico_1_HD",
                 "population_ico_1_HD" ),
        population_image_rects );
        
    // 
    //	Add coins and bucks
    //
    
    static const font_layout add_coins_font (layout_font_name( "Arial-BoldMT.otf" ),
                                             layout_font_sizes( 10, 20, 20 ) );   
    
    static const layout_rects add_coins_rect (
                                        layout_rect( 3, top_row[0] +  29, 127, 32 ),
                                        layout_rect( 6, top_row[1] +  56, 254, 64 ),
                                        layout_rect(  6, top_row[2] + 108, 241, 29 )
                                        );
                                        
    static const layout_rects add_coins_caption_rect (
                                              layout_rect( 30, top_row[0] +  30, 100, 30 ),
                                              layout_rect( 60, top_row[1] +  60, 200, 59 ),
                                              layout_rect(  6, top_row[2] + 108, 241, 29 )
                                              );
                                        
	static const image_button_layout
     add_coins_button(
                 layout_alignment(layout_halignment_left |
                                  layout_valignment_top),
                 image_names( "add_coins_bucks_normal",
                              "add_coins_bucks_normal@2x",
                              "add_coins_bucks_normal_ipad" ),
                 image_pressed_names( "add_coins_bucks_selected",
                                      "add_coins_bucks_selected@2x",
                                      "add_coins_bucks_selected_ipad" ) ,
                 add_coins_rect );
    
    static const label_layout
     add_coins_caption( layout_alignment( layout_halignment_left | layout_valignment_top ), //layout_halignment_left | layout_valignment_top
                        common_resources::string_message_add_coins_and_bucks,
                        layout_white_color,
                        draw_flags_hcenter_vcenter,
                        add_coins_font,
                        add_coins_caption_rect);

        
	// offset from right 
    static int power_shift[] 		= {   0,     0,   0 };
    static int water_shift[]		= {  63,  2*63, 100 };
    static int population_shift[]   = { 125, 2*125, 200 };
    
    static int animation_step[]		= { 7*30, 2*7*30, 10*30 };
}};

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_CITY_TOP_GUI_LAYOUT_H_INCLUDED__
