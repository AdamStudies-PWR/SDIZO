//Klasa obs³uguj¹ca testowanie i liczenie czasu
#include "pch.h"
#include "Tests.h"

using namespace std;

//Funkcja zapisuj¹ca wyniki do pliku
void Tests::save_data(string filename, int index)
{
	ofstream plik(filename + ".txt");
	if (plik.good() == true)
	{
		plik << ;
	}
}

//Uruchumienie pomiaru
void Tests::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) cout << "\n B³¹d pomiaru czasu!" << endl;
	PCFreq = double(li.QuadPart) / 1000000.0;
	QueryPerformanceCounter(&li);
	CounterStart = li.QuadPart;
}

//Pobranie wyniku pomiaru
double Tests::GetCounter()
{
	LARGE_INTEGER li;
	QueryPerformanceCounter(&li);
	return double(li.QuadPart - CounterStart) / PCFreq;
}
