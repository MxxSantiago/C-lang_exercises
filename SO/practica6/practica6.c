#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DATABASE "datos.txt"

#define READ "r"
#define WRITE "w"

typedef struct {
    char name[40];
    char address[40];
    char phoneNumber[10];
    float monthlySalary;
} User;

#define USER_BLOCK_SIZE sizeof(User)

#define USERS_QUANTITY 3

void initFile(char fileAction[]),
        showOne(User user),
        createOne(),
        createSeveral(),
        showAll(),
        showThoseThatStartWith(),
        showThoseWithHigherSalary(),
        showQuantityOfRecords(),
        showHigherThanRequestedSalary();

int menu();

FILE *filePointer = NULL;

int main() {
    int option = 0;

    while (option != 7) {
        option = menu();

        system("cls");

        switch (option) {
            case 1:
                createSeveral();
                break;
            case 2:
                showAll();
                break;
            case 3:
                showThoseThatStartWith();
                break;
            case 4:
                showQuantityOfRecords();
                break;
            case 5:
                showHigherThanRequestedSalary();
                break;
            case 6:
                showThoseWithHigherSalary();
                break;
            case 7:
                puts("Bye");
                break;
            default:
                puts("The given option does not exist...");
        }

        printf("\n");
        system("pause");
        system("cls");
    }

    return 0;
}

int menu() {
    int option;

    puts("1) Record");
    puts("2) Show");
    puts("3) Show those that his name start with the given character");
    puts("4) Show quantity of records");
    puts("5) Show those with higher salary than the requested one");
    puts("6) Show those with the highest salary");
    puts("7) Exit");

    printf("\nOption: ");
    scanf("%d", &option);

    return option;
}

void initFile(char fileAction[]) {
    filePointer = fopen(DATABASE, fileAction);

    if (filePointer == NULL) {
        printf("An error occurred while opening the file\n");
        exit(1);
    }
}

void createOne() {
    User user;

    printf("Monthly salary: ");
    scanf("%f", &user.monthlySalary);

    printf("Name: ");
    getc(stdin);
    gets(user.name);

    printf("Address: ");
    gets(user.address);

    printf("Phone number: ");
    gets(user.phoneNumber);

    fwrite(&user, USER_BLOCK_SIZE, 1, filePointer);
}

void createSeveral() {
    initFile(WRITE);

    for (int i = 0; i < USERS_QUANTITY; i++) {
        createOne();
    }

    fclose(filePointer);
}

void showAll() {
    User user;

    initFile(READ);

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        showOne(user);
    }

    fclose(filePointer);
}

void showQuantityOfRecords() {
    User user;
    int quantity = 0;

    initFile(READ);

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        quantity++;
    }

    printf("Quantity of records: %d\n", quantity);

    fclose(filePointer);
}

void showHigherThanRequestedSalary() {
    User user;
    float requestedSalary = 0;

    printf("Enter the requested salary: ");
    scanf("%f", &requestedSalary);

    initFile(READ);

    printf("\n\nUsers with highest salary than the requested one:\n\n");

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        if (user.monthlySalary > requestedSalary) {
            showOne(user);
        }
    }

    fclose(filePointer);
}

void showOne(User user) {
    printf("Monthly salary: %.2f\n", user.monthlySalary);
    printf("Name: %s\n", user.name);
    printf("Address: %s\n", user.address);
    printf("Phone number: %s\n\n", user.phoneNumber);
}

void showThoseThatStartWith() {
    User user;
    char enteredCharacter;

    initFile(READ);

    printf("Those that start with: ");
    scanf(" %c", &enteredCharacter);

    printf("\n");

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        if (tolower(user.name[0]) == tolower(enteredCharacter)) {
            showOne(user);
        }
    }

    fclose(filePointer);
}

void showThoseWithHigherSalary() {
    User user;
    float higherSalary = 0;

    initFile(READ);

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        if (user.monthlySalary > higherSalary) {
            higherSalary = user.monthlySalary;
        }
    }

    rewind(filePointer);

    printf("Users with highest salary:\n\n");

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        if (user.monthlySalary == higherSalary) {
            showOne(user);
        }
    }

    fclose(filePointer);
}

