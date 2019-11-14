#include<iostream>
long long int longitud (long long int n) {
    if (n == 0) return 0;
    else return 2*longitud(n-1) + n + 2;
}

char resolverCaso(long long int i, long long int n) {
    long long int inicio = longitud(n-1)+1;
    long long int fin = inicio + n + 1;
    if (inicio <= i && i <= fin) 
        if (inicio == i) return 'B';
        else if (fin == i) return 'H';
        else return 'U';
    else {
        i = i > fin ? i - fin : i;
        return resolverCaso(i, n-1);
    } 
}

int main() {
    long long int i, n;
    std::cin >> n >> i;
    while (std::cin) {
        std::cout << resolverCaso(i,n) << std::endl;
        std::cin >> n >> i;
    }
}
