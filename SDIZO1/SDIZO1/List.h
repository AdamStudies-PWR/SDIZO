#pragma once
//Klasa obs�uguj�ca funkcje Listy
#include "pch.h"

using namespace std;

struct ElemList
{
	int data;
	ElemList *next = nullptr, *prev = nullptr;
};

class List
{
private:
	int size = 0;
	ElemList *head = nullptr;
public:
	//Funkcja zapisu
	void save(string filename)
	{
		if (size == 0) cout << "\nLista jest pusta!" << endl, _getche();
		else
		{
			ofstream plik(filename + ".txt");
			if (plik.good() == true)
			{
				plik << size << endl;
				ElemList *out = head;
				while (out != nullptr)
				{
					plik << out->data << endl;
					out = out->next;
				}
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
			pop_all();
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
			display();
		}
		else cout << "B��d odczytu" << endl, _getch();
	}
	//Funkcja wy�wietla liste na ekranie
	 void display()
	 {
		 cout <<"\nZawarto�� listy: "<< endl;
		 if (head == nullptr) cout << "\nLista jest pusta!" << endl , _getch();
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
	 void getSize()
	 {
		 cout << "\nObecny rozmiar listy to: " << size;
		 _getch();
	 }
	 //Funkcja dodaje nowy element na pocz�tek listy
	 void push_front(int val)
	 {
		 ElemList *newEl = new ElemList;
		 newEl->data = val;
		 newEl->next = head;
		 newEl->prev = nullptr;
		 if(head != nullptr) head->prev = newEl;
		 head = newEl;
		 size++;
		 display();
	 }
	 //Funkcja dodajaca element na dowolnie wynranej pozycji
	 void push_chosen(int val)
	 {
		 int index;
		 system("cls");
		 cout << "Podaj pozycje na kt�rej chcesz wstawi� liczbe: ";
		 cin >> index;
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
				 display();
			 }
		 }
	 }
	 //Funkcja dodaj�ca nowy element na ko�cu listy
	 void push_tail(int val)
	 {
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
			 display();
		 }
	 }
	 //Funkcja usuwaj�ca warto�� z pocz�tku
	 void pop_front()
	 {
		 if (head == nullptr) cout << "\nLista jest pusta!" << endl, _getch();
		 else
		 {
			 ElemList *temp = head;
			 head = head->next;
			 if (head != nullptr) head->prev = nullptr;
			 delete temp;
			 size--;
			 display();
		 }
	 }
	 //Funkcja usuwaj�ca z ogona
	 void pop_tail()
	 {
		 ElemList *tail = getTail();
		 ElemList *temp = tail->prev;
		 if(tail == nullptr) cout << "\nLista jest pusta!" << endl, _getch();
		 else
		 {
			 if(temp != nullptr) temp->next = nullptr;
			 else head = nullptr;
			 delete tail;
			 size--;
			 display();
		 }
	 }
	 //Funkcja usuwaj�ca dowolny element
	 void pop_chosen()
	 {
		 int index;
		 system("cls");
		 cout << "Podaj pozycje, z kt�rej chcesz usun�� liczbe: ";
		 cin >> index;
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
				 display();
			 }
		 }
	 }
	 //Funkcja usuwaj�ca wszytkie elementy listy
	 void pop_all()
	 {
		 ElemList *element;
		 while (head != nullptr)
		 {
			element = head;
			head = head->next;
			delete element;
			size--;
		 }
	 }
	 //Funkcja zwracaj�ca warto�� na wskazanej prze� u�ytkownika pozycji
	 void get_value()
	 {
		 int index;
		 system("cls");
		 cout << "Podaj pozycje, z kt�rej chcesz uzyska� warto��: ";
		 cin >> index;
		 if (index > size || index <= 0)
		 {
			 cout << "\nNie mo�na znale�� elementu na podanej pozycji" << endl;
			 _getch();
			 return;
		 }
		 else
		 {
			 ElemList *searched = find(index);
			 if(searched == nullptr) 
			 {
				 cout << "\nWyst�pi� nieoczekiwany b��d" << endl;
				 _getch();
				 return;
			 }
			 else cout << "\n " << searched->data << endl, _getch();
		 }
	 }
	 //Funkcja tworzy lsite o podanym rozmiarze
	 void generate(int lenght)
	 {
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
		 display();
	 }
private:
	 //Funkcja zwracaj�ca ogon
	 ElemList *getTail()
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
	 ElemList *find(int index)
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
};
