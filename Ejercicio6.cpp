#include <iostream>
#include <vector>



/*
Coste del algoritmo (tiempo): O(n)
Coste del algoritmo (espacio): O(n)
Precondiciones: N > 0
fun resuelveCaso(V[N]: de ent) dev maxLongitudSegmento
Poscondiciones:
    maxLongitudSegmento = (max j,k: 0 < j < k < N ^ (para todo l: j <= l < k: V[k] = V[k+1]) : j -k)
Invariante:
    maxLongitudSegmento = (max j,k: 0 < j < k < i ^ (para todo l: j <= l < k: V[k] = V[k+1]) : j -k)
    longitud = i - (min j : 0 < j < i: (para todo k: j <= k < i: V[k] = V[k+1]))
Avanzar: i++
    maxLongitudSegmento = max { maxLongitudSegmento, longitud }
                        
Función de cota: N - i 
Condición de bucle: i < N
Terminación: i = N
*/

bool resuelve();
long int resuelveCaso(const std::vector<int> &v);

bool resuelve() {
	int nuevoNumero, respuesta;
  std::vector <int> v;

  std::cin >> nuevoNumero;
  if (nuevoNumero == -1) return false; 
	while (nuevoNumero != -1) {
		v.push_back(nuevoNumero);
    std::cin >> nuevoNumero;
	}

	respuesta = resuelveCaso(v);
	if (respuesta == 0) std::cout << "HOY NO COMEN" << std::endl;
	else std::cout << respuesta << std::endl;

	return true;
}
long int resuelveCaso(const std::vector<int> &v) {
	long int maxLongitudSegmento = 0, longitudSegmento = 0;

	for (long int i = 1; i < v.size(); ++i) {
		if (v[i - 1] == v[i]) ++longitudSegmento;
		else longitudSegmento = 0; 
		if (longitudSegmento > maxLongitudSegmento) 
      maxLongitudSegmento  = longitudSegmento;
	}
  return maxLongitudSegmento;
}

int main() {
	while (resuelve());
	return 0;
}
