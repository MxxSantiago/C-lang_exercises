// Leer una cadena de caracteres de un máximo de 80 caracteres y mostrar la cantidad de palabras que inician con mayúscula

#include <stdio.h>
#include <string.h>

int main() {
	int cantidad = 0;
	char cadena[80] = "";
	
	printf("Ingrese una cadena de un maximo de 80 caracteres: ");
	gets(cadena);
	
	int longitudCadena = strlen(cadena);
	
	int i = 0;
	
	for(i; i <= longitudCadena; i++) {
		if (i == 0 && cadena[i] >= 'A' && cadena[i] <= 'Z') cantidad += 1;
		
		if (cadena[i] == ' ') {
			if (cadena[i + 1] >= 'A' && cadena[i + 1] <= 'Z') {
				cantidad += 1;
			}
		}
	}
	
	printf("\n%i de las palabras ingresadas empiezan con mayuscula.\n", cantidad);
}

