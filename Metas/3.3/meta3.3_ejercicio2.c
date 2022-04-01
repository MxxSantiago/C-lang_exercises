#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBEROFPATIENTS 500 // Change its value to 0 to test vectors limit validation
#define USERNAME_LENGTH 15

void recordPatients(int *position, int age[NUMBEROFPATIENTS],
					int dose[NUMBEROFPATIENTS],
					char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
					char address[NUMBEROFPATIENTS][50],
					char laboratory[NUMBEROFPATIENTS][20],
					char phone[NUMBEROFPATIENTS][10]),
		queryByLaboratory(int *position, int age[NUMBEROFPATIENTS],
						  int dose[NUMBEROFPATIENTS],
						  char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
						  char address[NUMBEROFPATIENTS][50],
						  char laboratory[NUMBEROFPATIENTS][20],
						  char phone[NUMBEROFPATIENTS][10]),
		modifyDose(int *position, int dose[NUMBEROFPATIENTS],
				   char name[NUMBEROFPATIENTS][USERNAME_LENGTH]),
		unsubscribePatient(int *position, int age[NUMBEROFPATIENTS],
						   int dose[NUMBEROFPATIENTS],
						   char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
						   char address[NUMBEROFPATIENTS][50],
						   char laboratory[NUMBEROFPATIENTS][20],
						   char phone[NUMBEROFPATIENTS][10]);

int main() {
	char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
			address[NUMBEROFPATIENTS][50],
			laboratory[NUMBEROFPATIENTS][20],
			phone[NUMBEROFPATIENTS][10];
	int age[NUMBEROFPATIENTS], dose[NUMBEROFPATIENTS];
	int option = 0, position = 0;

	while (option != 'e') {
		system("cls");

		puts("a) Record");
		puts("b) Query by laboratory name");
		puts("c) Modify dose to a registered patient");
		puts("d) Unsubscribe patient");
		puts("e) Close application");

		printf("\nOption: ");
		scanf("%c", &option);

		system("cls");

		switch (option) {
			case 'a':
				recordPatients(&position, age, dose, name, address, laboratory,
							   phone);
				break;
			case 'b':
				queryByLaboratory(&position, age, dose, name, address,
								  laboratory, phone);
				break;
			case 'c':
				modifyDose(&position, dose, name);
				break;
			case 'd':
				unsubscribePatient(&position, age, dose, name, address,
								   laboratory, phone);
				break;
			default:
				break;
		}

		puts("\n");
		system("pause");
	}

	return 0;
}

void recordPatients(int *position, int age[NUMBEROFPATIENTS],
					int dose[NUMBEROFPATIENTS],
					char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
					char address[NUMBEROFPATIENTS][50],
					char laboratory[NUMBEROFPATIENTS][20],
					char phone[NUMBEROFPATIENTS][10]) {
	if (*position >= NUMBEROFPATIENTS) {
		puts("The number of patients to record reached its limit");
	} else {
		printf("Name: ");
		getc(stdin);
		gets(name[*position]);

		printf("Address: ");
		gets(address[*position]);

		printf("Laboratory: ");
		gets(laboratory[*position]);

		printf("Dose: ");
		scanf("%i", &dose[*position]);

		printf("Age: ");
		scanf("%i", &age[*position]);

		printf("Phone: ");
		getc(stdin);
		gets(phone[*position]);

		(*position)++;
	}
}

void queryByLaboratory(int *position, int age[NUMBEROFPATIENTS],
					   int dose[NUMBEROFPATIENTS],
					   char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
					   char address[NUMBEROFPATIENTS][50],
					   char laboratory[NUMBEROFPATIENTS][20],
					   char phone[NUMBEROFPATIENTS][10]) {
	char laboratoryName[20];
	int matchedPatients = 0, i;

	printf("Enter the name of the laboratory you want to filter by: ");
	scanf("%s", &laboratoryName);

	system("cls");

	printf("Patients registered in the laboratory %s:\n\n", laboratoryName);

	for (i = 0; i < *position; i++) {
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

	if (matchedPatients == 0)
		printf("[There is no patient registered in that laboratory]");
}

void modifyDose(int *position, int dose[NUMBEROFPATIENTS],
				char name[NUMBEROFPATIENTS][USERNAME_LENGTH]) {
	int i, enteredPatientPosition;
	char userName[USERNAME_LENGTH];

	enteredPatientPosition = -1;

	printf("Name of the patient to modify: ");
	scanf("%s", &userName);

	for (i = 0; i < *position; i++) {
		if ((strcmp(userName, name[i])) == 0) {
			enteredPatientPosition = i;
			break;
		}
	}

	system("cls");

	if (enteredPatientPosition == -1) {
		puts("No patient was found with that name");
	} else {
		printf("Current dose quantity: ");
		scanf("%i", &dose[enteredPatientPosition]);
	}
}

void unsubscribePatient(int *position, int age[NUMBEROFPATIENTS],
						int dose[NUMBEROFPATIENTS],
						char name[NUMBEROFPATIENTS][USERNAME_LENGTH],
						char address[NUMBEROFPATIENTS][50],
						char laboratory[NUMBEROFPATIENTS][20],
						char phone[NUMBEROFPATIENTS][10]) {
	int i, enteredPatientPosition;
	char patientName[USERNAME_LENGTH];

	enteredPatientPosition = -1;

	printf("Name of the patient to be removed from the storage: ");
	scanf("%s", &patientName);

	for (i = 0; i < *position; i++) {
		if ((strcmp(patientName, name[i])) == 0) {
			enteredPatientPosition = i;
			break;
		}
	}

	system("cls");

	if (enteredPatientPosition == -1) {
		puts("No patient was found with that name");
	} else {
		for (i = enteredPatientPosition; i < *position; i++) {
			strcpy(name[i], name[i + 1]);
			strcpy(address[i], address[i + 1]);
			strcpy(phone[i], phone[i + 1]);
			strcpy(laboratory[i], laboratory[i + 1]);
			age[i] = age[i + 1];
			dose[i] = dose[i + 1];
		}

		(*position)--;

		printf("The patient %s has been unsubscribed from the storage",
			   patientName);
	}
}
