#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "libFiles.h"
#include "libFunctions.h"
#include "ExceptionHandler.h" 
using namespace std;





int main() {
    // Lista przedmiotów
    //vector<Rzecz> rzeczy = { {1, 40, 2, 20.0, true}, {2, 30, 5, 6.0, true}, {3, 50, 10, 5.0, true}, {4, 10, 5, 2.0, true} };
    vector<Rzecz> rzeczy = { {1, 20, 2, 10.0, true}, {2, 30, 5, 6.0, true}, {3, 35, 7, 5.0, true}, {4, 12, 3, 4.0, true}, {5, 3, 1, 3.0, true} };
    int n = rzeczy.size(); // Liczba przedmiotów
    int W = 19; // Limit wagi plecaka


    int maxProfit = 0;
    Wezel v;
    v.lvl = 0;
    v.profit = 0;
    v.waga = 0;
    v.rzeczy = rzeczy;
    v.granica = f_obliczGranice(rzeczy, W, v.profit, v.waga, v.lvl, n);

    // Otwarcie pliku do zapisu
    ofstream zapis;
    string nazwaPliku = "wynik";
    try {
        f_zapisDoPliku(zapis, nazwaPliku);
    }
    catch (const exception& e) {
        ExceptionHandler::handle(e);
        return EXIT_FAILURE;
    }

    // Wypisanie informacji o pocz¹tkowym wêŸle
    zapis << "Poziom: " << v.lvl << ", Profit: " << v.profit << ", Waga: " << v.waga << ", Granica: " << v.granica << endl;
    cout << "Poziom: " << v.lvl << ", Profit: " << v.profit << ", Waga: " << v.waga << ", Granica: " << v.granica << endl;

    // Sprawdzenie kolejnych wêz³ów w drzewie
    f_sprawdzWezel(v, W, maxProfit, n, zapis);

    // Wypisanie maksymalnego zysku
    cout << "Maksymalny zysk: " << maxProfit << endl;
    zapis << "Maksymalny zysk: " << maxProfit << endl;


    zapis.close();

    return 0;
}