#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int cantidadDePacientes = 100; // Cantidad dinamica
	
	char nombre[cantidadDePacientes][15], ocupacion[cantidadDePacientes][30], tipoDeSangre[cantidadDePacientes][2], sexo[cantidadDePacientes];
	int seguroSocial[cantidadDePacientes], edad[cantidadDePacientes], i, opcion, posicion = 0; 
	
	while (opcion != 'e') {
		system("cls");
		
		puts("a) Altas");
		puts("b) Consulta de los datos ");
		puts("c) Consulta por numero de seguro social");
		puts("d) Consulta por tipo de sangre");
		puts("e) Salida");

		printf("\nQue opcion quieres: ");
		scanf("%c", &opcion);

		system("cls");

		switch (opcion) {
			case 'a': {
				if (posicion >= cantidadDePacientes) {
					puts("Los arreglos estan llenos");
				} else {
					int seguroSocialElegido;
					int validacion = 1;
					
					while (validacion != 2) {
						validacion = 1;
						
						printf("Numero de seguro social: ");
						scanf("%i", &seguroSocialElegido);
						
						for (i = 0; i < posicion; i++) {
							if (seguroSocialElegido == seguroSocial[i]) {
								printf("El numero de seguro social ingresado ya esta ocupado, tendra que ingresar otro\n\n");
								
								validacion = 3;
								
								system("pause");
								system("cls");
								break;
							}
						}
						
						if (validacion != 3) {
							validacion = 2;
							
							seguroSocial[posicion] = seguroSocialElegido;
						}
					}
					
					printf("Nombre: ");
					getc(stdin);
					gets(nombre[posicion]);
						
					printf("Ocupacion: ");
					gets(ocupacion[posicion]);
						
					printf("Tipo de sangre: ");
					gets(tipoDeSangre[posicion]);
						
					printf("Sexo: ");
					sexo[posicion] = getchar();
						
					printf("Edad: ");
					scanf("%d", &edad[posicion]);
		
					posicion++;
				}
	
				break;
			}
			
			case 'b': {
				if (posicion == 0) {
					puts("No hay pacientes registrados\n\n");
				} else {
					for (i = 0; i < posicion; i++) {
						printf("1. NOMBRE: %s\n", nombre[i]);
						printf("2. SEXO: %c\n", sexo[i]);
						printf("3. OCUPACION: %s\n", ocupacion[i]);
						printf("4. TIPO DE SANGRE: %s\n", tipoDeSangre[i]);
						printf("5. EDAD: %d\n", edad[i]);
						printf("------------------------------------------------\n");
					}
				}
				
				puts("\n");
				
				system("pause");
				
				break;
			}
	
			case 'c': {
				char numeroPaciente;
				int posicionPaciente = -1;
				
				printf("Ingrese el numero de seguro social del paciente buscado: ");
				scanf("%d", &numeroPaciente);
				
				for (i = 0; i < posicion; i++) {
					if (numeroPaciente == seguroSocial[i]) {
						posicionPaciente = i;
						break;
					}
				}
				
				system("cls");
	
				if (posicionPaciente == -1) {
					puts("No se encontro a ningun paciente con ese numero de seguro social\n");
				} else {
					printf("1. NOMBRE: %s\n", nombre[posicionPaciente]);
					printf("2. SEXO: %c\n", sexo[posicionPaciente]);
					printf("3. OCUPACION: %s\n", ocupacion[posicionPaciente]);
					printf("4. TIPO DE SANGRE: %s\n", tipoDeSangre[posicionPaciente]);
					printf("5. EDAD: %d\n", edad[posicionPaciente]);
				}
				
				puts("\n");
				system("pause");
	
				break;
			}
			
			case 'd': {
				char tipoDeSangrePaciente[2];
				int pacientesEmparejados = 0;
				
				printf("Ingrese el tipo de sangre por el que desea filtrar los pacientes: ");
				scanf("%s", &tipoDeSangrePaciente);
				
				system("cls");
				
				for (i = 0; i < posicion; i++) {
					if ((strcmp(tipoDeSangrePaciente, tipoDeSangre[i])) == 0) {
						pacientesEmparejados++;
						
						printf("1. NOMBRE: %s\n", nombre[i]);
						printf("----------------\n");
					}
				}
				
				if (pacientesEmparejados == 0) printf("No se encontro a ningun paciente con ese tipo de sangre");
				
				puts("\n");
				system("pause");
	
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
