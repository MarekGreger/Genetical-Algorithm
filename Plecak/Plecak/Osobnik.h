#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "Obiekt.h"
/// <summary>
/// Klasa zawieraj¹ca metody dotycz¹ce pojedyñczego osobnika.
/// </summary>
class Osobnik
{
protected:
	int iteracja = 1;
	double zero = 0;
	int licznik = 0;
	int ile = 0;
	double Wynik;
	double Pojemnosc;
	double Sumaryczna_cena;
public:

	std::vector <int> Chromosom;
	Osobnik(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow);
	void Generowanie_Osobnika(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow);
	void Wyswietl_Chromosom();
	void Wyswietl_Wynik();
	bool operator <(const Osobnik& val) const {
		return Wynik < val.Wynik;
	}
	void Aktualizuj_Dane(std::vector<Obiekt>& dane, int Udzwig);
	void Set_Wynik(double temp);
	double Get_Wynik();
	double Get_Pojemnosc();
	double Get_Sumaryczna_cena();
	~Osobnik();
};