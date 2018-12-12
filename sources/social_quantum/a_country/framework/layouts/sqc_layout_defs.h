/*
 *  sqc_framework.h
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef __SQC_COMMAND_PROXY_H_INCLUDED__
#define __SQC_COMMAND_PROXY_H_INCLUDED__

#include "../framework/sqc_framework_defs.h"

NAMESPACE_SQC_FRAMEWORK

// theme size
enum sqc_theme_size {
	sqc_theme_small,
	sqc_theme_normal,
	sqc_theme_large,
	sqc_theme_countof,
    sqc_theme_first = sqc_theme_small,
};

inline std::string
print_theme_size_name( sqc_theme_size theme ) {
	if ( sqc_theme_small == theme ) return "theme_small";
    if ( sqc_theme_normal == theme ) return "theme_normal";
    if ( sqc_theme_large == theme ) return "theme_large";
    return "unknown theme";
}

// themes dimensions
namespace themes_size {
	namespace small {
		static const int width	= 480;
		static const int height	= 320;
	}
	namespace normal {
		static const int width	= 960;
		static const int height	= 640;
	}
	namespace large {
		static const int width	= 1024;
		static const int height	= 768;
	}
}

typedef surf::surf_val		layout_val;
typedef surf::surf_point    layout_point;
typedef surf::surf_size		layout_size;
typedef surf::surf_rect		layout_rect;

typedef surf::surf_9way_info slice_offset;

typedef std::string			layout_resource_id;
typedef std::string			layout_font_name;
typedef unsigned short		layout_font_size;
typedef std::string			layout_string;

enum layout_alignment_t {
	layout_halignment_left      = (1 << 0),
	layout_halignment_center    = (1 << 1),
	layout_halignment_right     = (1 << 2),
    layout_halignment_no_width  = (1 << 3),//for layout_halignment_right
	layout_halignment_fill      = (1 << 4),
    
	layout_valignment_top       = (1 << 10),
	layout_valignment_bottom    = (1 << 11),
    layout_valignment_no_height = (1 << 12),// for layout_valignment_top
	layout_valignment_center    = (1 << 13),
	layout_valignment_fill      = (1 << 14),
};

typedef unsigned int layout_alignment_mask;
static const unsigned int layout_alignment_hmask = ( 1<<5 ) - 1;
static const unsigned int layout_alignment_vmask = (( 1<<5 ) - 1)<<10;
class layout_alignment {
public:
    layout_alignment() {
        m_mask = layout_alignment_mask( 0 );
    }
    
	layout_alignment( layout_alignment_mask mask ) {
		m_mask = mask;
	}
    
//    layout_alignment operator |( const layout_alignment &other ) const {
//        layout_alignment result = *this;
//        return result |= other;
//    }
    
//    layout_alignment &operator |=( const layout_alignment &other ) {
//        m_mask |= other.m_mask;
//        return *this;
//    }
    
	const layout_alignment_mask mask() const {
		return m_mask;
	}
protected:
	layout_alignment_mask	m_mask;
};

//static const layout_alignment layout_halignment_left( layout_halignment_left_t );
//static const layout_alignment layout_halignment_center( layout_halignment_center_t );
//static const layout_alignment layout_halignment_right( layout_halignment_right_t );
//static const layout_alignment layout_halignment_no_width( layout_halignment_no_width_t );
//static const layout_alignment layout_halignment_fill( layout_halignment_fill_t );
//static const layout_alignment layout_valignment_top( layout_valignment_top_t );
//static const layout_alignment layout_valignment_bottom( layout_valignment_bottom_t );
//static const layout_alignment layout_valignment_no_height( layout_valignment_no_height_t );
//static const layout_alignment layout_valignment_center( layout_valignment_center_t );
//static const layout_alignment layout_valignment_fill( layout_valignment_fill_t );

static const layout_alignment top_layout_alignment( layout_halignment_left|layout_valignment_top );
static const layout_alignment bottom_layout_alignment( layout_halignment_left|layout_valignment_bottom );
static const layout_alignment programm_layout_alignment( layout_halignment_left|layout_valignment_bottom );

static const layout_alignment layout_alignment_left_top = top_layout_alignment;

static const layout_alignment layout_alignment_center_top = layout_halignment_center | layout_valignment_top;
static const layout_alignment layout_alignment_top = layout_alignment_center_top;
static const layout_alignment layout_alignment_right_top = layout_halignment_right | layout_valignment_top;
static const layout_alignment layout_alignment_left_center = layout_halignment_left | layout_valignment_center;
static const layout_alignment layout_alignment_left = layout_alignment_left_center;
static const layout_alignment layout_alignment_center_center = layout_halignment_center | layout_valignment_center;
static const layout_alignment layout_alignment_center = layout_alignment_center_center;
static const layout_alignment layout_alignment_right_center = layout_halignment_right | layout_valignment_center;
static const layout_alignment layout_alignment_right = layout_alignment_right_center;
static const layout_alignment layout_alignment_left_bottom = bottom_layout_alignment;
static const layout_alignment layout_alignment_center_bottom = layout_halignment_center | layout_valignment_bottom;
static const layout_alignment layout_alignment_bottom = layout_alignment_center_bottom;
static const layout_alignment layout_alignment_right_bottom = layout_halignment_right | layout_valignment_bottom;
static const layout_alignment layout_alignment_left_fill = layout_halignment_left | layout_valignment_fill;
static const layout_alignment layout_alignment_right_fill = layout_halignment_right | layout_valignment_fill;
static const layout_alignment layout_alignment_fill = layout_halignment_fill | layout_valignment_fill;

//
//	layout theme
//
template <class T>
class layout_themes_t {
public:
    layout_themes_t() {
        for ( size_t counter = sqc_theme_first; counter < sqc_theme_countof; counter += 1 ) {
            m_layouts[ counter ] = T();
        }
    }
    
	layout_themes_t( const T &small, const T &normal, const T &large ) {
		m_layouts[sqc_theme_small]	= small;
		m_layouts[sqc_theme_normal]	= normal;
		m_layouts[sqc_theme_large]	= large;
	}
    
	virtual ~layout_themes_t() {
	}
    
	const T& at( const sqc_theme_size theme_size ) const {
		return m_layouts[theme_size];
	}
    void set_at( const sqc_theme_size theme_size, const T& elem ) {
		m_layouts[theme_size] = elem;
	}    
    
    template< class Another_type >
    layout_themes_t operator +( const layout_themes_t< Another_type > &other ) const {
        layout_themes_t result = *this;
        return result += other;
    }
    
    template< class Another_type >
    layout_themes_t &operator +=( const layout_themes_t< Another_type > &other ) {
        for ( size_t counter = sqc_theme_first; counter < sqc_theme_countof; counter += 1 ) {
            m_layouts[ counter ] += other.at( static_cast< sqc_theme_size >( counter ) );
        }
        
        return *this;
    }

    template< class Another_type >
    layout_themes_t operator -( const layout_themes_t< Another_type > &other ) const {
        layout_themes_t result = *this;
        return result -= other;
    }
    
    template< class Another_type >
    layout_themes_t &operator -=( const layout_themes_t< Another_type > &other ) {
        for ( size_t counter = sqc_theme_first; counter < sqc_theme_countof; counter += 1 ) {
            m_layouts[ counter ] -= other.at( static_cast< sqc_theme_size >( counter ) );
        }
        
        return *this;
    }
    
    template< class Another_type >
    layout_themes_t operator *( const layout_themes_t< Another_type > &other ) const {
        layout_themes_t result = *this;
        return result *= other;
    }
    
    template< class Another_type >
    layout_themes_t &operator *=( const layout_themes_t< Another_type > &other ) {
        for ( size_t counter = sqc_theme_first; counter < sqc_theme_countof; counter += 1 ) {
            m_layouts[ counter ] *= other.at( static_cast< sqc_theme_size >( counter ) );
        }
        
        return *this;
    }
    
protected:
	T m_layouts[sqc_theme_countof];
    
};

typedef layout_themes_t<layout_val>				layout_vals;
typedef layout_themes_t<layout_rect>			layout_rects;
typedef layout_themes_t<layout_size>			layout_sizes;
typedef layout_themes_t<layout_point>			layout_points;
typedef layout_themes_t<layout_font_name>		layout_font_names;
typedef layout_themes_t<layout_font_size>		layout_font_sizes;
typedef layout_themes_t<layout_string>			layout_strings;
typedef layout_themes_t<slice_offset> 			slice_offsets;
typedef layout_themes_t< layout_alignment >     layout_alignments;

//
//	basic layout
//
class basic_layout {
public:
	basic_layout( const layout_alignment& alignment ) 
		: m_alignments( alignment, alignment, alignment )
    {}
    
    basic_layout( const layout_alignments &alignments )
        : m_alignments( alignments )
    {}
    
	const layout_alignment& alignment() const {
		return m_alignments.at( sqc_theme_first );
	}
    
    const layout_alignments &get_alignments() const {
        return m_alignments;
    }
    
protected:
	layout_alignments m_alignments;
    
};


//
//	font layout
//

class font_layout {
public:
	font_layout( const layout_font_name& name,
				 const layout_font_sizes& sizes )
		: m_names( name,name,name )
		, m_sizes( sizes ) {
	}
	font_layout( const layout_font_names& names,
				const layout_font_sizes& sizes )
	: m_names( names )
	, m_sizes( sizes ) {
	}
	const layout_font_names& names() const {
		return m_names;
	}
	const layout_font_sizes& sizes() const {
		return m_sizes;
	}
	
protected:
	layout_font_names	m_names;
	layout_font_sizes	m_sizes;
};

class layout_string_resource {
public:
	layout_string_resource( 
		const layout_resource_id& resource_id,
		const layout_string& def_value ) 
		: m_resource_id( resource_id )
		, m_def_value( def_value ) {
	}
	const layout_resource_id&	resource_id() const {
		return m_resource_id;
	}
	const layout_string&		def_value() const {
		return m_def_value;
	}
						 
	layout_resource_id	m_resource_id;
	layout_string		m_def_value;
};

//
// layout color
//
typedef float layout_color_component;

class layout_color {
public:
	layout_color( layout_color_component r,
				 layout_color_component g,
				 layout_color_component b,
				 layout_color_component a )
		: m_r( r ), m_g( g ), m_b( b ), m_a( a ) {
	}
    
    explicit layout_color(unsigned int v, layout_color_component a = 1)
    	: m_r( hc(v,16) ), m_g( hc(v, 8) ), m_b( hc(v, 0) ), m_a( a )
    {
    	
    }
    
	const layout_color_component r() const {
		return m_r;
	}
	const layout_color_component g() const {
		return m_g;
	}
	const layout_color_component b() const {
		return m_b;
	}
	const layout_color_component a() const {
		return m_a;
	}
	
protected:
	layout_color_component m_r, m_g, m_b, m_a;
private:
	layout_color_component hc(unsigned int v, unsigned int shift ) 
	{
        unsigned int p = v;
        p = (v >> shift) & 0x0000FF;
        return p / 255.0;
    }
    
};

// predefined colors
static const layout_color	layout_white_color( 1., 1., 1., 1. );
static const layout_color	layout_black_color( 0., 0., 0., 1. );
static const layout_color   layout_green_color( 0.1, 0.8, 0.5, 1.);
static const layout_color	layout_red_color( 1., 0., 0., 1. );

//
//	label layout
//
typedef layout_rects					label_rects;
typedef surf::surf_draw_string_flags	layout_label_draw_flags;

class shadow_layout {
public:
	shadow_layout(const layout_color& clr, const layout_points& offsets) :
		m_shadow_color(clr),m_shadow_offsets(offsets) {
	}
	const layout_color& shadow_color() const {
		return m_shadow_color;
	}
	const layout_points& shadow_offsets() const {
		return m_shadow_offsets;
	}
private:
	layout_color			m_shadow_color;
	layout_points			m_shadow_offsets;
};

class label_layout : public basic_layout {
public:
	label_layout( const layout_alignment& alignment,
				 const layout_string_resource& string_resource,
				 const layout_color& color,
				 const layout_label_draw_flags label_draw_flags,
				 const font_layout& fnt_layout,
				 const label_rects& rects )
		: basic_layout( alignment )
		, m_string_resource( string_resource )
		, m_color( color )
		, m_label_draw_flags( label_draw_flags )
		, m_rects( rects ) 
		, m_font_layout( fnt_layout )
		, m_shadow_color( layout_black_color) {
	}
	
	label_layout( const layout_alignment& alignment,
				 const layout_string_resource& string_resource,
				 const layout_color& color,
				 const layout_label_draw_flags label_draw_flags,
				 const font_layout& fnt_layout,
				 const label_rects& rects,
				 const shadow_layout& shadow)
	: basic_layout( alignment )
	, m_string_resource( string_resource )
	, m_color( color )
	, m_label_draw_flags( label_draw_flags )
	, m_rects( rects ) 
	, m_font_layout( fnt_layout )
	, m_shadow_color( layout_black_color) {
		set_shadow(shadow);
	}
	
	
	label_layout( const layout_alignments& these_alignments,
				 const layout_string_resource& string_resource,
				 const layout_color& color,
				 const layout_label_draw_flags label_draw_flags,
				 const font_layout& fnt_layout,
				 const label_rects& rects )
        : basic_layout( these_alignments )
        , m_string_resource( string_resource )
        , m_color( color )
        , m_label_draw_flags( label_draw_flags )
        , m_rects( rects ) 
        , m_font_layout( fnt_layout )
		, m_shadow_color( layout_black_color)
    {}
    
	const layout_string_resource& string_resource() const {
		return m_string_resource;
	}
	const layout_color&	color() const {
		return m_color;
	}
	const layout_label_draw_flags label_draw_flags() const {
		return m_label_draw_flags;
	}
	const label_rects& rects() const {
		return m_rects;
	}
	const font_layout& fnt_layout() const {
		return m_font_layout;
	}
	const layout_color& shadow_color() const {
		return m_shadow_color;
	}
	const layout_points& shadow_offsets() const {
		return m_shadow_offsets;
	}
	label_layout& set_shadow( const shadow_layout& shadow ) {
		m_label_draw_flags |= surf::draw_string_draw_shadow_enabled;
		m_shadow_color = shadow.shadow_color();
		m_shadow_offsets = shadow.shadow_offsets();
		return *this;
	}
	label_layout with_shadow(const shadow_layout& shadow) const {
		label_layout res(*this);
		return res.set_shadow( shadow );
	}
protected:
	layout_string_resource	m_string_resource;
	layout_color			m_color;
	layout_label_draw_flags m_label_draw_flags;
	label_rects				m_rects;
	font_layout				m_font_layout;
	layout_color			m_shadow_color;
	layout_points			m_shadow_offsets;
};

//
// Theme Button layout
//


class theme_button_layout : public basic_layout {
public:
	theme_button_layout( const layout_alignment& alignment, 
						 const milk::theme_button_type type,
                         const label_rects& rects )
    	: basic_layout( alignment )
        , m_type(type)
        , m_rects(rects)
    {
    }
		
	const milk::theme_button_type& type() const {
		return m_type;
	}

	const label_rects& rects() const {
		return m_rects;
	}
	
protected:
	milk::theme_button_type m_type;
    label_rects	m_rects;
};



//
//	image layout
//
typedef layout_rects	image_rects;
typedef layout_strings	image_names;

class image_layout : public basic_layout {
public:
	image_layout( const layout_alignment& alignment,
				 const image_names& names,
				 const image_rects& rects )
		: basic_layout( alignment )
		, m_names( names )
		, m_rects( rects ) {
	}
    
    image_layout( const layout_alignments &these_alignments,
                 const image_names &these_image_names,
                 const image_rects &these_image_rectangles )
        : basic_layout( these_alignments )
        , m_names( these_image_names )
        , m_rects( these_image_rectangles )
    {}
	
	const image_names& names() const {
		return m_names;
	}
	const image_rects& rects() const {
		return m_rects;
	}
protected:
	image_names m_names;
	image_rects m_rects;
};



//
//	slice image layout
//
class slice_image_layout : public basic_layout {
public:
	slice_image_layout( const layout_alignment& alignment,
				 const image_names& names,
				 const slice_offsets& offsets,
                 const image_rects& rects )
		: basic_layout( alignment )
		, m_names( names )
		, m_offsets( offsets )
        , m_rects( rects ) 
    {
	}
	
	const image_names& names() const {
		return m_names;
	}
	const slice_offsets& offsets() const {
		return m_offsets;
	}
	const image_rects& rects() const {
		return m_rects;
	}
protected:
	image_names m_names;
    slice_offsets m_offsets;
	image_rects m_rects;
};


//
//	image button layout
//
typedef layout_strings	image_pressed_names;

class image_button_layout : public image_layout {
public:
	image_button_layout( const layout_alignment& alignment,
				const image_names& names,
				const image_pressed_names& pressed_names,
				const image_rects& rects ) 
		: image_layout( alignment, names, rects )
		, m_pressed_names( pressed_names ) {
	}
    
	image_button_layout( const layout_alignments& these_alignments,
                        const image_names& these_image_names,
                        const image_pressed_names& these_pressed_image_names,
                        const image_rects& these_image_rectangles ) 
        : image_layout( these_alignments, these_image_names, these_image_rectangles )
        , m_pressed_names( these_pressed_image_names )
    {}
    
	const image_pressed_names& pressed_names() const {
		return m_pressed_names;
	}
	
protected:
	image_pressed_names	m_pressed_names;
};

typedef image_names image_names_type;

class deactivable_image_button_layout : public image_button_layout {
    
public:
    deactivable_image_button_layout( const layout_alignment &the_alignment,
                                    const image_names &active_image_names,
                                    const image_pressed_names &pressed_image_names,
                                    const image_names &inactive_image_names,
                                    const image_rects &image_rectangles )
        : image_button_layout( the_alignment, active_image_names, pressed_image_names, image_rectangles )
        , _inactive_image_names( inactive_image_names )
    {}

	deactivable_image_button_layout( const layout_alignments &these_alignments,
                                    const image_names &these_image_names,
                                    const image_pressed_names &these_pressed_image_names,
                                    const image_names &these_inactive_image_names,
                                    const image_rects &these_image_rectangles ) 
        : image_button_layout( these_alignments, these_image_names, these_pressed_image_names, these_image_rectangles )
        , _inactive_image_names( these_inactive_image_names ) {
	}
    
    const image_names_type &get_inactive_image_names() const {
        return _inactive_image_names;
    }
    
private:
    image_names_type _inactive_image_names;
  
};

//
//	switch button layout
//
typedef layout_rects	switch_rects;

class switch_button_layout : public basic_layout {
public:
	switch_button_layout( const layout_alignment& alignment,
				 const switch_rects& rects )
	: basic_layout( alignment )
	, m_rects( rects ) {
	}
	const image_rects& rects() const {
		return m_rects;
	}
protected:
	image_rects m_rects;
};

// standart switch size
static const layout_sizes
switch_button_size(
	layout_size( 60, 30 ),
	layout_size( 2*60, 30 ),
	layout_size( 2*60, 30 ) );

//
// spinboard layout
//
typedef layout_rects	spinboard_rects;
typedef layout_themes_t< milk::milk_spinboard_theme_flags >     spinboard_theme_flags;

class spinboard_layout : public basic_layout {
public:
	spinboard_layout( const layout_alignment& alignment,
                         const spinboard_rects& rects,
					 milk::milk_spinboard_theme_flags flags=0)
        : basic_layout( alignment )
        , m_rects( rects ),theme_flags(flags,flags,flags) {
	}
	spinboard_layout( const layout_alignment& alignment,
					 const spinboard_rects& rects,
					 const spinboard_theme_flags& flags)
	: basic_layout( alignment )
	, m_rects( rects ),theme_flags(flags) {
	}
	const spinboard_rects& rects() const {
		return m_rects;
	}
	const spinboard_theme_flags flags() const {
		return theme_flags;
	}
protected:
	spinboard_rects m_rects;
	spinboard_theme_flags theme_flags;
};

//
// spinboard pager layout
//

class spinboard_pager_layout : public basic_layout {
public:
	spinboard_pager_layout( const layout_alignment& alignment,
					 const spinboard_rects& rects)
	: basic_layout( alignment )
	, m_rects( rects ){
	}
	const spinboard_rects& rects() const {
		return m_rects;
	}
protected:
	spinboard_rects m_rects;
};

// bevel
typedef layout_rects	bevel_rects;
class base_bevel_layout : public basic_layout {
public:
	base_bevel_layout( const layout_alignment& alignment,
					  const bevel_rects& rects,
					  milk::milk_bevel_type type) 
		: basic_layout( alignment )
		, m_rects( rects )
		, m_type( type )
	{
	}
		
	const bevel_rects& rects() const {
		return m_rects;
	}
	milk::milk_bevel_type type() const {
		return m_type;
	}
	layout_sizes sizes() const {
		return layout_sizes(m_rects.at(sqc_theme_small).size(),
							m_rects.at(sqc_theme_normal).size(),
							m_rects.at(sqc_theme_large).size());
	}
private:
	bevel_rects	m_rects;
	milk::milk_bevel_type	m_type;
};



/// separators
typedef layout_vals separator_offsets;
class vertical_separator_layout : public basic_layout {
public:
	explicit vertical_separator_layout(
						  const layout_alignment& alignment,
						  const separator_offsets& x,
						  const separator_offsets& top = separator_offsets(0,0,0),
						  const separator_offsets& bottom = separator_offsets(0,0,0))
	:  basic_layout( alignment ),m_x(x),m_top(top),m_bottom(bottom),m_type(milk::milk_separator_type_basic){
	}
	const separator_offsets& get_x() const { return m_x;}
	const separator_offsets& get_top() const { return m_top;}
	const separator_offsets& get_bottom() const { return m_bottom;}
	milk::milk_separator_type get_type() const { return m_type;}
protected:
	separator_offsets m_x;
	separator_offsets m_top;
	separator_offsets m_bottom;
	milk::milk_separator_type	m_type;
};

class horizontal_separator_layout : public basic_layout {
public:
	explicit horizontal_separator_layout(
										 const layout_alignment& alignment,
									   const separator_offsets& y,
									   const separator_offsets& left = separator_offsets(0,0,0),
									   const separator_offsets& right = separator_offsets(0,0,0))
	:  basic_layout( alignment ),m_y(y),m_left(left),m_right(right),m_type(milk::milk_separator_type_basic){
	}
	const separator_offsets& get_y() const { return m_y;}
	const separator_offsets& get_left() const { return m_left;}
	const separator_offsets& get_right() const { return m_right;}
	milk::milk_separator_type get_type() const { return m_type;}
protected:
	separator_offsets m_y;
	separator_offsets m_left;
	separator_offsets m_right;
	milk::milk_separator_type	m_type;
};



//
//	dialog layout
//



typedef layout_strings	dialog_backgrounds;
typedef layout_sizes	dialog_sizes;

class dialog_layout : public basic_layout {
public:
	dialog_layout( const layout_alignment& alignment,
				  const dialog_sizes& sizes ) 
		: basic_layout( alignment )
		, m_sizes( sizes) {
	}
	const layout_sizes& sizes() const {
		return m_sizes;
	}
protected:
	dialog_sizes		m_sizes;
};

typedef surf::surf_rect bevel_offset;
typedef layout_rects bevel_offsets;
inline 
layout_rects apply_layout_ofssets( 
									const layout_sizes& rects,
									const layout_rects& transforms ) {
    
    layout_rects new_rects;
    for ( int idx = sqc_theme_first; idx < sqc_theme_countof; ++idx ) {
        
        sqc_theme_size theme = (sqc_theme_size)idx;
        layout_rect rc = layout_rect( rects.at( theme ) );
        rc.x = transforms.at( theme ).x;
        rc.y = transforms.at( theme ).y;
        rc.cx -= transforms.at( theme ).cx+transforms.at( theme ).x;
        rc.cy -= transforms.at( theme ).cy+transforms.at( theme ).y;
        new_rects.set_at( theme, rc );
    }
    return new_rects;
}
template <milk::milk_bevel_type bevel_type>
class typed_bevel_layout : public base_bevel_layout {
public:
	typed_bevel_layout( const layout_alignment& alignment,
						 const bevel_rects& rects )
	: base_bevel_layout( alignment,rects, bevel_type ) {
	}
	typed_bevel_layout( const dialog_layout& layout, const bevel_offsets& offsets ) 
	: base_bevel_layout( layout_alignment( layout_halignment_left | 
										  layout_valignment_top ),apply_layout_ofssets(layout.sizes(),offsets)
						, bevel_type ){
	
	}
};

typedef typed_bevel_layout<milk::milk_bevel_type_content> content_bevel_layout;
typedef typed_bevel_layout<milk::milk_bevel_type_content_scroll> content_scroll_bevel_layout;



// transform layout rects
inline 
layout_rects transform_layout_rects( 
    const layout_rects& rects,
    const layout_rects& transforms ) {
    
    layout_rects new_rects = rects;
    for ( int idx = sqc_theme_first; idx < sqc_theme_countof; ++idx ) {
        
        sqc_theme_size theme = (sqc_theme_size)idx;
        layout_rect rc = rects.at( theme );
        rc.x += transforms.at( theme ).x;
        rc.y += transforms.at( theme ).y;
        rc.cx += transforms.at( theme ).cx;
        rc.cy += transforms.at( theme ).cy;
        new_rects.set_at( theme, rc );
    }
    
    return new_rects;
}

static const layout_label_draw_flags 
draw_flags_hcenter_vcenter( surf::draw_string_alignment_center|
                           surf::draw_string_valignment_center|
                           surf::draw_string_single_line|
                           surf::draw_string_truncation_tail );

static const layout_label_draw_flags 
draw_flags_hleft_vcenter( surf::draw_string_alignment_left|
                         surf::draw_string_valignment_center|
                         surf::draw_string_single_line|
                         surf::draw_string_truncation_tail );

static const layout_label_draw_flags 
draw_flags_hleft_vbottom( surf::draw_string_alignment_left|
                         surf::draw_string_valignment_bottom|
                         surf::draw_string_single_line|
                         surf::draw_string_truncation_tail );

static const layout_label_draw_flags 
draw_flags_hcenter_vbottom( surf::draw_string_alignment_center|
                           surf::draw_string_valignment_bottom|
                           surf::draw_string_single_line|
                           surf::draw_string_truncation_tail );

static const layout_label_draw_flags 
draw_flags_hright_vcenter( surf::draw_string_alignment_right|
                          surf::draw_string_valignment_center|
                          surf::draw_string_single_line|
                          surf::draw_string_truncation_tail );

static const layout_label_draw_flags 
draw_flags_hleft_vtop( surf::draw_string_alignment_left|
                          surf::draw_string_valignment_top|
                          surf::draw_string_single_line|
                          surf::draw_string_truncation_tail );

static const layout_label_draw_flags 
draw_flags_hcenter_vtop( surf::draw_string_alignment_center|
                         surf::draw_string_valignment_top|
                         surf::draw_string_single_line|
                         surf::draw_string_truncation_tail );

class sqc_window_factory_ctx;
typedef std::tr1::shared_ptr<sqc_window_factory_ctx>	sqc_window_factory_ctx_ptr;


END_NAMESPACE_SQC_FRAMEWORK

#endif//__SQC_COMMAND_PROXY_H_INCLUDED__
