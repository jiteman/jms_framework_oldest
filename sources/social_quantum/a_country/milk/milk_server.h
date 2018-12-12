#ifndef __MILK_SERVER_H_INCLUDED
#define __MILK_SERVER_H_INCLUDED

#include "milk_defs.h"

namespace sqc {
	namespace animation {
		class animation_server;
	}
}

NAMESPACE_MILK

class milk_desktop;
class milk_theme;
typedef std::tr1::shared_ptr<milk_desktop> milk_desktop_ptr;


class milk_dialog;
typedef std::tr1::shared_ptr<milk_dialog>    milk_dialog_ptr;
typedef std::list<milk_dialog_ptr> dialogs_list;

//
// milk_window_server implementation
//
class milk_window_server {
public:
    milk_window_server( surf_graphics_server &s, milk_theme &t );
    ~milk_window_server();
	
    // 2nd stage initialization (shit)
    void init_desktop();

    
    void render();
    void handle_timer( surf_ddword ticks );
    bool handle_touch( milk_touch_info const &touch );
    void set_device_info( milk_device_info const &info );
    
    //
    //
    //
    void redraw();
    bool    need_render() const;
    milk_desktop_ptr        get_desktop();
    milk_theme              &get_theme();
    surf_graphics_server    &get_graphics();
    surf_ddword             get_tick_count();
    
    void    set_capture( milk_widget_ptr ptr );
    void    release_capture( milk_widget_ptr ptr );
	
	void	activate_modal( milk_dialog_ptr ptr );
	void	deactivate_modal( milk_dialog_ptr ptr );

    void	close_modals( milk_dialog_ptr ptr_first );
    
    bool    get_bypass_current_click() const;

	// animation
	sqc::animation::animation_server& animation() { return *m_animation_server;}
private:
    bool                        need_redraw;
    bool                        bypass_current_click;
    milk_desktop_ptr            desktop;
    milk_widget_ptr             capture_widget;
    milk_device_info            device_info;
    milk_theme                  &theme;
    surf_graphics_server         &graphics;
    surf_ddword                 tick_count;
	
	dialogs_list				modal_dialogs;
	
	// noncopyable
	milk_window_server( const milk_window_server& );
	milk_window_server& operator = (const milk_window_server& ); 
	
	// animation
	sqc::animation::animation_server*	m_animation_server;
};

typedef std::tr1::shared_ptr<milk_window_server>    milk_window_server_ptr;

END_NAMESPACE_MILK

#endif //__MILK_SERVER_H_INCLUDED
