#pragma once
#ifndef List_hpp
#define List_hpp
//Klasa obs�uguj�ca listow� reprezentacje graf�w
#include "Graphs.h"

struct Node;
struct Edge;

struct Node
{
	int index = 0;
	Edge *head = nullptr;
	Node *next = nullptr;
	Node *prev = nullptr;
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
	//Funkcja losowo tworz�ca graf
	void create(int nodes, double edges, int maxedges, bool directed);
	//Funkcja wy�wietlaj�ca graf//Funkcja wy�wietlaj�ca graf
	void display();
private:
	//Funkcja towrz�ca drzewo rozpinaj�ce dla nieskierowanego
	void spanningtree(int *visited);
};

#endif