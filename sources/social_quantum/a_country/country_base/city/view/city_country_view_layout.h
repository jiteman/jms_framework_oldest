//
//  city_country_view_layout.h
//  aCountry
//
//  Created by Andrey Kunitsyn on 10/27/11.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#ifndef aCountry_city_country_view_layout_h
#define aCountry_city_country_view_layout_h

NAMESPACE_SQC_CITY
//struct image_info
namespace city_country_view_layout {
	
    using namespace framework;
    
	// CityButtonsGuiManager
    
    static const sqc_dword gift_rect_x [] = { 53, 106,  6 }; 
    static const sqc_dword gift_rect_y [] = {  2,   6, 119 }; 
    static const sqc_dword width[] = {480, 960, 1024};
    
    static const image_layout gift_number_img(bottom_layout_alignment,
                                              image_names(
                                                          "button_gift_number",
                                                          "button_gift_number@2x",
                                                          "button_gift_number_ipad"),
                                              image_rects( layout_rect( 34, 40, 25, 15 ),
                                                          layout_rect( 68, 80, 46, 28 ),
                                                          layout_rect( 50, 50, 34, 34 )));
    
	static const image_button_layout gift_button( bottom_layout_alignment,
                                                 image_names( "button_gift_normal",
                                                             "button_gift_normal@2x",
                                                             "button_gift_normal_ipad" ),
                                                 image_pressed_names( "button_gift_selected",
                                                                     "button_gift_selected@2x",
                                                                     "button_gift_selected_ipad" ),
                                                 image_rects( layout_rect( gift_rect_x[0], gift_rect_y [0], 49, 49 ),
                                                             layout_rect( gift_rect_x[1], gift_rect_y [1], 96, 96 ),
                                                             layout_rect( gift_rect_x[2], gift_rect_y [2], 72, 72 ) ) );
    
    static const layout_string_resource
    string_gift_count( "*", "%d" ); // to do: *resources!
    
    static const font_layout 
    font_gift_count( 
                    layout_font_name( "Arial-BoldMT.otf" ), 
                    layout_font_sizes( 11, 22, 20 ) );
    
    static const label_layout
    label_gift_count(
                     bottom_layout_alignment,
                     string_gift_count,
                     layout_white_color,
                     draw_flags_hcenter_vcenter,
                     font_gift_count,
                     image_rects( layout_rect( 34, 39, 25, 15 ),
                                 layout_rect( 68, 78, 46, 28 ),
                                 layout_rect( 50, 49, 34, 34 )));
    
    static const int icon_button_width[] = { 49, 96, 72 };
    static const int icon_button_height[] = { 49, 96, 72 };
    
    static const layout_sizes button_size(
                                          layout_size( icon_button_width[0], icon_button_height[0] ),
                                          layout_size( icon_button_width[1], icon_button_height[1] ),
                                          layout_size( icon_button_width[2], icon_button_height[2] ) );
    
    // distance beetwen buttons (y)
    static const int button_distance[] = { 2, 2*2, 5 };
    
    static const int bottom_row_y[] = {51-49,102-96,78-72};
    static const int right_col_x[] = { width[0] - 429 - 49, width[1] - 858 - 96, width[2] - 946 - 72 };
    static const int col_step[] = { 
        icon_button_width[0]+button_distance[0],
        icon_button_width[1]+button_distance[1],
        icon_button_width[2]+button_distance[2] };
        
    static const int row_step[] = { 
        icon_button_height[0]+button_distance[0],
        icon_button_height[1]+button_distance[1],
        icon_button_height[2]+button_distance[2] };
    
	static const image_button_layout friend_button( bottom_layout_alignment,
                                                   image_names( "guiButtonFriends",
                                                               "guiButtonFriends_HD",
                                                               "guiButtonFriends_iPad" ),
                                                   image_pressed_names( "guiButtonFriendsOn",
                                                                       "guiButtonFriendsOn_HD",
                                                                       "guiButtonFriendsOn_iPad" ),
                                                   image_rects( layout_rect( right_col_x[0], bottom_row_y[0], 49, 49 ),
                                                               layout_rect( right_col_x[1], bottom_row_y[1], 96, 96 ),
                                                               layout_rect( right_col_x[2], bottom_row_y[2], 72, 72 ) ) );
	
    static const image_button_layout market_button(
                                                   layout_alignment( layout_halignment_right|layout_valignment_bottom ),
                                                   image_names( "button_market_normal", 
                                                               "button_market_normal@2x", 
                                                               "button_market_normal_ipad" ),
                                                   image_pressed_names( "button_market_selected",
                                                                       "button_market_selected@2x",
                                                                       "button_market_selected_ipad" ),
                                                   image_rects( layout_rect( right_col_x[0]+col_step[0], bottom_row_y[0], 49, 49 ),
                                                               layout_rect( right_col_x[1]+col_step[1], bottom_row_y[1], 96, 96 ),
                                                               layout_rect( right_col_x[2]+col_step[2], bottom_row_y[2], 72, 72 ) ) );
    
	
	static const image_button_layout menu_button( 
                                                 layout_alignment( layout_halignment_right|layout_valignment_bottom ),
                                                 image_names( "button_settings_normal", 
                                                             "button_settings_normal@2x", 
                                                             "button_settings_normal_ipad" ),
                                                 image_pressed_names( "button_settings_selected",
                                                                     "button_settings_selected@2x",
                                                                     "button_settings_selected_ipad" ),
                                                 image_rects( layout_rect( right_col_x[0], bottom_row_y[0]+row_step[0], 49, 49 ),
                                                             layout_rect( right_col_x[1], bottom_row_y[1]+row_step[1], 96, 96 ),
                                                             layout_rect( right_col_x[2], bottom_row_y[2]+row_step[2], 72, 72 ) ) );
	
	static const image_button_layout edit_button(
                                                 layout_alignment( layout_halignment_right|layout_valignment_bottom ),
                                                 image_names( "button_edit_normal",
                                                             "button_edit_normal@2x", 
                                                             "button_edit_normal_ipad" ),
                                                 image_pressed_names( "button_edit_selected",
                                                                     "button_edit_selected@2x",
                                                                     "button_edit_selected_ipad" ),
                                                 image_rects( layout_rect( right_col_x[0], bottom_row_y[0], 49, 49 ),
                                                             layout_rect( right_col_x[1], bottom_row_y[1], 96, 96 ),
                                                             layout_rect( right_col_x[2], bottom_row_y[2], 72, 72 ) ) );
    
    static const image_button_layout achive_button(
                                                   layout_alignment( layout_halignment_right|layout_valignment_top ),
                                                   image_names( "achive_button_3g_0",
                                                               "achive_button_4g_0",
                                                               "achive_button_ipad_0" ),
                                                   image_pressed_names( "achive_button_3g_1",
                                                                       "achive_button_4g_1",
                                                                       "achive_button_ipad_1" ) ,
                                                   image_rects( layout_rect( right_col_x[0], 49, 36, 36 ),
                                                               layout_rect( right_col_x[1], 98, 72, 72 ),
                                                               layout_rect( right_col_x[2], 67, 55, 55 ) ) );
    
    static const image_button_layout top_button(
                                                layout_alignment( layout_halignment_right|layout_valignment_top ),
                                                image_names( "top_button_3g_0",
                                                            "top_button_4g_0",
                                                            "top_button_ipad_0" ),
                                                image_pressed_names( "top_button_3g_1",
                                                                    "top_button_4g_1",
                                                                    "top_button_ipad_1" ) ,
                                                image_rects( layout_rect( right_col_x[0], 87, 36, 36 ),
                                                            layout_rect( right_col_x[1], 174, 72, 72 ),
                                                            layout_rect( right_col_x[2], 124, 55, 55 ) ) );
    
    static const image_button_layout league_button(
                                                   layout_alignment( layout_halignment_right|layout_valignment_top ),
                                                   image_names( "",
                                                               "",
                                                               "" ),
                                                   image_pressed_names( "",
                                                                       "",
                                                                       "" ) ,
                                                   image_rects( layout_rect( right_col_x[0], 125, 36, 36 ),
                                                               layout_rect( right_col_x[1], 250, 72, 72 ),
                                                               layout_rect( right_col_x[2], 182, 55, 55 ) ) );
    
    
    
        static const sqc_dword message_rect_x [] = { 2, 4, 6 }; 
        static const sqc_dword message_rect_y [] = { 102-49, 204-96, 159-72 }; 
    
        static const image_rects message_and_quest_rects[] = {image_rects( layout_rect( message_rect_x[0], message_rect_y[0], 49, 49 ),
                                                         layout_rect( message_rect_x[1], message_rect_y[1], 96, 96 ),
                                                         layout_rect( message_rect_x[2], message_rect_y[2] + 108, 72, 72 )),
        image_rects( layout_rect( message_rect_x[0], message_rect_y[0] + 51, 49, 49 ),
                    layout_rect( message_rect_x[1], message_rect_y[1] + 98, 96, 96 ),
                    layout_rect( message_rect_x[2], message_rect_y[2] + 74 + 109, 72, 72 )) };
    
    static const image_rects quest_label_rects
    ( layout_rect( 19, 2, 26, 16 ),
     layout_rect( 39, 2, 48, 32 ),
     layout_rect( 30, 2, 30, 20 ));
    
    
    static const layout_string_resource
    string_quest_count( "*", "x %d" ); // to do: *resources!
    
    static const font_layout 
    font_quest_count( 
                     layout_font_name( "Arial-BoldMT.otf" ), 
                     layout_font_sizes( 13, 22, 20 ) );
    
    static const label_layout
    label_quest_count(
                      bottom_layout_alignment,
                      string_quest_count,
                      layout_white_color,
                      draw_flags_hcenter_vcenter,
                      font_quest_count,
                      quest_label_rects);
    
    static const image_button_layout quest_button(
                                                  layout_alignment( layout_halignment_left|layout_valignment_bottom ),
                                                  image_names( "button_quest_all_0",
                                                              "button_quest_all@2x_0",
                                                              "button_quest_all_ipad_0" ),
                                                  image_pressed_names( "button_quest_all_1",
                                                                      "button_quest_all@2x_1",
                                                                      "button_quest_all_ipad_1" ),
                                                  message_and_quest_rects[1] );
    
    static const image_button_layout message_button(
                                                    layout_alignment( layout_halignment_left|layout_valignment_bottom ),
                                                    image_names( "main_page_message_button_0",
                                                                "main_page_message_button@2x_0",
                                                                "main_page_message_button_ipad_0" ),
                                                    image_pressed_names( "main_page_message_button_1",
                                                                        "main_page_message_button@2x_1",
                                                                        "main_page_message_button_ipad_1" ),
                                                    message_and_quest_rects[0]);
    
    
    static const image_names
    league_bronze_normal_images("button_league_bronze_normal",
                                "button_league_bronze_normal@2x",
                                "button_league_bronze_normal_ipad");
    
    static const image_pressed_names
    league_bronze_selected_images("button_league_bronze_selected",
                                  "button_league_bronze_selected@2x",
                                  "button_league_bronze_selected_ipad");
    
    static const image_names
    league_diamond_normal_images("button_league_diamond_normal",
                                 "button_league_diamond_normal@2x",
                                 "button_league_diamond_normal_ipad");
    
    static const image_pressed_names
    league_diamond_selected_images("button_league_diamond_selected",
                                   "button_league_diamond_selected@2x",
                                   "button_league_diamond_selected_ipad");
    
    static const image_names
    league_gold_normal_images("button_league_gold_normal",
                              "button_league_gold_normal@2x",
                              "button_league_gold_normal_ipad");
    
    static const image_pressed_names
    league_gold_selected_images("button_league_gold_selected",
                                "button_league_gold_selected@2x",
                                "button_league_gold_selected_ipad");
    
    static const image_names
    league_platinum_normal_images("button_league_platinum_normal",
                                  "button_league_platinum_normal@2x",
                                  "button_league_platinum_normal_ipad");
    
    static const image_pressed_names
    league_platinum_selected_images("button_league_platinum_selected",
                                    "button_league_platinum_selected@2x",
                                    "button_league_platinum_selected_ipad");
    
    static const image_names
    league_silver_normal_images("button_league_silver_normal",
                                "button_league_silver_normal@2x",
                                "button_league_silver_normal_ipad");
    
    static const image_pressed_names
    league_silver_selected_images("button_league_silver_selected",
                                  "button_league_silver_selected@2x",
                                  "button_league_silver_selected_ipad");
    
    static int top_row[] = { 1, 2, 3 };
    
    //
    // Quests
    //
    
    // To Do: about 80 quests
    //-- 
    static const image_button_layout quest_test_1_button( top_layout_alignment,
                                                         image_names( "quest1",
                                                                     "quest1@2x",
                                                                     "quest1_ipad" ),
                                                         image_pressed_names( "quest1",
                                                                             "quest1@2x",
                                                                             "quest1_ipad" ),
                                                         image_rects( layout_rect( 3, top_row[0] + 29 + 35, 49, 49 ),
                                                                     layout_rect( 6, top_row[1] + 56 + 67, 96, 96 ),
                                                                     layout_rect( 6, top_row[2] + 50 + 33, 72, 72 ) ) );
    
    static const image_button_layout quest_test_2_button( top_layout_alignment,
                                                         image_names( "quest2",
                                                                     "quest2@2x",
                                                                     "quest2_ipad" ),
                                                         image_pressed_names( "quest2",
                                                                             "quest2@2x",
                                                                             "quest2_ipad" ),
                                                         image_rects( layout_rect( 3, top_row[0] + 29 + 34 + 52, 49, 49 ),
                                                                     layout_rect( 6, top_row[1] + 56 + 66 + 99, 96, 96 ),
                                                                     layout_rect( 6, top_row[2] + 50 + 32 + 75, 72, 72 ) ) );
    //--
    
    
    
    struct image_button
    {
        image_names normal;
        image_pressed_names pressed;
        
        image_button(image_names n, image_pressed_names p)
        : normal(n),
        pressed(p)
        {}
    };             
    
    static image_button league_images_button [] = { image_button(league_bronze_normal_images,
                                                                 league_bronze_selected_images),   // level = 1
        image_button(league_silver_normal_images,
                     league_silver_selected_images),   // level = 2
        image_button(league_gold_normal_images,
                     league_gold_selected_images),     // level = 3
        image_button(league_platinum_normal_images,
                     league_platinum_selected_images), // level = 4
        image_button(league_diamond_normal_images,
                     league_diamond_selected_images) };// level = 5
    
    
    static const font_layout add_coins_font (layout_font_name( "Arial-BoldMT.otf" ),
                                             layout_font_sizes( 10, 20, 14 ) );   
    
    struct add_coins_rects
    {   
        layout_rects button_rects;
        layout_rects caption_rects;
    };
    
        static const add_coins_rects add_coins_rect [] = { { layout_rects (layout_rect(  3, top_row[0] +  29, 127, 32 ),
                                                          layout_rect(  6, top_row[1] +  56, 254, 64 ),
                                                          layout_rect(  6, top_row[2] + 50, 241, 29 )),
        layout_rects (layout_rect(30, top_row[0] +  30, 100, 30 ),
                      layout_rect( 60, top_row[1] + 60, 200, 59 ),
                      layout_rect( 40, top_row[2] + 50, 208, 29 ))},
        
        { layout_rects (layout_rect( 3, top_row[0], 127, 32 ),
                        layout_rect(  6, top_row[1], 254, 64 ),
                        layout_rect(  6, top_row[2], 241, 29 )),
            layout_rects (layout_rect(30, top_row[0], 100, 30 ),
                          layout_rect( 60, top_row[1], 200, 59 ),
                          layout_rect(  6, top_row[2], 241, 29 ))}
    };
    
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
                     add_coins_rect[0].button_rects );
    
    static const label_layout
    add_coins_caption( layout_alignment( layout_halignment_left | layout_valignment_top ), //layout_halignment_left | layout_valignment_top
                      common_resources::string_message_add_coins_and_bucks,
                      layout_white_color,
                      draw_flags_hcenter_vcenter,
                      add_coins_font,
                      add_coins_rect[0].caption_rects);
    
    static const image_button_layout leave_friend_button( layout_alignment( layout_halignment_right|layout_valignment_bottom ),
                                                         image_names( "guiButtonHome", "guiButtonHome_HD", "guiButtonHome_iPad" ),
                                                         image_pressed_names( "guiButtonHomeOn", "guiButtonHome_HD", "guiButtonHome_iPad" ),
                                                         image_rects( layout_rect( right_col_x[0], bottom_row_y[0], 49, 49 ),
                                                                     layout_rect( right_col_x[1], bottom_row_y[1], 96, 96 ),
                                                                     layout_rect( right_col_x[2], bottom_row_y[2], 72, 72 ) ) );
    
    
} // namespace city_country_view_layout

END_NAMESPACE_SQC_CITY

#endif
