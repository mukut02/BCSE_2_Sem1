/*
2. Implement a one dimensional array of integers where array size of the array will be provided during runtime. 
Accept the value for the elements and print those using pointers.

Name : Mukut Chatterjee
Roll : 002410501007
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int size;
    scanf("%d",&size);
    int *p=(int *)malloc(size*sizeof(int)); // dynamic allocation during run time

    for(int i=0;i<size;++i){
        scanf("%d",p+i); // input
    }
     
    for(int i=0;i<size;++i){
        printf("%d\n", *(p+i)); // output
    }
}
