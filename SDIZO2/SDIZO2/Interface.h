#pragma once
#ifndef Interface_hpp
#define Interface_hpp
// Kasa obs�uguj�ca wszsytkie interakcje u�ytkownika z aplikacj�
#include "Matrix.h"

using namespace std;

class Interface
{
private:
	//zmienne
	Matrix mat;
public:
	//metody
	//G��wne menu propgramu
	void main_menu();
private:
	//Menu struktury
	char structure_menu(string name);
	//Obs�uga funkcji dla implementacji macierzowej
	void matrix();
	//Obs�uga losowego tworzenia grafu
	void create_ui(Graphs *g);
};

#endif