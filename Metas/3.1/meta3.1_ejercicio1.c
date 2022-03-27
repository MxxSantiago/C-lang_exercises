#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBEROFPATIENTS 100 // Change its value to 0 to test vectors limit validation

void recordPatients(), dataQuery(), queryBySocialSN(), queryByBloodType(), showMenu();
char name[100][15], occupation[100][30], bloodType[100][2], gender[100];
int socialSecurity[100], age[100], i, option, position = 0;

int main() {
    while (option != 'e') {
        showMenu();

        switch (option) {
            case 'a':
                recordPatients();
                break;
            case 'b':
                dataQuery();
                break;
            case 'c':
                queryBySocialSN();
                break;
            case 'd':
                queryByBloodType();
                break;
            default:
                break;
        }
    }

    return 0;
}

void showMenu() {
    system("cls");

    puts("a) Record");
    puts("b) Data query");
    puts("c) Query by social security number");
    puts("d) Query by blood type");
    puts("e) Close application");

    printf("\nOption: ");
    scanf("%c", &option);
    system("cls");
}

void recordPatients() {
    if (position >= NUMBEROFPATIENTS) {
        puts("The number of patients to register reached its limit\n");
        system("pause");
        system("cls");
    } else {
        int electedSocialSecurity;
        int flag = 1;

        while (flag == 1) {
            flag = 2;

            printf("Social Security number: ");
            scanf("%i", &electedSocialSecurity);

            if (position > 0) {
                for (i = 0; i < position; i++) {
                    if (electedSocialSecurity == socialSecurity[i]) {
                        puts("\nThe social security number entered is already occupied, you will have to enter another one");

                        flag = 1;

                        system("pause");
                        system("cls");
                        break;
                    }
                }
            }

            if (flag == 2) socialSecurity[position] = electedSocialSecurity;
        }

        printf("Name: ");
        getc(stdin);
        gets(name[position]);

        printf("Ocupation: ");
        gets(occupation[position]);

        printf("Blood type: ");
        gets(bloodType[position]);

        printf("Gender (M|F): ");
        gender[position] = getchar();

        printf("Age: ");
        scanf("%i", &age[position]);

        position++;
    }
}

void dataQuery() {
    if (position == 0) {
        puts("\nThere are no registered patients");
    } else {
        for (i = 0; i < position; i++) {
            printf("1. NAME: %s\n", name[i]);
            printf("2. GENDER: %c\n", gender[i]);
            printf("3. OCUPATION: %s\n", occupation[i]);
            printf("4. BLOOD TYPE: %s\n", bloodType[i]);
            printf("5. AGE: %i\n", age[i]);
            printf("------------------------------------------------\n");
        }
    }

    puts("\n");
    system("pause");
}

void queryBySocialSN() {
    char patientID;
    int patientPosition = -1;

    printf("Enter the social security number of the patient sought: ");
    scanf("%i", &patientID);

    for (i = 0; i < position; i++) {
        if (patientID == socialSecurity[i]) {
            patientPosition = i;
            break;
        }
    }

    system("cls");

    if (patientPosition < 0) {
        puts("\nNo patient found with that social security number");
    } else {
        printf("1. NAME: %s\n", name[patientPosition]);
        printf("2. GENDER: %c\n", gender[patientPosition]);
        printf("3. OCUPATION: %s\n", occupation[patientPosition]);
        printf("4. BLOOD TYPE: %s\n", bloodType[patientPosition]);
        printf("5. AGE: %i\n", age[patientPosition]);
    }

    puts("\n");
    system("pause");
}

void queryByBloodType() {
    char patientBloodType[2];
    int matchedPatients = 0;

    printf("Enter the blood type you want to filter patients for: ");
    scanf("%s", &patientBloodType);

    system("cls");

    for (i = 0; i < position; i++) {
        if ((strcmp(patientBloodType, bloodType[i])) == 0) {
            matchedPatients++;

            printf("1. NAME: %s\n", name[i]);
            printf("----------------\n");
        }
    }

    if (matchedPatients == 0) printf("\nNo patient with that blood type was found");

    puts("\n");
    system("pause");
}
