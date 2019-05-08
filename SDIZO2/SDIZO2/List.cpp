//Implementacja metdo klasy List
#include "pch.h"
#include "List.h"

using namespace std;

//Funkcja losowo tworz¹ca graf
void List::create(int NN, double EE, double ME, bool directed)
{
	system("cls");
	Edge *els;
	Edge *newEdge;
	nodes = NN;
	edges = ME * (EE / 100);
	vector<Node *> vnodes(nodes);
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
					els->target->connections++;
				}
				els = els->next;
			}
			temp = temp->next;
		}
	}
	display();
	while (counter <= edges)
	{
		for (int i = 0; i < nodes; i++) visited[i] = 0;
		begin = rand() % nodes;
		temp = vnodes[begin];
		if (temp->connections == (nodes - 1)) continue;
		els = temp->head;
		for (int i = 0; i < temp->connections; i++)
		{
			visited[els->target->index] = 1;
			els = els->next;
		}
		for (end = 0; end < temp->connections; end++)
		{
			if (end != temp->index && visited[end] == 0) break;
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

		temp->connections++;
		counter++;
	}
	display();
}

//Funkcja wyœwietlaj¹ca graf
void List::display()
{
	//system("cls");
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