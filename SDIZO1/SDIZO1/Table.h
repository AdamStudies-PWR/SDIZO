#pragma once
//Klasa obs³uguj¹ca funkcje Tablicy
#include "pch.h"

class Table
{
private:
	int size = 0;
	int *pointer = nullptr;
public:
	//Funkcja zapisu
	void save(string filename)
	{
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << size << endl;
			for (int i = 1; i < size; i++)
			{
				plik << pointer[i] << endl;
			}
		}
		else cout << "B³¹d zapisu" << endl, _getch();
	}
	//Funkcja wyœwietlaj¹ca wartoœæ
	void display()
	{
		system("cls");
		if (size == 0) cout << "Tablica jest pusta" << endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << " " << pointer[i];
			}
		}
		_getche();
	}
	//Funkcja dodaj¹ca elementy na pocz¹tek tablicy
	void push_front(int val)
	{
		size++;
		int *newpointer = new int[size];
		if (size != 1)
		{
			for (int i = 0; i < (size - 1); i++)
			{
				newpointer[i + 1] = pointer[i];
			}
		}
		newpointer[0] = val;
		delete pointer;
		pointer = newpointer;
		display();
	}
	//Funkcja dodaj¹ca wartoœæ na koñcu tablicy
	void push_back(int val)
	{
		size++;
		int *newpointer = new int[size];
		if (size == 1) newpointer[0] = val;
		else
		{
			for (int i = 0; i < (size - 1); i++)
			{
				newpointer[i] = pointer[i];
			}
			newpointer[size - 1] = val;
		}
		delete pointer;
		pointer = newpointer;
		display();
	}
	//Funkcja zwracaj¹ca rozmar tablicy
	void getSize()
	{
		cout << "\nRozmiar tablicy to: " << size << endl;
		_getche();
	}
};