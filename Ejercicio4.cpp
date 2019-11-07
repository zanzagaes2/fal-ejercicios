#include <algorithm>
#include <iostream>
#include <vector>

/*
Coste del algoritmo (tiempo) = 3n ~ O(n)
Coste del algoritmo (espacio) = n

Precondición (0 < N <= 10.000 ^ (para todo i: 0 <= i < N: -274 < V[N] < 1000))
Interfaz: cuentaExtremos (V[N]: de enteros) dev numPicos, numValles
 donde numPicos = (#i: 1 < i < N-1: V[i-1] < V[i] ^ V[i] > V[i+1])
 y numValles = (#i: 1 < i < N-1: V[i-1] > V[i] ^ V[i] < V[i+1])

Invariante: (1 <= i < N-1) ^ 
 numPicos = (#j: 1 < j < i-1: V[j-1] < V[j] ^ V[j] > V[j+1])
 numValles = (#j: 1 < j < i-1: V[j-1] > V[j] ^ V[j] < V[j+1])
Funcion de cota: N-1-i
Avanzar: i++, 
    numPicos = numPicos+1 si V[i-1] < V[i] ^ V[i] > V[i+1]
               numPicos si no
    numValles = numValles+1 si V[i-1] > V[i] ^ V[i] < V[i+1]
               numValles si no

Condición de bucle: i < N-1
Comprobar terminación: i = N-1


*/

std::vector<int> resuelveCaso(std::vector<int> datos) {
    int numValles = 0, numPicos = 0;
    for (int i = 1; i < datos.size()-1; i++)
        if (datos.at(i-1) < datos.at(i) && datos.at(i) > datos.at(i+1))
            numPicos++;
        else if (datos.at(i-1) > datos.at(i) && datos.at(i) < datos.at(i+1))
            numValles++;
    std::vector<int> resultados = {numPicos, numValles};
    return resultados;
}

void printVector(std::vector<int> datos) {
    for (auto dato: datos)
        std::cout << dato << " ";
    std::cout << std::endl;
}

int main() {
	int numCasos, longVector, nuevoDato;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
	    std::cin >> longVector;
		std::vector<int> datos;
		for (int i = 0; i < longVector; i++) {
            std::cin >> nuevoDato;
            datos.push_back(nuevoDato);
        }
	    datos = resuelveCaso(datos);		
        std::cout << datos.at(0) << " " << datos.at(1) << std::endl;
       }
}
