#pragma once
#ifndef Tests_hpp
#define Tests_hpp

//Klasa obs�uguj�ca testowanie i liczenie czasu
class Tests
{
private:
	//Zmienne pomiar czasu
	double PCFreq = 0.0;
	_int64 CounterStart = 0;
protected:
	const static int number = 1000;
	//Zmiennie przechwuj�ce czasy pomiaru
	double dijkstra_results[number];
	double fordbellman_results[number];
	double prim_results[number];
	double kruskal_results[number];
public:
	//Metody
	//Funkcja zapisuj�ca wyniki do pliku
	void save_data(std::string filename, int index);
	//Funkcje mierz�ce czas
	//Uruchumienie pomiaru
	void StartCounter();
	//Pobranie wyniku pomiaru
	double GetCounter();
	//funkcje dodaj�ce wynik pomiaru do odpowiedniej tablicy
	void adddijkstra(double numb, int *index, int where);
	void addford_bellman(double numb, int *index, int where);
	void addprim(double numb, int *index, int where);
	void addkruskal(double numb, int *index, int where);
};
#endif