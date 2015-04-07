/* CS261- Assignment 1 - Q. 0*/
/* Name: Keeley Abbott and Theodore Duchow-Pressley
   Date: 2015 April, 6
   Solution description: In main(), the integer x is declared, and set to 0,
                         the address of x is then printed, and then passed to
                         the function fooA(int* iptr). In fooA(int* iptr), the
                         value pointed to by iptr is printed, the address
                         pointed to by iptr is printed, and the address of
                         iptr is printed before concluding the function.
                         Finally, in main(), the value of x is printed and 0
                         is returned.
*/

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr)
{
     /* Print the value of the integer pointed to by iptr */
     printf("Value of int pointed to by iptr is %d\n", *iptr);

     /* Print the address pointed to by iptr */
     printf("Address pointed to by iptr %p\n", iptr);

     /* Print the address of iptr itself */
     printf("Address of iptr %p\n", &iptr);
}

int main()
{
    /* Declare an integer x */
    int x = 0;

    /* Print the address of x */
    printf("Address of x is %p\n", &x);

    /* Call fooA() with the address of x */
    fooA(&x);

    /* Print the value of x */
    printf("Value of x is %d\n", x);
    return 0;
}
