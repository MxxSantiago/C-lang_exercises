#include <stdio.h>
#include <stdlib.h>

// File names
#define DATABASE "database.txt"
#define TEMPORAL_DATABASE "temporal.txt"

// File actions
#define READ "r"
#define WRITE "w"

// Database record
typedef struct {
    char name[40];
    int age;
    int id;
} User;

// Database record bit size
#define USER_BLOCK_SIZE sizeof(User)

#define USERS_QUANTITY 5

void createOne(),
     createSeveral(),
     showAll(),
     deleteOne(),
     showThoseStartWith(),
     showOne(User user),
     showOlder();

void initFile(char fileAction[]);

void initTemporalFile(char fileAction[]);

FILE *filePointer = NULL;
FILE *temporalFilePointer = NULL;

int main() {
    createSeveral();

    showAll();

    deleteOne();

    showAll();

    showThoseStartWith();

    showOlder();

    system("pause");

    return 0;
}

void initFile(char fileAction[]) {
    filePointer = fopen(DATABASE, fileAction);

    if (filePointer == NULL) {
        printf("An error occurred while opening the file\n");
        exit(1);
    }
}

void initTemporalFile(char fileAction[]) {
    temporalFilePointer = fopen(TEMPORAL_DATABASE, fileAction);

    if (temporalFilePointer == NULL) {
        printf("An error occurred while opening the file\n");
        exit(1);
    }
}

void createOne() {
    User user;

    printf("Id: ");
    scanf("%d", &user.id);

    printf("Age: ");
    scanf("%d", &user.age);

    printf("Name: ");
    getc(stdin);
    gets(user.name);

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

void showOne(User user) {
    printf("\nId = %d\n", user.id);
    printf("Age = %d\n", user.age);
    printf("Name = %s\n", user.name);
}

void deleteOne() {
    User user;
    int enteredId;

    initFile(READ);
    initTemporalFile(WRITE);

    printf("Delete with id: ");
    scanf("%d", &enteredId);

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        /*
         * we want to remove the user with the entered id,
         * so if the user in the current block does not contain that id,
         * we add it to the new file
         * */
        if (user.id != enteredId) {
            fwrite(&user, USER_BLOCK_SIZE, 1, temporalFilePointer);
        }
    }

    fclose(filePointer);
    fclose(temporalFilePointer);
    remove(DATABASE);
    rename(TEMPORAL_DATABASE, DATABASE);
}

void showThoseStartWith() {
    User user;
    char enteredCharacter;

    initFile(READ);

    printf("Those that start with: ");
    scanf(" %c", &enteredCharacter);

    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        // Compare first character of the user with the entered character
        if (user.name[0] == enteredCharacter) {
            showOne(user);
        }
    }

    fclose(filePointer);
}

void showOlder() {
    User user;
    int higherAge = 0, higherAgeId;

    initFile(READ);

    // Search id of the oldest user
    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        if (user.age > higherAge) {
            higherAge = user.age;
            higherAgeId = user.id;
        }
    }

    // Set file position to the beginning
    rewind(filePointer);

    // Show the user with the help of his id
    while (fread(&user, USER_BLOCK_SIZE, 1, filePointer)) {
        if (user.id == higherAgeId) {
            printf("\nOlder user:\n");
            showOne(user);

            break;
        }
    }

    fclose(filePointer);
}
