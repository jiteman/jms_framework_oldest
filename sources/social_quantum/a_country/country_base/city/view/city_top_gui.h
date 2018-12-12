#pragma once

#include "../../view/sqc_scene_view.h"
#include "../../dialogs/controls/sqc_multipart_widget.h"

#include "../../sqc_country_common.h"

NAMESPACE_SQC_FRAMEWORK

//
// sqc_city_top_gui implementation
//
class sqc_city_top_gui : public sqc_multipart_widget {
public:
	enum top_button_t {
    	button_water,
        button_power,
        button_population,
    };
    
	sqc_city_top_gui( milk::milk_widget_ptr p, 
    			sqc_window_factory_ctx_ptr window_ctx);
	virtual ~sqc_city_top_gui();

	virtual void	on_create();
    
    bool is_full_expanded();

protected:
    virtual	void	on_visible_count_change();

protected:
	void			layout_controls();
    void			update_manage_button();
public:
	void			update_counters( const sqc::sqc_common_scene_info& scene_info );
    
protected:
    bool			shift_control_left( milk::milk_widget_ptr p, const int offset );
private:
	void			add_transparent_button( const surf::surf_rect& rc0, 
    										const surf::surf_rect& rc1,
                                            const top_button_t button_type );
	void			on_top_button_pressed( const top_button_t button_type );
    
    enum top_gui_parts {
    	top_gui_part_button,
        top_gui_part_prices,
        top_gui_part_experience,
        top_gui_part_counters,
        top_gui_part_countof,
    };
    
    milk::milk_image_ptr	m_left_arrow_ptr;
    milk::milk_image_ptr	m_right_arrow_ptr;
    
    milk::milk_label_ptr	m_coins_label_ptr;
    milk::milk_label_ptr	m_bucks_label_ptr;
    milk::milk_label_ptr	m_level_label_ptr;
    milk::milk_label_ptr	m_descr_label_ptr;
    
    milk::milk_label_ptr	m_water_label_ptr;
    milk::milk_label_ptr	m_max_water_label_ptr;
    
    milk::milk_label_ptr	m_power_back_ptr;
    milk::milk_label_ptr	m_max_power_back_ptr;
    
    milk::milk_label_ptr	m_population_label_ptr;
    milk::milk_label_ptr	m_max_population_label_ptr;

    milk::milk_progress_bar_ptr m_progress_bar;
    
    milk::milk_image_ptr	m_subpanel_water;
    milk::milk_image_ptr	m_subpanel_power;
    milk::milk_image_ptr	m_subpanel_popul;
};

typedef std::tr1::shared_ptr<sqc_city_top_gui>    sqc_city_top_gui_ptr;


//
// sqc_multipart_widget provider events id
// and notification events id
//
declare_notification_provider_id( top_gui_provider_id )
declare_notification_event_id( top_gui_moved_on )

END_NAMESPACE_SQC_FRAMEWORK
