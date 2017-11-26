#ifndef RECORD_H
#define RECORD_H

#include <string>       //obsluga slowek
#include <vector>       //obsluga bazy w pamieci
using namespace std;

const int LJEZYKOW(2);

class Record{
 public:
  Record();
  ~Record(){}
 private:
  string words[2];
  int stat[2];
};

#endif
