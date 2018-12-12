/*
 *  sqc_select_person_dlg.h
 *  aCountry
 *	The file contains a base class for select people dialog cell
 *  Created by Vasily Alioshechkin (albacil@gmail.com) on 06.09.11.
 *  Copyright 2011 Social Quantum. All rights reserved.
 *
 */

#include "sqc_person_cell.h"

NAMESPACE_SQC_FRAMEWORK

sqc_person_cell::sqc_person_cell( milk::milk_widget_ptr p )
	: milk::milk_widget (p)
{
}

sqc_person_cell::~sqc_person_cell()
{
}

END_NAMESPACE_SQC_FRAMEWORK
