#include "Game.h"

Game::Game() : size(0), tsize(0), difr(0), left(0), drawed(0), previous(0) {
  srand(time(0));
}

void Game::load(ifstream& file) {
  string line, distributor;
  distributor = ASTER;
  distributor += '=';
  distributor += ASTER;

  while (1) {
    getline(file, line);
    if (line.find("[Dane]", 0, 6) != string::npos) break;
  }
  int mark = 0;
  string tmp;
  while (1) {
    getline(file, line);
    mark = line.find(distributor);
    if (mark == (signed int)string::npos) {
      break;
    }
    tmp = line.substr(mark + distributor.length());
    Record brandnew(line.substr(0, mark), tmp, 1, 0);
    base.push_back(brandnew);
  }
  size = base.size();

  return;
}

void Game::play() {
  tsize = size;  // Ilosc slowek do powtorki w tej turze
  difr = tsize;  // Ilosc pozostalych slowek
  left = tsize;  // Ilosc pozostalych roznych slowek

  string answer = " ";

  while (1) {
    left = tsize;

    while (left) {
      if ((!(base[drawed = rand() % size].howManyNow())) ||
          ((drawed == previous) && difr != 1)) {  // nie 2 razy pod rzad
        do {
          if ((++drawed) >= size) {
            drawed = 0;
          }
        } while ((!(base[drawed].howManyNow())) ||
                 ((drawed == previous) && difr != 1));  // nie 2 razy pod rzad
      }
      previous = drawed;
      cout << base[drawed][0];
      cout << "\nPrzetlumacz:\n";
      getline(cin, answer);
      if (answer == base[drawed][1]) {
        cout << "Brawo! ;)\n\n";
        if (!base[drawed].doneCorrectly()) {
          --difr;
        }
        --left;
      } else {
        cout << "Zle! X(\n\tPoprawna odpowiedz: " << ((base[drawed][1]))
             << endl;
        cout << endl;
        base[drawed].oneMoreTime();
      }
    }
    reorganise();
    if (tsize == 0) break;
    cout << "\n\n-----POWTORKA!-----\n\n";
  }
  return;
}

void Game::reorganise() {
  tsize = 0;
  difr = 0;
  vector<Record>::iterator iterSmall = base.begin();
  for (vector<Record>::iterator iterBig = base.begin(); iterBig != base.end();
       ++iterBig) {
    if ((*iterBig).howManyMore()) {
      (*iterSmall) = (*iterBig);

      tsize += (*iterBig).howManyMore();
      (*iterSmall).updateStats();
      ++iterSmall;
      difr++;
    }
  }

  for (vector<Record>::iterator iterErase = (--base.end());
       iterErase != (iterSmall - 1); --iterErase) {
    base.erase(iterErase);
  }

  return;
}

void Game::showParams() {
  cout << "tsize: " << tsize << endl;
  cout << "left: " << left << endl;
  cout << "difr: " << difr << endl;
  cout << "previous: " << previous << endl;
}
