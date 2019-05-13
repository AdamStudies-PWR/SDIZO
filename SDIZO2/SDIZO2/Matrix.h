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
	void create(int nodes, double edges, double maxedges, bool directed);
	//Funkcja wy�wietlaj�ca graf
	void display();
	//Funkcja obs�uguj�ca algorytm Dijsktry
	void mst_Dijkstra(int start);
private:
	//Funkcja towrz�ca drzewo rozpinaj�ce dla nieskierowanego
	void spanningtree(int *visited);
	//Funkcja relaksuj�ca s�siad�w
	int relax(int index);
	void test();
};

#endif