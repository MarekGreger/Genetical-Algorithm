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
#include"Operacje.h"
#include <chrono>
/// <summary>
/// Metoda odczytuj¹ca z pliku dane do wektora obiektów.
/// </summary>
void Operacje::Wczytywanie_Obiektow(int Iloscobiektow, std::vector<Obiekt>& dane)
{
	/// <summary>
///  Funkcja ta przyjmuje ilosc przedmiotów które mo¿emy upakowaæ do plecaka oraz wektor tych przedmiotów.
/// Tworzymy wektor zawieraj¹cy ceny i wagi poszczególnych przedmiotów.
/// </summary>
/// <param name="iloscobiektow">Iloœæ wszystkich przedmiotów</param>
/// <param name="dane">Wektor wszystkich przedmiotów</param>
	//srand(time(NULL));
	Obiekt Przedmiot;
	for (int i = 1;i <= Iloscobiektow;i++)
	{
		Przedmiot.Cena = rand() % 100 + 1;
		Przedmiot.Waga = rand() % 10 + 1;
		dane.push_back(Przedmiot);
	}
}
/// <summary>
/// Metoda generuj¹ca populacjê.
/// </summary>
void Operacje::Generowanie_Populacji(std::vector<Obiekt>& dane, int Udzwig, int Iloscobiektow, int Ilosc_populacji, std::vector<Osobnik>& populacja)
{
	/// <summary>
/// Generujemy populacjê czyli tyle osobników (zape³nionych plecaków) ile podamy w parametrze funkcji. 
/// Przekazujemy wektor przedmiotów, udŸwig, iloœæ obiektów wygenerowanych oraz wektor populacji do którego bêdziemy osobników dodawaæ.
/// </summary>
/// <param name="dane">Wektor obiektów</param>
/// <param name="Udzwig">Maksymalny udŸwig</param>
/// <param name="Iloscobiektow">Iloœæ obiektów</param>
/// <param name="Ilosc_populacji">Iloœæ populacji</param>
/// <param name="populacja">Wektor populacji</param>
	for (int i = 0;i < Ilosc_populacji;i++)
	{
		Osobnik Plecak(dane, Udzwig, Iloscobiektow);
		populacja.push_back(Plecak);
	}
};
/// <summary>
/// Metoda selekcji czyli wyboru najlepszych osobników
/// </summary>
void Operacje::Selekcja(std::vector<Osobnik>& populacja/*,std::vector<Osobnik>& nowapopulacja*/)
{
/// <summary>
/// Selekcja polega na tym, ¿e sortujemy nasz wektor za pomoc¹ przeci¹¿onego operatora porównania.
/// Przekazujemy wektor osobników. 
/// </summary>
/// <param name="populacja">Wektor populacji</param>
	int j = 0;
	std::sort(populacja.begin(), populacja.end());
}
/// <summary>
/// Metoda krzy¿owania
/// </summary>

void Operacje::Krzyzowanie(std::vector<Osobnik>& populacja, std::vector<Obiekt>& dane, int Udzwig)
{
	/// <summary>
	/// Metoda krzyzowania najlepszych osobników, krzy¿ujemy ze sob¹ po³owê populacji. Dwóch rodziców tworzy dwójkê dzieci.
	/// Losowany jest punkt przeciêcia chromosomu, jedna czêœæ chromosomu idzie do pierwszego dziecka, a druga do drugiego.
	/// </summary>
	/// <param name="populacja">Wektor populacji</param>
	/// <param name="dane">Wektor obiektów</param>
	/// <param name="Udzwig">Maksymalny udŸwig</param>
	int j = 0;
	int wielkosc = populacja[0].Chromosom.size();
	int przeciecie = rand() % (populacja[0].Chromosom.size() - 1) + 1;
	if ((populacja.size() / 2) % 2 == 0)
	{
		for (int i = (populacja.size() / 2);i < populacja.size();i += 2)
		{
			for (int h = 0;h < przeciecie;h++)
			{
				populacja[j].Chromosom[h] = populacja[i].Chromosom[h];
				populacja[j + 1].Chromosom[h] = populacja[i + 1].Chromosom[h];
			}
			for (int h = przeciecie;h < wielkosc;h++)
			{
				populacja[j + 1].Chromosom[h] = populacja[i].Chromosom[h];
				populacja[j].Chromosom[h] = populacja[i + 1].Chromosom[h];
			}
			populacja[j].Aktualizuj_Dane(dane, Udzwig);
			populacja[j + 1].Aktualizuj_Dane(dane, Udzwig);
			j += 2;
		}
	}
	else
	{
		int test = populacja.size();
		while ((test / 2) % 2 == 0)
			test++;
		for (int i = (test);i < populacja.size();i += 2)
		{
			for (int h = 0;h < przeciecie;h++)
			{
				populacja[j].Chromosom[h] = populacja[i].Chromosom[h];
				populacja[j + 1].Chromosom[h] = populacja[i + 1].Chromosom[h];
			}
			for (int h = przeciecie;h < wielkosc;h++)
			{
				populacja[j + 1].Chromosom[h] = populacja[i].Chromosom[h];
				populacja[j].Chromosom[h] = populacja[i + 1].Chromosom[h];
			}
			populacja[j].Aktualizuj_Dane(dane, Udzwig);
			populacja[j + 1].Aktualizuj_Dane(dane, Udzwig);
			j += 2;
		}
	}

}
/// <summary>
/// Metoda wyswietlajaca populacji
/// </summary>
void Operacje::Wyswietl_Populacje(std::vector<Osobnik>& populacja)
{
	/// <summary>
	/// Metoda wyœwietlaj¹ca populacjê, funkcja wyœwietla chromosom, a nastêpnie wynik.
	/// </summary>
	/// <param name="populacja">Wektor populacji</param>
	for (int i = 0;i < populacja.size();i++)
	{
		std::cout << "\n";
		populacja[i].Wyswietl_Chromosom();
		std::cout << " ";
		populacja[i].Wyswietl_Wynik();


	}
}
/// <summary>
/// Metoda zawieraj¹ca mutacjê
/// </summary>
void Operacje::Mutacja(std::vector<Osobnik>& populacja, double Prawdopodobienstwo, std::vector<Obiekt>& dane, int Udzwig)
{
	/// <summary>
	/// Metoda ta zawiera mutacjê. Dla ka¿dego osobnika osobno z danym prawdopodobieñstwiem mo¿e wyst¹piæ mutacja. Mutacja zamienia
	/// nam losowy bit z 0 na 1 albo na odwrót.
	/// </summary>
	/// <param name="populacja">Wektor populacji</param>
	/// <param name="Prawdopodobienstwo">Prawdopodobieñstwo wyst¹pienia</param>
	/// <param name="dane">Wektor obiektów</param>
	/// <param name="Udzwig">Maksymalny udŸwig</param>
	Prawdopodobienstwo = Prawdopodobienstwo * 100;
	int miejsce;
	double losowa;
	int chromsize = populacja[0].Chromosom.size();
	for (int i = 0;i < populacja.size();i++)
	{
		losowa = rand() % 100 + 1;
		if (losowa <= Prawdopodobienstwo)
		{
			miejsce = rand() % chromsize;
			if (populacja[i].Chromosom[miejsce] == 1)
				populacja[i].Chromosom[miejsce] = 0;
			else
				populacja[i].Chromosom[miejsce] = 1;
			populacja[i].Aktualizuj_Dane(dane, Udzwig);
		}
	}


}
/// <summary>
/// Metoda oceny kiedy algorytm siê zakoñczy
/// </summary>
void Operacje::Ocena(std::vector<Osobnik>& populacja)
{
	/// <summary>
	/// Metoda ta sprawdza czy wynik najlepszego osobnika poprzedniej populacji ró¿ni siê o wiêcej ni¿ 0.01. Je¿eli 10 razy, 
	/// ró¿nica bêdzie mniejsza ni¿ 0.01 program automatycznie siê zakoñczy
	/// </summary>
	/// <param name="populacja">Wektor populacji</param>
	int ostatni = populacja.size() - 1;
	if (iteracja > 1)
	{
		if ((populacja[ostatni].Get_Wynik() - zero) < 0.01 && licznik == 10)
			sprawdzajacy = true;
		else if ((populacja[ostatni].Get_Wynik() - zero) > 0.01)
		{
			licznik = 0;
			zero = populacja[ostatni].Get_Wynik();
			sprawdzajacy = false;
		}
		else if ((populacja[ostatni].Get_Wynik() - zero) < 0.01)
		{
			licznik++;
			zero = populacja[ostatni].Get_Wynik();
			sprawdzajacy = false;
		}
	}
	else
	{
		iteracja++;
		sprawdzajacy = false;
	}

}
/// <summary>
/// Metoda zapisuj¹ca ostateczn¹ populacjê do pliku
/// </summary>
void Operacje::Zapis(const std::string& nazwapliku, std::vector<Osobnik>& populacja)
{
	/// <summary>
	/// Otwierany jest plik do zapisu i zapisywana jest ostatnia populacja-sumaryczna cena, pojemnoœæ i wynik ka¿dego osobnika.
	/// </summary>
	/// <param name="nazwapliku">Przekazujemy nazwe jak sie ma nazywaæ plik z wynikami</param>
	/// <param name="populacja">Wektor populacji</param>
	int chromos = populacja[1].Chromosom.size();

	try {
		std::ofstream plik(nazwapliku);
		if (!plik.is_open()) { throw - 1; }
		for (int i = 0;i < populacja.size();i++)
		{
			plik << std::endl;
			for (int j = 0;j < chromos;j++)
			{
				plik << populacja[i].Chromosom[j] << " ";
			}
			plik << " ";
			plik << " " << populacja[i].Get_Sumaryczna_cena();
			plik << " " << populacja[i].Get_Pojemnosc();
			plik << " " << populacja[i].Get_Wynik();
		}
		plik.close();
	}
	catch (int code)
	{
		//if (code == -1) {
		std::cout << "Nie otwarto pliku do zapisu.";
		//}
	}
}


/// <summary>
/// Metoda iteracyjna
/// </summary>
void Operacje::Set_ile()
{
	/// <summary>
	/// Iterujemy wartoœæ przebiegów cyklu algorytmu.
	/// </summary>
	ile++;
}
/// <summary>
/// Funkcja zwracaj¹ca
/// </summary>
/// <returns></returns>
int Operacje::Get_ile()
{
	/// <summary>
	/// Zwracamy ile razy algorytm genetyczny siê wykona³.
	/// </summary>
	/// <returns></returns>
	return ile;
}