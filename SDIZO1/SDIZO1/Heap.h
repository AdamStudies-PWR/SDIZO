#pragma once
#ifndef Heap_hpp
#define Heap_hpp
#include "Tests.h"

//Klasa obs³uguj¹ca funkcje Kopca
class Heap: public Tests
{
private:
	//Zmienne
	const static int size = 30000;
	int used_size = 0;
	int heap_tab[size];
public:
	//Metody
	void save(string filename);
	void load(string filename);
	void display();
	void push(int val, bool show);
	void push_random(int lenght);
	void pop(int val);
	void pop_all();
	void getSize();
	int find(int val);
	void switch_test();
private:
	void fix_from_top(int index);
	void fix_from_bottom(int index);
};
#endif