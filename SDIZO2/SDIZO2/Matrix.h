#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs�uguj�ca bazowe elemety dla obu typ�w graf�w
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	int *pointer;
public:
	void create();
};

#endif