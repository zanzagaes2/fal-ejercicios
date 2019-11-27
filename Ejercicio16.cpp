/*
 * Definimos ocurr(x, V): (#i: 0 <= i < n: V[i] = x)
 * Precondición:
 *  (ex k: 0 <= k < n: ocurr(k, V) = 1 ^ 
 *      ((pt j: 0 <= j < n: ocur(j, V) = 1) -> j = k))
 *
 * fun encontrarFalta(V[n]: ent, i: ent, j:ent) dev falta: ent
 * Poscondición:
 *  (ocur(falta, V) = 1)
 *
 * Se observa que en la primera llamda a función se considera
 * el segmento V[0]...V[n-1] con n impar.
 *
 * Llamemos medio a (0+n-1)/2
 * Hay varias posibilidades:
 *  > V[medio] == V[medio-1] y medio es par:
 *      en ese caso, en el segmento V[0]...V[medio-2] hay un número
 *      impar de elementos, con lo que *falta* debe ser un índice
 *      entre 0 y medio-2
 *  > V[medio] == V[medio-1] y medio es impar:
 *      en ese caso, el semgmento V[medio+1]...V[n-1] tiene
 *      n - medio + 2 elementos, que es impar.
 *      Por tanto, *falta* es un índice entre medio+1 y n-1.
 *
 * Para el caso V[medio] == V[medio+1] se razona de forma análoga y 
 * la recurrencia se obtiene de sustituir 0 y n-1 por i,j arbitrarios
 * con 0 <= i <= j < n, i par, j par
 *
 * Llamemos A a V[medio] == V[medio+1]
 *          B a V[medio] == V[medio-1]
 *
 * Llamemos Par a medio mod 2 == 0
 *          Impar a medio mod 2 == 1
 *
 * Llamemos medio := (i+j)/2
 *
 * Caso trivial (j - i < 2) falta := i
 * A ^ Par: falta := encontrarFalta(v, i, medio-2)
 * A ^ Impar: falta := encontrarFalta(v, medio+1, j)
 * B ^ Par: falta := encontrarFalta(v, medio+2, j)
 * B ^ Impar: falta := encontrarFalta(v, i, medio-1)
 * noA y noB: falta := medio 
 *
 * En todos los casos la recurrencia es final y el tamaño del problema
 * se reduce a la mitad con lo que el comportamiento asintótico es log n.
 *
 * En el mejor caso, *falta* es la mediana del vector V y el programa
 * funciona en tiempo constante.
 *
 */
#include<algorithm>
#include<iostream>
#include<vector>

long long int encontrarFalta(const std::vector<long long int> &v, 
        long long int i, long long int j) 
{
    if (j - i < 2) return i;
    long long int medio = (i+j)/2;
    if (v[medio] == v[medio-1]) 
        if(medio % 2 == 0) return encontrarFalta(v, i, medio-2);
        else return encontrarFalta(v, medio+1, j);
    else if (v[medio] == v[medio + 1]) 
        if (medio % 2 == 0) return encontrarFalta(v, medio+2, j);
        else return encontrarFalta(v, i, medio - 1);
    else return medio;
}

void printArray(const std::vector<long long int> &v) {
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << " ";
    std::cout << std::endl;
}

bool resuelveCaso() {
  long long int casos, n, numeroLeido;
  std::cin >> casos;
  for (int i= 0; i < casos; i++) {
      std::cin >> n;
      std::vector<long long int> v;
      for (int j = 0; j < n; j++) {
          std::cin >> numeroLeido;
          v.push_back(numeroLeido); 
      } 
      std::cout << encontrarFalta(v, 0, n-1) << std::endl;
  }
  return true;
}


int main() {
    resuelveCaso();
}

