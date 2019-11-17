#include<cmath>
#include<climits>
#include<iostream>

int piezas2(int num);
int piezas1(int num);

int piezas1(int num) {
  int x, y, sol;
  x = y = sqrt(num);
  bool resuelto = false;
  while (!resuelto) {
    sol = x*y;
    resuelto = sol == num;
    if (sol < num) x++;
    else y--;
  }
  return x;
}

int piezas2(int num) {
  int diff, minDiff = INT_MAX, minDiffx = 0;
  for (int i = 0; i < num; i++) {
    for (int j = i; j < num; j++) {
      diff = j-i;
      if (diff < minDiff && i*j == num) {
        minDiff = diff;
        minDiffx = j;
      }
    }
  }
  return minDiffx;
}

int main() {
}
