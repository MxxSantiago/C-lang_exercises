#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int cantidad = 500; // Cantidad dinamica

    int horasDeClase[cantidad], horasDeLaboratorio[cantidad], numeroDeEmpleado[cantidad] ,i, validacion, opcion = 0, largoNombre = 15, posicion = 0;
    char nombre[cantidad][largoNombre], categoria[cantidad], fechaDeIngreso[cantidad][8], nombreCoordinacion[cantidad][20];

    while (opcion != 'c') {
        system("cls");

        puts("a) Altas");
        puts("b) Consultas");
        puts("c) Salir");

        printf("\nOpcion: ");
        scanf("%c", &opcion);

        system("cls");

        switch (opcion) {
            case 'a': {
                if (posicion == cantidad) {
                    puts("Los arreglos estan llenos");
                } else {
                    printf("Numero de empleado: ");
                    scanf("%i", &numeroDeEmpleado[posicion]);

                    printf("Fecha de ingreso: ");
                    getc(stdin);
                    gets(fechaDeIngreso[posicion]);

                    printf("Nombre: ");
                    gets(nombre[posicion]);

                    printf("Categoria: ");
                    scanf("%c", &categoria[posicion]);

                    if (categoria[posicion] == 'A') {
                        validacion = -1;

                        while (validacion == -1) {
                            printf("Numero de horas de clase: ");
                            scanf("%i", &horasDeClase[posicion]);

                            system("cls");

                            if (horasDeClase[posicion] <= 20) {
                                validacion++;
                            } else {
                                printf("Las horas de clase no deben ser mayores a 20, vuelve a intentarlo\n\n");
                                system("pause");
                                system("cls");
                            }
                        }

                        printf("Ingrese el nombre de coordinacion: ");
                        getc(stdin);
                        gets(nombreCoordinacion[posicion]);
                    }

                    if (categoria[posicion] == 'B') {
                        validacion = -1;

                        while (validacion == -1) {
                            printf("Numero de horas de clase: ");
                            scanf("%i", &horasDeClase[posicion]);

                            printf("Numero de horas de laboratorio: ");
                            scanf("%i", &horasDeLaboratorio[posicion]);

                            system("cls");

                            if ((horasDeClase[posicion] + horasDeLaboratorio[posicion]) <= 30) {
                                validacion++;
                            } else {
                                printf("Las suma de horas de clase no deben ser mayores a 30, vuelve a intentarlo\n\n");
                                system("pause");
                                system("cls");
                            }
                        }
                    }

                    if (categoria[posicion] == 'C') {
                        validacion = -1;

                        while (validacion == -1) {
                            printf("Numero de horas de laboratorio: ");
                            scanf("%i", &horasDeLaboratorio[posicion]);

                            system("cls");

                            if (horasDeLaboratorio[posicion] <= 25) {
                                validacion++;
                            } else {
                                printf("Las horas de laboratorio no deben ser mayores a 25, vuelve a intentarlo\n\n");
                                system("pause");
                                system("cls");
                            }
                        }
                    }

                    posicion++;
                }

                break;
            }

            case 'b': {
                int opcionSegundoMenu = 0;

                while (opcionSegundoMenu != 'd') {
                    system("cls");

                    puts("a) Consulta general");
                    puts("b) Consulta por fecha de ingreso");
                    puts("c) Consulta por categoria");
                    puts("d) Regreso al menu principal");

                    printf("\nOpcion: ");
                    scanf("%c", &opcionSegundoMenu);

                    system("cls");

                    switch (opcionSegundoMenu) {
                        case 'a': {
                            int A = 0, B = 0, C = 0;

                            for (i = 0; i < posicion; i++)  {
                                if (categoria[i] == 'A') A++;
                                if (categoria[i] == 'B') B++;
                                if (categoria[i] == 'C') C++;
                            }

                            printf("Maestros en categoria A: %i\n", A);
                            printf("Maestros en categoria B: %i\n", B);
                            printf("Maestros en categoria C: %i\n\n", C);

                            for (i = 0; i < posicion; i++) {
                                printf("NUMERO DE EMPLEADO: %i\n", numeroDeEmpleado[i]);
                                printf("NOMBRE: %s\n", nombre[i]);
                                printf("CATEGORIA: %c\n", categoria[i]);
                                printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);

                                if (horasDeLaboratorio[i] > 0) printf("HORAS DE LABORATORIO: %i\n", horasDeLaboratorio[i]);
                                if (horasDeClase[i] > 0) printf("HORAS DE CLASE: %i\n", horasDeClase[i]);
                                if (strlen(nombreCoordinacion[i]) > 0) printf("NOMBRE DE COORDINACION: %s\n", nombreCoordinacion[i]);

                                printf("----------------\n");
                            }

                            puts("\n");
                            system("pause");

                            break;
                        }

                        case 'b': {
                            char fechaIngresada[8];
                            int personasEmparejadas = 0;

                            printf("Ingrese la fecha por la que desea hacer el filtrado: ");
                            scanf("%s", &fechaIngresada);

                            system("cls");

                            printf("Maestros con fecha de ingreso el dia %s:\n\n", fechaIngresada);

                            for (i = 0; i <= posicion; i++) {
                                if ((strcmp(fechaIngresada, fechaDeIngreso[i])) == 0) {
                                    personasEmparejadas++;

                                    printf("NUMERO DE EMPLEADO: %i\n", numeroDeEmpleado[i]);
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("CATEGORIA: %c\n", categoria[i]);

                                    if (horasDeLaboratorio[i] > 0) printf("HORAS DE LABORATORIO: %i\n", horasDeLaboratorio[i]);
                                    if (horasDeClase[i] > 0) printf("HORAS DE CLASE: %i\n", horasDeClase[i]);
                                    if (strlen(nombreCoordinacion[i]) > 0) printf("NOMBRE DE COORDINACION: %s\n", nombreCoordinacion[i]);

                                    printf("----------------\n");
                                }
                            }

                            if (personasEmparejadas == 0) printf("[No se encontro a ningun maestro con esa fecha de ingreso]");

                            puts("\n");
                            system("pause");

                            break;
                        }

                        case 'c': {
                            char categoriaIngresada = ' ';
                            int personasEmparejadas = 0;

                            printf("Ingrese la categoria por la que desea hacer el filtrado: ");
                            scanf(" %c", &categoriaIngresada);

                            system("cls");

                            printf("Maestros de la categoria %c:\n\n", categoriaIngresada);

                            for (i = 0; i <= posicion; i++) {
                                if (categoriaIngresada == categoria[i]) {
                                    personasEmparejadas++;

                                    printf("NUMERO DE EMPLEADO: %i\n", numeroDeEmpleado[i]);
                                    printf("NOMBRE: %s\n", nombre[i]);
                                    printf("FECHA DE INGRESO: %s\n", fechaDeIngreso[i]);

                                    if (horasDeLaboratorio[i] > 0) printf("HORAS DE LABORATORIO: %i\n", horasDeLaboratorio[i]);
                                    if (horasDeClase[i] > 0) printf("HORAS DE CLASE: %i\n", horasDeClase[i]);
                                    if (strlen(nombreCoordinacion[i]) > 0) printf("NOMBRE DE COORDINACION: %s\n", nombreCoordinacion[i]);

                                    printf("----------------\n");
                                }
                            }

                            if (personasEmparejadas == 0) printf("[No se encontro a ningun maestro con la categoria ingresada]");

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