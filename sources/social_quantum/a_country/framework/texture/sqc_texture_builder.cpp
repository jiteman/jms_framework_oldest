/*
 *  sqc_framework.cpp
 *  aCountry
 *
 *  Created by paul on 5/30/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_texture_builder.h"
#include "sqc_file_api.h"
#include "sqc_xml.h"
#include "sqc_plist.h"

using namespace std::tr1::placeholders;

NAMESPACE_SQC_FRAMEWORK


static const sqc_ddword c_max_timeout = 20;    //10 ms per call
static sqc_ddword get_tick_count() {
    sstl::time_mks time;
    sstl::get_current_time_mks(time);
    return time/1000;
}

//
// log
//
#define tp_verbose()      sqc_verbose()
#define tp_info()         sqc_info()
#define tp_warning()      sqc_warning()
#define tp_error()        sqc_error()
#define tp_fatal()        sqc_fatal()

//
// texture downloader
//
sqc_downloader::sqc_downloader() : m_texture_requests(0), m_need_save_revision(false) {

}

void sqc_downloader::init( sqc_downloader_init &init ) {
    config = init;
    
    tp_info() << "downloader is initialized, path = \"" << init.download_path << "\""; 
    
    file_api::create_directory(config.download_path);
    
    path_to_revision = file_api::append_path( config.download_path, "cache.xml" );
    
    if (!file_api::file_exist(path_to_revision)) {
        file_api::write_text_file(path_to_revision, "<cache></cache>");
    }
    
    read_revisions();
}

bool sqc_downloader::is_animation_downloaded(download_texture_info &info) {
    sqc_string postfix;
    
    if (info.extension.size()) {
        postfix = "." + info.extension;
    }
    else {
        postfix = info.is_png4 ? ".png4" : ".png";
    }
    
    sqc_string path_image = file_api::append_path(config.download_path, info.name + postfix);
    sqc_string path_plist = file_api::append_path(config.download_path, info.name + ".plist");
    
    bool res = file_api::file_exist(path_image) && file_api::file_exist(path_plist); 
    
    return res;
}

void sqc_downloader::download(
                              download_texture_info &info,
                              sqc_downloader_callback cb, 
                              sqc_check_texture_actuality_callback acb) {
    
    m_calback = cb;
    m_actuality_callback = acb;
    
    std::map<sqc_string, int>::const_iterator it = m_revisions.find(info.name);
    if (it != m_revisions.end() && it->second == info.revision) {
        if (info.is_animation && is_animation_downloaded(info)) {
            m_calback(info.name, true);
            m_calback(info.name, false);
            return;
        }
        
        m_calback(info.name, true);
    }
    
    if (info.priority == load_priority_now) {
        m_now_queue[info.name] = info;
    } else if (info.priority == load_priority_normal) {
        m_normal_queue[info.name] = info;
    } else {
        m_idle_queue[info.name] = info;
    }

    if (m_texture_requests <= config.max_download_queue_size) {
        start_download();
    }
}

void sqc_downloader::download_texture(download_texture_info info, bool check_actuality) {
    tp_info() << "sqc_downloader: start download texture: \"" << info.name << "\"";
    
    
    if (check_actuality && !m_actuality_callback(info.name)) {
        tp_info() << "sqc_downloader: texture: \"" << info.name << "\" not actual now, stop download";
        m_not_actual_queue[info.name] = info;
        return;
    }
    
    m_texture_requests++;
    
    sqc_string postfix = info.is_png4 ? ".png4" : ".png";
    
    sqc_net_path url;
    if (info.url.size()) {
        url = info.url;
    }
    else {
        url = file_api::append_path(config.download_url, info.name + postfix);
    }
    
    sqc_net_param   params;
    params.complete_callback = std::tr1::bind(&sqc_downloader::on_http_complete, this, info, url, _2);
    params.error_callback = std::tr1::bind(&sqc_downloader::on_http_error, this, info, url, _2);
    
    sqc_string path_image = file_api::append_path(config.download_path, info.name + postfix);
    
    if (!info.is_animation) {
        config.http->download( url, params );
    }
    else if(!file_api::file_exist(path_image)) {
        config.http->download( url, params );
    }
    
    if (info.is_animation) {
        info.is_plist = true;
        
        params.complete_callback = std::tr1::bind(&sqc_downloader::on_http_complete, this, info, url, _2);
        params.error_callback = std::tr1::bind(&sqc_downloader::on_http_error, this, info, url, _2);
        
        sqc_net_path url_plist = file_api::append_path(config.download_url, info.name + ".plist");
        sqc_string path_plist = file_api::append_path(config.download_path, info.name + ".plist");
        
        if (!file_api::file_exist(path_plist)) {
            config.http->download( url_plist, params );
        }
    }
}

void sqc_downloader::download_textures(sqc_download_texture_map &textures, bool check_actuality) {
    
    for(sqc_download_texture_map::iterator it = textures.begin(); it != textures.end(); ) {
        if (m_texture_requests > config.max_download_queue_size) {
            break;
        }
        
        download_texture(it->second, check_actuality);
        textures.erase(it++);
    }    
}

void sqc_downloader::start_download() {
    download_textures(m_now_queue);    
    download_textures(m_normal_queue);
    download_textures(m_idle_queue);
}

void sqc_downloader::on_http_complete(download_texture_info info, sqc_net_path url, sqc_net_data const &raw) {
    tp_info() << "sqc_downloader: texture: \"" << info.name <<  "\" downloaded";
    
    m_revisions[info.name] = info.revision;
    m_need_save_revision = true;
    
    sqc_string postfix;
    
    if (info.extension.size()) {
        postfix = "." + info.extension;
    }
    else if (info.is_plist) {
        postfix = ".plist";
    }
    else {
        postfix = info.is_png4 ? ".png4" : ".png";
    }
    
    sqc_string path = file_api::append_path(config.download_path, info.name + postfix);
    file_api::write_text_file(path, raw);
    
    if (!info.is_plist) {
        m_texture_requests = std::max(--m_texture_requests, 0);
    }
    
    m_calback(info.name, info.is_animation);
    
    start_download();        
}

void sqc_downloader::on_http_error(download_texture_info info, sqc_net_path url, sqc_net_error const &error) {
    tp_info() << "sqc_downloader: can't download texture: \"" << info.name << "\"";
    m_texture_requests = std::max(--m_texture_requests, 0);
}

void sqc_downloader::on_idle() {
    store_revistions();
    if (m_texture_requests < config.max_download_queue_size && m_not_actual_queue.size()) {
        download_textures(m_not_actual_queue, false);    
    }
}

void sqc_downloader::read_revisions() {
    using namespace xml;
    
    tp_info() << "read revision file";
    
    sqc_string  raw_xml;
    if( !file_api::read_text_file( path_to_revision, raw_xml ) ) {
        tp_warning() << "failed to read revistion file";
        return;
    }
    
    xml_doc xml( raw_xml );
    if( !xml.is_valid() ) {
        tp_warning() << "failed to parse revistion file";
        return;
    }
    
    xml_node_list   node_entries;
    xml.get_root()->get_childs( node_entries );
    
    for( xml_node_list::const_iterator i = node_entries.begin(); i != node_entries.end(); ++i ) {
        xml_node_ptr    node( *i );
        
        int rev = node->get_attribute_int( "revision" );
        if( !rev ) continue;
        
        m_revisions[node->get_name()] = rev;
    }
}

void sqc_downloader::store_revistions() {
    if (!m_need_save_revision) {
        return;
    }
    
    using namespace xml;
    
    tp_info() << "store revision file";
    
    xml_doc new_doc;
    xml_node_ptr root_node = new_doc.create_node( "cache", xml_node_ptr() );
    
    for( sqc_revision_map::const_iterator i = m_revisions.begin(); i != m_revisions.end(); ++i ) {
        xml_node_ptr    new_node = new_doc.create_node( i->first.c_str(), root_node );
        new_node->set_attribute_int( "revision", i->second );
    }
    
    sqc_string xml_data;
    new_doc.write_xml(xml_data);
    
    file_api::write_text_file(path_to_revision, xml_data);
    
    m_need_save_revision = false;
}

void sqc_downloader::set_download_url(sqc_string url) {
    config.download_url = url;
    tp_info() << "sqc_downloader: download url = \"" << url << "\"";
}

sqc_string sqc_downloader::get_texture_cache_path() {
    return config.download_path;
}

//
// texture proxy
//
sqc_texture_proxy::sqc_texture_proxy(surf::surf_graphics_server &graphics) 
    : m_graphics(graphics), 
      m_textures_changed(false), 
      m_current_frame_no(0), 
      m_texture_memory_used(0), 
      m_texture_normal_memory_needed(0), 
      m_texture_idle_memory_needed(0),
      m_current_logic_frame(0),
      m_next_frame_for_redraw(100000)
{
    
}

void sqc_texture_proxy::init( sqc_texture_proxy_init const &init ) {
    tp_info() << "initialize texture proxy";
    config = init;
}

/*
 * Get the texture with given name. 
 * Texture object are created immediately, loading texture data is scheduled.
 * Returns empty ptr in case of error.
 */
sqc_texture_ptr sqc_texture_proxy::get_texture(const char *name, sqc_load_texture_priority load_priority) {
    
    BEGIN_PROFILED_AREA( "texture_man->get_texture" );
    sqc_texture_entry_ptr   entry;
    
    //tp_verbose() << "getting texture: \"" << name << "\"";
    
    if( m_errors.find( name ) != m_errors.end() ) {
        return sqc_texture_ptr();
    }
    
    sqc_texture_map::const_iterator it = m_textures_cache.find(name);
	if (it != m_textures_cache.end()) {
        //tp_verbose() << "texture: \"" << name << "\" geting from cache";
        it->second->set_priority(load_priority);
		return it->second;
	}
	
    // check the texture entry exist in the description map
    sqc_texture_entry_map::const_iterator i = m_entries.find(name);
    if( i != m_entries.end() ) {
        entry = i->second;
        //tp_verbose() << "texture: \"" << name << "\" creating by description map";
    }
    else {
        entry = create_entry_by_local(name);
        if( !entry ) {
            tp_warning() << "can't create texture: \"" << name << "\"";
            m_errors.insert( name );
            return sqc_texture_ptr();
        }
        m_entries[name] = entry;
        //tp_verbose() << "texture: \"" << name << "\" creating by local";
    }
    
    entry->load_priority = load_priority;
    
	m_textures_cache[name] = create_texture(entry, load_priority == load_priority_now);
    return m_textures_cache[name];
}

// any texture location (not in texture.plist)
sqc_texture_ptr sqc_texture_proxy::get_remote_texture( 
	const char *uri, const char *file_name, const char *extension, sqc_load_texture_priority load_priority ) {
    
    tp_verbose() << "getting remote texture: \"" << file_name << "\"";
    
    sqc_texture_map::const_iterator it = m_textures_cache.find(file_name);
	if (it != m_textures_cache.end()) {
        //tp_verbose() << "texture: \"" << file_name << "\" geting from cache";
        it->second->set_priority(load_priority);
		return it->second;
	}
    
    sqc_texture_entry_ptr entry(new sqc_texture_entry( file_name ));
    entry->is_local = false;
    entry->state = texture_entry_state_loading;
    entry->url = uri;
    entry->extension = extension;
    m_entries[file_name] = entry;
    
    m_textures_cache[file_name] = create_texture(entry, load_priority == load_priority_now);
    
    return m_textures_cache[file_name];
}


sqc_texture_ptr sqc_texture_proxy::create_texture(sqc_texture_entry_ptr entry, bool load_image) {
    entry->state = texture_entry_state_loading;
    
    if (load_image) {
        load_texture_image(entry);
	}
    else {
        load_texture_info(entry);
    }

	sqc_texture_ptr texture(entry->is_animation ? new sqc_texture_animation_impl(entry, *this) : new sqc_texture_impl(entry, *this));
    return texture;
}

void sqc_texture_proxy::load_texture_image(sqc_texture_entry_ptr &entry) {
    if (!entry->is_local) {
        
        download_texture_info info;
        info.name = entry->get_name();
        info.revision = entry->revision;
        info.priority = entry->load_priority;
        info.is_png4 = entry->is_png4;
        info.is_animation = entry->is_animation;
        info.url = entry->url;
        info.extension = entry->extension;
        
        config.downloader->download(
                                    info, 
                                    std::tr1::bind(&sqc_texture_proxy::on_texture_downloaded, this, _1, _2),
                                    std::tr1::bind(&sqc_texture_proxy::check_texture_actuality, this, _1));
    } 
    else {
        on_texture_downloaded(entry->get_name());
    }
}

void sqc_texture_proxy::load_texture_info(sqc_texture_entry_ptr &entry) {
	surf::surf_image_info  info;
    surf::surf_create_image_info create_info;
    
    if (!entry->is_local) {
        create_info.reading_path = surf::surf_create_image_info::from_temp;
    }
    
    if (entry->state == texture_entry_state_loaded) {
        config.image_loader->load_image_info(entry->get_name().c_str(), info, create_info );
        entry->memory_size = info.mem_size;
    }
}

void sqc_texture_proxy::release_texture_image(sqc_texture_entry_ptr &entry) {
	m_texture_memory_used = 
        entry->memory_size > m_texture_memory_used ? 0 : m_texture_memory_used - entry->memory_size;
    
	entry->image.reset();
	entry->state = texture_entry_state_unloaded;
    
    tp_info() << "texture: \"" << entry->get_name() << "\" unloaded";
    tp_info() << "texture memory used: " << m_texture_memory_used;
}

void sqc_texture_proxy::load_textures(sqc_texture_list &textures, sqc_texture_list &loaded_textures, sqc_ddword max_tick ) {
    BEGIN_PROFILED_AREA("texture_man->load_texture");
    
    for (sqc_texture_list::iterator it = textures.begin(); it != textures.end(); ++it) {
        if (m_texture_memory_used >= config.memory_limit) {
            break;
        }
        if( get_tick_count() > max_tick ) {
            break;
        }
        (*it)->load_texture_image();
        loaded_textures.push_back(*it);
    }
    
    textures.clear();
}

sqc_size_t sqc_texture_proxy::release_textures(sqc_texture_list &textures, sqc_size_t mem_for_release, bool with_actual_render) {
    textures.sort();
    sqc_size_t mem_released = 0;
    
    sqc_texture_list::iterator it = textures.begin();
    while (it != textures.end()) {
        if ((*it)->is_actual() && !with_actual_render) {
            break;
        }
        
        mem_released += (*it)->unload_texture_image();
        it = textures.erase(it);
        if (mem_released >= mem_for_release) break;
    }
    
    if ( mem_released ) {
        tp_info() << "release textures: " << mem_released;
        tp_info() << "texture memory used: " << m_texture_memory_used;
    }
    
    return mem_released;
}

void sqc_texture_proxy::on_post_render() {
    BEGIN_PROFILED_AREA( "texture_man->on_post_render" );

    long mem_needed = m_texture_normal_memory_needed + m_texture_idle_memory_needed;
    long mem_for_release = (mem_needed + m_texture_memory_used) - config.memory_limit;
    long mem_for_release_for_normal = (m_texture_normal_memory_needed + m_texture_memory_used) - config.memory_limit;
    
    bool    allow_load_idle = true;
    
    if (mem_for_release > 0) {
        
        long    released_mem = release_textures(m_textures_idle_loaded, mem_for_release);
        mem_for_release -= released_mem;
        mem_for_release_for_normal -= released_mem;
        
        if (mem_for_release > 0 ) {
            released_mem = release_textures(m_textures_normal_loaded, mem_for_release);
            mem_for_release -= released_mem;
            mem_for_release_for_normal -= released_mem;
            
            if( mem_for_release_for_normal > 0 ) {
                // unload the used idle textures if we have no enougth memory for normal textures
                released_mem = release_textures(m_textures_idle_loaded, mem_for_release, true);
                allow_load_idle = false;
            }
        }
    }
    
    sqc_ddword max_tick = get_tick_count() + c_max_timeout;
    load_textures(m_textures_normal_for_load, m_textures_normal_loaded, max_tick);
    
    if( allow_load_idle ) {
        // do not load idle textures if we have no enougth memory for normal textures
        load_textures(m_textures_idle_for_load, m_textures_idle_loaded, max_tick);
    }
}

void sqc_texture_proxy::add_texture_for_load(sqc_texture_ptr texture, sqc_size_t memory_size, sqc_load_texture_priority priority) {
    BEGIN_PROFILED_AREA( "texture_man->add_texture_for_load" );

    if (priority == load_priority_normal) {
        sqc_texture_list::iterator it = std::find(m_textures_normal_for_load.begin(), m_textures_normal_for_load.end(), texture);
        if (it != m_textures_normal_for_load.end()) {
            (*it)->set_priority(priority);
            return;
        }
        
        m_textures_normal_for_load.push_back(texture);
        m_texture_normal_memory_needed += memory_size;
    }
    else if (priority == load_priority_idle) {
        sqc_texture_list::iterator it = std::find(m_textures_idle_for_load.begin(), m_textures_idle_for_load.end(), texture);
        if (it != m_textures_idle_for_load.end()) {
            (*it)->set_priority(priority);
            return;
        }
        
        m_textures_idle_for_load.push_back(texture);
        m_texture_idle_memory_needed += memory_size;
    }
}

sqc_texture_proxy::sqc_texture_entry_ptr sqc_texture_proxy::create_entry_by_local( const char *name ) {
    surf::surf_image_info  info;
    
    surf::surf_image_loader    *image_loader = config.image_loader;
    surf::surf_create_image_info create_info;
    if( !image_loader->load_image_info( name, info, create_info ) ) {
        return sqc_texture_entry_ptr();
    }
    
    sqc_texture_entry_ptr entry(new sqc_texture_entry( name ));
    entry->revision = 0;
    entry->is_animation = false;
    entry->is_local = true;
    entry->size = info.size; 
    entry->memory_size = info.mem_size;
	
    return entry;
}

bool sqc_texture_proxy::need_to_redraw() {
    if( m_textures_changed ) {
        return true;
    }
    
    ++m_current_logic_frame;
    if (m_current_logic_frame == m_next_frame_for_redraw) {
        return true;
    }
    
    return false;
}

void sqc_texture_proxy::on_pre_render() {
    m_textures_changed = false;
    m_texture_normal_memory_needed = 0;
    m_texture_idle_memory_needed = 0;
    ++m_current_frame_no;
}

void sqc_texture_proxy::on_texture_downloaded( sqc_string const &name, bool plist ) {
    sqc_texture_entry_ptr entry = m_entries[name];
    
    if (plist) {
        parse_texture_animation_info(entry);
        return;
    }
    
    surf::surf_image_info  info;
    surf::surf_create_image_info create_info;
    create_info.reduce_bitwidth = entry->is_png4;
    create_info.file_type = entry->is_png4 ? surf::surf_image_file_type_png4 :  surf::surf_image_file_type_png;
    
    // костыль!!!
    bool is_jpg = false;
    if ( entry->extension == "jpg" ) {
        create_info.file_type = surf::surf_image_file_type_jpg;
        is_jpg = true;
    }
    
    sqc_string texture_name;
    if (!entry->is_local) {
        texture_name += "cache/";
        create_info.reading_path = surf::surf_create_image_info::from_temp;
    }
    
    texture_name += entry->get_name();
    
    entry->image = m_graphics.create_image_ex(texture_name.c_str(), create_info);
	if (!entry->image) {
        entry->image = m_graphics.create_image_ex(texture_name.c_str(), create_info);
        tp_error() << "can't load image for texture: \"" << entry->get_name() << "\"";
        
        return;
    }
    
    // костыль!!!
    if ( is_jpg ) {
        surf::surf_image_info surf_info = {};
        entry->image->get_info( surf_info );
        entry->size = surf_info.size;
    }
    
    entry->state = texture_entry_state_loaded;
	
	entry->image->get_info(info);
	entry->memory_size = info.mem_size;
	
	m_texture_memory_used += info.mem_size;

    m_textures_changed = true;
    
    tp_info() << "texture: \"" << entry->get_name() << "\" loaded";
    tp_info() << "texture memory used: " << m_texture_memory_used;
}

bool sqc_texture_proxy::check_texture_actuality( sqc_string const &name ) {
	int	requested_frame = m_entries[name]->requested_frame;
	if( requested_frame != m_current_frame_no /*&&  m_entries[name]->load_priority != load_priority_now*/) {
        tp_info() << "sqc_downloader: texture: \"" << name << "\" not actual now: " << requested_frame << " !=" << m_current_frame_no << ", stop download";
        return false;
    }

//!!!
    return true;
}

void sqc_texture_proxy::on_description_downloaded( sqc_string const &path ) {
    tp_info() << "load textures description";
    
    sqc_string  raw;
    if( !file_api::read_text_file( path, raw ) ) {
        tp_warning() << "failed to read textures.plist";
    }
    
    using namespace plist;
    sqc_plist   plist;
    if( !plist.parse( raw ) ) {
        tp_warning() << "failed to parse textures.plist";
        return;
    }
    
    plist::sqc_plist_entry_ptr plist_root = plist.get_root();
    
    if( !plist_root ) {
        tp_warning() << "no information in textures.plist";
        return;
    }
    
    int counter = 0;
    int fail_counter = 0;
    
    for( sqc_plist_iterator i = plist_root->begin(); i != plist_root->end(); ++i ) {
        sqc_string  texture_name = i->first;
        sqc_plist_entry_ptr plist_entry = i->second;
        
        sqc_texture_entry_ptr   entry( new sqc_texture_entry( texture_name ) );
        
        entry->is_local = false;
        entry->revision = plist_entry->get_value_int( "revision" );
        
        
        {
            sqc_string val = plist_entry->get_value_string( "format" );
            if( val == "png4444" )  entry->is_png4 = true;
        }
        
        {
            sqc_string val = plist_entry->get_value_string( "anchor" );
            sqc::string_to_point( val, entry->anchor );
        }
        
        {
            sqc_string  val = plist_entry->get_value_string( "size" );
            if( !sqc::string_to_size( val, entry->size ) ) {
                tp_error() << "failed to parse size for \"" << texture_name << "\"";
                ++fail_counter;
                continue;
            }
        }
        
        plist::sqc_plist_entry_ptr plist_entry_animation = plist_entry->get_value( "animation_params" );
        if( plist_entry_animation ) {
            entry->is_animation = true;
            
            // default frame step = 15
            int frame_step = plist_entry_animation->get_value_int( "frame_step" );
            if( !frame_step ) frame_step = 1;
            
            frame_step*= 2;
            entry->frame_step = frame_step;            
            //int     fps = 15;
            //entry->frame_step = frame_step ? fps / frame_step : fps;

        }
        
        entry->memory_size = entry->size.cx * entry->size.cy * 2;
        if( !entry->is_png4 ) {
            entry->memory_size*=2;
        }

        
        m_entries[texture_name] = entry;
        ++counter;
    }
    
    tp_info() << counter << " texture(s) loaded";
    if ( fail_counter ) {
        tp_info() << fail_counter << " texture(s) unable to load";
    }
}

void sqc_texture_proxy::parse_texture_animation_info(sqc_texture_entry_ptr &entry) {
    if( !entry->frames.empty() ) {
        tp_info() << "animation info already loaded: \"" << entry->get_name() << "\"";
        return;
    }
    else {
        tp_info() << "start load animation info for: \"" << entry->get_name() << "\"";
    }
    
    sqc_string plist_file = entry->get_name() + ".plist";
    tp_info() << "load: \"" << plist_file << "\"";
    
    sqc_string path = file_api::append_path(config.downloader->get_texture_cache_path(), plist_file);
    
    sqc_string  raw;
    if( !file_api::read_text_file( path, raw ) ) {
        tp_warning() << "failed to read: \"" << plist_file << "\"" ;
    }
    
    using namespace plist;
    sqc_plist   plist;
    if( !plist.parse( raw ) ) {
        tp_warning() << "failed to parse: \"" << plist_file << "\"";
        return;
    }
    
    plist::sqc_plist_entry_ptr plist_root = plist.get_root();
    
    if( !plist_root ) {
        tp_warning() << "no information in \"" << plist_file << "\"";
        return;
    }
    
    plist::sqc_plist_entry_ptr plist_frames = plist_root->get_value( "frames" );
    
    if( !plist_frames ) {
        tp_warning() << "no frames information in \"" << plist_file << "\"";
        return;
    }
        
    for( sqc_plist_iterator i = plist_frames->begin(); i != plist_frames->end(); ++i ) {
        sqc_frame_info_ptr frame_info(new sqc_frame_info());
        
        sqc_string  frame_name = i->first;
        sqc_plist_entry_ptr plist_entry = i->second;
        
        sqc_rect  frame_rect;
        sqc_rect  source_rect;
        bool        rotated = false;
        { // frame
            sqc_string  val = plist_entry->get_value_string( "frame" );
            if( !sqc::string_to_rect( val, frame_rect ) ) {
                tp_warning() << "failed to parse frame for \"" << frame_name << "\" in \"" << plist_file << "\"";
            }
        }
        
        { // offset
            sqc_string  val = plist_entry->get_value_string( "offset" );
            if( !sqc::string_to_point( val, frame_info->offset ) ) {
                tp_warning() << "failed to parse offset for \"" << frame_name << "\" in \"" << plist_file << "\"";
            }
        }
        
        // rotated
        rotated = plist_entry->get_value_bool( "rotated" );
        
        { // sourceColorRect
            sqc_string  val = plist_entry->get_value_string( "sourceColorRect" );
            if( !sqc::string_to_rect( val, source_rect ) ) {
                tp_warning() << "failed to parse sourceColorRect for \"" << frame_name << "\" in \"" << plist_file << "\"";
            }
        }
        
//        if (rotated) {
//            std::swap( frame_rect.cx, frame_rect.cy );
//        }
        
        surf::surf_nrect    internal_rect( frame_rect.x, frame_rect.y, frame_rect.cx, frame_rect.cy );
        surf::surf_npoint   internal_offset( source_rect.x, source_rect.y );
        
        frame_info->rotated = rotated;
        frame_info->rect = internal_rect;
        frame_info->offset = internal_offset;
         
        entry->frames.push_back(frame_info);
    }
    
    tp_info() << "animation info for: \"" << entry->get_name() << "\" loaded " << "parsed " << entry->frames.size() << " frames(s)";
}

void sqc_texture_proxy::set_next_redraw_frame(sqc_ddword frame) {
    
    int current_frame_delta = m_next_frame_for_redraw - m_current_logic_frame;
    int new_frame_delta = frame - m_current_logic_frame;
    
    if (current_frame_delta <= 0 || current_frame_delta > new_frame_delta) {
        m_next_frame_for_redraw = frame;
    }
}

//
// texture implementation
//
sqc_texture_proxy::sqc_texture_impl::sqc_texture_impl( sqc_texture_entry_ptr e, sqc_texture_proxy &p )
    : entry( e )
    , proxy( p )
{
    assert( entry );
}

void sqc_texture_proxy::sqc_texture_impl::touch() {
    entry->requested_frame = proxy.m_current_frame_no;
    
    if( !entry->image ) {
        if( entry->state != texture_entry_state_loading || entry->state != texture_entry_state_downloading ) {
            proxy.add_texture_for_load(shared_from_this(), entry->memory_size, entry->load_priority);
        }
    }
}



void sqc_texture_proxy::sqc_texture_impl::draw( surf::surf_context_ptr ctx, surf::surf_point const &point, sqc_texture_draw_info const &draw_info ) {
    touch();
    
    if( entry->state == texture_entry_state_loaded && entry->image ) {
        surf::surf_rect  real_rect( point.x, point.y, entry->size.cx, entry->size.cy );
        surf::surf_rect   source_rect( 0, 0, entry->size.cx, entry->size.cy );
        
        surf::surf_draw_image_flags flags = 0;
        
        if( draw_info.use_mirror ) {
            flags |= surf::draw_image_mirrored;
        }

        
        int anchored_height = entry->size.cy;
        
        if( draw_info.use_tile ) {
            real_rect.cx = draw_info.tile_info.tile_size.cx;
            real_rect.cy = draw_info.tile_info.tile_size.cy;
            
            int row = draw_info.tile_info.tile_no / draw_info.tile_info.tile_cols;
            int col = draw_info.tile_info.tile_no % draw_info.tile_info.tile_cols;
            
            source_rect.x = real_rect.cx * col;
            source_rect.y = real_rect.cy * row;
            source_rect.cx = real_rect.cx;
            source_rect.cy = real_rect.cy;
            
            anchored_height = draw_info.tile_info.tile_size.cy;
        }
        else if( draw_info.use_target_size ) {
            real_rect.cx = draw_info.target_size_info.target_size.cx;
            real_rect.cy = draw_info.target_size_info.target_size.cy;
            
            if( draw_info.target_size_info.draw_tile ) {
                flags |= surf::tile_flag_both;
            }
            
            if( draw_info.target_size_info.keep_aspect ) {
                surf::surf_point  point = real_rect.bottom_left();
                point.x += real_rect.cx/2;
                point.y += real_rect.cy/2;
                
                
                double  horz = real_rect.cx/entry->size.cx;
                double  vert = real_rect.cy/entry->size.cy;
                
                double  zoom = std::min( horz, vert );
                
                surf::surf_size   new_size;
                new_size.cx = entry->size.cx * zoom;
                new_size.cy = entry->size.cy * zoom;
                
                real_rect.x = point.x - new_size.cx/2;
                real_rect.y = point.y - new_size.cy/2;
                real_rect.cx = new_size.cx;
                real_rect.cy = new_size.cy;
            }
        }
        
        if( draw_info.use_source_size ) {
            int cx = draw_info.source_size_info.source_size.cx;
            int cy = draw_info.source_size_info.source_size.cy;
            
            if (cx) {
                source_rect.cx = cx;
            }
            
            if (cy) {
                source_rect.cy = cy;
            }
        }

        if( draw_info.use_anchor ) {
            surf::surf_npoint anchor_point;
            
            if ( draw_info.use_custom_anchor ) {
                anchor_point = draw_info.custom_anchor_info.point;
            }
            else {
                anchor_point = entry->anchor;
            }
            
            if( draw_info.use_mirror ) {
                real_rect.x -= draw_info.mirror_info.mirror_width - anchor_point.x + entry->size.cx;
            }
            else {
                real_rect.x -= anchor_point.x;
            }
            real_rect.y -= ( anchored_height - anchor_point.y );
        }
        entry->image->draw( ctx, real_rect, source_rect, flags );
    }
}


int sqc_texture_proxy::sqc_texture_impl::get_width_for_mirroring() const {
    return ( 2 * entry->anchor.x - entry->size.cx );
}

bool sqc_texture_proxy::sqc_texture_impl::hit_test( surf::surf_npoint const &point ) {
    if( !entry->image ) {
        return true;
    }
    
    surf::surf_color color = entry->image->get_color( point );
    return color.a > 0.1;
}


bool sqc_texture_proxy::sqc_texture_impl::is_ready() {
    if( entry->image ) {
        return true;
    }
    
    touch();
    return false;
}

surf::surf_nsize sqc_texture_proxy::sqc_texture_impl::get_size() const {
    return entry->size;
}

surf::surf_npoint sqc_texture_proxy::sqc_texture_impl::get_anchor() const {
    return entry->anchor;
}

void sqc_texture_proxy::sqc_texture_impl::set_anchor( surf::surf_npoint const &p ) {
    entry->anchor = p;
}

sqc_string sqc_texture_proxy::sqc_texture_impl::get_name() const {
	return entry->get_name();
}

void sqc_texture_proxy::sqc_texture_impl::load_texture_image() {
    proxy.load_texture_image(entry);
}

sqc_size_t sqc_texture_proxy::sqc_texture_impl::unload_texture_image() {
    sqc_size_t result = entry->memory_size;
    proxy.release_texture_image(entry);
    return result;
}

bool sqc_texture_proxy::sqc_texture_impl::is_actual() {
    return entry->requested_frame == proxy.m_current_frame_no;
}

bool sqc_texture_proxy::sqc_texture_impl::is_loading() {
    return entry->state == 
            texture_entry_state_loading || entry->state == texture_entry_state_downloading;
}

void sqc_texture_proxy::sqc_texture_impl::set_priority(sqc_load_texture_priority priority) {
    entry->load_priority = priority;
}

bool sqc_texture_proxy::sqc_texture_impl::operator<(const sqc_texture &texture) {
    return entry->requested_frame != proxy.m_current_frame_no; 
}


//
// texture animation implementation
//
sqc_texture_proxy::sqc_texture_animation_impl::sqc_texture_animation_impl( sqc_texture_entry_ptr e, sqc_texture_proxy &p )
: sqc_texture_impl(e, p), m_last_draw_frame(0)
{    
}

void sqc_texture_proxy::sqc_texture_animation_impl::draw( surf::surf_context_ptr ctx, surf::surf_point const &point, sqc_texture_draw_info const &draw_info ) {
    touch();
    
	if (entry->frames.empty()) return;
    
    if (!m_last_draw_frame) {
        m_last_draw_frame = proxy.m_current_logic_frame;
    }
    
    int frame_info_index = ((proxy.m_current_logic_frame - m_last_draw_frame) / entry->frame_step) % entry->frames.size();
    
    sqc_ddword next_redraw_frame = 
    (proxy.m_current_logic_frame + entry->frame_step) - ((proxy.m_current_logic_frame - m_last_draw_frame) % entry->frame_step);
    
    proxy.set_next_redraw_frame(next_redraw_frame);
    
    
    sqc_frame_info_ptr frame_info = entry->frames[frame_info_index];

    
    if( entry->state == texture_entry_state_loaded && entry->image ) {
        surf::surf_rect  real_rect( 
                                    point.x+frame_info->offset.x, 
                                    point.y-frame_info->offset.y, 
                                    frame_info->rect.cx, 
                                    frame_info->rect.cy );
        surf::surf_rect   source_rect( frame_info->rect.x, 
                                      frame_info->rect.y, 
                                      entry->size.cx, 
                                      entry->size.cy );
        surf::surf_draw_image_flags flags = frame_info->rotated ? surf::draw_image_rotated : 0;
        if( draw_info.use_mirror ) {
            flags |= surf::draw_image_mirrored;
        }
        
        if( frame_info->rotated ) {
            source_rect.cy = frame_info->rect.cx;
            source_rect.cx = frame_info->rect.cy;
        }
        else {
            source_rect.cx = frame_info->rect.cx;
            source_rect.cy = frame_info->rect.cy;
        }
        
        int anchored_height = frame_info->rect.cy;

        
        //
        //
        //
        
        
        if( draw_info.use_tile ) {
            assert( false );
            return;
        }
        else if( draw_info.use_target_size ) {
            real_rect.cx = draw_info.target_size_info.target_size.cx;
            real_rect.cy = draw_info.target_size_info.target_size.cy;
            
            if( draw_info.target_size_info.draw_tile ) {
                flags |= surf::tile_flag_both;
            }
            
            if( draw_info.target_size_info.keep_aspect ) {
                assert( false );
                surf::surf_point  point = real_rect.bottom_left();
                point.x += real_rect.cx/2;
                point.y += real_rect.cy/2;
                
                
                double  horz = real_rect.cx/entry->size.cx;
                double  vert = real_rect.cy/entry->size.cy;
                
                double  zoom = std::min( horz, vert );
                
                surf::surf_size   new_size;
                new_size.cx = entry->size.cx * zoom;
                new_size.cy = entry->size.cy * zoom;
                
                real_rect.x = point.x - new_size.cx/2;
                real_rect.y = point.y - new_size.cy/2;
                real_rect.cx = new_size.cx;
                real_rect.cy = new_size.cy;
            }
        }
        if( draw_info.use_anchor ) {
            if( draw_info.use_mirror ) {
                real_rect.x -= draw_info.mirror_info.mirror_width - entry->anchor.x;
            }
            else {
                real_rect.x -= entry->anchor.x;
            }
            real_rect.y -= ( anchored_height - entry->anchor.y );
        }
        entry->image->draw( ctx, real_rect, source_rect, flags );
    }
}

sqc_size_t sqc_texture_proxy::get_memory_used() const {
	return m_texture_memory_used;
}

void sqc_texture_proxy::set_memory_limit( sqc_size_t size) {
	/// @todo stub
}

void sqc_texture_proxy::free_memory() {
	/// @todo stub
}

END_NAMESPACE_SQC_FRAMEWORK
