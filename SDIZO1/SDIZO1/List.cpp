//Klasa obs�uguj�ca funkcje Listy
#include "pch.h"
#include "List.h"

using namespace std;

//Funkcja zapisu
void List:: save(string filename)
{
	if (size == 0) cout << "\nLista jest pusta!" << endl, _getche();
	else
	{
		if (tests) tester.StartfileCounter();
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << size << endl;
			ElemList *out = getTail();
			while (out != nullptr)
			{
				plik << out->data << endl;
				out = out->prev;
			}
			plik.close();
			if (tests) addsave(tester.GetCounter());
		}
		else cout << "B��d zapisu" << endl, _getch();
	}
}
//Funkcja odczytu
void List:: load(string filename)
{
	ifstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		if (!automatic) pop_all();
		if (tests) tester.StartfileCounter();
		plik >> size;
		for (int i = 0; i < size; i++)
		{
			ElemList *newEl = new ElemList;
			plik >> newEl->data;
			newEl->next = head;
			newEl->prev = nullptr;
			if (head != nullptr) head->prev = newEl;
			head = newEl;
		}
		if (tests) addload(tester.GetCounter());
		if (!automatic) display();
		plik.close();
	}
	else cout << "B��d odczytu" << endl, _getch();
}
//Funkcja wy�wietla liste na ekranie
void List:: display()
{
	cout << "\nZawarto�� listy: " << endl;
	if (head == nullptr) cout << "\nLista jest pusta!" << endl, _getch();
	else
	{
		ElemList *out = head;
		while (out != nullptr)
		{
			cout << " " << out->data;
			out = out->next;
		}
		_getch();
	}
}
//Funkcja zwraca aktualny rozmiar listy
void List::getSize()
{
	cout << "\nObecny rozmiar listy to: " << size;
	_getch();
}
//Funkcja dodaje nowy element na pocz�tek listy
void List:: push_front(int val)
{
	if (tests) tester.StartCounter();
	ElemList *newEl = new ElemList;
	newEl->data = val;
	newEl->next = head;
	newEl->prev = nullptr;
	if (head != nullptr) head->prev = newEl;
	head = newEl;
	size++;
	if (tests) addfront(tester.GetCounter());
	if (!automatic) display();
}
//Funkcja dodajaca element na dowolnie wybranej pozycji
void List::push_chosen(int val)
{
	int index;
	if (!automatic)
	{
		system("cls");
		cout << "Podaj pozycje na kt�rej chcesz wstawi� liczbe: ";
		cin >> index;
	}
	else index = (rand() % (quantity - 2)) + 1;
	if (index == (size + 1)) push_tail(val);
	else
	{
		if (index <= 0)
		{
			cout << "\nPozycje indeksowane od 1" << endl;
			_getch();
			return;
		}
		if (index == 1) push_front(val);
		else
		{
			if (tests) tester.StartCounter();
			ElemList *oldEl = find(index);
			if (oldEl == nullptr)
			{
				cout << "\nNie mo�na wstawi� elementu na t� pozycje" << endl;
				_getch();
				return;
			}
			ElemList *newEl = new ElemList;
			newEl->data = val;
			newEl->prev = oldEl->prev;
			newEl->next = oldEl;
			oldEl->prev->next = newEl;
			oldEl->prev = newEl;
			size++;
			if (tests) addchosen(tester.GetCounter());
			if (!automatic) display();
		}
	}
}
//Funkcja dodaj�ca nowy element na ko�cu listy
void List::push_tail(int val)
{
	if (tests) tester.StartCounter();
	ElemList *tail = getTail();
	if (tail == nullptr) push_front(val);
	else
	{
		ElemList *newEl = new ElemList;
		newEl->data = val;
		newEl->next = nullptr;
		newEl->prev = tail;
		tail->next = newEl;
		size++;
		if (tests) addback(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja usuwaj�ca warto�� z pocz�tku
void List::pop_front()
{
	if (head == nullptr) cout << "\nLista jest pusta!" << endl, _getch();
	else
	{
		if (tests) tester.StartCounter();
		ElemList *temp = head;
		head = head->next;
		if (head != nullptr) head->prev = nullptr;
		delete temp;
		size--;
		if (tests) addpopf(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja usuwaj�ca z ogona
void List::pop_tail()
{
	if (tests) tester.StartCounter();
	ElemList *tail = getTail();
	ElemList *temp = tail->prev;
	if (tail == nullptr) cout << "\nLista jest pusta!" << endl, _getch();
	else
	{
		if (temp != nullptr) temp->next = nullptr;
		else head = nullptr;
		delete tail;
		size--;
		if (tests) addpopl(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja usuwaj�ca dowolny element
void List::pop_chosen()
{
	int index;
	if (!automatic)
	{
		system("cls");
		cout << "Podaj pozycje, z kt�rej chcesz usun�� liczbe: ";
		cin >> index;
	}
	else index = (rand() % (quantity - 2)) + 1;
	if (index > size || index <= 0)
	{
		cout << "\nNie mo�na usn�� elementu na podanej pozycji" << endl;
		_getch();
		return;
	}
	if (index == 1) pop_front();
	else
	{
		if (index == size) pop_tail();
		else
		{
			if (tests) tester.StartCounter();
			ElemList *oldEl = find(index);
			if (oldEl == nullptr)
			{
				cout << "\nWyst�pi� niespodziewany b��d" << endl;
				_getch();
				return;
			}
			oldEl->prev->next = oldEl->next;
			oldEl->next->prev = oldEl->prev;
			size--;
			delete oldEl;
			if (tests) addpop(tester.GetCounter());
			if (!automatic) display();
		}
	}
}
//Funkcja usuwaj�ca wszytkie elementy listy
void List::pop_all()
{
	if (tests) tester.StartCounter();
	ElemList *element;
	while (head != nullptr)
	{
		element = head;
		head = head->next;
		delete element;
		size--;
	}
	if (tests) addpopa(tester.GetCounter());
}
//Funkcja zwracaj�ca warto�� na wskazanej prze� u�ytkownika pozycji
int List::get_value(int val)
{
	if (tests) tester.StartCounter();
	int i = 0;
	ElemList *searched = head;
	while (searched != nullptr)
	{
		if (searched->data == val)
		{
			if (tests) addsearch(tester.GetCounter());
			return i;
		}
		i++;
		searched = searched->next;
	}
	if (tests) addsearch(tester.GetCounter());
	return -1;
}
//Funkcja tworzy lsite o podanym rozmiarze
void List::generate(int lenght)
{
	pop_all();
	for (int i = 0; i < lenght; i++)
	{
		ElemList *newEl = new ElemList;
		newEl->data = rand();
		newEl->next = head;
		newEl->prev = nullptr;
		if (head != nullptr) head->prev = newEl;
		head = newEl;
		size++;
	}
	if (!automatic) display();
}
//W��czanie wy��czanie testowania
void List::switch_test() { tests = !tests; }
//Funkcja zwracaj�ca ogon
ElemList* List:: getTail()
{
	if (head == nullptr) return nullptr;
	else
	{
		ElemList *tail = head;
		while (tail->next != nullptr)
		{
			tail = tail->next;
		}
		return tail;
	}
}
//Funkcja znajduj�ca szukany element
ElemList* List:: find(int index)
{
	if (head == nullptr) return nullptr;
	else
	{
		if (index > size) return nullptr;
		else
		{
			ElemList *searched = head;
			for (int i = 1; i < index; i++)
			{
				searched = searched->next;
			}
			return searched;
		}
	}
}