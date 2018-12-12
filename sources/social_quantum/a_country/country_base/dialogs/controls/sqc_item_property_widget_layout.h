/*
 *  city_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __SQC_ITEM_PROPERTY_WIDGET_LAYOUT_H_INCLUDED__
#define __SQC_ITEM_PROPERTY_WIDGET_LAYOUT_H_INCLUDED__

NAMESPACE_SQC_FRAMEWORK

namespace layout { namespace item_property_widget {
	
    // spinboard cell item properties
    static const font_layout 
    cell_item_properties_font( 
        layout_font_name( "Arial.otf" ), //Arial
        layout_font_sizes( 11, 2*11, 14 ) );

    /////////////////////////////////////
    static const int cell_w[] = { 54, 108, 69 };
    static const int cell_h[] = { 19, 38, 23 };
    
    static const int cell_col_x[] = { 3, 2*3, 4 };
    
    // top layout
    static const int cell_row0_y[] = { 5, 2*5, 6 }; 
    // top layout
    static const int cell_row1_y[] = { 3 + cell_row0_y[0] + cell_h[0],
                                       4 + cell_row0_y[1] + cell_h[1],
                                       3 + cell_row0_y[2] + cell_h[2] };
    // bottom layout
    static const int cell_row3_y[] = { 5, 2*5, 6 }; 
    // bottom layout
    static const int cell_row2_y[] = { 3 + cell_row3_y[0] + cell_h[0],
                                       4 + cell_row3_y[1] + cell_h[1],
                                       3 + cell_row3_y[2] + cell_h[2] };
    
    // label from image offset
    static const int label_offset[] = { 20, 2*20, 30 }; 
    static const layout_rects
    label_transforms_col0( 
                layout_rect( label_offset[0], 0, -1 * label_offset[0], 0 ),
                layout_rect( label_offset[1], 0, -1 * label_offset[1], 0 ),
                layout_rect( label_offset[2], 0, -1 * label_offset[2], 0 ) );

    static const layout_rects
    label_transforms_col1( 
                layout_rect( 0, 0, -1 * label_offset[0], 0 ),
                layout_rect( 0, 0, -1 * label_offset[1], 0 ),
                layout_rect( 0, 0, -1 * label_offset[2], 0 ) );
    
    // spinboard cell power change (row0, col0)
    static const layout_rects
    power_change_image_rect( 
                layout_rect( cell_col_x[0], cell_row0_y[0], cell_w[0], cell_h[0] ),
                layout_rect( cell_col_x[1], cell_row0_y[1], cell_w[1], cell_h[1] ),
                layout_rect( cell_col_x[2], cell_row0_y[2], cell_w[2], cell_h[2] ) );

    static const layout_rects power_change_label_rect( 
                transform_layout_rects( power_change_image_rect, label_transforms_col0 ) );
    
    
    static layout_alignment 
    power_change_image_alignment( layout_halignment_left |
                                layout_valignment_top );
    
    static const image_layout 
    cell_power_change_image( // layout by spinboard background image
        power_change_image_alignment,
        image_names( "energy_icon",
                   "energy_icon@2x",
                   "energy_icon_ipad" ),
        power_change_image_rect );
    
    
    static const layout_alignment
    power_change_label_alignment( layout_halignment_left |
                                layout_valignment_top );
    
    static const label_layout
    cell_power_change_label( //layout by spinboard background image
        power_change_label_alignment,
        layout_string_resource( "", "" ),                                        
        layout_black_color,
        draw_flags_hleft_vcenter,
        cell_item_properties_font,
        power_change_label_rect );


    // spinboard cell water change (row1, col0)
    static const layout_rects
    water_change_rect( 
        layout_rect( cell_col_x[0], cell_row1_y[0], cell_w[0], cell_h[0] ),
        layout_rect( cell_col_x[1], cell_row1_y[1], cell_w[1], cell_h[1] ),
        layout_rect( cell_col_x[2], cell_row1_y[2], cell_w[2], cell_h[2] ) );
    
    static const image_layout
    cell_water_change_image( // layout by spinboard background image
           layout_alignment( layout_halignment_left |
                           layout_valignment_top),
           image_names( "water_icon",
                       "water_icon@2x",
                       "water_icon_ipad" ),
           water_change_rect );
    
    static const label_layout
    cell_water_change_label( //layout by spinboard background image
           layout_alignment( layout_halignment_left |
                           layout_valignment_top),
           layout_string_resource( "", "" ),                                        
           layout_black_color,
           draw_flags_hleft_vcenter,
           cell_item_properties_font,
           transform_layout_rects( water_change_rect, label_transforms_col0 ) );

    // spinboard cell population change (row2, col0)
    static const layout_rects
    population_change_rect( 
        layout_rect( cell_col_x[0], cell_row2_y[0], cell_w[0], cell_h[0] ),
        layout_rect( cell_col_x[1], cell_row2_y[1], cell_w[1], cell_h[1] ),
        layout_rect( cell_col_x[2], cell_row2_y[2], cell_w[2], cell_h[2] ) );
    
    static const image_layout
    cell_population_change_image( // layout by spinboard background image
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        image_names( "people_icon",
                   "people_icon@2x",
                   "people_icon_ipad" ),
        population_change_rect );
    
    static const label_layout
    cell_population_change_label( //layout by spinboard background image
        layout_alignment( layout_halignment_left |
                       layout_valignment_bottom),
        layout_string_resource( "", "" ),                                        
        layout_black_color,
        draw_flags_hleft_vcenter,
        cell_item_properties_font,
        transform_layout_rects( population_change_rect, label_transforms_col0 ) );

    // spinboard cell population change (row3, col0)
    static const layout_rects
    coins_change_image_rect( 
        layout_rect( cell_col_x[0], cell_row3_y[0], cell_w[0], cell_h[0] ),
        layout_rect( cell_col_x[1], cell_row3_y[1], cell_w[1], cell_h[1] ),
        layout_rect( cell_col_x[2], cell_row3_y[2], cell_w[2], cell_h[2] ) );

    static const layout_rects
    coins_change_label_rect = 
    transform_layout_rects( coins_change_image_rect, label_transforms_col0 );

    static const layout_alignment_mask
    coins_change_image_alignment( layout_halignment_left |
                                layout_valignment_bottom);

    static const layout_alignment_mask
    coins_change_label_alignment( layout_halignment_left |
                                layout_valignment_bottom);
    
    static const image_layout
    cell_coins_change_image( // layout by spinboard background image
        coins_change_image_alignment,
        image_names( "coins_icon",
                 "coins_icon@2x",
                 "coins_icon_ipad" ),
        coins_change_image_rect );
    
    static const label_layout
    cell_coins_change_label( //layout by spinboard background image
        coins_change_label_alignment,
        layout_string_resource( "", "" ),                                        
        layout_black_color,
        draw_flags_hleft_vcenter,
        cell_item_properties_font,
        coins_change_label_rect );
    
    // spinboard cell experience change (row0, col1)
    static const layout_rects
    experience_change_rect(
        layout_rect( cell_col_x[0], cell_row0_y[0], cell_w[0], cell_h[0] ),
        layout_rect( cell_col_x[1], cell_row0_y[1], cell_w[1], cell_h[1] ),
        layout_rect( cell_col_x[2], cell_row0_y[2], cell_w[2], cell_h[2] ) );
    
    static const image_layout
    cell_experience_change_image( // layout by spinboard background image
        layout_alignment( layout_halignment_right |
                       layout_valignment_top),
        image_names( "xp_icon",
                   "xp_icon@2x",
                   "xp_icon_ipad" ),
        experience_change_rect );
    
    static const label_layout
    cell_experience_change_label( //layout by spinboard background image
        layout_alignment( layout_halignment_right |
                       layout_valignment_top),
        layout_string_resource( "", "" ),                                        
        layout_black_color,
        draw_flags_hleft_vcenter,
        cell_item_properties_font,
        transform_layout_rects( experience_change_rect, label_transforms_col1 ) );
    
    
    // spinboard cell time (row2, col1)
    static const layout_rects
    time_build_rect( 
        layout_rect( cell_col_x[0], cell_row3_y[0], cell_w[0], cell_h[0] ),
        layout_rect( cell_col_x[1], cell_row3_y[1], cell_w[1], cell_h[1] ),
        layout_rect( cell_col_x[2], cell_row3_y[2], cell_w[2], cell_h[2] ) );
    
    static const image_layout
    cell_time_build_image( // layout by spinboard background image
        layout_alignment( layout_halignment_right |
                        layout_valignment_bottom),
        image_names( "time_icon",
                    "time_icon@2x",
                    "time_icon_ipad" ),
        time_build_rect );
    
    static const label_layout
    cell_time_build_label( //layout by spinboard background image
        layout_alignment( layout_halignment_right |
                        layout_valignment_bottom),
        layout_string_resource( "", "" ),                                        
        layout_black_color,
        draw_flags_hleft_vcenter,
        cell_item_properties_font,
        transform_layout_rects( time_build_rect, label_transforms_col1 ) );
    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_ITEM_PROPERTY_WIDGET_LAYOUT_H_INCLUDED__


