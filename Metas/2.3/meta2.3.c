#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int cantidad = 500; // Cantidad dinamica
	
	int edad[cantidad], dosis[cantidad] ,i, opcion, posicionPersonaIngresada, largoNombre = 15, posicion = 0; 
	char nombre[cantidad][largoNombre], direccion[cantidad][50], laboratorio[cantidad][20], telefono[cantidad][10];
	
	while (opcion != 'e') {
		system("cls");
		
		puts("a) Registro");
		puts("b) Consulta por nombre de laboratorio");
		puts("c) Modificacion de dosis a persona registrada");
		puts("d) Dar de baja a persona registrada");
		puts("e) Salir");

		printf("\nOpcion: ");
		scanf("%c", &opcion);

		system("cls");

		switch (opcion) {
			case 'a': {
				if (posicion > (cantidad - 1)) {
					puts("Los arreglos estan llenos");
				} else {
					printf("Nombre: ");
					getc(stdin);
					gets(nombre[posicion]);
						
					printf("Direccion: ");
					gets(direccion[posicion]);
						
					printf("Laboratorio: ");
					gets(laboratorio[posicion]);
					
					printf("Dosis: ");
					scanf("%i", &dosis[posicion]);
						
					printf("Edad: ");
					scanf("%i", &edad[posicion]);
					
					printf("Telefono: ");
					getc(stdin);
					gets(telefono[posicion]);
		
					posicion++;
				}
	
				break;
			}
			
			case 'b': {
				char nombreLaboratorio[20];
				int personasEmparejadas = 0;
				
				printf("Ingrese el nombre del laboratorio por el que desea hacer el filtrado: ");
				scanf("%s", &nombreLaboratorio);
				
				system("cls");
				
				printf("Pacientes registrados en el laboratorio %s:\n\n", nombreLaboratorio);
				
				for (i = 0; i < posicion; i++) {
					if ((strcmp(nombreLaboratorio, laboratorio[i])) == 0) {
						personasEmparejadas++;
						
						printf("1. NOMBRE: %s\n", nombre[i]);
						printf("3. DIRECCION: %s\n", direccion[i]);
						printf("5. EDAD: %i\n", edad[i]);
						printf("5. TELEFONO: %s\n", telefono[i]);
						printf("6. DOSIS: %i\n", dosis[i]);
						printf("----------------\n");
					}
				}
				
				if (personasEmparejadas == 0) printf("[No se encontro a ninguna persona registrada en ese laboratorio]");
				
				puts("\n");
				system("pause");
	
				break;
			}
			
			case 'c': {
				char nombrePersona[largoNombre];
				
				posicionPersonaIngresada = -1;
				
				printf("Nombre de la persona a modificar: ");
				scanf("%s", &nombrePersona);
				
				for (i = 0; i < posicion; i++) {
					if ((strcmp(nombrePersona, nombre[i])) == 0) {
						posicionPersonaIngresada = i;
						break;
					}
				}
				
				system("cls");
	
				if (posicionPersonaIngresada == -1) {
					puts("No se encontro a la persona con el nombre ingresado\n\n");
					system("pause");
				} else {
					printf("Cantidad de dosis actual: ");
					scanf("%i", &dosis[posicionPersonaIngresada]);
				}
	
				break;
			}
			
			case 'd': {
				char nombrePersona[largoNombre];
				
				posicionPersonaIngresada = -1;
				
				printf("Nombre de la persona a dar de baja: ");
				scanf("%s", &nombrePersona);
				
				for (i = 0; i < posicion; i++) {
					if ((strcmp(nombrePersona, nombre[i])) == 0) {
						posicionPersonaIngresada = i;
						break;
					}
				}
				
				system("cls");
	
				if (posicionPersonaIngresada == -1) {
					puts("No se encontro a la persona con el nombre ingresado\n\n");
					system("pause");
				} else {
					for (i = posicionPersonaIngresada; i < posicion; i++) {
						strcpy(nombre[i], nombre[i + 1]);
						strcpy(direccion[i], direccion[i + 1]);
						strcpy(telefono[i], telefono[i + 1]);
						strcpy(laboratorio[i], laboratorio[i + 1]);
						edad[i] = edad[i + 1];
						dosis[i] = dosis[i + 1];
					}
	
					posicion--;
					
					printf("La persona con el nombre ingresado se ha dado de baja\n\n");
					
					system("pause");
				}
				
				break;
			}
	
			case 'e': {
				puts("Chau\n");
				break;
			}
	
			default: {
				puts("La opcion ingresada no existe, intentelo nuevamente\n");
				break;
			}
		} 	
	}
	
	return 0;
}
