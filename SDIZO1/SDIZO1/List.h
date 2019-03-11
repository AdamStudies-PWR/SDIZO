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
	 // Funkcja zwraca aktualny rozmiar listy
	 void getSize()
	 {
		 cout << "\nObecny rozmiar listy to: " << size;
		 _getch();
	 }

	 void push_front(int val)
	 {
		 ElemList *newEl = new ElemList;
		 newEl->data = val;
		 newEl->next = head;
		 newEl->prev = nullptr;
		 head = newEl;
		 size++;
		 display();
	 }
};
