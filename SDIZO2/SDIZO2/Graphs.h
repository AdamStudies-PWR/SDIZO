#pragma once
#ifndef Graphs_hpp
#define Graphs_hpp
//Klasa obs³uguj¹ca bazowe elemety dla obu typów grafów
class Graphs
{
protected:
	//Zmienne
	int nodes;
	double edges;
public:
	//Funkcja losowo tworz¹ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
};

#endif