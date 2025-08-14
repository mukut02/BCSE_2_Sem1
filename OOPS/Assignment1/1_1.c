/*
1. Write a program that will have an integer variable and a pointer (say, p) pointing to it. 
Also have a pointer to pointer pointing to p. Take the value for the integer variable and print it using p, and pp.

Name : Mukut Chatterjee
Roll : 002410501007
*/

#include<stdio.h>
#include<stdlib.h>

int main(){
    int x;
    scanf("%d",&x);
    int *p;
    p=&x; // single ptr to x
    int **pp; // double ptr to x
    pp=&p;
    printf("%d\n",*p);// x's value by dereferncing p
    printf("%d\n",**pp); // x's value by derefercing pp two times
}
