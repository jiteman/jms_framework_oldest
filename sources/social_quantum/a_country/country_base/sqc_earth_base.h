#pragma once

#include "../sqc/sqc_base.h"
#include "../framework/sqc_framework_defs.h"
#include "../framework/texture/sqc_texture_builder.h"

NAMESPACE_SQC_FRAMEWORK

struct earth_texture_info {
	earth_texture_info( surf::surf_point p , sqc_texture_ptr tx)
    	: point(p), texture(tx)
    {}
    surf::surf_point point;
    sqc_texture_ptr texture;
};

typedef std::vector<earth_texture_info> texture_list_type;


class sqc_earth_base : public sqc_noncopyable
{
public:
    /// txt_zero - zero point of texture relative screen
    /// size_in_block - size texture in blocks
    sqc_earth_base(sqc_string prefix, sqc_point field_start_point, surf::surf_nsize offsets, surf::surf_nsize size_in_blocks);
	virtual void render( surf::surf_context_ptr ctx );
    void create_label(surf::surf_context_ptr ctx, sqc_string str, surf::surf_point point);
    void draw_box(surf::surf_context_ptr ctx, surf::surf_point start_point, surf::surf_nsize nsize, surf::surf_npoint start_box );
    void generate_texture_list( sqc_coord_convertor &coord_conv );
    void fill_set(surf::surf_point start_point, surf::surf_nsize nsize, surf::surf_npoint start_box );
    void set_start_point( sqc_point start_point );
 
private:
    int m_oetx;
    int m_oety;

    int m_stxt;
    surf::surf_point m_txt_zero;

	sqc_point m_field_start_point;
    texture_list_type m_texture_list;
    surf::surf_nsize m_size_in_blocks;
    sqc_string m_prefix;
    
};

typedef std::tr1::shared_ptr<sqc_earth_base> sqc_earth_base_ptr;

END_NAMESPACE_SQC_FRAMEWORK
