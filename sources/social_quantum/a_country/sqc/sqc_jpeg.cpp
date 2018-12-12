/*
 *  sqc_jpeg.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/19/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_jpeg.h"
#include <jpeglib.h>
#include <setjmp.h>
#include <iostream>
#include <fstream>

static const size_t BUFFER_SIZE = 1024*8;

NAMESPACE_SQC_JPEG


// struct for handling jpeg errors
struct sqc_jpeg_error_mgr
{
	// public jpeg error fields
	struct jpeg_error_mgr pub;
	
	// for longjmp, to return to caller on a fatal error
	jmp_buf setjmp_buffer;
};

// struct for reading jpeg data
struct sqc_jpeg_source_mgr
{
	// public jpeg source fields
	struct jpeg_source_mgr pub;
	
	// stream ptr
	sqc_data_stream*	stream;
	sqc_byte buffer[BUFFER_SIZE];
};

static void sqc_jpeg_init_source (j_decompress_ptr cinfo)
{
	sqc_jpeg_source_mgr * src = (sqc_jpeg_source_mgr*)cinfo->src;
	src->pub.bytes_in_buffer = 0;
	src->pub.next_input_byte = src->buffer;
}



static boolean sqc_jpeg_fill_input_buffer (j_decompress_ptr cinfo)
{
	sqc_jpeg_source_mgr * src = (sqc_jpeg_source_mgr*)cinfo->src;
	if (!src->stream) return 0;
	src->pub.bytes_in_buffer = src->stream->read(src->buffer,BUFFER_SIZE);
	src->pub.next_input_byte = src->buffer;
	return (src->pub.bytes_in_buffer>0) ? 1 : 0;
}

static void sqc_jpeg_skip_input_data (j_decompress_ptr cinfo, long count)
{
	sqc_jpeg_source_mgr * src = (sqc_jpeg_source_mgr*)cinfo->src;
	if(count > 0)
	{
		if (src->pub.bytes_in_buffer>=count) {
			src->pub.bytes_in_buffer -= count;
			src->pub.next_input_byte += count;
		} else {
			count-=src->pub.bytes_in_buffer;
			src->pub.bytes_in_buffer = 0;
			src->stream->seek(count,true);
		}
	}
}

static void sqc_jpeg_term_source (j_decompress_ptr cinfo)
{
	// DO NOTHING
}


static void sqc_jpeg_error_exit (j_common_ptr cinfo)
{
	// unfortunately we need to use a goto rather than throwing an exception
	// as gcc crashes under linux crashes when using throw from within
	// extern c code
	
	// Always display the message
	(*cinfo->err->output_message) (cinfo);
	
	// cinfo->err really points to a irr_error_mgr struct
	sqc_jpeg_error_mgr *myerr = (sqc_jpeg_error_mgr*) cinfo->err;
	
	longjmp(myerr->setjmp_buffer, 1);
}

static void sqc_jpeg_output_message(j_common_ptr cinfo)
{
	// display the error message.
	char temp1[JMSG_LENGTH_MAX];
	(*cinfo->err->format_message)(cinfo, temp1);
	std::cout << temp1 << std::endl;
}


bool jpeg_image::decode( sqc_data_stream* stream, sqc_image_raw_data& data, bool info_only , bool reduce_bitdepth) {
	sqc_byte *raw_data=0;
	
	// allocate and initialize JPEG decompression object
	struct jpeg_decompress_struct cinfo;
	struct sqc_jpeg_error_mgr jerr;
	
	//We have to set up the error handler first, in case the initialization
	//step fails.  (Unlikely, but it could happen if you are out of memory.)
	//This routine fills in the contents of struct jerr, and returns jerr's
	//address which we place into the link field in cinfo.
	
	cinfo.err = jpeg_std_error(&jerr.pub);
	cinfo.err->error_exit = sqc_jpeg_error_exit;
	cinfo.err->output_message = sqc_jpeg_output_message;
	
	// compatibility fudge:
	// we need to use setjmp/longjmp for error handling as gcc-linux
	// crashes when throwing within external c code
	if (setjmp(jerr.setjmp_buffer))
	{
		// If we get here, the JPEG code has signaled an error.
		// We need to clean up the JPEG object and return.
		
		jpeg_destroy_decompress(&cinfo);
		
		// if the row pointer was created, we delete it.
		if (raw_data)
			delete [] raw_data;
		// return error
		return false;
	}
	
	// Now we can initialize the JPEG decompression object.
	jpeg_create_decompress(&cinfo);
	
	// specify data source
	sqc_jpeg_source_mgr jsrc;
	jsrc.stream = stream;
	
	// Set up data pointer
	jsrc.pub.bytes_in_buffer = 0;
	jsrc.pub.next_input_byte = (JOCTET*)0;
	cinfo.src = &jsrc.pub;
	
	jsrc.pub.init_source = sqc_jpeg_init_source;
	jsrc.pub.fill_input_buffer = sqc_jpeg_fill_input_buffer;
	jsrc.pub.skip_input_data = sqc_jpeg_skip_input_data;
	jsrc.pub.resync_to_restart = jpeg_resync_to_restart;
	jsrc.pub.term_source = sqc_jpeg_term_source;
	
	
	// Decodes JPG input from whatever source
	// Does everything AFTER jpeg_create_decompress
	// and BEFORE jpeg_destroy_decompress
	// Caller is responsible for arranging these + setting up cinfo
	
	// read file parameters with jpeg_read_header()
	jpeg_read_header(&cinfo, TRUE);
	
	
	data.size.cx = cinfo.image_width;
	data.size.cy = cinfo.image_height;
	
	data.bpp = 24;
	
	if (info_only) {
		jpeg_destroy_decompress(&cinfo);
		return true;
	}

	cinfo.out_color_space=JCS_RGB;
	cinfo.out_color_components=3;
	cinfo.do_fancy_upsampling=FALSE;
	
	jpeg_start_decompress(&cinfo);

	sqc_dword rowspan = cinfo.image_width * cinfo.out_color_components;
	sqc_dword height = cinfo.image_height;
	
	raw_data = new sqc_byte[height*rowspan];
	{
		JOCTET* rowPtr[height];
		for( sqc_dword i = 0; i < height; i++ )
			rowPtr[i] = &raw_data[ i * rowspan ];
		
		sqc_dword rowsRead = 0;
		
		while( cinfo.output_scanline < cinfo.output_height )
			rowsRead += jpeg_read_scanlines( &cinfo, &rowPtr[rowsRead], cinfo.output_height - rowsRead );
		
		jpeg_finish_decompress(&cinfo);
	}
	
	// Release JPEG decompression object
	// This is an important step since it will release a good deal of memory.
	jpeg_destroy_decompress(&cinfo);
	
	data.data = raw_data;
	
	return true;
}



END_NAMESPACE_SQC_JPEG