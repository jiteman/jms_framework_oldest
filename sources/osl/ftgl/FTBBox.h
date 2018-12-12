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

#ifndef __FTBBox__
#define __FTBBox__

/**
 * FTBBox is a convenience class for handling bounding boxes.
 */
class FTGL_EXPORT FTBBox
{
    public:
        /**
         * Default constructor. Bounding box is set to zero.
         */
        FTBBox();

        /**
         * Constructor.
         */
        FTBBox(float lx, float ly, float lz, float ux, float uy, float uz);

        /**
         * Constructor.
         */
        FTBBox(FTPoint l, FTPoint u);

        /**
         * Constructor. Extracts a bounding box from a freetype glyph. Uses
         * the control box for the glyph. <code>FT_Glyph_Get_CBox()</code>
         *
         * @param glyph A freetype glyph
         */
        FTBBox(FT_GlyphSlot glyph);

        /**
         * Destructor
         */
        ~FTBBox();

        /**
         * Mark the bounds invalid by setting all lower dimensions greater
         * than the upper dimensions.
         */
        void Invalidate();

        /**
         * Determines if this bounding box is valid.
         *
         * @return True if all lower values are <= the corresponding
         *         upper values.
         */
        bool IsValid();

        /**
         * Move the Bounding Box by a vector.
         *
         * @param vector  The vector to move the bbox in 3D space.
         */
        FTBBox& operator += (const FTPoint vector);

        /**
         * Combine two bounding boxes. The result is the smallest bounding
         * box containing the two original boxes.
         *
         * @param bbox  The bounding box to merge with the second one.
         */
        FTBBox& operator |= (const FTBBox& bbox);

        void SetDepth(float depth);


        const FTPoint &Upper() const;
        const FTPoint &Lower() const;

    private:
        /**
         * The bounds of the box
         */
        FTPoint lower, upper;
};

#endif  //  __FTBBox__
