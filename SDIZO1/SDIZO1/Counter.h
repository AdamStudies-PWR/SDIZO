#pragma once
#ifndef Counter_hpp
#define Counter_hpp
// Klasa obs�uguj�ca funkcje mierzenia czasu
using namespace std;


class Counter
{
private:
	double PCFreq = 0.0;
	_int64 CounterStart = 0;
public:
	//Funkcja uruchamiaj�ca odliczanie
	void StartCounter();
	void StartfileCounter();
	double GetCounter();
};
#endif