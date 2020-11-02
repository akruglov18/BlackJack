#ifndef REV_H
#define REV_H

#include<string>

using namespace std;

void myReverse(string& str) {
  for (int i = 0; i < str.size() / 2; i++)
    swap(str[i], str[str.size() - i - 1]);
}
#endif