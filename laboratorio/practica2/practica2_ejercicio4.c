/******************************************************************************
Guardar 10 frases en un vector de cadenas de caracteres, las frases no deber�n de ser mayor a 15 caracteres,
el programa deber� mostrar:
a. La frase m�s larga y en qu� posici�n se encuentra
b. La frase m�s corta y en qu� posici�n se encuentra
c. Todas las frases le�das en orden inverso a como fueron le�das.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main() {
    int cantidad = 10, caracteresPorFrase = 15, i, j;
    char frases[cantidad][caracteresPorFrase];
    
    for (i = 1; i <= cantidad; i++) {
    	system("cls");
    	
        printf("[%i de %i] Ingrese una frase: ", i, cantidad);
        gets(frases[i]);
    }
    
    char opcion;
    
    while (opcion != 'd') {
        system("cls");
        
        puts("a) La frase mas larga y en que posicion se encuentra");
        puts("b) La frase mas corta y en que posicion se encuentra");
        puts("c) Todas las frases leidas en orden inverso a como fueron leidas");
        puts("d) Salir");
        
        system("cls");
        
        printf("Opcion: ");
        scanf("%c", &opcion);
        
        system("cls");
        
        switch (opcion) {
        	case 'a': {
            	int maxCaracteres = 0, posicion;
            	char fraseMasLarga[caracteresPorFrase];
                
                for (i = 1; i <= cantidad; i++) {
                	int largoFrase = strlen(frases[i]);
                	
                	if (largoFrase > maxCaracteres) {
                		strcpy(fraseMasLarga, frases[i]);	
                		maxCaracteres = largoFrase;
                		posicion = i;
					}
                }
                
            	printf("'%s' es la frase mas larga y se encuentra en la posicion [%i]: \n\n", fraseMasLarga, posicion);
                
                system("pause");
                
                break;
            }
            
            case 'b': {
             	int minCaracteres = INT_MAX, posicion;
            	char fraseMasCorta[caracteresPorFrase];
                
                for (i = 1; i <= cantidad; i++) {
                	int largoFrase = strlen(frases[i]);
                	
                	if (largoFrase < minCaracteres) {
                		strcpy(fraseMasCorta, frases[i]);	
                		minCaracteres = largoFrase;
                		posicion = i;
					}
                }
                
            	printf("'%s' es la frase mas corta y se encuentra en la posicion [%i]: \n\n", fraseMasCorta, posicion);
                
                system("pause");

                break;
            }
            
            case 'c': {
                printf("Las frases leidas en orden inverso: \n\n");
                
                for (i = cantidad; i >= 1; i--) {
                    printf("%s\n", frases[i]);
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
