//Implementacja metod klasy Matrix
#include "pch.h"
#include "Matrix.h"

using namespace std;

//Funkcja losowo tworz¹ca graf
void Matrix::create(int NN, double EE, double ME, bool directed) 
{
	nodes = NN;
	edges = ME * (EE/100);
	bool found;
	int counter = nodes;
	int begin, end;
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
		for (int i = 0; i < nodes; i++)
		{
			for (int j = 0; j < nodes; j++)
			{
				if (pointer[i][j] != 0) pointer[j][i] = pointer[i][j];
			}
		}
	}
	while (counter <= edges)
	{
		found = false;
		begin = rand() % nodes;
		for (int i = 0; i < nodes; i++)
		{
			if (i != begin && pointer[begin][i] == 0)
			{
				found = true;
				end = i;
			}
		}
		if (!found) continue;
		pointer[begin][end] = (rand() % 99) + 1;
		if (!directed) pointer[end][begin] = pointer[begin][end];
		counter++;
	}
	delete visited;
	display();
}

//Funkcja wyœwietlaj¹ca graf
void Matrix::display()
{
	system("cls");
	if (pointer == nullptr) cout << "Graf nie istnieje!" << endl;
	else
	{
		cout << "\nWierzcho³ki: " << nodes << ", Krawêdzie: " << edges;
		cout << "\nMacierz s¹siedztwa: " << endl;
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
	}
	_getche();
}

//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
void Matrix::spanningtree(int *visited)
{
	bool check = true;
	int created = 1;
	int node = 0;
	int children, count, temp, rr;
	visited[node] = 1;
	do
	{
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
				pointer[node][temp] = (rand() % 99) + 1;
				visited[temp] = 1;
			}
			count++;
			created++;
		} while (count != children);
		while(true)
		{
			rr =  rand() % nodes;
			if (visited[rr] == 1)
			{
				for (int j = 1; j < nodes; j++)
				{
					if (pointer[rr][j] != 0) { check = false;  break; }
				}
				if (check) { node = rr; break; }
				else check = true;
			}
		}
	} while (created != nodes);
}

//Funkcja obs³uguj¹ca algorytm Dijsktry
void Matrix::mst_Dijkstra(int start)
{
	dnch = nodes;
	dch = 0;
	notchecked = new Dijkstra[dnch];
	for (int i = 0; i < dnch; i++)
	{
		notchecked[i].index = i;
	}
	notchecked[start].distance = 0;
	do
	{
		start = relax(start);
		dnch--;
		dch++;
	} while (dnch != 0);
	display_Dijkstra();
}

//Funkcja relaksuj¹ca s¹siadów
int Matrix::relax(int index)
{
	Dijkstra *temp;
	int small = 200;
	int next = -1;
	int loop;
	for (int i = 0; i < nodes; i++)
	{
		if (pointer[notchecked[index].index][i] != 0)
		{
			for (int j = 0; j < dnch; j++)
			{
				if (notchecked[i].index == i)
				{
					if ((notchecked[j].distance > pointer[notchecked[index].index][i]) || (notchecked[j].distance == -1))
					{
						if (notchecked[index].prev == i) continue;
						notchecked[j].distance = pointer[notchecked[index].index][i];
						notchecked[j].prev = notchecked[index].index;
						if (pointer[notchecked[index].index][i] < small)
						{
							small = pointer[notchecked[index].index][i];
							next = i;
						}
					}
				}
			}
		}
	}
	temp = new Dijkstra[dch + 1];
	if (dch == 0)
	{
		temp[0] = notchecked[index];
	}
	else
	{
		loop = 0;
		for (int i = 0; i < (dch + 1); i++)
		{
			if (checked[i].index > notchecked[notchecked[index].index].index)
			{
				temp[i] = notchecked[notchecked[index].index];
				temp[i + 1] = checked[i];
				loop++;
			}
			else temp[loop] = checked[i];
			loop++;
		}
		delete checked;
	}
	checked = temp;
	loop = 0;
	temp = new Dijkstra[dnch - 1];
	for (int i = 0; i < (dnch - 1); i++)
	{
		if (i == notchecked[index].index)
		{
			temp[i] = notchecked[i + 1];
			loop++;
		}
		else temp[i] = notchecked[loop];
		loop++;
	}
	delete notchecked;
	notchecked = temp;
	if (next != -1)
	{
		for (int i = 0; i < (dnch - 1); i++)
		{
			if (notchecked[i].index == next) return i;
		}
	}
	else
	{
		next = 0;
		small = 200;
		for (int i = 0; i < (dnch - 1); i++)
		{
			if (notchecked[i].distance < small && notchecked[i].distance != -1)
			{
				small = notchecked[i].distance;
				next = notchecked[i].index;
			}
		}
		return next;
	}
}

//Funckja drukuj¹ca wynik dzia³ania algorytmu Disjkstry
void Matrix::display_Dijkstra()
{
	system("cls");
	cout << "Node: ";
	for (int i = 0; i < nodes; i++)
	{
		cout << i << "  ";
	}
	cout << "\nDist: ";
	for (int i = 0; i < nodes; i++)
	{
		cout << checked[i].distance; 
		if(checked[i].distance > 9) cout << " ";
		else cout << "  ";
	}
	cout << "\nPrev: ";
	for (int i = 0; i < nodes; i++)
	{
		cout << checked[i].prev;
		if (checked[i].prev > 9) cout << " ";
		else cout << "  ";
	}
	_getche();
}