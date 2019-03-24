// Interface.h Klasa ta zawiera wszystkie elementy interfejsu u¿ytkownika
#include "pch.h"
#include "Interface.h"
using namespace std;

//G³ówne menu programu
void Interface::mmenu()
{
	char choice;
	do
	{
		system("cls");
		cout << "\t---G³ówne Menu---" << endl;
		cout << " [1] Tablica" << endl;
		cout << " [2] Lista" << endl;
		cout << " [3] Kopiec" << endl;
		cout << " [4] Drzewo BST" << endl;
		cout << " [5] Drzewo CC" << endl;
		cout << " [6] Testowanie" << endl;
		cout << " [7] Automatyczne testy [EKSPERYMENTALNE]" << endl;
		cout << " [0] Zakoñcz program" << endl;
		cout << " Wybór: ";
		choice = _getche();
		switch (choice)
		{
		case '1': table(); break;
		case '2': list(); break;
		case '3': heap(); break;
		case '4': binarytree(); break;
		case '5': cout << "\nTBA" << endl, _getche(); break;
		case '6':
		{
			do
			{
				if (test) cout << "\nCzy chcesz wy³¹czyæ testowanie? T/N" << endl;
				else cout << "\nCzy chcesz w³¹czyæ testowanie? T/N" << endl;
				choice = _getche();
				switch (choice)
				{
				case 't':;
				case 'T':
				{
					test = !test;
					lista.switch_test();
					tab.switch_test();
					heapa.switch_test();
					btree.switch_test();
				}break;
				case 'n': break;
				case 'N': break;
				}
			} while (choice != 't' && choice != 'T' && choice != 'n' && choice != 'N');
		}break;
		case '7':
		{
			lista.switch_test();
			tab.switch_test();
			heapa.switch_test();
			btree.switch_test();
			int ii;
			system("cls");
			cout << "Iloœæ danych: ";
			cin >> ii;
		}
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
//Funkcja wyœwietlaj¹ca g³ówne menu oraz przyjmuj¹ca input
char Interface::printmenu(string name, bool tree)
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
	cout << " [7] Rozmiar " << name << endl;
	if (tree) cout << " [8] Równowa¿enie drzewa" << endl;
	if (test) cout << " [9] Zapisz wyniki testów" << endl;
	cout << " [0] Wróæ" << endl;
	cout << " Wybór: ";
	choice = _getche();
	return choice;
}
//Funkcja obs³uguj¹ca interfejs tablicy
void Interface::table()
{
	int ii;
	char choice;
	do
	{
		choice = printmenu("Tablica", false);
		switch (choice)
		{
		case '0': tab.pop_all();  break;
		case '1':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			tab.load(name);
		}break;
		case '2':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			tab.save(name);
		}break;
		case '3':
		{
			do
			{
				system("cls");
				cout << " [1] Usuñ z pocz¹tku" << endl;
				cout << " [2] Usuñ z koñca" << endl;
				cout << " [3] Usuñ z wybranego miejsca" << endl;
				cout << " [4] Usuñ wszystko" << endl;
				choice = _getch();
				switch (choice)
				{
				case '1': tab.pop_front(); break;
				case '2': tab.pop_back(); break;
				case '3': tab.pop_chosen(); break;
				case '4': tab.pop_all(); break;
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
		}break;
		case '4':
		{
			do
			{
				system("cls");
				cout << " [1] Dodaj na pocz¹tek" << endl;
				cout << " [2] Dodaj na koniec" << endl;
				cout << " [3] Dodaj na wybranego miejsce" << endl;
				cout << " [4] Utwórz tablice losowo" << endl;
				choice = _getch();
				if (choice == '1' || choice == '2' || choice == '3' || choice == '4')
				{
					system("cls");
					cout << "WprowadŸ wartoœæ: ";
					cin >> ii;
				}
				switch (choice)
				{
				case '1': tab.push_front(ii); break;
				case '2': tab.push_back(ii); break;
				case '3': tab.push_chosen(ii); break;
				case '4':
				{
					system("cls");
					cout << "WprowadŸ wielkoœæ porz¹danej tablicy: ";
					cin >> ii;
					tab.push_random(ii);
				}
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
		}break;
		case '5':
		{
			system("cls");
			cout << "WprowadŸ szukan¹ wartoœæ: ";
			cin >> ii;
			ii = tab.find(ii);
			if (ii == -1) cout << "W tablicy nie ma takiej wartoœci" << endl;
			else cout << "Szukana wartoœæ znajduje siê na pozycji: " << ii << endl;
			_getch();
		} break;
		case '6': tab.display(); break;
		case '7': tab.getSize(); break;
		case '9': tab.save_data("tablicatesty"), cout << "\nZapisano" << endl, _getch(); break;
		default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
		}
	} while (choice != '0');
}
//FUnkcja obs³uguj¹ca interfejs Listy
void Interface::list()
{
	char choice;
	int ii;
	do
	{
		choice = printmenu("Lista", false);
		switch (choice)
		{
		case '0': break;
		case '1':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			lista.load(name);
		}break;
		case '2':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			lista.save(name);
		}break;
		case '3':
		{
			do
			{
				system("cls");
				cout << " [1] Usuñ z pocz¹tku" << endl;
				cout << " [2] Usuñ z koñca" << endl;
				cout << " [3] Usuñ z wybranego miejsca" << endl;
				cout << " [4] Usuñ wszytko" << endl;
				choice = _getch();
				switch (choice)
				{
				case '1': lista.pop_front(); break;
				case '2': lista.pop_tail(); break;
				case '3': lista.pop_chosen(); break;
				case '4': lista.pop_all(); break;
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
		}break;
		case '4':
		{
			do
			{
				system("cls");
				cout << " [1] Dodaj na pocz¹tek" << endl;
				cout << " [2] Dodaj na koniec" << endl;
				cout << " [3] Dodaj na wybrane miejsce" << endl;
				cout << " [4] Utwórz liste losowo" << endl;
				choice = _getch();
				if (choice == '1' || choice == '2' || choice == '3')
				{
					system("cls");
					cout << "WprowadŸ wartoœæ: ";
					cin >> ii;
				}
				switch (choice)
				{
				case '1': lista.push_front(ii); break;
				case '2': lista.push_tail(ii); break;
				case '3': lista.push_chosen(ii); break;
				case '4':
				{
					system("cls");
					cout << "WprowadŸ wielkoœæ porz¹danej tablicy: ";
					cin >> ii;
					lista.generate(ii);
				}break;
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
		}break;
		case '5':
		{
			system("cls");
			cout << "WprowadŸ szukany element: ";
			cin >> ii;
			ii = lista.get_value(ii);
			if (ii == -1) cout << "Nie znaleziono szukanego elementu" << endl;
			else cout << "Szukany element znajduje siê na pozycji: " << ii << endl;
			_getche();
		} break;
		case '6': lista.display(); break;
		case '7': lista.getSize(); break;
		case '9': lista.save_data("listatesty"), cout << "\nZapisano" << endl, _getch(); break;
		default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
		}
	} while (choice != '0');
}
//Funkcja obs³uguj¹ca interfejs kopca
void Interface::heap()
{
	int ii;
	char choice;
	do
	{
		choice = printmenu("Kopiec", false);
		switch (choice)
		{
		case '0': break;
		case '1':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			heapa.load(name);
		}break;
		case '2':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			heapa.save(name);
		}break;
		case '3':
		{
			do
			{
				system("cls");
				cout << " [1] Usuñ z wybranego miejsca" << endl;
				cout << " [2] Usuñ wszytko" << endl;
				choice = _getch();
				switch (choice)
				{
				case '1':
				{
					system("cls");
					cout << "WprowadŸ element, który chesz usun¹æ: ";
					cin >> ii;
					heapa.pop(ii);
				} break;
				case '2': heapa.pop_all(); break;
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2');
		}break;
		case '4':
		{
			do
			{
				system("cls");
				cout << " [1] Dodaj normalnie" << endl;
				cout << " [2] Utwórz losowo" << endl;
				choice = _getch();
				switch (choice)
				{
				case '1':
				{
					system("cls");
					cout << "WprowadŸ wartoœæ: ";
					cin >> ii;
					heapa.push(ii);
				} break;
				case '2':
				{
					system("cls");
					cout << "WprowadŸ d³ugoœæ: ";
					cin >> ii;
					heapa.push_random(ii);
				}break;
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2');
		} break;
		case '5':
		{
			system("cls");
			cout << "WprowadŸ szukany element: ";
			cin >> ii;
			ii = heapa.find(ii);
			if (ii == -1) cout << "Nie znaleziono szukanego elementu" << endl;
			else cout << "Szukany element znajduje siê na pozycji: " << ii << endl;
			_getche();
		} break;
		case '6': heapa.display(); break;
		case '7': heapa.getSize(); break;
		case '9': heapa.save_data("kopiectesty"), cout << "\nZapisano" << endl, _getch(); break;
		default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
		}
	} while (choice != '0');
}
//Funkcja obs³uguj¹ca interfejs drzewa
void Interface::binarytree()
{
	int ii;
	char choice;
	do
	{
		choice = printmenu("Drzewo binarne", true);
		switch (choice)
		{
		case '0': break;
		case '1':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			btree.load(name);
		}break;
		case '2':
		{
			string name;
			system("cls");
			cout << "WprowadŸ nazwe pliku: ";
			cin >> name;
			btree.save(name);
		}break;
		case '3':
		{
			do
			{
				system("cls");
				cout << " [1] Usuñ z wybranego miejsca" << endl;
				cout << " [2] Usuñ wszytko" << endl;
				choice = _getch();
				switch (choice)
				{
				case '1':
				{
					system("cls");
					cout << "WprowadŸ element, który chesz usun¹æ: ";
					cin >> ii;
					btree.pop_chosen(ii);
				} break;
				case '2': btree.pop_all(); break;
				default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
				}
			} while (choice != '1' && choice != '2');
		}break;
		case '4':
		{
			{
				do
				{
					system("cls");
					cout << " [1] Dodaj wartoœæ" << endl;
					cout << " [2] Utwórz losowo" << endl;
					choice = _getch();
					switch (choice)
					{
					case '1':
					{
						system("cls");
						cout << "WprowadŸ wartoœæ: ";
						cin >> ii;
						btree.push(ii, true);
					} break;
					case '2':
					{
						system("cls");
						cout << "WprowadŸ d³ugoœæ: ";
						cin >> ii;
						btree.push_random(ii);
					} break;
					default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
					}
				} while (choice != '1' && choice != '2');
			}break;
		} break;
		case '5':
		{
			bool searched;
			system("cls");
			cout << "WprowadŸ szukany element: ";
			cin >> ii;
			searched = btree.find(ii);
			if (searched) cout << "Szukany element znajduje siê w drzewie" << endl;
			else cout << "Nie znaleziono szukanego elementu" << endl;
			_getche();
		} break;
		case '6': btree.display(); break;
		case '7': btree.getSize(); break;
		case '8': btree.balance_tree(true); break;
		case '9': btree.save_data("drzewotesty"), cout << "\nZapisano" << endl, _getch(); break;
		default: cout << "\nB³¹d wprowadzenia, spróbuj ponownie" << endl, _getch();
		}
	} while (choice != '0');
}