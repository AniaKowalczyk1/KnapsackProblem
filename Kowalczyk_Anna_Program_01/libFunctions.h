#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "libFiles.h"
using namespace std;


// Struktura reprezentuj¹ca przedmiot
struct Rzecz {
    int indeks;
    int profit;
    int waga;
    float stosunek; // Stosunek zysku do wagi
    bool aktywny; // Czy przedmiot jest aktywny w rozwi¹zaniu
};

// Struktura reprezentuj¹ca wêze³ drzewa przegl¹du w algorytmie branch and bound
struct Wezel {
    int lvl; // Poziom w drzewie
    int profit; // Aktualny zysk
    int waga; // Aktualna waga
    float granica; // Granica górnego ograniczenia
    vector<Rzecz> rzeczy; // Lista przedmiotów do rozwa¿enia na danym poziomie
};



/*
// Funkcja sprawdzaj¹ca, czy dany wêze³ jest obiecuj¹cy wagowo
@param w - waga
@param W - maksymalna waga
@return true je¿eli waga jest mniejsza od maksymalnej
*/
bool f_czyObiecujacyWagowo(int w, int W);

/*
// Funkcja sprawdzaj¹ca, czy dany wêze³ jest obiecuj¹cy profitowo
@param mp - maksymalny profit
@param b - granica
@return true je¿eli granica jest wiêksza od maksymalnej
*/

bool f_czyObiecujacyProfitowo(int mp, float b);

/*
// Funkcja sprawdzaj¹ca, czy dany wêze³ jest obiecuj¹cy
@param w - waga
@param W - maksymalna waga
@param mp - maksymalny profit
@param b - granica
@return true je¿eli wezel jest obiecuj¹cy
*/
bool f_obiecujaca(int w, int W, int mp, float b);



/*
// Funkcja wyznaczaj¹ca wartoœæ k
@param rzeczy - wektor zawieraj¹cy rzeczy
@param n - iloœæ rzeczy
@param W - maksymalna waga
@return zwraca wyliczone k
*/
int f_wyznaczK(vector<Rzecz> rzeczy, int n, int W);

/*
// Funkcja policzTW obliczaj¹ca wartoœæ total weight
@param rzeczy - wektor zawieraj¹cy rzeczy
@param n - iloœæ rzeczy
@param w - waga
@param W - maksymalna waga
@param lvl - poziom, na którym jest wêze³
@return zwraca wyliczone tw
*/
int f_policzTW(vector<Rzecz> rzeczy, int n, int w, int W, int lvl);

/*
// Funkcja obliczaj¹ca granicê górnego ograniczenia
@param rzeczy - wektor zawieraj¹cy rzeczy
@param W - maksymalna waga
@param profit - profit
@param w - waga
@param lvl - poziom, na którym jest wêze³
@param n - iloœæ rzeczy
@return zwraca wyliczon¹ granicê
*/
float f_obliczGranice(vector<Rzecz> rzeczy, int W, int profit, int waga, int lvl, int n);

/*
// Funkcja sprawdzaj¹ca wêze³
@param v - wêze³ pocz¹tkowy
@param W - maksymalna waga
@param maxProfit - maksymalny profit
@param n - iloœæ rzeczy
@param n - iloœæ rzeczy
@param zapis - referencja do obiektu strumienia wyjœciowego pliku
*/
void f_sprawdzWezel(Wezel v, int W, int& maxProfit, int n, ofstream& zapis);