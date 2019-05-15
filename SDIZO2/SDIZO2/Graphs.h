#pragma once
#ifndef Graphs_hpp
#define Graphs_hpp



//Struktura obs�uguj�ca algorytm Dijkstry
struct Dijkstra
{
	int index = 0;
	int distance = -1;
	std::string prev = "";
};

struct Prim
{
	int index = 0;
	int distance = -1;
	int prev = -1;
};

//Klasa obs�uguj�ca bazowe elemety dla obu typ�w graf�w
class Graphs
{
protected:
	//Zmienne
	int nodes;
	int edges;
	//Zmienne powi�zane z algorytmem Dijkstry
	Dijkstra *checked;
	Dijkstra *notchecked;
	int dch, dnch;
	//Zmiennie powi�zane z algorytmem Prima
	Prim *solved;
	Prim *notSolved;
	int sol, nsol;
public:
	//Funkcja losowo tworz�ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
	//Funkcja obs�uguj�ca algorytm Dijsktry
	virtual void dijkstra(int start) = 0;
	//Funckja obs�uguj�ca algorytm prima
	virtual void mst_Prim(int start) = 0;
protected:
	//Funckja drukuj�ca wynik dzia�ania algorytmu Disjkstry
	void display_Dijkstra(Dijkstra *list, int size);
	//Funckja drukuj�ca wynik dzia�ania algorytmu Prima
	void display_Prim(Prim *list, int size);
};

#endif