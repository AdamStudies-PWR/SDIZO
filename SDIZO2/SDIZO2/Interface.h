#pragma once
#ifndef Interface_hpp
#define Interface_hpp
// Kasa obs�uguj�ca wszsytkie interakcje u�ytkownika z aplikacj�
#include "Matrix.h"
#include "List.h"

using namespace std;

class Interface
{
private:
	//zmienne
	Matrix mat;
	List list;
	bool directed = false;
	bool exists = false;
	int size_n;
public:
	//metody
	//G��wne menu propgramu
	void main_menu();
private:
	//Menu struktury
	char structure_menu(string name);
	//Obs�uga funkcji dla implementacji macierzowej
	void matrix();
	//Obs�uga losowego tworzenia grafu
	void create_ui(Graphs *g);
	//Obs�uga funkcji dla implementacji listwoej
	void glist();
	//Obs�uga algorytmu Dijsktry
	void dijkstra_ui(Graphs *g);
	//Obs�uga algorytmu Prima
	void prim_ui(Graphs * g);
	//Obs�uga algorytmu Kruskala
	void kruskal_ui(Graphs *g);
};

#endif