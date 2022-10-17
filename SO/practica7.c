#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define DATABASE "imc.dat"
#define READ "rb"
#define WRITE "wb"
#define NAME_LENGTH 16

typedef struct {
	char name[NAME_LENGTH];
	char gender;
	int age;
	float height;
	float weight;
} User;

#define USER_BLOCK_SIZE sizeof(User)
#define USERS_QUANTITY 5
#define ATTRIBUTES_QUANTITY 7

#define TABLE_HORIZONTAL_MARGIN NAME_LENGTH
#define TABLE_HORIZONTAL_LENGTH (TABLE_HORIZONTAL_MARGIN * ATTRIBUTES_QUANTITY)
#define TABLE_HORIZONTAL_CHARACTER "-"
#define TABLE_VERTICAL_CHARACTER "|"

const char attributes[NAME_LENGTH][ATTRIBUTES_QUANTITY] = {
		"Height", "Weight", "Age", "Gender", "IMC", "Status", "Name"
};

void initFile(char fileAction[]),
		showOne(User user, int verticalViewPosition),
		createOne(),
		createSeveral(),
		showAll(),
		showWithRequestedIMCAndAge(),
		showWithRequestedAgeRange(),
		printTable(int initialPositionY);

int getIMCFromMenu(float IMC), menu();

float calculateIMC(float weight, float height);

FILE *filePointer = NULL;

int main() {
	initscr();

	if (has_colors()) start_color();

	init_pair(1, COLOR_BLACK, COLOR_RED);
	init_pair(2, COLOR_BLACK, COLOR_BLUE);

	int option = 0;

	while (option != 5) {
		option = menu();

		system("clear");

		switch (option) {
			case 1:
				createSeveral();
				break;
			case 2:
				showAll();
				break;
			case 3:
				showWithRequestedIMCAndAge();
				break;
			case 4:
				showWithRequestedAgeRange();
				break;
			case 5:
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
	printw("3) IMC and gender\n");
	printw("4) Show per age range\n");
	printw("5) Exit\n");

	printw("\nOption: ");
	scanw("%d", &option);

	return option;
}

void initFile(char fileAction[]) {
	filePointer = fopen(DATABASE, fileAction);

	if (filePointer == NULL) {
		printw("An error occurred while opening the file\n");
		exit(1);
	}
}

void createOne() {
	User user;

	printw("Gender: ");
	scanw(" %c", &user.gender);

	printw("Age: ");
	scanw("%d", &user.age);

	printw("Height: ");
	scanw("%f", &user.height);

	printw("Weight: ");
	scanw("%f", &user.weight);

	printw("Name: ");
	scanw("%s", user.name);

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
	int tableInitialPositionY = 0;
	int viewPosition = tableInitialPositionY + 3;

	initFile(READ);
	printTable(tableInitialPositionY);

	while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
		showOne(user, viewPosition);
		viewPosition++;
	}

	fclose(filePointer);
}

void printTable(int initialPositionY) {
	// Print header column for each attribute "| | | |"
	mvprintw(initialPositionY + 1, 0, TABLE_VERTICAL_CHARACTER);

	mvprintw(initialPositionY + 1, TABLE_HORIZONTAL_LENGTH,
			 TABLE_VERTICAL_CHARACTER);
	for (int i = TABLE_HORIZONTAL_MARGIN;
		 i <= TABLE_HORIZONTAL_LENGTH - 1; i += TABLE_HORIZONTAL_MARGIN) {
		mvprintw(initialPositionY + 1, i - 1, TABLE_VERTICAL_CHARACTER);
	}

	// Print top and bottom header container "------"
	for (int i = 0; i <= TABLE_HORIZONTAL_LENGTH; i++) {
		mvprintw(initialPositionY, i, TABLE_HORIZONTAL_CHARACTER);
		mvprintw(initialPositionY + 2, i, TABLE_HORIZONTAL_CHARACTER);
	}

	// Print each of the attributes on his given header cell " a b c d"
	mvprintw(initialPositionY + 1, 1, attributes[0]);

	for (int i = 1; i < ATTRIBUTES_QUANTITY; i++) {
		mvprintw(initialPositionY + 1, TABLE_HORIZONTAL_MARGIN * i,
				 attributes[i]);
	}

	// Print the bottom of the table "------"
	for (int i = 0; i <= TABLE_HORIZONTAL_LENGTH; i++) {
		mvprintw((3 + USERS_QUANTITY + initialPositionY), i,
				 TABLE_HORIZONTAL_CHARACTER);
	}

	// Print body column for each attribute on the table
	int verticalViewPosition = initialPositionY + 3;

	for (int i = 0; i < USERS_QUANTITY; i++) {
		mvprintw(verticalViewPosition, 0, TABLE_VERTICAL_CHARACTER);

		for (int j = TABLE_HORIZONTAL_MARGIN;
			 j <= TABLE_HORIZONTAL_LENGTH - 1; j += TABLE_HORIZONTAL_MARGIN) {
			mvprintw(verticalViewPosition, j - 1, TABLE_VERTICAL_CHARACTER);
		}

		mvprintw(verticalViewPosition, TABLE_HORIZONTAL_LENGTH,
				 TABLE_VERTICAL_CHARACTER);
		verticalViewPosition++;
	}
}

void showWithRequestedIMCAndAge() {
	User user;
	int requestedImc;
	char requestedGender;

	printw("Enter the requested gender: ");
	scanw(" %c", &requestedGender);

	printw("1) Under weight\n"
		   "2) Normal weight\n"
		   "3) Overweight\n"
		   "4) Grade 1 obesity\n"
		   "5) Grade 2 obesity\n"
		   "6) Grade 3 obesity\n");
	printw("\n\nRequested IMC: ");
	scanw("%d", &requestedImc);

	initFile(READ);
	clear();

	mvprintw(0, 0, "Users with the requested IMC and gender:");

	int tableInitialPositionY = 1;
	int tableBodyPositionY = tableInitialPositionY + 3;

	printTable(tableInitialPositionY);

	while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
		int userIMC = getIMCFromMenu(calculateIMC(user.weight, user.height));

		if ((user.gender == requestedGender) && (userIMC == requestedImc)) {
			showOne(user, tableBodyPositionY);
			tableBodyPositionY++;
		}
	}

	fclose(filePointer);
}

void showWithRequestedAgeRange() {
	User user;
	int minimumAge, maximumAge;

	printw("Minimum age: ");
	scanw("%d", &minimumAge);
	printw("Maximum age: ");
	scanw("%d", &maximumAge);

	initFile(READ);
	clear();

	mvprintw(0, 0, "Users with the requested age range:");

	int tableInitialPositionY = 1;
	int tableBodyPositionY = tableInitialPositionY + 3;

	printTable(tableInitialPositionY);

	while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
		if ((user.age >= minimumAge) && (user.age <= maximumAge)) {
			showOne(user, tableBodyPositionY);
			tableBodyPositionY++;
		}
	}

	fclose(filePointer);
}

int getIMCFromMenu(float IMC) {
	if (IMC >= 40) return 6;
	else if (IMC >= 35) return 5;
	else if (IMC >= 30) return 4;
	else if (IMC >= 25) return 3;
	else if (IMC >= 18.5) return 2;

	return 1;
}

void printfIMCLegend(float IMC) {
	char IMCLegends[6][30] = {
			"Under weight",
			"Normal weight",
			"Overweight",
			"Grade 1 obesity",
			"Grade 2 obesity",
			"Grade 3 obesity"
	};

	if (IMC >= 40) printw("%s", IMCLegends[5]);
	else if (IMC >= 35) printw("%s", IMCLegends[4]);
	else if (IMC >= 30) printw("%s", IMCLegends[3]);
	else if (IMC >= 25) printw("%s", IMCLegends[2]);
	else if (IMC >= 18.5) printw("%s", IMCLegends[1]);
	else if (IMC < 18.5) printw("%s", IMCLegends[0]);
}

float calculateIMC(float weight, float height) {
	return weight / (height * height);
}

void showOne(User user, int verticalViewPosition) {
	float userIMC = calculateIMC(user.weight, user.height);
	int IMCStatus = getIMCFromMenu(userIMC);

	if (IMCStatus == 6) attron(COLOR_PAIR(1));
	else if (IMCStatus == 1) attron(COLOR_PAIR(2));

	move(verticalViewPosition, 1);
	printw("%.2f", user.height);

	move(verticalViewPosition, TABLE_HORIZONTAL_MARGIN);
	printw("%.2f", user.weight);

	move(verticalViewPosition, TABLE_HORIZONTAL_MARGIN * 2);
	printw("%d", user.age);

	move(verticalViewPosition, TABLE_HORIZONTAL_MARGIN * 3);
	printw("%c", user.gender);

	move(verticalViewPosition, TABLE_HORIZONTAL_MARGIN * 4);
	printw("%.2f", userIMC);

	move(verticalViewPosition, TABLE_HORIZONTAL_MARGIN * 5);
	printfIMCLegend(userIMC);

	move(verticalViewPosition, TABLE_HORIZONTAL_MARGIN * 6);
	printw("%s", user.name);

	attroff(COLOR_PAIR(1));
	attroff(COLOR_PAIR(2));
}
