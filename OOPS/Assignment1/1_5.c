/*
5. Store name and age of number of persons (number provided at run time). Collect the data and display
data in the ascending order of age. Implement without using structure. Write functions for memory
allocation of the list, sorting and display of data.

Name : Mukut Chatterjee
Roll : 002410501007
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swapInt(int *x,int *y){
    // swap two integer values
    int temp=*x;
    *x=*y;
    *y=temp;
}

void swapStr(char **x, char **y){
    // swap two string values
    char *temp= *x;
    *x=*y;
    *y=temp;
}

void allocate(char ***names,int** age,int n){
    // dynamic allocation of names, age 
   *names=(char **)malloc(n*sizeof(char*));
   *age=(int *)malloc(n*sizeof(int));
   
   // input
   for(int i=0;i<n;++i){
    char temp[100];
    scanf(" %99[^\n]",temp); // taking name input
    (*names)[i] = malloc((strlen(temp) + 1)*sizeof(char));
    strcpy((*names)[i], temp); // copying it to names[i]
    scanf("%d",&( (*age)[i])); // taking age input
   }

}

void sortByAge(char ***names,int** age,int n){
    // sorting By age
    // Sorting Algorithm used here is Bubble Sort whose time complexity is O(n^2)

    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            if((*age)[j] > (*age)[j+1]){
                swapInt(&( (*age)[j]), &( (*age)[j+1]) ) ;
                swapStr(&( (*names)[j]) , &( (*names))[j+1]);
            }
        }
    }
}

void printInfo(char **names,int *age,int n){
    // output of the given information
    for(int i=0;i<n;++i){
        printf("%s %d\n",names[i], age[i]);
    }
}

int main(){
    int n;scanf("%d",&n);
    getchar();

    char **name;
    int *age;

    allocate(&name, &age, n);
    sortByAge(&name, &age, n);
    printInfo(name, age, n);
}
