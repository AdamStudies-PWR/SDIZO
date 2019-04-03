#pragma once
#ifndef TreeB_hpp
#define TreeB_hpp
#include "Tests.h"

//Struktura pojedynczego liœcia drzewa
struct Node
{
	_int64 data;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *parent = nullptr;
};

// Klasa obs³uguj¹ca funkcje drzewa binarnego
class TreeB: public Tests
{
private:
	//Zmienne
	int size = 0;
	Node *head = nullptr;
	double balancing[number];
	int bnumber = 0;
public:
	//Metody
	TreeB();
	void display();
	void save(string filename);
	void load(string filename);
	void push(int val, bool show);
	void push_random(int lenght);
	void pop_all();
	void pop_chosen(int val);
	void getSize();
	bool find(int val);
	void balance_tree(bool show);
	void switch_test();
	void save_data(string filename);
private:
	void displayloop(Node *out);
	void pushloop(Node *oldNode, int val, bool rise);
	void saveloop(Node *out, ofstream *plik);
	void pop_allloop(Node *oldNode);
	bool findloop(int val, Node *searched);
	Node *find_delete(int val, Node *searched);
	Node *find_successor(Node *node);
	Node *search_min(Node * node);
	void addbal(double numb);
};
#endif