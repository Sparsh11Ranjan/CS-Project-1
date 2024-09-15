#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void handleFlu(FILE *file, FILE *calendar);
void handleCold(FILE *file, FILE *calendar);
void handleHeadache(FILE *file, FILE *calendar);
void handleStomachache(FILE *file, FILE *calendar);
void handleOther(FILE *file, FILE *calendar, const char *disease);

int mmain() {
    char disease[50];

    // Open a file in append mode for disease instructions
    FILE *file = fopen("disease_instructions.txt", "a");
    if (file == NULL) {
        printf("Error opening file for disease instructions.\n");
        return 1;
    }

    // Open a file in append mode for the medication calendar
    FILE *calendar = fopen("medication_calendar.txt", "a");
    if (calendar == NULL) {
        printf("Error opening file for medication calendar.\n");
        fclose(file);
        return 1;
    }

    // Prompting user to enter the name of the disease
    printf("Enter the name of the disease: ");
    scanf("%s", disease);

    // Converting input to lowercase for case-insensitive comparison
    for(int i = 0; disease[i]; i++){
        disease[i] = tolower(disease[i]);
    }

    // Checking for common diseases and writing instructions to the file
    if (strcmp(disease, "flu") == 0) {
        handleFlu(file, calendar);
    } else if (strcmp(disease, "cold") == 0) {
        handleCold(file, calendar);
    } else if (strcmp(disease, "headache") == 0) {
        handleHeadache(file, calendar);
    } else if (strcmp(disease, "stomachache") == 0) {
        handleStomachache(file, calendar);
    } else {
        handleOther(file, calendar, disease);
    }

    // Close the files
    fclose(file);
    fclose(calendar);

    return 0;
}

// Function to handle instructions for flu
void handleFlu(FILE *file, FILE *calendar) {
    fprintf(file, "For flu:\n");
    fprintf(file, "- Get plenty of rest.\n");
    fprintf(file, "- Drink fluids, such as water, broth, or sports drinks.\n");
    fprintf(file, "- Avoid close contact with others, especially in crowded places.\n");
    fprintf(file, "- Cover your mouth and nose with a tissue when coughing or sneezing, then throw the tissue away and wash your hands.\n");
    fprintf(file, "- Take over-the-counter flu medications, such as acetaminophen or ibuprofen, to relieve symptoms.\n");
    fprintf(file, "\n");

    // Add medication schedule to the calendar
    fprintf(calendar, "Medication Schedule for Flu:\n");
    fprintf(calendar, "Day 1: Take 2 tablets of acetaminophen in the morning and 2 tablets in the evening.\n");
    fprintf(calendar, "Day 2-5: Take 2 tablets of ibuprofen every 6 hours as needed for fever and body aches.\n");
    fprintf(calendar, "\n");
}

// Function to handle instructions for a cold
void handleCold(FILE *file, FILE *calendar) {
    fprintf(file, "For a cold:\n");
    fprintf(file, "- Drink plenty of fluids to stay hydrated.\n");
    fprintf(file, "- Get plenty of rest to help your body recover.\n");
    fprintf(file, "- Use over-the-counter cold medications, such as decongestants or cough syrups, to relieve symptoms.\n");
    fprintf(file, "- Consider using saline nasal sprays or drops to help relieve nasal congestion.\n");
    fprintf(file, "\n");

    // Add medication schedule to the calendar
    fprintf(calendar, "Medication Schedule for Cold:\n");
    fprintf(calendar, "Day 1-3: Take 1 tablespoon of cough syrup every 4 hours as needed for cough.\n");
    fprintf(calendar, "Day 1-5: Take 1 tablet of decongestant every 6 hours as needed for nasal congestion.\n");
    fprintf(calendar, "\n");
}

// Function to handle instructions for a headache
void handleHeadache(FILE *file, FILE *calendar) {
    fprintf(file, "For a headache:\n");
    fprintf(file, "- Rest in a quiet, dark room to help reduce sensitivity to light and noise.\n");
    fprintf(file, "- Apply a cold or warm compress to your forehead or neck.\n");
    fprintf(file, "- Consider taking over-the-counter pain relievers, such as acetaminophen, ibuprofen, or aspirin.\n");
    fprintf(file, "- Stay hydrated by drinking water.\n");
    fprintf(file, "\n");

    // Add medication schedule to the calendar
    fprintf(calendar, "Medication Schedule for Headache:\n");
    fprintf(calendar, "Day 1-3: Take 1 tablet of acetaminophen every 4-6 hours as needed for headache.\n");
    fprintf(calendar, "Day 1-3: Apply a cold compress to the forehead for 15 minutes every hour.\n");
    fprintf(calendar, "\n");
}

// Function to handle instructions for a stomachache
void handleStomachache(FILE *file, FILE *calendar) {
    fprintf(file, "For a stomachache:\n");
    fprintf(file, "- Avoid solid foods until you feel better. Stick to clear fluids, such as water, broth, or herbal tea.\n");
    fprintf(file, "- Consider taking over-the-counter medications, such as antacids or anti-diarrheal medications, to relieve symptoms.\n");
    fprintf(file, "- Apply a warm compress to your stomach to help ease discomfort.\n");
    fprintf(file, "- If symptoms persist or worsen, consult a healthcare professional.\n");
    fprintf(file, "\n");

    // Add medication schedule to the calendar
    fprintf(calendar, "Medication Schedule for Stomachache:\n");
    fprintf(calendar, "Day 1-2: Avoid solid foods and stick to clear fluids.\n");
    fprintf(calendar, "Day 1-3: Take 2 tablets of antacid after meals as needed for stomach discomfort.\n");
    fprintf(calendar, "\n");
}

// Function to handle instructions for other diseases
void handleOther(FILE *file, FILE *calendar, const char *disease) {
    fprintf(file, "Sorry, we don't have specific instructions for %s.\n", disease);
    fprintf(file, "Please consult a healthcare professional for proper diagnosis and treatment.\n");
    fprintf(file, "\n");

    // Add a generic medication schedule to the calendar
    fprintf(calendar, "Generic Medication Schedule:\n");
    fprintf(calendar, "Day 1-7: Follow the instructions provided by your healthcare professional.\n");
    fprintf(calendar, "\n");
}