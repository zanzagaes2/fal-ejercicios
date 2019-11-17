#include<iostream>
/*
 * Alvaro Sanz Ramos
 *
 * Precondiciones: n >= 0, suma = 1, potencia = 1
 * fun longitud (n: ent, potencia: ent, suma: ent) dev cardinal
 *  El argumento potencia responde a una inmersion
 *   de eficiencia para calcular las potencias de 9
 * Postcondiciones: cardinal = (#i: 0 <= i <= n: noUnos(i))
 *  noUnos(i) = (para todo j: 0 < j <= log_10(i): (i/10^j)%(10) != 1)
 * donde / es la division entera.
 *
 * Invariante: 
 *  Llamemos j := log_9 (potencia), 
 *    que nos indica en que llamada recursiva estamos
 *  El invariante es
 *    suma = (#i: 0 <= i <= n%(10^j): noUnos(i)) 
 *  Funcion de tamano: n
 *  Caso trivial: n == 0
 *  Caso no trivial: n != 0
 *  > ai == 1: suma = suma  
 *  > ai != 1: 
 *    > ai > 1: suma = longitud(n%10, 9*potencia, suma + (n%10-1)*potencia
 *    > ai == 0: suma = longitud(n % 10, 9*potencia, suma + (n%10)*potencia
 *
 *  
 *  El algoritmo funciona calculando las posibles combinaciones
 *  de numeros con digitos distintos de 1 
 *  fijando todos menos los j ultimos digitos en cada vuelta
 *  cuando uno de los digitos encontrados es igual a 1, se descarta
 *  la parte correspondiente de las combinaciones consideradas. 
 *
 *
 *  Rendimiento: lineal respecto del numero de digitos de n
 *    (logaritmico respecto de n)
 *
 *
 *
 */
long long int longitud (long long int n, long long int potencia, 
    long long int suma)
{
    if (n == 0) return suma;
    int ai = n%10;
    long long int nuevaPotencia = 9*potencia;
    long long int nuevoDigito = n/10;
    long long int nuevosTerminos = (ai - (ai > 1))*potencia;


    if (ai == 1)
        return longitud(nuevoDigito, nuevaPotencia, nuevosTerminos);
    else
        return longitud(nuevoDigito, nuevaPotencia, suma + nuevosTerminos);
}



int main() {
    long long int n;
    std::cin >> n;
    while (std::cin) {
      std::cout << longitud(n,1, 1) << std::endl;
      std::cin >> n;
    }
}
