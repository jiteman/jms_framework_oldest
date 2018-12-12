#pragma once

#include "../../view/sqc_scene_view.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_city_scene_view implementation
//
class sqc_city_scene_view : public sqc_scene_view {
public:
	sqc_city_scene_view( milk::milk_widget_ptr p, sqc_field_ptr f );
	virtual ~sqc_city_scene_view();

	virtual void on_create();
    virtual void render( surf::surf_context_ptr ctx );
    virtual surf::surf_size get_cell_size() const;
    
    virtual void on_notify( const sqc_provider_id& provider_id, const sqc_event_id& event_id, const sqc_event_value value );

private:
	surf::surf_font_ptr   font;
	virtual sqc_bubble_ptr create_bubble( sqc_bubble_content const &content) ;
};

END_NAMESPACE_SQC_FRAMEWORK
