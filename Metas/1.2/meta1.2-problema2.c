// Leer una cadena de caracteres y si hay un punto antes de una palabra cambiar la primera letra a mayúscula

#include <stdio.h>
#include <string.h>

int main() {
	char cadena[100] = "";
	
	printf("Ingrese una cadena de caracteres: ");
	gets(cadena);
	
	int longitudCadena = strlen(cadena);
	
	int i = 0;
	
	for(i; i <= longitudCadena; i++) {
		if (cadena[i] == '.') {
			cadena[i + 1] = cadena[i + 1] - 'a' + 'A';
		}
	}
	
	printf("\n%s\n", cadena);
}
