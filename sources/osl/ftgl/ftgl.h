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
#define __ftgl__

#include "ftgl_dll.h"

/* We need the Freetype headers */
#include "osl/freetype/ft2build.h"
#include "osl/freetype/freetype.h"
#include "osl/freetype/ftglyph.h"
#include "osl/freetype/ftoutln.h"

/* Floating point types used by the library */
typedef double   FTGL_DOUBLE;
typedef float    FTGL_FLOAT;

namespace FTGL {
    enum RenderMode {
        RENDER_FRONT = 0x0001,
        RENDER_BACK  = 0x0002,
        RENDER_SIDE  = 0x0004,
        RENDER_ALL   = 0xffff
    };

    enum TextAlignment {
        ALIGN_LEFT    = 0,
        ALIGN_CENTER  = 1,
        ALIGN_RIGHT   = 2,
        ALIGN_JUSTIFY = 3
    };
}

// Compiler-specific conditional compilation
#ifdef _MSC_VER // MS Visual C++

    // Disable various warning.
    // 4786: template name too long
//     #pragma warning(disable : 4251)
//     #pragma warning(disable : 4275)
//     #pragma warning(disable : 4786)

    // The following definitions control how symbols are exported.
    // If the target is a static library ensure that FTGL_LIBRARY_STATIC
    // is defined. If building a dynamic library (ie DLL) ensure the
    // FTGL_LIBRARY macro is defined, as it will mark symbols for
    // export. If compiling a project to _use_ the _dynamic_ library
    // version of the library, no definition is required.
    #if defined FTGL_LIBRARY_STATIC      // static lib - no special export required
    #  define FTGL_EXPORT
    #elif defined FTGL_LIBRARY              // dynamic lib - must export/import symbols appropriately.
    #  define FTGL_EXPORT   __declspec(dllexport)
    #else
    #  define FTGL_EXPORT   __declspec(dllimport)
    #endif

#else
    // Compiler that is not MS Visual C++.
    // Ensure that the export symbol is defined (and blank)
    #define FTGL_EXPORT
#endif

#include "FTPoint.h"
#include "FTBBox.h"
#include "FTBuffer.h"

#include "ftglyph/FTGlyph.h"
#include "ftglyph/FTBitmapGlyph.h"
#include "ftglyph/FTBufferGlyph.h"
#include "ftglyph/FTExtrudeGlyph.h"
#include "ftglyph/FTOutlineGlyph.h"
#include "ftglyph/FTPixmapGlyph.h"
#include "ftglyph/FTPolygonGlyph.h"
#include "ftglyph/FTTextureGlyph.h"

#include "ftfont/FTFont.h"
#include "ftfont/FTGLBitmapFont.h"
#include "ftfont/FTBufferFont.h"
#include "ftfont/FTGLExtrudeFont.h"
#include "ftfont/FTGLOutlineFont.h"
#include "ftfont/FTGLPixmapFont.h"
#include "ftfont/FTGLPolygonFont.h"
#include "ftfont/FTGLTextureFont.h"

#include "ftlayout/FTLayout.h"
#include "ftlayout/FTSimpleLayout.h"

#endif  //  __ftgl__
