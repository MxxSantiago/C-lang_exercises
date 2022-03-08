#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int cantidad = 100, i, longitudCadena;
    char descripcion[cantidad];

    printf("Descripcion: ");
    gets(descripcion);

    longitudCadena = strlen(descripcion);

    system("cls");

    printf("Letras mayusculas que contiene la cadena:\n\n");

    for (i = 0; i < longitudCadena; i++) {
        if (isupper(descripcion[i])) {
            printf("%c", descripcion[i]);
        }
    }

    return 0;
}