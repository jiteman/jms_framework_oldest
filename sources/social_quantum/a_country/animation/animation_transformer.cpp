/*
 *  animation_transformer.cpp
 *  aCountry
 *
 *  Created by Andrey Kunitsyn on 9/27/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "animation_transformer.h"

NAMESPACE_ANIMATION


animation_transformer::animation_transformer() : m_scale(1,1),m_color(1,1,1,1),m_in_draw(false) {
}


void animation_transformer::begin_draw( const surf::surf_context_ptr& ctx ) {
	assert( !m_in_draw );
	m_state.transform = ctx->get_transform();
	m_state.color = ctx->get_color();
	ctx->set_color( m_state.color * color() );
	surf::surf_transform tr = m_state.transform;
	ctx->set_transform( tr.translate( translate()+m_anchor ).scale( scale() ).translate( m_anchor*-1) );
	m_in_draw = true;
}

void animation_transformer::end_draw( const surf::surf_context_ptr& ctx ) {
	assert( m_in_draw );
	ctx->set_transform( m_state.transform );
	ctx->set_color( m_state.color );
	m_in_draw = false;
}

END_NAMESPACE_ANIMATION