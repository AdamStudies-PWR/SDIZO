#pragma once
//Klasa obs³uguj¹ca funkcje Tablicy
#include "Tests.h"

class Table: public Tests
{
private:
	//zmienne
	int *pointer;
public:
	//metody
	Table();
	~Table();
	void save(string filename);
	void load(string filename);
	void display();
	void push_front(int val);
	void push_back(int val);
	void push_chosen(int val);
	void push_random(int lenght);
	void pop_front();
	void pop_back();
	void pop_chosen();
	void pop_all();
	void getSize();
	int find(int val);
	void switch_test();
};