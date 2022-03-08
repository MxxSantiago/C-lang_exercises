/******************************************************************************
Hacer un programa que lea un vector de enteros de 20 números, todos los números deberán ser múltiplos de
10, de no ser así no se aceptaran en el vector, obtener lo siguiente:
a. Sumatoria de todos los números leídos
b. Mostrar los números leídos en el rango de 30 a 90
c. Mostrar los números que se guardaron en las posiciones impares
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int cantidad = 20, numeros[cantidad], i, j;
    
    for (i = 1; i <= cantidad; i++) {
        int validacion = 1;
        
        while(validacion != 2) {
        	system("cls");
        	
            printf("[%i de %i] Ingrese un numero: ", i, cantidad);
            scanf("%d", &numeros[i]);
            
            if((numeros[i] % 10) == 0) {
                validacion = 2;
            } else {
            	printf("\nEl numero ingresado debe ser multiplo de 10\n");
            	
            	system("pause");
			}
        }
    }
    
    char opcion;
    
    while (opcion != 'd') {
        system("cls");
        
        puts("a) Sumatoria de todos los numeros leidos");
        puts("b) Mostrar los numeros leidos en el rango de 30 a 90");
        puts("c) Mostrar los numeros que se guardaron en las posiciones impares");
        puts("d) Salir");
        
        printf("Opcion: ");
        scanf("%c", &opcion);
        
        system("cls");
        
        switch (opcion) {
            case 'a': {
                int total = 0;
                
                printf("Sumatoria de todos los numeros leídos: ");
                
                for (i = 1; i <= cantidad; i++) {
                    total += numeros[i];
                }
                
                printf("%d", total);
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'b': {
                printf("Numeros leidos en el rango de 30 a 90: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    if(numeros[i] >= 30 && numeros[i] <= 90) {
                        printf("%d\n", numeros[i]);
                    }
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'c': {
                printf("Numeros que se guardaron en las posiciones impares: \n");
                
                for (i = 1; i <= cantidad; i += 2) {
                    printf("%i\n", numeros[i]);
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'd': {
                printf("Chau\n");
                break;
            }
        }
    }

    return 0;
}

