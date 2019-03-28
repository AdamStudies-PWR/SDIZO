// Klasa obs�uguj�ca funkcje mierzenia czasu
#include "pch.h"
#include "Counter.h"

//Funkcja uruchamiaj�ca odliczanie
void Counter::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) cout << "\n B��d pomiaru czasu!" << endl;
	PCFreq = double(li.QuadPart)/1000000.0;
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
//Funkcja uruchamiaj�ca odliczanie w sekundach
void Counter::StartfileCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) cout << "\n B��d pomiaru czasu!" << endl;
	PCFreq = double(li.QuadPart)/100.0;
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
//Funkcja zwracj�ca czas kt�ry up�yn��
double Counter::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}