// Leer una cadena de caracteres y si hay un punto antes de una palabra cambiar la primera letra a mayúscula

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char cadena[100], i, j;
	
	printf("Ingrese una cadena de caracteres: ");
	gets(cadena);
	
	int longitudCadena = strlen(cadena);
	
	for (i = 0; i <= longitudCadena; i++) {
		if (cadena[i] == '.') {
			for (j = i; j <= longitudCadena; j++) {
				if (isalpha(cadena[j])) {
					cadena[j] = toupper(cadena[j]);
					break;
				}
			}
		}
	}
	
	printf("\nCadena modificada:\n\n%s", cadena);
}
