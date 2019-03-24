// Klasa obs³uguj¹ca funkcje drzewa binarnego
#include "pch.h"
#include "TreeB.h"
using namespace std;

//konstruktor drzewa
TreeB::TreeB()
{
	Tests();
	for (int i = 0; i < number; i++) balancing[i] = 0;
}
//Funkcja wyœwietlaj¹ca drzewo (pocz¹tek)
void TreeB::display()
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
void TreeB::save(string filename)
{
	if (size == 0) cout << "\nLista jest pusta!" << endl, _getche();
	else
	{
		if (tests) tester.StartCounter();
		ofstream *plik = new ofstream(filename + ".txt");
		if (plik->good() == true)
		{
			*plik << size << endl;
			*plik << head->data << endl;
			if (head->left != nullptr) saveloop(head->left, plik);
			if (head->right != nullptr) saveloop(head->right, plik);
			plik->close();
			if (tests) addsave(tester.GetCounter());
			delete plik;
		}
		else cout << "B³¹d zapisu" << endl, _getch();
	}
}
//Funkjca odczytuj¹ca dane z pliku
void TreeB::load(string filename)
{
	int ii, temp;
	ifstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		if (!automatic) pop_all();
		if (tests) tester.StartCounter();
		plik >> temp;
		for (int i = 0; i < temp; i++)
		{
			plik >> ii;
			size++;
			push(ii, false);
		}
		if (tests) addload(tester.GetCounter());
		if (!automatic) display();
		plik.close();
	}
	else cout << "B³¹d odczytu" << endl, _getch();
}
//Funkcja dodaj¹ca nowy element do drzewa (pocz¹tek)
void TreeB::push(int val, bool show)
{
	if (tests && show) tester.StartCounter();
	if (head == nullptr)
	{
		Node *newNode = new Node;
		newNode->data = val;
		head = newNode;
		if (show) size++;
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
				if (show) size++;
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
				if (show) size++;
			}
			else pushloop(head->right, val, show);
		}
	}
	//balance_tree(show);
	if (tests && show) addchosen(tester.GetCounter());
	if (!automatic && show) display();
}
//Funkcja losowa wype³niaj¹ca drzewo
void TreeB::push_random(int lenght)
{
	pop_all();
	size = lenght;
	for (int i = 0; i < lenght; i++)
	{
		push(rand(), false);
	}
	if (!automatic) display();
}
//Funkcja usuwaj¹ca ca³e drzewo
void TreeB::pop_all()
{
	if (head != nullptr)
	{
		if (tests) tester.StartCounter();
		Node *oldNode = head;
		size = 0;
		head = nullptr;
		if (oldNode->left != nullptr) pop_allloop(oldNode->left);
		if (oldNode->right != nullptr) pop_allloop(oldNode->right);
		delete oldNode;
		if (tests) addpopa(tester.GetCounter());
	}
}
//Funkcja usuwaj¹ca wybrany element z drzewa
void TreeB::pop_chosen(int val)
{
	if (head == nullptr)
	{
		cout << "\nDrzewo jest puste!" << endl;
		_getche();
		return;
	}
	if (tests) tester.StartCounter();
	Node *deleteNode = find_delete(val, head);
	if (deleteNode == nullptr) cout << "\nNie znaleziono takiego elementu w drzewie" << endl, _getche();
	else
	{
		Node *y, *x;
		if ((deleteNode->left == nullptr) || (deleteNode->right == nullptr)) y = deleteNode;
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
		balance_tree(!tests);
		if (tests) addpop(tester.GetCounter());
		if (!automatic) display();
	}
}
//Funkcja zwraca aktualny rozmiar listy
void TreeB::getSize()
{
	cout << "\nObecny rozmiar listy to: " << size;
	_getch();
}
//Funkcja sprawdzaj¹ca czy podana wartoœæ jest w fukcji
bool TreeB::find(int val)
{
	if (tests) tester.StartCounter();
	bool found;
	if (head == nullptr)
	{
		if (tests) addsearch(tester.GetCounter());
		return false;
	}
	else
	{
		if (head->data == val)
		{
			if (tests) addsearch(tester.GetCounter());
			return true;
		}
		if (head->left != nullptr)
		{
			found = findloop(val, head->left);
			if (found)
			{
				if (tests) addsearch(tester.GetCounter());
				return found;
			}
		}
		if (head->right != nullptr)
		{
			found = findloop(val, head->right);
			if (found)
			{
				if (tests) addsearch(tester.GetCounter());
				return found;
			}
		}
		if (tests) addsearch(tester.GetCounter());
		return false;
	}
}
// Równowa¿enie drzewa - algorytm DSW
void TreeB::balance_tree(bool show)
{
	if (tests || show) tester.StartCounter();
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
	int t = log2(size + 1);
	int m = pow(2, t) - 1;
	temp = head;
	for (int i = 0; i < (size - m); i++)
	{
		if (temp->parent == nullptr) head = temp->right;
		else temp->parent->right = temp->right;
		temp->right->parent = temp->parent;
		temp->parent = temp->right;
		temp->right = temp->parent->left;
		temp->parent->left = temp;
		temp = temp->parent->right;
	}
	while (m > 1)
	{
		m = m / 2;
		temp = head;
		for (int i = 0; i < m; i++)
		{
			if (temp->parent == nullptr) head = temp->right;
			else temp->parent->right = temp->right;
			temp->right->parent = temp->parent;
			temp->parent = temp->right;
			temp->right = temp->parent->left;
			temp->parent->left = temp;
			temp = temp->parent->right;
		}
	}
	if (tests || show) addbal(tester.GetCounter());
	if(!automatic && show) display();
}
//W³¹czanie wy³¹czanie testowania
void TreeB::switch_test() { tests = !tests; }
//Przeci¹¿enie funkcji zapisu
void TreeB::save_data(string filename)
{
	ofstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		plik << "wczytywanie;zapisywanie;usuwanie;usuwanie ostatniego;usuwanie pierwszego;usuwanie wszystkiego;dodawanie;dodawaniena pierwszego;dodawanie ostatniego;wyszukiwanie;równowa¿enie drzewa" << endl;
		for (int i = 0; i < 100; i++)
		{
			plik << loading[i] << ";" << saving[i] << ";" << deletech[i] << ";" << deletelast[i] << ";" << deletefirst[i] << ";" << deleteall[i] << ";" << addch[i] << ";" << addfirst[i] << ";" << addlast[i] << ";" << finder[i] << ";" << balancing[i] << endl;
		}
		plik.close();
	}
	else cout << "B³¹d zapisu" << endl, system("pasue");
}
//Funkcja wyœwietlaj¹ca drzewo (dalsza rekurencyjna czêœæ)
void TreeB::displayloop(Node *out)
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
void TreeB::pushloop(Node *oldNode, int val, bool rise)
{
	if (val < oldNode->data)
	{
		if (oldNode->left == nullptr)
		{
			Node *newNode = new Node;
			newNode->data = val;
			newNode->parent = oldNode;
			oldNode->left = newNode;
			if (rise) size++;
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
			if (rise) size++;
		}
		else pushloop(oldNode->right, val, rise);
	}
}
//Funkcja zapisu (rekurencyjna)
void TreeB::saveloop(Node *out, ofstream *plik)
{
	*plik << out->data << endl;
	if (out->left != nullptr) saveloop(out->left, plik);
	if (out->right != nullptr) saveloop(out->right, plik);
}
//Funkcja usuwaj¹ca rekrencyjnie ca³e drzewo
void TreeB::pop_allloop(Node *oldNode)
{
	if (oldNode->left != nullptr) pop_allloop(oldNode->left);
	if (oldNode->right != nullptr) pop_allloop(oldNode->right);
	delete oldNode;
}
//Funkcja szukaj¹ca rekrencyjnie w drzewie
bool TreeB::findloop(int val, Node *searched)
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
Node *TreeB::find_delete(int val, Node *searched)
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
Node *TreeB::find_successor(Node *node)
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
Node *TreeB::search_min(Node * node)
{
	while (node->left != nullptr)
	{
		node = node->left;
	}
	return node;
}
//Funkcja umieszczaj¹ca wynik pomiaru w tabeli
void TreeB::addbal(double numb)
{
	balancing[bnumber] = numb;
	bnumber++;
	displayresult(numb, bnumber);
}