#include<iostream>
#include<vector>

typedef struct {
  bool parcialmenteOrdenado;
  long long int minimo;
  long long int maximo;
} tRetorno;

tRetorno parcialmenteOrdenado(const std::vector<int> &v, int i, int j) {
  tRetorno ret;
  if (i == j-1) {
    ret.parcialmenteOrdenado = v[i] <= v[j];
    ret.minimo = v[i];
    ret.maximo = v[j];
  }
  else {
    int medio = (i+j)/2;
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
  std::vector<int> v;
  int n;
  std::cin >> n;
 
  if (n == 0) return false;
  while (n != 0) {
    v.push_back(n);
    std::cin >> n;
  }

  tRetorno ret = parcialmenteOrdenado(v, 0, v.size()-1);
  std::cout << (ret.parcialmenteOrdenado ? "SI" : "NO") << std::endl;
  return true;
}


int main() {
    while(resuelveCaso());
}

