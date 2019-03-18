#pragma once
// Klasa obs³uguj¹ca funkcje drzewa binarnego
#include "pch.h"

struct Node
{
	int data;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *parent = nullptr;
};

class TreeB
{
private:
	int size = 0;
	Node *head = nullptr;
public:
	//Funkcja wyœwietlaj¹ca drzewo (pocz¹tek)
	void display()
	{
		system("cls");
		if (head == nullptr) cout << "Drzewo jest puste!" << endl, _getche();
		else
		{
			cout << head->data << "(";
			if (head->left != nullptr) displayloop(head->left);
			else cout << "*";
			cout << ",";
			if (head->right != nullptr) displayloop(head->right);
			else cout << "*";
			cout << ")";
			_getche();
		}
	}
	//Funkcja obs³uguj¹ca zapis
	void save(string filename)
	{
		if (size == 0) cout << "\nLista jest pusta!" << endl, _getche();
		else
		{
			ofstream *plik = new ofstream(filename + ".txt");
			if (plik->good() == true)
			{
				*plik << size << endl;
				*plik << head->data << endl;
				if (head->left != nullptr) saveloop(head->left, plik);
				if (head->right != nullptr) saveloop(head->right, plik);
				plik->close();
				delete plik;
			}
			else cout << "B³¹d zapisu" << endl, _getch();
		}

	}
	//Funkjca odczytuj¹ca dane z pliku
	void load(string filename)
	{
		int ii;
		ifstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik >> size;
			for (int i = 0; i < (size - 1); i++)
			{
				plik >> ii;
				push(ii, false);
			}
			display();
			plik.close();
		}
		else cout << "B³¹d odczytu" << endl, _getch();
	}
	//Funkcja dodaj¹ca nowy element do drzewa (pocz¹tek)
	void push(int val, bool show)
	{
		if (head == nullptr)
		{
			Node *newNode = new Node;
			newNode->data = val;
			head = newNode;
			if(show) size++;
		}
		else
		{
			if (val < head->data)
			{
				if (head->left == nullptr)
				{
					Node *newNode = new Node;
					newNode->data = val;
					newNode->parent = head;
					head->left = newNode;
					if(show) size++;
				}
				else pushloop(head->left, val, show);
			}
			else
			{
				if (head->right == nullptr)
				{
					Node *newNode = new Node;
					newNode->data = val;
					newNode->parent = head;
					head->right = newNode;
					if(show) size++;
				}
				else pushloop(head->right, val, show);
			}
		}
		if(show) display();
	}
	//Funkcja zwraca aktualny rozmiar listy
	void getSize()
	{
		cout << "\nObecny rozmiar listy to: " << size;
		_getch();
	}
private:
	//Funkcja wyœwietlaj¹ca drzewo (dalsza rekurencyjna czêœæ)
	void displayloop(Node *out)
	{
		cout << out->data << "(";
		if (out->left != nullptr) displayloop(out->left);
		else cout << "*";
		cout << (",");
		if (out->right != nullptr) displayloop(out->right);
		else cout << "*";
		cout << ")";
	}
	//Funkcja dodaj¹ca nowy element od drzewa (dalsza czêœæ rekurencyjna)
	void pushloop(Node *oldNode, int val, bool rise)
	{
		if (val < oldNode->data)
		{
			if (oldNode->left == nullptr)
			{
				Node *newNode = new Node;
				newNode->data = val;
				newNode->parent = oldNode;
				oldNode->left = newNode;
				if(rise) size++;
			}
			else pushloop(oldNode->left, val, rise);
		}
		else
		{
			if (oldNode->right == nullptr)
			{
				Node *newNode = new Node;
				newNode->data = val;
				newNode->parent = oldNode;
				oldNode->right = newNode;
				if(rise) size++;
			}
			else pushloop(oldNode->right, val, rise);
		}
	}
	//Funkcja zapisu (rekurencyjna)
	void saveloop(Node *out, ofstream *plik)
	{
		*plik << out->data << endl;
		if (out->left != nullptr) saveloop(out->left, plik);
		if (out->right != nullptr) saveloop(out->right, plik);
	}
};