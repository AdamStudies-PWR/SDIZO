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
void Matrix::dijkstra(int start)
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
	display_Dijkstra(checked, dch);
}

//Funkcja relaksuj¹ca s¹siadów
int Matrix::relax(int index)
{
	Dijkstra *temp;
	int loop;
	int fall = 0;
	int result;
	int small;
	for (int i = 0; i < dnch; i++)
	{
		if (index == notchecked[i].index)
		{
			fall = i;
			break;
		}
	}
	for (int i = 0; i < nodes; i++)
	{
		if (pointer[index][i] != 0)
		{
			for (int j = 0 ; j < dnch; j++)
			{
				if (notchecked[j].index == i)
				{
					if ((notchecked[fall].distance + pointer[index][i]) < notchecked[j].distance || notchecked[j].distance == -1)
					{
						notchecked[j].distance = notchecked[fall].distance + pointer[index][i];
						notchecked[j].prev = notchecked[fall].prev + to_string(index) + ", ";
					}
					break;
				}
			}
		}
	}
	temp = new Dijkstra[dch + 1];
	if (dch == 0) temp[0] = notchecked[fall];
	else
	{
		loop = 0;
		for (int i = 0; i < dch; i++)
		{
			temp[i] = checked[i];
			loop++;
		}
		temp[loop] = notchecked[fall];
		delete[] checked;
	}
	loop = 0;
	checked = temp;
	temp = new Dijkstra[dnch - 1];
	for (int i = 0; i < (dnch - 1); i++)
	{
		if (i == fall)
		{
			loop++;
			temp[i] = notchecked[loop];
		}
		else
		{
			temp[i] = notchecked[loop];
		}
		loop++;
	}
	delete[] notchecked;
	notchecked = temp;
	result = notchecked[0].index;
	small = 10000000;
	for (int i = 0; i < (dnch - 1); i++)
	{
		if (notchecked[i].distance != -1)
		{
			if (notchecked[i].distance < small)
			{
				result = notchecked[i].index;
				small = notchecked[i].distance;
			}
		}
	}
	return result;
}

//Funckja obs³uguj¹ca algorytm prima
void Matrix::mst_Prim(int start)
{
	Prim *temp;
	int min, loop, fall;
	mst_size = 0;
	fall = start;
	sol = 0;
	nsol = nodes;
	notSolved = new Prim[nsol];
	for (int i = 0; i < nsol; i++) notSolved[i].index = i;
	while (sol != nodes)
	{
		for (int i = 0; i < nodes; i++)
		{
			if (pointer[fall][i] != 0)
			{
				for (int j = 0; j < nsol; j++)
				{
					if (notSolved[j].index == i)
					{
						if (notSolved[j].distance > pointer[fall][i] || notSolved[j].distance == 0)
						{
							notSolved[j].distance = pointer[fall][i];
							notSolved[j].prev = fall;
						}
						break;
					}
				}
			}
		}
		mst_size = mst_size + notSolved[start].distance;
		sol++;
		nsol--;
		//Zwiêkszanie listy rozwi¹zanych
		temp = new Prim[sol];
		loop = 0;
		if (sol == 1) temp[0] = notSolved[start];
		else
		{
			for (int i = 0; i < (sol - 1); i++)
			{
				temp[i] = solved[i];
				loop++;
			}
			temp[loop] = notSolved[start];
			delete[] solved;
		}
		solved = temp;
		//Zmiejszanie listy nie rozwi¹zanych
		loop = 0;
		temp = new Prim[nsol];
		for (int i = 0; i < nsol; i++)
		{
			if (i == start)
			{
				loop++;
				temp[i] = notSolved[loop];
			}
			else
			{
				temp[i] = notSolved[loop];
			}
			loop++;
		}
		delete[] notSolved;
		notSolved = temp;
		min = 100;
		for (int i = 0; i < nsol; i++)
		{
			if (notSolved[i].distance < min && notSolved[i].distance != 0)
			{
				start = i;
				fall = notSolved[i].index;
				min = notSolved[i].distance;
			}
		}
	}
	display_Prim(solved, sol);
	delete[] solved;
}

//Funkcja obs³uguj¹ca algorytm Kruskala
void Matrix::mst_Kruskal()
{
	bool found;
	int *temp;
	int index2, ind, tab, tab2;
	mst_size = 0;
	cnt = 0;
	t_size = nodes;
	sizes = new int[t_size];
	tree = new int*[t_size];
	int index = 0;
	for (int i = 0; i < t_size; i++)
	{
		temp = new int[1];
		temp[0] = i;
		tree[i] = temp;
		sizes[i] = 1;
	}
	line = new Kruskal[edges];
	for (int i = 0; i < nodes; i++)
	{
		for (int j = i; j < nodes; j++)
		{
			if (pointer[i][j] != 0)
			{
				line[index].source = i;
				line[index].target = j;
				line[index].weight = pointer[i][j];
				index++;
			}
			if (index == edges) break;
		}
		if (index == edges) break;
	}
	sort(line);
	result = new Kruskal[(nodes - 1)];
	ind = -1;
	while (cnt != (nodes - 1))
	{
		ind++;
		index = line[ind].source;
		index2 = line[ind].target;
		found = false;
		for (int i = 0; i < t_size; i++)   
		{
			for (int j = 0; j < sizes[i]; j++)
			{
				if (tree[i][j] == line[ind].source) tab = i;
				if (tree[i][j] == line[ind].target) tab2 = i;
			}
		}
		if (tab == tab2) continue;
		result[cnt] = line[ind];
		cnt++;
		if (tab > tab2) connect(tab2, tab);
		else connect(tab, tab2);
	}
	for (int i = 0; i < (nodes - 1); i++) mst_size = mst_size + result[i].weight;
	display_Kruskal(result, nodes - 1);
	delete[] result;
	delete[] line;
	delete[] tree;
}

//Funkcja obs³uguj¹ca algorytm Forda-Bellmana
void Matrix::ford_bellman(int node)
{

}