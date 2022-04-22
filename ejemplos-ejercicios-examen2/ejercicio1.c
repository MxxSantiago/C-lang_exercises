#include <stdio.h>
#include <ctype.h>

void menu(char *opcion), registro(int *posicion,
                                  int numerosDeEmpleado[400],
                                  float sueldos[400][6],
                                  char nombres[400][20],
                                  char categorias[400]),
        consultaGeneral(int posicion,
                        int numerosDeEmpleado[400],
                        float sueldos[400][6],
                        char nombres[400][20],
                        char categorias[400]);

float calcularBono(const float sueldos[6], char categoria);

int main() {
    float sueldos[400][6];
    int posicion = 0, numerosDeEmpleado[400];
    char opcion = 0, categorias[400], nombres[400][20];

    while (opcion != 'C') {
        menu(&opcion);

        switch (opcion) {
            case 'A': {
                registro(&posicion, numerosDeEmpleado, sueldos, nombres,
                         categorias);
                break;
            }
            case 'B': {
                consultaGeneral(posicion, numerosDeEmpleado, sueldos, nombres,
                                categorias);
                break;
            }
            default:
                puts("La opcion ingresada no existe\n");
                break;
        }

        puts("\n");
        getc(stdin);
    }

    return 0;
}

void menu(char *opcion) {
    puts("A) Registro");
    puts("B) Consulta general");
    puts("C) Salir");

    printf("\nOpcion: ");
    scanf("%c", opcion);

    *opcion = toupper(*opcion);
}

void registro(int *posicion, int numerosDeEmpleado[400], float sueldos[400][6],
              char nombres[400][20], char categorias[400]) {
    int renglon, i, flag = 0;
    char meses[6][20] = {"enero", "febrero", "marzo", "abril", "mayo", "junio"};

    if (*posicion > 400) {
        puts("Se ha llegado al limite de registros");
    } else {
        printf("Nombre: ");
        getc(stdin);
        gets(nombres[*posicion]);

        while (categorias[*posicion] != 'A' && categorias[*posicion] != 'B' &&
               categorias[*posicion] != 'C') {
            char ingresado = 0;

            printf("Categoria: ");
            scanf("%c", &ingresado);

            categorias[*posicion] = toupper(ingresado);
        }

        for (renglon = 0; renglon < 6; renglon++) {
            printf("Sueldo del mes de %s: ", &meses[renglon]);
            scanf("%f", &sueldos[*posicion][renglon]);
        }

        while (!flag) {
            int numeroIngresado;

            printf("Numero de empleado: ");
            scanf("%i", &numeroIngresado);

            flag = 1;

            for (i = 0; i < *posicion; i++) {
                if (numeroIngresado == numerosDeEmpleado[i]) flag = 0;
            }

            if (flag) numerosDeEmpleado[*posicion] = numeroIngresado;
        }

        (*posicion)++;
    }
}

void
consultaGeneral(int posicion, int numerosDeEmpleado[400], float sueldos[400][6],
                char nombres[400][20], char categorias[400]) {
    int i;

    for (i = 0; i < posicion; i++) {
        if (i == 0) printf("\n--------------------------");

        printf("\nNombre: %s", &nombres[i]);
        printf("\nCategoria: %s", &categorias[i]);
        printf("\nSueldo semestral: %.2f",
               calcularBono(sueldos[i], categorias[i]));
        printf("\nNumero: %i", numerosDeEmpleado[i]);
        printf("\n--------------------------");
    }
}

float calcularBono(const float sueldos[6], char categoria) {
    int i;
    float bono = 0;

    for (i = 0; i < 6; i++) bono += sueldos[i];
    if (categoria == 'B') bono += (bono * (float) 0.08);
    if (categoria == 'C') bono += (bono * (float) 0.25);

    return bono;
}
