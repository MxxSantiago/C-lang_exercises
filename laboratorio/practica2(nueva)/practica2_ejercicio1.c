/* 
	1. Hacer un programa que lea un arreglo de enteros de 10 n�meros, todos los n�meros deber�n  
       ser primos, de no ser primo no se guardara en el arreglo, al terminar su llenado obtener lo 
       siguiente:
   
	a. Sumatoria de todos los n�meros le�dos
	b. Mostrar los n�meros le�dos en el rango de 31 a 101
	c. Mostrar los n�meros que se guardaron en las posiciones impares del arreglo
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variables de ciclos
    int i, j;

    // La sumatoria de los numeros que leeremos, esta empezar� en 0 evidentemente
    int sumatoria = 0;

    // Definimos un vector con valores por defecto, esto nos facilita validar la condicion "c" del ejercicio
    int vector[10] = {0, 0, 0, 0, 0, 0, 0, 0 ,0, 0};
    
    // Vector en el que guardaremos todo valor ingresado 
    int vectorSecundario[10];

    /* --> Un n�mero primo solo tiene 2 divisores positivos, �l mismo y 1.  <-- */

    for (i = 0; i < 10; i++) {
        int numeroAEvaluar;

        // Divisores del numero evaluado en la posici�n actual
        int divisores = 0;

        /* Almacenaremos el valor ingresado en una variable temporal, esto con el fin de realizar realizar
         * las validaciones pertinentes antes de autorizar su incorporaci�n en el arreglo */
        printf("Ingrese un valor para la posicion %d: ", i);
        scanf("%d", &numeroAEvaluar);

        // Empezamos por 1 hasta llegar al valor actual del numero en la posici�n actual
        for (j = 1; j <= numeroAEvaluar; j++) {
            // Evaluamos si el residuo de la divisi�n es 0
            if (numeroAEvaluar % j == 0) {
                // En ese caso aumentamos los divisores del n�mero actual;
                divisores++;
            }
        }

        // Si el n�mero evaluado en la posici�n actual tiene 2 divisores, es un n�mero primo
        if (divisores == 2) {
            // En el caso de que sea un n�mero primo lo guardamos en el arreglo
            vector[i] = numeroAEvaluar;
        }

        // En este caso se nos pide la sumatoria de TODOS los n�meros le�dos, por lo que no hay validaci�n alguna
        sumatoria += numeroAEvaluar;

        // Guardamos el valor en el arreglo secundario para su uso posterior
        vectorSecundario[i] = numeroAEvaluar;
    }

    system("cls");

    // Imprimimos la sumatoria
    printf("Sumatoria de TODOS los numeros leidos: %d\n\n", sumatoria);

    printf("TODOS los numeros leidos en el rango [31-101]:\n\n");
    for (i = 0; i < 10; i++) {
        // Seg�n las condiciones dadas (31-101), mostramos el valor en la posici�n actual
        if (vectorSecundario[i] >= 31 && vectorSecundario[i] <= 101) {
            printf("%d\n", vectorSecundario[i]);
        }
    }

    printf("\nNumeros guardados en las posiciones impares del arreglo:\n\n");
    for (i = 0; i < 10; i++) {
        // Evaluamos que la posici�n actual NO sea un n�mero primo
        if (i % 2 != 0) {
            /* Evaluamos que contenga un valor mayor a 0 (en otro caso, es imposible que haya sido guardado en el arreglo,
             * por lo tanto, tiene un valor ingresado por el usuario)*/
            if (vector[i] > 0) {
                printf("posicion %d: %d\n", i, vector[i]);
            }
        }
    }

    // C�digo con fines est�ticos
    printf("\n");
    system("pause");

    return 0;
}

