#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs�uguj�ca maciorzow� reprezantacj� graf�w
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	int **pointer;
	int Nodes;
	int Edges;
public:
	//Funkcja losowo tworz�ca graf
	void create(int Nodes, int Edges);
};

#endif