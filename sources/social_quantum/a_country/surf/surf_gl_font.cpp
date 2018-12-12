#include "surf_gl.h"
#include "sqc_file_api.h"
#include "FTGL/ftgles.h"
#include "FTGL/ftglesGlue.h"
#include "../utils/crc32utils.h"

#include <gl/gl.h>
#include <gl/glext.h>


NAMESPACE_SURF

//
// surf_font
//
class surf_gl_font
{
public:
    surf_gl_font(surf_val face_size, const char *face_name) : font_face_size(face_size), font_face_name(face_name), font(NULL), font_content()
    {
        if (font_face_name.size())
        {
            font = new FTTextureFont(font_face_name.c_str());

            common_init();
        }
    }

    surf_gl_font(const surf_font_content& content, surf_val face_size) : font_face_size(face_size), font_face_name(""), font(NULL), font_content(content)
    {
        if (font_content.size())
        {
            font = new FTTextureFont((const unsigned char*)&font_content[0], font_content.size());

            common_init();
        }
    }

    virtual ~surf_gl_font()
    {
        if (font)
            delete font;
    }

    void common_init()
    {
        if (font && font->Error())
        {
            delete font;
            font = NULL;
        }

        if (font)
        {
			/// use hinter
			//font->GlyphLoadFlags(FT_LOAD_DEFAULT | FT_LOAD_NO_BITMAP );
            font->FaceSize(font_face_size);
            layout.SetFont(font);
        }
    }

    void set_layout_params(surf_size const &size, surf_draw_string_flags flags)
    {
        switch (flags & draw_string_alignment_mask)
        {
            case draw_string_alignment_left:    layout.SetAlignment(FTGL::ALIGN_LEFT);    break;
            case draw_string_alignment_right:   layout.SetAlignment(FTGL::ALIGN_RIGHT);   break;
            case draw_string_alignment_center:  layout.SetAlignment(FTGL::ALIGN_CENTER);  break;
            case draw_string_alignment_justify: layout.SetAlignment(FTGL::ALIGN_JUSTIFY); break;
        }

        layout.SetLineLength(size.cx);
    }

    void draw_debug_rect(surf_point const &point, surf_size const &size)
    {
        GLfloat coords[8] = { point.x, point.y, point.x, point.y + size.cy, point.x + size.cx, point.y + size.cy, point.x + size.cx, point.y };

        GLfloat color[4];
        glGetFloatv(GL_CURRENT_COLOR, color);

        glColor4f(1, 1, 0, 1);
        glDisable(GL_TEXTURE_2D);

        glLineWidth(1);

        glVertexPointer(2, GL_FLOAT, 0, coords);
        glDrawArrays(GL_LINE_LOOP, 0, 4);

        glColor4f(color[0], color[1], color[2], color[3]);
        glEnable(GL_TEXTURE_2D);
    }

    surf_size calc_size(surf_string const &s, surf_size const &size, surf_draw_string_flags flags)
    {
        if (font)
        {
            set_layout_params(size, flags);

            FTBBox box = layout.BBox(s.c_str());
            return surf_size(box.Upper().Xf() - box.Lower().Xf(), box.Upper().Yf() - box.Lower().Yf());
        }

        return surf_size();
    }

    surf_val calc_adjust_font_size_ratio(surf_string const &s, surf_size const &size, surf_draw_string_flags flags)
    {
        set_layout_params(size, flags);

        FTBBox   box   = layout.BBox(s.c_str());
        surf_val ratio = (box.Upper().Yf() - box.Lower().Yf()) / size.cy;

        if (ratio > 1.0f)
        {
            surf_val low = 1.0f;
            surf_val upp = ratio;

            do
            {
                ratio = (low + upp) / 2.0f;

                surf_size out_size = surf_size(size.cx * ratio, size.cy * ratio);

                set_layout_params(out_size, flags);
                box = layout.BBox(s.c_str());

                float r = (box.Upper().Yf() - box.Lower().Yf()) / out_size.cy;

                if (r < 1.0f && (1.0f - r) > 0.05f)
                {
                    upp = ratio - 0.005f;
                }
                else if (r > 1.0f && (r - 1.0f) > 0.05f)
                {
                    low = ratio + 0.005f;
                }
                else
                {
                    break;
                }
            }
            while (low <= upp);

            return ratio;
        }

        return 1.0f;
    }

    void calc_truncation_params(surf_string const &s, surf_size const &size, surf_draw_string_flags flags, size_t &pos, size_t &count)
    {
        set_layout_params(size, flags);

        FTBBox box = layout.BBox(s.c_str());
        surf_val h = box.Upper().Yf() - box.Lower().Yf();

        if (h > size.cy)
        {
            size_t b_low, b_upp, e_low, e_upp, r_pos, r_cnt, e_cnt;

            switch (flags & draw_string_truncation_mask)
            {
                case draw_string_truncation_head:   b_low = 0; b_upp = 0;            e_low = 0;     e_upp = s.size(); break;
                case draw_string_truncation_tail:   b_low = 0; b_upp = s.size();     e_low = 0;     e_upp = 0;        break;
                case draw_string_truncation_middle: b_low = 0; b_upp = s.size() / 2; e_low = b_upp; e_upp = s.size(); break;
            }

            size_t o_b_upp = b_upp, o_e_upp = e_upp, p_cnt = 0;

            do
            {
                r_pos = (b_low + b_upp) / 2;
                e_cnt = (e_low + e_upp) / 2;
                r_cnt = o_e_upp - e_cnt + o_b_upp - r_pos;

                surf_string out_string = s;
                out_string.replace(r_pos, r_cnt, " … ");

                box = layout.BBox(out_string.c_str());
                h   = box.Upper().Yf() - box.Lower().Yf();

                if (r_cnt == p_cnt)
                {
                    break;
                }
                else if (h > size.cy)
                {
                    b_upp = r_pos;
                    e_upp = e_cnt;
                }
                else
                {
                    b_low = r_pos;
                    e_low = e_cnt;
                }

                p_cnt = r_cnt;
            }
            while (b_low <= b_upp && e_low <= e_upp);

            pos   = r_pos;
            count = r_cnt;
        }
        else
        {
            pos   = surf_string::npos;
            count = 0;
        }
    }

    virtual void draw(surf_string const &s, surf_point const &point, surf_size const &size, surf_draw_string_flags flags, surf_color const &color, surf_color const &shadow_color, surf_size const &shadow_size)
    {
        if (font)
        {
            surf_point  out_point  = point;
            surf_size   out_size   = size;
            surf_string out_string = s;

            glPushMatrix();

            if ((flags & draw_string_adjust_font_size_mask) == draw_string_adjust_font_size_enabled)
            {
                // search cached value
                std::stringstream outstream;
                outstream << s << size << std::hex << draw_string_adjust_font_size_enabled;
                surf_string stream_string = outstream.str();
                unsigned long crc = crc32utils::crc32(stream_string.c_str(), stream_string.size() * sizeof(surf_string::value_type));

                std::map<unsigned long, cached_params_union>::iterator it = cache.find(crc);

                surf_val ratio;

                if (it != cache.end())
                {
                    // found cached value - use it
                    ratio = it->second.adjust_font_size_ratio;
                }
                else
                {
                    // calculate value and cache it
                    ratio = calc_adjust_font_size_ratio(s, size, flags);

                    cached_params_union params;
                    params.adjust_font_size_ratio = ratio;
                    cache[crc] = params;
                }

                if (ratio > 1.0f)
                {
                    out_size.cx *= ratio;
                    out_size.cy *= ratio;
                    out_point.x -= (out_size.cx - size.cx) / 2.0;
                    out_point.y -= (out_size.cy - size.cy) / 2.0;

                    ratio = 1.0f / ratio;

                    glTranslatef((point.x + size.cx / 2.0f) * (1.0f - ratio), (point.y + size.cy / 2.0f) * (1.0f - ratio), 0.0f);
                    glScalef(ratio, ratio, 1.0f);
                }
            }
            else if ((flags & draw_string_truncation_mask) != draw_string_truncation_disabled)
            {
                // search cached value
                std::stringstream outstream;
                outstream << s << size << std::hex << (flags & draw_string_truncation_mask);
                surf_string stream_string = outstream.str();
                unsigned long crc = crc32utils::crc32(stream_string.c_str(), stream_string.size() * sizeof(surf_string::value_type));

                std::map<unsigned long, cached_params_union>::iterator it = cache.find(crc);

                size_t pos, count;

                if (it != cache.end())
                {
                    // found cached value - use it
                    pos   = it->second.string_truncation_params.pos;
                    count = it->second.string_truncation_params.count;
                }
                else
                {
                    // calculate value and cache it
                    calc_truncation_params(s, size, flags, pos, count);

                    cached_params_union params;
                    params.string_truncation_params.pos   = pos;
                    params.string_truncation_params.count = count;
                    cache[crc] = params;
                }

                if (pos != surf_string::npos && count != 0)
                {
                    out_string.replace(pos, count, " … ");
                }
            }

            set_layout_params(out_size, flags);

            FTBBox box = layout.BBox(out_string.c_str());
			/// fix oneline vcenter alignment
			FTBBox udBox = layout.BBox("Ty");
			surf::surf_val upper = int( std::max( box.Upper().Yf(), udBox.Upper().Yf() ) );
			surf::surf_val lower = int( std::min( box.Lower().Yf(), udBox.Lower().Yf() ) );

            switch (flags & draw_string_valignment_mask)
            {
                case draw_string_valignment_top:    glTranslatef(out_point.x, out_point.y + out_size.cy - upper, 0.0f);                             break;
                case draw_string_valignment_bottom: glTranslatef(out_point.x, out_point.y - lower, 0.0f);                                           break;
                case draw_string_valignment_center: glTranslatef(out_point.x, out_point.y + int( (out_size.cy - upper - lower) / 2.0f), 0.0f); break;
            }

            ftglSetTextColor(color.r, color.g, color.b, color.a);

            if ((flags & draw_string_draw_shadow_mask) == draw_string_draw_shadow_enabled)
            {
                ftglEnableDrawShadow(true);
                ftglSetShadowColor(shadow_color.r, shadow_color.g, shadow_color.b, shadow_color.a);
                ftglSetShadowOffset(shadow_size.cx, shadow_size.cy, 0);
            }

            layout.Render(out_string.c_str());

            if ((flags & draw_string_draw_shadow_mask) == draw_string_draw_shadow_enabled)
            {
                ftglEnableDrawShadow(false);
            }

            glPopMatrix();
        }

        #ifdef DEBUG
        draw_debug_rect(point, size);
        #endif
		// reset error
		glGetError();
    }

protected:
    surf_string         font_face_name;
    surf_val            font_face_size;
    FTFont*             font;
    FTSimpleLayout      layout;
    surf_font_content   font_content;

private:
    typedef union
    {
        surf_val adjust_font_size_ratio;

        struct
        {
            size_t pos;
            size_t count;
        }
        string_truncation_params;
    }
    cached_params_union;

    std::map<unsigned long, cached_params_union> cache;
};

class surf_gl_stroked_font : public surf_gl_font
{
public:
    surf_gl_stroked_font(surf_val face_size, const char *face_name, surf_word stroke_size) : surf_gl_font(face_size, face_name), stroke(stroke_size), stroked_font(NULL)
    {
        // we don't create a stroked part of the font if normal part isn't available
        if (font)
        {
            ftglSetGlyphsStrokeSize(stroke);

            stroked_font = new FTTextureFont(font_face_name.c_str());

            common_init_stroked();

            ftglSetGlyphsStrokeSize(0);
        }
    }

    surf_gl_stroked_font(const surf_font_content& content, surf_val face_size, surf_word stroke_size) : surf_gl_font(content, face_size), stroke(stroke_size), stroked_font(NULL)
    {
        // we don't create a stroked part of the font if normal part isn't available
        if (font)
        {
            ftglSetGlyphsStrokeSize(stroke);

            stroked_font = new FTTextureFont((const unsigned char*)&font_content[0], font_content.size());

            common_init_stroked();

            ftglSetGlyphsStrokeSize(0);
        }
    }

    virtual ~surf_gl_stroked_font()
    {
        if (stroked_font)
            delete stroked_font;
    }

    void common_init_stroked()
    {
        if (stroked_font && stroked_font->Error())
        {
            delete stroked_font;
            stroked_font = NULL;
        }

        if (stroked_font)
        {
            stroked_font->FaceSize(font_face_size);
        }
    }

    virtual void draw(surf_string const &s, surf_point const &point, surf_size const &size, surf_draw_string_flags flags, surf_color const &color, surf_color const &shadow_color, surf_size const &shadow_size)
    {
        if ((flags & draw_string_draw_shadow_mask) == draw_string_draw_shadow_enabled)
        {
            flags = (flags & ~draw_string_draw_shadow_mask) | draw_string_draw_shadow_disabled;

            if (stroked_font)
            {
                layout.SetFont(stroked_font);
                ftglSetGlyphsStrokeSize(stroke);

                surf_gl_font::draw(s, point, size, flags, shadow_color, shadow_color, shadow_size);

                ftglSetGlyphsStrokeSize(0);
                layout.SetFont(font);
            }
        }

        surf_gl_font::draw(s, point, size, flags, color, shadow_color, shadow_size);
		// reset error
		glGetError();
    }

private:
    surf_word   stroke;
    FTFont*     stroked_font;
};


//
//
//
surf_font::surf_font( surf_gl_font_ptr p ) : impl(p)
{
}

surf_font::~surf_font()
{
}

surf_size surf_font::calc_size(surf_context_ptr ctx, surf_string const &s, surf_size const &size, surf_draw_string_flags flags)
{
    return impl->calc_size(s, size, flags);
}

void surf_font::draw(surf_context_ptr ctx, surf_string const &s, surf_point const &point, surf_size const &size, surf_draw_string_flags flags, surf_color const &color, surf_color const &shadow_color, surf_size const &shadow_size)
{
	surf::surf_color _color = color*ctx->get_color();
	surf::surf_color _shadow_color = shadow_color*ctx->get_color();
    impl->draw(s, point , size, flags, _color, _shadow_color, shadow_size);
}


//
//
//

const surf_font_content& surf_graphics_server::get_font_content( const char *face_name ) {
    
    font_content_map::const_iterator it = m_font_content_map.find( face_name );
    if( it != m_font_content_map.end() ) {
        return it->second;
    }

    surf_font_content font_content;
    font_loader.load_font(face_name, font_content);
    
    std::pair<std::map<std::string,surf_font_content>::iterator,bool> ret =
    m_font_content_map.insert( std::pair<std::string,surf_font_content>( face_name, font_content ) );

    return ret.first->second;

}

surf_font_ptr surf_graphics_server::create_font(surf_val face_size, const char *face_name)
{
    const surf_font_content& font_content = get_font_content( face_name );

    //surf_gl_font_ptr impl(new surf_gl_font(face_size, sqc::file_api::get_resource_path(face_name, "").c_str()));
    surf_gl_font_ptr impl(new surf_gl_font(font_content, face_size));
    return surf_font_ptr(new surf_font(impl));
}

surf_font_ptr surf_graphics_server::create_stroked_font(surf_val face_size, const char *face_name, surf_word stroke_size)
{
    const surf_font_content& font_content = get_font_content( face_name );

    //surf_gl_font_ptr impl(new surf_gl_stroked_font(face_size, sqc::file_api::get_resource_path(face_name, "").c_str(), stroke_size));
    surf_gl_font_ptr impl(new surf_gl_stroked_font(font_content, face_size, stroke_size));
    return surf_font_ptr(new surf_font(impl));
}

END_NAMESPACE_SURF
