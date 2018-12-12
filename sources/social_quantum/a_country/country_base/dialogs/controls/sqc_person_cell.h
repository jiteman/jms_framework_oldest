/*
 *  sqc_select_person_dlg.h
 *  aCountry
 *	The file contains a base class for select people dialog cell
 *  Created by Vasily Alioshechkin (albacil@gmail.com) on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#ifndef __SQC_PERSON_CELL_H_INCLUDED__
#define __SQC_PERSON_CELL_H_INCLUDED__

#include "framework/dialogs/sqc_base_dialog.h"

NAMESPACE_SQC_FRAMEWORK

/*
typedef std::tr1::function<void(const sqc_string& object_type)> cell_buy_callback;
typedef std::tr1::function<void(const sqc_string& object_type)> cell_ask_callback;
*/

class sqc_person_cell : public milk::milk_widget 
{
public:
	sqc_person_cell( milk::milk_widget_ptr p);
	virtual ~sqc_person_cell();
};

typedef std::tr1::shared_ptr<sqc_person_cell> sqc_person_cell_ptr;

END_NAMESPACE_SQC_FRAMEWORK

#endif

