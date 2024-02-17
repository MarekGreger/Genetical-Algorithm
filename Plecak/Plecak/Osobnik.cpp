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
#include"Osobnik.h"

#include <chrono>
/// <summary>
/// Metoda generuj¹ca osobnika.
/// </summary>
/// <param name="dane"></param>
/// <param name="Udzwig"></param>
/// <param name="Iloscobiektow"></param>
void Osobnik::Generowanie_Osobnika(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow)
{
	/// <summary>
/// Generujemy osobnika- polega to na tym, ¿e z wektora z przedmiotami losujemy kolejno przedmioty
///  i je¿eli przedmiot wagowo zmieœci siê jeszcze w udzwigu plecaka to dodajemy go.
/// Metoda wykonuje siê tak d³ugo a¿ jakiœ przedmiot w koñcu nie wejdzie do plecaka
/// </summary>
/// <param name="dane">Dane to reczy które wk³adamy do plecaka.</param>
/// <param name="Udzwig">UdŸwig to maksymalna waga jak¹ mo¿e mieæ plecak.</param>
/// <param name="Iloscobiektow">Iloœæ obiektów jest to funkcja która przechowuje ile jest rzeczy które mo¿emy w³o¿yæ do plecaka.</param>
	Pojemnosc = 0;
	int i = rand() % (Iloscobiektow)+0;
	while (Pojemnosc + dane[i].Waga <= Udzwig)
	{
		if (Chromosom[i] == 0)
		{
			Sumaryczna_cena = Sumaryczna_cena + dane[i].Cena;
			Pojemnosc = Pojemnosc + dane[i].Waga;
			Chromosom[i] = 1;
		}
		else
			break;
		i = rand() % (Iloscobiektow)+0;
	}
	Set_Wynik(Sumaryczna_cena / Udzwig);
};
/// <summary>
/// Metoda ta wyœwietla chromosom.
/// </summary>
void Osobnik::Wyswietl_Chromosom()
{
	/// <summary>
	/// Wyœwietlamy chromosom czyli wektor 0 i 1. Wektor ma wielkoœæ wektora z przedmiotami i jest jego reprezentacja w postaci
/// tego który przedmiot jest wziêty (czyli 1), a który nie jest wziêty(czyli 0).
	/// </summary>
	for (int i = 0;i < Chromosom.size();i++)
	{
		std::cout << Chromosom[i] << " ";
	}
};
/// <summary>
/// Metoda ta wyœwietla wynik.
/// </summary>
void Osobnik::Wyswietl_Wynik()
{
	/// <summary>
	/// Wyœwietlamy sumaryczn¹ cenê plecaka, pojemnoœæ oraz wynik.
	/// </summary>
	std::cout << " " << Sumaryczna_cena;
	std::cout << " " << Pojemnosc;
	std::cout << " " << Wynik;

};
/// <summary>
/// Metoda osobnika.
/// </summary>
Osobnik::Osobnik(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow)
{
	/// <summary>
	/// Metoda generuj¹ca osobnika. Najpierw tworzy pusty chromosom, a nastêpnie wywo³ywana jest metoda generowania osobnika.
	/// </summary>
	/// <param name="dane">Przekazujemy wektor obiektów</param>
	/// <param name="Udzwig">Przekazujemy udzwig</param>
	/// <param name="Iloscobiektow">Przekazujemy ilosc obiektow jakie sa w wektorze dane</param>
	Wynik = 0;
	Pojemnosc = 0;
	Sumaryczna_cena = 0;
	for (int i = 0;i < Iloscobiektow;i++)
	{
		Chromosom.push_back(0);
	}
	Generowanie_Osobnika(dane, Udzwig, Iloscobiektow);
};
/// <summary>
/// Metoda aktualizujaca dane.
/// </summary>
void Osobnik::Aktualizuj_Dane(std::vector<Obiekt>& dane, int Udzwig)
{
	/// <summary>
	/// Aktualizujemy dane dla osobnika. Je¿eli jego pojemnoœæ przekroczy maksymalny udŸwig, jego wynik jest zerowany.
	/// </summary>
	/// <param name="dane">Przekazujemy wektor obiektów</param>
	/// <param name="Udzwig">Przekazujemy maksymalny udŸwig</param>
	Pojemnosc = 0;
	Sumaryczna_cena = 0;
	for (int i = 0;i < Chromosom.size();i++)
	{
		if (Chromosom[i] == 1)
		{
			Pojemnosc = Pojemnosc + dane[i].Waga;
			Sumaryczna_cena = Sumaryczna_cena + dane[i].Cena;
		}
	}
	Wynik = Sumaryczna_cena / Udzwig;
	if (Pojemnosc > Udzwig)
	{
		Wynik = 0;
	}
}
/// <summary>
/// Dekonstruktor
/// </summary>
Osobnik::~Osobnik()
{
	/// <summary>
	/// Niszczymy chromosom aby nowy mógl byæ tworzony i uzupe³niany.
	/// </summary>
	Chromosom.clear();
};
/// <summary>
/// Metoda aktualizuj¹ca wynik.
/// </summary>
/// <param name="temp"></param>
void Osobnik::Set_Wynik(double temp)
{
	Wynik = temp;
}
/// <summary>
/// Metoda zwracaj¹ca wynik
/// </summary>
/// <returns></returns>
double  Osobnik::Get_Wynik()
{
	return Wynik;
}
/// <summary>
/// Metoda zwracaj¹ca pojemnoœæ.
/// </summary>
/// <returns></returns>
double  Osobnik::Get_Pojemnosc()
{
	return Pojemnosc;
}
/// <summary>
/// Metoda zwracaj¹ca sumaryczn¹ cenê.
/// </summary>
/// <returns></returns>
double  Osobnik::Get_Sumaryczna_cena()
{
	return Sumaryczna_cena;
}