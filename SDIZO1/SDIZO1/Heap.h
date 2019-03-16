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
		else cout << "B��d zapisu" << endl, _getch();
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
		else cout << "B��d odczytu" << endl, _getch();
	}
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
			if (used_size != 1) fix_from_bottom(used_size - 1);
			display();
		}
	}
	//Funkcja usuwaj�ca wszytkie elementy w kopcu
	void pop_all()
	{
		used_size = 0;
	}
	//Funkcja zwracaj�ca rozmiar kopca
	void getSize()
	{
		cout << "\nObecny rozmiar kopca to: " << used_size;
		_getch();
	}
private:
	//Funkcja sprawdzaj�ca kopioec od spodu
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
	//Funkcja sprawdzaj�ca kopiec od g�ry
	void fix_from_top(int index)
	{
		//TODO
	}
};