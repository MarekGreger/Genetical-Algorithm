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
#include "Osobnik.h"

/// <summary>
/// Klasa Operacje jest klasa dziedziczaca po klasie osobnik.
/// </summary>
class Operacje :public Osobnik
{
public:
	bool sprawdzajacy;
	Operacje(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow) :Osobnik(dane, Udzwig, Iloscobiektow) {};
	void Wczytywanie_Obiektow(int iloscobiektow, std::vector<Obiekt>& dane);
	void Generowanie_Populacji(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow, int Ilosc_populacji, std::vector<Osobnik>& populacja);
	void Selekcja(std::vector<Osobnik>& populacja);
	void Krzyzowanie(std::vector<Osobnik>& populacja, std::vector<Obiekt>& dane, int Udzwig);
	void Wyswietl_Populacje(std::vector<Osobnik>& populacja);
	void Mutacja(std::vector<Osobnik>& populacja, double Prawdopodobienstwo, std::vector<Obiekt>& dane, int Udzwig);
	void Ocena(std::vector<Osobnik>& populacja);
	void Zapis(const std::string& nazwapliku, std::vector<Osobnik>& populacja);
	~Operacje() {};
	void Set_ile();
	int Get_ile();
};