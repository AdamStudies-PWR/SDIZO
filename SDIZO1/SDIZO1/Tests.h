#pragma once
#ifndef Tests_hpp
#define Tests_hpp
#include "Counter.h"

// Klasa abstrakcyjna u³atwiaj¹ca masowe testowanie
class Tests
{
protected:
	//Zmienne
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

	Counter tester;
	int size = 0;
	bool tests = false;
	bool automatic = false;
	int quantity = 1000;
public:
	//Metody
	Tests();
	void save_data(string filename);
	void setquantity(int newdata);
protected:
	void displayresult(double numb, int info);
	void addsave(double numb);
	void addload(double numb);
	void addchosen(double numb);
	void addfront(double numb);
	void addback(double numb);
	void addpopf(double numb);
	void addpopl(double numb);
	void addpop(double numb);
	void addpopa(double numb);
	void addsearch(double numb);
};
#endif