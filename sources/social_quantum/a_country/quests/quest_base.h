/*
 *  quest_base.h
 *  common module
 *
 *  Created by Alexey Yukin on 27 Jun 2011
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __QUEST_BASE_INCLUDED__
#define __QUEST_BASE_INCLUDED__

#include "sqc_defs.h"
#include "sqc_yaml.h"
#include "sqc_locale_parser.h"

#define NAMESPACE_QUESTS namespace sqc { namespace quests {
#define END_NAMESPACE_QUESTS }}

NAMESPACE_QUESTS

class reward_item
{
public:
    reward_item( const sqc_string &n ) : name(n) {}
    
    virtual ~reward_item() {}

    virtual void load( yaml::sqc_yaml_node_ptr node );

    
    sqc_string const &get_name() const {
        return name;
    }
    
    int get_min_quantity() const {
        return min_quantity;
    }
    
private:
    sqc_string name;
    int        min_quantity;
};

typedef shared_ptr2<reward_item> reward_item_ptr;
typedef std::list<reward_item_ptr>        reward_item_list;

class quest_reward
{
public:
    quest_reward() {}
    
    virtual ~quest_reward() {}
    
    virtual void load( yaml::sqc_yaml_node_ptr node );
    
    
    int get_roll() const {
        return roll;
    }

    reward_item_list const&get_items() const {
        return items;
    }
    
private:
    int              roll;
    reward_item_list items;
};

typedef shared_ptr2<quest_reward> quest_reward_ptr;
typedef std::list<quest_reward_ptr>        quest_reward_list;

class quest_goal
{
public:
    quest_goal() {}
    
    virtual ~quest_goal() {}

    
#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
    virtual void load( yaml::sqc_yaml_node_ptr node, sqc_locale_parser &locale_parser, sqc_string const &goal_key );
#else
    virtual void load( yaml::sqc_yaml_node_ptr node );
#endif //SQC_ENABLE_EXTERNAL_LOCALIZATION

    


    sqc_string const &get_type() const {
        return type;
    }

    sqc_string const &get_klass() const {
        return klass;
    }

    sqc_string const &get_action() const {
        return action;
    }

    int get_count() const {
        return count;
    }

    int get_min_stage() const {
        return min_stage;
    }

    int get_max_stage() const {
        return max_stage;
    }

    int get_initial() const {
        return initial;
    }

    int get_value() const {
        return value;
    }

    sqc_string const &get_description() const {
        return description;
    }

    sqc_string const &get_icon_path() const {
        return icon_path;
    }

    int get_unlock_cost() const {
        return unlock_cost;
    }

    bool get_completed() const {
        return completed;
    }

    void set_completed( bool c ) {
        completed = c;
    }

    int get_progress() const {
        return progress;
    }

    int set_progress( int p ); // возвращает разницу между новым и старым значением и меняет текущее значение когда новое значение больше старого

    void set_progress_unconditional( int p );

private:
    sqc_string type;
    sqc_string klass;
    sqc_string action;
    int        count;
    int        min_stage;
    int        max_stage;
    int        initial;
    int        value;
    sqc_string description;
    sqc_string icon_path;
    int        unlock_cost;

    bool       completed; // завершена ли эта подзадача
    int        progress;  // текущий прогресс выполнения подзадачи
};

typedef shared_ptr2<quest_goal> quest_goal_ptr;
typedef std::list<quest_goal_ptr>        quest_goal_list;

class quest_require : public quest_goal
{
public:
    quest_require() {}

    virtual ~quest_require() {}
};

typedef shared_ptr2<quest_require> quest_require_ptr;
typedef std::list<quest_require_ptr>        quest_require_list;

class quest_base
{
public:
    quest_base( const sqc_string &t ) : type(t) {}

    virtual ~quest_base() {}

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
    virtual void load( yaml::sqc_yaml_node_ptr node, sqc_locale_parser &locale_parser );
#else
    virtual void load( yaml::sqc_yaml_node_ptr node );
#endif //ENABLE_EXTERNAL_LOCALIZATION


    sqc_string const &get_type() const {
        return type;
    }

    sqc_string const &get_image() const {
        return image;
    }

    sqc_string const &get_name() const {
        return name;
    }

    sqc_string const &get_description_text() const {
        return description_text;
    }

    sqc_string const &get_hint() const {
        return hint;
    }

    sqc_string const &get_complete_image() const {
        return complete_image;
    }

    sqc_string const &get_complete_text() const {
        return complete_text;
    }

    sqc_string const &get_wall_text() const {
        return wall_text;
    }

    sqc_string const &get_splash_text() const {
        return splash_text;
    }

    sqc_string const &get_achievement() const {
        return achievement;
    }

    int get_id() const {
        return quest_id;
    }

    bool get_repeatable() const {
        return repeatable;
    }

    int get_sort_order() const {
        return sort_order;
    }

    quest_goal_list const&get_goals() const {
        return goals;
    }
    
    quest_require_list const&get_requires() const {
        return requires;
    }

    std::map<sqc_string, quest_reward_list> const&get_rewards() const {
        return rewards;
    }

    int get_display_order() const {
        return display_order;
    }

    void set_display_order( int o ) {
        display_order = o;
    }

    int get_xml_order() const {
        return xml_order;
    }

    void set_xml_order( int o ) {
        xml_order = o;
    }

private:
    sqc_string type;
    int        quest_id;
    bool       repeatable;
    sqc_string image;
    sqc_string name;
    sqc_string description_text;
    sqc_string hint;
    sqc_string complete_image;
    sqc_string complete_text;
    sqc_string wall_text;
    sqc_string splash_text;
    sqc_string achievement;
    int        sort_order;
    int        display_order;
    int        xml_order;

    quest_goal_list    goals;
    quest_require_list requires;

    std::map<sqc_string, quest_reward_list> rewards;
};

typedef shared_ptr2<quest_base> quest_base_ptr;
typedef std::list<quest_base_ptr>        quest_list;

class request_base
{
public:
    request_base( const sqc_string &t ) : type(t) {}
    
    virtual ~request_base() {}
    
    virtual void load( yaml::sqc_yaml_node_ptr node, sqc_locale_parser &locale_parser );

    
    sqc_string const &get_type() const {
        return type;
    }

    sqc_string const &get_request_type() const {
        return request_type;
    }

    sqc_string const &get_position() const {
        return position;
    }

    sqc_string const &get_image() const {
        return image;
    }

    int get_id() const {
        return request_id;
    }
    
    int get_expire() const {
        return expire;
    }

    int get_max_count() const {
        return max_count;
    }

    bool get_limited() const {
        return limited;
    }

    quest_reward_list const&get_reward() const {
        return reward;
    }

    quest_reward_list const&get_poster_reward() const {
        return poster_reward;
    }

    sqc_string const &get_call_back_request() const {
        return call_back_request;
    }

    bool get_not_wait_for_drop() const {
        return not_wait_for_drop;
    }

    bool get_is_callback() const {
        return is_callback;
    }

    sqc_string const &get_send_post() const {
        return send_post;
    }

    sqc_string const &get_send_button() const {
        return send_button;
    }

    sqc_string const &get_receive_post() const {
        return receive_post;
    }

    sqc_string const &get_receive_button() const {
        return receive_button;
    }

private:
    sqc_string type;
    int        request_id;
    sqc_string request_type;
    sqc_string position;
    sqc_string image;
    int        expire;
    int        max_count;
    bool       limited;
    sqc_string call_back_request;
    bool       not_wait_for_drop;
    bool       is_callback;
    sqc_string send_post;
    sqc_string send_button;
    sqc_string receive_post;
    sqc_string receive_button;

    quest_reward_list reward;
    quest_reward_list poster_reward;
};

typedef shared_ptr2<request_base> request_base_ptr;
typedef std::list<request_base_ptr>        request_list;

END_NAMESPACE_QUESTS

#endif //__QUEST_BASE_INCLUDED__
