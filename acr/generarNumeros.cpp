#include<math.h>
#include<fstream>
int main() {
    std::ofstream archivoEntrada;
    archivoEntrada.open("numeros.in");
    long int limite = pow(10, 6);
    for (long int x = 1; x < limite; x += 17)
        archivoEntrada << x << "\n";
}
