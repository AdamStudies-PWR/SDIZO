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
		case '2': glist(); break;
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
	double maxedge;
	double mindensity;
	char choice;
	do
	{
		system("cls");
		cout << "Podaj ilość wierzchołków: ";
		cin >> nodes;
		if (nodes <= 1) cout << "\nIlość wierzchołków musi być większa od 1!" << endl, _getche();
	} while (nodes <= 1);
	do
	{
		system("cls");
		cout << "Czy graf Skierowany? [T/N]" << endl;
		choice = _getche();
	} while (choice != 't' && choice != 'T' && choice != 'n' && choice != 'N');
	if (choice == 't' || choice == 'T')
	{
		directed = true;
		maxedge = nodes * (nodes - 1);
	}
	else
	{
		directed = false;
		maxedge = (nodes * (nodes - 1))/2;
	}
	mindensity = ceil((((double)nodes - 1) * 100) / maxedge);
	do
	{
		system("cls");
		cout << "Podaj porządaną gęstość, > " << mindensity << "%" << endl;
		cin >> edge;
	} while (edge < mindensity || edge > 100);
	size_n = nodes;
	exists = true;
	gg->create(nodes, edge, maxedge, directed);
}

//Obsługa algorytmu Dijsktry
void Interface::dijkstra_ui(Graphs *gg)
{
	int node;
	if (!directed) cout << "\n Graf musi być skierowany" << endl, _getche();
	else
	{
		if(!exists) cout << "\n Graf nie istnieje" << endl, _getche();
		else
		{
			do
			{
				system("cls");
				cout << "Podaj węzeł początkowy [0 - " << size_n - 1 << "]:" << endl;
				cin >> node;
			} while (node < 0 || node > (size_n - 1));
			gg->dijkstra(node);
		}
	}
}

//Obsługa algorytmu Prima
void Interface::prim_ui(Graphs *gg)
{
	int node;
	if (directed) cout << "\n Graf nie może być skierowany" << endl, _getche();
	else
	{
		if (!exists) cout << "\n Graf nie istnieje" << endl, _getche();
		else
		{
			do
			{
				system("cls");
				cout << "Podaj węzeł początkowy [0 - " << size_n - 1 << "]:" << endl;
				cin >> node;
			} while (node < 0 || node >(size_n - 1));
			gg->mst_Prim(node);
		}
	}
}

void Interface::kruskal_ui(Graphs *gg)
{
	int node;
	if (directed) cout << "\n Graf nie może być skierowany" << endl, _getche();
	else
	{
		if (!exists) cout << "\n Graf nie istnieje" << endl, _getche();
		else gg->mst_Kruskal();
	}
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
		case '3': mat.display(); break;
		case '4': prim_ui(&mat); break;
		case '5': kruskal_ui(&mat); break;
		case '6': dijkstra_ui(&mat); break;
		default: cout << "\n Błąd wprowadzenia, spróbuj ponownie." << endl, _getche();
		}
	} while (choice != '0');
}

//Obsługa funkcji dla implementacji listwoej
void Interface::glist()
{
	char choice;
	do
	{
		choice = structure_menu("Reprezentacja Listowa");
		switch (choice)
		{
		case '0': break;
		case '2': create_ui(&list); break;
		case '3': list.display(); break;
		case '4': prim_ui(&list); break;
		case '5': kruskal_ui(&list); break;
		case '6': dijkstra_ui(&list); break;
		default: cout << "\n Błąd wprowadzenia, spróbuj ponownie." << endl, _getche();
		}
	} while (choice != '0');
}