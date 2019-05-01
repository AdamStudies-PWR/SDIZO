#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs³uguj¹ca maciorzow¹ reprezantacj¹ grafów
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	int **pointer;
	int Nodes;
	int Edges;
public:
	//Funkcja losowo tworz¹ca graf
	void create(int Nodes, int Edges);
};

#endif