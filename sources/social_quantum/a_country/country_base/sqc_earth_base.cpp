/*
 *  sqc_earth_base.cpp
 *  aCountry
 *
 *  Created by Василий (albacil@gmail.com) on 31.08.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "sqc_earth_base.h"

#include "sqc_field_base.h"
#include "sqc_zorder_sort.h"
#include "framework/sqc_framework.h"
#include "framework/texture/sqc_texture_builder.h"

//#include "milk_defs.h"

NAMESPACE_SQC_FRAMEWORK

#define LOG_2VAR(v1, v2) surf::surf_info() << #v1 << ": " << (v1) << ", " << #v2 << ": " << (v2)

sqc_earth_base::sqc_earth_base(sqc_string prefix, sqc_point field_start_point, surf::surf_nsize offsets, surf::surf_nsize size_in_blocks)
    : m_oetx(offsets.cx)	// offset earth texture x relative zero scene (increases inversely)
    , m_oety(offsets.cy)	// offset earth texture y relative zero scene
	, m_stxt(128)
    , m_field_start_point( field_start_point )
    , m_size_in_blocks( size_in_blocks )
    , m_prefix(prefix)
    
{
}

void sqc_earth_base::generate_texture_list( sqc_coord_convertor &coord_conv )
{
    // get start coordinate of bridg
    surf::surf_point start_coord = coord_conv.field_to_screen( m_field_start_point );
    surf::surf_nsize screen_size = coord_conv.get_screen_size();

    // get offset zero scene relative game screen
    float zero_scene_x = start_coord.x; 
    float zero_scene_y = start_coord.y;
    
    //LOG_2VAR(zero_scene_x, zero_scene_y);

    // calculate left bottom point of the Earth Texture relative screen (must be negative value)
    float earth_x = zero_scene_x - m_oetx;
    float earth_y = zero_scene_y - m_oety;


	//LOG_2VAR(earth_x, earth_y);
   
    // calculate index of start block of the Large Earth Texture for drawing
    
    int idx_block_x = floor( -earth_x / m_stxt );
    int idx_block_y = floor( -earth_y / m_stxt );

    //LOG_2VAR(idx_block_x, idx_block_y);
    
    // calculate point start drawing texture relative screen
    surf::surf_point start_point(
    	m_stxt * idx_block_x + earth_x,
        m_stxt * idx_block_y + earth_y
    );
    
    surf::surf_npoint screen_start_block(idx_block_x, idx_block_y);
    
 	// caluclate size of screen in blocks
    surf::surf_nsize screen_block(
    	ceil( (-start_point.x + screen_size.cx) / m_stxt),
        ceil( (-start_point.y + screen_size.cy) / m_stxt)
    );

	//LOG_2VAR(dx, dy);


	//surf::surf_info() << "block_x: "<< idx_block_x << ", " << "block_y: " << idx_block_y;
	
    //LOG_2VAR(idx_block_x, idx_block_y);

	//draw_box(ctx, surf::surf_point(0,0), screen_size, surf::surf_npoint(idx_block_x, idx_block_y));

    fill_set( start_point, screen_block,  screen_start_block );
}

void sqc_earth_base::create_label(surf::surf_context_ptr ctx, sqc_string str, surf::surf_point point)
{
	surf::surf_font_ptr font = framework().graphics().create_font(12, "Arial.otf");
	font->draw(ctx, 
    	str, 
        point, 
        surf::surf_size(m_stxt, m_stxt),
        surf::draw_string_alignment_center | surf::draw_string_valignment_center,
        surf::surf_byte_color(255, 0, 0, 255),
        surf::surf_byte_color(0, 0, 0, 255),
        surf::surf_size()
    );
        
    // draw( surf_context_ptr ctx, surf_string const &s, surf_point const &point, surf_size const &size, surf_draw_string_flags flags, surf_color const &color, surf_color const &shadow_color, surf_size const &shadow_size );
}

void sqc_earth_base::fill_set(surf::surf_point start_point, surf::surf_nsize nsize, surf::surf_npoint start_box )
{
	m_texture_list.clear();

	int mblock_x = nsize.cx; //ceil(nsize.cx * 1. / stxt);  // max index of Earth Texture Block x
	int mblock_y = nsize.cy; //ceil(nsize.cy * 1. / stxt);  // max index of Earth Texture Block y
    
    //sqc_info() << "<<< fillset begin";
    
    //LOG_2VAR(mblock_x, mblock_y);
    
    //LOG_2VAR(start_point.x, start_point.y);
    
    sqc_texture_proxy &proxy = framework::framework().texture_proxy();
    
    surf::surf_point texture_point(start_point.x, start_point.y);
	
    for (int iey = start_box.y; iey < start_box.y + mblock_y; ++iey)
    {
        texture_point.x = start_point.x;
        for (int iex = start_box.x; iex < start_box.x + mblock_x; ++iex)
        {
            std::ostringstream texture_name;

            // texture name: earth_y_x
            texture_name << m_prefix << "_" << m_size_in_blocks.cy - 1 - iey << "_" << iex;
            // sqc_info() << "texture_name: " << texture_name;

            sqc_texture_ptr texture = proxy.get_texture( texture_name.str().c_str(), framework::load_priority_normal );

            if ( texture ) {
                //LOG_2VAR(tex_x, tex_y);
                m_texture_list.push_back( earth_texture_info( texture_point, texture ) );
            }
            
            texture_point.x += m_stxt;
        }
        texture_point.y += m_stxt;
    }
    //sqc_info() << "<<< fillset end";


}

void sqc_earth_base::render( surf::surf_context_ptr ctx )
{
	for (texture_list_type::iterator it = m_texture_list.begin() ; it != m_texture_list.end(); ++it) {
		it->texture->draw( ctx, it->point, sqc_texture_draw_info().set_use_anchor( false ) );
    }
}

void sqc_earth_base::set_start_point( sqc_point start_point ) {
    m_field_start_point = start_point;
}

END_NAMESPACE_SQC_FRAMEWORK
