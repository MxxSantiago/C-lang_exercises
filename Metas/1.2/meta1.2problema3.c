/* Leer una cadena de caracteres , contar cuantas palabras hay, preguntar cuantas quieres mostrar y solo 
mostrar las que se indiquen, validar no aceptar mostrar un número de palabras mayor al que contiene la cadena */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int cantidad = 0, mostrar = 0, i, j, k;
	char cadena[100];
	
	printf("Ingrese una cadena de caracteres: ");
	gets(cadena);
	
	int longitudCadena = strlen(cadena);
	
	// Contar palabras
	for (i = 0; i <= longitudCadena; i++) {
		char valorActual = cadena[i], valorSiguiente = cadena[i + 1];
		
		if (i == 0 && isalpha(valorActual)) cantidad ++;
		
		if (cadena[i] == ' ') {
			for (j = i; j <= longitudCadena; j++) {
				if (isalpha(cadena[j])) {
					cantidad++;
					
					i = j;
					
					break;
				}
			}
		}
	}
	
	// Preguntar cuantas palabras mostrar
	while (mostrar <= 0) {
		system("cls");
		
		printf("Ingrese las palabras a mostrar: ");
		scanf("%i", &mostrar);
		
		if (mostrar > cantidad) {
			mostrar = 0;
			
			printf("\nSe debe ingresar una cantidad menor o igual a la de la cadena ingresada. (%i)\n\n", cantidad);
			
			system("pause");
		}
	}
		
	// Mostrar palabras
	for (i = 0; i <= longitudCadena; i++) {
		char valorActual = cadena[i], valorSiguiente = cadena[i + 1];
		
		if (i == 0 && isalpha(valorActual)) mostrar--;
		
		if (mostrar < 0) break;
		
		printf("%c", valorActual);
		
		if (valorSiguiente == ' ') {
			for (j = i + 1; j <= longitudCadena; j++) {
				if (isalpha(cadena[j])) {
					for (k = j - 1; k <= longitudCadena; k++) {
						printf("%c", cadena[k]);
						
						if (cadena[k] == ' ') {
							i = k;
							
							mostrar--;
							
							break;
						}
					}
					
					break;
				}
			}
		}
	}
}
