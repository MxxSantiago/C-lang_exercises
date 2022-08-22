// Leer una cadena de caracteres de un máximo de 80 caracteres y mostrar la cantidad de palabras que inician con mayúscula

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	int cantidad = 0, i;
	char cadena[80];
	
	printf("Ingrese una cadena de un maximo de 80 caracteres: ");
	gets(cadena);
	
	int longitudCadena = strlen(cadena);
	
	for (i = 0; i <= longitudCadena; i++) {
		char valorActual = cadena[i], valorSiguiente = cadena[i + 1];
		
		if (i == 0 && isupper(valorActual)) cantidad++;
		
		if (valorActual == ' ') {
			if (isupper(valorSiguiente)) cantidad++;
		}
	}
	
	printf("\n%i de las palabras ingresadas empiezan con mayuscula.\n", cantidad);
}
