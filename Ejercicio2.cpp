// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <algorithm>
#include <iostream>

/*
	Precondición: (numCasos >= 0) y (0 <= indice <= numCasos)
	Poscondición: (resuelveCasos(numCasos, indice) = 
		(para todo i,j : 0 <= i <= indice ^ indice < j <= numCasos: V[i] < V[j])
	Invariante: (0 <= i <= numCasos ^ maxIzquierda = max (V, 0, i)
*/
bool resuelveCaso(int numCasos, int indice) {
	int i = 1;
	int maxIzquierda, valorLeido;
	std::cin >> maxIzquierda;
	while (i <= indice) {
		std::cin >> valorLeido;
		maxIzquierda = std::max(valorLeido, maxIzquierda);
		i++;
	}

	int minDerecha = maxIzquierda+1;
	if(i <  numCasos) std::cin >> minDerecha, i++;
	while (i < numCasos) {
		std::cin >> valorLeido;
		minDerecha = std::min(valorLeido, minDerecha);
		i++;
	}
	return minDerecha > maxIzquierda;
}

int main() {
	int numCasos, longVector, indice;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
		std::cin >> longVector >> indice;
		if (resuelveCaso(longVector, indice)) std::cout << "SI\n";
		else std::cout << "NO\n";
		std::cin.ignore(10000, '\n');
	}
}