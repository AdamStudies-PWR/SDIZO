#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs�uguj�ca maciorzow� reprezantacj� graf�w
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	//Zmienne
	int **pointer = nullptr;
public:
	//Metody
	//Funkcja losowo tworz�ca graf
	void create(int nodes, double edges, int maxedges, bool directed);
	//Funkcja wy�wietlaj�ca graf
	void display();
private:
	//Funkcja towrz�ca drzewo rozpinaj�ce dla nieskierowanego
	void spanningtree(int *visited);
};

#endif