#ifndef __MILK_SPINBOARD_H_INCLUDED__
#define __MILK_SPINBOARD_H_INCLUDED__

#include "milk_scroll_area.h"

NAMESPACE_MILK



class milk_spinboard_callbacks {
public:
    virtual milk_widget_ptr create_cell( int idx, surf_rect const &rect ) = 0;
    virtual int get_cell_count() = 0;
};

//typedef std::tr1::shared_ptr<milk_spinboard_callbacks>	milk_spinboard_callbacks_ptr;
typedef milk_spinboard_callbacks* milk_spinboard_callbacks_ptr;
typedef std::vector<milk_widget_ptr> milk_spinboard_cells;

class milk_spinboard : public milk_scroll_area {

public:
    milk_spinboard( milk_widget_ptr p, milk_spinboard_callbacks_ptr cb , milk_spinboard_theme_flags flags = 0);
    virtual void render( surf_context_ptr ctx );
    virtual void handle_render( surf::surf_context_ptr ctx );
    
    virtual void on_create();
	virtual void on_destroy();
    virtual void on_scroll_complete();
    
    void    set_rows_count(int rc);
    void    set_visible_count( int ic );
    void    set_item_spacing( int cx );
    surf_size calc_size( surf_size const &cell_size );
    
    int     get_pages_count();
    int     get_active_page();
    void    set_active_page( int page, bool animated );
    
    milk_spinboard_cells get_cells();
    
	void	set_left_fade( int size );
	void	set_right_fade( int size );
	
	void set_on_page_change( const std::tr1::function<void(int)>& callback );
	const std::tr1::function<void(int)>& get_on_page_change() const { return m_on_page_change;}
	void set_on_pages_count_change( const std::tr1::function<void(int)>& callback );
	const std::tr1::function<void(int)>& get_on_pages_count_change() const { return m_on_pages_count_change;}
protected:    
    void    update_layout();
    surf_rect  get_item_rect( int n );
    
    surf_size   cell_size;
    
    int     rows_count;
    int     visible_count;
    int     pages_count, selected_page;
    int     cx_item_spacing, cx_scroll_distance;
    milk_spinboard_callbacks_ptr   callbacks;
    
    milk_spinboard_cells   cells;
	surf::surf_rendertarget_ptr	m_rendertaget;
	int	m_left_fade;
	int	m_right_fade;
	milk_spinboard_theme_flags	  m_theme_flags;
	std::tr1::function<void(int)> m_on_page_change;
	std::tr1::function<void(int)> m_on_pages_count_change;
};

typedef std::tr1::shared_ptr<milk_spinboard>   milk_spinboard_ptr;


/// pager

class milk_spinboard_pager : public milk::milk_scroll_area {
public:
	milk_spinboard_pager( milk::milk_widget_ptr p );
	/// @{ configure view
	/// set normal image
	void set_normal_image( const surf::surf_image_ptr& img );
	/// set active image
	void set_active_image( const surf::surf_image_ptr& img );
	/// set items step
	void set_step( surf::surf_val step );
	/// set visibility if only one page presented
	void set_one_page_visible( bool v );
	/// @}
	/// handle touches
	virtual bool on_touch( milk::milk_touch_info const &touch );
	/// set pages count
	void set_pages( int pages );
	/// set active page
	void set_active_page( int page );
	/// set on select callback
	void set_on_select( const std::tr1::function<void(int)>& fun );
	/// auto bind to spinboard
	void bind( const milk_spinboard_ptr& spinboard );
	
	/// @{ milk_widget owerride
	/// render control
	void render( surf::surf_context_ptr ctx );
	/// on create initialization
	void on_create();
	/// on destroy deinitialization
	void on_destroy();
	/// @}
private:
	class pager_button  {
	public:
		pager_button( )  : m_pressed(false),m_active(false){
		}
		void render( surf::surf_context_ptr ctx , const surf::surf_point& pos, 
					surf::surf_val left_hide, 
					surf::surf_val right_hide,
					const surf::surf_image_ptr& normal_image,
					const surf::surf_image_ptr& pressed_image);
		void set_active( bool active ) {
			m_active = active;
		}
		void set_pressed( bool pressed ) {
			m_pressed = pressed;
		}
		bool on_release() {
			bool res = m_pressed;
			m_pressed = false;
			return res;
		}
	private:
		bool	m_active;
		bool	m_pressed;
	};
private:
	surf::surf_val		m_step;
	std::vector<pager_button> m_buttons;
	surf::surf_image_ptr	m_normal_image;
	surf::surf_image_ptr	m_pressed_image;
	std::tr1::function<void(int)> m_on_select;
	bool	m_one_visible;
public:
	
};

typedef std::tr1::shared_ptr<milk_spinboard_pager>   milk_spinboard_pager_ptr;

END_NAMESPACE_MILK

#endif //#ifndef __MILK_SPINBOARD_H_INCLUDED__