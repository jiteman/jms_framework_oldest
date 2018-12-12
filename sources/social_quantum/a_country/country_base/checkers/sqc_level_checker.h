#pragma once

#include "../message_queue/sqc_checker_base.h"
#include "../message_queue/sqc_message_queue_base.h"
#include "../sqc_game_base.h"

class sqc_level_checker :
	public sqc::framework::sqc_checker_base
{

public:
	sqc_level_checker(sqc::framework::sqc_message_queue_base& message_queue
                           ,sqc::framework::sqc_game_ptr& game
                           ,sqc::framework::sqc_country_base_ui_face& ui
                           ,const sqc::sqc_string &in_name);
                           
    virtual ~sqc_level_checker(); 
    
	virtual void invoke(); 
    
protected:
    bool need_show();
    void show_level_up();
    void show_on_next_level();
    void on_destroy();
        
    sqc::sqc_dword m_current_level;
    
    // -- members    
    sqc::framework:: sqc_game_ptr& m_game;
    
    void update();
        
private:
    
    bool m_is_next_window_showed;

};
