// Klasa obs³uguj¹ca funkcje mierzenia czasu
#include "pch.h"
#include "Counter.h"

//Funkcja uruchamiaj¹ca odliczanie
void Counter::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) cout << "\n B³¹d pomiaru czasu!" << endl;
	PCFreq = double(li.QuadPart) / 1000;
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}
//Funkcja zwracj¹ca czas który up³yn¹³
double Counter::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}