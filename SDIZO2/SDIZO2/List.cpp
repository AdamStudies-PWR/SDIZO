//Implementacja metdo klasy List
#include "pch.h"
#include "List.h"

using namespace std;

//Funkcja losowo tworz¹ca graf
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

//Funkcja wyœwietlaj¹ca graf
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
				cout << out->target << "|" << out->weight << " ";
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
	Node *create = head;
	Edge *child;
	int children, count;
	int node = 0;
	int created = 1;
	visited[node] = 1;
	do
	{
		count = 0;
		children = (rand() % 2) + 2;
		do
		{
			if (create->head == nullptr)
			{
				child = new Edge();
				child->source = create;
			}
			if (created == nodes) return;

		} while (count != children);
	} while (created != nodes);
}