#include "Record.h"

Record::Record(string word0, string word1, int stat0, int stat1) {
  words[0] = word0;
  words[1] = word1;
  stat[0] = stat0;
  stat[1] = stat1;
}

Record::Record(const Record& X) {
  words[0] = X.words[0];
  words[1] = X.words[1];
  stat[0] = X.stat[0];
  stat[1] = X.stat[1];
}

string& Record::operator[](int x) {
  if ((x < 0) || (x > 1)) {
    // TODO: rzuc wyjatkiem
  }
  return words[x];
}

void Record::oneMoreTime() { ++stat[1]; }

int Record::howManyNow() { return stat[0]; }

int Record::howManyMore() { return stat[1]; }

bool Record::doneCorrectly() { return --stat[0]; }

void Record::updateStats() {
  stat[0] = stat[1];
  stat[1] = 0;
}
