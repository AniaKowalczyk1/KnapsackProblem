#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "libFiles.h"
using namespace std;


// Struktura reprezentuj�ca przedmiot
struct Rzecz {
    int indeks;
    int profit;
    int waga;
    float stosunek; // Stosunek zysku do wagi
    bool aktywny; // Czy przedmiot jest aktywny w rozwi�zaniu
};

// Struktura reprezentuj�ca w�ze� drzewa przegl�du w algorytmie branch and bound
struct Wezel {
    int lvl; // Poziom w drzewie
    int profit; // Aktualny zysk
    int waga; // Aktualna waga
    float granica; // Granica g�rnego ograniczenia
    vector<Rzecz> rzeczy; // Lista przedmiot�w do rozwa�enia na danym poziomie
};



/*
// Funkcja sprawdzaj�ca, czy dany w�ze� jest obiecuj�cy wagowo
@param w - waga
@param W - maksymalna waga
@return true je�eli waga jest mniejsza od maksymalnej
*/
bool f_czyObiecujacyWagowo(int w, int W);

/*
// Funkcja sprawdzaj�ca, czy dany w�ze� jest obiecuj�cy profitowo
@param mp - maksymalny profit
@param b - granica
@return true je�eli granica jest wi�ksza od maksymalnej
*/

bool f_czyObiecujacyProfitowo(int mp, float b);

/*
// Funkcja sprawdzaj�ca, czy dany w�ze� jest obiecuj�cy
@param w - waga
@param W - maksymalna waga
@param mp - maksymalny profit
@param b - granica
@return true je�eli wezel jest obiecuj�cy
*/
bool f_obiecujaca(int w, int W, int mp, float b);



/*
// Funkcja wyznaczaj�ca warto�� k
@param rzeczy - wektor zawieraj�cy rzeczy
@param n - ilo�� rzeczy
@param W - maksymalna waga
@return zwraca wyliczone k
*/
int f_wyznaczK(vector<Rzecz> rzeczy, int n, int W);

/*
// Funkcja policzTW obliczaj�ca warto�� total weight
@param rzeczy - wektor zawieraj�cy rzeczy
@param n - ilo�� rzeczy
@param w - waga
@param W - maksymalna waga
@param lvl - poziom, na kt�rym jest w�ze�
@return zwraca wyliczone tw
*/
int f_policzTW(vector<Rzecz> rzeczy, int n, int w, int W, int lvl);

/*
// Funkcja obliczaj�ca granic� g�rnego ograniczenia
@param rzeczy - wektor zawieraj�cy rzeczy
@param W - maksymalna waga
@param profit - profit
@param w - waga
@param lvl - poziom, na kt�rym jest w�ze�
@param n - ilo�� rzeczy
@return zwraca wyliczon� granic�
*/
float f_obliczGranice(vector<Rzecz> rzeczy, int W, int profit, int waga, int lvl, int n);

/*
// Funkcja sprawdzaj�ca w�ze�
@param v - w�ze� pocz�tkowy
@param W - maksymalna waga
@param maxProfit - maksymalny profit
@param n - ilo�� rzeczy
@param n - ilo�� rzeczy
@param zapis - referencja do obiektu strumienia wyj�ciowego pliku
*/
void f_sprawdzWezel(Wezel v, int W, int& maxProfit, int n, ofstream& zapis);