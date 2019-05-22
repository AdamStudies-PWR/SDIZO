#pragma once
#ifndef List_hpp
#define List_hpp
//Klasa obs�uguj�ca listow� reprezentacje graf�w
#include "Graphs.h"
#include "Tests.h"

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

class List : public Graphs, public Tests
{
private:
	//Zmienne
	Node *head = nullptr;
	Node *tail = nullptr;
public:
	//Metody
	//Funkcja losowo tworz�ca graf
	void create(int nodes, double edges, double maxedges, bool directed);
	//Funkcja wy�wietlaj�ca graf//Funkcja wy�wietlaj�ca graf
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
	void rekdel(Node *nod);
	void edgedel(Edge *edg);
	//Wczytanie grafu
	void load_graph(std::string filename);
private:
	//Funkcja towrz�ca drzewo rozpinaj�ce dla nieskierowanego
	void spanningtree();
	//Funkcja relaksuj�ca s�siad�w
	int relax(int index);
};

#endif