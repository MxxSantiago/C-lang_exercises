#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Alumno {
	int matricula;
	char nombre[20];
	float examenes[3]; // 60
	float calificacionTareasYPart; // 20
	float calificacionProyecto; // 20
};

void menu(char *opcion),
		registro(int *posicion, struct Alumno *alumno),
		ordenarPorNombre(int posicion, struct Alumno alumnos[40]),
		imprimirAlumnos(int posicion, struct Alumno alumnos[40]);

float
calificacionFinal(float proyecto, float tareasYPart, const float examenes[3]);

int main() {
	int posicion = 0;
	struct Alumno alumnos[40];
	char opcion = 0;

	while (opcion != 'd') {
		menu(&opcion);

		switch (opcion) {
			case 'a':
				registro(&posicion, &alumnos[posicion]);
				break;
			case 'b':
				imprimirAlumnos(posicion, alumnos);
				break;
			case 'c':
				ordenarPorNombre(posicion, alumnos);
				break;
			default:
				puts("La opcion ingresada es invalida");
		}

		getc(stdin);
		puts("\n");
		system("pause");
		system("cls");
	}

	return 0;
}

void menu(char *opcion) {
	puts("a) Registro");
	puts("b) Consulta");
	puts("c) Ordenacion");
	puts("d) Salir");

	printf("\nOpcion: ");

	*opcion = tolower(getchar());
}

void registro(int *posicion, struct Alumno *alumno) {
	if (*posicion <= 40) {
		int i;

		printf("Matricula: ");
		scanf("%i", &alumno->matricula);

		printf("Nombre: ");
		scanf("%s", alumno->nombre);

		printf("Calificacion de tareas y participacion: ");
		scanf("%f", &alumno->calificacionTareasYPart);

		printf("Calificacion de proyecto final: ");
		scanf("%f", &alumno->calificacionProyecto);

		for (i = 0; i < 3; i++) {
			printf("Calificacion del examen %i: ", i + 1);
			scanf("%f", &alumno->examenes[i]);
		}

		(*posicion)++;

		puts("\nCliente registrado");
	} else {
		puts("Se ha llegado al limite de alumnos a registrar");
	}
}

void
ordenarPorNombre(int posicion, struct Alumno alumnos[40]) {
	int i, j;
	struct Alumno auxAlumno;

	for (i = 1; i < posicion; i++) {
		for (j = 0; j < posicion - i; j++) {
			if (strcmp(alumnos[j].nombre, alumnos[j + 1].nombre) > 0) {
				auxAlumno = alumnos[j + 1];
				alumnos[j + 1] = alumnos[j];
				alumnos[j] = auxAlumno;
			}
		}
	}

	puts("Alumnos ordenados");
}

void
imprimirAlumnos(int posicion, struct Alumno alumnos[40]) {
	if (posicion > 0) {
		int i;

		for (i = 0; i < posicion; i++) {
			if (i == 0) puts("-------------------------");

			printf("Nombre: %s\n", alumnos[i].nombre);
			printf("Matricula: %i\n", alumnos[i].matricula);
			printf("Calificacion final: %.2f\n",
				   calificacionFinal(alumnos[i].calificacionProyecto,
									 alumnos[i].calificacionTareasYPart,
									 alumnos[i].examenes));
			puts("-------------------------");
		}
	} else {
		puts("No hay alumnos que mostrar");
	}
}

float
calificacionFinal(float proyecto, float tareasYPart, const float examenes[3]) {
	int i;
	float promedioExamenes = 0;

	for (i = 0; i < 3; i++) promedioExamenes += examenes[i];
	promedioExamenes /= 3;

	return (float) ((.60 * promedioExamenes) + (.20 * tareasYPart) +
					(.20 * proyecto));
}
