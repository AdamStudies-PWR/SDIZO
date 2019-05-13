//Implementacja metod klasy Graphs
#include "pch.h"
#include "Matrix.h"

using namespace std;

//Funckja drukuj¹ca wynik dzia³ania algorytmu Disjkstry
void Graphs::display_Dijkstra()
{
	system("cls");
	cout << "Checked:" << endl;
	cout << "\nDist: ";
	for (int i = 0; i < dch; i++)
	{
		cout << checked[i].distance;
		if (checked[i].distance > 9 || checked[i].distance == -1) cout << " ";
		else cout << "  ";
	}
	cout << "\nPrev: ";
	for (int i = 0; i < dch; i++)
	{
		cout << checked[i].prev;
		if (checked[i].prev > 9 || checked[i].prev == -1) cout << " ";
		else cout << "  ";
	}
	cout << "\nInde: ";
	for (int i = 0; i < dch; i++)
	{
		cout << checked[i].index;
		if (checked[i].index > 9 || checked[i].index == -1) cout << " ";
		else cout << "  ";
	}
	_getche();
}