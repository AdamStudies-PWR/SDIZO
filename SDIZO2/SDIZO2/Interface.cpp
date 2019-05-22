//Implementacja metod klasy Interface
#include "pch.h"
#include "Interface.h"
#include "Automatic.h"

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
		cout << " [3] Wczytywanie" << endl;
		cout << " [4] Automatyczne testy" << endl;
		cout << " [0] Zakończ program" << endl;
		cout << "Wybór: ";
		choice = _getche();
		switch (choice)
		{
		case '0': break;
		case '1': matrix(); break;
		case '2': glist(); break;
		case '3': load_menu(); break;
		case '4': auto_test(); break;
		default: cout << "\nBłąd wprowadzenia, spróbuj ponowne." << endl; _getch();
		}
	} while (choice != '0');
}

void Interface::load_menu()
{
	string filename;
	char choice;
	do
	{
		system("cls");
		cout << "\t---Menu wczytywania---" << endl;
		cout << " [1] Wczytaj i wyświetl graf" << endl;
		cout << " [2] Wczytaj Dikistra" << endl;
		cout << " [3] Wczytaj Kruskal" << endl;
		cout << " [4] Wczytaj Prim" << endl;
		cout << " [5] Wczytaj Ford-Bellman" << endl;
		cout << " [0] Cofnij" << endl;
		cout << "Wybór: ";
		choice = _getche();
		switch (choice)
		{
		case '0': break;
		case '1':
		{
			system("cls");
			cout << "Wprowadź nazwe pliku: ";
			cin >> filename;
			mat.load_graph(filename);
			mat.display();
			mat.free_memory();
			list.load_graph(filename);
			list.display();
			list.free_memory();
		}break;
		case '3':
		{
			system("cls");
			cout << "Wprowadź nazwe pliku: ";
			cin >> filename;
			mat.load_graph(filename);
			mat.mst_Prim(0);
			mat.free_memory();
			list.load_graph(filename);
			list.mst_Prim(0);
			list.free_memory();
		}break;
		case '4':
		{
			system("cls");
			cout << "Wprowadź nazwe pliku: ";
			cin >> filename;
			mat.load_graph(filename);
			mat.mst_Kruskal();
			mat.free_memory();
			list.load_graph(filename);
			list.mst_Kruskal();
			list.free_memory();
		}break;
		default: cout << "\nBłąd wprowadzenia, spróbuj ponowne." << endl; _getch();
		}
	} while (choice != '0');
}

//Obsługa testów
void Interface::auto_test()
{
	mat.switch_test();
	list.switch_test();
	int ii;
	system("cls");
	cout << "[MAX 2000] Wielkość grafu: ";
	cin >> ii;
	if (ii > 2000 || ii < 1)
	{
		cout << "\nBłędna wartość!" << endl;
		_getche();
	}
	else loop_tests(mat, list, ii);
	mat.switch_test();
	list.switch_test();
}

//Menu struktury
char Interface::structure_menu(string name)
{
	char choice;
	system("cls");
	cout << "\t---" << name << "---" << endl;
	cout << " [1] Wygeneruj graf losowo" << endl;
	cout << " [2] Wyświetl graf" << endl;
	cout << " [3] Algorytm Prima" << endl;
	cout << " [4] Algorytm Kruskala" << endl;
	cout << " [5] Algorytm Dijkstry" << endl;
	cout << " [6] Algorytm Forda-Bellmana" << endl;
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

//Obsługa algorytmu Kruskala
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

//Obsługa algorytmu Forda-Bellmana
void Interface::ford_ui(Graphs *gg)
{
	int node;
	if (!directed) cout << "\n Graf musi być skierowany" << endl, _getche();
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
			gg->ford_bellman(node);
		}
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
		case '1': create_ui(&mat); break;
		case '2': mat.display(); break;
		case '3': prim_ui(&mat); break;
		case '4': kruskal_ui(&mat); break;
		case '5': dijkstra_ui(&mat); break;
		case '6': ford_ui(&mat); break;
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
		case '1': create_ui(&list); break;
		case '2': list.display(); break;
		case '3': prim_ui(&list); break;
		case '4': kruskal_ui(&list); break;
		case '5': dijkstra_ui(&list); break;
		case '6': ford_ui(&list); break;
		default: cout << "\n Błąd wprowadzenia, spróbuj ponownie." << endl, _getche();
		}
	} while (choice != '0');
}