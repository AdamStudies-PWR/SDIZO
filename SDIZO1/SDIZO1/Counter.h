#pragma once
#ifndef Counter_hpp
#define Counter_hpp
// Klasa obs³uguj¹ca funkcje mierzenia czasu
using namespace std;

//Klasa odpowiedzialna za obliczanie czasu
class Counter
{
private:
	//Zmienne potrzebne do obliczania czasu
	double PCFreq = 0.0;
	_int64 CounterStart = 0;
public:
	//Metody
	void StartCounter();
	void StartfileCounter();
	double GetCounter();
};
#endif