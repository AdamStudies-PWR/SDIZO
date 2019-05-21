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
		plik << "Dijkstra;Ford-Bellman;Prim;Kruskal" << endl;
		for (int i = 0; i < 100; i++)
		{
			plik << dijkstra_results[index] << ";" << fordbellman_results[index] << ";" << prim_results[index] << ";" << kruskal_results[index] << endl;
			index++;
		}
		plik.close();
	}
	else
	{
		cout << "B³¹d zapisu!" << endl;
		_getche();
	}
}

//Uruchumienie pomiaru
void Tests::StartCounter()
{
	LARGE_INTEGER li;
	if (!QueryPerformanceFrequency(&li)) cout << "\n B³¹d pomiaru czasu!" << endl;
	PCFreq = double(li.QuadPart) / 10;
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

//Funkcje dodaj¹ce wartoœci do odpowiednich tabeli
void Tests::adddijkstra(double numb, int *index, int where)
{
	dijkstra_results[index[where]] = numb;
	index[where]++;
}

void Tests::addford_bellman(double numb, int *index, int where)
{
	fordbellman_results[index[where]] = numb;
	index[where]++;
}

void Tests::addprim(double numb, int *index, int where)
{
	prim_results[index[where]] = numb;
	index[where]++;
}

void Tests::addkruskal(double numb, int *index, int where)
{
	kruskal_results[index[where]] = numb;
	index[where]++;
}

