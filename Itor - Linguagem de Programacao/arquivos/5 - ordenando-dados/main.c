#include <stdio.h>
#include <string.h>

#define FILENAME "alunos.csv"

typedef struct {
    char  name[50];
    float grades[4];
    float average;
} Student;

int importStudents(FILE *file, Student *students, int *i);
void calculateAverage(Student *students, int studentsQty);
void printStudents(Student *students, int studentsQty);

int main() {

    FILE *file = fopen(FILENAME, "r");
    int studentsQty = -1, i = 0;    // Index

    if (file == NULL) {
        printf("Error.\n");
        return 1;
    }

    fscanf(file, "%d\n", &studentsQty);

    Student students[studentsQty];

    importStudents(file, students, &i);

    calculateAverage(students, studentsQty);

    printStudents(students, studentsQty);

    fclose(file);

    return 0;
}

int importStudents(FILE *file, Student *students, int *i) {
    while (fscanf(file, "%[^,],%f,%f,%f,%f\n", students[*i].name, &students[*i].grades[0], &students[*i].grades[1], &students[*i].grades[2], &students[*i].grades[3]) == 5) {
        (*i)++;
    }
    return *i;
}

void calculateAverage(Student *students, int studentsQty) {

    for (int j=0; j<studentsQty; j++) {
        students[j].average = 0;
        for (int k=0; k<4; k++) {
            students[j].average += students[j].grades[k];
        }
        students[j].average /= 4;
    }

    return;
}

void printStudents(Student *students, int studentsQty) {

    for (int j=0; j<studentsQty; j++) {
        printf("Student: %-20s | Average: %-5.2f\n", students[j].name, students[j].average);
    }

    return;
}