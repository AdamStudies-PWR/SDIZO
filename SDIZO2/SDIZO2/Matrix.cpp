//Implementacja metod klasy Matrix
#include "pch.h"
#include "Matrix.h"

using namespace std;

//Funkcja losowo tworz¹ca graf
void Matrix::create(int NN, double EE, int ME, bool directed) 
{
	nodes = NN;
	edges = ME * (EE/100);
	int *visited = new int [nodes];
	pointer = new int *[nodes];
	for (int i = 0; i < nodes; i++)
	{
		visited[i] = 0;
		pointer[i] = new int[nodes];
		for (int j = 0; j < nodes; j++)
		{
			pointer[i][j] = 0;
		}
	}
	spanningtree(visited);
	if (!directed)
	{
		for (int i = 0; i < (nodes/2) + 1; i++)
		{
			for (int j = 0; j < nodes; j++) pointer[j][i] = pointer[i][j];
		}
	}
	display();
}

//Funkcja wyœwietlaj¹ca graf
void Matrix::display()
{
	system("cls");
	cout << "Macierz s¹siedztwa: " << endl;
	cout << "  ";
	for (int i = 0; i < nodes; i++)
	{
		if (i > 10) cout << " ";
		else cout << "  ";
		cout << i;
	}
	cout << "\n" << endl;
	for (int i = 0; i < nodes; i++)
	{
		cout << i;
		if (i < 10) cout << " ";
		for (int j = 0; j < nodes; j++)
		{
			if (j > 0)
			{
				if (pointer[i][j - 1] >= 10) cout << " ";
				else cout << "  ";
			}
			else cout << "  ";
			cout << pointer[i][j];
		}
		cout << endl;
	}
	_getche();
}

//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
void Matrix::spanningtree(int *visited)
{
	bool check;
	int created = 1;
	int node = 0;
	int children, count, temp;
	visited[node] = 1;
	do
	{
		check = true;
		count = 0;
		children = (rand() % 2) + 2;
		do
		{
			if (created == nodes) return;
			temp = rand() % nodes;
			if (temp == (node)) continue;
			if (visited[temp] != 0) continue;
			else
			{
				pointer[node][temp] = (rand() % 100) + 1;
				visited[temp] = 1;
			}
			count++;
			created++;
		} while (count != children);
		for (int i = 1; i < nodes; i++)
		{
			if (visited[i] == 1)
			{
				for (int j = 1; j < nodes; j++)
				{
					if (pointer[i][j] != 0) check = false;  break;
				}
				if (check) { node = i; break; }
			}
		}
	} while (created != nodes);
}