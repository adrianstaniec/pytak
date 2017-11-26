#include "Game.h"

Game::Game():
  size(0), tsize(0), difr(0), left(0), drawed(0), previous(0) {
  srand(time(0));
}

void Game::load(ifstream& file){
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
  int mark=0;
  string tmp;
  //  Record brandnew;
  while(1){
    getline(file,line);
    //    cout << line << endl;
    mark=line.find(distributor);
    if(mark==(signed int) string::npos){
      break;
    }
    tmp = line.substr(mark+3);
    Record brandnew(line.substr(0,mark),tmp.erase(tmp.length()-1),1,0);
    base.push_back(brandnew);
//     cout << "1: " << (base.back())[0] << endl;
//     cout << "2: " << (base.back())[1] << endl;
  }
  size=base.size();

//   cout << "Ilosc slowek w bazie:: " << words[0].size() << endl;
//   for(int i=0;i<size;++i){
//     cout << stat[0][i] << "." << stat[1][i] << " " << words[1][i] << endl;
//   }
//   cout << stat[0].size() << endl;

  return;
}

void Game::play(){
  tsize=size;    // Ilosc slowek do powtorki w tej turze
  difr = tsize;  // Ilosc pozostalych slowek
  left = tsize;  // Ilosc pozostalych roznych slowek

  string answer=" ";
  //  system("clear");

  while(1){
    left = tsize;

    while(left){

      //showParams();
      if((!(base[drawed = rand() % size].howManyNow()))  || ((drawed==previous)&&difr!=1 )){ //nie 2 razy pod rzad
	do{
 	  //cout << drawed;
	  if( (++drawed) >= size ){
	    drawed=0;
	  }
	}while((!(base[drawed].howManyNow())) || ((drawed==previous)&&difr!=1 )); //nie 2 razy pod rzad
      }
      //cout << "-" << drawed << "-\n";
      previous = drawed;
      cout << base[drawed][0];
      //cout << "  |" << base[drawed].howManyNow() << "|" << base[drawed].howManyMore() << "|";
      cout << "\nPrzetlumacz:\n";
      getline(cin,answer);
      if(answer == base[drawed][1]){
	cout << "Brawo! ;)\n\n";
	if(!base[drawed].doneCorrectly()){
	  --difr;
	}
	--left;
      }else{
	cout << "Zle! X(\n\tPoprawna odpowiedz: " << ((base[drawed][1])) << endl;
        cout << endl;
        base[drawed].oneMoreTime(); //oneMoreTime()
      }
    }
    reorganise();
    if(tsize==0)
      break;
    cout << "\n\n-----POWTORKA!-----\n\n";
  }
  return;
}

void Game::reorganise(){
  tsize=0;
  difr=0;
  vector<Record>::iterator iterSmall=base.begin();
  for(vector<Record>::iterator iterBig=base.begin(); iterBig!=base.end(); ++iterBig){
    if((*iterBig).howManyMore()){
  //if(base[i].howManyMore()){
      (*iterSmall)=(*iterBig);

      //base[difr]=base[i];
      tsize+=(*iterBig).howManyMore();
      (*iterSmall).updateStats();
      ++iterSmall;
      difr++;
    }
  }

  for(vector<Record>::iterator iterErase=(--base.end()); iterErase!=(iterSmall-1); --iterErase){
    //cout << "usuwam " << (*iterErase)[0] << endl;
    base.erase(iterErase);
  }

//   cout << "++: " << (size=difr) <<endl;
//   cout << "++: " << base.size() << endl;
  return;
}

void Game::showParams(){
       cout << "tsize: " << tsize << endl;
       cout << "left: " << left << endl;
       cout << "difr: " << difr << endl;
       cout << "previous: " << previous << endl;
}
