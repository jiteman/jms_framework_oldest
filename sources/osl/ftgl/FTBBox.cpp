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

#include "ftgl_config.h"

#include "ftgl.h"


/**
 * FTBBox is a convenience class for handling bounding boxes.
 */
FTBBox::FTBBox()
    :
        lower( 0.0f, 0.0f, 0.0f ),
        upper( 0.0f, 0.0f, 0.0f )
{}

FTBBox::FTBBox(float lx, float ly, float lz, float ux, float uy, float uz)
    :
        lower(lx, ly, lz),
        upper(ux, uy, uz)
{}

FTBBox::FTBBox(FTPoint l, FTPoint u)
        :   lower(l),
            upper(u)
        {}

        /**
         * Constructor. Extracts a bounding box from a freetype glyph. Uses
         * the control box for the glyph. <code>FT_Glyph_Get_CBox()</code>
         *
         * @param glyph A freetype glyph
         */
FTBBox::FTBBox(FT_GlyphSlot glyph)
        :   lower(0.0f, 0.0f, 0.0f),
            upper(0.0f, 0.0f, 0.0f)
        {
            FT_BBox bbox;
            FT_Outline_Get_CBox(&(glyph->outline), &bbox);

            lower.X(static_cast<float>(bbox.xMin) / 64.0f);
            lower.Y(static_cast<float>(bbox.yMin) / 64.0f);
            lower.Z(0.0f);
            upper.X(static_cast<float>(bbox.xMax) / 64.0f);
            upper.Y(static_cast<float>(bbox.yMax) / 64.0f);
            upper.Z(0.0f);
        }

        /**
         * Destructor
         */
FTBBox::~FTBBox()
        {}

        /**
         * Mark the bounds invalid by setting all lower dimensions greater
         * than the upper dimensions.
         */
void FTBBox::Invalidate()
        {
            lower = FTPoint(1.0f, 1.0f, 1.0f);
            upper = FTPoint(-1.0f, -1.0f, -1.0f);
        }

        /**
         * Determines if this bounding box is valid.
         *
         * @return True if all lower values are <= the corresponding
         *         upper values.
         */
bool FTBBox::IsValid()
        {
            return lower.X() <= upper.X()
                && lower.Y() <= upper.Y()
                && lower.Z() <= upper.Z();
        }

        /**
         * Move the Bounding Box by a vector.
         *
         * @param vector  The vector to move the bbox in 3D space.
         */
FTBBox& FTBBox::operator += (const FTPoint vector)
        {
            lower += vector;
            upper += vector;

            return *this;
        }

        /**
         * Combine two bounding boxes. The result is the smallest bounding
         * box containing the two original boxes.
         *
         * @param bbox  The bounding box to merge with the second one.
         */
FTBBox& FTBBox::operator |= (const FTBBox& bbox)
        {
            if(bbox.lower.X() < lower.X()) lower.X(bbox.lower.X());
            if(bbox.lower.Y() < lower.Y()) lower.Y(bbox.lower.Y());
            if(bbox.lower.Z() < lower.Z()) lower.Z(bbox.lower.Z());
            if(bbox.upper.X() > upper.X()) upper.X(bbox.upper.X());
            if(bbox.upper.Y() > upper.Y()) upper.Y(bbox.upper.Y());
            if(bbox.upper.Z() > upper.Z()) upper.Z(bbox.upper.Z());

            return *this;
        }

void FTBBox::SetDepth(float depth)
        {
            if(depth > 0)
                upper.Z(lower.Z() + depth);
            else
                lower.Z(upper.Z() + depth);
        }


const FTPoint &FTBBox::Upper() const
        {
            return upper;
        }


const FTPoint &FTBBox::Lower() const
        {
            return lower;
        }
