#include <stdio.h>
#include <stdlib.h>

int main() {
    int cantidad = 50; // Cantidad dinamica

    int numeroDeFolio[cantidad] ,i, validacion, opcion = 0, largoNombre = 15, posicion = 0;
    char nombre[cantidad][largoNombre], nombreMadre[cantidad][20], sala[cantidad], fechaDeIngreso[cantidad][8];
    float edad[cantidad];

    while (opcion != 'c') {
        system("cls");

        puts("a) Alta");
        puts("b) Consulta");
        puts("c) Terminar");

        printf("\nOpcion: ");
        scanf("%c", &opcion);

        system("cls");

        switch (opcion) {
            case 'a': {
                if (posicion == cantidad) {
                    puts("Los arreglos estan llenos");
                } else {
                    printf("Numero de folio: ");
                    scanf("%i", &numeroDeFolio[posicion]);

                    printf("Fecha de ingreso: ");
                    getc(stdin);
                    gets(fechaDeIngreso[posicion]);

                    printf("Nombre: ");
                    gets(nombre[posicion]);

                    printf("Nombre de la madre: ");
                    gets(nombreMadre[posicion]);

                    validacion = 1;

                    do {
                        validacion = 1;
                        printf("Edad: ");
                        scanf("%f", &edad[posicion]);

                        if (edad[posicion] < 1) {
                            sala[posicion] = 'A';
                        } else if (edad[posicion] >= 1 && edad[posicion] < 2) {
                            sala[posicion] = 'B';
                        } else if (edad[posicion] >= 2 && edad[posicion] <= 4) {
                            sala[posicion] = 'C';
                        } else {
                            validacion = -1;
                            system("cls");
                            printf("La edad maxima es de 4 \n\n");
                            system("pause");
                            system("cls");
                        }
                    } while (validacion == -1);

                    posicion++;
                }

                break;
            }

            case 'b': {
                int opcionSegundoMenu = 0;

                while (opcionSegundoMenu != 'd') {
                    system("cls");

                    puts("a) Consulta general");
                    puts("b) Consulta por sala");
                    puts("c) Consulta por rango de edades");
                    puts("d) Regreso al menu principal");

                    printf("\nOpcion: ");
                    scanf("%c", &opcionSegundoMenu);

                    system("cls");

                    switch (opcionSegundoMenu) {
                        case 'a': {
                            int A = 0, B = 0, C = 0;

                            for (i = 0; i < posicion; i++)  {
                                if (sala[i] == 'A') A++;
                                if (sala[i] == 'B') B++;
                                if (sala[i] == 'C') C++;
                            }

                            printf("Inscritos en sala A: %i\n", A);
                            printf("Inscritos en sala B: %i\n", B);
                            printf("Inscritos en sala C: %i\n\n", C);

                            for (i = 0; i < posicion; i++) {
                                printf("NOMBRE: %s\n", nombre[i]);
                                printf("EDAD: %.1f\n", edad[i]);
                                printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                printf("----------------\n");
                            }

                            puts("\n");
                            system("pause");

                            break;
                        }

                        case 'b': {
                            char salaIngresada = ' ';
                            int personasEmparejadas = 0;

                            printf("Ingrese la sala por la que desea hacer el filtrado: ");
                            scanf(" %c", &salaIngresada);

                            system("cls");

                            printf("Inscritos en la sala %c:\n\n", salaIngresada);

                            for (i = 0; i <= posicion; i++) {
                                if (salaIngresada == sala[i]) {
                                    personasEmparejadas++;

                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("EDAD: %.1f\n", edad[i]);
                                    printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                    printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                    printf("----------------\n");
                                }
                            }

                            if (personasEmparejadas == 0) printf("[No se encontro a nadie inscrito en esta sala]");

                            puts("\n");
                            system("pause");

                            break;
                        }

                        case 'c': {
                            printf("Menores a 1 anio:\n\n");
                            for (i = 0; i < posicion; i++) {
                                if (edad[i] < 1) {
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                    printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                    printf("----------------\n");
                                }
                            }

                            printf("Con edad de 1 anio:\n\n");
                            for (i = 0; i < posicion; i++) {
                                if (edad[i] >= 1 && edad[i] < 2) {
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                    printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                    printf("----------------\n");
                                }
                            }

                            printf("\n\nCon edad de 2 anios:\n\n");
                            for (i = 0; i < posicion; i++) {
                                if (edad[i] >= 2 && edad[i] < 3) {
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                    printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                    printf("----------------\n");
                                }
                            }

                            printf("\n\nCon edad de 3 anios:\n\n");
                            for (i = 0; i < posicion; i++) {
                                if (edad[i] >= 3 && edad[i] < 4) {
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                    printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                    printf("----------------\n");
                                }
                            }

                            printf("\n\nCon edad de 4 anios:\n\n");
                            for (i = 0; i < posicion; i++) {
                                if (edad[i] >= 4 && edad[i] < 5) {
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("NOMBRE DE LA MADRE: %s\n", nombreMadre[i]);
                                    printf("NUMERO DE FOLIO: %i\n", numeroDeFolio[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);
                                    printf("----------------\n");
                                }
                            }

                            puts("\n");
                            system("pause");

                            break;
                        }

                        default: {
                            break;
                        }
                    }
                }
            }

            default: {
                puts("La opcion ingresada no existe, intentelo nuevamente\n");
                break;
            }
        }
    }

    return 0;
}