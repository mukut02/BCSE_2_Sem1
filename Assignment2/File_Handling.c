/*
1. Write a program to store student information in a file and to do the following operations. Information
includes roll, name, and score in five subjects. Use may like to add record (ensure roll number is unique),
display all records showing roll, name and total score. User may search for the record against a roll. User
may edit the details a record. User may delete record. Deletion may be logical (by some means indicate it is
an invalid record and to be avoided in processing) and physical (file will not have the record).

Name: Mukut Chatterjee
Roll: 002410501007

*/
#include <stdio.h>
#include <string.h>

typedef struct student{
    int roll;
    char name[50];
    int marks[5];
} student;

void AddStudent(){
   student s;
   FILE *fp = fopen("student.txt","a+");
   if (!fp) { printf("File error!\n"); return; }

   printf("Enter roll: "); scanf("%d",&s.roll);
   getchar();
   printf("Enter name: "); fgets(s.name,50,stdin);
   s.name[strcspn(s.name, "\n")] = 0;

   printf("Enter marks of 5 subjects: "); 
   for(int i=0;i<5;++i) scanf("%d",&s.marks[i]);
   
   rewind(fp);
   student curr;
   while (fscanf(fp, "%d %s %d %d %d %d %d",
                 &curr.roll, curr.name,
                 &curr.marks[0], &curr.marks[1],
                 &curr.marks[2], &curr.marks[3], &curr.marks[4]) == 7) 
   {
      if(curr.roll == s.roll){
         printf("Already Exists!!\n");
         fclose(fp);
         return;
      }
   }

   fprintf(fp, "%d %s %d %d %d %d %d\n",
           s.roll, s.name,
           s.marks[0], s.marks[1], s.marks[2],
           s.marks[3], s.marks[4]);
   fclose(fp);
   printf("Record added\n");
}

void Display(){
    FILE *fp = fopen("student.txt", "r");
    if (!fp) { printf("No records found.\n"); return; }

    student s;
    printf("\n--- Records ---\n");
    while (fscanf(fp, "%d %s %d %d %d %d %d",
                  &s.roll, s.name,
                  &s.marks[0], &s.marks[1],
                  &s.marks[2], &s.marks[3], &s.marks[4]) == 7) 
    {
        int total = 0;
        for(int i=0;i<5;i++) total += s.marks[i];
        if(s.roll!=-1) printf("Roll: %d, Name: %s, Total: %d\n",
               s.roll, s.name, total);
    }
    fclose(fp);
}

void Search(){
    student s;
    FILE *fp = fopen("student.txt","a+");
    int roll;
    printf("Enter roll: "); scanf("%d",&roll);
    while( (fscanf(fp, "%d %s %d %d %d %d %d",
        &s.roll, s.name,
        &s.marks[0], &s.marks[1], &s.marks[2], &s.marks[3], &s.marks[4] 
     )==7)
    ){
        if(s.roll==roll){
            printf("Student Found :Roll -> %d, Name -> %s\n", s.roll, s.name);
            return;
        }
    }

    printf("Not found!! \n");
}

void Edit(){
    int roll;printf("Enter the roll to edit:\n");scanf("%d",&roll);
    student s;
    FILE *fp = fopen("student.txt","a+");
    FILE *temp = fopen("temp.txt","a+");
    while (fscanf(fp, "%d %s %d %d %d %d %d",
                  &s.roll, s.name,
                  &s.marks[0], &s.marks[1], &s.marks[2], &s.marks[3], &s.marks[4]
                  ) == 7) {
        if(s.roll == roll){
            printf("Editing record for %s\n", s.name);
            getchar();
            printf("Enter new name: ");
            fgets(s.name, 50, stdin);
            s.name[strcspn(s.name, "\n")] = 0;
            printf("Enter 5 new marks: ");
            for(int i=0;i<5;i++) scanf("%d", &s.marks[i]);
        }
        fprintf(temp, "%d %s %d %d %d %d %d\n",
                s.roll, s.name,
                s.marks[0], s.marks[1], s.marks[2], s.marks[3], s.marks[4]);
    }
    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");
    printf("Done\n");
}

void LogicalDelete() {
    int roll;printf("Enter roll: ");scanf("%d",&roll);

    FILE *fp = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) { printf("File error!\n"); return; }

    student s;
    int found = 0;
   // marking the student's roll -1 -> meaning deleted entry
    while (fscanf(fp, "%d %s %d %d %d %d %d",
                  &s.roll, s.name,
                  &s.marks[0], &s.marks[1],
                  &s.marks[2], &s.marks[3], &s.marks[4]) == 7) {
        if (s.roll == roll) {
            found = 1;
            s.roll=-1;
        }
        fprintf(temp, "%d %s %d %d %d %d %d\n",
                s.roll, s.name,
                s.marks[0], s.marks[1], s.marks[2],
                s.marks[3], s.marks[4]);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) printf("Record logically deleted (roll set -1).\n");
    else printf("Record not found.\n");
}
void PhysicalDelete(int roll) {
    FILE *fp = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) { printf("File error!\n"); return; }

    student s;
    int found = 0;

    while (fscanf(fp, "%d %s %d %d %d %d %d",
                  &s.roll, s.name,
                  &s.marks[0], &s.marks[1],
                  &s.marks[2], &s.marks[3], &s.marks[4]) == 7) {
        if (s.roll ==roll) {
            found = 1;
            continue; 
        }
        fprintf(temp, "%d %s %d %d %d %d %d\n",
                s.roll, s.name,
                s.marks[0], s.marks[1], s.marks[2],
                s.marks[3], s.marks[4]);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) printf("Record physically deleted.\n");
    else printf("Record not found.\n");
}

void PhysicalDelete(int roll) {
    FILE *fp = fopen("student.txt", "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!fp || !temp) { printf("File error!\n"); return; }

    student s;
    int found = 0;

    while (fscanf(fp, "%d %s %d %d %d %d %d",
                  &s.roll, s.name,
                  &s.marks[0], &s.marks[1],
                  &s.marks[2], &s.marks[3], &s.marks[4]) == 7) {
        if (s.roll == roll || s.roll==-1) {
            found = 1;
            continue; // skip
        }
        fprintf(temp, "%d %s %d %d %d %d %d\n",
                s.roll, s.name,
                s.marks[0], s.marks[1], s.marks[2],
                s.marks[3], s.marks[4]);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if (found) printf("Record physically deleted.\n");
    else printf("Record not found.\n");
}

int main(){
    int choice, roll;
    while(1){
        printf("\n--- Student Management (Text File) ---\n");
        printf("1. Add\n2. Display All\n3. Search\n4. Edit\n5. Logical Delete\n6. Physical Delete\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: AddStudent(); break;
            case 2: Display(); break;
            case 3: Search(); break;
            case 4: Edit(); break;
            case 5: LogicalDelete(); break;
            case 6: physicalDelete(); break;
            case 7: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
