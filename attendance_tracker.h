#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_CLASSES 50
#define MAX_NAME_LENGTH 50

struct Subject {
    char name[MAX_NAME_LENGTH];
    int classes[MAX_CLASSES]; // 0 for absent, 1 for present
    int totalClasses;
};

// Function prototypes
void markAttendance(struct Subject subjects[], int numSubjects);
void showNetAttendance(struct Subject subjects[], int numSubjects);
double calculateAttendancePercentage(int attendedClasses, int totalClasses);
void displaySubjectPercentageAttendance(double attendancePercentage, char *subjectName);
char* generateFileName(char *subjectName);
void writeAttendanceToFile(struct Subject subjects[], int numSubjects);
void readAttendanceFromFile(struct Subject subjects[], int numSubjects);

void attendanceTracker() {
    struct Subject subjects[MAX_SUBJECTS];
    int numSubjects;

    printf("Enter the number of subjects: ");
    scanf("%d", &numSubjects);

    // Input subject names
    for (int i = 0; i < numSubjects; i++) {
        printf("Enter name of subject %d: ", i + 1);
        scanf("%s", subjects[i].name);
        subjects[i].totalClasses = 0;
    }

    // Read attendance data from file if available
    readAttendanceFromFile(subjects, numSubjects);

    // Menu
    int choice;
    do {
        printf("\nAttendance Tracker Menu:\n");
        printf("1. Mark Attendance\n");
        printf("2. Show Net Attendance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                markAttendance(subjects, numSubjects);
                // Write attendance data to file after marking attendance
                writeAttendanceToFile(subjects, numSubjects);
                break;
            case 2:
                showNetAttendance(subjects, numSubjects);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);
}

// Function to mark attendance for each subject
void markAttendance(struct Subject subjects[], int numSubjects) {
    for (int i = 0; i < numSubjects; i++) {
        printf("Mark attendance for %s (0 for absent, 1 for present):\n", subjects[i].name);
        printf("Class %d: ", i + 1);
        int attendance;
        while (1) {
            scanf("%d", &attendance);
            if (attendance == 0 || attendance == 1)
                break;
            printf("Invalid input. Please enter 0 for absent or 1 for present.\n");
            printf("Class %d: ", i + 1); // Re-prompt for the same class
        }
        subjects[i].classes[subjects[i].totalClasses] = attendance;
        subjects[i].totalClasses++;
        printf("Attendance for %s marked successfully.\n", subjects[i].name);
    }
}

// Function to calculate and display net attendance for each subject
void showNetAttendance(struct Subject subjects[], int numSubjects) {
    int anyClassesMarked = 0; // Flag to check if any classes have been marked
    for (int i = 0; i < numSubjects; i++) {
        int presentCount = 0;
        for (int j = 0; j < subjects[i].totalClasses; j++) {
            if (subjects[i].classes[j] == 1) {
                presentCount++;
                anyClassesMarked = 1; // Set flag if at least one class has been marked
            }
        }
        if (anyClassesMarked) {
            printf("Net attendance for %s: %d/%d\n", subjects[i].name, presentCount, subjects[i].totalClasses);
            double attendancePercentage = calculateAttendancePercentage(presentCount, subjects[i].totalClasses);
            displaySubjectPercentageAttendance(attendancePercentage, subjects[i].name);
        } else {
            printf("No classes have occurred for %s\n", subjects[i].name);
        }
    }
}

// Function to calculate attendance percentage
double calculateAttendancePercentage(int attendedClasses, int totalClasses) {
    return (double) attendedClasses / totalClasses * 100;
}

// Function to display percentage attendance for a subject
void displaySubjectPercentageAttendance(double attendancePercentage, char *subjectName) {
    printf("Percentage Attendance for %s: %.2f%%\n", subjectName, attendancePercentage);
}

// Function to generate filename for each subject
char* generateFileName(char *subjectName) {
    char *filename = malloc(strlen(subjectName) + 5); // ".txt" plus null terminator
    strcpy(filename, subjectName);
    strcat(filename, ".txt");
    return filename;
}

// Function to write attendance data to file
void writeAttendanceToFile(struct Subject subjects[], int numSubjects) {
    for (int i = 0; i < numSubjects; i++) {
        char *filename = generateFileName(subjects[i].name);
        FILE *file = fopen(filename, "w");
        if (file != NULL) {
            for (int j = 0; j < subjects[i].totalClasses; j++) {
                fprintf(file, "%d\n", subjects[i].classes[j]);
            }
            fclose(file);
        } else {
            printf("Error: Could not write attendance data to file %s\n", filename);
        }
        free(filename);
    }
}

// Function to read attendance data from file
void readAttendanceFromFile(struct Subject subjects[], int numSubjects) {
    for (int i = 0; i < numSubjects; i++) {
        char *filename = generateFileName(subjects[i].name);
        FILE *file = fopen(filename, "r");
        if (file != NULL) {
            int attendance;
            int count = 0;
            while (fscanf(file, "%d", &attendance) == 1 && count < MAX_CLASSES) {
                subjects[i].classes[count++] = attendance;
            }
            subjects[i].totalClasses = count;
            fclose(file);
        } else {
            printf("No previous attendance data found for %s\n", subjects[i].name);
        }
        free(filename);
    }
}

int attmain() {
    attendanceTracker();
    return 0;
}
