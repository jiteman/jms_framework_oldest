/*
 * FTGL - OpenGL font library
 *
 * Copyright (c) 2001-2004 Henry Maddocks <ftgl@opengl.geek.nz>
 * Copyright (c) 2008 Sam Hocevar <sam@zoy.org>
 * Copyright (c) 2008 Sean Morrison <learner@brlcad.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef __ftgl__
#   warning This header is deprecated. Please use <FTGL/ftgl.h> from now.
#   include <FTGL/ftgl.h>
#endif

#ifndef __FTGlyph__
#define __FTGlyph__

class FTGlyphImpl;

/**
 * FTGlyph is the base class for FTGL glyphs.
 *
 * It provides the interface between Freetype glyphs and their openGL
 * renderable counterparts. This is an abstract class and derived classes
 * must implement the <code>Render</code> function.
 *
 * @see FTBBox
 * @see FTPoint
 */
class FTGL_EXPORT FTGlyph
{
    protected:
        /**
         * Create a glyph.
         *
         * @param glyph  The Freetype glyph to be processed
         */
        FTGlyph(FT_GlyphSlot glyph);

    private:
        /**
         * Internal FTGL FTGlyph constructor. For private use only.
         *
         * @param pImpl  Internal implementation object. Will be destroyed
         *               upon FTGlyph deletion.
         */
        FTGlyph(FTGlyphImpl *pImpl);

        /* Allow our internal subclasses to access the private constructor */
        friend class FTBitmapGlyph;
        friend class FTBufferGlyph;
        friend class FTExtrudeGlyph;
        friend class FTOutlineGlyph;
        friend class FTPixmapGlyph;
        friend class FTPolygonGlyph;
        friend class FTTextureGlyph;

    public:
        /**
          * Destructor
          */
        virtual ~FTGlyph();

        /**
         * Renders this glyph at the current pen position.
         *
         * @param pen  The current pen position.
         * @param renderMode  Render mode to display
         * @return  The advance distance for this glyph.
         */
        virtual const FTPoint& Render(const FTPoint& pen, int renderMode) = 0;

        /**
         * Return the advance width for this glyph.
         *
         * @return  advance width.
         */
        virtual float Advance() const;

        /**
         * Return the bounding box for this glyph.
         *
         * @return  bounding box.
         */
        virtual const FTBBox& BBox() const;

        /**
         * Queries for errors.
         *
         * @return  The current error code.
         */
        virtual FT_Error Error() const;

    private:
        /**
         * Internal FTGL FTGlyph implementation object. For private use only.
         */
        FTGlyphImpl *impl;
};

#endif  //  __FTGlyph__
