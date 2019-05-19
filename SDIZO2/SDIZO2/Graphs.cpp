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
	cout << "\nPrev:";
	for (int i = 0; i < size; i++)
	{
		if (list[i].prev == -1) cout << " ";
		else if (list[i].prev < 9) cout << "  ";
		else cout << " ";
		cout << list[i].prev;
	}
	_getche();
}

//Funkcja sortuj¹ca krawêdzie
void Graphs::sort(Kruskal *target)
{
	Kruskal temp;
	for (int j = 1; j < 2*edges; j++)
	{
		for (int i = j; i < 2*edges; i++)
		{
			if (target[i].weight < target[j - 1].weight)
			{
				temp = target[j - 1];
				target[j - 1] = target[i];
				target[i] = temp;
			}
		}
	}
}

//Funkcja ³¹cz¹ca dwa podzbiory w algorytmie Kruskala
void Graphs::connect(int tab, int tab2)
{
	int loop = 0;
	Prim *temp;
	Prim **temp2;
	int *temp3;
	int start = sizes[tab];
	int ind = 0;
	sizes[tab] = sizes[tab] + sizes[tab2];
	temp = new Prim[sizes[tab]];
	for (int i = 0; i < sizes[tab]; i++)
	{
		if (i < start)
		{
			temp[i] = tree[tab][i];
		}
		else
		{
			temp[i] = tree[tab2][ind];
			ind++;
		}
	}
	delete[] tree[tab];
	tree[tab] = temp;
	t_size--;
	temp2 = new Prim*[t_size];
	temp3 = new int[t_size];
	for (int i = 0; i < t_size; i++)
	{
		if (i == tab2)
		{
			loop++;
			temp2[i] = tree[loop];
			temp3[i] = sizes[loop];
		}
		else
		{
			temp2[i] = tree[loop];
			temp3[i] = sizes[loop];
		}
		loop++;
	}
	delete[] sizes;
	//for (int i = 0; i < (t_size + 1); i++) delete tree[i];
	delete tree;
	sizes = temp3;
	tree = temp2;
}

//Funkcja odwracaj¹ca po³¹czenie
void Graphs::reverse(int tab, int index, int weight, int from)
{
	/*int con = 0;
	int temp;
	do
	{
		for (int i = 0; i < sizes[tab]; i++)
		{
			if (tree[tab][i].index == index) 
			{
				con = i;
				break;
			}
		}
		index = tree[tab][con].prev;
		tree[tab][con].prev = from;
		from = tree[tab][con].index;
		temp = tree[tab][con].distance;
		tree[tab][con].distance = weight;
		weight = temp;
	} while (index != -1);*/
}