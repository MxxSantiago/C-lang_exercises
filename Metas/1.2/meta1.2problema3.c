/* Leer una cadena de caracteres , contar cuantas palabras hay, preguntar cuantas quieres mostrar y solo 
mostrar las que se indiquen, validar no aceptar mostrar un número de palabras mayor al que contiene la cadena */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int cantidad = 0;
	char cadena[100] = "";
	
	printf("Ingrese una cadena de caracteres: ");
	gets(cadena);
	
	int longitudCadena = strlen(cadena);
	
	// Contar palabras
	int i = 0;
	
	for (i; i <= longitudCadena; i++) {
		if (i == 0 && isalpha(cadena[i])) cantidad += 1;
		if (cadena[i] == ' ' && isalpha(cadena[i + 1])) cantidad += 1;
	}
	
	// Preguntar cuantas palabras mostrar
	int mostrar = 0;
	
	while (mostrar <= 0) {
		system("cls");
		
		printf("Ingrese las palabras a mostrar: ");
		scanf("%i", &mostrar);
		
		if (mostrar > cantidad) {
			mostrar = 0;
			
			printf("\nSe debe ingresar una cantidad menor o igual a la de la cadena ingresada. (%i)\n", cantidad);
			
			system("pause");
		}
	}
		
	// Mostrar palabras
	int j = 0;
	
	for (j; j <= longitudCadena; j++) {
		printf("%c", cadena[j]);
		
		if (j == 0 || cadena[j + 1] == ' ') mostrar -= 1;
		
		if (mostrar < 0) break;
	}
}
