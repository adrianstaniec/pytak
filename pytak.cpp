//zobiektowanie
#include <iostream>     //drukowanie na stdout
#include <string>       //obsluga slowek
#include <fstream>      //wczytywanie bazy z pliku
#include <vector>       //obsluga bazy w pamieci
#include <algorithm>    //fill
#include <cstdlib>      //srand() rand() //moze zastap boostem w przyszlosci
#include <ctime>        //rand(time(0))
using namespace std;

#include "base.h"

int main(int argc, char* argv[]){
  Base base;

  if(argc!=2){
    perror("podaj plik !\n");
    exit(-1);
  }
  ifstream file(argv[1]);

  base.load(file);

  base.play();

  cout << "\n\n^*^ GRATULACJE! ^*^\n\n";
  //  baza[0].clear;
  //baza[1].clear;
  //  baza.clear;
  //stat[0].clear;
  //stat[1].clear;
  //stat.clear;
  return 0;
}

int loadBase(ifstream& file, vector<vector<string> >& baza,vector<vector<int> >& stat){
    string line,distributor;
    char aster;

    aster=-92;
    distributor+=aster;
    distributor+='=';
    distributor+=aster;

    while(1){
      getline(file,line);
      //      cout << line << endl;
      if(line.find("[Dane]",0,6)!=string::npos)
      	break;
    }
    //    cout << "------------------------- ha\n";
    int index=0,mark=0;
    string tmp;
    while(1){
      getline(file,line);
            cout << line << endl;
      mark=line.find(distributor);
      if(mark==(signed int) string::npos){
	break;
      }
      baza[0].push_back(line.substr(0,mark));
      stat[0].push_back(1);
      tmp = line.substr(mark+3);
      baza[1].push_back(tmp.erase(tmp.length()-1));
      stat[1].push_back(0);
      cout << "1: " << baza[0][index] << endl;
      cout << "2: " << baza[1][index] << endl;
      index++;
    }
    return index;
}

void play(vector<vector<string> >& baza, vector<vector<int> >& stat, int size){
  int tsize=size;    // Ilosc slowek do powtorki w tej turze
  int difr = tsize;  // Ilosc pozostalych slowek
  int left = tsize;  // Ilosc pozostalych roznych slowek
  int drawed=0;
  string answer=" ";
  int previous = 0;   // ostatnio wyswietlany
  //  system("clear");

  while(1){
    left = tsize;

    while(left){

       cout << "tsize: " << tsize << endl;
       cout << "left: " << left << endl;
       cout << "difr: " << difr << endl;
       cout << "previous: " << previous << endl;

      if((!(stat[0][drawed = rand() % size]))  || ((drawed==previous)&&difr!=1 )){ //nie 2 razy pod rzad
	do{
 	  cout << drawed;
	  if( (++drawed) >= size ){
	    drawed=0;
	  }
	}while((!(stat[0][drawed])) || ((drawed==previous)&&difr!=1 )); //nie 2 razy pod rzad
      }
      cout << "-" << drawed << "-\n";
      previous=drawed;
      cout << baza[0][drawed] << "  |" << stat[0][drawed] << "|" << stat[1][drawed] << "|" << endl;
      cout << "Przetlumacz:\n";
      getline(cin,answer);
      if(answer == baza[1][drawed]){
	cout << "Brawo! ;)\n\n";
	if(!(--(stat[0][drawed]))){
	  --difr;
	}
	--left;
      }else{
	cout << "Zle! X(\n\tPoprawna odpowiedz: " << ((baza[1][drawed])) << endl;
        cout << endl;
        (stat[1][drawed])++;
      }
    }

    tsize=0;
    difr=0;
    for(int i=0; i<size; ++i){
      if(stat[1][i]){
	baza[0][difr]=baza[0][i]; //przeogranizowanie bazy
	baza[1][difr]=baza[1][i]; //przeogranizowanie bazy
	tsize+=stat[1][i];        //przeogranizowanie bazy
	stat[0][difr]=stat[1][i]; //przeogranizowanie bazy
	stat[1][difr]=0;          //przeogranizowanie bazy
	difr++;
      }
    }
    size=difr;                    //przeogranizowanie bazy
    if(tsize==0)
      break;
    cout << "\n\n-----POWTORKA!-----\n\n";
  }
  return;
}
