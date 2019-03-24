#pragma once
// Klasa abstrakcyjna u³atwiaj¹ca masowe testowanie
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
	double finder[number];
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
	int fnumber = 0;
	int dnumber = 0;

	Counter tester;
	int size = 0;
	bool tests = false;
	bool automatic = false;
	int quantity = 1000;
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
			finder[i] = 0;
			display[i] = 0;
		}
	}
	//Funkcja zapisujaca wyniki testu
	void save_data(string filename)
	{
		ofstream plik(filename + ".txt");
		if (plik.good() == true)
		{
			plik << "wczytywanie;zapisywanie;usuwanie;usuwanie ostatniego;usuwanie pierwszego;usuwanie wszystkiego;dodawanie;dodawaniena pierwszego;dodawanie ostatniego;wyszukiwanie;wyœwietlanie" << endl;
			for (int i = 0; i < 100; i++)
			{
				plik << loading[i] << ";" << saving[i] << ";" << deletech[i] << ";" << deletelast[i] << ";" << deletefirst[i] << ";" << deleteall[i] << ";" << addch[i] << ";" << addfirst[i] << ";" << addlast[i] << ";" << finder[i] << ";" << display[i] << endl;
			}
			plik.close();
		}
		else cout << "B³¹d zapisu" << endl, system("pasue");
	}
	//Funkcja wyswietlaj¹ca wynik testu
	void displayresult(double numb, int info)
	{
		if (!automatic)
		{
			cout << "\n" << info << " Wynik testu: " << numb << endl;
			system("pause");
		}
	}
	void adddisplay(double numb)
	{
		display[dnumber] = numb;
		dnumber++;
		displayresult(numb, dnumber);
	}
	void addsave(double numb)
	{
		saving[svnumber] = numb;
		svnumber++;
		displayresult(numb, svnumber);
	}
	void addload(double numb)
	{
		loading[ldnumber] = numb;
		ldnumber++;
		displayresult(numb, ldnumber);
	}
	void addchosen(double numb)
	{
		addch[achnumber] = numb;
		achnumber++;
		displayresult(numb, achnumber);
	}
	void addfront(double numb)
	{
		addfirst[afnumber] = numb;
		afnumber++;
		displayresult(numb, afnumber);
	}
	void addback(double numb)
	{
		addlast[alnumber] = numb;
		alnumber++;
		displayresult(numb, alnumber);
	}
	void addpopf(double numb)
	{
		deletefirst[dfnumber] = numb;
		dfnumber++;
		displayresult(numb, dfnumber);
	}
	void addpopl(double numb)
	{
		deletelast[dlnumber] = numb;
		dlnumber++;
		displayresult(numb, dlnumber);
	}
	void addpop(double numb)
	{
		deletech[dchnumber] = numb;
		dchnumber++;
		displayresult(numb, dchnumber);
	}
	void addpopa(double numb)
	{
		deleteall[danumber] = numb;
		danumber++;
		displayresult(numb, danumber);
	}
};
