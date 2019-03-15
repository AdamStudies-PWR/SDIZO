#pragma once
//Klasa obs³uguj¹ca funkcje Kopca
#include "pch.h"

class Heap
{
private:
	const static int size = 1000;
	int used_size = 0;
	int heap_tab[size];
public:
	//Funkcja wyœwietlaj¹ca kopiec
	void display()
	{
		used_size = 100;
		for (int i = 0; i < 100; i++)
		{
			heap_tab[i] = i;
		}
		system("cls");
		int level = 0;
		int limit = 1;
		int counter = 0;
		if (used_size == 0) cout << "Kopiec jest pusty" << endl, _getch();
		else
		{
			cout << level << ":";
			for (int i = 1; i < used_size; i++)
			{
				cout << " " << heap_tab[i - 1];
				counter++;
				if (counter == limit)
				{
					limit = limit * 2;
					counter = 0;
					level++;
					cout << "\n" << level << ":";
				}
			}
			_getch();
		}
	}
};