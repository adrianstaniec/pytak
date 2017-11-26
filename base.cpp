#include "base.h"

Base::Base(): 
  words(LJEZYKOW), stat(LJEZYKOW), size(0), tsize(0), difr(0), left(0), drawed(0), previous(0) {
  srand(time(0));
}

void Base::load(ifstream& file){
  string line,distributor;
  distributor=ASTER;
  distributor+='=';
  distributor+=ASTER;
  
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
    words[0].push_back(line.substr(0,mark));
    stat[0].push_back(1);
    tmp = line.substr(mark+3);
    words[1].push_back(tmp.erase(tmp.length()-1));
    stat[1].push_back(0);
//     cout << "1: " << words[0][index] << endl;
//     cout << "2: " << words[1][index] << endl;
    index++;
  }
  size=index;

//   cout << "Ilosc slowek w bazie:: " << words[0].size() << endl;
//   for(int i=0;i<size;++i){
//     cout << stat[0][i] << "." << stat[1][i] << " " << words[1][i] << endl;
//   }
//   cout << stat[0].size() << endl;

  return;
}

void Base::play(){
  tsize=size;    // Ilosc slowek do powtorki w tej turze
  difr = tsize;  // Ilosc pozostalych slowek
  left = tsize;  // Ilosc pozostalych roznych slowek

  string answer=" ";
  //  system("clear");

  while(1){
    left = tsize;

    while(left){

      showParams();
      if((!(stat[0][drawed = rand() % size]))  || ((drawed==previous)&&difr!=1 )){ //nie 2 razy pod rzad
	do{
 	  cout << drawed;
	  if( (++drawed) >= size ){
	    drawed=0;
	  }
	}while((!(stat[0][drawed])) || ((drawed==previous)&&difr!=1 )); //nie 2 razy pod rzad
      }
      cout << "-" << drawed << "-\n";
      previous = drawed;
      cout << words[0][drawed];
      cout << "  |" << stat[0][drawed] << "|" << stat[1][drawed] << "|" << endl;
      cout << "Przetlumacz:\n";
      getline(cin,answer);
      if(answer == words[1][drawed]){
	cout << "Brawo! ;)\n\n";
	if(!(--(stat[0][drawed]))){
	  --difr;
	}
	--left;
      }else{
	cout << "Zle! X(\n\tPoprawna odpowiedz: " << ((words[1][drawed])) << endl;
        cout << endl;
        (stat[1][drawed])++;
      }
    }
    reorganise();
    if(tsize==0)
      break;
    cout << "\n\n-----POWTORKA!-----\n\n";
  }
  return;
}

void Base::reorganise(){
  tsize=0;
  difr=0;
  for(int i=0; i<size; ++i){
    if(stat[1][i]){
      words[0][difr]=words[0][i]; //przeogranizowanie bazy
      words[1][difr]=words[1][i]; //przeogranizowanie bazy
      tsize+=stat[1][i];        //przeogranizowanie bazy
      stat[0][difr]=stat[1][i]; //przeogranizowanie bazy
      stat[1][difr]=0;          //przeogranizowanie bazy
      difr++;
    }
  }
  size=difr;                    //przeogranizowanie bazy
  return;
}

void Base::showParams(){
       cout << "tsize: " << tsize << endl;
       cout << "left: " << left << endl;
       cout << "difr: " << difr << endl;
       cout << "previous: " << previous << endl;
}
