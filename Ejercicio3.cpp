// Álvaro Sanz y Juan Manuel Haro
//
#include <algorithm>
#include <iostream>
#include <vector>

/*
	Precondición: (N >= 0 ^ (para todo i: 0 <= i < N : 0 < V[i] <= 10^18))
	Interfaz: resuelveCaso (V[N] de ent) dev m, f2, M, f1
	Postcondición: M = (max i: 0 <= i < N: V[i]) ^ m = (min i: 0 <= i < N: V[i])
		^ f1 = (#i: 0 <= i < N : V[i] = M) ^ f2 = (#i: 0 <= i < N : V[i] = m)
	
	Inicialización i = 0
	Función de cota: N-1-i
	Invariante: 0 <= i < N ^ M = (max j: 0 <= j < i: V[j]) ^ m = (min j: 0 <= j < i: V[j])
		^ f1 = (#j: 0 <= j < i : V[j] = M) ^ f2 = (#j: 0 <= j < i : V[j] = m)
	Condición de bucle: i != n-1
	Avanzar: i++
	Comprobar terminación: i = n-1
*/

std::vector<long long int> resuelveCaso() {
	long long int valorLeido, maximo, minimo;
	int f1 = 0, f2 = 0;
	std::cin >> valorLeido;
	maximo = minimo = valorLeido;
	while (valorLeido > 0) {
		if (valorLeido == maximo) f1++;
		if (valorLeido == minimo) f2++;
		if (valorLeido > maximo) maximo = valorLeido, f1 = 1;
		if (valorLeido < minimo) minimo = valorLeido, f2 = 1;
		std::cin >> valorLeido;
	}
	std::vector<long long int> resultado = { minimo, f2, maximo, f1 };
	return resultado;
}

int main() {
	int numCasos, longVector, indice;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		std::vector<long long int> solucion = resuelveCaso();
		for (int i = 0; i < solucion.size()-1; i++)
			std::cout << solucion.at(i) << " ";
		std::cout << solucion.at(solucion.size()-1) << std::endl;
	}
}
