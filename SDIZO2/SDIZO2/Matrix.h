#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs�uguj�ca maciorzow� reprezantacj� graf�w
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	//Zmienne
	int **pointer;
public:
	//Metody
	//Funkcja losowo tworz�ca graf
	void create(int node, int edge);
	//Funkcja wy�wietlaj�ca graf
	void display();
};

#endif