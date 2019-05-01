#pragma once
#ifndef Matrix_hpp
#define Matrix_hpp
//Klasa obs³uguj¹ca maciorzow¹ reprezantacj¹ grafów
#include "Graphs.h"

class Matrix: public Graphs
{ 
private:
	//Zmienne
	int **pointer;
public:
	//Metody
	//Funkcja losowo tworz¹ca graf
	void create(int node, int edge);
	//Funkcja wyœwietlaj¹ca graf
	void display();
};

#endif