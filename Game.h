#ifndef GAME_H
#define GAME_H

#include <iostream>     //drukowanie na stdout
#include <fstream>      //wczytywanie bazy z pliku
#include <vector>       //obsluga bazy w pamieci
#include <algorithm>    //fill
#include <cstdlib>      //srand() rand() //moze zastap boostem w przyszlosci
#include <ctime>        //rand(time(0))
using namespace std;
#include "Record.h"

const char ASTER(-92);

class Game{
 public:
  Game();
  ~Game(){}
  void load(ifstream& file);
  void play();
 private:
  vector<Record> base;
  int size;      //Rozmiar bazy
  int tsize;     // Ilosc slowek do powtorki w tej turze
  int difr;      // Ilosc pozostalych slowek
  int left;      // Ilosc pozostalych roznych slowek
  int drawed;    // wylosowany
  int previous;  // ostatnio wyswietlany
  void reorganise();
  void showParams();
};

#endif
