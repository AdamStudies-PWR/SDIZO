//Implementacja metdo klasy List
#include "pch.h"
#include "List.h"

using namespace std;

//Funkcja losowo tworz¹ca graf
void List::create(int NN, double EE, double ME, bool directed)
{
	bool np;
	system("cls");
	Node *temp;
	Node *direct;
	Edge *els;
	Edge *newEdge;
	Edge *edge;
	nodes = NN;
	edges = ME * (EE / 100);
	head = new Node();
	int counter = nodes;
	int begin, end;
	spanningtree();
	els = head->head;
	edge = head->head;
	while (counter <= edges)
	{
		np = false;
		temp = head;
		direct = head;
		begin = rand() % nodes;
		end = rand() % nodes;
		if (begin == end) continue;
		for (int i = 0; i < begin; i++) temp = temp->next;
		for (int i = 0; i < end; i++) direct = direct->next;
		newEdge = temp->head;
		while (newEdge != nullptr)
		{
			if (newEdge->target->index == end)
			{
				np = true;
				break;
			}
			els = newEdge;
			newEdge = newEdge->next;
		}
		if (!directed)
		{
			newEdge = direct->head;
			while (newEdge != nullptr)
			{
				if (newEdge->target->index == begin)
				{
					np = true;
					break;
				}
				newEdge = newEdge->next;
			}
		}
		if (np) continue;
		newEdge = new Edge();
		newEdge->weight = (rand() % 99) + 1;
		newEdge->target = direct;
		newEdge->source = temp;
		if (temp->head == nullptr) temp->head = newEdge;
		else els->next = newEdge;
		counter++;
	}
	if (!directed)
	{
		temp = head;
		while (temp != nullptr)
		{
			els = temp->head;
			while (els != nullptr)
			{
				np = false;
				begin = els->source->index;
				edge = els->target->head;
				while (edge != nullptr)
				{
					if (edge->target->index == begin)
					{
						np = true;
						break;
					}
					edge = edge->next;
				}
				if (np)
				{
					els = els->next;
					continue;
				}
				edge = els->target->head;
				newEdge = new Edge();
				if (edge == nullptr) edge = newEdge;
				else while (edge->next != nullptr) edge = edge->next;
				edge->next = newEdge;
				newEdge->source = els->target;
				newEdge->target = els->source;
				newEdge->weight = els->weight;
				els = els->next;
			}
			temp = temp->next;
		}
	}
	display();
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

void List::spanningtree()
{
	tail = head;
	Node *create = head;
	Node *newNode;
	Edge *child;
	Edge *temp;
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
			if (create->head == nullptr) create->head = child;
			else
			{
				temp = create->head;
				while (temp->next != nullptr) temp = temp->next;
				temp->next = child;
			}
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