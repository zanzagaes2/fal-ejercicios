/*
 * Precondición: 
 *  (ex j: 0 <= j < n: (pt i: 0 <= i < j: V[i+1] < V[i]) 
 *                      ^ (pt k: j <= k < n: V[k] < V[k+1]))
 * fun encontrarMinimo(V[N]: ent, i: ent, j:ent) dev m: ent
 * Postcondición:
 *  m = (min i: 0 <= i < n : V[i])
 *
 * Definimo medio := (n-1)/2
 * Para la recursión se observa que dado V si V[medio] > V[n-1]
 * entonces el segmento V[medio] ... V[n-1] es decreciente. En ese caso,
 * también el segmento V[0]...V[medio] es decreciente y podemos limitarnos 
 * a estudiar la segunda mitad.
 *
 * Repitiéndose el razonamiento para cualquier segmento V[i] ... V[j] no trivial    se tiene el algoritmo recursivo.
 *
 * Recurrencia:
 *  Casos: 
 *   > j - i < 2: m :=  min(V[i], V[j])
 *   > j - i >= 2:
 *      > V[(i+j)/2] > V[j]: por el razonamiento anterior,
 *         m := encontrarMinimo(V, medio, j)
 *      > V[(i+j)/2] <= V[j]: no podemos saber en qué parte de la curva estamos.
 *          m := min{ encontrarMinimo(V, i, medio),
 *                   encontrarMinimo(V, medio, j) }
 *
 * Rendimiento de la solución:
 *  Espacio: lineal (orden simétrico)
 *  Tiempo:
 *  > Mejor caso: se trata del caso estrictamente decreciente. 
 *      Como V[(i+j)/2] > V[j] pt 0 <= i < j < n el problema
 *      se reduce a la mitad en cada llamada recursiva (y la 
 *      recursión es final).
 *
 *      Rendimiento : log n (logarítmico)
 *  
 *  > Peor caso: se trata del caso estrictamente creciente. En este caso,
 *      no es posible reducir el número de casos a estudiar y es necesario
 *      comparar todos los elementos.
 *
 *      Rendimiento : n (lineal)
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
    else if (v[medio] > v[j]) return encontrarMinimo(v, medio, j);
    else return std::min(encontrarMinimo(v,i,medio),
           encontrarMinimo(v,medio,j)); 
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

