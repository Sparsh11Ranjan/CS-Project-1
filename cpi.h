#include <stdio.h>

// Function prototypes
void calculateSPI();
void calculateCPI();

int cpimain()
{
    char ch;
    int choice1;

    // Display program title
    printf("\n\n\t\t\t\t\tSEMESTER  PERFORMANCE  INDEX  CALCULATOR  (SPIC)");

    // Main program loop
    while (1)
    {
        // Display main menu
        printf("\n\n  What do you wish to calculate?");
        printf("\n\n 1. SPI (Semester Performance Index)");
        printf("\n\n 2. CPI (Cumulative Performance Index)");
        printf("\n\n 3. Exit");
        printf("\n\n  Enter your choice : ");
        scanf("%d", &choice1);

        switch (choice1)
        {
        case 1:
            // Calculate SPI
            calculateSPI();
            break;
        case 2:
            // Calculate CPI
            calculateCPI();
            break;
        case 3:
            // Exit the program
            return 0;
        default:
            // Handle invalid choices
            printf("\nEnter a valid choice.\n");
            break;
        }

        // Ask if user wants to calculate more or exit
        printf("\n\n  Do you wish to calculate more? (y/n) : ");
        scanf(" %c", &ch);
        if (ch != 'y')
            break;
    }

    return 0;
}

void calculateSPI()
{
    int choice2, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    float p1 = 8, p2 = 6, p3 = 5, p4 = 3, x1;

    // Get semester choice from user
    printf("\n\n  Enter your semester : ");
    printf("\n\n  1. 1st");
    printf("\n\n  2. 2nd");
    printf("\n\n Enter your choice : ");
    scanf("%d", &choice2);

    switch (choice2)
    {
    case 1:
        // Calculate SPI for first semester
        printf("\n\n  Enter your pointer in the following courses :  ");
        printf("\n\n 1. Mathematics-1 : ");
        scanf("%d", &n1);
        printf("\n 2. Introductory Chemistry : ");
        scanf("%d", &n2);
        printf("\n 3. Communicative English for Engineers  : ");
        scanf("%d", &n3);
        printf("\n 4. Engineering Drawing : ");
        scanf("%d", &n4);
        printf("\n 5. Chemistry Laboratory : ");
        scanf("%d", &n5);
        printf("\n 6. Mechanical Workshop : ");
        scanf("%d", &n6);

        x1 = ((n1 * p1) + (n2 * p1) + (n3 * p2) + (n4 * p3) + (n5 * p4) + (n6 * p4)) / 33;
        printf("\n  Your spi for the first semester is %0.2f.", x1);
        break;

    case 2:
        // Calculate SPI for second semester
        printf("\n\n  Enter your pointer in the following courses : ");
        printf("\n\n 1. Mathematics - II : ");
        scanf("%d", &n1);
        printf("\n 2. Engineering Mechanics : ");
        scanf("%d", &n2);
        printf("\n 3. Physics : ");
        scanf("%d", &n3);
        printf("\n 4. Basic Electronics : ");
        scanf("%d", &n4);
        printf("\n 5. Introduction to Computing : ");
        scanf("%d", &n5);
        printf("\n 6. Bio : ");
        scanf("%d", &n6);
        printf("\n 7. Environmental : ");
        scanf("%d", &n7);
        printf("\n 8. Physics Laboratory : ");
        scanf("%d", &n8);
        printf("\n 9. Basic Electronics Laboratory : ");
        scanf("%d", &n9);
        printf("\n 10. Computing Laboratory : ");
        scanf("%d", &n10);

        x1 = ((n1 * p1) + (n2 * p1) + (n3 * p1) + (n4 * p1) + (n5 * p2) + (n6 * p4) + (n7 * p4) + (n8 * p4) + (n9 * p4) + (n10 * p4)) / 53;
        printf("\n  Your spi for the second semester is %0.2f.", x1);
        break;

    default:
        printf("\nEnter a valid choice.\n");
        break;
    }
}

void calculateCPI()
{
    float A[10], B[10], x2 = 0, x3;
    int i, j, c = 0;

    // Get SPI values for two semesters
    for (i = 1; i < 3; i++)
    {
        printf("\n  Enter your spi in semester %d : ", i);
        scanf("%f", &A[i]);
    }

    // Define credit points for each semester
    B[0] = 33;
    B[1] = 53;

    // Calculate CPI
    for (i = 0; i < 2; i++)
    {
        c += B[i];
    }
    for (i = 1, j = 0; i <= 3; i++, j++)
    {
        x2 += A[i] * B[j];
    }
    x3 = x2 / c;

    // Display CPI
    printf("\n  Your expected CPI is %0.2f.", x3);
}
