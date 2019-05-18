#pragma once
#ifndef Graphs_hpp
#define Graphs_hpp



//Struktura obs³uguj¹ca algorytm Dijkstry
struct Dijkstra
{
	int index = 0;
	int distance = -1;
	std::string prev = "";
};

//Struktura obs³uguj¹ca algorytm Prima
struct Prim
{
	int index = 0;
	int distance = 0;
	int prev = -1;
};

//Struktura obs³uguj¹ca algorytm Kruskala
struct Kruskal
{
	int source;
	int weight;
	int target;
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
	//Zmiennie powi¹zane z algorytmem Prima (czêœæ dzielona z Kruskalem)
	Prim *solved;
	Prim *notSolved;
	int sol, nsol;
	int mst_size;
	//Zmienne powi¹zane z algorytmem Kruskala
	Kruskal *line;
	Prim **tree;
	int t_size;
	int *sizes;
public:
	//Funkcja losowo tworz¹ca graf
	virtual void create(int nodes, double edges, double maxedges, bool directed) = 0;
	//Funkcja obs³uguj¹ca algorytm Dijsktry
	virtual void dijkstra(int start) = 0;
	//Funckja obs³uguj¹ca algorytm Prima
	virtual void mst_Prim(int start) = 0;
	//Funkcja obs³uguj¹ca algorytm Kruskala
	virtual void mst_Kruskal() = 0;
protected:
	//Funkcja sortuj¹ca krawêdzie
	void sort(Kruskal *target);
	//£¹czenie dwóch zbiorów 
	void connect(int tab, int tab2);
	//Funckja drukuj¹ca wynik dzia³ania algorytmu Disjkstry
	void display_Dijkstra(Dijkstra *list, int size);
	//Funckja drukuj¹ca wynik dzia³ania algorytmu Prima
	void display_Prim(Prim *list, int size);
};

#endif