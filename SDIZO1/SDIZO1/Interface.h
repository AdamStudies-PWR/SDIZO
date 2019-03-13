#pragma once
// Interface.h Klasa ta zawiera wszystkie elementy interfejsu u¿ytkownika
#include <iostream>
#include <conio.h>
#include <string>
#include "pch.h"
#include "List.h"

using namespace std;

class Interface
{
private:
	List lista;
public:
	//G³ówne menu programu
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
			case '2': list(); break;
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
	//Funkcja wyœwietlaj¹ca g³ówne menu oraz przyjmuj¹ca input
	char printmenu(string name)
	{
		char choice;
		system("cls");
		cout << "\t---" << name << "---" << endl;
		cout << " [1] Wczytaj z pliku" << endl;
		cout << " [2] Zapisz do pliku" << endl;
		cout << " [3] Usuñ" << endl;
		cout << " [4] Dodaj" << endl;
		cout << " [5] ZnajdŸ" << endl;
		cout << " [6] Wyswietl" << endl;
		cout << " [7] Stwórz losowo" << endl;
		cout << " [8] Testowanie" << endl;
		cout << " [9] Rozmiar " << name << endl;
		cout << " [0] Wróæ" << endl;
		cout << " Wybór: ";
		choice = _getche();
		return choice;
	}
	//Funkcja obs³uguj¹ca interfejs tablicy
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
	//FUnkcja obs³uguj¹ca interfejs Listy
	void list()
	{
		char choice;
		int ii;
		do
		{
			choice = printmenu("Lista");
			switch (choice)
			{
			case '0': break;
			case '3':
			{
				do
				{
					system("cls");
					cout << " [1] Usuñ z pocz¹tku" << endl;
					cout << " [2] Usuñ z koñca" << endl;
					cout << " [3] Usuñ z wybranego miejsca" << endl;
					choice = _getch();
					switch (choice)
					{
					case '1': lista.pop_front(); break;
					case '2': lista.pop_tail(); break;
					default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
					}
				} while (choice != '1' && choice != '2');
			}break;
			case '4':
			{
				system("cls");
				cout << "WprowadŸ wartoœæ: ";
				cin >> ii;
				do
				{
					system("cls");
					cout << " [1] Dodaj na pocz¹tek" << endl;
					cout << " [2] Dodaj na koniec" << endl;
					cout << " [3] Dodaj na wybrane miejsce" << endl;
					choice = _getch();
					switch (choice)
					{
					case '1': lista.push_front(ii); break;
					default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
					}
				} while (choice != '1' && choice != '2');
			}break;
			case '6': lista.display(); break;
			case '9': lista.getSize(); break;
			default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
			}
		} while (choice != '0');
	}
};