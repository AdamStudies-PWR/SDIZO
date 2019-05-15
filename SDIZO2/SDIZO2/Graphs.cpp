//Implementacja metod klasy Graphs
#include "pch.h"
#include "Matrix.h"

using namespace std;

//Funckja drukuj¹ca wynik dzia³ania algorytmu Disjkstry
void Graphs::display_Dijkstra(Dijkstra *list, int size)
{
	system("cls");
	cout << "Solution:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "\nIndex: " << list[i].index << endl;;
		cout << "Dist: " << list[i].distance << endl;
		cout << "Prev: " << list[i].prev << endl;
	}
	_getche();
}