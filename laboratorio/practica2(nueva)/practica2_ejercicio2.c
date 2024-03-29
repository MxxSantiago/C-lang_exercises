/*
	2. Hacer un programa para guardar 10 frases en un arreglo de cadenas de caracteres, las frases 
       no deber�n de ser mayor a 30 caracteres, al finalizar el llenado del arreglo deber� mostrar:
       
	a. La frase m�s larga y en qu� posici�n del arreglo se encuentra
	b. Las frases en may�sculas que se encuentran en las posiciones pares
	c. Mostrar las frases en orden inverso al de su ingreso
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // variables de ciclos
    int i, j;

    // Definimos la variable que contendr� la posici�n en la que se encontr� la cadena m�s larga
    int posicionMaximaLongitud;

    // Definimos la variable en la cual almacenaremos la longitud mas larga encontrada en el arreglo de cadenas
    int maximaLongitud = INT_MIN;

    // 10 cadenas con una longitud m�xima de 30 caracteres
    char cadenas[10][30];

    // leer cada una de las cadenas ingresadas hasta llenar el arreglo
    for (i = 0; i < 10; i++) {
        printf("Ingrese la cadena en la posicion %d: ", i);
        gets(cadenas[i]);
    }

    // CADENA CON MAYOR LONGITUD
    for (i = 0; i < 10; i++) {
        // Almacenamos la longitud de la cadena evaluada en el ciclo actual
        int longitudCadenaActual = strlen(cadenas[i]);

        /* Si la longitud de la cadena actual es mayor
         * al valor que contiene la variable maximaLongitud, esta le otorga su valor
         * */
        if (maximaLongitud < longitudCadenaActual) {
            maximaLongitud = longitudCadenaActual;

            // Almacenamos la posicion en la que se encuentra la cadena
            posicionMaximaLongitud = i;
        }
    }

    // Limpiar consola
    system("cls");

    // Mostrar la posicion y la cadena con mayor longitud
    printf("La cadena mas grande se encuentra en la posicion %d, y es: %s\n\n", posicionMaximaLongitud, cadenas[posicionMaximaLongitud]);


    printf("Cadenas en mayusculas que se encuentran en una posicion par:\n\n");

    // CADENAS PARES EN MAYUSCULA
    for (i = 0; i < 10; i++) {
        int longitudCadenaActual = strlen(cadenas[i]);
        int caracteresEnMayuscula = 0;

        // Evaluar si la posici�n evaluada ( i ) es par obteniendo su resto al dividirlo entre 2
        if (i % 2 == 0) {
            // Recorremos cada uno de los caracteres de la cadena en la posici�n actual
            for (j = 0; j < longitudCadenaActual; j++) {
                if (isupper(cadenas[i][j])) {
                    caracteresEnMayuscula++;
                }
            }

            // Evaluamos si la cantidad de mayusculas de la cadena equivale a su longitud
            if (caracteresEnMayuscula == longitudCadenaActual) {
                // De ser as� la imprimimos en pantalla
                printf("%d.-%s\n", i, cadenas[i]);
            }
        }
    }

    printf("\nOrden inverso de las cadenas:\n\n");
    // IMPRIMIR EN ORDEN INVERSO
    // Empezamos de la posici�n m�s alta (9 ya que empieza en 0) y vamos reduciendo
    for (i = 9; i >= 0; i--) {
        printf("%d.-%s\n", i, cadenas[i]);
    }

    // C�digo con fines est�ticos
    printf("\n");
    system("pause");

    return 0;
}

