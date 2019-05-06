//Implementacja metdo klasy List
#include "pch.h"
#include "List.h"

using namespace std;

//Funkcja losowo tworz�ca graf
void List::create(int NN, double EE, int ME, bool directed)
{
	nodes = NN;
	edges = ME * (EE / 100);
	int *visited = new int[nodes];
	for (int i = 0; i < nodes; i++) visited[i] = 0;
	head = new Node();
	spanningtree(visited);

	display();
}

//Funkcja wy�wietlaj�ca graf
void List::display()
{
	system("cls");
	if (head == nullptr) cout << "Graf nie istnieje!" << endl;
	else
	{
		cout << "Lista:\n" << endl;
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

void List::spanningtree(int *visited)
{
	tail = head;
	Node *create = head;
	Node *newNode;
	Edge *child;
	Edge *temp;
	int children, count, rr;
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
		while (true)
		{
			rr = rand() % (created - 1);
			create = head;
			for (int i = 0; i < rr; i++);
			{
				create = create->next;
			}
			if (create->head == nullptr) break;
		}
	} while (created != nodes);
}