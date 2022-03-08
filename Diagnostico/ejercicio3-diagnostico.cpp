#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {	
	char opcion;
	
	float promedio = 0;
	
	int multiplos = 0, cantidad = 0;
	
	int mayor = INT_MIN; 
	int menor = INT_MAX;

	while (opcion != '#') {
			int numero = 0;
			
			printf("ingrese un numero: ");
			scanf("%i", &numero);
			
			cantidad += 1;
			
			if(numero > mayor) mayor = numero;
			if(numero < menor) menor = numero;
			
			promedio += numero;
			
			if(numero%10 == 0) multiplos++;
			
			system("cls");
			
			printf("Ingrese cualquier caracter para continuar, para salir del programa ingrese '#': ");
			scanf(" %c", &opcion);
			
			system("cls");
	}
	
	promedio /= cantidad;
	
	printf("Mayor: %i\nMenor: %i\nPromedio: %.2f\nMultiplos de 10: %i\n", mayor, menor, promedio, multiplos); 
	
	system("pause");
}
