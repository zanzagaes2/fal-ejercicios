#include <algorithm>
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

long int resuelveCaso(std::vector<long int> &v) {
    long int longitudSegmento = 0, maxLongitudSegmento = 0; 
    long unsigned int size = v.size();
    for(long unsigned int i = 0; i < size-1; i++)
        if (v.at(i) == v.at(i+1) && ++longitudSegmento > maxLongitudSegmento) 
            maxLongitudSegmento = longitudSegmento;
        else longitudSegmento = 0;
    return maxLongitudSegmento;
}

int main() {
    do {
        long int datoLeido;
        std::vector<long int> v;
        std::cin >> datoLeido;
        while (datoLeido != -1) {
            v.push_back(datoLeido);
            std::cin >> datoLeido;
        }
        if (v.size()) {
            long int diff = resuelveCaso(v);
            if (diff == 0) std::cout << "HOY NO COMEN" << std::endl;
            else std::cout << diff << std::endl;
        }
	} while (std::cin);
}
