#include <stdio.h>
#include<iostream>
#include<vector>

typedef struct {
  bool parcialmenteOrdenado;
  long long int minimo;
  long long int maximo;
} tRetorno;

tRetorno parcialmenteOrdenado(const std::vector<long long int> &v, 
        long long i, 
        long long j) {
  tRetorno ret;
  if (i == j-1) {
    ret.parcialmenteOrdenado = v[i] <= v[j];
    ret.minimo = v[i];
    ret.maximo = v[j];
  }
  else {
    long long int medio = (i+j)/2;
    tRetorno x1 = parcialmenteOrdenado(v, i, medio);
    tRetorno x2 = parcialmenteOrdenado(v, medio+1, j);
    ret.parcialmenteOrdenado = x1.parcialmenteOrdenado && 
      x2.parcialmenteOrdenado && x1.maximo <= x2.maximo && 
      x1.minimo <= x2.minimo;
    ret.minimo = x1.minimo;
    ret.maximo = x2.maximo;
  }
  return ret;
}

bool resuelveCaso() {
  std::vector<long long int> v;
  long long int n;
  scanf("%lld", &n);
 
  if (n == 0) return false;
  while (n != 0) {
    v.push_back(n);
    scanf("%lld", &n);
  }

  tRetorno ret = parcialmenteOrdenado(v, 0, v.size()-1);
  printf("%s\n", (ret.parcialmenteOrdenado ? "SI" : "NO"));
  return true;
}


int main() {
    while(resuelveCaso());
}

