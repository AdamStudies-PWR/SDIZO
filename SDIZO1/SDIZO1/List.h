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
};
