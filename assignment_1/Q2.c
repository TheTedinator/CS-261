/* CS261- Assignment 1 - Q.2*/
/* Name: Keeley Abbott and Theodore Duchow-Pressley
   Date: 2015 April, 6
   Solution description: main() declares and sets integers x, y, and z to 7,
                         8, and 9 respectively. Prints the values of x, y, and
                         z. Passes foo(int *a, int *b, int c), the addresses of
                         x and y, and the value of z. foo(int* a, int* b, int c)
                         doubles the value of the first integer, halves the
                         value of the second integer, and sets the value of the
                         third integer to the sum of the first and second. Back
                         in main(), prints the value returned by foo, and
                         finally prints the values of x, y, and z.
*/

#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
  /* Set a to double its original value */
  *a = *a * 2;

  /* Set b to half its original value */
  *b = *b / 2;

  /* Assign a + b to c */
  c = *a + *b;

  /* Return c */
  return c;
}

int main(){
  /* Declare three integers x,y and z and initialize them to 7, 8, 9
     respectively */
  int x = 7, y = 8, z = 9;

  /* Print the values of x, y and z */
  printf("Value of x: %d\nValue of y: %d\nValue of z: %d\n", x, y, z);

  /* Call foo() appropriately, passing x,y,z as parameters */
  int val = foo(&x, &y, z);

  /* Print the value returned by foo */
  printf("Value of val: %d\n", val);

  /* Print the values of x, y and z again */
  printf("Value of x: %d\nValue of y: %d\nValue of z: %d\n", x, y, z);

  /* Is the return value different than the value of z?  Why? */
  /* The return value is different than the value of z, because z was
     passed-by-value into foo, instead of by simulated pass-by-reference
     like x and y. Effectively what happens in this case is the VALUE of 9
     is used and then modified by foo, while the value of z remains
     unchanged, because foo was never given a way to access it. */
  return 0;
}
