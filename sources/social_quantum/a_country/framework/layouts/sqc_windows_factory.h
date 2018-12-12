#pragma once

#include "../sqc_framework_defs.h"
#include "sqc_layout_defs.h"
#include "sqc_common_resources.h"

NAMESPACE_SQC_FRAMEWORK

class sqc_window_factory;
//
// sqc_window_factory_context implementation (cache images, etc)
//
class sqc_window_factory_ctx {
    friend class sqc_window_factory;
public:
	sqc_window_factory_ctx( surf::surf_graphics_server& graphics );
    virtual ~sqc_window_factory_ctx();

public:
    // create or reuse image
    surf::surf_image_ptr    create_image( const sqc_string& image_path );
    // create or reuse font
    surf::surf_font_ptr     create_font( surf::surf_val face_size, 
                                        const sqc_string&  face_name );
    
private:
    class font_cache {
    public:
        font_cache( surf::surf_val face_size,
                   const sqc_string&  face_name ) 
            : m_face_size( face_size )
            , m_face_name( face_name ) {
        }
        
        struct cmp {
            bool operator()( const font_cache& x0, const font_cache& x1 ) const { 
                if ( x0.m_face_size != x1.m_face_size ) {
                    return x0.m_face_size < x1.m_face_size;
                }
                return x0.m_face_name < x1.m_face_name;
            }
        };
    protected:
        sqc_string      m_face_name;
        surf::surf_val  m_face_size;
    };
    
    typedef std::map<sqc_string,surf::surf_image_ptr>   map_image;
    typedef std::map<font_cache,surf::surf_font_ptr,font_cache::cmp>    map_font;
    
    map_image                   m_images;
    map_font                    m_fonts;
    
    surf::surf_graphics_server&	m_graphics;
    
    int m_stat_image_calls, m_stat_image_cached;
    int m_stat_font_calls, m_stat_font_cached;
};

typedef std::tr1::shared_ptr<sqc_window_factory_ctx>	sqc_window_factory_ctx_ptr;
    

//
// sqc_window factory implementation
//
class sqc_window_factory {
public:
	sqc_window_factory( surf::surf_graphics_server& graphics ) 
		: m_graphics( graphics )
        , m_theme( sqc_theme_small ) {
	}
	virtual ~sqc_window_factory() {
	}
	
    // init factory
    void init_factory( int cx, int cy );
    
	// return current theme size
	sqc_theme_size get_theme_size() const;
    
    // create window context
    sqc_window_factory_ctx_ptr  create_window_ctx();
	
	// create label by layout
	milk::milk_label_ptr	create_label( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                          milk::milk_widget_ptr parent, 
										  const label_layout& layout );
	// create image by layout
	milk::milk_image_ptr	create_image( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                          milk::milk_widget_ptr parent, 
										  const image_layout& layout );
    
    // create slice image by layout
	milk::milk_slice_image_ptr	create_slice_image( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                          milk::milk_widget_ptr parent, 
										  const slice_image_layout& layout );
	// create background by layout
	milk::milk_image_ptr	create_background( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                               milk::milk_widget_ptr parent, 
										       const dialog_backgrounds& layout );

	// create button by layout
	milk::milk_image_button_ptr	create_button( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                               milk::milk_widget_ptr parent,
										       const image_button_layout& layout );
    
	// create deactivable button by layout
	milk::milk_image_button_ptr create_deactivable_button( sqc_window_factory_ctx_ptr &ptr_wnd_ctx,
                                                          milk::milk_widget_ptr parent,
                                                          const deactivable_image_button_layout &layout );

	// create Theme Button
    milk::milk_theme_button_ptr create_theme_button( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
													 milk::milk_widget_ptr parent, 
													 const theme_button_layout& layout );
	// create Theme Button by layout
	milk::milk_theme_button_ptr	create_button( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
											  milk::milk_widget_ptr parent,
											  const theme_button_layout& layout ) { return create_theme_button(ptr_wnd_ctx,parent,layout); }

	// create switch
	milk::milk_switch_button_ptr create_switch_button( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                                       milk::milk_widget_ptr parent,
											           const switch_button_layout& layout );
    
	/// create bevel
	milk::milk_bevel_ptr	create_bevel( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
										 milk::milk_widget_ptr parent,
										 const base_bevel_layout& layout );
	
	milk::milk_separator_ptr	create_separator( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
												   milk::milk_widget_ptr parent,
												   const vertical_separator_layout& layout );
	milk::milk_separator_ptr	create_separator( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
												   milk::milk_widget_ptr parent,
												   const horizontal_separator_layout& layout );
	
    // layout widget
    void    layout_widget( const milk::milk_widget_ptr parent,
                          milk::milk_widget_ptr widget,
                          const layout_alignment& alignment,
                          const layout_rects& rects );

    milk::milk_progress_bar_ptr create_progress_bar( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                                 milk::milk_widget_ptr parent,
                                                 const slice_image_layout& layout );
                          
    // create spinboard
    template <class T>
    milk::milk_spinboard_ptr create_spinboard( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                               milk::milk_widget_ptr parent,
                                               const spinboard_layout& layout,
                                               T callbacks ) {
        // take current theme size
        sqc_theme_size theme_size = get_theme_size();
        
        // align rect by parent
        surf::surf_rect rc = layout_child_rect( parent, 
                                         layout.rects().at( theme_size ), 
                                         layout.alignment().mask() );
        
        milk::milk_spinboard_ptr spinboard = 
        parent->create_child<milk::milk_spinboard>( rc, callbacks ,layout.flags().at( theme_size ));
        
        return spinboard;
	}
	/// create spinboard pager
	milk::milk_spinboard_pager_ptr create_spinboard_pager( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
														  const milk::milk_widget_ptr& parent,
														  const milk::milk_spinboard_ptr& soinboard,
														  const spinboard_pager_layout& layout );
        
public:
    template <class T>
    std::tr1::shared_ptr<T> create_child( sqc_window_factory_ctx_ptr& ptr_wnd_ctx,
                                         const milk::milk_widget_ptr parent, 
                                         const layout_rects& rects,
                                         const layout_alignment aligment ) {
        // take current theme size
        sqc_theme_size theme_size = get_theme_size();
        
        // align rect by parent
        surf::surf_rect rc = layout_child_rect( parent, 
                                         rects.at( theme_size ),
                                         aligment );
        
        std::tr1::shared_ptr<T> child =
		parent->create_child<T>( rc );
        
        return child;
    }
    // layout position
	surf::surf_point layout_position( const milk::milk_widget_ptr parent, 
									  const surf::surf_point& pos,
									  const layout_alignment alignment ) const;
	surf::surf_point layout_position( const surf::surf_rect& parent, 
									 const surf::surf_point& pos,
									 const layout_alignment alignment ) const;
	// layout child rect
	surf::surf_rect layout_child_rect( const milk::milk_widget_ptr parent, 
								const surf::surf_rect& child_rect,
								const layout_alignment alignment ) const;
	// layout child rects
	surf::surf_rect layout_child_rects( const milk::milk_widget_ptr parent, 
								const layout_rects& child_rects,
								const layout_alignment alignment ) const;

protected:
	surf::surf_graphics_server&	m_graphics;
    sqc_theme_size              m_theme;
};

END_NAMESPACE_SQC_FRAMEWORK
