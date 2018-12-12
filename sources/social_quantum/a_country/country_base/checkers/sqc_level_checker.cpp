#include "sqc_level_checker.h"
#include "../message_queue/sqc_message_queue_base.h" 
#include "../../framework/sqc_framework.h"
#include "../sqc_framework_base.h"

sqc_level_checker::sqc_level_checker(
                       sqc::framework::sqc_message_queue_base& message_queue
                       ,sqc::framework::sqc_game_ptr& game
                       ,sqc::framework::sqc_country_base_ui_face& ui
                       ,const sqc::sqc_string &in_name)
    : sqc_checker_base(message_queue,ui,in_name)
    , m_game(game)
    , m_current_level(0)
    , m_is_next_window_showed(false)
{
}

void sqc_level_checker::invoke()
{
    using namespace sqc::framework;  
        
    sqc_assert( m_game );
      
    if(!need_show())
        return;
    
    //-- save level
    update();
    sqc::framework::framework().preferences().set_int( "next_level_checker", "last_level", m_current_level );
    //--
    
    // show( add to queue)
    show_level_up();
}

void sqc_level_checker::show_level_up()
{
    sqc::framework::sqc_level_up_params params;
    m_game->fill_common_info(params.scene_info);
    
    //-- just example. To Do late..
    params.received_buks  = 1;
    params.received_coins = 1500;
    //--
    
    milk::milk_dialog_ptr dlg = m_ui.create_level_up_dialog(params);
    if ( !dlg )
    {
        sqc_error() << "unable to create level up dialog";
        return;
    }
    
    dlg->set_next_button_action( 
                                std::tr1::bind( &sqc_level_checker::show_on_next_level, this ) );
    
    if(m_is_next_window_showed == true)
    {
        m_message_queue.add_messsage_front( dlg );
    }
    else
    {
        m_message_queue.add_messsage_back( dlg );
    }
    
    m_is_next_window_showed = true;
    sqc_info() << "'level up' dialog was added in queue "; 
}



void sqc_level_checker::show_on_next_level()
{ 
    sqc::framework::sqc_on_next_level_params params;
    m_game->fill_common_info(params.scene_info);
    
    milk::milk_dialog_ptr	     m_on_next_level_wnd; 
    
    milk::milk_dialog_ptr dlg = m_ui.create_on_next_level_dialog( params );
    if ( !dlg )
    {
        sqc_error() << "unable to create on_next_level window";
        return;
    }
    
    dlg->set_back_button_action( 
                           std::tr1::bind( &sqc_level_checker::show_level_up, this ) );
    
    dlg->set_destroy_handler( 
                           std::tr1::bind( &sqc_level_checker::on_destroy, this ) );
    
    
    sqc_info() << "'on next level' dialog was added in queue ";
    m_message_queue.add_messsage_front( dlg );
}

void sqc_level_checker::on_destroy()
{
    m_message_queue.m_last_time = sqc::framework::clock_msec();
}

void sqc_level_checker::update()
{
    sqc::sqc_common_scene_info _si;
    
    m_game->fill_common_info(_si);
    
    m_current_level = _si.level;
}

sqc_level_checker::~sqc_level_checker()
{

}

bool sqc_level_checker::need_show()
{
    update();
    sqc::sqc_dword last_show_level = sqc::framework::framework().preferences().get_int( "next_level_checker", "last_level", 0 );
    
    /* //For test
    static bool a = false;
    if( !a )
    {   a = true;
        return true;
    }
    */
    
    if(last_show_level == 0)
    {
        sqc_warning() << "sqc_level_checker: Level = 0. First start?";
        sqc::framework::framework().preferences().set_int( "next_level_checker", "last_level", m_current_level );
        return false;
    }
    
    if ( m_current_level == last_show_level )
    {
        sqc_info() << "sqc_level_checker: m_current_level == last_show_level";
        return false;
    }
    else
    {
        m_is_next_window_showed = false;
        return true;   
    }
}
