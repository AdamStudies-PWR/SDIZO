#pragma once
#ifndef Graphs_hpp
#define Graphs_hpp

//Struktura obs³uguj¹ca algorytm Dijkstry
struct Dijkstra
{
	int index = 0;
	int distance = -1;
	int prev = -1;
};

//Klasa obs³uguj¹ca bazowe elemety dla obu typów grafów
class Graphs
{
protected:
	//Zmienne
	int nodes;
	int edges;
	//Zmienne powi¹zane z algorytmem Dijkstry
	Dijkstra *checked;
	Dijkstra *notchecked;
	int dch, dnch;
public:
	//Funkcja losowo tworz¹ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
	virtual void mst_Dijkstra(int start) = 0;
};

#endif