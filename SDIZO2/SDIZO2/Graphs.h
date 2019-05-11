#pragma once
#ifndef Graphs_hpp
#define Graphs_hpp

//Struktura obs�uguj�ca algorytm Dijkstry
struct Dijkstra
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
public:
	//Funkcja losowo tworz�ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
	virtual void mst_Dijkstra(int start) = 0;
};

#endif