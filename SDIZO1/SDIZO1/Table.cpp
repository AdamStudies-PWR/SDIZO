//Klasa obs³uguj¹ca funkcje Tablicy
#include "pch.h"
#include "Table.h"
using namespace std;

Table::Table()
{
	Tests();
	size = 0;
	pointer = NULL;
}
Table::~Table()
{
	if (pointer != NULL)
	{
		delete pointer;
	}
}
//Funkcja zapisu
void Table::save(string filename)
{
	if (size == 0) cout << "\nTablica jest pusta!" << endl, _getche();
	else
	{
		if (tests) tester.StartfileCounter();
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << size << endl;
			for (int i = 0; i < size; i++)
			{
				plik << pointer[i] << endl;
			}
			plik.close();
			if (tests) addsave(tester.GetCounter());
		}
		else cout << "B³¹d zapisu" << endl, _getch();
	}
}
//Funkcja odczytu
void Table::load(string filename)
{
	ifstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		plik >> size;
		if (tests) tester.StartfileCounter();
		int *newpointer = new int[size];
		for (int i = 0; i < size; i++)
		{
			plik >> newpointer[i];
		}
		if (tests) addload(tester.GetCounter());
		if (!automatic) pop_all();
		pointer = newpointer;
		if (!automatic) display();
		plik.close();
	}
	else cout << "B³¹d odczytu" << endl, _getch();
}
//Funkcja wyœwietlaj¹ca wartoœæ
void Table::display()
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
void Table::push_front(int val)
{
	if (tests) tester.StartCounter();
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
	if (tests) addfront(tester.GetCounter());
	if (!automatic) display();
}
//Funkcja dodaj¹ca wartoœæ na koñcu tablicy
void Table::push_back(int val)
{
	if (tests) tester.StartCounter();
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
	if (tests) addback(tester.GetCounter());
	if (!automatic) display();
}
//Funkcja dodaj¹ca elementy na wybrane miejsce
void Table::push_chosen(int val)
{
	int index;
	if (!automatic)
	{
		system("cls");
		cout << "Podaj pozycje na której chcesz wstawiæ liczbe: ";
		cin >> index;
	}
	else index = (rand() % (quantity - 2)) + 1;
	if (index == 0) push_front(val);
	else
	{
		if (index == (size)) push_back(val);
		else
		{
			if (index > size || index < 0) cout << "\nElement poza list¹" << endl, _getch();
			else
			{
				if (tests) tester.StartCounter();
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
					newpointer[i] = pointer[i - 1];
				}
				delete pointer;
				pointer = newpointer;
				if (tests) addchosen(tester.GetCounter());
				if (!automatic) display();
			}
		}
	}
}
//Funkcja dodaj¹ca elementy losowo
void Table::push_random(int lenght)
{
	size = lenght;
	int *newpointer = new int[lenght];
	for (int i = 0; i < lenght; i++)
	{
		newpointer[i] = rand();
	}
	delete pointer;
	pointer = newpointer;
	if (!automatic) display();
}
//Funkca usuwaj¹ca wartoœci z pocz¹tku
void Table::pop_front()
{
	if (size == 0) cout << "\nTablica jest pusta!" << endl, _getch();
	else
	{
		if (tests) tester.StartCounter();
		size--;
		int *newpointer = new int[size];
		for (int i = 0; i < size; i++)
		{
			newpointer[i] = pointer[i + 1];
		}
		delete pointer;
		pointer = newpointer;
		if (tests) addpopf(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja usuwaj¹ca z koñca
void Table::pop_back()
{
	if (size == 0) cout << "\nTablica jest pusta!" << endl, _getch();
	else
	{
		if (tests) tester.StartCounter();
		size--;
		int *newpointer = new int[size];
		for (int i = 0; i < size; i++)
		{
			newpointer[i] = pointer[i];
		}
		delete pointer;
		pointer = newpointer;
		if (tests) addpopl(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja usuwaj¹ca wybrane
void Table::pop_chosen()
{
	if (size == 0) cout << "\nTablica jest pusta!" << endl, _getch();
	else
	{
		int index;
		if (!automatic)
		{
			cout << "Podaj pozycje, z której chcesz usun¹æ liczbe: ";
			cin >> index;
		}
		else index = (rand() % (quantity - 2)) + 1;
		if (index == 0) pop_front();
		else
		{
			if (index == (size - 1)) pop_back();
			else
			{
				if (index >= size || index < 0) cout << "\nElement poza list¹" << endl, _getch();
				else
				{
					if (tests) tester.StartCounter();
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
					if (tests) addpop(tester.GetCounter());
					if (!automatic) display();
				}
			}
		}
	}
}
//Funkcja kasuj¹ca wszytko
void Table::pop_all()
{
	if (pointer != NULL)
	{
		if (tests) tester.StartCounter();
		int *newpointer = NULL;
		delete pointer;
		pointer = newpointer;
		size = 0;
		if (tests) addpopa(tester.GetCounter());
	}
}
//Funkcja zwracaj¹ca rozmar tablicy
void Table::getSize()
{
	cout << "\nRozmiar tablicy to: " << size << endl;
	_getche();
}
//Funkcja znajduj¹ca szukany element
int Table::find(int val)
{
	if (pointer == NULL) return -1;
	else
	{
		if (tests) tester.StartCounter();
		for (int i = 0; i < size; i++)
		{
			if (val == pointer[i])
			{
				if (tests) addsearch(tester.GetCounter());
				return i;
			}
		}
		if (tests) addsearch(tester.GetCounter());
		return -1;
	}
}
//W³¹czanie wy³¹czanie testowania
void Table::switch_test() { tests = !tests; }