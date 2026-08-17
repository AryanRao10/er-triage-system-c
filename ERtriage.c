#include <stdio.h>
#include <string.h>

#define MAX_PATIENTS 100

int arrivalIDs[MAX_PATIENTS];
char names[MAX_PATIENTS][50]; // 2D array to hold multiple strings
int ages[MAX_PATIENTS];
int priorities[MAX_PATIENTS]; // 1: Critical, 2: Serious, 3: Standard

int patientCount = 0;
int totalArrivals = 0;

void flushInput() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void printHeader(const char* title) {
    printf("\n======================================================\n");
    printf(" %s\n", title);
    printf("======================================================\n");
}

void sortArrays() {
    for (int i = 0; i < patientCount - 1; i++) {
        for (int j = 0; j < patientCount - i - 1; j++) {
           
            int needsSwap = 0;
           
            // Primary Sort: Lower priority number comes first
            if (priorities[j] > priorities[j+1]) {
                needsSwap = 1;
            }
            // Secondary Sort: Tie-breaker using Arrival ID
            else if (priorities[j] == priorities[j+1] && arrivalIDs[j] > arrivalIDs[j+1]) {
                needsSwap = 1;
            }

            // If they are out of order, swap EVERYTHING in all 4 arrays
            if (needsSwap == 1) {
                // Swap Priority
                int tempPri = priorities[j];
                priorities[j] = priorities[j+1];
                priorities[j+1] = tempPri;

                // Swap Arrival ID
                int tempArr = arrivalIDs[j];
                arrivalIDs[j] = arrivalIDs[j+1];
                arrivalIDs[j+1] = tempArr;

                // Swap Age
                int tempAge = ages[j];
                ages[j] = ages[j+1];
                ages[j+1] = tempAge;

                // Swap Name (using string copy)
                char tempName[50];
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j+1]);
                strcpy(names[j+1], tempName);
            }
        }
    }
}

// 2. Add a new patient
void addPatient() {
    if (patientCount >= MAX_PATIENTS) {
        printf("\n Error: Hospital queue is at maximum capacity!\n");
        return;
    }

    totalArrivals++;
    arrivalIDs[patientCount] = totalArrivals;

    printHeader("REGISTER NEW PATIENT");

    printf("Enter Patient Name: ");
    fgets(names[patientCount], 50, stdin);
    names[patientCount][strcspn(names[patientCount], "\n")] = 0;

    printf("Enter Patient Age: ");
    scanf("%d", &ages[patientCount]);

    do {
        printf("\nSelect Priority Level:\n");
        printf(" [1] Critical (Heart attack, Severe trauma)\n");
        printf(" [2] Serious (Bone fracture, High fever)\n");
        printf(" [3] Standard (Sprain, Minor illness)\n");
        printf("Choice (1-3): ");
        scanf("%d", &priorities[patientCount]);
       
        if(priorities[patientCount] < 1 || priorities[patientCount] > 3) {
            printf(" Invalid input. Please enter 1, 2, or 3.\n");
        }
    } while (priorities[patientCount] < 1 || priorities[patientCount] > 3);

    flushInput();

    patientCount++; // Increase total patient count
    sortArrays(); // Instantly reorganize the waiting list

    printf("\n Patient successfully added to the queue!\n");
}

// 3. View the waiting list
void viewList() {
    printHeader("CURRENT WAITING LIST");

    if (patientCount == 0) {
        printf(" The waiting room is currently empty.\n");
        printf("------------------------------------------------------\n");
        return;
    }

    printf("%-5s | %-20s | %-4s | %-10s\n", "Seq", "Patient Name", "Age", "Priority");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < patientCount; i++) {
        printf("%-5d | %-20s | %-4d | %-10d\n",
            i + 1,
            names[i],
            ages[i],
            priorities[i]);
    }
    printf("------------------------------------------------------\n");
    printf("Total Patients Waiting: %d\n", patientCount);
}

// 4. Treat a patient (Shift arrays)
void treatPatient() {
    printHeader("TREATMENT ROOM");

    if (patientCount == 0) {
        printf(" No patients to treat. The queue is empty.\n");
        return;
    }

    printf(" NOW TREATING: %s (Age: %d) - Priority: %d \n",
        names[0], ages[0], priorities[0]);

    // Shift all remaining patients up by one slot in ALL arrays
    for (int i = 0; i < patientCount - 1; i++) {
        arrivalIDs[i] = arrivalIDs[i+1];
        ages[i] = ages[i+1];
        priorities[i] = priorities[i+1];
        strcpy(names[i], names[i+1]);
    }
   
    patientCount--;
    printf("\n Treatment complete. Patient removed from list.\n");
}

int main() {
    int choice;

    do {
        printHeader("ASAP CITY HOSPITAL DASHBOARD");
        printf("1. Register New Patient\n");
        printf("2. View Waiting List\n");
        printf("3. Treat Next Patient\n");
        printf("4. Exit System\n");
        printf("------------------------------------------------------\n");
        printf("Enter your choice (1-4): ");
       
    if (scanf("%d", &choice) != 1) {
    printf("\n Invalid input! Please enter a number.\n");
    flushInput();
    continue;
    }

    flushInput();

        switch(choice) {
            case 1: addPatient(); break;
            case 2: viewList(); break;
            case 3: treatPatient(); break;
            case 4: printf("\nExiting System\n\n"); break;
            default: printf("\n Invalid choice! Please select 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}