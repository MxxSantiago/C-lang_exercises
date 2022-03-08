#include <stdio.h>
#include <stdlib.h>


int main() {
	int opcion = 0;
	
	while (opcion != 3) {
		system("cls");
		
		printf("1. Numero primo\n2. Factorial\n");
		printf("\nOpcion: ");
		scanf("%i", &opcion);
		
		switch(opcion) {
			case 1: {
				system("cls");
				
				int numero;
				int factorial = 1;
	
				printf("Ingrese un numero: ");
				scanf("%d", &numero);
	
				system("cls");
	
				for (int i = 1; i <= numero; i++) {
					factorial *= i;
				}
	
				printf("El factorial de %d es igual a %d \n", numero, factorial);
	
				system("pause");
				break;
			}
			
			case 2: {
				system("cls");

				int numero;		
				int divisores = 0;
	
				printf("Introduce un numero: ");
				scanf("%d", &numero);
	
				for (int i = 1; i <= numero; i++) {
					if(numero % i == 0) divisores++;
				}
	
				if (divisores == 2) printf("\nEs primo\n");
				else printf("\nNo es primo\n");
	
				system("pause");				
				break;
			}
		}
	}
	
	return 0;
}

