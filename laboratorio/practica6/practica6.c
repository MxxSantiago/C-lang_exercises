#include <stdio.h>
#include <string.h>
char nombre[5][20];
int numeroDeControl[5];
int promedio[5];
int posicion = 0;
int i = 0;
void altas(void);
void consultaGeneral(void);
void consultaPromedios(void);

int main() {
	int opcion;
	
	while(opcion != 4) {
		puts("1) Registrar alumnos");
		puts("2) Consulta general");
		puts("3) Promedios");
		puts("4) Salir");
		
		printf("Opcion: ");
		scanf("%i", &opcion);
		
		switch(opcion) {
			case 1: {
				altas();
				break;
			}
			case 2: {
				consultaGeneral();
				break;
			} 
			case 3: {
				consultaPromedios();
				break;
			}
			case 4: {
				puts("Chau");
				break;
			}
		}
	}	
	
	return 0;
}

void altas(void) {
	if (posicion >= 5) {
		puts("No se pueden ingresar mas alumnos");
	} else {
		int promedioAlumno = 0;
		
		printf("Nombre: ");
		getc(stdin);
		gets(nombre[posicion]);						
		
		printf("Numero de control: ");
		scanf("%i", &numeroDeControl[posicion]);
				
		for(i = 1; i <= 3; i++) {
			int contador;
			
			printf("Calificacion examen [%i]: ", i);
			scanf("%i", &contador);
			
			promedioAlumno += contador;
		}
		
		promedioAlumno /= 3;
		
		promedio[posicion] = promedioAlumno;
		
		posicion ++;
	}
}

void consultaGeneral(void) {
	for (i = 0; i < posicion; i++) {
		printf("Numero de control: %i\n", numeroDeControl[i]);
		printf("Nombre: %s\n", nombre[i]);
		printf("\n");
	}
}

void consultaPromedios(void) {
	int promedioGeneral = 0;
	
	printf("posicion: %i", numeroDeControl[0]);
	
	for (i = 0; i < posicion; i++) {
		printf("Numero de control: %i\n", numeroDeControl[i]);
		printf("Nombre: %s\n", nombre[i]);
		printf("Promedio: %i\n", promedio[i]);
		printf("\n");
		
		promedioGeneral += promedio[i];
	}
	
	promedioGeneral /= posicion;
	
	printf("\nPromedio general: %i\n", promedioGeneral);
}
