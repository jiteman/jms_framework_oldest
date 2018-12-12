#pragma once

#include "../framework/sqc_framework_defs.h"
#include "../sqc/sqc_base.h"
#include "sqc_country_common.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_object_selection : public sqc_noncopyable {

public:
	sqc_object_selection(const char* pattern_name,size_t iterations,int iteration_delta);
	~sqc_object_selection();
	
	void set_object( sqc_game_object_ptr object , sqc_game_object_selection_type type);
	const sqc_game_object_ptr& get_object() const {
		return m_object;
	}
    sqc_game_object_selection_type get_selection_type() const { return m_selection_type;}

	void render( surf::surf_context_ptr ctx, sqc_coord_convertor &coord_conv , const sqc_game_object_draw_args& draw_args);
	bool need_redraw() const;

protected:
	void process_draw(surf::surf_context_ptr ctx);

private:
	const char*	m_pattern_name;
	size_t	m_max_iterations;
	int	m_iteration_delta;
	sqc_game_object_ptr m_object;
    sqc_game_object_selection_type   m_selection_type;
	struct implementation;
	implementation* m_impl;
	void calculate_size(sqc_coord_convertor &coord_conv);
	bool create_targets();
	int get_space() const { return m_iteration_delta * m_max_iterations;}
    
    surf::surf_color    m_normal_selection_color;
    surf::surf_color    m_invalid_selection_color;
};

typedef std::tr1::shared_ptr<sqc_object_selection>  sqc_object_selection_ptr;

END_NAMESPACE_SQC_FRAMEWORK
