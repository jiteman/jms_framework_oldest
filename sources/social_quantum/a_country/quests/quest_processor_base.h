/*
 *  quest_processor_base.h
 *  common module
 *
 *  Created by Alexey Yukin on 29 Jun 2011
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __QUEST_PROCESSOR_BASE_INCLUDED__
#define __QUEST_PROCESSOR_BASE_INCLUDED__

#include "quest_base.h"
#include <libxml/parser.h>

#define HIDE_OBJECTIVE_C_KEYWORDS
#include "sqc_base.h"

//
// tempo!!!
//
#include "sqc_xml.h"

NAMESPACE_QUESTS

typedef std::vector<int> ids_list;
typedef std::map<sqc_string, int> string_val_map;

struct inc_counter_data {
public:
    int quest_id, counter_id, value;
    inc_counter_data() : quest_id( 0 ), counter_id( 0 ), value( 0 ) {}
    inc_counter_data( int qid, int cid, int v ) : quest_id( qid ), counter_id( cid ), value( v ) {}
};

typedef std::list<inc_counter_data> icd_list;

//
//
//

struct sqc_counter {
    int vals[7];
};

typedef std::map<const char *, sqc_counter, cmp_psz>    sqc_counters_by_name;


typedef std::map<int, xml::xml_node_ptr>  sqc_node_by_id;


struct sqc_process_context {
    sqc_node_by_id  node_by_id;
    sqc_counters_by_name counter_by_name;
    int             level;
};
//
//
//
class quest_processor_base
{
public:
    quest_processor_base() : quest_descriptions(NULL) {}

    virtual ~quest_processor_base() {}

    ids_list const&get_completed_quests() const {
        return completed_quests;
    }

    ids_list const&get_available_quests() const {
        return available_quests;
    }

    ids_list const&get_new_completed_quests() const {
        return new_completed_quests;
    }
    
    ids_list const&get_new_available_quests() const {
        return new_available_quests;
    }

    void set_quest_descriptions( quest_list* qd ) {
        quest_descriptions = qd;
    }

    void set_counter_value( const sqc_string& name, int value ) {
        current_counters[name] = value;
    }

    void inc_counter_value( const sqc_string& name, int value ) {
        current_counters[name] += value;
    }

    icd_list const&get_inc_counters_params() const {
        return inc_counters_params;
    }

    void clear_counters() {
        current_counters.clear();
    }

    virtual void process( xmlDoc* inXML, const sqc::info::sqc_object_info_provider& provider, sqc_process_context &ctx ) = 0;
    virtual void read_counters( xmlDoc* inXML, const sqc::info::sqc_object_info_provider& provider, sqc_process_context &ctx ) = 0;
    virtual void unlock_counter( int counter, int quest_id ) = 0;
    virtual void reset_quests_state() = 0;
    virtual void read_display_order( xmlDoc* inXML ) = 0;

protected:
    ids_list completed_quests;      // id-шки квестов, у которых выполнены условия goal
    ids_list available_quests;      // id-шки квестов, у которых выполнены условия require
    ids_list new_completed_quests;  // id-шки квестов, которые нужно завершить (команда серверу)
    ids_list new_available_quests;  // id-шки квестов, которые нужно стартовать (команда серверу)
    icd_list inc_counters_params;   // параметры обновления счетчиков (команда серверу)

    quest_list* quest_descriptions; // описания квестов из yml

    string_val_map current_counters;
};

END_NAMESPACE_QUESTS

#endif //__QUEST_PROCESSOR_BASE_INCLUDED__
