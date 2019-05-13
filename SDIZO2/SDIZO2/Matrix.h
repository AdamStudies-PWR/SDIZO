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
	void create(int nodes, double edges, double maxedges, bool directed);
	//Funkcja wyœwietlaj¹ca graf
	void display();
	//Funkcja obs³uguj¹ca algorytm Dijsktry
	void mst_Dijkstra(int start);
private:
	//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
	void spanningtree(int *visited);
	//Funkcja relaksuj¹ca s¹siadów
	int relax(int index);
	void test();
};

#endif