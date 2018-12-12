/*
 *  sqc_utils.cpp
 *  common module
 *
 *  Created by Alexey Yukin on 25 Jun 2011
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "sqc_utils.h"

NAMESPACE_SQC_UTILS

void get_values_list( sqc_string const &s, size_t s_from, size_t s_to, const char* delimiter, std::vector<sqc_string> &values )
{
    size_t len = strlen(delimiter);
    size_t pos;

    values.clear();

    while ((pos = s.find(delimiter, s_from)) < s_to)
    {
        values.push_back(s.substr(s_from, pos - s_from));
        s_from = pos + len;
    }

    values.push_back(s.substr(s_from, s_to - s_from + 1));
}

sqc_string format_string_by_values( sqc_string const &s, std::map<sqc_string, int> const &values )
{
    sqc_string result(s);

    size_t start;

    while ((start = result.find('[')) != sqc_string::npos)
    {
        size_t key_end = result.find(':', start + 1);
        if (key_end == sqc_string::npos) break;

        size_t end = result.find(']', key_end + 1);
        if (end == sqc_string::npos) break;

        sqc_string key = result.substr(start + 1, key_end - start - 1);

        std::map<sqc_string, int>::const_iterator it = values.find(key);

        if (it != values.end())
        {
            int value_index = it->second;

            std::vector<sqc_string> values_list;
            get_values_list(result, key_end + 1, end - 1, "|", values_list);

            if (values_list.size() > value_index)
            {
                result.replace(start, end - start + 1, values_list[value_index]);
            }
            else
            {
                result.erase(start, end - start + 1);
            }
        }
        else
        {
            result.erase(start, end - start + 1);
        }
    }

    return result;
}

void process_description_string( sqc_string &description )
{
    size_t idx;

    const char* wordsToReplace[] = 
    { 
        "\\n",
        "<br/>",
    };
    
    const char* wordsToErase[] = 
    { 
        "\\"
    };
    
    for (size_t i = 0; i < sizeof(wordsToReplace) / sizeof(wordsToReplace[0]); i++)
    {
        int last_idx = -1;
        while ((idx = description.find(wordsToReplace[i])) != -1)
        {
            if ( (idx - last_idx) > 0) {
                description.replace(idx, strlen(wordsToReplace[i]), " ");
                last_idx = ++idx;
            }
            else {
                description.erase(idx, strlen(wordsToReplace[i]));
                last_idx = idx;
            }
            
        }
    }
    
    for (size_t i = 0; i < sizeof(wordsToErase) / sizeof(wordsToErase[0]); i++)
    {
        while ((idx = description.find(wordsToErase[i])) != -1)
        {
            description.erase(idx, strlen(wordsToErase[i]));
        }
    }
    
    //&nbsp;
    while ((idx = description.find("&nbsp;")) != -1)
    {
        description.replace(idx, 6, "\u00A0");
    }
    
    //long dash
    while ((idx = description.find("\xE2\x80\x94")) != -1)
    {
        description.replace(idx, 3, "-");
    }
}

void parse_map_string_into_map( sqc_string const &s, sqc_string_map &m )
{
    std::vector<sqc_string> values_list;
    get_values_list(s, 1, s.size() - 2, ", ", values_list);

    for (std::vector<sqc_string>::iterator it = values_list.begin(); it != values_list.end(); ++it)
    {
        sqc_string const &ss = *it;

        std::vector<sqc_string> key_value;
        get_values_list(ss, 0, ss.size() - 1, ": ", key_value);

        if (key_value.size() == 2)
        {
            m[key_value[0]] = key_value[1];
        }
    }
}

END_NAMESPACE_SQC_UTILS
