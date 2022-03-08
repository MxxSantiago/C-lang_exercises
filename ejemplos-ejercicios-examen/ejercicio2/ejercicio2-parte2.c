#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int cantidad = 100; // Cantidad dinamica

    int numeroDeControl[cantidad], precio[cantidad] , cantidadArticulo[cantidad], i, opcion = 0, posicionArticuloIngresado, posicion = 0;
    char descripcion[cantidad][50];

    while (opcion != 'e') {
        system("cls");

        puts("a) Registro");
        puts("b) Eliminar articulo por numero de control");
        puts("c) Salir");

        printf("\nOpcion: ");
        scanf("%c", &opcion);

        system("cls");

        switch (opcion) {
            case 'a': {
                if (posicion > (cantidad - 1)) {
                    puts("Los arreglos estan llenos");
                } else {
                    printf("Numero de control: ");
                    scanf("%i", &numeroDeControl[posicion]);

                    printf("Precio: ");
                    scanf("%i", &precio[posicion]);

                    printf("Cantidad del articulo: ");
                    scanf("%i", &cantidadArticulo[posicion]);

                    printf("Descripcion: ");
                    getc(stdin);
                    gets(descripcion[posicion]);

                    posicion++;
                }

                break;
            }

            case 'b': {
                int numeroControlIngresado;

                posicionArticuloIngresado = -1;

                printf("Numero de control del articulo a eliminar: ");
                scanf("%i", &numeroControlIngresado);

                for (i = 0; i < posicion; i++) {
                    if (numeroControlIngresado == numeroDeControl[i]) {
                        posicionArticuloIngresado = i;
                        break;
                    }
                }

                system("cls");

                if (posicionArticuloIngresado == -1) {
                    puts("No se encontro el articulo con el numero de control ingresado\n\n");
                    system("pause");
                } else {
                    for (i = posicionArticuloIngresado; i < posicion; i++) {
                        strcpy(descripcion[i], descripcion[i + 1]);
                        numeroDeControl[i] = numeroDeControl[i + 1];
                        precio[i] = precio[i + 1];
                        cantidadArticulo[i] = cantidadArticulo[i + 1];
                    }

                    posicion--;

                    printf("El articulo con el numero de control ingresado se a eliminado.\n\n");
                    printf("Articulos restantes: \n\n");

                    for (i = 0; i < posicion; i++) {
                        printf("ARTICULO [%i]:", i);
                        printf("Numero de control: %i\n",  numeroDeControl[i]);
                        printf("Descripcion: %s\n", descripcion[i]);
                        printf("Precio: %i\n",  precio[i]);
                        printf("CantidadArticulo: %i\n",  cantidadArticulo[i]);
                        printf("-------------------------------\n");
                    }

                    system("pause");
                }

                break;
            }

            case 'c': {
                puts("Chau\n");
                break;
            }

            default: {
                puts("La opcion ingresada no existe, intentelo nuevamente\n");
                break;
            }
        }
    }

    return 0;
}