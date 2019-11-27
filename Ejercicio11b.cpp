#include <stdio.h>
#include<iostream>
#include<vector>

typedef struct {
  bool parcialmenteOrdenado;
  long long int minimo;
  long long int maximo;
} tRetorno;

tRetorno parcialmenteOrdenado(const std::vector<long long int> &v, 
        long long int i, long long int j) {
  if (i == j-1) return {v[i] <= v[j], v[i], v[j]}; 
  else {
    tRetorno ret;
    long long int medio = (i + j)/2;
    tRetorno x1 = parcialmenteOrdenado(v, i, medio);
    if (x1.parcialmenteOrdenado) {
        tRetorno x2 = parcialmenteOrdenado(v, medio+1, j);
        ret.parcialmenteOrdenado = x2.parcialmenteOrdenado &&
            x1.maximo <= x2.maximo && x1.minimo <= x2.minimo;
            ret.minimo = x1.minimo;
            ret.maximo = x2.maximo;
    }
    else ret.parcialmenteOrdenado = false;
    return ret;
  }
}

bool resuelveCaso() {
  std::vector<long long int> v;
  long long int n;
  std::cin >> n;
 
  if (n == 0) return false;
  while (n != 0) {
    v.push_back(n);
    std::cin >> n;
  }

  tRetorno ret = parcialmenteOrdenado(v, 0, v.size()-1);
  std::cout << (ret.parcialmenteOrdenado ? "SI\n" : "NO\n");
  return true;
}


int main() {
    while(resuelveCaso());
}

