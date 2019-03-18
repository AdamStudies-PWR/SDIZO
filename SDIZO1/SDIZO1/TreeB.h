#pragma once
// Klasa obs�uguj�ca funkcje drzewa binarnego
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
	//Funkcja wy�wietlaj�ca drzewo (pocz�tek)
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
	void save(string filename)
	{
		if (size == 0) cout << "\nLista jest pusta!" << endl, _getche();
		else
		{

		}
	}
	//Funkcja dodaj�ca nowy element do drzewa (pocz�tek)
	void push(int val)
	{
		if (head == nullptr)
		{
			Node *newNode = new Node;
			newNode->data = val;
			head = newNode;
			size++;
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
					size++;
				}
				else pushloop(head->left, val);
			}
			else
			{
				if (head->right == nullptr)
				{
					Node *newNode = new Node;
					newNode->data = val;
					newNode->parent = head;
					head->right = newNode;
					size++;
				}
				else pushloop(head->right, val);
			}
		}
		display();
	}
	//Funkcja zwraca aktualny rozmiar listy
	void getSize()
	{
		cout << "\nObecny rozmiar listy to: " << size;
		_getch();
	}
private:
	//Funkcja wy�wietlaj�ca drzewo (dalsza rekurencyjna cz��)
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
	//Funkcja dodaj�ca nowy element od drzewa (dalsza cz�� rekurencyjna)
	void pushloop(Node *oldNode, int val)
	{
		if (val < oldNode->data)
		{
			if (oldNode->left == nullptr)
			{
				Node *newNode = new Node;
				newNode->data = val;
				newNode->parent = oldNode;
				oldNode->left = newNode;
				size++;
			}
			else pushloop(oldNode->left, val);
		}
		else
		{
			if (oldNode->right == nullptr)
			{
				Node *newNode = new Node;
				newNode->data = val;
				newNode->parent = oldNode;
				oldNode->right = newNode;
				size++;
			}
			else pushloop(oldNode->right, val);
		}
	}
};