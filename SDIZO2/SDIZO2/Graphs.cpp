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

//Funckja drukuj¹ca wynik dzia³ania algorytmu Primy
void Graphs::display_Prim(Prim *list, int size)
{
	system("cls");
	cout << "Solution:" << endl;
	cout << "Total mst size: " << mst_size << endl;
	cout << "\nInde:  ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i].index;
		if (list[i].index > 9) cout << " ";
		else cout << "  ";
	}
	cout << "\nDist:  ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i].distance;
		if (list[i].distance > 9) cout << " ";
		else cout << "  ";
	}
	cout << "\nPrev: ";
	for (int i = 0; i < size; i++)
	{
		cout << list[i].prev;
		if (list[i].prev > 9) cout << " ";
		else cout << "  ";
	}
	_getche();
}

//Funkcja sortuj¹ca krawêdzie
void Graphs::sort(Kruskal *traget)
{

}