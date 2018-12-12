#pragma once

#include "../framework/sqc_framework_defs.h"
#include "../framework/http_service/sqc_http_service.h"

NAMESPACE_SQC_FRAMEWORK

enum sqc_load_texture_priority {
    
    /*
     * UI elements, window backgrounds - NO WAIT!
     */
    load_priority_now,
    
    /*
     * Object textures - load ASAP
     */
    load_priority_normal,
    
    /*
     * Object animations etc - may be delayed
     */
    load_priority_idle,
        
};

struct sqc_downloader_init {
    
    /*
     * HTTP downloader
     */
    sqc_http_service *http;
    
    /*
     * Path to download files.
     */
    sqc_string      download_path;
    
    /*
     * remote URL
     */
    sqc_string      download_url;
    
    /*
     * The maximum size of downloading threads
     */
    sqc_dword   max_download_queue_size;
};

typedef std::tr1::function<void ( sqc_string const &, bool )>  sqc_downloader_callback;
typedef std::tr1::function<bool ( sqc_string const & )>  sqc_check_texture_actuality_callback;

struct download_texture_info {
    download_texture_info() : 
                          revision(0)
                        , priority(load_priority_normal)
                        , is_animation(false)
                        , is_png4(false)
                        , is_plist(false) {}
    
    sqc_string name;
    sqc_string url;
    sqc_string extension;
    int revision;
    sqc_load_texture_priority priority;
    bool is_animation;
    bool is_png4;
    bool is_plist;
};

class sqc_downloader {
public:
    sqc_downloader();   
    /*
     * Initialize the texture downloader component
     */
    void init( sqc_downloader_init &init );
    
    /*
     * Download the given file.
     *   name: file to download
     *   revision: file version. The cached version is imediately returned if version matches the cached one
     */
    void download(
                  download_texture_info &info, 
                  sqc_downloader_callback cb, 
                  sqc_check_texture_actuality_callback acb = sqc_check_texture_actuality_callback());
    
    /*
     * Should be called on idle.
     * The cache revision will be stored, if something is changed.
     */
    void on_idle();
    
    void set_download_url(sqc_string url);
    sqc_string get_texture_cache_path();
protected:
    typedef std::map<sqc_string, download_texture_info> sqc_download_texture_map;
    
    bool is_animation_downloaded(download_texture_info &info);
    
    void read_revisions();
    void store_revistions();
    
    void start_download();
    void download_textures(sqc_download_texture_map &textures, bool check_actuality = true);
    void download_texture(download_texture_info info, bool check_actuality = true);
    void on_http_complete(download_texture_info info, sqc_net_path url, sqc_net_data const &raw);
    void on_http_error(download_texture_info info, sqc_net_path url, sqc_net_error const &error);    
private:
    sqc_downloader_init config;
    
    sqc_string  path_to_revision;
    
    typedef std::map<sqc_string, int>   sqc_revision_map;
    sqc_revision_map    m_revisions;
    
    sqc_downloader_callback m_calback;
    sqc_check_texture_actuality_callback m_actuality_callback;
    
    sqc_download_texture_map m_now_queue;
    sqc_download_texture_map m_normal_queue;
    sqc_download_texture_map m_idle_queue;
    sqc_download_texture_map m_not_actual_queue;
    
    int m_texture_requests;
    bool m_need_save_revision;
};

typedef std::tr1::shared_ptr<sqc_downloader>   sqc_downloader_ptr;

class sqc_texture_proxy;
class sqc_texture_entry;

struct sqc_tile_info {
    sqc_size    tile_size;
    int         tile_rows;
    int         tile_cols;
};


enum texture_draw_flag {
	texture_draw_use_anchor      = (1 << 0),
    texture_draw_keep_aspect     = (1 << 1),
};

typedef sqc_dword texture_draw_flags;

enum sqc_draw_texture_style {
    draw_texture_style_normal,
    draw_texture_style_tiled,
};

struct sqc_texture_draw_info {
    bool    use_anchor;
    bool    use_custom_anchor;
    bool    use_target_size;
    bool    use_source_size;
    bool    use_mirror;
    bool    use_tile;
    bool    single_pass_animation;
    bool    callback;
    
    struct {
        surf::surf_npoint point;
    }
    custom_anchor_info;
    
    
    struct {
        sqc_size    tile_size;
        int         tile_rows;
        int         tile_cols;
        int         tile_no;
    }
    tile_info;
    
    struct {
        int         mirror_width;
    }
    mirror_info;
    
    struct {
        bool            draw_tile;
        bool            keep_aspect;
        surf::surf_size target_size;
    }
    target_size_info;
    
    struct {
        surf::surf_size source_size;
    }
    source_size_info;
    
    sqc_texture_draw_info() {
        use_anchor = true;
        use_custom_anchor = false;
        use_target_size = false;
        use_mirror = false;
        use_tile = false;
        single_pass_animation = false;
        callback = false;
    }
    
    /*
     * set single pass option for animation
     */
    void set_animation_play_once( )
    {
        single_pass_animation = true;
    }
    
    /*
     * set custom anchor point
     */
    void set_custom_anchor( surf::surf_npoint const &p )
    {
        use_custom_anchor = true;
        custom_anchor_info.point = p;
    }
    
    /*
     * fill the specified size by tiled texture
     */
    sqc_texture_draw_info &set_tile_info( surf::surf_size const &s, int c, int r, int n ) {
        use_tile = true;
        tile_info.tile_size = s;
        tile_info.tile_cols = c;
        tile_info.tile_rows = r;
        tile_info.tile_no = n;
        
        return *this;
    }
    
    /*
     * fill the specified size by tiled texture
     */
    sqc_texture_draw_info &set_fill( surf::surf_size const &s ) {
        use_target_size = true;
        target_size_info.target_size = s;
        target_size_info.draw_tile = true;
        target_size_info.keep_aspect = false;
        use_anchor = false;
        return *this;
    }
    
    /*
     * stretch the texture to the given dimension
     */
    sqc_texture_draw_info &set_stretch( surf::surf_size const &s, bool keep_aspect = true ) {
        use_target_size = true;
        target_size_info.target_size = s;
        target_size_info.draw_tile = false;
        target_size_info.keep_aspect = keep_aspect;
        use_anchor = false;
        return *this;
    }
    
    /*
     * Mirror the texture, and mirror the anchor point using the specified width
     */
    sqc_texture_draw_info &set_mirrored( bool mirror, int mirror_width ) {
        use_mirror = mirror;
        mirror_info.mirror_width = mirror_width;
        return *this;
    }

    /*
     * Use or not anchor
     */
    sqc_texture_draw_info &set_use_anchor( bool f ) {
        use_anchor = f;
        return *this;
    }
};

/*
 * Texture interface
 */
class sqc_texture : public std::tr1::enable_shared_from_this<sqc_texture>, sqc_noncopyable {
public:
    /*
     * Draw the texture at the given location (anchor is used).
     */
    virtual void draw( surf::surf_context_ptr ctx, surf::surf_point const &point, sqc_texture_draw_info const &draw_info ) = 0;
    
    /*
     * Check is texure ready to draw
     */
    virtual bool is_ready() = 0;
    
    /*
     * Get the texture pixel size
     */
    virtual surf::surf_nsize get_size() const = 0;
    
    /*
     * Get width value to calculate mirrored anchors
     */
    virtual int get_width_for_mirroring() const = 0;
    
    /*
     * Get the texture anchor point.
     */
    virtual surf::surf_npoint get_anchor() const = 0;
    virtual void set_anchor( surf::surf_npoint const &p ) = 0;
	
	/*
     * Get the texture name.
     */
	virtual sqc_string get_name() const = 0;
        
    /*
     * Check the texture transparency
     */
    virtual bool hit_test( surf::surf_npoint const &point ) = 0;
protected:
    virtual bool operator<(const sqc_texture&) = 0;
    
    virtual void load_texture_image() = 0;
    virtual sqc_size_t unload_texture_image() = 0;
    virtual bool is_actual() = 0;
    virtual bool is_loading() = 0;
    virtual void set_priority(sqc_load_texture_priority priority) = 0;
    
    friend class sqc_texture_proxy;      
};

typedef std::tr1::shared_ptr<sqc_texture> sqc_texture_ptr;

struct sqc_texture_proxy_init {
    /*
     * maximum amount of memory which can be used by textures. 
     * iPhone - 10 mb, iPhone4, iPad - 20 mb
     * manager works effective if all available memory is used.
     */
    sqc_size_t      memory_limit;
    
    /*
     * Path to local resources.
     */
    sqc_string  resource_path;
    
    
    /*
     * Texture downloader. May be 0.
     */
    
    sqc_downloader*    			downloader;
    
    /*
     * image loader
     */
    surf::surf_image_loader*   image_loader;
    
};

class sqc_texture_proxy {
    enum sqc_texture_entry_state {
        texture_entry_state_undefined,
        texture_entry_state_downloading,
        texture_entry_state_loading,
        texture_entry_state_loaded,
        texture_entry_state_unloaded
    };
    
    struct sqc_frame_info {
        sqc_frame_info() : rotated(false) {}
        
        surf::surf_nrect    rect;
        surf::surf_npoint   offset;
        bool                rotated;
    };
    
    typedef std::tr1::shared_ptr<sqc_frame_info> sqc_frame_info_ptr;
    typedef std::vector<sqc_frame_info_ptr> sqc_frame_info_vector; 
    
    struct sqc_texture_entry {
        sqc_texture_entry( sqc_string const &n ) 
            : requested_frame( 0 )
            , is_animation( false ) 
            , is_local( true )
            , is_png4( false )
            , revision( false ) 
            , state( texture_entry_state_undefined )
            , frame_step( 15 )
            , name( n )
            , memory_size( 256*256*4 )
        {
        }
        
        surf::surf_image_ptr            image;
        sqc_ddword                      requested_frame;
        sqc_dword                       revision;
        
        surf::surf_npoint               anchor;
        surf::surf_nsize                size;
        bool                            is_animation;
        bool                            is_local;
        bool                            is_png4;
        
        int                             frame_step;
        
        sqc_frame_info_vector           frames;
        
        sqc_texture_entry_state         state;
        
        sqc_load_texture_priority       load_priority;
        sqc_size_t                      memory_size;        
        
        sqc_string                      url;
        sqc_string                      extension;
        
        sqc_string const &get_name() const {
            return name;
        }
    protected:        
        sqc_string                      name;

    };
    
    typedef std::tr1::shared_ptr<sqc_texture_entry>     sqc_texture_entry_ptr;
    typedef std::map<sqc_string, sqc_texture_entry_ptr> sqc_texture_entry_map;
    typedef std::list<sqc_texture_entry_ptr>            sqc_texture_entry_list;
    
	typedef std::map<sqc_string, sqc_texture_ptr>     sqc_texture_map;
	typedef std::list<sqc_texture_ptr>					sqc_texture_list;
	
    struct sqc_texture_impl : public sqc_texture {
    public:
        sqc_texture_impl( sqc_texture_entry_ptr e, sqc_texture_proxy &p );
        
        virtual void draw( surf::surf_context_ptr ctx, surf::surf_point const &point, sqc_texture_draw_info const &draw_info );
        virtual bool is_ready();
        virtual surf::surf_nsize get_size() const;
        virtual surf::surf_npoint get_anchor() const;
        virtual void set_anchor( surf::surf_npoint const &p );
		virtual sqc_string get_name() const;
        virtual int get_width_for_mirroring() const;
        virtual bool hit_test( surf::surf_npoint const &point );

    
    protected:
        
        void touch();
        virtual void load_texture_image();
        virtual sqc_size_t unload_texture_image();
        virtual bool is_actual();
        virtual bool is_loading();
        virtual void set_priority(sqc_load_texture_priority priority);
        
        virtual bool operator<(const sqc_texture&);
        
        
        
        sqc_texture_entry_ptr   entry;
        sqc_texture_proxy       &proxy;
        
        sqc_tile_info          tile_info;
    };
	typedef std::list<sqc_texture_impl> sqc_texture_impl_list;
	
    class sqc_texture_animation_impl : public sqc_texture_impl {
    public:
        sqc_texture_animation_impl( sqc_texture_entry_ptr e, sqc_texture_proxy &p );
        
        virtual void draw( surf::surf_context_ptr ctx, surf::surf_point const &point, sqc_texture_draw_info const &draw_info );
    private:
        sqc_ddword m_last_draw_frame;
    };
    
public:
    sqc_texture_proxy(surf::surf_graphics_server &graphics);
    
    void init( sqc_texture_proxy_init const &init );
    /*
     * Get the texture with given name. 
     * Texture object are created immediately, loading texture data is scheduled.
     * Returns empty ptr in case of error.
     */
    sqc_texture_ptr    get_texture( const char *name, sqc_load_texture_priority load_priority );

    // any texture location (not in texture.plist)
    sqc_texture_ptr    get_remote_texture( const char *uri, const char *file_name, const char *extension, sqc_load_texture_priority load_priority );
    
    /*
     * Check the state of textures, which are used on last frame, is changed.
     */
    bool need_to_redraw();
    
    /*
     * Render started notification.
     */
    void on_pre_render();
    
    /*
     * Render complete notification.
     */
    void on_post_render();
    
    /*
     * Textures is ready notification.
     */
    void on_texture_downloaded( sqc_string const &name, bool plist = false );
    
    /*
     * Textures description is ready notification.
     */
    void on_description_downloaded( sqc_string const &path );
	
	/*
	 * Memory amount currently used
	 */
	sqc_size_t get_memory_used() const;
	
	/*
	 * Reconfigure memory limit
	 */
	void set_memory_limit( sqc_size_t );
	
	/*
	 * Free all used memory
	 */
	void free_memory();
	
protected:
    sqc_texture_ptr create_texture(sqc_texture_entry_ptr entry, bool load_image = false);
    
	void load_texture_image(sqc_texture_entry_ptr &entry);
    void load_texture_info(sqc_texture_entry_ptr &entry);
    void release_texture_image(sqc_texture_entry_ptr &entry);
    
    void load_textures(sqc_texture_list &textures, sqc_texture_list &loaded_textures, sqc_ddword max_tick );
    sqc_size_t release_textures(sqc_texture_list &textures, sqc_size_t mem_for_release, bool with_actual_render = false);
    
    void add_texture_for_load(sqc_texture_ptr texture, sqc_size_t mem_size, sqc_load_texture_priority priority);
	
    void parse_texture_animation_info(sqc_texture_entry_ptr &entry);
    
    sqc_texture_entry_ptr create_entry_by_local( const char *name );
    bool check_texture_actuality( sqc_string const &name );
    void set_next_redraw_frame(sqc_ddword frame);
private:
    sqc_texture_proxy_init  config;
    bool            m_textures_changed;
    sqc_ddword      m_current_frame_no;
    
    sqc_size_t		m_texture_memory_used;
    
    sqc_size_t      m_texture_normal_memory_needed;
    sqc_size_t      m_texture_idle_memory_needed;
    
    sqc_texture_entry_map   m_entries;
    sqc_texture_map			m_textures_cache;
	
    sqc_texture_list   m_textures_normal_for_load;
    sqc_texture_list   m_textures_idle_for_load;
    
    sqc_texture_list   m_textures_normal_loaded;
    sqc_texture_list   m_textures_idle_loaded;
    
    surf::surf_graphics_server& m_graphics;
    
    sqc_texture_entry_list  m_load_queue;
    sqc_texture_entry_list  m_download_queue;
    sqc_texture_entry_list  m_delayed_queue;
    
    std::set<sqc_string>           m_errors;
	
    std::tr1::shared_ptr<sstl::sstl_thread>     m_load_thread;
    
    sqc_ddword m_current_logic_frame;
    sqc_ddword m_next_frame_for_redraw;
};
	
END_NAMESPACE_SQC_FRAMEWORK
