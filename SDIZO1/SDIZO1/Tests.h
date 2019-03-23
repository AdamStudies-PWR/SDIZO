#pragma once
// Klasa abstrakcyjna u�atwiaj�ca masowe testowanie
#include "pch.h"
#include "Counter.h"

using namespace std;

class Tests
{
protected:
	const static int number = 1000;
	double loading[number];
	double saving[number];
	double deletech[number];
	double deletelast[number];
	double deletefirst[number];
	double deleteall[number];
	double addch[number];
	double addfirst[number];
	double addlast[number];
	double create[number];
	double display[number];

	int ldnumber = 0;
	int svnumber = 0;
	int dchnumber = 0;
	int dlnumber = 0;
	int dfnumber = 0;
	int danumber = 0;
	int achnumber = 0;
	int afnumber = 0;
	int alnumber = 0;
	int cnumber = 0;
	int dnumber = 0;

	Counter tester;
	int size = 0;
	bool tests = false;
public:
	//konstruktor zerujacy tabele
	Tests()
	{
		for (int i = 0; i < number; i++)
		{
			loading[i] = 0;
			saving[i] = 0;
			deletech[i] = 0;
			deletelast[i] = 0;
			deletefirst[i] = 0;
			deleteall[i] = 0;
			addch[i] = 0;
			addfirst[i] = 0;
			addlast[i] = 0;
			create[i] = 0;
			display[i] = 0;
		}
	}
	//Funkcja zapisujaca wyniki testu
	void save_data(string filename)
	{
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << "wczytywanie;zapisywanie;usuwanie;usuwanie ostatniego;usuwanie pierwszego;usuwanie wszystkiego;dodawanie;dodawaniena pierwszego;dodawanie ostatniego;tworzenie;wy�wietlanie" << endl;
			for (int i = 0; i < 100; i++)
			{
				plik << loading[i] << ";" << saving[i] << ";" << deletech[i] << ";" << deletelast[i] << ";" << deletefirst[i] << ";" << deleteall[i] << ";" << addch[i] << ";" << addfirst[i] << ";" << addlast[i] << ";" << create[i] << ";" << display[i] << endl;
			}
			plik.close();
		}
		else cout << "B��d zapisu" << endl, system("pasue");
	}
	//Funkcja wyswietlaj�ca wynik testu
	void displayresult(double numb, int info)
	{
		cout << "\n" << info << " Wynik testu: " << numb << endl;
	}
	void adddisplay(double numb)
	{
		display[dnumber] = numb;
		dnumber++;
		displayresult(numb, dnumber);
	}
};
