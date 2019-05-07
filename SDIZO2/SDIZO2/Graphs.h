#pragma once
#ifndef Graphs_hpp
#define Graphs_hpp
//Klasa obs�uguj�ca bazowe elemety dla obu typ�w graf�w
class Graphs
{
protected:
	//Zmienne
	int nodes;
	double edges;
public:
	//Funkcja losowo tworz�ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
};

#endif