#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs³uguj¹ca maciorzow¹ reprezantacj¹ grafów
#include "Graphs.h"
#include "Tests.h"

class Matrix: public Graphs, public Tests
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
	void dijkstra(int start);
	//Funckja obs³uguj¹ca algorytm prima
	void mst_Prim(int start);
	//Funkcja obs³uguj¹ca algorytm Kruskala
	void mst_Kruskal();
	//Funkcja obs³uguj¹ca algorytm Forda-Bellmana
	void ford_bellman(int node);
	//Czyszczeni pamiêci
	void free_memory();
	//Wczytanie grafu
	void load_graph(std::string filename, bool directed);
	// Wczytywanie dla algorytmu najkrótszej drogi
	int load_sw(std::string filename);
private:
	//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
	void spanningtree(int *visited);
	//Funkcja relaksuj¹ca s¹siadów
	int relax(int index);
};

#endif