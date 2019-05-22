#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs�uguj�ca maciorzow� reprezantacj� graf�w
#include "Graphs.h"
#include "Tests.h"

class Matrix: public Graphs, public Tests
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
	void dijkstra(int start);
	//Funckja obs�uguj�ca algorytm prima
	void mst_Prim(int start);
	//Funkcja obs�uguj�ca algorytm Kruskala
	void mst_Kruskal();
	//Funkcja obs�uguj�ca algorytm Forda-Bellmana
	void ford_bellman(int node);
	//Czyszczeni pami�ci
	void free_memory();
	//Wczytanie grafu
	void load_graph(std::string filename, bool directed);
	// Wczytywanie dla algorytmu najkr�tszej drogi
	int load_sw(std::string filename);
private:
	//Funkcja towrz�ca drzewo rozpinaj�ce dla nieskierowanego
	void spanningtree(int *visited);
	//Funkcja relaksuj�ca s�siad�w
	int relax(int index);
};

#endif