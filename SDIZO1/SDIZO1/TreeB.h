#pragma once
// Klasa obs³uguj¹ca funkcje drzewa binarnego
#include "pch.h"

struct Node
{
	int data;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *parent = nullptr;
};

class TreeB
{
private:
	int size = 0;
	Node *head;
public:
	void display()
	{
		Node *out = head;
		system("cls");
		if (head == nullptr) cout << "Drzewo jest puste" << endl;
		else
		{
			cout << out->data << "(";
			while (out->left == nullptr || out->right == nullptr)
			{

			}
			cout << ")";
		}
	}
};