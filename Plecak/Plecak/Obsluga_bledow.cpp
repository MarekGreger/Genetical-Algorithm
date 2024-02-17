#include<iostream>    
#include <ctime>
#include <string>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
#include<fstream>
#include<map>
#include <chrono>
using namespace std;

bool Obsluga_bledow(const int& argc,int Udzwig_Plecaka,int Rozmiar_Populacji, int Ilosc_Rzeczy)
{
/// <summary>
/// Funkcja majaca na celu zabezpieczyæ kod przed b³êdamami w podaniu danych.
/// </summary>
/// <param name="argc">Przekazywana wartoœæ argc</param>
/// <param name="Udzwig_Plecaka">Przekazywany udŸwig plecaka</param>
/// <param name="Rozmiar_Populacji">Przekazywany rozmiar populacji</param>
/// <returns></returns>
	if (argc!=6)
	{
		cout << " Niewlasciwa ilosc argumentow! Podaj: Plik wyj, Plik wej, Udzwig, Populacja, oraz czy chcesz wyœwietliæ populacjê- jeœli tak podaj 1 jako ostatni argument.";
		return false;
	}
	else if (Udzwig_Plecaka < 1)
	{
		cout << " Udzwig plecaka powinien minimalnie wynosic 2";
		return false;
	}
	else if (Rozmiar_Populacji < 6)
	{
		cout << " Populacja powinna wynosic minimalnie 4";
		return false;
	}
	else if (Ilosc_Rzeczy == 1)
	{
		cout << "Pusty plik.";
		return 0;
	}
	return true;
}