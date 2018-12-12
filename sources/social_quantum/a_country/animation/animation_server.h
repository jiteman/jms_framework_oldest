#pragma once

#include "animation_defs.h"
#include "../surf/surf_defs.h"
#include <vector>

NAMESPACE_ANIMATION

class animation_transformer;
typedef std::tr1::shared_ptr<animation_transformer>	animation_transformer_ptr;
class animation_animator_base;
typedef std::tr1::shared_ptr<animation_animator_base>	animation_animator_base_ptr;

class animation_server {
public:
	animation_server();
	~animation_server();
	
	bool handle_timer( sqc_ddword ticks );
	
	template <class Animator> void add_animator( const animation_transformer_ptr& transformer, const Animator& a ) {
		m_added_animators.push_back( animtor_entry(transformer,animation_animator_base_ptr(new Animator(a)) ));
		on_animator_added();
	}
private:
	sqc_ddword	m_last_time;
	bool process( surf::surf_val dt );
	class animtor_entry {
	public:
		bool	started;
		bool	complete;
		animation_transformer_ptr	transformer;
		animation_animator_base_ptr	animator;
		animtor_entry( const animation_transformer_ptr& tr, const animation_animator_base_ptr& anim) 
			: started(false),complete(false),transformer(tr),animator(anim) {
		}
		~animtor_entry();
	};
	typedef std::vector<animtor_entry> animators_list;
	animators_list	m_animators;
	animators_list	m_added_animators;
	void on_animator_added();
};

END_NAMESPACE_ANIMATION
