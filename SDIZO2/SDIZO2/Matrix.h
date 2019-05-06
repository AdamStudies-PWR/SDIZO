#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs³uguj¹ca maciorzow¹ reprezantacj¹ grafów
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	//Zmienne
	int **pointer = nullptr;
public:
	//Metody
	//Funkcja losowo tworz¹ca graf
	void create(int nodes, double edges, int maxedges, bool directed);
	//Funkcja wyœwietlaj¹ca graf
	void display();
private:
	//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
	void spanningtree(int *visited);
};

#endif