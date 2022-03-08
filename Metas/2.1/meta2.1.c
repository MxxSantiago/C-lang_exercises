// Escriba un programa que lea un vector de 20 elementos enteros y obtenga e 
// imprima para cada uno de los elementos del vector en cuanto difieren con respecto a su valor promedio

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int cantidad = 20; // Cantidad dinamica
	int i, j, vector[cantidad];
	
	float promedio = 0;
		
	for (i = 1; i <= cantidad; i++) {
		printf("[%i] Introduzca un numero: ", i);
		scanf("%d", &vector[i]);
		
		promedio += vector[i];
		
		system("cls");
	}
	
	promedio /= cantidad; 	
	
	printf("PROMEDIO: %.2f\n", promedio);
 
	printf("Difieren en cuanto a su valor promedio:\n\n");
	for (j = 1; j <= cantidad; j++) {
		float difiere = abs(vector[j] - promedio);		

		printf("%d = %.2f\n", vector[j], difiere);
	}
}
