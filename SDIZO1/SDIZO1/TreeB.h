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
};