/*
7. Maintain a list to store roll, name and score of students. As and when required student record may be added or deleted. 
Also, the list has to be displayed. Design suitable functions for different operations.  

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Assuming any student as name of max len 49

Used Linked List implementation to store the info where 
each node is student info
*/

// student Node
typedef struct Student{
    int roll;
    char name[50];
    float score;
    struct Student* next;
} Student;


Student* createStudent(int roll, char name[], float score) {
    // new Entry insert
    // allocated space using malloc
    Student* newNode = (Student*)malloc(sizeof(Student));
    newNode->roll = roll;
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;
    return newNode;
}


void insertStudent(Student** head, int roll, char name[], float score) {
    // head double ptr as head can be changed -> refer SKS sir
    Student* newNode = createStudent(roll, name, score);

    if(*head == NULL){   // empty list
        *head = newNode;
        return;
    }

    Student* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    // End of List reached
    temp->next = newNode;
}


void deleteStudent(Student** head, int roll) {
    Student* temp = *head, *prev = NULL;

    // Empty list
    if(temp == NULL){
        printf("Empty List!\n");
        return;
    }

    // If head needs to be deleted
    if(temp != NULL && temp->roll == roll) {
        *head = temp->next;
        free(temp);
        printf("Record with Roll %d deleted.\n", roll);
        return;
    }

    // Search for student
    while(temp != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }

    // end of list
    if(temp == NULL) {
        printf("Record with Roll %d not found!\n", roll);
        return;
    }

    // Delete node
    prev->next = temp->next;
    free(temp);
    printf("Record with Roll %d deleted.\n", roll);
}


void displayStudents(Student* head) {
    if(head == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    while(head != NULL) {
        printf("%d\t %s\t %f\n", head->roll, head->name, head->score);
        head = head->next;
    }
}

// Driver program
int main() {
    Student* head = NULL;
    int choice, roll;
    char name[50];
    float score;

    do{
        printf("\n--- Student Record Menu ---\n");
        printf("1. Insert Record\n");
        printf("2. Delete Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Roll, Name, Score: ");
                scanf("%d %s %f", &roll, name, &score);
                insertStudent(&head, roll, name, score);
                break;
            case 2:
                printf("Enter Roll to delete: ");
                scanf("%d", &roll);
                deleteStudent(&head, roll);
                break;
            case 3:
                displayStudents(head);
                break;
            case 4:
                printf("Exit Succesful\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } 
    while(choice != 4);

    return 0;
}
