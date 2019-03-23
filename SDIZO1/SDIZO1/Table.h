#pragma once
//Klasa obs�uguj�ca funkcje Tablicy
#include "pch.h"

class Table
{
private:
	int size;
	int *pointer;
public:
	Table()
	{
		size = 0;
		pointer = NULL;
	}
	~Table()
	{
		if (pointer != NULL)
		{
			delete pointer;
			//size = 0;
		}
	}
	//Funkcja zapisu
	void save(string filename)
	{
		if (size == 0) cout << "\nTablica jest pusta!" << endl, _getche();
		else
		{
			ofstream plik(filename + ".txt");
			if (plik.good() == true)
			{
				plik << size << endl;
				for (int i = 0; i < size; i++)
				{
					plik << pointer[i] << endl;
				}
				plik.close();
			}
			else cout << "B��d zapisu" << endl, _getch();
		}
	}
	//Funkcja odczytu
	void load(string filename)
	{
		ifstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik >> size;
			int *newpointer = new int[size];
			for (int i = 0; i < size; i++)
			{
				plik >> newpointer[i];
			}
			pop_all();
			pointer = newpointer;
			display();
			plik.close();
		}
		else cout << "B��d odczytu" << endl, _getch();
	}
	//Funkcja wy�wietlaj�ca warto��
	void display()
	{
		system("cls");
		if (size == 0) cout << "Tablica jest pusta" << endl;
		else
		{
			for (int i = 0; i < size; i++)
			{
				cout << " " <<pointer[i];
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
	//Funkcja dodaj�ca warto�� na ko�cu tablicy
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
	//Funkcja dodaj�ca elementy na wybrane miejsce
	void push_chosen(int val)
	{
		int index;
		system("cls");
		cout << "Podaj pozycje na kt�rej chcesz wstawi� liczbe: ";
		cin >> index;
		if (index == 0) push_front(val);
		else
		{
			if (index == (size)) push_back(val);
			else
			{
				if (index > size || index < 0) cout << "\nElement poza list�" << endl, _getch();
				else
				{
					size++;
					int i = 0;
					int *newpointer = new int[size + 1];
					for (i; i < index; i++)
					{
						newpointer[i] = pointer[i];
					}
					newpointer[index] = val;
					i = i + 1;
					for (i; i < (size); i++)
					{
						newpointer[i] = pointer[i-1];
					}
					delete pointer;
					pointer = newpointer;
					display();
				}
			}
		}
	}
	//Funkcja dodaj�ca elementy losowo
	void push_random(int lenght)
	{
		size = lenght;
		int *newpointer = new int[lenght];
		for (int i = 0; i < lenght; i++)
		{
			newpointer[i] = rand();
		}
		delete pointer;
		pointer = newpointer;
		display();
	}
	//Funkca usuwaj�ca warto�ci z pocz�tku
	void pop_front()
	{
		if (size == 0) cout << "\nTablica jest pusta!" << endl, _getch();
		else
		{
			size--;
			int *newpointer = new int[size];
			for (int i = 0; i < size; i++)
			{
				newpointer[i] = pointer[i + 1];
			}
			delete pointer;
			pointer = newpointer;
			display();
		}
	}
	//Funkcja usuwaj�ca z ko�ca
	void pop_back()
	{
		if (size == 0) cout << "\nTablica jest pusta!" << endl, _getch();
		else
		{
			size--;
			int *newpointer = new int[size];
			for (int i = 0; i < size; i++)
			{
				newpointer[i] = pointer[i];
			}
			delete pointer;
			pointer = newpointer;
			display();
		}
	}
	//Funkcja usuwaj�ca wybrane
	void pop_chosen()
	{
		if(size == 0) cout << "\nTablica jest pusta!" << endl, _getch();
		else
		{
			int index;
			system("cls");
			cout << "Podaj pozycje z kt�rej chcesz usun�� liczbe: ";
			cin >> index;
			if (index == 0) pop_front();
			else
			{
				if (index == (size - 1)) pop_back();
				else
				{
					if (index >= size || index < 0) cout << "\nElement poza list�" << endl, _getch();
					else
					{
						size--;
						int i = 0;
						int *newpointer = new int[size + 1];
						for (i; i < index; i++)
						{
							newpointer[i] = pointer[i];
						}
						i = i + 1;
						for (i; i < (size + 1); i++)
						{
							newpointer[i - 1] = pointer[i];
						}
						delete pointer;
						pointer = newpointer;
						display();
					}
				}
			}
		}
	}
	//Funkcja kasuj�ca wszytko
	void pop_all()
	{
		if (pointer != NULL)
		{
			int *newpointer = NULL;
			delete pointer;
			pointer = newpointer;
			size = 0;
		}
	}
	//Funkcja zwracaj�ca rozmar tablicy
	void getSize()
	{
		cout << "\nRozmiar tablicy to: " << size << endl;
		_getche();
	}
	//Funkcja znajduj�ca szukany element
	int find(int val)
	{
		if (pointer == NULL) return -1;
		else
		{
			for (int i = 0; i < size; i++)
			{
				if (val == pointer[i]) return i;
			}
			return -1;
		}
	}
};