#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define DESCRIPTION_SIZE 256


typedef struct {
    char description[DESCRIPTION_SIZE];
    int completed; // 0 for incomplete, 1 for complete
} Task;


typedef struct {
    Task tasks[MAX_TASKS];
    int count;
} ToDoList;

// Function types
void addTask(ToDoList *list);
void markTaskComplete(ToDoList *list);
void deleteTask(ToDoList *list);
void sortTasks(ToDoList *list);
void showTasks(ToDoList *list);

// Function to add a task to the to-do list
void addTask(ToDoList *list) {
    if (list->count >= MAX_TASKS) {
        printf("To-Do list is full. Cannot add more tasks.\n");
        return;
    }

    printf("Enter task description: ");
    fgets(list->tasks[list->count].description, DESCRIPTION_SIZE, stdin);
    
    list->tasks[list->count].description[strcspn(list->tasks[list->count].description, "\n")] = '\0';

    list->tasks[list->count].completed = 0; // Mark the task as incomplete
    list->count++;

    printf("Task added successfully.\n");
}

// Function to mark a task as complete
void markTaskComplete(ToDoList *list) {
    int index;
    showTasks(list);
    printf("Enter the task index to mark as complete: ");
    scanf("%d", &index);
    getchar(); 

    if (index < 0 || index >= list->count) {
        printf("Invalid task index.\n");
        return;
    }

    list->tasks[index].completed = 1;
    printf("Task marked as complete.\n");
}

// Function to delete a task from the to-do list
void deleteTask(ToDoList *list) {
    int index;
    showTasks(list);
    printf("Enter the task index to delete: ");
    scanf("%d", &index);
    getchar(); 

    if (index < 0 || index >= list->count) {
        printf("Invalid task index.\n");
        return;
    }

    
    for (int i = index; i < list->count - 1; i++) {
        list->tasks[i] = list->tasks[i + 1];
    }
    list->count--;

    printf("Task deleted successfully.\n");
}

// Function to sort tasks based on completion status 
void sortTasks(ToDoList *list) {
   
    for (int i = 0; i < list->count - 1; i++) {
        for (int j = 0; j < list->count - i - 1; j++) {
            // Compare based on completion status first, then description
            if ((list->tasks[j].completed > list->tasks[j + 1].completed) ||
                (list->tasks[j].completed == list->tasks[j + 1].completed && strcmp(list->tasks[j].description, list->tasks[j + 1].description) > 0)) {
                
                Task temp = list->tasks[j];
                list->tasks[j] = list->tasks[j + 1];
                list->tasks[j + 1] = temp;
            }
        }
    }

    printf("Tasks sorted.\n");
}

// Function to display all tasks in the to-do list
void showTasks(ToDoList *list) {
    if (list->count == 0) {
        printf("No tasks in the to-do list.\n");
        return;
    }

    printf("To-Do List:\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d: [%s] %s\n", i, list->tasks[i].completed ? "X" : " ", list->tasks[i].description);
    }
}

int tdlmain() {
    ToDoList toDoList = { .count = 0 }; // Initialize an empty to-do list
    int choice;

    while (1) {
        
    printf("\nOptions:\n");
    printf("1. Add task\n");
    printf("2. Mark task as complete\n");
    printf("3. Delete task\n");
    printf("4. Sort tasks\n");
    printf("5. Show tasks\n");
    printf("6. Exit\n");


        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addTask(&toDoList);
                break;
            case 2:
                markTaskComplete(&toDoList);
                break;
            case 3:
                deleteTask(&toDoList);
                break;
            case 4:
                sortTasks(&toDoList);
                break;
            case 5:
                showTasks(&toDoList);
                break;
            case 6:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
