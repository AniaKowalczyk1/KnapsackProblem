#include "libFiles.h"

// Funkcja otwieraj�ca plik do zapisu
void f_zapisDoPliku(std::ofstream& zapis, std::string& nazwaPliku) {
    try {
        int dlugosc = nazwaPliku.size();  // Pobranie d�ugo�ci nazwy pliku
        // Sprawdzenie, czy nazwa pliku ma rozszerzenie ".txt", je�li nie, dodaj je
        if ((dlugosc <= 4) || (nazwaPliku[dlugosc - 4] != '.' || nazwaPliku[dlugosc - 3] != 't' || nazwaPliku[dlugosc - 2] != 'x' || nazwaPliku[dlugosc - 1] != 't')) {
            nazwaPliku += ".txt"; // Dodanie rozszerzenia ".txt", je�li nie zosta�o podane
        }

        zapis.open(nazwaPliku); // Otwarcie pliku o podanej nazwie do zapisu

        if (!zapis.is_open()) {
            throw std::runtime_error("Nie uda�o si� otworzy� pliku do zapisu.");
        }
    }
    catch (const std::exception& e) {
        ExceptionHandler::handle(e);
        throw; // Ponowne zg�oszenie wyj�tku, aby mo�na go by�o obs�u�y� w main.cpp
    }
}
