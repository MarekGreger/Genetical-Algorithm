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
#include"nazwy.h"
#include <chrono>
/// <summary>
///  Funkcja ta przyjmuje ilosc przedmiot�w kt�re mo�emy upakowa� do plecaka oraz wektor tych przedmiot�w.
/// Tworzymy wektor zawieraj�cy ceny i wagi poszczeg�lnych przedmiot�w.
/// </summary>
/// <param name="iloscobiektow"></param>
/// <param name="dane"></param>
void Operacje::Wczytywanie_Obiektow(int Iloscobiektow, std::vector<Obiekt> &dane)
{
	//srand(time(NULL));
	Obiekt Przedmiot;
	for (int i = 1;i <= Iloscobiektow;i++)
	{
		Przedmiot.Cena = rand() % 100+1;
		Przedmiot.Waga = rand() % 10+1;
		dane.push_back(Przedmiot);
	}
}
/// <summary>
/// Generujemy osobnika- polega to na tym, �e z wektora z przedmiotami losujemy kolejno przedmioty
///  i je�eli przedmiot wagowo zmie�ci si� jeszcze w udzwigu plecaka to dodajemy go.
/// Funkcja wykonuje si� tak d�ugo a� jaki� przedmiot w ko�cu nie wejdzie do plecaka
/// </summary>
/// <param name="dane"></param>
/// <param name="Udzwig"></param>
/// <param name="Iloscobiektow"></param>
void Osobnik::Generowanie_Osobnika(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow)
{
	Pojemnosc = 0;
	int i = rand() % (Iloscobiektow)+0;
	while (Pojemnosc + dane[i].Waga <= Udzwig)
	{
		if (Chromosom[i]==0)
		{
			Sumaryczna_cena = Sumaryczna_cena+dane[i].Cena;
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
/// Funkcja ta wy�wietla chromosom czyli wektor 0 i 1. Wektor ma wielko�� wektora z przedmiotami i jest jego reprezentacja w postaci
/// tego kt�ry przedmiot jest wzi�ty (czyli 1), a kt�ry nie jest wzi�ty(czyli 0).
/// </summary>
void Osobnik::Wyswietl_Chromosom()
{
	for (int i = 0;i <Chromosom.size();i++)
	{
		std::cout << Chromosom[i] << " ";
	}
};
/// <summary>
/// Funkcja ta wy�wietla wynik.
/// </summary>
void Osobnik::Wyswietl_Wynik()
{
	std::cout << " " << Sumaryczna_cena;
	std::cout << " " << Pojemnosc;
	std::cout <<" "<< Wynik;
	
};
/// <summary>
/// Kontruktor- podajemy wektor z przedmiotami, ud�wig oraz ilo�� przedmiot�w kt�re generuje nasz program losowo.
/// W tym konstruktorze wywo�uje si� metoda generuj�ca osobnika, wy�wietlaj�ca chromosom oraz wynik.
/// </summary>
/// <param name="dane"></param>
/// <param name="Udzwig"></param>
/// <param name="Iloscobiektow"></param>
Osobnik::Osobnik(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow) 
{
	Wynik=0;
	Pojemnosc = 0;
	Sumaryczna_cena=0;
	for (int i = 0;i < Iloscobiektow;i++)
	{
		Chromosom.push_back(0);
	}
	Generowanie_Osobnika(dane, Udzwig, Iloscobiektow);
};
/// <summary>
/// <---------------------------------------------------------------------------dodaj komentarz!
/// </summary>
void Osobnik::Aktualizuj_Dane(std::vector<Obiekt>& dane, int Udzwig)
{

	Pojemnosc = 0;
	Sumaryczna_cena = 0;
	for (int i = 0;i < Chromosom.size();i++) 
	{
		if (Chromosom[i] == 1)
		{
			Pojemnosc = Pojemnosc + dane[i].Waga;
			Sumaryczna_cena = Sumaryczna_cena+ dane[i].Cena;
		}
	}
	Wynik = Sumaryczna_cena / Udzwig;
	if (Pojemnosc > Udzwig)
	{
		Wynik = 0;
	}
}
/// <summary>
/// Dekonstruktor- niszczymy chromosom aby nowy m�gl by� tworzony i uzupe�niany.
/// </summary>
Osobnik::~Osobnik()
{
	Chromosom.clear();
};

void Osobnik::Set_Wynik(double temp)
{
	Wynik = temp;
}
double  Osobnik::Get_Wynik()
{
	return Wynik;
}
double  Osobnik::Get_Pojemnosc()
{
	return Pojemnosc;
}
double  Osobnik::Get_Sumaryczna_cena()
{
	return Sumaryczna_cena;
}