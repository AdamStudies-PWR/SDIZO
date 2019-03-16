#pragma once
//Klasa obs�uguj�ca funkcje Tablicy
#include "pch.h"

class Table
{
private:
	int size = 0;
	int *pointer = nullptr;
public:
	//Funkcja wy�wietlaj�ca warto��
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
	//Funkcja dodaj�ca elementy na pocz�tek tablicy
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
	//Funkcja zwracaj�ca rozmar tablicy
	void getSize()
	{
		cout << "\nRozmiar tablicy to: " << size << endl;
		_getche();
	}
};