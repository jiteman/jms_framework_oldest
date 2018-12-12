/*
 *  city_tooltips.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 10/3/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "city_tooltips.h"

NAMESPACE_SQC_FRAMEWORK


sqc_city_tooltips_manager::sqc_city_tooltips_manager() {
	/// @todo theme_size
	surf::surf_val fnt_size = 12;
	if (framework().windows_factory().get_theme_size()!=sqc_theme_small)
		fnt_size*=2;
	set_font( framework().graphics().create_font( fnt_size, "Arial-BoldMT.otf" ) );
}

END_NAMESPACE_SQC_FRAMEWORK