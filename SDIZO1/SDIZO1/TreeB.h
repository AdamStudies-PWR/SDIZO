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
			pop_all();
			plik >> size;
			for (int i = 0; i < (size - 1); i++)
			{
				plik >> ii;
				push(ii, false);
			}
			balance_tree();
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
	//Funkcja losowa wype³niaj¹ca drzewo
	void push_random(int lenght)
	{
		pop_all();
		for (int i = 0; i < lenght; i++)
		{
			push(rand(), false);
		}
		display();
	}
	//Funkcja usuwaj¹ca ca³e drzewo
	void pop_all()
	{
		if (head != nullptr)
		{
			Node *oldNode = head;
			size = 0;
			head = nullptr;
			if (oldNode->left != nullptr) pop_allloop(oldNode->left);
			if (oldNode->right != nullptr) pop_allloop(oldNode->right);
			delete oldNode;
		}
	}
	//Funkcja usuwaj¹ca wybrany element z drzewa
	void pop_chosen(int val)
	{
		if (head == nullptr) 
		{
			cout << "\nDrzewo jest puste!" << endl;
			_getche();
			return;
		}
		Node *deleteNode = find_delete(val, head);
		if (deleteNode == nullptr) cout << "\nNie znaleziono takiego elementu w drzewie" << endl, _getche();
		else
		{
			Node *y, *x;
			if((deleteNode->left == nullptr) || (deleteNode->right == nullptr)) y = deleteNode;
			else y = find_successor(deleteNode);
			if (y->left != nullptr) x = y->left;
			else x = y->right;
			if (x != nullptr) x->parent = y->parent;
			if (y->parent == nullptr) head = x;
			else
			{
				if (y == y->parent->left) y->parent->left = x;
				else y->parent->right = x;
			}
			if (y != deleteNode)
			{
				deleteNode->data = y->data;
				delete y;
			}
			size--;
			display();
		}
	}
	//Funkcja zwraca aktualny rozmiar listy
	void getSize()
	{
		cout << "\nObecny rozmiar listy to: " << size;
		_getch();
	}
	//Funkcja sprawdzaj¹ca czy podana wartoœæ jest w fukcji
	bool find(int val)
	{
		bool found;
		if (head == nullptr) return false;
		else
		{
			if (head->data == val) return true;
			if (head->left != nullptr)
			{
				found = findloop(val, head->left);
				if (found) return found;
			}
			if (head->right != nullptr) 
			{
				found = findloop(val, head->right);
				if (found) return found;
			}
			return false;
		}
	}
	// Równowa¿enie drzewa - algorytm DSW
	void balance_tree()
	{
		//Etap 1 - prostowanie
		Node *temp = head;
		while (temp != nullptr)
		{
			if (temp->left != nullptr)
			{
				if (temp->parent == nullptr) head = temp->left;
				else temp->parent->right = temp->left;
				temp->left->parent = temp->parent;
				temp->parent = temp->left;
				temp->left = temp->left->right;
				temp->parent->right = temp;
				temp = temp->parent;
			}
			else temp = temp->right;
		}
		//Etap 2 - równowa¿enie
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
	//Funkcja usuwaj¹ca rekrencyjnie ca³e drzewo
	void pop_allloop(Node *oldNode)
	{
		if (oldNode->left != nullptr) pop_allloop(oldNode->left);
		if (oldNode->right != nullptr) pop_allloop(oldNode->right);
		delete oldNode;
	}
	//Funkcja szukaj¹ca rekrencyjnie w drzewie
	bool findloop(int val, Node *searched)
	{
		bool found;
		if (searched->data == val) return true;
		if (searched->left != nullptr)
		{
			found = findloop(val, searched->left);
			if (found) return found;
		}
		if (searched->right != nullptr)
		{
			found = findloop(val, searched->right);
			if (found) return found;
		}
		return false;
	}
	//Funkcja znajduj¹ca usuwany element
	Node *find_delete(int val, Node *searched)
	{
		Node *temp;
		if (searched->data == val) return searched;
		if (searched->left != nullptr)
		{
			temp = find_delete(val, searched->left);
			if (temp != nullptr) return temp;
		}
		if (searched->right != nullptr)
		{
			temp = find_delete(val, searched->right);
			if (temp != nullptr) return temp;
		}
		return nullptr;
	}
	//Funkcja znajduj¹ca nastêpce
	Node *find_successor(Node *node)
	{
		if (node->right != nullptr) return search_min(node->right);
		Node *temp = node->parent;
		while (temp != nullptr && temp->left != node)
		{
			node = temp;
			temp = temp->parent;
		}
		return node;
	}
	//Funkcja szukaj¹ca minimum w drzewie
	Node *search_min(Node * node)
	{
		while (node->left != nullptr)
		{
			node = node->left;
		}
		return node;
	}
};