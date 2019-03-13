#pragma once
//Klasa obs³uguj¹ca funkcje Listy
#include "pch.h"
#include <iostream>

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
	//Funkcja wyœwietla liste na ekranie
	 void display()
	 {
		 cout <<"\nZawartoœæ listy: "<< endl;
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
	 //Funkcja dodaje nowy element na pocz¹tek listy
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
	 //Funkcja dodaj¹ca nowy element na koñcu listy
	 void push_chosen(int val)
	 {
		 int index;
		 system("cls");
		 cout << "Podaj pozycje na której chcesz wstawiæ liczbe: ";
		 cin >> index;
		 if (index == (size + 1)) push_tail(val);
		 else
		 {
			 if (index == 1) push_front(val);
			 else
			 {
				 ElemList *oldEl = find(index);
				 if (oldEl == nullptr)
				 {
					 cout << "\nNie mo¿na wstawiæ elementu na t¹ pozycje" << endl;
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
	 //Funkcja usuwaj¹ca wartoœæ z pocz¹tku
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
	 //Funkcja usuwaj¹ca z ogona
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
private:
	 //Funkcja zwracaj¹ca ogon
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
	 //Funkcja znajduj¹ca szukany element
	 ElemList *find(int index)
	 {
		 if (head == nullptr) return nullptr;
		 else
		 {
			 if (index >= size) return nullptr;
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
