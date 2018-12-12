#ifndef SURF_GL_H
#define SURF_GL_H

#include "surf_defs.h"
#include "surf_transform2d.h"
#include <array>

NAMESPACE_SURF

class surf_graphics_server;
class surf_context;

class surf_context_state {
    friend class surf_context;
public:
    surf_context_state() 
        : color(1.,1.,1.,1.) {
  }
protected:
    surf_color color;
	surf_transform transform;
};

class surf_image;
typedef std::tr1::shared_ptr<surf_image> surf_image_ptr;

enum surf_brush_blend_ {
	surf_brush_mode_mask_alpha = 0,		///< use src alpha only
	surf_brush_mode_multiply   = 1,		///< use src color as multiplicator
	surf_brush_mode_additive   = 2,		///< use src color plus brush
	surf_brush_mode_rotate	   = 1 << 8,	///< rotate brush (90)
	surf_brush_mode_draw_to_target = 1 << 9, ///< for internal use only
};

static const surf_dword surf_brush_blend_mask = 0xff;

typedef surf_dword surf_brush_mode;


class surf_context : public surf_object {
public:
    surf_context( surf_graphics_server &s );
    
    void    store_state( surf_context_state &state );
    void    restore_state( surf_context_state const &state );
    
    void    set_color( surf_color const &color );
	const	surf_color& get_color() const { return m_color;}
    void    reset_color( surf_context_state const &state );
    
    void    set_width( surf_val v );
    void    set_smooth( bool v );
    
    void    set_clip_rect( surf_rect const &rect );
    void    reset_clip();
    
	void set_brush( surf_image_ptr brush , surf_brush_mode mode = surf_brush_mode_mask_alpha);
	surf_image_ptr get_brush() const;
	surf_brush_mode get_brush_mode() const;
	
	bool brush_supported() const;
	
    void clear();
    
    surf_graphics_server &server();

	/// transformations
	const surf_transform& get_transform() const { return m_transform;}
	void set_transform( const surf_transform& tr );

	/// dont use this functions everywere
	/// @todo make it private and use friends
	surf_point get_brush_offset() const;

private:
    surf_graphics_server    &m_server;
	surf_transform m_transform;
    surf_val    m_alpha;
  	surf_image_ptr	brush_image;
	surf_brush_mode	brush_mode;
	surf_color	m_color;
	friend class surf_rendertarget;
	friend class surf_image;
	bool	m_draw_to_target;
};

typedef std::tr1::shared_ptr<surf_context>  surf_context_ptr;

class surf_curve : public surf_object {
public:
    void move_to( surf_point const &point );
    void line_to( surf_point const &point );
    
    void offset( surf_point const &offset );
    
    void draw( surf_context_ptr ctx );
    
    std::list<surf_point> data;
};

typedef std::tr1::shared_ptr<surf_curve> surf_curve_ptr;

class surf_gl_image;
typedef std::tr1::shared_ptr<surf_gl_image> surf_gl_image_ptr;

struct surf_image_info {
    surf_nsize  size;
    surf_byte   bpp;
	size_t		mem_size;
    bool        reduced_bitdepth;
};

class surf_graphics_server;

enum surf_image_corner {
	surf_image_corner_top_left,
	surf_image_corner_bottom_left,
	surf_image_corner_top_right,
	surf_image_corner_bottom_right,
	surf_image_corners_amount
};
typedef std::tr1::array<surf_color,surf_image_corners_amount> surf_image_corners_color;

class surf_image : public surf_object {
public:
    surf_image( surf_graphics_server* server, surf_gl_image_ptr ptr );
    ~surf_image();
    
    void draw( surf_context_ptr ctx, surf_rect const &rect );
    void draw( surf_context_ptr ctx, surf_point const &point );
    void draw( surf_context_ptr ctx, surf_rect const &rect_to, 
			  surf_rect const &rect_from, 
			  surf_draw_image_flags tile = tile_flag_none );
	void draw( surf_context_ptr ctx, const surf_rect& rect_to,
			  const surf_rect& rect_from,
			  const surf_image_corners_color& colors);
	void get_info ( surf_image_info &info );
    surf_color get_color( const surf_npoint& point );
    
    surf_nsize  get_size() const;
private:
	surf_graphics_server* server;
    surf_gl_image_ptr   impl;
    friend class surf_curve;
};



class surf_gl_font;
typedef std::tr1::shared_ptr<surf_gl_font> surf_gl_font_ptr;

class surf_font : public surf_object {
public:
    surf_font( surf_gl_font_ptr ptr );
    ~surf_font();

    surf_size   calc_size( surf_context_ptr ctx, surf_string const &s, surf_size const &size, surf_draw_string_flags flags );
    void        draw( surf_context_ptr ctx, surf_string const &s, surf_point const &point, surf_size const &size, surf_draw_string_flags flags, surf_color const &color, surf_color const &shadow_color, surf_size const &shadow_size );
private:
    surf_gl_font_ptr   impl;
};

typedef std::tr1::shared_ptr<surf_font> surf_font_ptr;

enum surf_image_file_type {
	surf_image_file_type_unknown,	///< autodetect
	surf_image_file_type_png,
	surf_image_file_type_png4,
	surf_image_file_type_jpg	
};

struct surf_create_image_info {
    enum sqc_reading_path {
        from_bundle,
        from_temp,
    };
    
    surf_create_image_info() 
    : reduce_bitwidth( false )
    , clip_image( false )
    , reading_path( from_bundle )
    , file_type( surf_image_file_type_unknown)
    {
    }
    
    bool                reduce_bitwidth;
    bool                clip_image;
    surf_image_file_type                file_type;
    sqc_reading_path    reading_path;
    surf_nrect          source_rect;
};


typedef std::tr1::function<void(surf_image_info&, surf_create_image_info const &cinfo, surf_byte const *)>    surf_image_ready_callback;



class surf_image_loader : public surf_object{
public:
	virtual ~surf_image_loader() {}
    virtual bool load_image( const char *name, surf_image_info &image_info, surf_image_ready_callback cb, surf_create_image_info const &create_info ) = 0;
    virtual bool load_image_info( const char *name, surf_image_info &image_info, surf_create_image_info const &create_info ) = 0;
};

typedef surf_raw_data	surf_font_content;

class surf_font_loader : public surf_object{
public:
    virtual bool load_font( const char *name, surf_font_content& font_content ) = 0;
};

/// rendertarget object
class surf_rendertarget : public surf_object {
public:
	struct implementation;
	surf_rendertarget( implementation* impl);
	~surf_rendertarget();
	
	/// size of target
	surf_nsize  get_size() const;
	/// bind target
	void bind(const surf_context_ptr & ctx);
	/// unbind target
	void unbind(const surf_context_ptr & ctx);
	/// get data ( 32 bpp : 4bytes per pixel )
	void get_raw_data( const surf_nrect& rect, surf_byte* buffer );
	/// get attached image, ( if exists )
	surf_image_ptr get_image() const;
	/// clear target
	void clear(const surf_color& clr);
private:
	implementation*	m_impl;
};
typedef std::tr1::shared_ptr<surf_rendertarget> surf_rendertarget_ptr;

class surf_graphics_server {
public:
    surf_graphics_server( surf_image_loader &l, surf_font_loader &f ) 
		: image_loader( l )
		, font_loader( f ) {
    }
    surf_context_ptr create_context();
    surf_image_ptr   create_image( const char *resource_id );
    surf_image_ptr   create_image_ex( const char *resource_id, surf_create_image_info const &info );
    surf_font_ptr    create_font( surf_val face_size = 12, const char *face_name = 0 );
    surf_font_ptr    create_stroked_font( surf_val face_size = 12, const char *face_name = 0, surf_word stroke_size = 3 );
    surf_curve_ptr   create_curve();
	surf_rendertarget_ptr get_getpixel_target();
	surf_rendertarget_ptr create_target( surf_dword w, surf_dword h, bool reduse );
	bool full_render_to_target_supported();
protected:
    void on_image_complete( surf_gl_image_ptr impl, surf_image_info &info, surf_create_image_info const &cinfo, surf_byte const *raw );
    const surf_font_content& get_font_content( const char *face_name );
private:
    surf_image_loader	&image_loader;
	surf_font_loader	&font_loader;
    typedef std::map<std::string,surf_font_content> font_content_map;
    font_content_map    m_font_content_map;
	surf_rendertarget_ptr	m_getpixel_target;
};

typedef std::tr1::shared_ptr<surf_graphics_server>  surf_graphics_server_ptr;


END_NAMESPACE_SURF

#endif //SURF_GL_H