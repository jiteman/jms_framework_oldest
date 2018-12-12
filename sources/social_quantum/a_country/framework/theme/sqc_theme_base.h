/*
 *  sqc_theme_base.h
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/9/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "framework/sqc_framework_defs.h"
#include "milk/milk_defs.h"
#include "framework/layout/sqc_layout_defs.h"
#include <map>

NAMESPACE_SQC_FRAMEWORK



struct theme_button_def {
	enum button_skin {
		button_skin_normal,
		button_skin_pushed,
		button_skin_disabled,
		button_skins_amount
	};
	theme_button_def(){}
	theme_button_def(image_names s, image_names ps, image_names ds, slice_offsets slice) 
	: slice(slice)
    {
		skins[button_skin_normal] = s;
		skins[button_skin_pushed] = ps;
		skins[button_skin_disabled] = ds;
    }
	theme_button_def(image_names s, image_names ps,slice_offsets slice) 
	: slice(slice)
    {
		skins[button_skin_normal] = s;
		skins[button_skin_pushed] = ps;
    }
	theme_button_def(image_names s, slice_offsets slice) 
	: slice(slice)
    {
		skins[button_skin_normal] = s;
    }
	image_names skins[button_skins_amount];
    slice_offsets slice;
};


class sqc_theme_base : public milk::milk_theme
{
public:
	virtual bool on_end_dialog( milk::milk_dialog& dlg, milk::milk_dialog_init_arg const &arg ) {
		return true;
	}
	virtual surf::surf_rect get_dialog_content_rect( const surf::surf_rect& rect, const milk::milk_dialog_init_arg& init_arg );
	virtual void init_dialog_tabs( milk::milk_dialog& dlg, 
								  const milk::milk_dialog_init_arg& init_arg,
								  milk::milk_dialog_draw_arg const &arg,  
								  std::vector<milk::milk_dialog_tab_def>& tabs ) {}
	virtual void on_init_spinboard( milk::milk_spinboard& spin , milk::milk_spinboard_theme_flags flags ) {}
	virtual void on_init_pager( milk::milk_spinboard_pager& pager  ) {}
protected:
	sqc_theme_base( surf::surf_graphics_server& gs );
	surf::surf_9way_image_ptr create_9way_image( const char* file,
												const surf::surf_rect& offsets,
												bool draw_center = true,
												surf::surf_draw_image_flags flags = surf::tile_flag_none);
	surf::surf_9way_image_ptr create_9way_image( const image_names& name, const slice_offsets& slices,bool draw_center = true,
												surf::surf_draw_image_flags flags = surf::tile_flag_none);
	bool load_all();
	virtual bool preload() { return true;}
	void set_button_def( milk::theme_button_type type, const theme_button_def& def );
	virtual void draw_button( surf::surf_context_ptr ctx, milk::milk_theme_button &w ) ;
	surf::surf_graphics_server& graphics() { return m_graphics_server;}
protected:
	surf::surf_9way_image_ptr get_button_skin( milk::theme_button_type button_type, theme_button_def::button_skin skin);
private:
	struct theme_button_container {
		theme_button_def	def;
		surf::surf_9way_image_ptr images[theme_button_def::button_skins_amount];
	};
	typedef std::map<milk::theme_button_type,theme_button_container> ButtonsMap;
	ButtonsMap m_buttons_map;
	surf::surf_graphics_server&     m_graphics_server;
    bool 							m_loaded;
};

END_NAMESPACE_SQC_FRAMEWORK