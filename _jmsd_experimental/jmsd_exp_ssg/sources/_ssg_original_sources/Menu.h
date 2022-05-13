#pragma once


#include "jmsf/stdal/stdal_stl.h"

template< class > class st;

bool ActMenu( bool bt );
std::string IntToString(int i);

void SetStatusU( st< int > *sl,char filter);
void SetStatusG( st< int > *sl,char filter);
