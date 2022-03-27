#include <string.h>
#include <stdio.h>
#include <ctype.h>

void registro(), cgeneral(), cnumeroE(), cnombreE(), cCategoria(), bajas(), modificaciones(), buscar();
int ne[50], horas[50], cont = 0, pos, x;
char nom[50][25], cat[50];

int main() {
    int op1 = 0, op2 = 0;

    while (op1 != 5) {
        printf("\n");
        puts("MENU PPAL");
        puts("1. REGISTRO");
        puts("2. CONSULTAS");
        puts("3. BAJAS");
        puts("4. MODIFICACIONES");
        puts("5. SALIR");

        printf("\nSelecciona la opcion: ");
        scanf("%i", &op1);

        switch (op1) {
            case 1: {
                registro();
                break;
            }
            case 2: {
                printf("\n");
                puts("MENU CONSULTAS");
                puts("1. GENERAL");
                puts("2. NUMERO");
                puts("3. NOMBRE");
                puts("4. CATEGORIA");
                puts("5. REGRESO AL MENU PPAL");

                printf("Selecciona la opcion ");
                scanf("%i", &op2);

                switch (op2) {
                    case 1:
                        cgeneral();
                        break;
                    case 2:
                        cnumeroE();
                        break;
                    case 3:
                        cnombreE();
                        break;
                    case 4:
                        cCategoria();
                        break;
                    case 5:
                        puts("Regreso al ppal");
                        break;
                    default:
                        puts("Error");
                        break;
                }

                break;
            }
            case 3:
                bajas();
                break;
            case 4:
                modificaciones();
                break;
            case 5:
                puts("Adios....");
                break;
            default:
                puts("Error");
                break;
        }
    }
}

void registro() {
    if (cont >= 50) {
        puts("Se ha alcanzado el limite de registros");
    } else {
        int band;

        printf("\nNumero de empleado: ");
        scanf("%i", &ne[cont]);

        printf("Nombre: ");
        getc(stdin);
        gets(nom[cont]);

        while (cat[cont] != 'A' && cat[cont] != 'B' && cat[cont] != 'C') {
            printf("Categoria [A,B,C]: ");
            cat[cont] = toupper(getchar());

            if (cat[cont] != 'A' && cat[cont] != 'B' && cat[cont] != 'C') {
                getc(stdin);
                puts("\nLa categoria ingresada no existe, categorias permitidas: [A,B,C]\n");
            }
        }

        do {
            band = 0;

            printf("Da el numero de horas: ");
            scanf("%d", &horas[cont]);

            if (cat[cont] == 'A' && horas[cont] > 20) {
                puts("Maximo 20 horas");
                band = 1;
            }

            if (cat[cont] == 'B' && horas[cont] > 25) {
                puts("Maximo 25 horas");
                band = 1;
            }

            if (cat[cont] == 'C' && horas[cont] > 30) {
                puts("Maximo 30 horas");
                band = 1;
            }

        } while (band);

        cont++;
    }
}

void buscar() {
    int neb;
    pos = -1;

    printf("Cual es el numero que buscas: ");
    scanf("%d", &neb);

    for (x = 0; x < cont; x++) {
        if (neb == ne[x]) {
            pos = x;
            break;
        }
    }

    if (pos == -1) puts("No se encontro el numero de empleado que buscas");
}

void cgeneral() {
    for (x = 0; x < cont; x++) {
        printf("\n");
        printf("Numero de docente: %d \n", ne[x]);
        printf("Nombre del docente: %s\n", nom[x]);
        printf("Categoria del docente: %c \n", cat[x]);
        printf("Cantidad de horas: %d \n", horas[x]);
    }
}

void cnumeroE() {
    buscar();

    if (pos != -1) {
        printf("\n");
        printf("Numero de docente: %d \n", ne[pos]);
        printf("Nombre del docente: %s\n", nom[pos]);
        printf("Categoria del docente: %c \n", cat[pos]);
        printf("Cantidad de horas: %d \n", horas[pos]);
    }
}

void cnombreE() {
    char Nomb[25];

    printf("Da el nombre del empleado: ");
    getc(stdin);
    gets(Nomb);

    for (x = 0; x < cont; x++) {
        if (strcmp(Nomb, nom[x]) == 0) {
            printf("\n");
            printf("Numero de docente: %d \n", ne[x]);
            printf("Nombre del docente: %s\n", nom[x]);
            printf("Categoria del docente: %c \n", cat[x]);
            printf("Cantidad de horas: %d \n", horas[x]);
        }
    }
}

void cCategoria() {
    char catb;

    printf("Da la categoria a consultar: ");
    getc(stdin);
    gets(catb);

    for (x = 0; x < cont; x++) {
        if (catb == cat[x]) {
            printf("\n");
            printf("Numero de docente: %d \n", ne[x]);
            printf("Nombre del docente: %s\n", nom[x]);
            printf("Categoria del docente: %c \n", cat[x]);
            printf("Cantidad de horas: %d \n", horas[x]);
        }
    }
}

void bajas() {
    buscar();

    if (pos != -1) {
        for (x = pos; x < cont; x++) {
            ne[x] = ne[x + 1];
            horas[x] = horas[x + 1];
            cat[x] = cat[x + 1];
            strcpy(nom[x], nom[x + 1]);

            cont--;
        }
    }
}

void modificaciones() {
    int band, opc2 = 0;

    buscar();

    if (pos != -1) {
        puts("DATOS A MODIFICAR ");
        puts("1. NOMBRE ");
        puts("2. CATEGORIA");
        puts("3. NINGUNA");

        printf("\nQue quieres modificar: ");
        scanf("%i", &opc2);

        switch (opc2) {
            case 1:
                printf("Da el nuevo nombre: ");
                getc(stdin);
                gets(nom[pos]);
                break;
            case 2: {
                printf("Da la nueva categoria: ");
                getc(stdin);
                cat[pos] = toupper(getchar());

                do {
                    band = 0;

                    printf("Da el numero de horas: ");
                    scanf("%d", &horas[pos]);

                    if (cat[pos] == 'A' && horas[pos] > 20) {
                        puts("Maximo 20 horas");
                        band = 1;
                    }

                    if (cat[pos] == 'B' && horas[pos] > 25) {
                        puts("Maximo 25 horas");
                        band = 1;
                    }

                    if (cat[pos] == 'C' && horas[pos] > 30) {
                        puts("Maximo 30 horas");
                        band = 1;
                    }

                } while (band);

                break;
            }
            default: {
                break;
            }
        }
    }
}
