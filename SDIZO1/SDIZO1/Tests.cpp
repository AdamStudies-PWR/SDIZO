// Klasa abstrakcyjna u³atwiaj¹ca masowe testowanie
#include "pch.h"
#include "Tests.h"
using namespace std;

//konstruktor zerujacy tabele
Tests:: Tests()
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
	}
}
//Funkcja zapisujaca wyniki testu
void Tests::save_data(string filename)
{
	ofstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		plik << "wczytywanie;zapisywanie;usuwanie;usuwanie ostatniego;usuwanie pierwszego;usuwanie wszystkiego;dodawanie;dodawaniena pierwszego;dodawanie ostatniego;wyszukiwanie" << endl;
		for (int i = 0; i < 100; i++)
		{
			plik << loading[i] << ";" << saving[i] << ";" << deletech[i] << ";" << deletelast[i] << ";" << deletefirst[i] << ";" << deleteall[i] << ";" << addch[i] << ";" << addfirst[i] << ";" << addlast[i] << ";" << finder[i] << endl;
		}
		plik.close();
	}
	else cout << "B³¹d zapisu" << endl, system("pasue");
}
//Funkcja wyswietlaj¹ca wynik testu
void Tests:: displayresult(double numb, int info)
{
	if (!automatic)
	{
		cout << "\n" << info << " Wynik testu: " << numb << endl;
		_getche();
	}
}
void Tests:: addsave(double numb)
{
	saving[svnumber] = numb;
	svnumber++;
	displayresult(numb, svnumber);
}
void Tests:: addload(double numb)
{
	loading[ldnumber] = numb;
	ldnumber++;
	displayresult(numb, ldnumber);
}
void Tests:: addchosen(double numb)
{
	addch[achnumber] = numb;
	achnumber++;
	displayresult(numb, achnumber);
}
void Tests::addfront(double numb)
{
	addfirst[afnumber] = numb;
	afnumber++;
	displayresult(numb, afnumber);
}
void Tests:: addback(double numb)
{
	addlast[alnumber] = numb;
	alnumber++;
	displayresult(numb, alnumber);
}
void Tests:: addpopf(double numb)
{
	deletefirst[dfnumber] = numb;
	dfnumber++;
	displayresult(numb, dfnumber);
}
void Tests:: addpopl(double numb)
{
	deletelast[dlnumber] = numb;
	dlnumber++;
	displayresult(numb, dlnumber);
}
void Tests:: addpop(double numb)
{
	deletech[dchnumber] = numb;
	dchnumber++;
	displayresult(numb, dchnumber);
}
void Tests:: addpopa(double numb)
{
	deleteall[danumber] = numb;
	danumber++;
	displayresult(numb, danumber);
}
void Tests:: addsearch(double numb)
{
	finder[fnumber] = numb;
	fnumber++;
	displayresult(numb, fnumber);
}

