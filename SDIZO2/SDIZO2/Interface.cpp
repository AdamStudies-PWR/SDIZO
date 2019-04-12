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
		cout << " [1] Grafy" << endl;
		cout << " [0] Zakończ program" << endl;
		cout << " Wybór: ";
		choice = _getche();
		switch (choice)
		{
		case '0': break;
		case '1': cout << "\nTBA" << endl, _getch(); break;
		default: cout << "\nBłąd wprowadzenia, spróbuj ponowne" << endl; _getch();
		}
	} while (choice != '0');
}