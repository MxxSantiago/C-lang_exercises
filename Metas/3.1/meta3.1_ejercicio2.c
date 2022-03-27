#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTITY 500 // Change its value to 0 to test vectors limit validation

void showMenu(), recordPatients(), queryByLaboratory(), modifyDose(), unsubscribePatient();
int age[500], dose[500] ,i, enteredPatientPosition, nameLength = 15, position = 0, option = 0;
char name[500][500], address[500][50], laboratory[500][20], phone[500][10];

int main() {
	while (option != 'e') {
        showMenu();

		switch (option) {
			case 'a':
                recordPatients();
				break;
			case 'b':
                queryByLaboratory();
				break;
			case 'c':
                modifyDose();
				break;
			case 'd':
                unsubscribePatient();
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
    puts("b) Query by laboratory name");
    puts("c) Modify dose to a registered patient");
    puts("d) Unsubscribe patient");
    puts("e) Close application");

    printf("\nOption: ");
    scanf("%c", &option);

    system("cls");
}

void recordPatients() {
    if (position >= CANTITY) {
        puts("The number of patients to record reached its limit\n");
        system("pause");
        system("cls");
    } else {
        printf("Name: ");
        getc(stdin);
        gets(name[position]);

        printf("Address: ");
        gets(address[position]);

        printf("Laboratory: ");
        gets(laboratory[position]);

        printf("Dose: ");
        scanf("%i", &dose[position]);

        printf("Age: ");
        scanf("%i", &age[position]);

        printf("Phone: ");
        getc(stdin);
        gets(phone[position]);

        position++;
    }
}

void queryByLaboratory() {
    char laboratoryName[20];
    int matchedPatients = 0;

    printf("Enter the name of the laboratory you want to filter by: ");
    scanf("%s", &laboratoryName);

    system("cls");

    printf("Patients registered in the laboratory %s:\n\n", laboratoryName);

    for (i = 0; i < position; i++) {
        if ((strcmp(laboratoryName, laboratory[i])) == 0) {
            matchedPatients++;

            printf("1. NAME: %s\n", name[i]);
            printf("3. ADDRESS: %s\n", address[i]);
            printf("5. AGE: %i\n", age[i]);
            printf("5. PHONE: %s\n", phone[i]);
            printf("6. DOSE: %i\n", dose[i]);
            printf("----------------\n");
        }
    }

    if (matchedPatients == 0) printf("[There is no patient registered in that laboratory]");

    puts("\n");
    system("pause");
}

void modifyDose() {
    char userName[nameLength];

    enteredPatientPosition = -1;

    printf("Name of the patient to modify: ");
    scanf("%s", &userName);

    for (i = 0; i < position; i++) {
        if ((strcmp(userName, name[i])) == 0) {
            enteredPatientPosition = i;
            break;
        }
    }

    system("cls");

    if (enteredPatientPosition == -1) {
        puts("No patient was found with that name\n");
        system("pause");
    } else {
        printf("Current dose quantity: ");
        scanf("%i", &dose[enteredPatientPosition]);
    }
}

void unsubscribePatient() {
    char patientName[nameLength];

    enteredPatientPosition = -1;

    printf("Name of the patient to be removed from the storage: ");
    scanf("%s", &patientName);

    for (i = 0; i < position; i++) {
        if ((strcmp(patientName, name[i])) == 0) {
            enteredPatientPosition = i;
            break;
        }
    }

    system("cls");

    if (enteredPatientPosition == -1) {
        puts("No patient was found with that name\n");
        system("pause");
    } else {
        for (i = enteredPatientPosition; i < position; i++) {
            strcpy(name[i], name[i + 1]);
            strcpy(address[i], address[i + 1]);
            strcpy(phone[i], phone[i + 1]);
            strcpy(laboratory[i], laboratory[i + 1]);
            age[i] = age[i + 1];
            dose[i] = dose[i + 1];
        }

        position--;

        printf("The patient %s has been unsubscribed from the storage\n\n", patientName);
        system("pause");
    }
}
