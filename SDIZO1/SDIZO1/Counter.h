#pragma once
// Klasa obs³uguj¹ca funkcje mierzenia czasu
#include <Windows.h>

using namespace std;

class Counter
{
private:
	double PCFreq = 0.0;
	_int64 CounterStart = 0;
public:
	//Funkcja uruchamiaj¹ca odliczanie
	void StartCounter()
	{
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li)) cout << "\n B³¹d pomiaru czasu!" << endl;
		PCFreq = double(li.QuadPart)/1000;
		QueryPerformanceCounter(&li);
		CounterStart = li.QuadPart;
	}
	//Funkcja zwracj¹ca czas który up³yn¹³
	double GetCounter()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return double(li.QuadPart - CounterStart) / PCFreq;
	}
};