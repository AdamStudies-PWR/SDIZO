//Klasa obs³uguj¹ca funkcje Kopca
#include "pch.h"
#include "Heap.h"
using namespace std;

//Funkcja zapisu
void Heap::save(string filename)
{
	if (used_size == 0) cout << "\nKopiec jest pusty!" << endl, _getche();
	else
	{
		if (tests) tester.StartfileCounter();
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << used_size << endl;
			for (int i = 0; i < used_size; i++)
			{
				plik << heap_tab[i] << endl;
			}
			plik.close();
			if (tests) addsave(tester.GetCounter());
		}
		else cout << "B³¹d zapisu" << endl, _getch();
	}
}
//Funkcja odczytu
void Heap::load(string filename)
{
	ifstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		int temp, data;
		if (!automatic) pop_all();
		if (tests) tester.StartfileCounter();
		plik >> temp;
		for (int i = 0; i < temp; i++)
		{
			plik >> data;
			push(data, false);
		}
		if (tests) addload(tester.GetCounter());
		if (!automatic) display();
		plik.close();
	}
	else cout << "B³¹d odczytu" << endl, _getch();
}
//Funkcja wyœwietlaj¹ca kopiec
void Heap::display()
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
	_getch();
}
//Funkcja dodaj¹ca elementy do kopca
void Heap::push(int val, bool show)
{
	if (tests && show) tester.StartCounter();
	if ((used_size + 1) == size) cout << "\nKopiec jest zape³niony" << endl, _getch();
	else
	{
		heap_tab[used_size] = val;
		used_size++;
		if (used_size != 1) fix_from_bottom(used_size - 1);
		if (tests && show) addchosen(tester.GetCounter());
		if (!automatic && show) display();
	}
}
//Funkcja dodaj¹ca losowo do podanego rozmiaru
void Heap::push_random(int lenght)
{
	used_size = 0;
	for (int i = 0; i < lenght; i++)
	{
		heap_tab[i] = rand();
		used_size++;
		if (i == 0) continue;
		fix_from_bottom(i);
	}
	if(!automatic) display();
}
//Funkcja usuwaj¹ca wybrany Element
void Heap::pop(int val)
{
	if (tests) tester.StartCounter();
	int index = find(val);
	if (index == -1) cout << "Nie ma takiego elementu" << endl, _getche();
	else
	{
		used_size--;
		if (used_size == 0) return;
		heap_tab[index] = heap_tab[used_size];
		fix_from_top(index);
		fix_from_bottom(index);
		if (tests) addpop(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja usuwaj¹ca wszytkie elementy w kopcu
void Heap::pop_all()
{
	if (tests) tester.StartCounter();
	used_size = 0;
	if (tests) addpopa(tester.GetCounter());
}
//Funkcja zwracaj¹ca rozmiar kopca
void Heap::getSize()
{
	cout << "\nObecny rozmiar kopca to: " << used_size;
	_getch();
}
//Funkcja szukaj¹ca elementu w kopcu
int Heap::find(int val)
{
	if (used_size == 0) return -1;
	if (tests) tester.StartCounter();
	for (int i = 0; i < used_size; i++)
	{
		if (val == heap_tab[i])
		{
			if (tests) addsearch(tester.GetCounter());
			return i;
		}
	}
	if (tests) addsearch(tester.GetCounter());
	return -1;
}
void Heap::switch_test() { tests = !tests; }
//Funkcja sprawdzaj¹ca kopiec od do³u
void Heap::fix_from_bottom(int index)
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
void Heap::fix_from_top(int index)
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
			kid1 = 2 * index + 1;
			kid2 = 2 * index + 2;
		}
		else return;
	}
}