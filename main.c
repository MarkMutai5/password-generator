#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void randomPasswordGenerator(int size) {
    char *password = (char *) malloc(size * sizeof(char)); //dynamic allocation
    const char numbers[] = "0123456789";
    const char upperCaseStrings[] = "abcdefghijklmnopqrstuvwxyz";
    const char lowerCaseStrings[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char specialCharacters[] = "!@#$%^&*()_+}|{><";
    int i = 0;
    int randomNumber = 0;


    for (i = 0; i < size; i++) {
        randomNumber = rand() % 4; // Randomly choose character type

        switch (randomNumber) {
            case 0:
                password[i] = numbers[rand() % 10];
                break;
            case 1:
                password[i] = upperCaseStrings[rand() % 26];
                break;
            case 2:
                password[i] = lowerCaseStrings[rand() % 26];
                break;
            case 3:
                password[i] = specialCharacters[rand() % 16];
                break;
            default:
                printf("Could not generate password.");
        }
    }

    password[size] = '\0';
    printf("Generated Password: %s\n", password);
    free(password);
}

int main(void) {
    int length;

    printf("Enter password size:\n");
    scanf("%d", &length);

    if (length > 8) {
        srand(time(0));
        randomPasswordGenerator(length);
    } else {
        printf("Length should be greater than 8 characters");
    }

    return 0;
}
