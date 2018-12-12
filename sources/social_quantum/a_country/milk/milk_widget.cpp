#include "milk_widget.h"
#include "milk_server.h"
#include "animation/animation_transformer.h"

NAMESPACE_MILK


milk_widget::milk_widget( milk_widget_ptr p ) 
    : parent( p )
    , styles( 0 )
    , alpha( 1. )
    , is_runnig(true)
{
}

void milk_widget::on_create() {
    
}

void milk_widget::destroy() {

	// to avoid self destruction at the end of function
    milk_widget_ptr ptr_this( shared_from_this() );
    
    handle_destroy();
    
    milk_widget_list        local_childs = childs;
    childs.clear();
    
    for( milk_widget_list::iterator i = local_childs.begin(); i != local_childs.end(); ++i ) {
        milk_widget_ptr child( *i );
        
        child->destroy();
    }
    
    milk_widget_ptr parent = get_parent();
    if( parent ) {
        parent->remove_child( shared_from_this() );
    }
    
    if (destroy_callback) {
        destroy_callback();
    }
}

void milk_widget::set_destroy_handler(milk_destroy_callback callback) {
    destroy_callback = callback;
}

void milk_widget::on_destroy() {
}

void milk_widget::handle_destroy()
{
    is_runnig = false;
    on_destroy();
}

bool milk_widget::handle_touch( milk_touch_info const &touch, bool bypass_click ) {
	/// if animation active no handle any user activity
	if (m_transformer.lock()) return false;
	
    for( milk_widget_list::reverse_iterator i = childs.rbegin(); i != childs.rend(); ++i ) {
        milk_widget_ptr child( *i );
        
        if( !child->get_rect().point_in_rect( touch.points[0] ) ) {
            continue;
        }

        if (!child->is_visible()) {
            continue;
        }

        //
        // if server has captured window, it need
        //
//        if( server.get_capture() == child ) {
//            return false;
//        }
        
        milk_touch_info   child_touch( touch );
        child_touch.offset_coords( child->get_rect().bottom_left() );
        
        if( child->handle_touch( child_touch, bypass_click ) ) {
            return true;
        }
    }
    if( !bypass_click ) {
        return on_touch( touch );
    }
    else {
        return false;
    }
}

void milk_widget::handle_render( surf_context_ptr ctx ) {
    //PROFILE_ENTRY( "milk_widget::handle_render" );
    bool    clipped = is_clip_children();
    
	sqc::animation::animation_transformer_ptr anim = m_transformer.lock();
	
	if (anim)
		anim->begin_draw( ctx );
	
    if( clipped ) {
        //ctx->set_clip_rect( get_rect() );
        ctx->set_clip_rect( get_client_rect() );
    }
    
    surf_context_state state;
    ctx->store_state( state );
	surf::surf_color clr = ctx->get_color();
    ctx->set_color( surf::surf_color(clr.r,clr.g,clr.b,clr.a*alpha) );
    
    
    if ( !in_child_rect() ) {
        if ( is_visible() ) {
            render( ctx );
        }
    }
			
	ctx->set_color( surf::surf_color(clr.r,clr.g,clr.b,clr.a*alpha) );
    
	surf::surf_transform tr = ctx->get_transform();
    
    {
        //PROFILE_ENTRY( "milk_widget::handle_render:render childs" );
        for( milk_widget_list::iterator i = childs.begin(); i != childs.end(); ++i ) {
            milk_widget_ptr child( *i );
            if( !child->is_visible() || !child->in_parent_rect() ) {
                continue;
            }
            
            ctx->set_transform( tr.translated( child->get_rect().bottom_left() ) );
            child->handle_render( ctx );
        }
    }
    
    ctx->restore_state( state );
	
    if( clipped ) {
        ctx->reset_clip();
    }
	
	if (anim)
		anim->end_draw( ctx );
}

void milk_widget::handle_timer( surf_ddword tick ) {
    
    for( milk_widget_list::iterator i = childs.begin(); i != childs.end(); ++i ) {
        milk_widget_ptr child( *i );
        child->handle_timer( tick );
    }
    
    on_timer( tick );
}

void milk_widget::handle_cancel_mode() {
    for( milk_widget_list::iterator i = childs.begin(); i != childs.end(); ++i ) {
        milk_widget_ptr child( *i );
        child->handle_cancel_mode();
    }
    
    on_cancel_mode();
}


bool milk_widget::on_touch( milk_touch_info const &info ) {
    return false;
}

void milk_widget::on_cancel_mode() {
}

void milk_widget::on_timer( surf_ddword tick ) {
}

void milk_widget::on_show_window( bool show ) {
}

void milk_widget::render( surf_context_ptr ctx ) {
}


void milk_widget::set_rect( surf_rect const &r ) {
    window_rect = r;
}

surf_rect milk_widget::get_rect() const {
    return window_rect;
}

surf_rect milk_widget::get_client_rect() const {
    return surf_rect( window_rect.size() );
}

void milk_widget::set_caption( surf_string const &caption ) {
    window_caption = caption;
}
bool milk_widget::is_running() const
{
    return is_runnig;
}

surf_string milk_widget::get_caption() const {
    return window_caption;
}

milk_widget_ptr milk_widget::get_parent() const {
    return parent.lock();
}

void milk_widget::set_parent( milk_widget_ptr  new_parent ) {
    milk_widget_ptr old_parent = get_parent();
    surf::surf_point offset = get_rect().bottom_left();
    
    if( old_parent ) {
        offset = old_parent->client_to_screen( offset );
        old_parent->remove_child( shared_from_this() );
    }
    
    if( new_parent ) {
        offset = new_parent->screen_to_client( offset );
        new_parent->add_child( shared_from_this(), surf::surf_rect( offset, get_rect().size() ) );
    }    
}

void milk_widget::set_alpha( surf_val a ) {
    alpha = a;
}
surf_val milk_widget::get_alpha() const {
    return alpha;
}


void milk_widget::set_transparent( bool flag ) {
    if( flag )  styles |= widget_style_transparent;
    else        styles &= ~widget_style_transparent;
}

bool milk_widget::is_transparent() const {
    return (styles & widget_style_transparent) == widget_style_transparent;
}

void milk_widget::set_clip_children( bool flag ) {
    if( flag )  styles |= widget_style_clip_children;
    else        styles &= ~widget_style_clip_children;
}

bool milk_widget::is_clip_children() const {
    return (styles & widget_style_clip_children) == widget_style_clip_children;
}

void milk_widget::set_visible( bool flag ) {
    if( is_visible() == flag ) {
        return;
    }
    
    if( !flag ) styles |= widget_style_hidden;
    else        styles &= ~widget_style_hidden;
    
    on_show_window( flag );
    
    invalidate();
}

bool milk_widget::is_visible() const {
    return (styles & widget_style_hidden) != widget_style_hidden;
}

void milk_widget::set_disabled( bool flag ) {
    if( is_disabled() == flag ) {
        return;
    }
    
    if( flag ) styles |= widget_style_disabled;
    else        styles &= ~widget_style_disabled;
    
    on_show_window( flag );
    
    invalidate();
}

bool milk_widget::is_disabled() const {
    return (styles & widget_style_disabled) == widget_style_disabled;
}

bool milk_widget::in_parent_rect() {	
	milk_widget_ptr parent = get_parent();
    
	if (parent) {
		surf_rect parent_rect = parent->get_client_rect();
		surf_rect widget_rect = get_rect();
		
		return parent_rect.is_intercepted(widget_rect);
        
		/*
        return parent_rect.point_in_rect( widget_rect.bottom_left() ) 
			|| parent_rect.point_in_rect( widget_rect.top_right() )
            || parent_rect.point_in_rect( widget_rect.bottom_right() )
			|| parent_rect.point_in_rect( widget_rect.top_left() );
        */
	}
	
    return true;
}

bool milk_widget::in_child_rect() {
	surf_rect widget_rect = get_rect();
	
	for( milk_widget_list::iterator i = childs.begin(); i != childs.end(); ++i ) {
        milk_widget_ptr child( *i );
		
		if ( child->is_transparent() ) {
			continue;
		}
		
		surf_rect child_rect = child->get_client_rect();
     
		bool is_overlap = child_rect.point_in_rect( widget_rect.bottom_left() ) 
		&& child_rect.point_in_rect( widget_rect.top_right() )
		&& child_rect.point_in_rect( widget_rect.bottom_right() )
		&& child_rect.point_in_rect( widget_rect.top_left() );
		
		if ( is_overlap ) 
			return is_overlap;
	}
	
    return false;
}

void milk_widget::invalidate() {
    get_server().redraw();
}

sqc::animation::animation_transformer_ptr milk_widget::transform() {
	sqc::animation::animation_transformer_ptr ptr = m_transformer.lock();
	if (ptr) return ptr;
	ptr = sqc::animation::animation_transformer_ptr( new sqc::animation::animation_transformer() );
	m_transformer = ptr;
	return ptr;
}

milk_window_server  &milk_widget::get_server() const {
    return get_parent()->get_server();
}

surf_graphics_server &milk_widget::get_graphics() {
    return get_server().get_graphics();
}

void milk_widget::add_child( milk_widget_ptr child, surf_rect const &r ) {
    childs.push_back( child );
    child->set_rect( r );
    child->set_font( get_font() );
    child->on_create();
    
    invalidate();
    
}

void    milk_widget::add_child_at_index( milk_widget_ptr child, surf_rect const &rect , size_t index) {
    if (index>childs.size())
        index = childs.size();
    milk_widget_list::iterator it = childs.begin();
    for (size_t i=0;i<index;i++) it++;
	childs.insert( it , child );
	child->set_rect( rect );
    child->set_font( get_font() );
    child->on_create();
    invalidate();
}

void milk_widget::remove_child( milk_widget_ptr child ) {
    for( milk_widget_list::iterator i = childs.begin(); i != childs.end(); ++i ) {
        if( *i == child ) {
            childs.erase( i );
            invalidate();
            return;
        }
    }
}

void milk_widget::set_font( surf_font_ptr f ) {
    font = f;
}

surf_font_ptr milk_widget::get_font() const {
    return font;
}

surf_point milk_widget::screen_to_client( surf_point const &point ) {
    surf_point  result = point;
    
    milk_widget_ptr parent = get_parent();
    if( parent ) {
        result = parent->screen_to_client( result );
    }
    
    result -= get_rect().bottom_left();
    return result;
}

surf_point milk_widget::client_to_screen( surf_point const &point ) {
    surf_point  result = point;
    
    milk_widget_ptr parent = get_parent();
    if( parent ) {
        result = parent->client_to_screen( result );
    }
    
    result += get_rect().bottom_left();
    return result;
}


//
//
//

milk_desktop::milk_desktop( milk_window_server &s ) 
    : milk_widget( milk_widget_ptr() ) 
    , server( s )
{
    milk_metrics const &metrics = get_server().get_theme().get_metrics();
    surf_font_ptr   default_font = get_graphics().create_font( metrics.default_font_size, metrics.default_font_name.c_str() );
    set_font( default_font );
}

void milk_desktop::render( surf_context_ptr ctx ) {
    ctx->clear();
    milk_widget::render(ctx);
}

milk_window_server  &milk_desktop::get_server() const {
    return server;
}


END_NAMESPACE_MILK