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
		cout << " Wybór: ";
		choice = _getche();
		switch (choice)
		{
		case '0': break;
		case '1': cout << "\nTBA" << endl, _getch(); break;
		case '2': cout << "\nTBA" << endl, _getch(); break;
		default: cout << "\nBłąd wprowadzenia, spróbuj ponowne" << endl; _getch();
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
}