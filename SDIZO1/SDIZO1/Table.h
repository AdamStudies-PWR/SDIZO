#pragma once
//Klasa obsługująca funkcje Tablicy
#include "pch.h"

class Table
{
private:
	int size = 0;
	int *pointer = nullptr;
public:
	//Funkcja wyświetlająca wartość
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
	//Funkcja dodająca elementy na początek tablicy
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
	//Funkcja zwracająca rozmar tablicy
	void getSize()
	{
		cout << "\nRozmiar tablicy to: " << size << endl;
		_getche();
	}
};