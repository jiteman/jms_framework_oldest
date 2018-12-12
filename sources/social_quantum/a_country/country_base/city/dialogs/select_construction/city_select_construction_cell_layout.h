/*
 *  city_select_construction_cell_layout.h
 *  aCountry
 *
 *  Created by paul on 10/11/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __CITY_SELECT_CONSTRUCTION_CELL_LAYOUT_H_INCLUDED___
#define __CITY_SELECT_CONSTRUCTION_CELL_LAYOUT_H_INCLUDED___

#include "country_base/dialogs/controls/sqc_item_buttons_layout.h"

NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout { namespace select_construction_cell {
	
    // spinboard cell background
    
    static const int backing_w[] = { 133, 266, 155 };
    static const int backing_h[] = { 82, 162, 112 };

    static const int ctrls_offset[] = { 6, 2*6, 7 };

    static const sqc_shop_item_button_layout
    cell_background_btn( // layout by spinboard cell
        layout_alignment( layout_halignment_center |
                      layout_valignment_bottom),
        image_rects( layout_rect( 0, 42, backing_w[0], backing_h[0] ),
                     layout_rect( 0, 2*42, backing_w[1], backing_h[1] ),
                     layout_rect( 0, 70, backing_w[2], backing_h[2] ) ) );
    
    
    // spinboard cell item image alignment
    static const layout_alignment
    cell_item_image_alignment( layout_halignment_center |
                              layout_valignment_center);
    
    // spinboard cell item image rect
    static const image_rects
    cell_item_image_rects(
                          layout_rect( 0, 0, 60, 60 ),
                          layout_rect( 0, 0, 2*60, 2*60 ),
                          layout_rect( 0, 0, 68, 68 ) );
    
    // spinboard cell item name font
    static const font_layout 
    cell_item_name_font( 
        layout_font_name( "Arial.otf" ), //Arial
        layout_font_sizes( 12, 2*12, 18 ) );

    // spinboard cell item name
    static const label_layout
    cell_item_name_label( // layout by spinboard cell
        layout_alignment( layout_halignment_left |
                 layout_valignment_bottom ),
        layout_string_resource( "", "" ),
        layout_white_color,
        draw_flags_hcenter_vcenter,
        cell_item_name_font,
        label_rects(
             layout_rect( ctrls_offset[0], 127, backing_w[0], 28 ),
             layout_rect( ctrls_offset[1], 2*127, backing_w[1], 2*28 ),
             layout_rect( ctrls_offset[2], 200, backing_w[2], 60 ) ) );

    
    /////////////////////////////////////////////////////////////////////////////
    // apply button
    
    static const int buttons_y[] = { 5, 2*5, 7 };
    
    static const layout_rects
    apply_button_rect( layout_rect( 0, buttons_y[0], layout::item_buttons::width[0], layout::item_buttons::height[0] ),
                           layout_rect( 0, buttons_y[1], layout::item_buttons::width[1], layout::item_buttons::height[1] ),
                           layout_rect( 0, buttons_y[2], layout::item_buttons::width[2], layout::item_buttons::height[2] ) );
    
    static const layout_alignment
    apply_button_center_alignment( layout_halignment_center |
                               layout_valignment_bottom );
    
    ///////////////////////////////////////////////////////////////////////
    // spinboard cell separator
    static const vertical_separator_layout spinboard_cell_separator( 
                                                  layout_alignment( layout_halignment_right ),
                                                  separator_offsets( 0,0,0) );
  
    
    
} };

END_NAMESPACE_SQC_FRAMEWORK

#endif//__CITY_SELECT_CONSTRUCTION_CELL_LAYOUT_H_INCLUDED___


