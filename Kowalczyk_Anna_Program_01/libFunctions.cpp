#include "libFunctions.h"





/*
// Funkcja sprawdzaj¹ca, czy dany wêze³ jest obiecuj¹cy wagowo
@param w - waga
@param W - maksymalna waga
@return true je¿eli waga jest mniejsza od maksymalnej
*/
bool f_czyObiecujacyWagowo(int w, int W) {
    return w < W; // Zwraca true, jeœli waga jest mniejsza ni¿ limit wagi
}


/*
// Funkcja sprawdzaj¹ca, czy dany wêze³ jest obiecuj¹cy profitowo
@param mp - maksymalny profit
@param b - granica
@return true je¿eli granica jest wiêksza od maksymalnej
*/
bool f_czyObiecujacyProfitowo(int mp, float b) {
    return b > mp; // Zwraca true, jeœli granica górnego ograniczenia jest wiêksza ni¿ aktualny zysk
}


/*
// Funkcja sprawdzaj¹ca, czy dany wêze³ jest obiecuj¹cy
@param w - waga
@param W - maksymalna waga
@param mp - maksymalny profit
@param b - granica
@return true je¿eli wezel jest obiecuj¹cy
*/
bool f_obiecujaca(int w, int W, int mp, float b) {
    return f_czyObiecujacyWagowo(w, W) && f_czyObiecujacyProfitowo(mp, b);
}



/*
// Funkcja wyznaczaj¹ca wartoœæ k
@param rzeczy - wektor zawieraj¹cy rzeczy
@param n - iloœæ rzeczy
@param W - maksymalna waga
@return zwraca wyliczone k
*/
int f_wyznaczK(vector<Rzecz> rzeczy, int n, int W) {
    int sumaWag = 0;
    //iteracjaa przez wszystkie przedmioty
    for (int i = 0; i < rzeczy.size(); i++) {
        //sprawdzenie czy przedmiot jest aktywny, czyli czy nale¿y do wêz³a czy nie
        if (rzeczy[i].aktywny) {
            sumaWag += rzeczy[i].waga;
            if (sumaWag > W) {
                // Zwraca indeks ostatniego aktywnego przedmiotu, którego suma wag przekracza limit
                return i + 1;
            }
        }
    }
    // Zwraca n + 1, jeœli nie ma sumy, która przekracza limit wag
    return n + 1;
}


/*
// Funkcja policzTW obliczaj¹ca wartoœæ total weight
@param rzeczy - wektor zawieraj¹cy rzeczy
@param n - iloœæ rzeczy
@param w - waga
@param W - maksymalna waga
@param lvl - poziom, na którym jest wêze³
@return zwraca wyliczone tw
*/
int f_policzTW(vector<Rzecz> rzeczy, int n, int w, int W, int lvl) {
    int k = f_wyznaczK(rzeczy, n, W);
    int j = lvl + 1;

    int tw = w; //total weight
    for (int a = j; a <= k - 1; a++) {
        if (a - 1 < rzeczy.size() && rzeczy[a - 1].aktywny) {
            tw += rzeczy[a - 1].waga;
        }
    }
    return tw;
}


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
float f_obliczGranice(vector<Rzecz> rzeczy, int W, int profit, int waga, int lvl, int n) {
    int k = f_wyznaczK(rzeczy, n, W);
    int j = lvl + 1;
    int b = profit;

    for (int a = j; a <= k - 1; a++) {
        if (a - 1 < rzeczy.size()) {
            b += rzeczy[a - 1].profit;
        }
    }

    int tw = f_policzTW(rzeczy, n, waga, W, lvl);
    int zyskNaJednostke;

    //je¿eli k wychodzi poza zakres, to przyjmuje wartoœæ 0
    if (k > n) {
        zyskNaJednostke = 0;
    }
    else if (k - 1 < rzeczy.size()) {
        zyskNaJednostke = rzeczy[k - 1].stosunek;
    }
    else {
        zyskNaJednostke = 0;
    }

    //obliczenie granicy ze sk³adowych
    b = b + (W - tw) * zyskNaJednostke;
    return b;
}


/*
// Funkcja sprawdzaj¹ca wêze³
@param v - wêze³ pocz¹tkowy
@param W - maksymalna waga
@param maxProfit - maksymalny profit
@param n - iloœæ rzeczy
@param n - iloœæ rzeczy
@param zapis - referencja do obiektu strumienia wyjœciowego pliku
*/
void f_sprawdzWezel(Wezel v, int W, int& maxProfit, int n, ofstream& zapis) {
    // Aktualizacja maksymalnego zysku, jeœli aktualny zysk w wêŸle jest wiêkszy
    if (v.profit > maxProfit) {
        maxProfit = v.profit;
    }

    // Sprawdzenie, czy nie doszliœmy do koñca listy przedmiotów
    if (v.lvl < v.rzeczy.size()) {
        //tworzenie nowgo wêz³a, zawieraj¹cego bie¿¹cy przedmiot
        Wezel u = v;
        u.lvl = v.lvl + 1; // Zwiêkszenie poziomu drzewa

        // Dodanie kolejnego przedmiotu do plecaka
        u.waga += u.rzeczy[u.lvl - 1].waga;
        u.profit += u.rzeczy[u.lvl - 1].profit;
        u.rzeczy[v.lvl].aktywny = true; // Ustawienie przedmiotu jako aktywny

        // Obliczenie granicy górnego ograniczenia dla nowego wêz³a
        u.granica = f_obliczGranice(u.rzeczy, W, u.profit, u.waga, u.lvl, n);

        // Wypisanie informacji o wêŸle
        cout << "Poziom: " << u.lvl << ", Profit: " << u.profit << ", Waga: " << u.waga << ", Granica: " << u.granica << endl;
        zapis << "Poziom: " << u.lvl << ", Profit: " << u.profit << ", Waga: " << u.waga << ", Granica: " << u.granica << endl;

        // Sprawdzenie, czy wêze³ jest obiecuj¹cy i rekursywne sprawdzenie kolejnego wêz³a
        if (f_obiecujaca(u.waga, W, maxProfit, u.granica)) {
            f_sprawdzWezel(u, W, maxProfit, n, zapis);
        }

        // Utworzenie wêz³a wykluczaj¹cego bie¿¹cy przedmiot
        Wezel u_exclude = v;
        u_exclude.lvl = v.lvl + 1;

        // Wykluczenie przedmiotu z plecaka
        u_exclude.rzeczy[v.lvl].aktywny = false;

        // Obliczenie granicy górnego ograniczenia dla wêz³a wykluczaj¹cego
        u_exclude.granica = f_obliczGranice(u_exclude.rzeczy, W, u_exclude.profit, u_exclude.waga, u_exclude.lvl, n);

        // Wypisanie informacji o wêŸle wykluczaj¹cym
        cout << "Poziom: " << u_exclude.lvl << ", Profit: " << u_exclude.profit << ", Waga: " << u_exclude.waga << ", Granica: " << u_exclude.granica << endl;
        zapis << "Poziom: " << u_exclude.lvl << ", Profit: " << u_exclude.profit << ", Waga: " << u_exclude.waga << ", Granica: " << u_exclude.granica << endl;

        // Sprawdzenie, czy wêze³ wykluczaj¹cy jest obiecuj¹cy i rekursywne sprawdzenie kolejnego wêz³a
        if (f_obiecujaca(u_exclude.waga, W, maxProfit, u_exclude.granica)) {
            f_sprawdzWezel(u_exclude, W, maxProfit, n, zapis);
        }
    }
}