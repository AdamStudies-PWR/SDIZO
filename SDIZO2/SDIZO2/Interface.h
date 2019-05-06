#pragma once
#ifndef Interface_hpp
#define Interface_hpp
// Kasa obs³uguj¹ca wszsytkie interakcje u¿ytkownika z aplikacj¹
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
public:
	//metody
	//G³ówne menu propgramu
	void main_menu();
private:
	//Menu struktury
	char structure_menu(string name);
	//Obs³uga funkcji dla implementacji macierzowej
	void matrix();
	//Obs³uga losowego tworzenia grafu
	void create_ui(Graphs *g);
	//Obs³uga funkcji dla implementacji listwoej
	void glist();
};

#endif