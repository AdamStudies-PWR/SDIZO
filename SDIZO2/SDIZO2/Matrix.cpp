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
	display();
}

//Funkcja wyœwietlaj¹ca graf
void Matrix::display()
{
	string spacing;
	if (nodes < 11) spacing = " ";
	else spacing = "  ";
	system("cls");
	cout << "Macierz s¹siedztwa: " << endl;
	cout << spacing;
	for (int i = 0; i < nodes; i++)
	{
		if (i > 9) cout << " ";
		else cout << spacing;
		cout << i;
	}
	cout << "\n" << endl;
	for (int i = 0; i < nodes; i++)
	{
		cout << i;
		if (nodes > 10 && i < 10) cout << " ";
		for (int j = 0; j < nodes; j++)
		{
			cout << spacing << pointer[i][j];
		}
		cout << endl;
	}
	_getche();
}