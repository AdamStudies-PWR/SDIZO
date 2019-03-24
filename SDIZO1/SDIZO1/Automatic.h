#pragma once
#ifndef Automatic_hpp
#define Automatic_hpp
#include "List.h"
#include "Heap.h"
#include "Table.h"
#include "TreeB.h"
void auto_testing(List list, Heap heap, TreeB btree, Table table, int size)
{
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
		list.pop_chosen();
		list.push_chosen(44);
		list.get_value(44);
		heap.push_random(size);
		heap.save("test");
		heap.pop_all();
		heap.load("test");
		heap.push(44);
		heap.find(44);
		heap.pop(44);
		btree.push_random(size);
		btree.save("test");
		btree.pop_all();
		btree.load("test");
		btree.push(44, false);
		btree.find(44);
		btree.pop_chosen(44);
		btree.balance_tree(false);
		table.push_random(size);
		table.save("test");
		table.pop_all();
		table.load("test");
		table.pop_front();
		table.push_front(rand());
		table.pop_back();
		table.pop_chosen();
		table.push_chosen(44);
		table.find(44);
	}
	list.save_data("danelista");
	heap.save_data("danekopiec");
	btree.save_data("danedrzewo");
	table.save_data("danetablica");
}

#endif