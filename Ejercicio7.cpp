#include <iostream>
#include <vector>

/*
 * Precondicion: N >= 0
 * fun esApta(V[N] de ent, cota: ent) dev apta
 * Poscondicion:
 *  apta = (pt k,l: 0 <= k < l < N: V[l] - V[k] < cota)
 *
 *  que es equivalente a
 *    (pt j: 0 <= k < N: V[k] - V[comienzoCuesta(k)] < cota)
 *
 *  comienzoCuesta(x) = (min x: 0 <= k <= j: segmentoCreciente(k, x))
 *  segmentoCreciente(x,y) = (pt l: x <= l <= y-1: V[l] < V[l+1])
 *
 * Invariante:
 *  1 <= i < N
 *  j = comienzoCuesta(i)
 *    [Notese que si V[j-1] >= V[j] entonces j=i]
 *  apta = (pt j: 0 <= k < i: V[k] - V[comienzoCuesta(k)] < cota)
 *
 *  Avanzar:
 *    i := i+1
 *    si V[i-1] < V[i]: 
 *      apta := V[i] - V[j] < cota
 *    si no:
 *      j = i
 *
 * Funcion de cota: N-i
 * Condicion de bucle: i < N
 * Condicion de terminacion: i == N
 * Rendimiento: lineal orden simetrico(N)
 *
 */

bool esApta(const std::vector<int> &v, long long int cota);

bool resuelve(long long int cota, long long int casos) {
	long long int nuevoNumero;
  std::vector <int> v;

	for (int i = 0; i < casos; i++) {
    std::cin >> nuevoNumero;
		v.push_back(nuevoNumero);
	}

	if (esApta(v, cota)) std::cout << "APTA" << std::endl;
	else std::cout << "NO APTA" << std::endl;
  return true;
}

bool esApta(const std::vector<int> &v, 
    long long int cota) 
{
  bool apta = true;
  int i = 1, j = 0;
  while (apta && i < v.size()) {
    if (v.at(i-1) < v.at(i)) apta = v.at(i) - v.at(j) <= cota;
    else j = i;
    i++;
  }
  return apta;
}

int main() {
  long long int cota, numero;
  std::cin >> cota >> numero;
  while (std::cin) {
	  resuelve(cota, numero);
    std::cin >> cota >> numero;
  }
}
