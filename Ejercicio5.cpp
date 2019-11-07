#include <algorithm>
#include <iostream>
#include <vector>

/*
Coste del algoritmo (tiempo): O(n)
Coste del algoritmo (espacio): O(n)

Precondiciones: N > 0
alturaArboles(V[N]: de enteros, altura:entero) dev maxInicio, maxFin
Poscondiciones:
    (para todo i: maxInicio <= i <= maxFin: V[i] > altura)
    y si i,j son enteros entre 1 y N tales que 
        (para todo k: i <= k <= j: V[k] > altura) =>
            j-i < maxFin-maxInicio o bien i > maxInicio
Invariante:
    (para todo i: maxInicio <= i <= maxFin: V[i] > altura)
    y si j,k son enteros entre 1 y i tales que 
        (para todo k: i <= k <= j: V[k] > altura) =>
            j-k < maxFin-maxInicio o j-k = maxFin - maxInicio ^ k > maxInicio

Avanzar: i++
    si i-inicio > maxFin-maxInicio ^ (para todo j: inicio < j < i: V[j] > altura)
        maxFin, maxInicio = i, inicio
    si V[i] < 0 inicio = i+1   
                        
Función de cota: N - i 
Condición de bucle: i < N
Terminación: i = N

    

 */
void resuelveCaso(int longitud, int altura) {
    int datoLeido, maxInicio = 0, maxFin = 0, inicio = 0;
    for (int i = 0; i < longitud; i++) {
        std::cin >> datoLeido;
        if (datoLeido > altura && i - inicio > maxFin - maxInicio) maxFin = i, maxInicio=inicio;
        else if (datoLeido < altura) inicio = i+1; 
    }
    std::cout << maxInicio << " " << maxFin << std::endl;
}

int main() {
	int numCasos, longVector, altura;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; i++) {
	    std::cin >> longVector >> altura;
		resuelveCaso(longVector, altura);	
   }
}
