#include "sqc_png.h"
extern "C" {
#include <png.h>
}

NAMESPACE_SQC_PNG

static void sqc_png_error_handler( png_structp png_ptr, png_const_charp msg ) {
	char buf[256];

#if defined( JMSF_WINDOWS )
	::_snprintf(
#else // #ifdef _WIN32
    ::snprintf(
#endif // #ifdef _WIN32
        buf,255,"png: %s",msg);
	std::cout << buf << std::endl;
}
static void sqc_png_read_handler( png_structp png_ptr, png_bytep data, png_size_t length ) {
    sqc_data_stream    *stream = (sqc_data_stream*)png_get_io_ptr( png_ptr );
	stream->read( data, length );
}

bool png_image::decode( sqc_data_stream* stream, sqc_image_raw_data& data, bool info_only , bool reduce_bitdepth) {
	png_structp png = png_create_read_struct( PNG_LIBPNG_VER_STRING, this, sqc_png_error_handler, 0 );
	if (!png) return false;
	png_infop info = png_create_info_struct( png );
	if (!info) {
		png_destroy_read_struct(&png, 0, 0);
		return false;
	}
	
	sqc_byte* raw_data = 0;
	
	png_set_read_fn(png, stream, sqc_png_read_handler);
	
    if (setjmp ((*png_set_longjmp_fn((png), (png_longjmp_ptr)longjmp, sizeof
                                     (jmp_buf)))))
	//if (setjmp(png_jmpbuf(png)))
	{
		png_destroy_read_struct(&png, &info, 0);
		delete [] raw_data;
		return false;
	}

	png_read_info( png, info );
	
	if( png_get_bit_depth( png, info ) == 16 ) {
        png_set_strip_16( png );
        png_read_update_info( png, info );
    }
	
	png_byte color_type = png_get_color_type(png,info);
	
	switch (color_type) {
        case PNG_COLOR_TYPE_GRAY:
	        png_set_expand_gray_1_2_4_to_8(png);
			png_set_gray_to_rgb(png);
            png_read_update_info( png, info );
            break;
        case PNG_COLOR_TYPE_PALETTE:
            png_set_palette_to_rgb(png); 
            png_read_update_info( png, info );
            break;
        case PNG_COLOR_TYPE_RGB:
            
            break;
			
		case PNG_COLOR_TYPE_RGB_ALPHA:
			break;
			
        case PNG_COLOR_TYPE_GRAY_ALPHA:
	        png_set_expand_gray_1_2_4_to_8(png);
			png_set_gray_to_rgb(png);
            png_read_update_info( png, info );
			break; 
			
        default:
			assert(!"UNKNOWN TYPE");            
            break;
    }

	int  image_width = png_get_image_width( png, info );
    int  image_height = png_get_image_height( png, info );

	data.bpp = ( png_get_channels( png, info ) * png_get_bit_depth( png, info ) );

	data.size.cx = image_width;
	data.size.cy = image_height;

	if (info_only) {
		png_destroy_read_struct(&png, &info, 0);
		return true;
	}
	
    size_t  cb_row = image_width * data.bpp / 8;
    size_t  cb_alloc = image_height * cb_row;
    
    assert( !raw_data );
    raw_data = new sqc_byte[cb_alloc];
    
    if( !raw_data ) {
		png_destroy_read_struct(&png, &info, 0);
        return false;
    }
    
    {
#if defined( JMSF_WINDOWS )
        std::vector< png_bytep > rows( image_height );
        for( int y = 0; y < image_height;  ++y ) {
            rows[ y ] = raw_data + ( y * cb_row );
        }
        
        png_read_image( png, &rows[ 0 ] );
#else // #ifdef _WIN32
        png_bytep rows[image_height];
        for( int y = 0; y < image_height;  ++y ) {
            rows[y] = raw_data + (y * cb_row);
        }
        
        png_read_image( png, rows );
#endif // #ifdef _WIN32
    }
    
    if ( reduce_bitdepth ) {
        int bpp = data.bpp;
        png_bytep reduced = 0;
        int i;
        
        if ( bpp == 32 ) {
            // 32 -> 4-4-4-4
            reduced = new sqc_byte[image_height * image_width * 2];
			
			unsigned long  *inPixel32  = (unsigned long*)raw_data;
			unsigned short *outPixel16 = (unsigned short*)reduced;
			
			for ( i = 0; i < image_height * image_width; ++i ) {
                unsigned long pixel = *inPixel32++;
                *outPixel16++ = ((pixel & 0x000000F0) <<  8)  | // R
				((pixel & 0x0000F000) >>  4)  | // G
				((pixel & 0x00F00000) >> 16)  | // B
				((pixel & 0xF0000000) >> 28);   // A
            }
        }
        else if ( bpp == 24 ) {
            // 24 -> 5-6-5
            reduced = new sqc_byte[image_height * image_width * 2];
			
			unsigned char  *inPixel8   = (unsigned char*)raw_data;
			unsigned short *outPixel16 = (unsigned short*)reduced;
			
			for ( i = 0, --inPixel8; i < image_height * image_width; ++i ) {
				*outPixel16++ = ((((unsigned short)*++inPixel8) & 0x00F8) << 8) |   // R
				((((unsigned short)*++inPixel8) & 0x00FC) << 3) |   // G
				((((unsigned short)*++inPixel8) & 0x00F8) >> 3);    // B
			}
        }
        
        if ( reduced ) {
            delete []raw_data;
            raw_data = reduced;
        }
    }
	png_destroy_read_struct(&png, &info, 0);
    data.data = raw_data;
    return true;
}

END_NAMESPACE_SQC_PNG

