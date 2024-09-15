#include <stdio.h>
#include <string.h>

// Define the class schedule 
char classes[5][6][50]; 

// Function to display the timetable
void displayTimetable(int day) {
    for (int i = 0; i < 5; ++i) {
        printf("%d:00 - %d:00: %s\n", 8 + i, 9 + i, classes[day-1][i]);
    }
    printf("14:00 - 17:00: %s\n", classes[day-1][5]);
}

int ttmain() {
    int day, i;
    char temp[50]; // Temporary string to hold class names
    for(day = 1; day <= 5; day++){
        if(day == 1)
            printf("Monday:\n");
        else if(day == 2)
            printf("Tuesday:\n");
        else if(day == 3)
            printf("Wednesday:\n");
        else if(day == 4)
            printf("Thursday:\n"); 
        else if(day == 5)
            printf("Friday:\n");

        for(i = 0; i < 5; i++){
            printf("\n%d:00 - %d:00: ", 8 + i, 9 + i);
            scanf("%49s", temp); // Use %49s to prevent buffer overflow
            strcpy(classes[day-1][i], temp);
        }
        printf("\n14:00 - 17:00: ");
        scanf("%49s", temp); 
        strcpy(classes[day-1][5], temp);
    }

    while(1){
        printf("\nDays:\n");
        printf("1. Monday\n");
        printf("2. Tuesday\n");
        printf("3. Wednesday\n");
        printf("4. Thursday\n"); 
        printf("5. Friday\n");
        printf("6. Exit\n"); 

        printf("Enter the day: ");
        scanf("%d", &day);

        switch(day){
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                displayTimetable(day);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid Choice. Please try again.\n");
        }
    }
}