#include <iostream>

#include "sqc/sqc_city.h"
#include "sqc/sqc_xml.h"
#include "sqc/sqc_plist.h"
#include "sqc/sqc_file_api.h"
#include "sqc/sqc_png.h"
#include "sqc_info_load.h"
#include "sqc/sqc_farm.h"
#include "sqc_name_formatter.h"
#include "sqc/sqc_file_data_stream.h"

/*****************************************
                    README
 
 Executables ->configurator_city press right mouse button and choose get info. 
 Arguments tab -> add one Argument farm or city.
 
 Выберите Executables ->configurator_city нажмите правую кнопку и выберите get info из списка.
 Во вкладке Arguments добавьте новый единственны аргумент "farm"  или  "city".
 После сборки ,если аргумент добавлен , новый текстурный плист соберется по относительным путям.
 
*****************************************/

/////////// относительные пути к конфигурационным файлам ////////////////

#if defined _WIN32
    #define CITY_HIERARCHY_PATH     "RemoteFiles/city_hierarchy.yml"
    #define FARM_HIERARCHY_PATH     "RemoteFiles/farm_hierarchy.yml"

    #define CITY_ITEMS_PATH         "RemoteFiles/city_items.yml"
    #define FARM_ITEMS_PATH         "RemoteFiles/farm_items.yml"

    #define CITY_OBJECT_INFORMATION_BINARY_PATH "RemoteFiles/city_items.bin"
    #define FARM_OBJECT_INFORMATION_BINARY_PATH "RemoteFiles/farm_items.bin"

    #define FARM_TEXTURES_FOLDER    "RemoteFiles/iFarm"
    #define CITY_TEXTURES_FOLDER    "RemoteFiles/iCity"
#else

static const std::string REMOTE_FILES_DIR("..//..//..//RemoteFiles//");
static const std::string FARM_HIERARCHY_PATH(REMOTE_FILES_DIR + "farm_hierarchy.yml");
static const std::string FARM_ITEMS_PATH(REMOTE_FILES_DIR + "farm_items.yml");
static const std::string FARM_OBJECT_INFORMATION_BINARY_PATH(REMOTE_FILES_DIR + "farm_items.bin");
static const std::string FARM_TEXTURES_FOLDER(REMOTE_FILES_DIR + "iFarm");

    #define CITY_HIERARCHY_PATH     "..//..//..//RemoteFiles//city_hierarchy.yml"
    //#define FARM_HIERARCHY_PATH     "..//..//..//RemoteFiles//farm_hierarchy.yml"

    #define CITY_ITEMS_PATH         "..//..//..//RemoteFiles//city_items.yml"
    //#define FARM_ITEMS_PATH         "..//..//..//RemoteFiles//farm_items.yml"

    #define CITY_OBJECT_INFORMATION_BINARY_PATH "..//..//..//RemoteFiles//city_items.bin"
    //#define FARM_OBJECT_INFORMATION_BINARY_PATH "..//..//..//RemoteFiles//farm_items.bin"

    //#define FARM_TEXTURES_FOLDER    "..//..//..//RemoteFiles//iFarm"
    #define CITY_TEXTURES_FOLDER    "..//..//..//RemoteFiles//iCity"
#endif

//////////////////////////////////////////////////////////////////////////

NAMESPACE_SQC_INFO

std::string  path_key;

void check_textures( sqc_string const &texture_path, sqc_object_info_provider_ptr class_provider ) {
    plist::sqc_plist   texture_info;
    std::cout << "checking textures from " << texture_path << std::endl;
    {
        sqc_string  file_path = file_api::append_path( texture_path, "textures.plist" );
        sqc_string  tempo;
        
        if( !file_api::read_text_file( file_path, tempo ) ) {
            std::cerr << "ERROR: faild to read file: \"" << file_path << "\"" << std::endl;
        }
        if( !texture_info.parse( tempo ) ) {
            std::cerr << "ERROR: failed to parse texture info";
        }
    }

    sqc_string_list object_types = class_provider->get_object_names();
    
    for( sqc_string_list::const_iterator i = object_types.begin(); i != object_types.end(); ++i ) {
        sqc_string const &object_type = *i;
        
        sqc_game_object_ptr object = class_provider->create_instance( object_type.c_str() );
        if( !object ) {
            std::cerr << "ERROR: faild to create object: \"" << object_type << "\"" << std::endl;
            continue;
        }

        sqc_texture_info_list texture_names;
        sqc_object_info* obj_info = class_provider->get_object_info( object_type.c_str() );
        
        if (obj_info->get_type_id() > 0) {
            object->enumerate_textures( texture_names );
        }
        
        
//        std::cout << object_type << " -> ";
//
//        for( sqc_texture_info_list::const_iterator i = texture_names.begin(); i != texture_names.end(); ++i ) {
//            if( i != texture_names.begin() ) {
//                std::cout << ", ";
//            }
//            std::cout << "\"" << *i << "\"";
//        }
//        std::cout << std::endl;
        
        plist::sqc_plist_entry_ptr texture_info_root = texture_info.get_root();
        for( sqc_texture_info_list::const_iterator i = texture_names.begin(); i != texture_names.end(); ++i ) {
            
            bool    is_png4 = i->is_animation;
            //
            // check the texture entry is found
            //
            if( !texture_info_root ) {
                continue;
            }
            
            plist::sqc_plist_entry_ptr texture_entry = texture_info_root->get_value( i->name );
            if( !texture_entry ) {
                std::cerr 
                    << "WARNING: texture description is not found, created, " 
                    << "\"" << object_type << "\" -> \""  << i->name << "\"" 
                    << std::endl;
                texture_entry.reset( new plist::sqc_plist_entry_dict );
                texture_info_root->set_value( i->name, texture_entry );
            }
            if( i->need_anchor ) {
                sqc_string anchor = texture_entry->get_value_string( "anchor" );
                if( anchor.empty() ) {
                    std::cerr 
                        << "WARNING: texture anchor is empty, " 
                        << "\"" << object_type << "\" -> \""  << i->name << "\"" 
                        << std::endl;
                }
            }
            sqc_string image_name = i->name; 
            formattingString(image_name,path_key,true);
           
            sqc_string format = texture_entry->get_value_string( "format" );
            if( format.empty() ) {
                //
                // try to fix non-existing entry
                //
                
                sqc_string  file_path = file_api::append_path( texture_path, image_name );
                if( file_api::file_exist( file_path + ".png4" ) )   is_png4 = true;
                else if( file_api::file_exist( file_path + ".png" ) )   is_png4 = false;
                else {
                    std::cerr 
                        << "ERROR: unable to fix \"format\" entry, " 
                        << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                        << std::endl;
                }
                std::cerr 
                    << "WARNING: \"format\" entry is not exist, create " 
                    << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                    << std::endl;
                
                texture_entry->set_value_string( "format", is_png4 ? "png4444" : "png8888" );
            }
            else if( format == "png8888" )    is_png4 = false;
            else if( format == "png4444" )    is_png4 = true;
            else  {
                std::cerr 
                    << "ERROR: unsupported texture format: \"" << format << "\""
                    << ", \"" << object_type << "\" -> \""  << image_name << "\"" 
                    << std::endl;
            }
            
            int  revision = texture_entry->get_value_int( "revision" );
            if( !revision ) {
                std::cerr 
                    << "WARNING: \"revision\" is not specified, create "
                    << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                    << std::endl;
                texture_entry->set_value_int( "revision", 100 );
            }
            
            sqc_size    size_image;
            
            {
                sqc_string  file_path = file_api::append_path( texture_path, image_name );
                if( is_png4 )   file_path += ".png4";
                else            file_path += ".png";
                
                
				sqc::sqc_data_stream_ptr png_data_stream = sqc::sqc_file_data_stream::open( file_path.c_str() );
				sqc_image_raw_data png_image_data;
				png::png_image image;

                if ( !png_data_stream ) {
                    std::cerr << "ERROR: texture file not found: \"" << object_type << "\" -> \""  << image_name << "\"" << std::endl;
                    continue;
                }

                if ( !image.decode( png_data_stream.get(), png_image_data, true, false ) || png_image_data.size == sqc_size() ) {
                    std::cerr << "ERROR: can't get texture size: \"" << object_type << "\" -> \""  << image_name << "\"" << std::endl;
                    continue;
                }

				size_image = png_image_data.size;
            }
            
            if( size_image.cx > 1024 || size_image.cy > 1024 ) {
                std::cerr 
                << "ERROR: size of PNG image >1024 (" << size_to_string( size_image )<< ") "
                << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                << std::endl;
                continue;
            }

            sqc_string  size_text = texture_entry->get_value_string( "size" );
            
            if( size_text.empty() ) {
                std::cerr 
                    << "WARNING: \"size\" is not specified, set from texture "
                    << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                    << std::endl;
                
                size_text = size_to_string( size_image );
                texture_entry->set_value_string( "size", size_text );
            }
            
            sqc_size    size;
            
            if( !string_to_size( size_text, size ) || size_image != size ) {
                std::cerr 
                    << "WARNING: \"size\" is invalid, set from texture "
                    << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                    << std::endl;
                
                size_text = size_to_string( size_image );
                texture_entry->set_value_string( "size", size_text );
            }
            
            //
            // check the amimation entry
            //
            if( i->is_animation ) {
                plist::sqc_plist_entry_ptr animation_params = texture_entry->get_value( "animation_params" );
                if( !animation_params ) {
                    animation_params.reset( new plist::sqc_plist_entry_dict() );
                    texture_entry->set_value( "animation_params", animation_params );
                }
                
                int frame_count = animation_params->get_value_int( "frame_count" );

                
                sqc_string  frame_description = animation_params->get_value_string( "frame_description" );
                sqc_string  frame_descr_path = file_api::append_path( texture_path, image_name ) + ".plist";
                
                if( frame_description.empty() ) {
                    std::cerr 
                        << "ERROR: \"frame_description\" is not specified, set to PLIST "
                        << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                        << std::endl;
                    
                    if( !file_api::file_exist( frame_descr_path ) ) {
                        std::cerr 
                            << "ERROR: description file not found, "
                            << "\"" << object_type << "\" -> \""  << frame_descr_path << "\"" 
                            << std::endl;
                        continue;
                    }
                    
                    frame_description = "plist";
                    animation_params->set_value_string( "frame_description", frame_description );
                }
                
                if( frame_description == "plist" ) {
                    plist::sqc_plist    frame_descr;
                        
                    sqc_string  tempo1;
                    file_api::read_text_file( frame_descr_path, tempo1 );
                    
                    if( !frame_descr.parse( tempo1 ) ) {
                        std::cerr 
                            << "ERROR: during parsing file description, "
                            << "\"" << object_type << "\" -> \""  << frame_descr_path << "\"" 
                            << std::endl;
                        
                        continue;
                    }
                    
                    plist::sqc_plist_entry_ptr  descr_root = frame_descr.get_root();
                    
                    //
                    // check frames
                    //
                    plist::sqc_plist_entry_ptr  frames = descr_root->get_value( "frames" );
                    if( frames ) {
                        int frame_count_plist = 0;
                        for( plist::sqc_plist_iterator i1 = frames->begin(); i1 != frames->end(); ++i1 ) {
                            ++frame_count_plist;
                        }
                            
                        if( frame_count != frame_count_plist ) {
                            std::cerr 
                                << "WARNING: \"frame_count\" (" << frame_count << ") is not different from plist frames (" << frame_count_plist << "), fixed by PLIST "
                                << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                                << std::endl;
                            frame_count = frame_count_plist;
                            animation_params->set_value_int( "frame_count", frame_count_plist ); 
                        }
                    }
                    else {
                        std::cerr 
                        << "ERROR: frame description is not found, "
                        << "\"" << object_type << "\" -> \""  << frame_descr_path << "\"" 
                        << std::endl;
                    }
                    
                }
                else if( frame_description == "fixed" ) {
                    sqc_string tile_size_text = animation_params->get_value_string( "tile_size" );
                    sqc_size    tile_size;
                    if( !string_to_size( tile_size_text, tile_size ) ) {
                        std::cerr 
                        << "ERROR: \"tile_size\" is not specified or invalid, reset to frame size "
                        << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                        << std::endl;
                        
                        //tile_size_text = size_to_string( size, tile_size_text );
                        //animation_params->set_value_int( "tile_size", tile_size_text );
                    }
                }
                else {
                    std::cerr 
                    << "WARNING: unsupported \"frame_description\" value (\"" << frame_description << "\"), "
                    << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                    << std::endl;
                }
                
                int frame_step = animation_params->get_value_int( "frame_step" );
                if( !frame_step ) {
                    std::cerr 
                        << "WARNING: \"step\" is not specified, reset to 1 "
                        << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                        << std::endl;
                    animation_params->set_value_int( "frame_step", frame_step );
                }
                else if( frame_step > 1 ) {
                    std::cerr 
                        << "WARNING: \"step\" > 1 (" << frame_step << "),  animation may be bad, "
                        << "\"" << object_type << "\" -> \""  << image_name << "\"" 
                        << std::endl;
                }
            }
        }
    }
    
    
    {
        sqc_string  file_path = file_api::append_path( texture_path, "textures.new.plist" );
        sqc_string  tempo;
        
        
        if( !texture_info.write( tempo ) ) {
            std::cerr << "ERROR: failed to format texture info"  << std::endl;
        }
        else if( !file_api::write_text_file( file_path, tempo ) ) {
            std::cerr << "ERROR: faild to write file: \"" << file_path << "\"" << std::endl;
        }
    }
}

END_NAMESPACE_SQC_INFO


int main (int argc, char * const argv[]) {
    using namespace sqc;
    using namespace info;
    
    if (!argv[1]) {
        std::cerr << "Configurate key not found \n keys: city , farm" << std::endl;
        return 0;
    }
    std::string key = argv[1];
    
    sqc_version_provider_ptr version_provider(new sqc_version_provider());
    
    if(!key.empty())
    {
        if (key == "city") {
            sqc_class_factory_ptr    class_factory( new sqc_city_class_factory() );
            sqc_drawing_provider_ptr drawing_provider( new sqc_city_drawing_provider() );
            sqc_object_info_provider_ptr yaml_class_provider( new sqc_object_info_provider() );
            sqc_object_info_provider_ptr binary_class_provider( new sqc_object_info_provider() );
            path_key = "city";
            
            
            std::cout << "Check objects information..." << std::endl;
            if( argc > 3 ) 
                load_hierarchy( argv[3], class_factory, drawing_provider, version_provider );
            else 
            {
                load_hierarchy(CITY_HIERARCHY_PATH, class_factory, drawing_provider, version_provider );
            }
            
            std::cout << "Check drawing information..." << std::endl;
            if( argc > 2 ) 
                load_objects( argv[2], yaml_class_provider, class_factory, drawing_provider );
            else 
            {
                load_objects(CITY_ITEMS_PATH, yaml_class_provider, class_factory, drawing_provider );
            }

            std::cout << "Writing binary object information..." << std::endl;

            if ( !write_binary_object_information( CITY_OBJECT_INFORMATION_BINARY_PATH, yaml_class_provider ) ) {
                std::cout << "Writing binary object information failed" << std::endl;                
            } else {
                std::cout << "Writing binary object information is completed successfully" << std::endl;                
                std::cout << "Reading binary object information..." << std::endl;

                if ( !read_binary_object_information( CITY_OBJECT_INFORMATION_BINARY_PATH, binary_class_provider, class_factory, drawing_provider, version_provider ) ) {
                    std::cout << "Reading binary object information failed" << std::endl;                    
                } else {
                    std::cout << "Reading binary object information is completed successfully" << std::endl;
                    std::cout << "Checking object information..." << std::endl;

                    if ( compare_binary_object_information( yaml_class_provider, binary_class_provider ) ) {
                        std::cout << "Checking object information is completed successfully" << std::endl;
                    } else {
                        std::cout << "Checking object information failed" << std::endl;
                    }
                }
            }
            
            std::cout << "Check textures..." << std::endl;
            if( argc > 4 )
                check_textures( argv[4], yaml_class_provider );
            else 
            {
                check_textures(CITY_TEXTURES_FOLDER, yaml_class_provider );
            }
            
            std::cout << "checking is complete" << std::endl;
            
        }else if(key == "farm"){
            sqc_class_factory_ptr    class_factory( new sqc_farm_class_factory() );
            sqc_drawing_provider_ptr drawing_provider( new sqc_farm_drawing_provider() );
            sqc_object_info_provider_ptr yaml_class_provider( new sqc_object_info_provider() );
            sqc_object_info_provider_ptr binary_class_provider( new sqc_object_info_provider() );
            path_key = "farm";
            
            
            std::cout << "Сheck objects information..." << std::endl;
            if( argc > 3 ) 
                load_hierarchy( argv[3], class_factory, drawing_provider, version_provider );
            else 
            {
                load_hierarchy(FARM_HIERARCHY_PATH, class_factory, drawing_provider, version_provider );
            }
            
            std::cout << "Сheck drawing information..." << std::endl;
            if( argc > 2 ) 
                load_objects( argv[2], yaml_class_provider, class_factory, drawing_provider );
            else 
            {
                load_objects(FARM_ITEMS_PATH, yaml_class_provider, class_factory, drawing_provider );
            }

            std::cout << "Writing binary object information..." << std::endl;

            if ( !write_binary_object_information( FARM_OBJECT_INFORMATION_BINARY_PATH, yaml_class_provider ) ) {
                std::cout << "Writing binary object information failed" << std::endl;                
            } else {
                std::cout << "Writing binary object information completed is successfully" << std::endl;
                std::cout << "Reading binary object information..." << std::endl;

                if ( !read_binary_object_information( FARM_OBJECT_INFORMATION_BINARY_PATH, binary_class_provider, class_factory, drawing_provider, version_provider ) ) {
                    std::cout << "Reading binary object information failed" << std::endl;                    
                } else {
                    std::cout << "Reading binary object information is completed successfully" << std::endl;
                    std::cout << "Checking object information..." << std::endl;

                    if ( !compare_binary_object_information( yaml_class_provider, binary_class_provider ) ) {
                        std::cout << "Checking object information failed" << std::endl;                        
                    } else {
                        std::cout << "Checking object information is completed successfully" << std::endl;
                    }
                }
            }

            std::cout << "Сheck textures..." << std::endl;
            if( argc > 4 )
                check_textures( argv[4], yaml_class_provider );
            else 
            {
                check_textures(FARM_TEXTURES_FOLDER, yaml_class_provider );
            }
            
            std::cout << "checking is complete" << std::endl;
        } else {
            std::cerr << "Configurate key not found \n keys: city , farm" << std::endl;
        }

    }
    
    return 0;
}
