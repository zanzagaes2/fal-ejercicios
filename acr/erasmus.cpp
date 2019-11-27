#include <stdio.h>
#include<vector>
long long int sumar(std::vector<long int> &V) {
    long long int suma = 0;
    for (int i = 0; i < V.size(); i++)
        suma += V[i];
    return suma;
}

long long int numeroParejas(std::vector<long int> &V){
    long long int sumaTotal = sumar(V);
    long long int suma = 0;
    for (int i = 0; i < V.size(); i++) {
        sumaTotal -= V[i];
        suma += V[i]*sumaTotal;
    }
    return suma;
}

int main() {
    long int numero, numeroLeido;
    scanf("%ld", &numero);
    while (numero != 0) {
        std::vector<long int> V;
        for (int i = 0; i < numero; i++) {
            scanf("%ld", &numeroLeido);
            V.push_back(numeroLeido);
        }
        printf("%lld\n", numeroParejas(V));
        //printVector(V);
        scanf("%ld", &numero);
    }
}
