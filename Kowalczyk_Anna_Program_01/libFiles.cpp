#include "libFiles.h"

// Funkcja otwieraj¹ca plik do zapisu
void f_zapisDoPliku(std::ofstream& zapis, std::string& nazwaPliku) {
    try {
        int dlugosc = nazwaPliku.size();  // Pobranie d³ugoœci nazwy pliku
        // Sprawdzenie, czy nazwa pliku ma rozszerzenie ".txt", jeœli nie, dodaj je
        if ((dlugosc <= 4) || (nazwaPliku[dlugosc - 4] != '.' || nazwaPliku[dlugosc - 3] != 't' || nazwaPliku[dlugosc - 2] != 'x' || nazwaPliku[dlugosc - 1] != 't')) {
            nazwaPliku += ".txt"; // Dodanie rozszerzenia ".txt", jeœli nie zosta³o podane
        }

        zapis.open(nazwaPliku); // Otwarcie pliku o podanej nazwie do zapisu

        if (!zapis.is_open()) {
            throw std::runtime_error("Nie uda³o siê otworzyæ pliku do zapisu.");
        }
    }
    catch (const std::exception& e) {
        ExceptionHandler::handle(e);
        throw; // Ponowne zg³oszenie wyj¹tku, aby mo¿na go by³o obs³u¿yæ w main.cpp
    }
}
