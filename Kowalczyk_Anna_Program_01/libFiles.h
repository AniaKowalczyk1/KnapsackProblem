#pragma once
#include <iostream>
#include <fstream>
#include "ExceptionHandler.h"

using namespace std;

/*
Funkcja otwierająca zapis do pliku
@param zapis - referencja do obiektu strumienia wyjściowego pliku
@param nazwaPliku - referencja do nazwy pliku
*/
void f_zapisDoPliku(ofstream& zapis, string& nazwaPliku);