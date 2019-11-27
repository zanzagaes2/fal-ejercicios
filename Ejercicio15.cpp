/*
 * Precondición: 
 * (ex k: 0 <= k < n:
 *   (pt i: 0 <= i < k-1: V[i] < V[i+1]) ^
 *   (pt i: k <= i < n: V[i] < V[i+1])
 * fun encontrarMinimo(V[N]: ent, i: ent, j: ent) dev m: ent
 * Postcondición:
 *  m = (min i: 0 <= i < n : V[i])
 *
 *
 *  La clave del problema es encontrar en qué parte del vector estamos, 
 *  en la parte "rotada" o en la no rotada. 
 *
 *  Dado V[n] tomemos medio = (n-1)/2
 *
 *  > caso 1:
 *      v[medio] > v[0]: estamos necesariamente en la parte "rotada" 
 *          del vector.
 *      El mínimo debe estar en el segmento V[0]...V[medio-1]
 *
 *  > caso 2:
 *      v[medio] < v[n]: estamos en la parte no rotada del array.
 *      El mínimo debe estar en el segmento V[medio]...V[n]
 *
 *  > caso 3:
 *    v[0] > v[medio] > v[n]: en este caso el vector no ha sido rotado.
 *    En efecto, en caso de haber sido rotado tenemos
 *     v[n] > v[0] -> v[n] > v[medio], contradictorio.
 *
 *    Como el vector no ha sido rotado, el mínimo es V[n], por ser 
 *    el último elemento de un vector decreciente. 
 *
 *    El último paso es observar que este razonamiento puede repetirse
 *    cambiando 0 y n por i,j cualesquiera.
 *
 *  Casos de la recurrencia: se formaliza lo anterior.
 *  Caso:
 *      medio := (i+j)/2
 *      > j - i < 2: caso trivial, m := min {v[i], v[j]}
 *      > v[medio] > v[i]
 *          m := encontrarMinimo(v, i, j)
 *      > v[medio] < v[j]
 *          m := encontrarMinimo(v, i, j) 
 *      > v[i] < v[medio] < v[j]
 *
 * En cada recurrencia el segmento considerado se reduce como mínimo
 * a la mitad, con lo que el coste es logarítimo.
 *
 * En el caso mejor (array decreciente) el coste es constante.
 *
 *
 */
#include<algorithm>
#include<iostream>
#include<vector>

long long int encontrarMinimo(const std::vector<long long int> &v, 
        long long int i, long long int j) 
{
    long long int medio = (i+j)/2;
    if (j - i < 2) return std::min(v[i], v[j]);
    else if (v[medio] > v[i]) return encontrarMinimo(v, i, medio-1);
    else if (v[medio] < v[j]) return encontrarMinimo(v, medio, j);
    else return v[j];
}

void printArray(const std::vector<long long int> &v) {
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

bool resuelveCaso() {
  long long int n, numeroLeido;
  std::cin >> n;
  while (std::cin) {
      std::vector<long long int> v;
      for (int j = 0; j < n; j++) {
          std::cin >> numeroLeido;
          v.push_back(numeroLeido); 
      } 
      std::cout << encontrarMinimo(v, 0, n-1) << std::endl;
      std::cin >> n;
  }
  return true;
}


int main() {
    resuelveCaso();
}

