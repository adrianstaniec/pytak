//totalne zobiektowanie;] + usuwanie pamieci przy przeorganizowywaniu
#include <iostream>     //drukowanie na stdout
#include <string>       //obsluga slowek

#include <fstream>      //wczytywanie bazy z pliku
#include <vector>       //obsluga bazy w pamieci
#include <algorithm>    //fill
#include <cstdlib>      //srand() rand() //moze zastap boostem w przyszlosci
#include <ctime>        //rand(time(0))
using namespace std;

#include "Game.h"

int main(int argc, char* argv[]){
  Game game;

  if(argc!=2){
    perror("podaj plik !\n");
    exit(-1);
  }
  ifstream file(argv[1]);

  game.load(file);

  game.play();

  cout << "\n\n^*^ GRATULACJE! ^*^\n\n";
  return 0;
}
