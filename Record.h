#pragma once

#include <string>  //obsluga slowek
using namespace std;

const int LJEZYKOW(2);

class Record {
 public:
  Record() {}
  Record(string word0, string word1, int stat0, int stat1);
  Record(const Record& X);
  ~Record() {}
  string& operator[](int x);
  void oneMoreTime();
  bool doneCorrectly();
  void updateStats();
  int howManyMore();
  int howManyNow();
  int isItDone();

 private:
  string words[2];
  int stat[2];
};