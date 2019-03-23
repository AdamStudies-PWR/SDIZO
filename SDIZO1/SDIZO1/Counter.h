#pragma once
// Klasa obs�uguj�ca funkcje mierzenia czasu
#include <Windows.h>

using namespace std;

class Counter
{
private:
	double PCFreq = 0.0;
	_int64 CounterStart = 0;
public:
	//Funkcja uruchamiaj�ca odliczanie
	void StartCounter()
	{
		LARGE_INTEGER li;
		if (!QueryPerformanceFrequency(&li)) cout << "\n B��d pomiaru czasu!" << endl;
		PCFreq = double(li.QuadPart)/1000;
		QueryPerformanceCounter(&li);
		CounterStart = li.QuadPart;
	}
	//Funkcja zwracj�ca czas kt�ry up�yn��
	double GetCounter()
	{
		LARGE_INTEGER li;
		QueryPerformanceCounter(&li);
		return double(li.QuadPart - CounterStart) / PCFreq;
	}
};