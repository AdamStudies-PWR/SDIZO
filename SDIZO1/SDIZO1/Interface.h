#pragma once
#ifndef Interface_hpp
#define Interface_hpp
#include "List.h"
#include "Heap.h"
#include "Table.h"
#include "TreeB.h"

using namespace std;
// Klasa obs³uguj¹ interakcje z u¿ytkownikiem
class Interface
{
private:
	//Zmienne
	List lista;
	Heap heapa;
	Table tab;
	TreeB btree;
	bool test = false;
public:
	//Metody
	void mmenu();
private:
	char printmenu(string name, bool tree);
	void table();
	void list();
	void heap();
	void binarytree();
};
#endif