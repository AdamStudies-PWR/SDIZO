#pragma once
#ifndef List_hpp
#define List_hpp
//Klasa obs³uguj¹ca listow¹ reprezentacje grafów
#include "Graphs.h"

struct Node;
struct Edge;

struct Node
{
	int index = 0;
	Edge *head = nullptr;
	Edge *tail = nullptr;
	Node *next = nullptr;
	Node *prev = nullptr;
	int connections = 0;
};

struct Edge
{
	int weight = 0;
	Edge *next = nullptr;
	Node *target = nullptr;
	Node *source = nullptr;
};

class List : public Graphs
{
private:
	//Zmienne
	Node *head = nullptr;
	Node *tail = nullptr;
public:
	//Metody
	//Funkcja losowo tworz¹ca graf
	void create(int nodes, double edges, double maxedges, bool directed);
	//Funkcja wyœwietlaj¹ca graf//Funkcja wyœwietlaj¹ca graf
	void display();
	//Funkcja obs³uguj¹ca algorytm Dijsktry
	void dijkstra(int start);
	//Funckja obs³uguj¹ca algorytm prima
	void mst_Prim(int start);
	//Funkcja obs³uguj¹ca algorytm Kruskala
	void mst_Kruskal();
private:
	//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
	void spanningtree();
	//Funkcja relaksuj¹ca s¹siadów
	int relax(int index);
};

#endif