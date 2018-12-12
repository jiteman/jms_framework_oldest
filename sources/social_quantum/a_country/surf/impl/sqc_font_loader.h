#pragma once

#include "../surf_gl.h"
#include "../../sqc/sqc_defs.h"
#include "../../sqc/sqc_data_stream.h"

NAMESPACE_SQC

using namespace surf;

class sqc_font_loader : public surf_font_loader {
public:
    virtual bool load_font( const char *name, surf_font_content& font_content );
protected:
	virtual sqc_data_stream_ptr open_file( const char* name );
};

END_NAMESPACE_SQC
