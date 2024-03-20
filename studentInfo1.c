#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_Student_number 10
#define MAX_ID_LENGTH 10

struct Student{
    char id[MAX_ID_LENGTH];
    float cgpa;
};

void insert_Students_Info(struct Student students[], int* count);
void display_Students_Info(struct Student students[], int count);
void edit_Student_Info(struct Student students[], int count, char id[]);
void search_Student_Info(struct Student students[], int count, char id[]);

int main(){
    struct Student students[MAX_Student_number];
    int count=0;
    int choice;
    char id[MAX_ID_LENGTH];
    do{
        printf("Menu\n");
        printf("1. Enter for insert\n");
        printf("2. Enter for display\n");
        printf("3. Enter for edit a student's info\n");
        printf("4. Enter for search\n");
        printf("5. Enter for exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
            insert_Students_Info(students, &count);
            break;
            case 2:
            display_Students_Info(students, count);
            break;
            case 3:
            printf("\nEnter the student's ID to edit: ");
            scanf("%s", id);
            edit_Student_Info(students, count, id);
            break;
            case 4:
            printf("\nEnter the student's ID to search: ");
            scanf("%s", id);
            search_Student_Info(students, count, id);
            break;
            case 5:
            printf("Exiting...\n");
            break;
            default:
            printf("Invalid your choice!\n");
            break;
        }
    }while(choice!=5);
    return 0;
}

void insert_Students_Info(struct Student students[], int* count){
    if (*count < MAX_Student_number)
    {
        printf("\nEnter Student ID: ");
        scanf("%s", students[*count].id);
        printf("Enter Student CGPA: ");
        scanf("%f", &students[*count].cgpa);
        (*count)++;
        printf("\nStudent record inserted successfully.\n");
    }
    else
    {
        printf("Cannot insert. Maximum limit reached.\n");
    }
}
void display_Students_Info(struct Student students[], int count){
    printf("\nList of Students:\n");
    printf("ID\t\tCGPA\n");
    for(int i=0; i<count; ++i){
        printf("%s\t\t%.2f\n", students[i].id, students[i].cgpa);
    }printf("\n\n");
}
void edit_Student_Info(struct Student students[], int count, char id[]){
    for(int i=0; i<count; ++i){
        if(strcmp(students[i].id, id)==0){
            printf("Enter new CGPA for student %s: ", id);
            scanf("%f", &students[i].cgpa);
            printf("Record updated successfully.\n");
            return;
        }
    }printf("\n\n");
}
void search_Student_Info(struct Student students[], int count, char id[]){
    for (int i = 0; i < count; i++)
    {
        if (strcmp(students[i].id, id) == 0)
        {
            printf("Student found:\nID: %s, CGPA: %.2f\n", students[i].id, students[i].cgpa);
            return;
        }
    }
    printf("Student with ID %s not found.\n", id);
}