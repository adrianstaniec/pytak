#ifndef BASE_H
#define BASE_H

#include <iostream>     //drukowanie na stdout
#include <string>       //obsluga slowek
#include <fstream>      //wczytywanie bazy z pliku
#include <vector>       //obsluga bazy w pamieci
#include <algorithm>    //fill
#include <cstdlib>      //srand() rand() //moze zastap boostem w przyszlosci
#include <ctime>        //rand(time(0)) 
using namespace std;

const int LJEZYKOW(2);
const char ASTER(-92);

class Base{
 public:
  Base();
  ~Base(){}
  void load(ifstream& file);
  void play();
 private:
  vector<vector<string> > words;
  vector<vector<int> > stat;
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
