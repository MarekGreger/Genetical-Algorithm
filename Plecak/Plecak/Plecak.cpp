#include<iostream>    
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include"Osobnik.h"
#include"Obiekt.h"
#include"Operacje.h"
#include"Wczytywanie_Danych.h"
#include "Obsluga_bledow.h"

using namespace std;

int main(int argc, char* argv[])
{

	if (Obsluga_bledow(argc, 10, 10,10) == false)
		return 0;
	int Udzwig_Plecaka = atoi(argv[3]);
	int Rozmiar_Populacji = atoi(argv[4]);
	std::vector<Obiekt> Dane;
	std::vector<Osobnik> Populacja;
	Wczytanie_danych(argv[1], Dane);
	int Ilosc_Rzeczy = Dane.size();
	if (Obsluga_bledow(argc, Udzwig_Plecaka, Rozmiar_Populacji,Ilosc_Rzeczy) == false)
		return 0;
	Operacje* Test=new Operacje(Dane, Udzwig_Plecaka,Ilosc_Rzeczy);
	srand(time(NULL));
	Test->Generowanie_Populacji(Dane, Udzwig_Plecaka, Ilosc_Rzeczy, Rozmiar_Populacji, Populacja);
	Test->Selekcja(Populacja);
	Test->Wyswietl_Populacje(Populacja);
	Test->Ocena(Populacja);
	while (Test->sprawdzajacy==false)
	{
		Test->Krzyzowanie(Populacja, Dane, Udzwig_Plecaka);
		//Wyswietl_Populacje(Populacja);
		Test->Mutacja(Populacja, 0.1, Dane, Udzwig_Plecaka);
		Test->Selekcja(Populacja);
		if (atoi(argv[5])==1)
		{
			cout << "\n Aktualizowana populacja ";
			Test->Wyswietl_Populacje(Populacja);
		}
		Test->Ocena(Populacja);
		Test->Set_ile();
	}
	cout << endl << Test->Get_ile();
	cout << "\n Koncowa populacja ";
	Test->Wyswietl_Populacje(Populacja);
	Test->Zapis(argv[2], Populacja);
	Populacja.clear();
}
