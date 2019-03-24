#pragma once
#ifndef Counter_hpp
#define Counter_hpp
// Klasa obsługująca funkcje mierzenia czasu
using namespace std;


class Counter
{
private:
	double PCFreq = 0.0;
	_int64 CounterStart = 0;
public:
	//Funkcja uruchamiająca odliczanie
	void StartCounter();
	double GetCounter();
};
#endif