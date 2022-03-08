/******************************************************************************
Hacer un programa que lea un vector de 15 números enteros, después de ello muestre un menú con las
siguientes opciones:
a. Mostrar los números positivos del vector
b. Mostrar los números negativos del vector
c. Mostrar los números múltiplos de 3 del vector
d. Mostrar todos los números leídos en el vector
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int cantidad = 15, numeros[cantidad], i;
    
    for (i = 1; i <= cantidad; i++) {
    	system("cls");
    	
        printf("[%i de %i] Ingrese un numero: ", i, cantidad);
        scanf("%i", &numeros[i]);
    }
    
    char opcion;
    
    while (opcion != 'e') {
        system("cls");
        
        puts("a) Mostrar los numeros positivos del vector");
        puts("b) Mostrar los numeros negativos del vector");
        puts("c) Mostrar los numeros multiplos de 3 del vector");
        puts("d) Mostrar todos los numeros leidos en el vector");
        puts("e) Salir");
        
        system("cls");
        
        printf("Opcion: ");
        scanf("%c", &opcion);
        
        switch (opcion) {
            case 'a': {
                printf("Numeros positivos: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    if (numeros[i] > 0) {
                        printf("%i\n", numeros[i]);
                    }
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'b': {
                printf("Numeros negativos: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    if (numeros[i] < 0) {
                        printf("%i\n", numeros[i]);
                    }
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'c': {
                printf("Multiplos de 3: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    if (numeros[i] % 3 == 0) {
                        printf("%i\n", numeros[i]);
                    }
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'd': {
                printf("Numeros ingresados: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    printf("%i\n", numeros[i]);
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'e': {
                printf("Chau\n");
                break;
            }
        }
    }

    return 0;
}

