/*
 *  quest_base.cpp
 *  common module
 *
 *  Created by Alexey Yukin on 27 Jun 2011
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "quest_base.h"
#include "sqc_utils.h"

NAMESPACE_QUESTS

void reward_item::load( yaml::sqc_yaml_node_ptr node )
{
    using namespace yaml;

    min_quantity = get_yaml_val<int>( node, "min_quantity" );
}


void quest_reward::load( yaml::sqc_yaml_node_ptr node )
{
    using namespace yaml;
    
    roll = get_yaml_val<int>( node, "roll" );

    sqc_yaml_node_ptr   subNode = node->find( "items" );
    if ( subNode && subNode->get_type() == node_type_sequence ) {
        for ( size_t idx = 0; idx != subNode->size(); ++idx ) {
            yaml::sqc_yaml_node_ptr child = subNode->get_child( idx );
            if ( child->get_type() == node_type_mapping && child->size() == 1 ) {
                sqc_yaml_node_iterator it = child->begin();
                reward_item_ptr entry( new reward_item( (const sqc_string &)it->first ) );
                entry->load( it->second );
                items.push_back( entry );
            }
        }
    }
}


void quest_goal::load( yaml::sqc_yaml_node_ptr node, sqc_locale_parser &locale_parser, sqc_string const &goal_key )
{
    using namespace yaml;
    using namespace utils;

    size_t idx;

    type = get_yaml_val<sqc_string>( node, "type" );
    klass = get_yaml_val<sqc_string>( node, "klass" );
    action = get_yaml_val<sqc_string>( node, "action" );
    count = get_yaml_val<int>( node, "count" );
    min_stage = get_yaml_val<int>( node, "min_stage" );
    max_stage = get_yaml_val<int>( node, "max_stage" );
    initial = get_yaml_val<int>( node, "initial" );
    value = get_yaml_val<int>( node, "value" );

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
    description = locale_parser.get_string( goal_key );
#else
    description = get_yaml_val_localized<sqc_string>( node, "desc" );
    if (description.size() == 0)
    {
        description = get_yaml_val<sqc_string>( node, "desc" );
    }
#endif


    process_description_string( description );

    icon_path = get_yaml_val<sqc_string>( node, "icon_path" );
    if ( ( idx = icon_path.rfind( '.' ) ) != sqc_string::npos ) {
        icon_path.resize( idx );
    }

    unlock_cost = get_yaml_val<int>( node, "unlock_cost" );

    completed = false;
    progress  = initial;
}

int quest_goal::set_progress( int p )
{
    int diff = p - progress;

    if( diff > 0 ) {
        progress = p;
    }

    return diff;
}

void quest_goal::set_progress_unconditional( int p )
{
    progress = p;
}

#ifdef SQC_ENABLE_EXTERNAL_LOCALIZATION
void quest_base::load( yaml::sqc_yaml_node_ptr node, sqc::sqc_locale_parser &locale_parser )
#else
void quest_base::load( yaml::sqc_yaml_node_ptr node )
#endif //ENABLE_EXTERNAL_LOCALIZATION
{
    using namespace yaml;
    using namespace utils;

    size_t idx;
    sqc_yaml_node_ptr   subNode;

    quest_id = get_yaml_val<int>( node, "id" );
    repeatable = get_yaml_val<bool>( node, "repeatable" );

    image = get_yaml_val<sqc_string>( node, "swf_name" );
    if ( ( idx = image.rfind( '.' ) ) != sqc_string::npos ) {
        image.resize( idx );
    }
/*
 quest1:
 <<: *quest
 id: 12001
 swf_name: "quest1.swf"
 name.ru: "Крыша над головой"
 name.en: "Крыша над головой"
 name.ko: "도시생활의 기본!"
 description_text.ru: "Отличная новость! В новый город потянулись новые жители... Никто не должен остаться без крова! Не теряйте времени, стройте новые дома!"
 description_text.en: "Отличная новость! В новый город потянулись новые жители... Никто не должен остаться без крова! Не теряйте времени, стройте новые дома!"
 description_text.ko: '도시에 주택을 만들고, 인구를 생산해 보세요~'
 hint.ru: ""
 hint.en: ""
 hint.ko: ''
 wall_text.ru: "{0} знает, что новым жителям в его городе нужно уютное жилье, поэтому [sex:он|она] занимается строительством."
 wall_text.en: "{0} знает, что новым жителям в его городе нужно уютное жилье, поэтому [sex:он|она] занимается строительством."
 wall_text.ko: '축! \"도시 생활의 기본!\" 퀘스트 완료!'
 require:
 - {type: user, klass: level, count: 1}
 - {type: user, klass: level, count: 1, action: less_or_equal, value: 5}
 goal:
 - {type: field, klass: log_hut, count: 3, desc.ru: "Иметь 3 деревянных дома", desc.ko: "소형주택 3개 짓기!", icon_path: quest_log_hut.png, min_stage: 2, max_stage: 6}
 - {type: event, klass: event, action: pick_house, count: 3, desc.ru: "Собрать население с домов 3 раза", desc.ko: "주택에서 인구생산 3회 하기!", icon_path: quest_pick_population.png}
 reward:
 complete:
 - roll: 0
 items:
 - exp: {min_quantity: 35}
 - coins: {min_quantity: 500}
*/
    /*
 
 "quest1:description_text" = "Отличная новость! В новый город потянулись новые жители... Никто не должен остаться без крова! Не теряйте времени, стройте новые дома!";
 "quest1:goal_0" = "Построить 3 деревянных дома";
 "quest1:goal_1" = "Собрать население с домов 3 раза";
 "quest1:hint" = "";
 "quest1:name" = "Крыша над головой";
 "quest1:wall_text" = "{0} знает, что новым жителям в его городе нужно уютное жилье, поэтому [sex:он|она] занимается строительством.";
 */
#if SQC_ENABLE_EXTERNAL_LOCALIZATION
    name = locale_parser.get_string( type + ":name" );
    description_text = locale_parser.get_string( type + ":description_text" );
    complete_text = locale_parser.get_string( type + ":complete_text" );
    wall_text = locale_parser.get_string( type + ":wall_text" );
    hint = get_yaml_val_localized<sqc_string>( node, "hint" );
    splash_text = get_yaml_val_localized<sqc_string>( node, "splash_text" );
#else
    name = get_yaml_val_localized<sqc_string>( node, "name" );
    description_text = get_yaml_val_localized<sqc_string>( node, "description_text" );
    complete_text = get_yaml_val_localized<sqc_string>( node, "complete_text" );
    wall_text = get_yaml_val_localized<sqc_string>( node, "wall_text" );
    hint = get_yaml_val_localized<sqc_string>( node, "hint" );
    splash_text = get_yaml_val_localized<sqc_string>( node, "splash_text" );
#endif//    
    process_description_string( description_text );
    process_description_string( complete_text );
    process_description_string( wall_text );
    process_description_string( splash_text );
    

    complete_image = get_yaml_val<sqc_string>( node, "complete_image" );
    if ( ( idx = complete_image.rfind( '.' ) ) != sqc_string::npos ) {
        complete_image.resize( idx );
    }
    
    
    

    achievement = get_yaml_val<sqc_string>( node, "achievement" );

    sort_order = get_yaml_val<int>( node, "sort_order" );
    display_order = 0;
    xml_order = 0;

    subNode = node->find( "goal" );
    if ( subNode && subNode->get_type() == node_type_sequence ) {
        for ( idx = 0; idx != subNode->size(); ++idx ) {
            std::stringstream   out;
            out << type << ":goal_" << idx;
            
            quest_goal_ptr entry( new quest_goal() );
            entry->load( subNode->get_child( idx ), locale_parser, out.str() );
            goals.push_back( entry );
        }
    }

    subNode = node->find( "require" );
    if ( subNode && subNode->get_type() == node_type_sequence ) {
        for ( idx = 0; idx != subNode->size(); ++idx ) {
            std::string dummy;
            quest_require_ptr entry( new quest_require() );
            entry->load( subNode->get_child( idx ), locale_parser, dummy );
            requires.push_back( entry );
        }
    }

    subNode = node->find( "reward" );
    if ( subNode && subNode->get_type() == node_type_mapping ) {
        for( sqc_yaml_node_iterator i = subNode->begin(); i != subNode->end(); ++i ) {
            yaml::sqc_yaml_node_ptr listNode = i->second;

            if ( listNode->get_type() == node_type_sequence ) {
                quest_reward_list l;

                for ( idx = 0; idx != listNode->size(); ++idx ) {
                    quest_reward_ptr entry( new quest_reward() );
                    entry->load( listNode->get_child( idx ) );
                    l.push_back( entry );
                }

                rewards[i->first] = l;
            }
        }
    }
}


void request_base::load( yaml::sqc_yaml_node_ptr node, sqc_locale_parser &locale_parser )
{
    using namespace yaml;

    size_t idx;
    sqc_yaml_node_ptr   subNode;

    request_id = get_yaml_val<int>( node, "id" );
    request_type = get_yaml_val<sqc_string>( node, "request_type" );
    position = get_yaml_val<sqc_string>( node, "position" );

    image = get_yaml_val<sqc_string>( node, "image" );
    if ( ( idx = image.rfind( '.' ) ) != sqc_string::npos ) {
        image.resize( idx );
    }
    if ( ( idx = image.rfind( '/' ) ) != sqc_string::npos ) {
        image.erase( 0, idx + 1 );
    }

    expire = get_yaml_val<int>( node, "expire" );
    max_count = get_yaml_val<int>( node, "max_count" );
    limited = get_yaml_val<bool>( node, "limited" );

    subNode = node->find( "reward" );
    if ( subNode && subNode->get_type() == node_type_sequence ) {
        for ( idx = 0; idx != subNode->size(); ++idx ) {
            quest_reward_ptr entry( new quest_reward() );
            entry->load( subNode->get_child( idx ) );
            reward.push_back( entry );
        }
    }

    subNode = node->find( "poster_reward" );
    if ( subNode && subNode->get_type() == node_type_sequence ) {
        for ( idx = 0; idx != subNode->size(); ++idx ) {
            quest_reward_ptr entry( new quest_reward() );
            entry->load( subNode->get_child( idx ) );
            poster_reward.push_back( entry );
        }
    }

    call_back_request = get_yaml_val<sqc_string>( node, "call_back_request" );
    not_wait_for_drop = get_yaml_val<bool>( node, "not_wait_for_drop" );
    is_callback = get_yaml_val<bool>( node, "is_callback" );

    sqc_string string_key;

    string_key = get_yaml_val<sqc_string>( node, "send_post" );
    if ( string_key.size() ) {
        send_post = locale_parser.get_string( string_key );
        sqc::utils::process_description_string( send_post );
    }

    string_key = get_yaml_val<sqc_string>( node, "send_button" );
    if ( string_key.size() ) {
        send_button = locale_parser.get_string( string_key );
    }

    string_key = get_yaml_val<sqc_string>( node, "receive_post" );
    if ( string_key.size() ) {
        receive_post = locale_parser.get_string( string_key );
        sqc::utils::process_description_string( receive_post );
    }

    string_key = get_yaml_val<sqc_string>( node, "receive_button" );
    if ( string_key.size() ) {
        receive_button = locale_parser.get_string( string_key );
    }
}

END_NAMESPACE_QUESTS
