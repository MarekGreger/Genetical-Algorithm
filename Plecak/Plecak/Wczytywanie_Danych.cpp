#pragma once
#include<iostream>    
#include <ctime>
#include <string>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include<fstream>
#include<map>
#include"Wczytywanie_Danych.h"
#include <chrono>

void Wczytanie_danych(const std::string& nazwapliku, std::vector<Obiekt>& dane)
{/// <summary>
/// Funkcja wczytywanie danych zapisuje dane z pliku do obiekt�w w plecaku.
/// </summary>
/// <param name="nazwapliku">Podajemy nazw� pliku do odczytu</param>
/// <param name="dane">Podajemy wektor obiekt�w czyli reprezentacj� rzeczy jakie mo�emy w�o�y� do plecaka</param>
	bool isopen=false;
	int i = 0;
	try {
		std::ifstream plik(nazwapliku);
		if (!plik.is_open()) { throw - 1; }
		Obiekt Przedmiot;
		while (!plik.eof())
		{
			plik >> Przedmiot.Cena;
			plik >> Przedmiot.Waga;
			dane.push_back(Przedmiot);
			i++;

		}
	}
	catch (int code)
	{
		std::cout << "Nie udalo sie otworzyc pliku, prosze podaj wlasciwa sciezke do pliku zawierajacego dane do wczytania!";

	}
}