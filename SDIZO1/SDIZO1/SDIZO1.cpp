// SDIZO1.cpp : Ten plik zawiera funkcj� �main�. W nim rozpoczyna si� i ko�czy wykonywanie programu.

#include "pch.h"
#include "Interface.h"
// main jest w osobnym pliku tylko dlatego, �eby by�o go �atwiej znale��
int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "pl");
	Interface usr;
	usr.mmenu();
	return 0;
}

