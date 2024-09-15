#include <stdio.h>
#include <string.h>

#define MAX_PROFESSORS 10

int ncmain() {
     // Struct to hold professor details
    typedef struct {
        char name[50];
        char email[50];
        char phone[15];
        char department[50];
    } Professor;

    // Array of professors
    Professor professors[MAX_PROFESSORS] = {
        {"Dr. Arijit Roy", "arijitroy@iitp.ac.in", "06115-2338336","Computer Science"},
        {"Dr. Satendra Kumar", "satendra@iitp.ac.in", "06115-2338332","Computer Science"},
        {"Prof. Preetam Kumar", "pkumar@iitp.ac.in", "06115-2338048","Electrical"},
        {"Dr. Ahmad Ali","ali@iitp.ac.in","06115-2338044","Electrical"},
        {"Dr. Rishi Raj","rraj@iitp.ac.in","06115-2338166","Mechanical"},
        {"DR. Sunil Kumar Singh","sunils@iitp.ac.in","06115-2338164","Mechanical"},
        {"Prof.T.N.Singh","director@iitp.ac.in","06115-2338001","Civil"},
        {"Dr. Pradhi Rajeev","pradhi@iitp.ac.in","06115-2338173","Civil"},
        {"Prof. Prolay Das","prolay@iitp.ac.in","06115-2338057","Chemical"},
    };


    int choice;
    
    while(1){
        printf("\nProfessors name :\n");
        printf("1. Dr. Arijit Roy\n");
        printf("2. Dr. Satendra Kumar\n");
        printf("3. Prof. Preetam Kumar\n");
        printf("4. DR. Ahmad Ali\n");
        printf("5. Dr. Rishi Raj\n");
        printf("6. Dr. Sunil Kumar Singh\n");
        printf("7. Prof.T.N.Singh\n");
        printf("8. Dr. Pradhi Rajeev\n");
        printf("9. Prof. Prolay Das\n");
        printf("10. Exit\n");


            printf("Choose an option (1-10): ");
            scanf("%d", &choice);

        switch(choice) {
            case 1:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[0].name, professors[0].email, professors[0].phone,professors[0].department);
                   break;
            case 2:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[1].name, professors[1].email, professors[1].phone,professors[1].department);
                   break;
            case 3:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[2].name, professors[2].email, professors[2].phone,professors[2].department);
                   break;
            case 4:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[3].name, professors[3].email, professors[3].phone,professors[3].department);
                   break;
            case 5:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[4].name, professors[4].email, professors[4].phone,professors[4].department);
                   break;
            case 6:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[5].name, professors[5].email, professors[5].phone,professors[5].department);
                   break;
            case 7:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[6].name, professors[6].email, professors[6].phone,professors[6].department);
                   break;
            case 8:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[7].name, professors[7].email, professors[7].phone,professors[7].department);
                   break;
            case 9:printf("Contact details for %s:\nEmail: %s\nPhone: %s\nDepatment : %s\n",
                   professors[8].name, professors[8].email, professors[8].phone,professors[8].department);
                   break;
            case 10:printf("Exiting program.\n");
                return 0;
            default :
                 printf("Professor name not found.\n");

        }

    }
}


     