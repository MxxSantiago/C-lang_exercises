/* 
	1. Hacer un programa que lea un arreglo de enteros de 10 números, todos los números deberán  
       ser primos, de no ser primo no se guardara en el arreglo, al terminar su llenado obtener lo 
       siguiente:
   
	a. Sumatoria de todos los números leídos
	b. Mostrar los números leídos en el rango de 31 a 101
	c. Mostrar los números que se guardaron en las posiciones impares del arreglo
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variables de ciclos
    int i, j;

    // La sumatoria de los numeros que leeremos, esta empezará en 0 evidentemente
    int sumatoria = 0;

    // Definimos un vector con valores por defecto, esto nos facilita validar la condicion "c" del ejercicio
    int vector[10] = {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0};
    
    // Vector en el que guardaremos todo valor ingresado 
    int vectorSecundario[10];

    /* --> Un número primo solo tiene 2 divisores positivos, él mismo y 1.  <-- */

    for (i = 0; i < 10; i++) {
        int numeroAEvaluar;

        // Divisores del numero evaluado en la posición actual
        int divisores = 0;

        /* Almacenaremos el valor ingresado en una variable temporal, esto con el fin de realizar realizar
         * las validaciones pertinentes antes de autorizar su incorporación en el arreglo */
        printf("Ingrese un valor para la posicion %d: ", i);
        scanf("%d", &numeroAEvaluar);

        // Empezamos por 1 hasta llegar al valor actual del numero en la posición actual
        for (j = 1; j <= numeroAEvaluar; j++) {
            // Evaluamos si el residuo de la división es 0
            if (numeroAEvaluar % j == 0) {
                // En ese caso aumentamos los divisores del número actual;
                divisores++;
            }
        }

        // Si el número evaluado en la posición actual tiene 2 divisores, es un número primo
        if (divisores == 2) {
            // En el caso de que sea un número primo lo guardamos en el arreglo
            vector[i] = numeroAEvaluar;
        }

        // En este caso se nos pide la sumatoria de TODOS los números leídos, por lo que no hay validación alguna
        sumatoria += numeroAEvaluar;

        // Guardamos el valor en el arreglo secundario para su uso posterior
        vectorSecundario[i] = numeroAEvaluar;
    }

    system("cls");

    // Imprimimos la sumatoria
    printf("Sumatoria de TODOS los numeros leidos: %d\n\n", sumatoria);

    printf("TODOS los numeros leidos en el rango [31-101]:\n\n");
    for (i = 0; i < 10; i++) {
        // Según las condiciones dadas (31-101), mostramos el valor en la posición actual
        if (vectorSecundario[i] >= 31 && vectorSecundario[i] <= 101) {
            printf("%d\n", vectorSecundario[i]);
        }
    }

    printf("\nNumeros guardados en las posiciones impares del arreglo:\n\n");
    for (i = 0; i < 10; i++) {
        // Evaluamos que la posición actual NO sea un número primo
        if (i % 2 != 0) {
            /* Evaluamos que contenga un valor mayor a 0 (en otro caso, es imposible que haya sido guardado en el arreglo,
             * por lo tanto, tiene un valor ingresado por el usuario)*/
            if (vector[i] > 0) {
                printf("posicion %d: %d\n", i, vector[i]);
            }
        }
    }

    // Código con fines estéticos
    printf("\n");
    system("pause");

    return 0;
}

