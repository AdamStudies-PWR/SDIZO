#pragma once
#ifndef Automatic_hpp
#define Automatic_hpp
#include "Tests.h"
#include "Matrix.h"
#include "List.h"

//Testowanie
void loop_tests(Matrix mat, List list, int size)
{
	system("cls");
	Tests testing;
	int *sizes = new int[32];
	for (int i = 0; i < 4; i++) sizes[i] = 0;
	for (int i = 4; i < 8; i++) sizes[i] = 100;
	for (int i = 8; i < 12; i++) sizes[i] = 200;
	for (int i = 12; i < 16; i++) sizes[i] = 300;
	for (int i = 16; i < 20; i++) sizes[i] = 400;
	for (int i = 20; i < 24; i++) sizes[i] = 500;
	for (int i = 24; i < 28; i++) sizes[i] = 600;
	for (int i = 28; i < 32; i++) sizes[i] = 700;
	int directed = size * (size - 1);
	int notdirected = (size * (size - 1)) / 2;
	for (int ii = 0; ii < 100; ii++)
	{
		cout << (ii + 1) << endl;
		//25% skierowany
		mat.create(size, 25, directed, true);
		list.create(size, 25, directed, true);
		testing.StartCounter();
		mat.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 0);
		testing.StartCounter();
		mat.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 1);
		testing.StartCounter();
		list.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 16);
		testing.StartCounter();
		list.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 17);
		//25% nieskierowany
		mat.create(size, 25, notdirected, false);
		list.create(size, 25, notdirected, false);
		testing.StartCounter();
		mat.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 2);
		testing.StartCounter();
		mat.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 3);
		testing.StartCounter();
		list.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 18);
		testing.StartCounter();
		list.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 19);
		//50% skierowany
		mat.create(size, 50, directed, true);
		list.create(size, 50, directed, true);
		testing.StartCounter();
		mat.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 4);
		testing.StartCounter();
		mat.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 5);
		testing.StartCounter();
		list.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 20);
		testing.StartCounter();
		list.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 21);
		//50% nieskierowany
		mat.create(size, 50, notdirected, false);
		list.create(size, 50, notdirected, false);
		testing.StartCounter();
		mat.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 6);
		testing.StartCounter();
		mat.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 7);
		testing.StartCounter();
		list.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 22);
		testing.StartCounter();
		list.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 23);
		//75% skierowany
		mat.create(size, 75, directed, true);
		list.create(size, 75, directed, true);
		testing.StartCounter();
		mat.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 8);
		testing.StartCounter();
		mat.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 9);
		testing.StartCounter();
		list.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 24);
		testing.StartCounter();
		list.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 25);
		//75% nieskierowany
		mat.create(size, 75, notdirected, false);
		list.create(size, 75, notdirected, false);
		testing.StartCounter();
		mat.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 10);
		testing.StartCounter();
		mat.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 11);
		testing.StartCounter();
		list.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 26);
		testing.StartCounter();
		list.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 27);
		//99% skierowany
		mat.create(size, 99, directed, true);
		list.create(size, 99, directed, true);
		testing.StartCounter();
		mat.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 12);
		testing.StartCounter();
		mat.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 13);
		testing.StartCounter();
		list.dijkstra(0);
		testing.adddijkstra(testing.GetCounter(), sizes, 28);
		testing.StartCounter();
		list.ford_bellman(0);
		testing.addford_bellman(testing.GetCounter(), sizes, 29);
		//75% nieskierowany
		mat.create(size, 75, notdirected, false);
		list.create(size, 75, notdirected, false);
		testing.StartCounter();
		mat.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 14);
		testing.StartCounter();
		mat.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 15);
		testing.StartCounter();
		list.mst_Prim(0);
		testing.addprim(testing.GetCounter(), sizes, 30);
		testing.StartCounter();
		list.mst_Kruskal();
		testing.addkruskal(testing.GetCounter(), sizes, 31);
	}
	cout << "\nTestowanie zakoñczone!" << endl;
	_getche();
	testing.save_data("mat25", 0);
	testing.save_data("mat55", 100);
	testing.save_data("mat75", 200);
	testing.save_data("mat99", 300);
	testing.save_data("list25", 400);
	testing.save_data("list55", 500);
	testing.save_data("list75", 600);
	testing.save_data("list99", 700);
}

#endif