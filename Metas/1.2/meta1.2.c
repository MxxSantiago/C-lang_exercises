#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int opcion = 0;

    while (opcion != 4) {
        system("cls");

        puts("1) Leer una cadena de caracteres de un máximo de 80 caracteres y mostrar la cantidad de palabras que inician con mayuscula");
        puts("2) Leer una cadena de caracteres y si hay un punto antes de una palabra cambiar la primera letra a mayuscula");
        puts("3) Leer una cadena de caracteres, contar cuantas palabras hay, preguntar cuantas quieres mostrar y solo mostrar las que se indiquen, validar no aceptar mostrar un numero de palabras mayor al que contiene la cadena");
        puts("4) Terminar");

        printf("\nOpcion: ");
        scanf("%i", &opcion);

        getc(stdin);

        system("cls");

        switch (opcion) {
            case 1: {
                int cantidad = 0, i;
                char cadena[80];

                printf("Ingrese una cadena de un maximo de 80 caracteres: ");
                gets(cadena);

                int longitudCadena = strlen(cadena);

                for (i = 0; i <= longitudCadena; i++) {
                    char valorActual = cadena[i], valorSiguiente = cadena[i +
                                                                          1];

                    if (i == 0 && isupper(valorActual)) cantidad++;

                    if (valorActual == ' ') {
                        if (isupper(valorSiguiente)) cantidad++;
                    }
                }

                printf("\n%i de las palabras ingresadas empiezan con mayuscula.",
                       cantidad);

                break;
            }

            case 2: {
                char cadena[100], i, j;

                printf("Ingrese una cadena de caracteres: ");
                gets(cadena);

                int longitudCadena = strlen(cadena);

                for (i = 0; i <= longitudCadena; i++) {
                    if (cadena[i] == '.') {
                        for (j = i; j <= longitudCadena; j++) {
                            if (isalpha(cadena[j])) {
                                cadena[j] = toupper(cadena[j]);
                                break;
                            }
                        }
                    }
                }

                printf("\nCadena modificada:\n\n%s", cadena);

                break;
            }

            case 3: {
                int cantidad = 0, mostrar = 0, i, j, k;
                char cadena[100];

                printf("Ingrese una cadena de caracteres: ");
                gets(cadena);

                int longitudCadena = strlen(cadena);

                for (i = 0; i <= longitudCadena; i++) {
                    char valorActual = cadena[i], valorSiguiente = cadena[i +
                                                                          1];

                    if (i == 0 && isalpha(valorActual)) cantidad++;

                    if (cadena[i] == ' ') {
                        for (j = i; j <= longitudCadena; j++) {
                            if (isalpha(cadena[j])) {
                                cantidad++;

                                i = j;

                                break;
                            }
                        }
                    }
                }

                while (mostrar <= 0) {
                    system("cls");

                    printf("Ingrese las palabras a mostrar: ");
                    scanf("%i", &mostrar);

                    if (mostrar > cantidad) {
                        mostrar = 0;

                        printf("\nSe debe ingresar una cantidad menor o igual a la de la cadena ingresada. (%i)\n\n",
                               cantidad);

                        system("pause");
                    }
                }

                for (i = 0; i <= longitudCadena; i++) {
                    char valorActual = cadena[i], valorSiguiente = cadena[i +
                                                                          1];

                    if (i == 0 && isalpha(valorActual)) mostrar--;

                    if (mostrar < 0) break;

                    printf("%c", valorActual);

                    if (valorSiguiente == ' ') {
                        for (j = i + 1; j <= longitudCadena; j++) {
                            if (isalpha(cadena[j])) {
                                for (k = j - 1; k <= longitudCadena; k++) {
                                    printf("%c", cadena[k]);

                                    if (cadena[k] == ' ') {
                                        i = k;

                                        mostrar--;

                                        break;
                                    }
                                }

                                break;
                            }
                        }
                    }
                }

                break;
            }

            case 4:
                puts("Chau");
                break;
        }

        printf("\n\n");

        system("pause");
    }
}
