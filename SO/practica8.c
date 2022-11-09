#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <curses.h>

#define MAX_LENGTH 20

struct {
	char *name[4];
	char *firstSurname[4];
	char *lastSurname[4];
	char *tuition[4];
	char *career[4];
	int position;
} Students;

void record();

void show();

void showPerFirstSurname();

void showPerCareerAndName();

void elimination();

int menu();

int main() {
	initscr();

	int option = 0;

	while (option != 6) {
		option = menu();

		system("clear");

		switch (option) {
			case 1:
				record();
				break;
			case 2:
				show();
				break;
			case 3:
				showPerFirstSurname();
				break;
			case 4:
				showPerCareerAndName();
				break;
			case 5:
				elimination();
				break;
			case 6:
				puts("Bye");
				break;
			default:
				puts("The given option does not exist...");
		}

		refresh();
		getch();
		clear();
	}

	endwin();

	return 0;
}

int menu() {
	int option;

	printw("1) Record\n");
	printw("2) Show\n");
	printw("3) Show per first surname\n");
	printw("4) Show per career and name\n");
	printw("5) Elimination\n");
	printw("6) Exit\n");

	printw("\nOption: ");
	scanw("%d", &option);

	return option;
}

void record() {
	char enteredName[MAX_LENGTH],
			enteredFirstSurname[MAX_LENGTH],
			enteredLastSurname[MAX_LENGTH],
			enteredTuition[MAX_LENGTH],
			enteredCareer[MAX_LENGTH];
	char option = 'y';
	int length;

	while (option == 'y') {
		if (Students.position < 4) {
			printw("Name: "), getstr(enteredName);
			length = strlen(enteredName);
			Students.name[Students.position] = (char *) malloc(length + 1);

			printw("First surname: "), getstr(enteredFirstSurname);
			length = strlen(enteredFirstSurname);
			Students.firstSurname[Students.position] = (char *) malloc(
					length + 1);

			printw("Last surname: "), getstr(enteredLastSurname);
			length = strlen(enteredLastSurname);
			Students.lastSurname[Students.position] = (char *) malloc(
					length + 1);

			printw("Tuition: "), getstr(enteredTuition);
			length = strlen(enteredTuition);
			Students.tuition[Students.position] = (char *) malloc(length + 1);

			printw("Career: "), getstr(enteredCareer);
			length = strlen(enteredCareer);
			Students.career[Students.position] = (char *) malloc(length + 1);

			if (Students.name[Students.position] == NULL ||
				Students.firstSurname[Students.position] == NULL ||
				Students.lastSurname[Students.position] == NULL ||
				Students.tuition[Students.position] == NULL ||
				Students.career[Students.position] == NULL) {
				printw("Insufficient memory");
			} else {
				strcpy(Students.name[Students.position], enteredName);
				strcpy(Students.firstSurname[Students.position],
					   enteredFirstSurname);
				strcpy(Students.lastSurname[Students.position],
					   enteredLastSurname);
				strcpy(Students.tuition[Students.position], enteredTuition);
				strcpy(Students.career[Students.position], enteredCareer);
			}

			printw("Enter another one? y/n: ");
			scanw(" %c", &option);

			clear();

			Students.position++;
		} else {
			printw("Record limit reached...");
			option = 'n';
		}
	}
}

void show() {
	int i, verticalPosition = 2, columnWidth = MAX_LENGTH + 3;

	if (!Students.position) {
		printw("There are no users to show...");
	} else {
		for (i = 0; i < Students.position; i++) {
			move(verticalPosition, 0), printw("%s", Students.name[i]);
			move(verticalPosition, columnWidth), printw("%s",
														Students.firstSurname[i]);
			move(verticalPosition, columnWidth * 2), printw("%s",
															Students.lastSurname[i]);
			move(verticalPosition, columnWidth * 3), printw("%s",
															Students.tuition[i]);
			move(verticalPosition, columnWidth * 4), printw("%s",
															Students.career[i]);

			verticalPosition++;
		}
	}
}

void showPerFirstSurname() {
	char enteredSurname[MAX_LENGTH];
	int i, exists = -1;

	printw("Enter the student first surname: "), getstr(enteredSurname);

	for (i = 0; i < Students.position; i++) {
		if (!strcasecmp(enteredSurname, Students.firstSurname[i])) {
			exists = i;

			printw("\n%s", Students.name[i]);
			printw("\n%s", Students.firstSurname[i]);
			printw("\n%s", Students.lastSurname[i]);
			printw("\n%s", Students.tuition[i]);
			printw("\n%s", Students.career[i]);

			break;
		}
	}

	if (exists == -1) {
		printw("\nNo user was found with the specified first surname...");
	}
}

void showPerCareerAndName() {
	char enteredCareer[MAX_LENGTH], enteredName[MAX_LENGTH];
	int i, exists = -1;

	printw("Enter the student career: "), getstr(enteredCareer);
	printw("Enter the student name: "), getstr(enteredName);

	for (i = 0; i < Students.position; i++) {
		if (!strcasecmp(enteredCareer, Students.career[i])) {
			if (!strcasecmp(enteredName, Students.name[i])) {
				exists = i;

				printw("\n%s", Students.name[i]);
				printw("\n%s", Students.firstSurname[i]);
				printw("\n%s", Students.lastSurname[i]);
				printw("\n%s", Students.tuition[i]);
				printw("\n%s", Students.career[i]);

				break;
			}
		}
	}

	if (exists == -1) {
		printw("No user was found with the specified first surname...");
	}
}

void elimination() {
	int i, position, b = 0, s, length;
	char enteredSurname[MAX_LENGTH], option;

	printw("Enter student first surname: "), getstr(enteredSurname);

	for (i = 0; i < Students.position; i++) {
		if (!strcasecmp(enteredSurname, Students.firstSurname[i])) {
			printw("\n%s", Students.name[i]);
			printw("\n%s", Students.firstSurname[i]);
			printw("\n%s", Students.lastSurname[i]);
			printw("\n%s", Students.tuition[i]);
			printw("\n%s", Students.career[i]);

			printw("\nThis is the correct student to eliminate? y/n: ");
			scanw("%c", &option);

			if (option == 'y') {
				position = i;

				b = 1;

				free(Students.name[i]);
				free(Students.firstSurname[i]);
				free(Students.lastSurname[i]);
				free(Students.tuition[i]);
				free(Students.career[i]);
			}
		}
	}

	if (b == 1) {
		for (s = position; s < Students.position - 1; s++) {
			length = strlen(Students.name[s + 1]);
			Students.name[s] = (char *) malloc(length + 1);
			strcpy(Students.name[s], Students.name[s + 1]);

			length = strlen(Students.firstSurname[s + 1]);
			Students.firstSurname[s] = (char *) malloc(length + 1);
			strcpy(Students.firstSurname[s], Students.firstSurname[s + 1]);

			length = strlen(Students.lastSurname[s + 1]);
			Students.lastSurname[s] = (char *) malloc(length + 1);
			strcpy(Students.lastSurname[s], Students.lastSurname[s + 1]);

			length = strlen(Students.tuition[s + 1]);
			Students.tuition[s] = (char *) malloc(length + 1);
			strcpy(Students.tuition[s], Students.tuition[s + 1]);

			length = strlen(Students.career[s + 1]);
			Students.career[s] = (char *) malloc(length + 1);
			strcpy(Students.career[s], Students.career[s + 1]);
		}

		Students.position--;
	} else {
		printw("\nNo user was found with the specified career and first surname...");
	}
}
