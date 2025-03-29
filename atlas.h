#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_LOCATIONS 200
#define MAX_NAME_LENGTH 50

int readLocations(char locations[][MAX_NAME_LENGTH], const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    int count = 0;
    while (fgets(locations[count], MAX_NAME_LENGTH, file) != NULL) {
        locations[count][strcspn(locations[count], "\n")] = '\0';
        count++;
    }

    fclose(file);
    return count;
}

void getLocationStartingWith(char locations[][MAX_NAME_LENGTH], int numLocations, char letter, char *location, char usedLocations[][MAX_NAME_LENGTH], int numUsedLocations) {
    while (1) {
        int index = rand() % numLocations;
        if (tolower(locations[index][0]) == tolower(letter)) {
            int used = 0;
            for (int i = 0; i < numUsedLocations; i++) {
                if (strcmp(usedLocations[i], locations[index]) == 0) {
                    used = 1;
                    break;
                }
            }
            if (!used) {
                strcpy(location, locations[index]);
                break;
            }
        }
    }
}

void playAtlas(char locations[][MAX_NAME_LENGTH], int numLocations) {
    char currentLocation[MAX_NAME_LENGTH];
    char usedLocations[MAX_LOCATIONS][MAX_NAME_LENGTH] = {0};
    char usedUserLocations[MAX_LOCATIONS][MAX_NAME_LENGTH] = {0};
    char usedComputerLocations[MAX_LOCATIONS][MAX_NAME_LENGTH] = {0};

    printf("Enter the starting location: ");
    start:
    fgets(currentLocation, MAX_NAME_LENGTH, stdin);
    if ((int) currentLocation[0]<65 || ((int) currentLocation[0]>90 && (int) currentLocation[0]<97) || (int) currentLocation[0]> 122 )
    {
        printf("Please enter a valid location: ");
        goto start;
    }
    
    
    currentLocation[strcspn(currentLocation, "\n")] = '\0';

    int round = 0;
    while (1) {
        printf("\nRound %d:\n", round + 1);
        printf("Current location: %s\n", currentLocation);

        char lastLetter = tolower(currentLocation[strlen(currentLocation) - 1]);
        char nextLocation[MAX_NAME_LENGTH];
        
        getLocationStartingWith(locations, numLocations, lastLetter, nextLocation, usedLocations, round);
        printf("Computer's response: %s\n", nextLocation);
        lastLetter = tolower(nextLocation[strlen(nextLocation) - 1]);

        int validInput = 0;
        while (!validInput) {
            printf("Your response (enter 'quit' to end the game): ");
            fgets(currentLocation, MAX_NAME_LENGTH, stdin);
            currentLocation[strcspn(currentLocation, "\n")] = '\0';

            if (strcmp(currentLocation, "quit") == 0) {
                printf("\nGame ended by user.\n");
                return;
            }

            // Convert user input to uppercase
            for (int i = 0; currentLocation[i]; i++) {
                currentLocation[i] = toupper(currentLocation[i]);
            }

            int found = 0;
            for (int i = 0; i < numLocations; i++) {
                if (strcmp(currentLocation, locations[i]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Invalid input! Please enter a valid location.\n");
            } else if (tolower(currentLocation[0]) != lastLetter) {
                printf("Incorrect input! Please enter a location starting with the letter '%c'.\n", toupper(lastLetter));
            } else {
                int used = 0;
                for (int j = 0; j < round; j++) {
                    if (strcmp(usedLocations[j], currentLocation) == 0 || strcmp(usedUserLocations[j], currentLocation) == 0) {
                        used = 1;
                        break;
                    }
                }
                if (used) {
                    printf("You entered a location already used. Please enter a different location.\n");
                } else {
                    strcpy(usedUserLocations[round], currentLocation);
                    validInput = 1;
                }
            }
        }

        strcpy(usedLocations[round], currentLocation);
        strcpy(usedComputerLocations[round], nextLocation);
        round++;
    }
}

int atlmain() {
    char locations[MAX_LOCATIONS][MAX_NAME_LENGTH];
    int numLocations = readLocations(locations, "locations.txt");
    if (numLocations == -1) {
        return 1;
    }

    srand(time(NULL));

    playAtlas(locations, numLocations);

    return 0;
}