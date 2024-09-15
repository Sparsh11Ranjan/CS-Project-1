#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for emergency contacts
struct EmergencyContact {
    char name[50];
    char number[15];
    struct EmergencyContact *next;
};

// Function to add a new emergency contact to the linked list
void addEmergencyContact(struct EmergencyContact **head_ref, char name[], char number[]) {
    struct EmergencyContact *new_contact = (struct EmergencyContact *)malloc(sizeof(struct EmergencyContact));
    strcpy(new_contact->name, name);
    strcpy(new_contact->number, number);
    new_contact->next = *head_ref;
    *head_ref = new_contact;
}

// Function to print all emergency contacts
void printEmergencyContacts(struct EmergencyContact *head) {
    printf("\nEmergency Contacts:\n");
    while (head != NULL) {
        printf("%s: %s\n", head->name, head->number);
        head = head->next;
    }
}

// Function to edit an emergency contact
void editEmergencyContact(struct EmergencyContact *head, char name[], char new_number[]) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            strcpy(head->number, new_number);
            printf("Emergency contact '%s' edited successfully.\n", name);
            return;
        }
        head = head->next;
    }
    printf("Emergency contact '%s' not found.\n", name);
}

int emain() {
    struct EmergencyContact *head = NULL;
    int choice;
    char name[50];
    char number[15];
    
    do {
        printf("\n1. Add emergency contact\n");
        printf("2. Print emergency contacts\n");
        printf("3. Edit emergency contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter number: ");
                scanf("%s", number);
                addEmergencyContact(&head, name, number);
                break;
            case 2:
                printEmergencyContacts(head);
                break;
            case 3:
                printf("Enter name of the contact to edit: ");
                scanf("%s", name);
                printf("Enter new number: ");
                scanf("%s", number);
                editEmergencyContact(head, name, number);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 4);

    // Free the memory allocated for the linked list
    struct EmergencyContact *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}