//Implementacja metdo klasy List
#include "pch.h"
#include "List.h"

using namespace std;

//Funkcja losowo tworz¹ca graf
void List::create(int NN, double EE, double ME, bool directed)
{
	Edge *els;
	Edge *newEdge;
	Edge *revEdge;
	nodes = NN;
	edges = ME * (EE / 100);
	Node **vnodes = new Node*[nodes];
	int *visited = new int[nodes];
	head = new Node();
	int counter = nodes;
	int begin, end;
	spanningtree();
	Node *temp = head;
	for (int i = 0; i < nodes; i++)
	{
		vnodes[i] = temp;
		temp = temp->next;
	}
	if (!directed)
	{
		temp = head;
		while (temp != nullptr)
		{
			els = temp->head;
			while (els != nullptr)
			{
				if (els->target->index > temp->index)
				{
					newEdge = new Edge();
					newEdge->target = els->source;
					newEdge->source = els->target;
					newEdge->weight = els->weight;
					if (els->target->head == nullptr)
					{
						els->target->head = newEdge;
						els->target->tail = newEdge;
					}
					else
					{
						els->target->tail->next = newEdge;
						els->target->tail = newEdge;
					}
					if (!directed)
					{
						revEdge = new Edge();
						revEdge->target = newEdge->source;
					}
					els->target->connections++;
				}
				els = els->next;
			}
			temp = temp->next;
		}
	}
	while (counter <= edges)
	{
		for (int i = 0; i < nodes; i++) visited[i] = 0;
		begin = rand() % nodes;
		temp = vnodes[begin];
		if (temp->connections == (nodes - 1)) continue;
		els = temp->head;
		for (int i = 0; i < (temp->connections); i++)
		{
			visited[els->target->index] = 1;
			els = els->next;
		}
		for (end = 0; end < (temp->connections + 1); end++)
		{
			if (end != (temp->index) && visited[end] == 0) break;
		}
		newEdge = new Edge();
		newEdge->weight = (rand() % 99) + 1;
		newEdge->source = temp;
		newEdge->target = vnodes[end];
		if (temp->head == nullptr)
		{
			temp->head = newEdge;
			temp->tail = newEdge;
		}
		else
		{
			temp->tail->next = newEdge;
			temp->tail = newEdge;
		}
		if (!directed)
		{
			revEdge = new Edge();
			revEdge->target = newEdge->source;
			revEdge->source = newEdge->target;
			revEdge->weight = newEdge->weight;
			if (revEdge->source->head == nullptr)
			{
				revEdge->source->head = revEdge;
				revEdge->source->tail = revEdge;
			}
			else
			{
				revEdge->source->tail->next = revEdge;
				revEdge->source->tail = revEdge;
			}
			revEdge->source->connections++;
		}
		temp->connections++;
		counter++;
	}
	display();
	delete visited;
	delete vnodes;
}

//Funkcja wyœwietlaj¹ca graf
void List::display()
{
	system("cls");
	if (head == nullptr) cout << "Graf nie istnieje!" << endl;
	else
	{
		cout << "\nWierzcho³ki: " << nodes << ", Krawêdzie: " << edges;
		cout << "\nLista:\n" << endl;
		Node *temp = head;
		while (temp != nullptr)
		{
			cout << temp->index << ": ";
			Edge *out = temp->head;
			while (out != nullptr)
			{
				cout << out->target->index << "|" << out->weight << " ";
				out = out->next;
			}
			temp = temp->next;
			cout << endl;
		}
	}
	_getche();
}

//Funkcja towrz¹ca drzewo rozpinaj¹ce dla nieskierowanego
void List::spanningtree()
{
	tail = head;
	Node *create = head;
	Node *newNode;
	Edge *child;
	int children, count, rr, ii;
	int created = 1;
	do
	{
		count = 0;
		children = (rand() % 2) + 2;
		do
		{
			child = new Edge();
			child->source = create;
			newNode = new Node();
			child->target = newNode;
			newNode->index = created;
			created++;
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			child->weight = (rand() % 99) + 1;
			if (create->head == nullptr)
			{
				create->head = child;
				create->tail = child;
			}
			else
			{
				create->tail->next = child;
				create->tail = child;
			}
			create->connections++;
			count++;
			if (created == nodes) return;
		} while (count != children);
		while (create->head != nullptr)
		{
			rr = rand() % (created);
			create = head;
			for (ii = 0; ii < rr; ii++)
			{
				create = create->next;
			}
		}
	} while (created != nodes);
}

void List::dijkstra(int start)
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

int List::relax(int index)
{
	Dijkstra *temp;
	Node *iter = head;
	Edge *els;
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
	for (int i = 0; i < index; i++) iter = iter->next;
	els = iter->head;
	while (els != nullptr)
	{
		for (int i = 0; i < dnch; i++)
		{
			if (notchecked[i].index == els->target->index)
			{
				if ((notchecked[fall].distance + els->weight) < notchecked[i].distance || notchecked[i].distance == -1)
				{
					notchecked[i].distance = notchecked[fall].distance + els->weight;
					notchecked[i].prev = notchecked[fall].prev + to_string(index) + ", ";
				}
				break;
			}
		}
		els = els->next;
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
void List::mst_Prim(int start)
{
	Prim *temp;
	Node *iter;
	Edge *els;
	int min, index, old, loop, before;
	mst_size = 0;
	sol = 1;
	nsol = (nodes - 1);
	solved = new Prim[sol];
	notSolved = new Prim[nsol];
	solved[0].distance = 0;
	solved[0].index = start;
	int ii = 0;
	for (int i = 0; i < nsol; i++)
	{
		if (i != start) notSolved[i].index = ii;
		else
		{
			notSolved[i].index = ii + 1;
			ii++;
		}
		ii++;
	}
	while (sol != nodes)
	{
		min = 100;
		for (int i = 0; i < sol; i++)
		{
			iter = head;
			for (int j = 0; j < nodes; j++)
			{
				if (notSolved[i].index = j) break;
				iter = iter->next;
			}
			els = iter->head;
			while (els != nullptr)
			{
				for (int m = 0; m < nsol; m++)
				{
					if (notSolved[m].index == els->target->index)
					{
						if (els->weight < min)
						{
							min = els->weight;
							index = els->target->index;
							before = els->source->index;
						}
					}
				}
				els = els->next;
			}
			/*for (int j = 0; j < nodes; j++)
			{
				for (int m = 0; m < nsol; m++)
				{
					if (notSolved[m].index == j)
					{
						if (pointer[start][j] != 0)
						{
							if (pointer[start][j] < min)
							{
								min = pointer[start][j];
								index = j;
								before = start;
							}
						}
					}
				}
			}*/
		}
		if (min == 100) return;
		mst_size = mst_size + min;
		for (int i = 0; i < nsol; i++)
		{
			if (index == notSolved[i].index)
			{
				notSolved[i].distance = min;
				notSolved[i].prev = before;
				old = i;
				break;
			}
		}
		sol++;
		nsol--;
		//Zwiêkszanie listy rozwi¹zanych
		temp = new Prim[sol];
		loop = 0;
		for (int i = 0; i < (sol - 1); i++)
		{
			temp[i] = solved[i];
			loop++;
		}
		temp[loop] = notSolved[old];
		delete[] solved;
		solved = temp;
		//Zmiejszanie listy nie rozwi¹zanych
		loop = 0;
		temp = new Prim[nsol];
		for (int i = 0; i < nsol; i++)
		{
			if (i == old)
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
		display_Prim(solved, sol);
		display_Prim(notSolved, nsol);
	}
	display_Prim(solved, sol);
}
