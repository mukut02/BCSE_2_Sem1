#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Student{
    int roll;
    char name[50];
    float score;
} Student;


void sort(Student arr[], int n, int (*cmp)(void*, void*)){
    // Bubble Sort TC : O(n^2)
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(cmp(&arr[j], &arr[j+1])>0){
                Student temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Comparison functions
int cmpRollAsc(void* a, void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return s1->roll - s2->roll;
}

int cmpRollDesc(void* a, void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return s2->roll - s1->roll;
}

int cmpScoreAsc(void* a, void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    if(s1->score < s2->score) return -1;
    else if(s1->score > s2->score) return 1;
    else return 0;
}

int cmpScoreDesc(void* a, void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    if(s1->score < s2->score) return 1;
    else if(s1->score > s2->score) return -1;
    else return 0;
}

int cmpNameAsc(void* a, void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return strcmp(s1->name, s2->name);
}

int cmpNameDesc(void* a, void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;
    return strcmp(s2->name, s1->name);
}

int main(){
    int n;
    printf("Enter number of students: ");scanf("%d",&n);

    Student *students = (Student *)malloc(sizeof(Student)*n);
    
    
    // INPUT
    for(int i=0;i<n;i++){
        printf("Enter Roll, Name, Score: ");
        scanf("%d %s %f",&students[i].roll, students[i].name, &students[i].score);
    }

    sort(students, n, cmpNameAsc);

    printf("\nStudents sorted by Name Ascending:\n");
    for(int i=0;i<n;i++){
        printf("%d %s %f\n", students[i].roll, students[i].name, students[i].score);
    }

    free(students);
    return 0;
}
