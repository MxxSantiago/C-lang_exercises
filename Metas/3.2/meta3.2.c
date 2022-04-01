#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define VECTOR_LENGTH 20

void showMenu(), readVector();

int vectorSummation(const int _vector[VECTOR_LENGTH]),
        biggestNumber(const int _vector[VECTOR_LENGTH]),
        smallestNumber(const int _vector[VECTOR_LENGTH]),
        compareElements(const void *a, const void *b);

float vectorAverage(const int _vector[VECTOR_LENGTH]), vectorMedian(int _vector[VECTOR_LENGTH]);

// Test values
int i, vector[VECTOR_LENGTH] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

int main() {
    showMenu();
    return 0;
}

void showMenu() {
    int option = 0;

    while (option != 7) {
        system("cls");

        puts("1) Read vector");
        puts("2) vector summation");
        puts("3) vector average");
        puts("4) Biggest number in the vector");
        puts("5) Minor number in the vector");
        puts("6) Vector median");
        puts("7) Close application");

        printf("\nOption: ");
        scanf("%i", &option);

        system("cls");

        switch (option) {
            case 1:
                readVector();
                break;
            case 2:
                printf("Vector summation: %i", vectorSummation(vector));
                break;
            case 3:
                printf("Vector average: %.2f", vectorAverage(vector));
                break;
            case 4:
                printf("Biggest number in the vector: %i", biggestNumber(vector));
                break;
            case 5:
                printf("Smallest number in the vector: %i", smallestNumber(vector));
                break;
            case 6:
                printf("Vector median: %.2f", vectorMedian(vector));
                break;
            case 7:
                printf("Chau\n");
                break;
            default:
                printf("This option does not exist..");
                break;
        }

        puts("\n");
        system("pause");
    }
}

void readVector() {
    for (i = 0; i < VECTOR_LENGTH; i++) {
        printf("Enter the element [%i] of the vector: ", i + 1);
        scanf("%i", &vector[i]);
    }
}

int vectorSummation(const int _vector[VECTOR_LENGTH]) {
    int result = 0;

    for (i = 0; i < VECTOR_LENGTH; i++)
        result += _vector[i];

    return result;
}

float vectorAverage(const int _vector[VECTOR_LENGTH]) {
    float result = 0;

    for (i = 0; i < VECTOR_LENGTH; i++)
        result += (float) _vector[i];

    result /= VECTOR_LENGTH;

    return result;
}

int biggestNumber(const int _vector[VECTOR_LENGTH]) {
    int result = INT_MIN;

    for (i = 0; i < VECTOR_LENGTH; i++)
        if (_vector[i] > result) result = _vector[i];

    return result;
}

int smallestNumber(const int _vector[VECTOR_LENGTH]) {
    int result = INT_MAX;

    for (i = 0; i < VECTOR_LENGTH; i++)
        if (_vector[i] < result) result = _vector[i];

    return result;
}

float vectorMedian(int _vector[VECTOR_LENGTH]) {
    int elementSize = sizeof vector[0], middle = VECTOR_LENGTH / 2;
    float result;

    qsort(_vector, VECTOR_LENGTH, elementSize, compareElements);

    if (VECTOR_LENGTH % 2 == 0) {
        result = (float) ((_vector[middle - 1]) + (_vector[middle])) / 2;
    } else {
        /*
         * this code is unreachable since a default length was defined for the vector (20),
         * but validation is necessary in case we change its length
         * */

        result = (float) _vector[middle];
    }

    return result;
}

int compareElements(const void *a, const void *b) {
    int aInt = *(int *) a;
    int bInt = *(int *) b;

    return aInt - bInt;
}
