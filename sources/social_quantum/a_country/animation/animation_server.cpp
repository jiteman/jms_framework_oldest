#include "animation_server.h"
#include "animation_animators.h"

#include "../sstl/sstl_profiler.h"

NAMESPACE_ANIMATION

animation_server::animation_server() {
	m_last_time = 0;
}

animation_server::~animation_server() {
}

bool animation_server::handle_timer( sqc_ddword ticks ) {
	sqc_ddword delta = ticks - m_last_time;
	m_last_time = ticks;
	surf::surf_val dt = 0.001 * delta;
	/// too slow
	if (dt>(1.0/10))
		dt = 1.0/10;
	return process( dt );
}

animation_server::animtor_entry::~animtor_entry() {
}

bool animation_server::process( surf::surf_val dt ) {
	if (m_animators.empty() && m_added_animators.empty())
		return false;
	for (size_t i=0;i<m_added_animators.size();i++) {
		m_animators.push_back(m_added_animators[i]);
	}
	m_added_animators.clear();
	animators_list::iterator it = m_animators.begin();
	while (it!=m_animators.end()) {
		if (it->complete) {
			it = m_animators.erase(it);
		} else {
			if (!it->started) {
				if (it->animator->start(*(it->transformer.get()))) {
					it = m_animators.erase(it);
					continue;
				}
				it->started = true;
			}
			if (it->animator->update(*(it->transformer.get()),dt )) {
				it->animator->on_complete(*(it->transformer.get()));
				it->complete = true;
				it = m_animators.erase(it);
			} else {
				it++;
			}
		}
	}
	return true;
}

void animation_server::on_animator_added() {
	if (m_added_animators.empty()) return;
	if (!m_added_animators.back().started) {
		if (m_added_animators.back().animator->start((*m_added_animators.back().transformer.get())))
			m_added_animators.pop_back();
		else
			m_added_animators.back().started = true;
	}
}

END_NAMESPACE_ANIMATION