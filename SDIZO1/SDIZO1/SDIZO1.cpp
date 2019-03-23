// SDIZO1.cpp : Ten plik zawiera funkcjê „main”. W nim rozpoczyna siê i koñczy wykonywanie programu.

#include "pch.h"
#include "Interface.h"
// main jest w osobnym pliku tylko dlatego, ¿eby by³o go ³atwiej znaleŸæ
int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "pl");
	Interface usr;
	usr.mmenu();
	return 0;
}

