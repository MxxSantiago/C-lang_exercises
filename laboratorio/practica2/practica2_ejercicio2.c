/******************************************************************************
Hacer un programa que lea una lista de 10 nombres de sus compañeros de grupo, después de ello muestre un
menú con las siguientes opciones:
a. Los nombres de más de 8 caracteres
b. Los nombres compuestos (de más de un nombre)
c. Mostrar todos los nombres
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int cantidad = 10, caracteresPorNombre = 20, i, j;
    char nombres[cantidad][caracteresPorNombre];
    
    for (i = 1; i <= cantidad; i++) {
    	system("cls");
    	
        printf("[%i de %i] Ingrese un nombre: ", i, cantidad);
        gets(nombres[i]);
    }
    
    char opcion;
    
    while (opcion != 'd') {
        system("cls");
        
        puts("a) Los nombres de mas de 8 caracteres");
        puts("b) Los nombres compuestos (de más de un nombre)");
        puts("c) Mostrar todos los nombres");
        puts("d) Salir");
        
        printf("Opcion: ");
        scanf("%c", &opcion);
        
        system("cls");
        
        switch (opcion) {
            case 'a': {
                printf("Nombres con mas de 8 caracteres: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    if (strlen(nombres[i]) > 8) {
                        printf("%s\n", nombres[i]);
                    }
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'b': {
                printf("Nombres compuestos: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    char nombreEvaluado[caracteresPorNombre];
                    
                    strcpy(nombreEvaluado, nombres[i]);
                    
                    int esCompuesto = 0;
                    
                    for (j = 1; j <= caracteresPorNombre; j++) {
                        if (j != 1) {
                            if (nombreEvaluado[j] == ' ' && isalpha(nombreEvaluado[j + 1])) {
                                esCompuesto = 1;
                            }
                        }
                    }
                    
                    if (esCompuesto == 1) {
                        printf("%s\n", nombres[i]);
                    }
                }
                
                puts("\n");
                system("pause");
                
                break;
            }
            case 'c': {
                printf("Nombres ingresados: \n");
                
                for (i = 1; i <= cantidad; i++) {
                    printf("%s\n", nombres[i]);
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

