#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs³uguj¹ca bazowe elemety dla obu typów grafów
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	int *pointer;
public:
	void create();
};

#endif