#include <stdio.h>

char presoAusente(char v[], char charInicio, char charFinal, int i, int j) {
    if (j-1 == i) { // Solo quedan dos elementos
        char vi = v[i];
        if (v[j] - vi == 2) return vi + 1; 
        else if (i == 0) return charInicio;
        else return charFinal;
    }
    else {
        int medio = (i+j)/2;
        if (v[medio] > charInicio + medio) 
            return presoAusente(v, charInicio, charFinal, i, medio);
        else 
            return presoAusente(v, charInicio, charFinal, medio, j);
    }
}

int main() {
    int longitud, n;
    char charInicio, charFinal;
    char v[26];
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c %c\n", &charInicio, &charFinal);
        longitud = charFinal - charInicio;
        for (int j = 0; j < longitud; j++)
            scanf("%c ", &v[j]);
        printf("%c\n", presoAusente(v, charInicio, charFinal, 0, longitud-1));
    }
}
