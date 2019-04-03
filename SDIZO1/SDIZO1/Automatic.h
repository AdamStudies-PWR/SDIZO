#pragma once
#ifndef Automatic_hpp
#define Automatic_hpp
#include "List.h"
#include "Heap.h"
#include "Table.h"
#include "TreeB.h"
//Funkcja przeprowadzaj¹ce automatyczne testy struktur
void auto_testing(List list, Heap heap, TreeB btree, Table table, int size)
{
	int ii;
	for (int i = 0; i < 100; i++)
	{
		cout << i  << endl;
		list.generate(size);
		list.save("test");
		list.pop_all();
		list.load("test");
		list.pop_front();
		list.push_front(rand());
		list.pop_tail();
		list.push_tail(rand());
		list.pop_chosen();
		ii = rand();
		list.push_chosen(ii);
		list.get_value(ii);
		heap.push_random(size);
		heap.save("test");
		heap.pop_all();
		heap.load("test");
		ii = rand();
		heap.push(ii, true);
		heap.find(ii);
		heap.pop(ii);
		btree.push_random(size);
		btree.save("test");
		btree.pop_all();
		btree.load("test");
		ii = rand();
		btree.push(ii, true);
		btree.find(ii);
		btree.pop_chosen(ii);
		btree.balance_tree(false);
		table.push_random(size);
		table.save("test");
		table.pop_all();
		table.load("test");
		table.pop_front();
		table.push_front(rand());
		table.pop_back();
		table.push_back(rand());
		table.pop_chosen();
		ii = rand();
		table.push_chosen(ii);
		table.find(ii);
	}
	list.save_data("danelista");
	heap.save_data("danekopiec");
	btree.save_data("danedrzewo");
	table.save_data("danetablica");
}

#endif