#pragma once
#ifndef List_hpp
#define List_hpp
#include "Tests.h"

//using namespace std;

//Struktura listy
struct ElemList
{
	int data;
	ElemList *next = nullptr, *prev = nullptr;
};

//Klasa obs�uguj�ca funkcje Listy
class List: public Tests
{
private:
	//Zmienne
	ElemList *head = nullptr;
public:
	//Metody
	void save(string filename);
	void load(string filename);
	void display();
	void getSize();
	void push_front(int val);
	void push_chosen(int val);
	void push_tail(int val);
	void pop_front();
	void pop_tail();
	void pop_chosen();
	void pop_all();
	int get_value(int val);
	void generate(int lenght);
	void switch_test();
private:
	ElemList *getTail();
	ElemList *find(int index);
};
#endif