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
	//Funkcja zapisu
	void save(string filename)
	{
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << used_size << endl;
			for (int i = 0; i < used_size; i++)
			{
				plik << heap_tab[i] << endl;
			}
		}
		else cout << "B³¹d zapisu" << endl, _getch();
	}
	//Funkcja odczytu
	void load(string filename)
	{
		ifstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			pop_all();
			plik >> used_size;
			for (int i = 0; i < used_size; i++)
			{
				plik >> heap_tab[i];
			}
		}
		else cout << "B³¹d odczytu" << endl, _getch();
	}
	//Funkcja wyœwietlaj¹ca kopiec
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
	//Funkcja dodaj¹ca elementy do kopca
	void push(int val)
	{
		if ((used_size + 1) == size) cout << "\nKopiec jest zape³niony" << endl, _getch();
		else
		{
			heap_tab[used_size] = val;
			used_size++;
			if (used_size != 1) fix_from_bottom(used_size - 1);
			display();
		}
	}
	//Funkcja dodaj¹ca losowo do podanego rozmiaru
	void push_random(int lenght)
	{
		for (int i = 0; i < lenght; i++)
		{
			heap_tab[i] = rand();
			used_size++;
			if (i == 0) continue;
			fix_from_bottom(i);
		}
		display();
	}
	//Funkcja usuwaj¹ca wybrany Element
	void pop(int val)
	{
		int index = find(val);
		if (index == -1) cout << "Nie ma takiego elementu" << endl, _getche();
		else
		{
			used_size--;
			if (used_size == 0) return;
			heap_tab[index] = heap_tab[used_size];
			fix_from_top(index);
			display();
		}
	}
	//Funkcja usuwaj¹ca wszytkie elementy w kopcu
	void pop_all()
	{
		used_size = 0;
	}
	//Funkcja zwracaj¹ca rozmiar kopca
	void getSize()
	{
		cout << "\nObecny rozmiar kopca to: " << used_size;
		_getch();
	}
	//Funkcja szukaj¹ca elementu w kopcu
	int find(int val)
	{
		for (int i = 0; i < used_size; i++)
		{
			if (val == heap_tab[i]) return i;
		}
		return -1;
	}
private:
	//Funkcja sprawdzaj¹ca kopioec od spodu
	void fix_from_bottom(int index)
	{
		int parent = (index - 1) / 2;
		int buffer;
		do
		{
			if (heap_tab[parent] < heap_tab[index])
			{
				buffer = heap_tab[parent];
				heap_tab[parent] = heap_tab[index];
				heap_tab[index] = buffer;
			}
			index = parent;
			parent = (index - 1) / 2;
		} while (parent != 0 || index != 0);
	}
	//Funkcja sprawdzaj¹ca kopiec od góry
	void fix_from_top(int index)
	{
		int kid1 = 2 * index + 1;
		int kid2 = 2 * index + 2;
		int greater, buffer;
		while (kid1 < used_size || kid2 < used_size)
		{
			if (kid2 >= used_size)
			{
				if (heap_tab[index] < heap_tab[kid1])
				{
					buffer = heap_tab[index];
					heap_tab[index] = heap_tab[kid1];
					heap_tab[kid1] = buffer;
				}
				return;
			}
			if (heap_tab[kid1] > heap_tab[kid2]) greater = kid1;
			else greater = kid2;
			if (heap_tab[greater] > heap_tab[index])
			{
				buffer = heap_tab[greater];
				heap_tab[greater] = heap_tab[index];
				heap_tab[index] = buffer;
				index = greater;
				kid1 =  2 * index + 1;
				kid2 = 2 * index + 2;
			}
			else return;
		}
	}
};