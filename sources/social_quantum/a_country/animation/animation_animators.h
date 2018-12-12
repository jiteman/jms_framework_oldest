#pragma once

#include "animation_defs.h"
#include "../surf/surf_defs.h"

NAMESPACE_ANIMATION

class animation_transformer;

/// base animator ( interface)
class animation_animator_base {
private:
public:
	/// start animator
	virtual bool start( animation_transformer& transform ) {return true;}
	/// update animator 
	/**
	 * @arg dt delta time, secs
	 * @result tue if animator complete
	 */
	virtual bool update( animation_transformer& transform, surf::surf_val dt ) { (void)dt; return true;}
	/// on animator complete
	virtual void on_complete(animation_transformer& transform) { }
};
typedef std::tr1::shared_ptr<animation_animator_base>	animation_animator_base_ptr;

struct transform_functions {
	static surf::surf_val linear( surf::surf_val v ) { return v;}
};
typedef surf::surf_val (*transform_function)(surf::surf_val);

class animation_animator_time : public animation_animator_base {
public:
	explicit animation_animator_time(transform_function func,surf::surf_val time=1.0);
	 
	bool start(animation_transformer& transform);
	bool update( animation_transformer& transform, surf::surf_val dt);
	/// set transform time
	void set_time( surf::surf_val t ) { m_all_time = t; }
protected:
	/// set inertpolated value ( v(0->1) )
	virtual void set_value( animation_transformer& transform, surf::surf_val v ) {}
private:
	/// transform function ( 0->1 )->( 0->1 )
	transform_function	m_transform_function;
	surf::surf_val	m_time;
	surf::surf_val	m_all_time;
};

template <class T>
class animation_animator_value : public animation_animator_time {
protected:
	explicit animation_animator_value(transform_function func,surf::surf_val time) : animation_animator_time(func,time) {
	}
	typedef T	value_type;
	T get( surf::surf_val k ) const { return m_begin * (1.0-k) + m_end * k; }
	void set_begin( const T& p ) { m_begin = p;}
	void set_end(  const T& p ) { m_end = p;}
	virtual void set_from( animation_transformer& transform ) {}
	virtual void set_relative( animation_transformer& transform, const T& v ) {
		set_from(transform);
		m_end = m_begin + v;
	}
private:
	T	m_begin;
	T	m_end;
};

class animation_animator_translate : public animation_animator_value<surf::surf_point> {
public:
	animation_animator_translate( const surf::surf_point& from, const surf::surf_point& to,
								 surf::surf_val time=1.0, transform_function func=&transform_functions::linear) : parent_class(func,time) {
		set_begin(from);
		set_end(to);
	}
protected:
	typedef animation_animator_value<surf::surf_point> parent_class;
	explicit animation_animator_translate(transform_function func,surf::surf_val time) : parent_class(func,time) {
	}
	void set_value( animation_transformer& transform, surf::surf_val v ); 
	void set_from( animation_transformer& transform );
};
class animation_animator_scale : public animation_animator_value<surf::surf_val> {
public:
	animation_animator_scale( surf::surf_val from, surf::surf_val to,surf::surf_val time=1.0, transform_function func=&transform_functions::linear) : parent_class(func,time) {
		set_begin(from);
		set_end(to);
	}
protected:
	explicit animation_animator_scale(transform_function func,surf::surf_val time) : parent_class(func,time) {
	}
	typedef animation_animator_value<surf::surf_val> parent_class;
	void set_value( animation_transformer& transform, surf::surf_val v ); 
	void set_from( animation_transformer& transform );
};
class animation_animator_alpha : public animation_animator_value<surf::surf_val> {
public:
	animation_animator_alpha( surf::surf_val from, surf::surf_val to,surf::surf_val time=1.0, transform_function func=&transform_functions::linear) : parent_class(func,time) {
		set_begin(from);
		set_end(to);
	}
protected:
	explicit animation_animator_alpha(transform_function func,surf::surf_val time) : parent_class(func,time) {
	}
	typedef animation_animator_value<surf::surf_val> parent_class;
	void set_value( animation_transformer& transform, surf::surf_val v ); 
	void set_from( animation_transformer& transform );
};
class animation_animator_color : public animation_animator_value<surf::surf_color> {
protected:
	explicit animation_animator_color(transform_function func,surf::surf_val time) : parent_class(func,time) {
	}
	typedef animation_animator_value<surf::surf_color> parent_class;
	void set_value( animation_transformer& transform, surf::surf_val v ); 
	void set_from( animation_transformer& transform );
};

template <class T>
class animation_animator_relative : public T {
public:
	typedef typename T::value_type value_type;
	typedef T parent_class;
	explicit animation_animator_relative(const value_type& o,surf::surf_val time=1.0,transform_function func=&transform_functions::linear) : parent_class(func,time) {
		set_offset(o);
	}
	void set_offset( const value_type& o ) { m_offset = o;}
	bool start( animation_transformer& transform ) { 
		this->set_relative( transform, m_offset );
		return parent_class::start( transform );
	}
protected:
	value_type	m_offset;
};
typedef animation_animator_relative<animation_animator_translate> animation_animator_translate_relative;
typedef animation_animator_relative<animation_animator_scale> animation_animator_scale_relative;
typedef animation_animator_relative<animation_animator_alpha> animation_animator_alpha_relative;
typedef animation_animator_relative<animation_animator_color> animation_animator_color_relative;

template <class T>
class animation_animator_from_current : public T {
public:
	typedef typename T::value_type value_type;
	typedef T parent_class;
	explicit animation_animator_from_current(const value_type& to,surf::surf_val time=1.0,transform_function func=&transform_functions::linear) : parent_class(func,time) {
		this->set_end(to);
	}
	bool start( animation_transformer& transform ) { 
		this->set_from( transform  );
		return parent_class::start( transform );
	}
protected:
	value_type	m_offset;
};
typedef animation_animator_from_current<animation_animator_translate> animation_animator_translate_from_current;
typedef animation_animator_from_current<animation_animator_scale> animation_animator_scale_from_current;
typedef animation_animator_from_current<animation_animator_alpha> animation_animator_alpha_from_current;
typedef animation_animator_from_current<animation_animator_color> animation_animator_color_from_current;

class animation_animator_event : public animation_animator_base {
public:
	explicit animation_animator_event( const std::tr1::function<void()>& func) : m_func(func) {
	}
	bool start(animation_transformer& transform) {
		if (m_func) m_func();
		return true;
	}
private:
	std::tr1::function<void()> m_func;
};

class animation_animator_sequency : public animation_animator_base {
public:
	animation_animator_sequency() : m_index(0) {
	}
	template <class Animator>
	animation_animator_sequency& add( const Animator& animator ) {
		m_childs.push_back( animation_animator_base_ptr( new Animator(animator) ));
		return *this;
	}
	bool start(animation_transformer& transform) {
		m_index = 0;
		if (m_index<m_childs.size()) {
			m_childs[m_index]->start( transform );
		}
		return m_childs.empty();
	}
	bool update( animation_transformer& transform, surf::surf_val dt) {
		if (m_index<m_childs.size()) {
			if (m_childs[m_index]->update( transform,dt )) {
				m_childs[m_index]->on_complete( transform );
				m_index++;
				if (m_index<m_childs.size()) {
					if (m_childs[m_index]->start( transform ))
						return true;
				} else {
					return true;
				}
			}
			return false;
		}
		return true;
	}
private:
	std::vector<animation_animator_base_ptr> m_childs;
	size_t	m_index;
};

class animation_animator_group : public animation_animator_base {
public:
	animation_animator_group()  {
	}
	template <class Animator>
	animation_animator_group& add( const Animator& animator ) {
		m_childs.push_back( animation_animator_base_ptr( new Animator(animator) ));
		return *this;
	}
	bool start(animation_transformer& transform) {
		/// @todo
		for (size_t i=0;i<m_childs.size();i++) {
			m_childs[i]->start( transform );
		}
		return m_childs.empty();
	}
	bool update( animation_transformer& transform, surf::surf_val dt) {
		std::vector<animation_animator_base_ptr>::iterator it = m_childs.begin();
		while (it!=m_childs.end()) {
			if ((*it)->update( transform,dt )) {
				(*it)->on_complete( transform );
				it = m_childs.erase( it );
			} else {
				it++;
			}
		}
		return m_childs.empty();
	}
private:
	std::vector<animation_animator_base_ptr> m_childs;
};

class animation_animator_pause : public animation_animator_base {
public:
	explicit animation_animator_pause( surf::surf_val time ) : m_timeout( time ) {
		m_time = 0;
	}
	bool start(animation_transformer& ) {
		m_time = 0;
		return false;
	}
	bool update( animation_transformer& , surf::surf_val dt) {
		m_time+=dt;
		return m_time>=m_timeout;
	}
private:
	surf::surf_val	m_timeout;
	surf::surf_val	m_time;
};

template <class T>
inline T animation_keyframe_func( const T* values , size_t amount , surf::surf_val k ) {
	if (k<=0.) return values[0];
	if (k>=1.) return values[amount-1];
	size_t pos = size_t( k * surf::surf_val( amount-1 ) + 1 );
	if (pos>=amount) return values[amount-1];
	if (pos>0) {
		surf::surf_val sk = (k-(pos-1)*(1.0/surf::surf_val( amount-1 )));
		sk *= surf::surf_val( amount-1 );
		return values[pos-1]*(1.0-sk) + values[pos]*sk;
	}
	return values[pos];
}

END_NAMESPACE_ANIMATION
