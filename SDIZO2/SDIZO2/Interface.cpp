//Implementacja metod klasy Interface
#include "pch.h"
#include "Interface.h"

using namespace std;

//Główne menu programu
void Interface::main_menu()
{
	char choice;
	do
	{
		system("cls");
		cout << "\t---Główne Menu---" << endl;
		cout << " [1] Graf - reprezentacja macierzowa" << endl;
		cout << " [2] Graf - reprezentacja listowa" << endl;
		cout << " [0] Zakończ program" << endl;
		cout << "Wybór: ";
		choice = _getche();
		switch (choice)
		{
		case '0': break;
		case '1': matrix(); break;
		case '2': cout << "\nTBA" << endl, _getch(); break;
		default: cout << "\nBłąd wprowadzenia, spróbuj ponowne." << endl; _getch();
		}
	} while (choice != '0');
}

//Menu struktury
char Interface::structure_menu(string name)
{
	char choice;
	system("cls");
	cout << "\t---" << name << "---" << endl;
	cout << " [1] Wczytaj z pliku" << endl;
	cout << " [2] Wygeneruj graf losowo" << endl;
	cout << " [3] Wyświetl graf" << endl;
	cout << " [4] Algorytm Prima" << endl;
	cout << " [5] Algorytm Kruskala" << endl;
	cout << " [6] Algorytm Dijkstry" << endl;
	cout << " [7] Algorytm Forda-Bellmana" << endl;
	cout << " [0] Powrót" << endl;
	cout << "Wybór: ";
	choice = _getche();
	return choice;
}

//Obsługa losowego tworzenia grafu
void Interface::create_ui(Graphs *gg)
{
	int nodes, edge;
	int maxedge, mindensity;
	do
	{
		system("cls");
		cout << "Podaj ilość wierzchołków: ";
		cin >> nodes;
		if (nodes <= 1) cout << "\nIlość wierzchołków musi być większa od 1!" << endl, _getche();
	} while (nodes <= 1);
	maxedge = nodes * (nodes - 1);
	mindensity = ceil(((nodes - 1) * 100) / maxedge);
	do
	{
		system("cls");
		cout << "Podaj porządaną gęstość, > " << mindensity << "%" << endl;
		cin >> edge;
	} while (edge < mindensity || edge > 100);
	gg->create(nodes, edge);
}

//Obsługa funkcji dla implementacji macierzowej
void Interface::matrix()
{
	char choice;
	do
	{
		choice = structure_menu("Macierz sąsiedztwa");
		switch (choice)
		{
		case '0': break;
		case '2': create_ui(&mat); break;
		default: cout << "\n Błąd wprowadzenia, spróbuj ponownie." << endl, _getche();
		}
	} while (choice != '0');
}
