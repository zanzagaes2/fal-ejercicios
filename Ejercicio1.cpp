// Grupo XYZ, �lvaro Sanz y Luis Ariza
// Comentario general sobre la soluci�n,
// explicando c�mo se resuelve el problema

// Para cada n�mero en el vector se observa si es mayor que el anterior
#include <iostream>
#include <fstream>
// funci�n que resuelve el problema
// comentario sobre el coste, O(f(N)), donde N es ...

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta

/*  Pre-condici�n: {2 <= N <= 100.000 y para todo i, 1 <= i <= N, 1 <= V[i] <= 10^6}
	Post-condici�n: resuelveCaso(n) = (para todo i, 1 <= i <= n-1, V[i] < V[i+1]) o 
		(para todo i, 1 <= i <= n-1, V[i] > V[i+1])
	En tiempo, el comportamiento asint�tico es lineal y en memoria es constante

	Invariante: 0 <= i <= N y x=X y decreciente = (para todo j, 0 <= j < i, V[j] > V[j+1])
								  y creciente = (para todo j, 0 <= j < i, V[j] < V[j+1])
	Funcion de cota: N-i
*/
bool resuelveCaso(int numCasos) {
	int i = 1;
	bool creciente = true, decreciente = true;
	long int currentValue, lastValue;
	std::cin >> lastValue;
	while ((decreciente || creciente) && i < numCasos) {
 		std::cin >> currentValue;
		if (currentValue <= lastValue) creciente = false;
		if (currentValue >= lastValue) decreciente = false;
		lastValue = currentValue, i++;
	}
	return creciente || decreciente;
}

int main() {
	int numCasos;
	std::cin >> numCasos;
	while (numCasos) {
		if (resuelveCaso(numCasos)) std::cout << "DALTON\n";
		else std::cout << "DESCONOCIDOS\n";
		std::cin.ignore(10000, '\n');
		std::cin >> numCasos;
	}
}