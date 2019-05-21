#pragma once
#ifndef Automatic_hpp
#define Automatic_hpp
#include "Tests.h"
#include "Matrix.h"
#include "List.h"

//Testowanie
void loop_tests(Matrix mat, List list, int size)
{
	system("cls");
	Tests testing;
	int aa = 100;
	int bb = 200;
	int cc = 300;
	for (int ii = 0; ii < 100; ii++)
	{
		cout << (ii + 1) << endl;
	}
	cout << "\nTestowanie zakoñczone!" << endl;
	_getche();
}

#endif