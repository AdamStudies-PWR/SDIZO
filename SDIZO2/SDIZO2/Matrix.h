#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs�uguj�ca maciorzow� reprezantacj� graf�w
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	int *pointer;
public:
	void create(int Notes);
};

#endif