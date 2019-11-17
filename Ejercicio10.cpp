#include<iostream>
/*
 * Alvaro Sanz Ramos
 *
 * Definimos:
 *  longitudNumero(n) := log_10(n) + 1
 * donde asumimos que log_10 es el logaritmo entero en base 10
 *
 * esPolidivisible(n):
 *  n >=0 y (pt i: 0 =< i < longitudNumero(n): (n / (10^i))
 *    % (longitudNumero(n)-i+1) == 0) 
 *  donde "^" es la operacion potencia y "%" es la operacion modulo
 *   y "/" es la division entera
 *
 * Precondiciones: esPolidivisible(n) ^ long <= i
 * fun polidivisibles (n: ent, long: ent, i: ent) dev V[N] de ent 
 * Poscondiciones: 
 *  (pt i: 0 <= i < N: esPolidivisible(V[i]) ^ 
 *    V[i] / (long - longitudNumero(n)) == n)
 *
 * El argumento *long* responde a una inversion de eficiencia
 *  para evitar calcular la longitud de *n* (que es una operacion
 *  lineal)
 *
 * Funcion de tamano: 10**(i - longitud)
 * Caso trivial: si longitudNumero(n) == i
 *  si esPolidivisible(n) se annade a V
 *  si no se acaba
 * Caso no trivial:
 *  si esPolidivisible(n) se annade a V
 *  se llama a polidivisibles(n', long+1, i) para
 *   n*10 <= n' < n*10+10
 * Eficiencia: exponencial en i-longitud, puede haber
 *  hasta 10 llamadas recursivas en cada llamada
 *
 * Se observa que si un numero no es polidivisble entonces
 * ningun numero que lo incluya en el lugar inicial puede serlo. 
 *
  */

bool esPolidivisible(long long int, int);
int longitudNumero (long long int);
void polidivisibles(long long int, int, int);
void resuelve(long long int, int);

bool esPolidivisible(long long int n, int longitudNumero) {
  bool polidivisible = true;
  while (polidivisible && longitudNumero) {
    polidivisible = n % longitudNumero == 0;
    longitudNumero--, n /= 10;
  }
  return polidivisible;
}

int longitudNumero (long long int n) {
  int i = 1;
  for (; n >= 10; n /= 10)
    i++;
  return i;
}

void polidivisibles(long long int n, int longitud, int i) {
  if (longitud <= i && n % longitud == 0) {
    std::cout << n << std::endl;
    n *= 10;
    for (int j = 0; j < 10; j++)
      polidivisibles(n + j, longitud+1, i);
  }
}

int main() {
    long long int n;
    int i;
    std::cin >> n >> i;
    while (std::cin) {
      polidivisibles(n, longitudNumero(n), i);
      std::cout << "---" << std::endl;
      std::cin >> n >> i;
    }
}
