#include "animation_animators.h"
#include "animation_transformer.h"

NAMESPACE_ANIMATION


animation_animator_time::animation_animator_time(transform_function func,surf::surf_val time) : m_transform_function(func),m_time(0),m_all_time(time) {
}

bool animation_animator_time::start(animation_transformer& transform ) {
	m_time = 0;
	set_value( transform, m_transform_function(0)  );
	return false;
}

bool animation_animator_time::update( animation_transformer& transform, surf::surf_val dt ) {
	m_time+=dt;
	if (m_time>=m_all_time) {
		set_value( transform, m_transform_function( 1.0)  );
		return true;
	}
	set_value( transform,m_transform_function( m_time / m_all_time ) );
	return false;
}



void animation_animator_translate::set_value( animation_transformer& transform, surf::surf_val v ) {
	transform.set_translate( get(v) );
}
void animation_animator_translate::set_from( animation_transformer& transform ) {
	set_begin(transform.translate());
}


void animation_animator_scale::set_value( animation_transformer& transform, surf::surf_val v ) {
	transform.set_scale( get(v) );
}
void animation_animator_scale::set_from( animation_transformer& transform ) {
	set_begin((transform.scale().x+transform.scale().y)/2);
}

void animation_animator_alpha::set_value( animation_transformer& transform, surf::surf_val v ) {
	transform.set_alpha( get(v) );
}
void animation_animator_alpha::set_from( animation_transformer& transform ) {
	set_begin(transform.color().a);
}

void animation_animator_color::set_value( animation_transformer& transform, surf::surf_val v ) {
	transform.set_color( get(v) );
}
void animation_animator_color::set_from( animation_transformer& transform ) {
	set_begin(transform.color());
}

END_NAMESPACE_ANIMATION
