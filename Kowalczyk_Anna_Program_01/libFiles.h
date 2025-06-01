#pragma once
#include <iostream>
#include <fstream>
#include "ExceptionHandler.h"

using namespace std;

/*
Funkcja otwieraj¹ca zapis do pliku
@param zapis - referencja do obiektu strumienia wyjœciowego pliku
@param nazwaPliku - referencja do nazwy pliku
*/
void f_zapisDoPliku(ofstream& zapis, string& nazwaPliku);