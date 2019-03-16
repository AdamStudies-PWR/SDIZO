#pragma once
//Klasa obs�uguj�ca funkcje Kopca
#include "pch.h"

class Heap
{
private:
	const static int size = 1000;
	int used_size = 0;
	int heap_tab[size];
public:
	//Funkcja wy�wietlaj�ca kopiec
	void display()
	{
		system("cls");
		int level = 0;
		int limit = 1;
		int counter = 0;
		if (used_size == 0) cout << "Kopiec jest pusty" << endl, _getch();
		else
		{
			cout << level << ":";
			for (int i = 0; i < used_size; i++)
			{
				cout << " " << heap_tab[i];
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
	//Funkcja dodaj�ca elementy do kopca
	void push(int val)
	{
		if ((used_size + 1) == size) cout << "\nKopiec jest zape�niony" << endl, _getch();
		else
		{
			heap_tab[used_size] = val;
			used_size++;
			if (used_size != 1) fix_from_bottom();
			display();
		}
	}
	//Funkcja zwracaj�ca rozmiar kopca
	void getSize()
	{
		cout << "\nObecny rozmiar kopca to: " << used_size;
		_getch();
	}
private:
	//Funkcja sprawdzaj�ca kopioec od spodu
	void fix_from_bottom()
	{
		cout << "wsumiue to tylko taki test czy wchodzi";
		_getch();
	}
};