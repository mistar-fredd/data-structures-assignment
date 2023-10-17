#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int registration;
    float grades[5];
};

// Function to input student data
void inputStudentData(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter student name %d: ", i + 1);
        scanf("%s", students[i].name);

        printf("Enter registration number for student %d: ", i + 1);
        scanf("%d", &students[i].registration);

        printf("Enter grades for the following units for student %d:\n", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("Enter grade for unit %d: ", j + 1);
            scanf("%f", &students[i].grades[j]);
        }
    }
}

// Function to display a specific student's information
void displayStudentInfo(struct Student students[], int n, int registration) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].registration == registration) {
            printf("Name: %s\n", students[i].name);
            printf("Registration Number: %d\n", students[i].registration);
            printf("Grades: ");
            for (int j = 0; j < 5; j++) {
                printf("%.2f ", students[i].grades[j]);
            }
            printf("\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with registration number %d not found.\n", registration);
    }
}

int main() {
    int n = 5; // You can change this to the desired number of students
    struct Student students[n];

    inputStudentData(students, n);

    // Allow the user to search for a specific student's information
    int searchRegistration;
    printf("Enter a student's registration number to search for: ");
    scanf("%d", &searchRegistration);

    displayStudentInfo(students, n, searchRegistration);

    return 0;
}


