/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of the integer pointed to by iptr*/
     printf("Value of int pointed to by iptr is %d\n", *iptr);
     /*Print the address pointed to by iptr*/
     printf("Address pointed to by iptr %p\n", iptr);
     /*Print the address of iptr itself*/
     printf("Address of iptr %p\n", &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 7;
    /*print the address of x*/
    printf("Address of x is %p\n", &x);
    /*Call fooA() with the address of x*/
    fooA(&x);
    /*print the value of x*/
    printf("Value of x is %d\n", x);
    return 0;
}
