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
	if (!testing) display();
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

//Funkcja obs³uguj¹ca algorytm Dijsktry
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
	if(!testing) display_Dijkstra(checked, dch);
}

//Funkcja relaksuj¹ca s¹siadów
int List::relax(int index)
{
	Dijkstra *temp;
	Node *iter = head;
	Edge *els;
	int loop;
	int fall = 0;
	int result;
	int mini;
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
	mini = 10000000;
	for (int i = 0; i < (dnch - 1); i++)
	{
		if (notchecked[i].distance != -1)
		{
			if (notchecked[i].distance < mini)
			{
				result = notchecked[i].index;
				mini = notchecked[i].distance;
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
	int min, loop, fall;
	mst_size = 0;
	fall = start;
	sol = 0;
	nsol = nodes;
	notSolved = new Prim[nsol];
	for (int i = 0; i < nsol; i++) notSolved[i].index = i;
	while (sol != nodes)
	{
		iter = head;
		for (int i = 0; i < fall; i++) iter = iter->next;
		els = iter->head;
		while (els != nullptr)
		{
			if (els->weight != 0)
			{
				for (int j = 0; j < nsol; j++)
				{
					if (notSolved[j].index == els->target->index)
					{
						if (notSolved[j].distance > els->weight || notSolved[j].distance == 0)
						{
							notSolved[j].distance = els->weight;
							notSolved[j].prev = els->source->index;
						}
						break;
					}
				}
			}
			els = els->next;
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
	if (!testing) display_Prim(solved, sol);
}

//Funkcja obs³uguj¹ca algorytm Kruskala
void List::mst_Kruskal()
{
	Node *iter = head;
	Edge *els;
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
		els = iter->head;
		while (els != nullptr)
		{
			if (els->target->index < i)
			{
				line[index].source = i;
				line[index].target = els->target->index;
				line[index].weight = els->weight;
				index++;
			}
			els = els->next;
		}
		iter = iter->next;
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
	if (!testing) display_Kruskal(result, nodes - 1);
	delete[] result;
	delete[] line;
	delete[] tree;
}

//Funkcja obs³uguj¹ca algorytm Forda-Bellmana
void List::ford_bellman(int start)
{
	Node *temp = head;
	Edge *els;
	dnch = nodes;
	notchecked = new Dijkstra[dnch];
	for (int i = 0; i < dnch; i++)
	{
		notchecked[i].index = i;
	}
	notchecked[start].distance = 0;
	for (int i = 0; i < start; i++) temp = temp->next;
	els = temp->head;
	for (int i = 0; i < nodes; i++)
	{
		if (els->target->index == i)
		{
			notchecked[i].distance = notchecked[start].distance + els->weight;
			notchecked[i].prev = notchecked[start].prev + to_string(start) + ", ";
		}
		else if (start != i)
		{
			notchecked[i].distance = 0;
			notchecked[i].prev = notchecked[start].prev + to_string(start) + ", ";
		}
	}
	for (int i = 1; i < (nodes - 1); i++)
	{
		temp = head;
		for (int j = 0; j < nodes; j++)
		{
			els = temp->head;
			while(els != nullptr)
			{
				if (els->target->index != start)
				{
					if ((notchecked[els->source->index].distance + els->weight) < notchecked[els->target->index].distance || notchecked[els->target->index].distance == 0)
					{
						notchecked[els->target->index].distance = notchecked[els->source->index].distance + els->weight;
						notchecked[els->target->index].prev = notchecked[els->source->index].prev + to_string(els->source->index) + ", ";
					}
				}
				els = els->next;
			}
			temp = temp->next;
		}
	}
	if (!testing) display_Dijkstra(notchecked, dnch);
	delete[] notchecked;
}