/*
 *  city_salary_dlg_layout.h
 *  aCountry
 *
 *  Created by Ivan Konnov on 02.09.11.
 *  Copyright 2011 fair play. All rights reserved.
 *  mail: ivan.quantum@yandex.ru
 */
 
 

#ifndef __SQC_CITY_SALARY_DLG_LAYOUT_H_INCLUDED__
#define __SQC_CITY_SALARY_DLG_LAYOUT_H_INCLUDED__

#include "city/dialogs/city_base_dlg_layout.h" // contains global interface (as ),
                                  // some general struct and declared namespace 'city_dlg_layout'
                                  
NAMESPACE_SQC_FRAMEWORK

namespace city_dlg_layout {
    namespace salary_dlg {


//============================== Window =============================

//metrics for layout
static const sqc_int dlg_w[] = { 480, 960, 676 };// {small, middle,large}
static const sqc_int dlg_h[] = { 320, 640, 472 };
 
//for page item layout.  
static const sqc_dword   cell_rect_x[] = {20,  40,  50}; 
static const sqc_dword   cell_rect_y[] = {70,  135, 200};
static const sqc_dword   cell_rect_w[] = {150, 300, 310};
static const sqc_dword   cell_rect_h[] = {200, 400, 486};
                
static const sqc_dword   offset_x[] = {155, 310, 200};
static const sqc_dword   offset_y[] = {108, 216, 167};              
                
static const layout_rects cell_rects(
                            layout_rect( cell_rect_x[0], cell_rect_y[0],
                                         cell_rect_w[0], cell_rect_h[0] ),
                            layout_rect( cell_rect_x[1], cell_rect_y[1],
                                         cell_rect_w[1], cell_rect_h[1] ),
                            layout_rect( cell_rect_x[2], cell_rect_y[2],
                                         cell_rect_w[2], cell_rect_h[2] ));
        
static const dialog_layout background(
                                        layout_alignment( layout_halignment_center | layout_valignment_center ),
                                        dialog_sizes( layout_size( dlg_w[0], dlg_h[0] ),
                                                      layout_size( dlg_w[1], dlg_h[1] ),
                                                      layout_size( dlg_w[2], dlg_h[2] ) ) );


static const layout_string_resource title( layout_resource_id( "*CitySalaryTitle" ),
                                           layout_string( "Salary" ) );
                                    
static const sqc_int label_x[] = { 25,  40,  50  };
static const sqc_int label_y[] = { 55,  120, 80  };
static const sqc_int label_w[] = { 450, 800, 700 };
static const sqc_int label_h[] = { 50,  80,  50  };
                                          
//shadow
static const layout_points shadow_offsets( layout_point( -0.5, 1 ),
                                           layout_point( -1, 2 ),
                                           layout_point( -0.75, 1 ));
        
static const shadow_layout shadow(layout_black_color, shadow_offsets) ;
              
                 
static const label_layout
        text_label(
                   layout_alignment( layout_halignment_left |
                                   layout_valignment_top ),
                   layout_string_resource( "*CitySalaryDescription",
                                           "You can buy additional operation points and add money to\nCity Hall employees salary fund" ),
                   layout_white_color,
                   draw_flags_hleft_vcenter,
                   font_layout(
                               layout_font_name( "Arial-BoldMT.otf" ), //ArialBT
                               layout_font_sizes( 11, 2*11, 16 )),
                   label_rects( layout_rect( label_x[0], label_y[0],label_w[0] , label_h[0] ),
                                layout_rect( label_x[1], label_y[1],label_w[1] , label_h[1] ),
                                layout_rect( label_x[2], label_y[2], label_w[2], label_h[2]) ),
                                shadow  );
        
        
        
		// separtors
		static const city_horizontal_clear_separator_layout separator_h( 
															 layout_alignment( layout_valignment_top ),
															 separator_offsets( 200-1-50,2*205-2-50*2,299-2-70-8) );
		static const vertical_separator_layout separator_v1( 
															layout_alignment( layout_halignment_left ),
															separator_offsets( 166-1-7,2*160-2-7*2,440-2-25),
															separator_offsets( label_y[0]+label_h[0]-content_offset_top[0],
																			  label_y[1]+label_h[1]-content_offset_top[1],
																			  label_y[2]+label_h[2]-content_offset_top[2]));
		static const vertical_separator_layout separator_v2( 
															layout_alignment( layout_halignment_left ),
															separator_offsets( 318-1-7,2*318-2-7*2,235-2-25),
															separator_offsets( label_y[0]+label_h[0]-content_offset_top[0],
																			  label_y[1]+label_h[1]-content_offset_top[1],
																			  label_y[2]+label_h[2]-content_offset_top[2]));


                                            
                                            
//buttons

// button caption draw flags
static const layout_label_draw_flags cell_caption_draw_flags(
                                                             surf::draw_string_alignment_center |
                                                             surf::draw_string_valignment_center|
                                                             surf::draw_string_single_line      |  
                                                             surf::draw_string_truncation_tail );
                                                                     
//-- button rects
static const layout_rects cost_rect (
                                     layout_rect( 100   , 102,  20, 14 ),
                                     layout_rect( 2*100 , 2*102, 2*20, 2*14 ),
                                     layout_rect( 140  , 67, 80, 31 )
                                    );
                                   
static const layout_rects count_rect (
                                     layout_rect( 75, 128,  40, 20 ),
                                     layout_rect( 2*75, 2*128, 2*40, 2*20 ),
                                     layout_rect( 97, 105, 80, 31 )
                                    );
        

static const layout_rects buy_rect (
                                    layout_rect( 0,   58,  64, 24 ),
                                    layout_rect( 0, 2*58, 128, 48 ),
                                    layout_rect( 0, 0, 80, 31 )
                                   );
                                   
static const layout_rects gift_rect (
                                    layout_rect( 70, 58,  64, 24 ),
                                    layout_rect( 140, 2*58, 128, 48 ),
                                    layout_rect( 90, 0, 80, 31 )
                                   );
                                   
static const layout_rects add_rect (
                                     layout_rect( 265, 8,  166, 40 ),
                                     layout_rect( 530, 16, 331, 79 ),
                                     layout_rect( 410, 15, 198, 46 )
                                    );
                                            
static const sqc_theme_button_layout buy_button( 
                                            layout_alignment( bottom_layout_alignment ),
                                            sqc_theme_button_buy, 
                                            buy_rect
                                            );      
                                            
static const sqc_theme_button_layout gift_button( 
                                            layout_alignment( bottom_layout_alignment ),
                                            sqc_theme_button_gift, 
                                            gift_rect
                                           ); 
                                           
static const image_button_layout add_button( 
                                            layout_alignment( top_layout_alignment ),
                                            image_names( 
                                                         "slry_butoon_add_coins_normal", 
                                                         "slry_butoon_add_coins_normal@2x", 
                                                         "slry_butoon_add_coins_normal_ipad" 
                                                       ), 
                                            image_names( 
                                                        "slry_butoon_add_coins_selected", 
                                                        "slry_butoon_add_coins_selected@2x", 
                                                        "slry_butoon_add_coins_selected_ipad" 
                                                       ), 
                                            add_rect
                                            );   
                                           
static const font_layout buy_button_label_font (layout_font_name( "Arial-BoldMT.otf" ),  //Arial
                                                layout_font_sizes( 12, 2*12, 14 ) );      
                                                
static const font_layout gift_button_label_font (layout_font_name( "Arial-BoldMT.otf" ),  //Arial
                                                 layout_font_sizes( 12, 2*12, 14 ) );   
                                                
static const font_layout cost_label_font (layout_font_name( "Arial-BoldMT.otf" ),  //Arial
                                          layout_font_sizes( 15, 2*15, 21 ) );    
                                                
static const font_layout count_label_font (
                                           layout_font_name( "Arial-BoldMT.otf" ),  //Arial
                                           layout_font_sizes( 17, 34, 24) );   
                                           
static const font_layout add_button_label_font (layout_font_name( "Arial-BoldMT.otf" ),  //Arial
                                                layout_font_sizes( 16, 2*16, 20 ) );                  
                               

static const label_layout add_caption( layout_alignment( layout_halignment_left | layout_valignment_top ),
                                       common_resources::string_title_add_coins,
                                       layout_white_color,
                                       cell_caption_draw_flags,
                                       add_button_label_font,
                                       add_rect,
                                       shadow
                                       
                                       );
                 
static const label_layout buy_caption( layout_alignment( layout_halignment_left | layout_valignment_bottom ),
                                       common_resources::string_text_buy,
                                       layout_white_color,
                                       cell_caption_draw_flags,
                                       buy_button_label_font,
                                       buy_rect,
                                       shadow
                                    ); 
                                    
static const label_layout gift_caption(
                                      layout_alignment( layout_halignment_left | layout_valignment_bottom ),
                                      common_resources::string_text_gift,
                                      layout_white_color,
                                      cell_caption_draw_flags,
                                      buy_button_label_font,
                                      gift_rect,
                                      shadow
                                     );
                                     
static const layout_rects item_background_rect (
                                                layout_rect( 0, 0, 0, 0 ),
                                                layout_rect( 0, 0, 0, 0 ),
                                                layout_rect( 15, 20, 88, 93 )
                                               );                                                                                 
                                                                                        
                                     
static const image_layout salary_envelope_image(
                                      layout_alignment( layout_halignment_left | layout_valignment_bottom ),
                                      image_names("slry_icon_envelope", "slry_salary_envelope@2", "slry_icon_envelope_ipad" ),
                                      image_rects( 
                                                  layout_rect( 0, 91, 58, 58 ),
                                                  layout_rect( 0, 2*91, 2*58, 2*58 ),
                                                  layout_rect( 0, 40, 48, 44 ) ) );
                                                  
        
static const image_layout salary_buks_image(
                                  layout_alignment( layout_halignment_left |
                                                    layout_valignment_bottom ),
                                  image_names( "salary_buks", "slry_salary_buks@2", "slry_icon_buks_ipad"),
                                  image_rects( 
                                              layout_rect( 75, 103, 19, 17 ),
                                              layout_rect( 145, 2*103, 2*19, 2*17 ),
                                              layout_rect( 100, 67, 19, 17 ) ) );
                                                                                                                                                                                                                                        
// Count captions
static const label_layout label_count(
                layout_alignment( layout_halignment_left |
                                  layout_valignment_bottom ),
                    layout_string_resource( "*SalaryCount", "" ),
                    layout_white_color,
                    draw_flags_hleft_vcenter,
                    count_label_font,
                    count_rect,
                    shadow);
                    
static const label_layout label_cost(
                layout_alignment( layout_halignment_left |
                                  layout_valignment_bottom ),
                   layout_string_resource( "*SalaryCost", "" ),
                   layout_white_color,
                   draw_flags_hleft_vcenter,
                   cost_label_font,
                   cost_rect,
                   shadow);
                   
static const sqc_word  salary_cost[] = {1,3,5,7,10,15};    

}// END: namespace salary_dlg
}// END: namespace city_dlg_layout


END_NAMESPACE_SQC_FRAMEWORK




#endif