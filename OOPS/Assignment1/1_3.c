/*
Q3. WAP to implement array of pointer ,
ptr to ptr uing 2 malloc & 1 malloc, 
ptr to array, 
Name : Mukut Chatterjee
Roll : 002410501007
*/

#include<stdio.h>
#include<stdlib.h>

void arrayofptr(){
     int r,c;
    scanf("%d %d",&r,&c);
    
    // r size array each ptr to size of c
    int *arr[r];

    for(int i=0;i<r; ++i){
        arr[i]=(int *)malloc(c*sizeof(int));
    }
     
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void ptrtoarr(){
     int r,c;
    scanf("%d %d",&r,&c);
    
    int (*arr)[c];
    // ptr to arr method
    arr = malloc(r*sizeof(*arr));
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("\n");

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void ptr2ptr(){
    int r,c;
    scanf("%d %d",&r,&c);
    // using 2 malloc statements
    int **arr = (int **)malloc(r*sizeof(int *));
    for(int j=0;j<c;++j){
        arr[j] = (int *)malloc(c*sizeof(int));
    }
    
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void contiguousptr2ptr(){
    int r,c;
    scanf("%d %d",&r,&c);

    int **p=(int **)malloc(r*sizeof(int *) + r*c*sizeof(int)); 
    // contiguous allocation using 1 malloc statement

    for(int i=0;i<r;++i){
        p[i]=(int *)(p+r + i*c);
    }

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            scanf("%d",&p[i][j]);
        }
    }

    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
   ptr2ptr();
   contiguousptr2ptr();
   arrayofptr();
   ptrtoarr();
}
