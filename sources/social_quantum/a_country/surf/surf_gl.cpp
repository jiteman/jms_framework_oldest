
#include "surf_gl.h"

#if defined(__ANDROID__)

#include <GLES/gl.h>
#include <GLES/glext.h>

#else

#include <windows.h>
#include "osl/glew/gl/glew.h"
//#include <gl/gl.h>
//#include "osl/glew/gl/glext.h"
//#include <gl/glext.h>

#endif

#include <cassert>


#include <functional> 
using namespace std::tr1::placeholders;

NAMESPACE_SURF

static const bool gl_extension_supported(const char* ext) {
	static surf_string all;
	static bool inited = false;
	if (!inited) {
		all = (const char *) glGetString(GL_EXTENSIONS);
		inited = true;
	}
	return ::strstr( all.c_str(),ext) != 0;
}

static size_t gl_texture_units = 2;

#ifndef SURF_NO_RENDERTARGETS_SUPPORTED
#define RENDERTARGETS_SUPPORTED
/// use GL_OES_framebuffer_object
#define SURF_glGenFramebuffers glGenFramebuffersOES
#define SURF_glFramebufferTexture2D glFramebufferTexture2DOES
#define SURF_glGenRenderbuffers glGenRenderbuffersOES
#define SURF_glBindRenderbuffer glBindRenderbufferOES
#define SURF_glRenderbufferStorage glRenderbufferStorageOES
#define SURF_glFramebufferRenderbuffer glFramebufferRenderbufferOES
#define SURF_glCheckFramebufferStatus glCheckFramebufferStatusOES
#define SURF_glDeleteFramebuffers glDeleteFramebuffersOES
#define SURF_glDeleteRenderbuffers glDeleteRenderbuffersOES
#define SURF_glBindFramebuffer glBindFramebufferOES
#define SURF_GL_FRAMEBUFFER GL_FRAMEBUFFER_OES
#define SURF_GL_FRAMEBUFFER_READ GL_FRAMEBUFFER_READ_OES
#define SURF_GL_FRAMEBUFFER_WRITE GL_FRAMEBUFFER_WRITE_OES
#define SURF_GL_COLOR_ATTACHMENT0 GL_COLOR_ATTACHMENT0_OES
#define SURF_GL_RENDERBUFFER GL_RENDERBUFFER_OES
#define SURF_GL_DEPTH_COMPONENT16 GL_DEPTH_COMPONENT16_OES
#define SURF_GL_DEPTH_ATTACHMENT GL_DEPTH_ATTACHMENT_OES
#define SURF_GL_FRAMEBUFFER_COMPLETE GL_FRAMEBUFFER_COMPLETE_OES
#ifdef GL_RGBA8_OES
#define SURF_RENDERBUFFER_FORMAT GL_RGBA8_OES
#else
#define SURF_RENDERBUFFER_FORMAT GL_RGBA
#endif
#ifdef GL_RGBA4_OES
#define SURF_RENDERBUFFER_FORMAT_SMALL GL_RGBA4_OES
#else
#define SURF_RENDERBUFFER_FORMAT_SMALL GL_RGBA
#endif
#define SURF_GL_FRAMEBUFFER_BINDING GL_FRAMEBUFFER_BINDING_OES
#define SURF_GL_RENDERBUFFER_BINDING GL_RENDERBUFFER_BINDING_OES
static bool SURF_GL_OES_framebuffer_object_supported() {
	static bool supported = gl_extension_supported("GL_OES_framebuffer_object");
	return supported;
}
#endif

#ifdef GL_OES_blend_func_separate
#define SURF_glBlendFuncSeparateOES glBlendFuncSeparateOES
static bool SURF_GL_OES_blend_func_separate_supported() {
	static bool supported = gl_extension_supported("GL_OES_blend_func_separate");
	return supported;
}
#endif

inline unsigned int next_pot(unsigned int val) {
	val--;
	val = (val >> 1) | val;
	val = (val >> 2) | val;
	val = (val >> 4) | val;
	val = (val >> 8) | val;
	val = (val >> 16) | val;
	val++;
	return val;
}


surf_context::surf_context( surf_graphics_server &s ) 
    : m_server( s )
	, m_alpha(1.0)
, m_color(1,1,1,1) {
    m_draw_to_target = false;
}

surf_graphics_server &surf_context::server() {
    return m_server;
}

void surf_context::store_state( surf_context_state &state ) {
   state.color = m_color;
	state.transform = m_transform;
}

void surf_context::restore_state( surf_context_state const &state ) {
	m_color = state.color;
	set_color(m_color);
	set_transform( state.transform );
}


void surf_context::set_color( surf_color const &color ) {
    glColor4f( color.r, color.g, color.b, color.a*m_alpha );
	m_color = color;
}

void surf_context::reset_color( surf_context_state const &state ) {
    set_color( state.color );
}


surf_point surf_context::get_brush_offset() const {
	return surf_point(0,0);
}




surf_image_ptr surf_context::get_brush() const {
	return brush_image;
}

bool surf_context::brush_supported() const {
	static bool checked = false;
	static bool supported = false;
	if (!checked) {
		GLint param = 0;
		glGetIntegerv(GL_MAX_TEXTURE_UNITS, &param);
		supported = param > 1;
		checked = true;
	}
	return supported;
}

void surf_context::set_brush( surf_image_ptr brush , surf_brush_mode mode ) {
	if (brush_supported())
		brush_image = brush;
	brush_mode = mode;
}

surf_brush_mode surf_context::get_brush_mode() const {
	return brush_mode;
}
    
void surf_context::clear() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);    
}

void surf_context::set_clip_rect( surf_rect const &rect ) {
    glEnable( GL_SCISSOR_TEST );
	surf_point bl = m_transform.transform( rect.bottom_left() );
	surf_point tr = m_transform.transform( rect.top_right() );
	/// @todo bugs if rotate applied
    glScissor( bl.x,bl.y, tr.x-bl.x, tr.y-bl.y );
}

void surf_context::reset_clip() {
    glDisable( GL_SCISSOR_TEST );
}

void surf_context::set_width( surf_val v ) {
    glLineWidth( v );
}

void surf_context::set_smooth( bool v ) {
    if( v ) {
        glEnable( GL_LINE_SMOOTH );
    }
    else {
        glDisable( GL_LINE_SMOOTH );
    }
}

void surf_context::set_transform( const surf_transform& tr ) {
	GLfloat m[4*4] = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	m_transform = tr;
	/// matrix
	m[0+0*4] = tr.m.matrix[0+0*2];m[1+0*4] = tr.m.matrix[1+0*2];
	m[0+1*4] = tr.m.matrix[0+1*2];m[1+1*4] = tr.m.matrix[1+1*2];
	/// vector
	m[0+3*4] = tr.v.x;
	m[1+3*4] = tr.v.y;
	glLoadMatrixf(m);
}


static void set_draw_to_target_color_mode() {
	glActiveTexture(GL_TEXTURE1);
	glEnable(GL_TEXTURE_2D);
	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
	glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB,GL_PREVIOUS);
	glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,GL_SRC_COLOR);
	glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB,GL_PREVIOUS);
	glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,GL_SRC_ALPHA);
	glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_REPLACE);
	glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_ALPHA,GL_PREVIOUS);
	glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_ALPHA,GL_SRC_ALPHA);
	glActiveTexture(GL_TEXTURE0);
	glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
}

//
// surf_image
//
class surf_gl_image {
public:
    surf_gl_image( const char *n ) 
        : texture_id( 0 )
        , texture_name( n )
        , texture_bpp( 0 )
		, inverted_vertical(false)
		, target_image(false)
    {
    }
    
    ~surf_gl_image() {
        clear();
    }
    
    void clear() {
        if( texture_id ) {
            glDeleteTextures( 1, &texture_id );
        }             
        texture_id = 0;
    }
	GLuint get_id() const { return texture_id;}
	bool create( GLuint w, GLuint h , bool reduse_bpp ) {
		clear();
		target_image = true;
		/// reset errors
		glGetError();
		
		glGenTextures( 1, &texture_id );
        if ( !texture_id )
        {
            return false;
        }
         glBindTexture( GL_TEXTURE_2D, texture_id );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
      
		inverted_vertical = true;
		texture_reduced_bitdepth = reduse_bpp;
		texture_bpp = reduse_bpp ? 16 : 32;
		texture_size = surf_nsize(w,h);
		texture_raw_size = texture_size;
         {
            if (reduse_bpp) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, 0);
            }
            else {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, 0);
            }
        }
        
        GLenum error_code = glGetError();
        
        if( error_code != GL_NO_ERROR ) {
            surf_error() 
			<< "failed to create texture: " << w << "x" << h << " \"" << texture_name << "\" "
			<< (reduse_bpp ? " redused " : "full" )
			<< " error = " << error_code << surf_endl();
            return false;
        }
		return true;
	}
    
    bool set_image_data( surf_byte const *raw, surf_image_info const &image_info, surf_create_image_info const &create_info ) {
        clear();
		target_image = false;
		/// reset error
		glGetError();
        
        texture_size = image_info.size;
        texture_bpp = image_info.bpp;
        texture_reduced_bitdepth = image_info.reduced_bitdepth;
        
        
        surf_info() 
            << "load texture: \"" << texture_name << "\"" << surf_endl();
        
        //
        // calculate raw size
        //
        
        int bpp = (texture_reduced_bitdepth ? 16 : texture_bpp)/8;
        
        int from_x = 0;
        int from_y = 0;
        int to_x = texture_size.cx;
        int to_y = texture_size.cy;
        
        if( create_info.clip_image ) {
			if ( (create_info.source_rect.cx<=0)||(create_info.source_rect.cy<=0)) {
				surf_info() 
					<< "error load texture: \"" << texture_name << "\" invalid clip rect" << surf_endl();
				return false;
			}
            from_x = create_info.source_rect.x;
            from_y = create_info.source_rect.y;
            to_x  = from_x + create_info.source_rect.cx;
            to_y  = from_y + create_info.source_rect.cy;
            
            texture_size.cx = create_info.source_rect.cx;
            texture_size.cy = create_info.source_rect.cy;
            
        }
        
        texture_raw_size = surf_nsize( 1, 1 );
        while( texture_raw_size.cx < texture_size.cx ) texture_raw_size.cx <<= 1;
        while( texture_raw_size.cy < texture_size.cy ) texture_raw_size.cy <<= 1;
        
        size_t cb_row_raw = bpp * texture_raw_size.cx;
        size_t cb_row_src = bpp * image_info.size.cx;
        size_t cb_row     = bpp * texture_size.cx;
        

        
        surf_byte   *texture_raw = new surf_byte[texture_raw_size.cy * cb_row_raw];
        std::auto_ptr<surf_byte> texture_raw_keeper( texture_raw );
      
		const size_t right = texture_raw_size.cx-texture_size.cx;
		
        for( size_t row = from_y; row != to_y; ++row ) {
            surf_byte const *from = raw + cb_row_src * row + from_x * bpp;
            surf_byte *to = texture_raw + cb_row_raw * (row-from_y);
            
            memcpy( to, from, cb_row );
			from = to+cb_row-bpp;
			to = to+cb_row;
			for (size_t i=0;i<right;i++) {
				memcpy(to, from, bpp);
				to+=bpp;
			}
        }
        
        // fill tail
		const size_t bottom = texture_raw_size.cy - texture_size.cy;
		{
            surf_byte *to = texture_raw + cb_row_raw * texture_size.cy;
			const surf_byte *from = to - cb_row_raw;
			for (size_t i=0;i<bottom;i++) {
				memcpy(to, from, cb_row);
				to+=cb_row_raw;
			}
        }
		
		/// fill corner
		if (bottom && right)
        {
			const surf_byte *from = texture_raw + cb_row_raw * texture_size.cy - cb_row_raw + cb_row - bpp;
			surf_byte *to = texture_raw + cb_row_raw * texture_size.cy + cb_row;
			for (size_t i=0;i<right;i++) {
				memcpy(to, from, bpp);
				to+=bpp;
			}
			from+=cb_row_raw;
			from+=bpp;
			to = texture_raw + cb_row_raw * texture_size.cy + cb_row + cb_row_raw;
			for (size_t i=1;i<bottom;i++) {
				memcpy(to, from, right*bpp);
				to+=cb_row_raw;
			}
		}
        //
        // create texture object
        //
        static GLint texture_max_cx = 0;
        
        if ( !texture_max_cx )
        {
            glGetIntegerv( GL_MAX_TEXTURE_SIZE, &texture_max_cx );
        }
        
        if ( texture_size.cx > texture_max_cx || texture_size.cy > texture_max_cx ) {
            surf_warning() 
                << "failed to load texture: \"" << texture_name << "\" "
                << "because size is too big: " << texture_size << surf_endl();
            return false;
        }
        
        glGenTextures( 1, &texture_id );
        if ( !texture_id )
        {
            return false;
        }
        
        glBindTexture( GL_TEXTURE_2D, texture_id );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT );
        glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT );
        
        if( texture_bpp == 32 ) {
            if (texture_reduced_bitdepth) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_raw_size.cx, texture_raw_size.cy, 0, GL_RGBA, GL_UNSIGNED_SHORT_4_4_4_4, texture_raw);
            }
            else {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture_raw_size.cx, texture_raw_size.cy, 0, GL_RGBA, GL_UNSIGNED_BYTE, texture_raw);
            }
        }
        else if( texture_bpp == 24 ) {
            if (texture_reduced_bitdepth) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_raw_size.cx, texture_raw_size.cy, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, texture_raw);
            }
            else {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture_raw_size.cx, texture_raw_size.cy, 0, GL_RGB, GL_UNSIGNED_BYTE, texture_raw);
            }
		} 
        else {
            surf_error() 
                << "failed to load texture: \"" << texture_name << "\" "
				<< "bpp:" << (int)texture_bpp
				<< " ,format is not supported" << surf_endl();
            return false;
        }

        GLenum error_code = glGetError();
        
        if( error_code != GL_NO_ERROR ) {
            surf_error() 
                << "failed to load texture: \"" << texture_name << "\" "
                << " error = " << error_code << surf_endl();
            return false;
        }
        
        return true;
    }
    
    
    //-------------------------------------------------------
    void draw( surf_rect const &rect_to, surf_rect const &rect_from, surf_draw_image_flags tile ,const surf_image_corners_color* colors) {
		
        bool rotate = (tile & draw_image_rotated) == draw_image_rotated;
        bool mirror = (tile & draw_image_mirrored) == draw_image_mirrored;
        bool v_mirror = (tile & draw_image_v_mirrored) == draw_image_v_mirrored;
        
        glEnable(GL_TEXTURE_2D);
        
        if( !texture_id ) {
            surf_warning() 
                << "failed to draw texture: \"" << texture_name << "\" "
                << "texture is not ready" << surf_endl();
            return;
        }
        
		if (target_image) {
			glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
		}
		
        GLfloat vxl  = rect_to.x;
        GLfloat vyb  = rect_to.y;
        GLfloat vyt  = rect_to.y + rect_to.cy;
        GLfloat vxr  = rect_to.x + rect_to.cx;
        
        if( mirror ) {
            std::swap( vxl, vxr );
        }

        if( v_mirror ) {
            std::swap( vyt, vyb );
        }
                
        GLfloat vertices[8] = { vxl, vyt, vxl, vyb, vxr, vyt, vxr, vyb };
        
        
        GLfloat xl  = (rect_from.x) / texture_raw_size.cx ;
        GLfloat yt  = (rect_from.y) / texture_raw_size.cy;
        GLfloat xr  = (rect_from.x + rect_from.cx) / texture_raw_size.cx;
        GLfloat yb  = (rect_from.y + rect_from.cy) / texture_raw_size.cy;
		
		if (  inverted_vertical ) {
			yt = 1.0f - yt;
			yb = 1.0f - yb;
		}
        if( tile & tile_flag_horz) {
            xl = 0;
            xr = (vxr-vxl) / texture_raw_size.cx;
        }
        
        if( tile & tile_flag_vert ) {
            yt = 0;
            yb = (vyt-vyb) / texture_raw_size.cy;
        }
        
        GLfloat coordinates[8] = { xl, yt, xl, yb, xr, yt, xr, yb };
        
        //
        //
        //
        if( rotate ) 
        {
            coordinates[0] = xr;
            coordinates[1] = yt;
            coordinates[2] = xl;
            coordinates[3] = yt;
            coordinates[4] = xr;
            coordinates[5] = yb;
            coordinates[6] = xl;
            coordinates[7] = yb;
        }
        
        
        
        glBindTexture(GL_TEXTURE_2D, texture_id);
        
        glTexCoordPointer(2, GL_FLOAT, 0, coordinates);
		if (colors) {
			const surf_image_corners_color& colors_ = *colors;
			const GLfloat colors_array[4*4] = {
				colors_[0].r,colors_[0].g,colors_[0].b,colors_[0].a,
				colors_[1].r,colors_[1].g,colors_[1].b,colors_[1].a,
				colors_[2].r,colors_[2].g,colors_[2].b,colors_[2].a,
				colors_[3].r,colors_[3].g,colors_[3].b,colors_[3].a,
			};
			glColorPointer(4, GL_FLOAT, 0, colors_array );
			glEnableClientState(GL_COLOR_ARRAY);
		}
       
		glVertexPointer(2, GL_FLOAT, 0, vertices);
		
        if( tile ) {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        }
        else {
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        }
        
        glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
        
		if (colors) {
			glDisableClientState(GL_COLOR_ARRAY);
		}
		
		if (target_image) {
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		}
    }
 
	//-------------------------------------------------------
    void draw_mask( surf_gl_image_ptr mask, surf_rect const &rect_to, surf_rect const &rect_from, 
				   surf_draw_image_flags tile , surf_point const &brush_offset, 
				   surf_brush_mode mode,const surf_image_corners_color* colors) {
		if (!mask->texture_id) return;
		GLfloat xl  = (-brush_offset.x + rect_to.x) / mask->texture_raw_size.cx ;
        GLfloat yb  = 1.0-(-brush_offset.y + rect_to.y) / mask->texture_raw_size.cy;
        GLfloat xr  = (-brush_offset.x + rect_to.x + rect_to.cx) / mask->texture_raw_size.cx;
        GLfloat yt  = 1.0-(-brush_offset.y + rect_to.y + rect_to.cy) / mask->texture_raw_size.cy;
		
		GLfloat coordinates[8] = { xl, yt, xl, yb, xr, yt, xr, yb };
		
        if ( mode & surf_brush_mode_rotate ) {
			xl  = (-brush_offset.y + rect_to.y + rect_to.cy) / mask->texture_raw_size.cx;
			yt  = (-brush_offset.x + rect_to.x) / mask->texture_raw_size.cy ;
			yb  = (-brush_offset.x + rect_to.x + rect_to.cx) / mask->texture_raw_size.cy;
			xr  = (-brush_offset.y + rect_to.y ) / mask->texture_raw_size.cx;
			coordinates[0]=xl; coordinates[1]=yt;
			coordinates[2]=xr; coordinates[3]=yt;
			coordinates[4]=xl; coordinates[5]=yb;
			coordinates[6]=xr; coordinates[7]=yb;
		}
		
		glTexCoordPointer(2, GL_FLOAT, 0, coordinates);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, mask->texture_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		
		
		
		glActiveTexture(GL_TEXTURE1);
		glEnable(GL_TEXTURE_2D);
		
		glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_COMBINE);
		
		switch (mode & surf_brush_blend_mask) {
			case surf_brush_mode_mask_alpha:
				if ( (mode & surf_brush_mode_draw_to_target) && !SURF_GL_OES_blend_func_separate_supported() ) {
					glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
					glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB,GL_PREVIOUS);
					glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,GL_SRC_COLOR);
					glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB,GL_TEXTURE);
					glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,GL_SRC_ALPHA);

					glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
					glTexEnvi(GL_TEXTURE_ENV,GL_SRC0_ALPHA,GL_PREVIOUS);
					glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,GL_SRC_ALPHA);
					glTexEnvi(GL_TEXTURE_ENV,GL_SRC1_ALPHA,GL_TEXTURE);
					glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_ALPHA,GL_SRC_ALPHA);
				} else {
					
					glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_REPLACE);
					glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB,GL_PREVIOUS);
					glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,GL_SRC_COLOR);
					
					glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
					glTexEnvi(GL_TEXTURE_ENV,GL_SRC0_ALPHA,GL_PREVIOUS);
					glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,GL_SRC_ALPHA);
					glTexEnvi(GL_TEXTURE_ENV,GL_SRC1_ALPHA,GL_TEXTURE);
					glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_ALPHA,GL_SRC_ALPHA);
				}
				break;
			case surf_brush_mode_multiply:
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_MODULATE);
				glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB,GL_PREVIOUS);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,GL_SRC_COLOR);
				glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB,GL_TEXTURE);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,GL_SRC_COLOR);
				glTexEnvi(GL_TEXTURE_ENV,GL_SRC0_ALPHA,GL_PREVIOUS);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,GL_SRC_ALPHA);
				glTexEnvi(GL_TEXTURE_ENV,GL_SRC1_ALPHA,GL_TEXTURE);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_ALPHA,GL_SRC_ALPHA);
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
				if ( mode & surf_brush_mode_draw_to_target ) {
					surf_warning() << "unsupported brush mode" << surf_endl();
				}
				break;
			case surf_brush_mode_additive:
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_RGB, GL_ADD);
				glTexEnvi(GL_TEXTURE_ENV, GL_SRC0_RGB,GL_PREVIOUS);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND0_RGB,GL_SRC_COLOR);
				glTexEnvi(GL_TEXTURE_ENV, GL_SRC1_RGB,GL_TEXTURE);
				glTexEnvi(GL_TEXTURE_ENV, GL_OPERAND1_RGB,GL_SRC_COLOR);
				glTexEnvi(GL_TEXTURE_ENV,GL_SRC0_ALPHA,GL_PREVIOUS);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND0_ALPHA,GL_SRC_ALPHA);
				glTexEnvi(GL_TEXTURE_ENV,GL_SRC1_ALPHA,GL_TEXTURE);
				glTexEnvi(GL_TEXTURE_ENV,GL_OPERAND1_ALPHA,GL_SRC_ALPHA);
				glTexEnvi(GL_TEXTURE_ENV, GL_COMBINE_ALPHA, GL_MODULATE);
				if ( mode & surf_brush_mode_draw_to_target ) {
					surf_warning() << "unsupported brush mode" << surf_endl();
				}
				break;
			default:
				assert( false && "unknown brush blend mode" );
				break;
		};
		
		glClientActiveTexture(GL_TEXTURE1);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		
		
		
		draw(rect_to,rect_from,tile,colors);
        
		
    	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisable(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glClientActiveTexture(GL_TEXTURE0);
		
		
		if (surf_brush_mode_mask_alpha==(mode & surf_brush_blend_mask) && (mode & surf_brush_mode_draw_to_target) && !SURF_GL_OES_blend_func_separate_supported()) {
			set_draw_to_target_color_mode();
		}
	}
	
    surf_nsize  get_size() const {
        return texture_size;
    }
	
	bool have_alpha_channel() const { return texture_bpp!=24;}
private:
    surf_string texture_name;
    GLuint      texture_id;
    surf_nsize  texture_size;
    surf_nsize  texture_raw_size;
    surf_byte   texture_bpp;
    bool        texture_reduced_bitdepth;
	bool		inverted_vertical;
	bool		target_image;
};


surf_image::surf_image(  surf_graphics_server* server, surf_gl_image_ptr p ) 
    : server(server), impl( p )
{
}

surf_image::~surf_image() {
    
}

// TODO
void surf_image::get_info ( surf_image_info &info ) {
    surf_nsize  size = impl->get_size();
    info.mem_size   = size.cx * size.cy;
    info.size       = size;
    //surf_byte   bpp;
	//size_t		mem_size;
    //bool        reduced_bitdepth;

}

// TODO
surf_color surf_image::get_color( const surf_npoint& point ) {
	surf_nsize size = get_size();
	/// if outside point return transparent pixel
	if (point.x < 0) return surf_color(1,1,1,0);
	if (point.y < 0) return surf_color(1,1,1,0);
	if (point.x >size.cx) return surf_color(1,1,1,0);
	if (point.y >size.cy) return surf_color(1,1,1,0);
	if (server) {
		surf_rendertarget_ptr rendertarget = server->get_getpixel_target();
		if (rendertarget) {
			rendertarget->bind(surf_context_ptr());
			/// disable blending for getting pixels as is
			glDisable(GL_BLEND);
			impl->draw( surf_rect(0,0,1,1),
					   surf_rect( int(point.x),int(point.y),1,1 ),tile_flag_none,0);
			glEnable(GL_BLEND);
			surf_byte buffer[ 4 ];
			rendertarget->get_raw_data( surf_nrect(0,0,1,1), buffer );
			rendertarget->unbind(surf_context_ptr());
			return surf_byte_color(buffer[0],buffer[1],buffer[2],buffer[3]);
		}
	}
    return surf_color();
}

surf_nsize surf_image::get_size() const {
    return impl->get_size();
}

void surf_image::draw( surf_context_ptr ctx, surf_rect const &rect ) {
    const surf_nsize size = impl->get_size();
    
    const surf_rect   rect_from( 0, 0, size.cx, size.cy );
	
	bool disable_blend = false;
	if (!impl->have_alpha_channel() && ctx->get_color().a>=1.0 ) {
		disable_blend = true;
		glDisable(GL_BLEND);
	}
	
	if ( ctx->get_brush() )
		impl->draw_mask( ctx->get_brush()->impl,rect, rect_from, tile_flag_none,ctx->get_brush_offset(),
						ctx->get_brush_mode() | (ctx->m_draw_to_target ? surf_brush_mode_draw_to_target:0),0);
	else
		impl->draw( rect, rect_from, tile_flag_none ,0);
	if (disable_blend)
		glEnable(GL_BLEND);
}

void surf_image::draw( surf_context_ptr ctx, surf_point const &point ) {
    const surf_nsize size = impl->get_size();
    
    const surf_rect   rect_to( point.x, point.y, size.cx, size.cy );
    const surf_rect   rect_from( 0, 0, size.cx, size.cy );
	
	bool disable_blend = false;
	if (!impl->have_alpha_channel() && ctx->get_color().a>=1.0 ) {
		disable_blend = true;
		glDisable(GL_BLEND);
	}
	
    if ( ctx->get_brush() )
		impl->draw_mask( ctx->get_brush()->impl,rect_to, rect_from, tile_flag_none,ctx->get_brush_offset(),
						ctx->get_brush_mode() | (ctx->m_draw_to_target ? surf_brush_mode_draw_to_target:0),0);
	else
		impl->draw( rect_to, rect_from, tile_flag_none ,0);
	if (disable_blend)
		glEnable(GL_BLEND);
}

void surf_image::draw( surf_context_ptr ctx, surf_rect const &rect, surf_rect const &rect_from, surf_draw_image_flags tile_flag ) {
	
	bool disable_blend = false;
	if (!impl->have_alpha_channel() && ctx->get_color().a>=1.0 ) {
		disable_blend = true;
		glDisable(GL_BLEND);
	}
	
	if ( ctx->get_brush() )
		impl->draw_mask( ctx->get_brush()->impl,rect, rect_from, tile_flag,ctx->get_brush_offset(),
						ctx->get_brush_mode() | (ctx->m_draw_to_target ? surf_brush_mode_draw_to_target:0),0);
	else
		impl->draw( rect, rect_from, tile_flag ,0);
	if (disable_blend)
		glEnable(GL_BLEND);

}
void surf_image::draw( surf_context_ptr ctx, const surf_rect& rect_to,
		  const surf_rect& rect_from,
		  const surf_image_corners_color& colors) {
	
	if ( ctx->get_brush() )
		impl->draw_mask( ctx->get_brush()->impl,rect_to, rect_from, tile_flag_none,ctx->get_brush_offset(),
						ctx->get_brush_mode() | (ctx->m_draw_to_target ? surf_brush_mode_draw_to_target:0),&colors);
	else
		impl->draw( rect_to, rect_from, tile_flag_none ,&colors);
}
//
//
//    
void surf_curve::move_to( surf_point const &point ) {
    data.push_back( point );
}

void surf_curve::line_to( surf_point const &point ) {
    data.push_back( point );
}

void surf_curve::offset( surf_point const &point ) {
    for( std::list<surf_point>::iterator i = data.begin(); i != data.end(); ++i ) {
        *i += point;
    }
}

void surf_curve::draw( surf_context_ptr ctx ) {
    if (surf_image_ptr brush = ctx->get_brush()) {
        glBindTexture(GL_TEXTURE_2D, brush->impl->get_id());
    } else 
        glDisable(GL_TEXTURE_2D);

    GLfloat	coords[data.size()*2];
    GLshort points[data.size()*2];
    
    //GLfloat	coords[20];
    //GLshort points[10];
    
    size_t  idx = 0, idx_p = 0, point_no = 0;
    
    for( std::list<surf_point>::const_iterator i = data.begin(); i != data.end(); ++i, ++point_no ) {
//        if( idx_p ) {
//            points[idx_p] = point_no;
//            ++idx_p;
//        }
        points[idx_p++] = point_no;
        
        coords[idx++] = i->x;
        coords[idx++] = i->y;
    }
    
    glVertexPointer( 2, GL_FLOAT, 0, coords );
    glDrawElements( GL_LINE_LOOP, idx_p, GL_UNSIGNED_SHORT, points );
}



/// rendertarget


struct surf_rendertarget::implementation {
#ifdef RENDERTARGETS_SUPPORTED
	/// attributes
	GLuint width;
	GLuint height;
	bool	reduse_bpp;
	surf_image_ptr image;
	/// generated
	GLuint framebuffer;
	GLuint renderbuffer;
	/// stored state
	GLuint attached_framebuffer;
	GLint old_viewport[4];
	
	implementation( GLuint w, GLuint h,surf_image_ptr img,bool reduseBPP) 
		:width(w)
		,height(h)
		,reduse_bpp(reduseBPP)
		,image(img){
		framebuffer = 0;
		renderbuffer = 0;
        attached_framebuffer = 0;
	}
	~implementation() {
		if (renderbuffer) {
			SURF_glDeleteRenderbuffers(1,&renderbuffer);
		}
		if (framebuffer) {
			SURF_glDeleteFramebuffers(1,&framebuffer);
		}
	}
	bool create(GLuint texture_id = 0) {
		bool use_as_texture = image;

		SURF_glGenFramebuffers(1,&framebuffer);
        if ( !framebuffer ) {
        	return false;
        }
        
		glGetIntegerv(SURF_GL_FRAMEBUFFER_BINDING,(GLint*)&attached_framebuffer);
        
		SURF_glBindFramebuffer(SURF_GL_FRAMEBUFFER,framebuffer);
		if (!use_as_texture) {
			SURF_glGenRenderbuffers(1,&renderbuffer);
            if ( !renderbuffer ) {
            	return false;
            }
            GLuint prev_renderbuffer = 0;
			glGetIntegerv(SURF_GL_RENDERBUFFER_BINDING,(GLint*)&prev_renderbuffer);
			SURF_glBindRenderbuffer(SURF_GL_RENDERBUFFER,renderbuffer);
			SURF_glRenderbufferStorage(SURF_GL_RENDERBUFFER,
									   reduse_bpp ? SURF_RENDERBUFFER_FORMAT_SMALL : SURF_RENDERBUFFER_FORMAT,width,height);
			SURF_glFramebufferRenderbuffer(SURF_GL_FRAMEBUFFER,SURF_GL_COLOR_ATTACHMENT0,SURF_GL_RENDERBUFFER,renderbuffer);
			SURF_glBindRenderbuffer(SURF_GL_RENDERBUFFER,prev_renderbuffer);
		} else {
			SURF_glFramebufferTexture2D(SURF_GL_FRAMEBUFFER, SURF_GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texture_id, 0);
		}
		GLenum status = SURF_glCheckFramebufferStatus(SURF_GL_FRAMEBUFFER); 
		SURF_glBindFramebuffer(SURF_GL_FRAMEBUFFER,attached_framebuffer);
		return status==SURF_GL_FRAMEBUFFER_COMPLETE;
	}
	void bind() {
		glBindTexture(GL_TEXTURE_2D, 0);
		glGetIntegerv(SURF_GL_FRAMEBUFFER_BINDING,(GLint*)&attached_framebuffer);
        
		glGetIntegerv(GL_VIEWPORT, old_viewport);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		SURF_glBindFramebuffer(SURF_GL_FRAMEBUFFER,framebuffer);
		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
        glOrthof(0, width, 0, float(height), 0, 1);
        glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
        glLoadIdentity();
#ifdef SURF_glBlendFuncSeparateOES
		if (SURF_GL_OES_blend_func_separate_supported()) {
			SURF_glBlendFuncSeparateOES(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA,GL_ONE,GL_ONE_MINUS_SRC_ALPHA);
		} else {
			if (gl_texture_units>1) {
				set_draw_to_target_color_mode();
			} else {
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
		}
#else
     	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
#endif
	}
	void unbind() {
		glFlush();
		glBindTexture(GL_TEXTURE_2D, 0);
#ifdef SURF_glBlendFuncSeparateOES
		if (!SURF_GL_OES_blend_func_separate_supported() && (gl_texture_units>1) ) {
			glActiveTexture(GL_TEXTURE1);
			glDisable(GL_TEXTURE_2D);
			glActiveTexture(GL_TEXTURE0);
		}
#endif
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		SURF_glBindFramebuffer(SURF_GL_FRAMEBUFFER,attached_framebuffer);
		glViewport(old_viewport[0], old_viewport[1], old_viewport[2], old_viewport[3]);
		glPopMatrix();
		glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);
		glFlush();
	}
	void get_raw_data( GLuint x, GLuint y, GLuint w, GLuint h, GLubyte* data ) {
		glFlush();
		glReadPixels(x, y, w, h, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}
	void clear(float r,float g,float b,float a) {
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}
#endif
};

surf_rendertarget::surf_rendertarget( implementation* impl ) : m_impl(impl) {
}

surf_rendertarget::~surf_rendertarget() {
	delete m_impl;
}

surf_nsize surf_rendertarget::get_size() const {
#ifdef RENDERTARGETS_SUPPORTED
	return surf_nsize( m_impl->width, m_impl->height );
#else
	return surf_nsize();
#endif
}

void surf_rendertarget::bind(const surf_context_ptr & ctx) {
#ifdef RENDERTARGETS_SUPPORTED
	m_impl->bind();
	if (ctx) ctx->m_draw_to_target = true;
#endif
}

void surf_rendertarget::unbind(const surf_context_ptr & ctx) {
#ifdef RENDERTARGETS_SUPPORTED
	m_impl->unbind();
	if (ctx) ctx->m_draw_to_target = false;
#endif
}

surf_image_ptr surf_rendertarget::get_image() const {
#ifdef RENDERTARGETS_SUPPORTED
	return m_impl->image;
#endif
	return surf_image_ptr();
}

// get data ( 32 bpp : 4bytes per pixel )
void surf_rendertarget::get_raw_data( const surf_nrect& rect, surf_byte* buffer ) {
#ifdef RENDERTARGETS_SUPPORTED
	m_impl->get_raw_data(rect.x,rect.y,rect.cx,rect.cy,buffer);
#endif
}

void surf_rendertarget::clear(const surf_color& clr) {
#ifdef RENDERTARGETS_SUPPORTED
	m_impl->clear(clr.r,clr.g,clr.b,clr.a);
#endif
}

//
//
//
surf_context_ptr surf_graphics_server::create_context() {
	static bool first_frame = true;
	if (first_frame) {
		first_frame = false;
		surf_info() << "GL version  : " << glGetString(GL_VERSION)		<<surf_endl();
		surf_info() << "GL vendor   : " << glGetString(GL_VENDOR)		<<surf_endl();
		surf_info() << "GL renderer : " << glGetString(GL_RENDERER)		<<surf_endl();
		surf_info() << "GL extensions : " << glGetString(GL_EXTENSIONS)	<<surf_endl();
		GLint units = 0;
		glGetIntegerv( GL_MAX_TEXTURE_UNITS, &units );
		gl_texture_units = units;
		surf_info() << "GL_MAX_TEXTURE_UNITS : " << gl_texture_units	<<surf_endl();
	}
    return surf_context_ptr( new surf_context( *this ) );
}

surf_image_ptr surf_graphics_server::create_image( const char *resource_id ) {
    surf_create_image_info info;
    info.reduce_bitwidth = false;
    return create_image_ex( resource_id, info );
}

surf_image_ptr surf_graphics_server::create_image_ex( const char *resource_id, surf_create_image_info const &cinfo ) {
    surf_gl_image_ptr impl( new surf_gl_image( resource_id ) );
    
    surf_image_info info;
    if (!image_loader.load_image( resource_id, info, std::tr1::bind( &surf_graphics_server::on_image_complete, this, impl, _1, _2, _3 ), cinfo ))
		return surf_image_ptr();
    return surf_image_ptr( new surf_image( this,impl ) );
}

void surf_graphics_server::on_image_complete( surf_gl_image_ptr impl, surf_image_info &info, surf_create_image_info const &cinfo, surf_byte const *raw ) {
    impl->set_image_data( raw, info, cinfo );
}

surf_curve_ptr surf_graphics_server::create_curve() {
    surf_curve_ptr  curve( new surf_curve() );
    return curve;
}

bool surf_graphics_server::full_render_to_target_supported() {
#ifndef RENDERTARGETS_SUPPORTED
	return false;
#else
#ifdef SURF_glBlendFuncSeparateOES
	static bool supported = SURF_GL_OES_framebuffer_object_supported() 
		&& ( SURF_GL_OES_blend_func_separate_supported() || (gl_texture_units>1) );
	return supported;
#else
	return false;
#endif
#endif
}

surf_rendertarget_ptr surf_graphics_server::create_target( surf_dword w, surf_dword h, bool reduse ) {
#ifndef RENDERTARGETS_SUPPORTED
	return surf_rendertarget_ptr();
#else
	if (SURF_GL_OES_framebuffer_object_supported()) {
		w = next_pot(w);
		h = next_pot(h);
		surf_gl_image_ptr gl_img = surf_gl_image_ptr(new surf_gl_image("rendertarget"));
		if (!gl_img->create( w,h,reduse)) {
			return surf_rendertarget_ptr();
		}
		surf_image_ptr image = surf_image_ptr( new surf_image( this, gl_img ) );
		surf_rendertarget::implementation* impl =  new surf_rendertarget::implementation(w,h,image,reduse);
		if (!impl->create(gl_img->get_id())) {
			delete impl;
			return surf_rendertarget_ptr();
		}
		return surf_rendertarget_ptr( new surf_rendertarget( impl ) );
	}
	return surf_rendertarget_ptr();
#endif
}

surf_rendertarget_ptr surf_graphics_server::get_getpixel_target() {
#ifndef RENDERTARGETS_SUPPORTED
	return surf_rendertarget_ptr();
#else
	if (!m_getpixel_target && SURF_GL_OES_framebuffer_object_supported()) {
		surf_rendertarget::implementation* impl =  new surf_rendertarget::implementation(16,16,surf_image_ptr(),false);
		if (!impl->create()) {
			delete impl;
			return surf_rendertarget_ptr();
		}
		m_getpixel_target = surf_rendertarget_ptr( new surf_rendertarget( impl ) );
	}
	return m_getpixel_target;
#endif
}

END_NAMESPACE_SURF
