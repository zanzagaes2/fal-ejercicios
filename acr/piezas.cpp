#include<cmath>
#include<climits>
#include<fstream>
#include<iostream>
#include<stdio.h>

long int piezas3(long int num);
long int piezas2(long int num);
long int piezas1(long int num);

long int piezas1(long int num) {
  long int y;
  y = sqrt(num);
  bool resuelto = false;
  while (!resuelto) {
    resuelto = num % y == 0;
    if (!resuelto) y++;
  }
  return y;
}

long int piezas3(long int num) {
  long int y;
  y = sqrt(num);
  bool resuelto = false;
  while (!resuelto) {
    resuelto = num % y == 0;
    if (!resuelto) y--;
  }
  return num / y;
}

long int piezas2(long int num) {
  long int diff, minDiff = INT_MAX, minDiffx = 0;
  for (long int i = 0; i < num; i++) {
    for (long int j = i; j < num; j++) {
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
    using Clock = std::chrono::steady_clock; 
    using milisegundos = std::chrono::duration<double, std::milli>;
    long int num;
    int REPETICIONES = 5;
    std::ifstream archivoEntrada;
    std::ofstream archivoSalida;
    archivoEntrada.open("numeros.in");
    archivoSalida.open("out3.out");
    
    archivoEntrada >> num;
    while(archivoEntrada && num != 0) {
        Clock::duration tiempo_total = Clock::duration::zero();
        for (int repeticion = 0; repeticion < REPETICIONES; repeticion++) {
            Clock::time_point inicio = Clock::now();
            piezas3(num);
            tiempo_total += Clock::now() - inicio;
        }
        double tiempo = milisegundos(tiempo_total / (double)REPETICIONES).count();
        archivoSalida << num << " " << tiempo << "\n";
        archivoEntrada >> num;
    }
    archivoSalida.close();
}
