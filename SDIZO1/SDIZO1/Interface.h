#pragma once
// Interface.h Klasa ta zawiera wszystkie elementy interfejsu u¿ytkownika
#include <iostream>
#include <conio.h>
#include <string>
#include "pch.h"

using namespace std;

class Interface
{
private:

public:
	void mmenu()
	{
		char choice;
		do
		{
			system("cls");
			cout << "\t---G³ówne Menu---" << endl;
			cout << " [1] Tablica" << endl;
			cout << " [2] Lista" << endl;
			cout << " [3] Kopiec" << endl;
			cout << " [4] Drzewo DST" << endl;
			cout << " [5] Drzewo CB" << endl;
			cout << " [0] Zakoñcz program" << endl;
			cout << " Wybór: ";
			choice = _getche();
			switch (choice)
			{
			case '1': table(); break;
			case '2': cout << "TBA" << endl; break;
			case '3': cout << "TBA" << endl; break;
			case '4': cout << "TBA" << endl; break;
			case '5': cout << "TBA" << endl; break;
			case '0':
			{
				system("cls");
				cout << "Koniec" << endl;
				_getch();
			} break;
			default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
			}
		} while (choice != '0');
	}
private:
	char printmenu(string name)
	{
		char choice;
		system("cls");
		cout << "\t---" << name << "---" << endl;
		cout << " [1] Wczytaj z pliku" << endl;
		cout << " [2] Usuñ" << endl;
		cout << " [3] Dodaj" << endl;
		cout << " [4] ZnajdŸ" << endl;
		cout << " [5] Wyswietl" << endl;
		cout << " [6] Stwórz losowo" << endl;
		cout << " [7] Testowanie" << endl;
		cout << " [0] Wróæ" << endl;
		choice = _getche();
		return choice;
	}

	void table()
	{
		char choice;
		do
		{
			choice = printmenu("Tablica");
			switch (choice)
			{
			case '1': break;
			case '0': break;
			default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
			}
		} while (choice != '0');
	}
};