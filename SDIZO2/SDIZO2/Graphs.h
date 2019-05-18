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

//Struktura obs�uguj�ca algorytm Prima
struct Prim
{
	int index = 0;
	int distance = 0;
	int prev = -1;
};

//Struktura obs�uguj�ca algorytm Kruskala
struct Kruskal
{
	int source;
	int weight;
	int target;
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
	//Zmiennie powi�zane z algorytmem Prima (cz�� dzielona z Kruskalem)
	Prim *solved;
	Prim *notSolved;
	int sol, nsol;
	int mst_size;
	//Zmienne powi�zane z algorytmem Kruskala
	Kruskal *line;
	Prim **tree;
	int t_size;
	int *sizes;
public:
	//Funkcja losowo tworz�ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
	//Funkcja obs�uguj�ca algorytm Dijsktry
	virtual void dijkstra(int start) = 0;
	//Funckja obs�uguj�ca algorytm Prima
	virtual void mst_Prim(int start) = 0;
	//Funkcja obs�uguj�ca algorytm Kruskala
	virtual void mst_Kruskal() = 0;
protected:
	//Funkcja sortuj�ca kraw�dzie
	void sort(Kruskal *target);
	//��czenie dw�ch zbior�w 
	void connect(int tab, int tab2);
	//Funckja drukuj�ca wynik dzia�ania algorytmu Disjkstry
	void display_Dijkstra(Dijkstra *list, int size);
	//Funckja drukuj�ca wynik dzia�ania algorytmu Prima
	void display_Prim(Prim *list, int size);
};

#endif