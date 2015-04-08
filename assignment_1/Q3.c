/* Name: Keeley Abbott and Theodore Duchow-Pressley
   Date: 2015 April  6
   Solution description: Creates an array of integers, fills the integers with
                         randomly generated values, and then sorts them from
                         smallest to largest and prints the array before and
                         after sorting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void sort(int* number, int n){
  /* Sort the given array number, of length n */
  int curr;

  for(int i = 0; i < n; i++){
    curr = number[i];
    for(int j = (i + 1); j < n; j++){
      if(number[j] < curr){
        number[i] = number[j];
        number[j] = curr;
        curr = number[i];
      }
    }
  }
}

int main(){
  srand(time(NULL));

  /* Declare an integer n and assign it a value of 20. */
  int n = 20;

  /* Allocate memory for an array of n integers using malloc. */
  int *pArray = malloc(sizeof(int)*n);

  /* Fill this array with random numbers between 0 and n, using rand(). */
  for(int i = 0;i < n; i++){
    pArray[i] = rand()%n;
  }

  /* Print the contents of the array. */
  printf("Unsorted: ");
  for(int i = 0; i < n; i++){
    printf("%d%s", pArray[i], i == n - 1 ? "\n" : " ");
  }

  /* Pass this array along with n to the sort() function. */
  sort(pArray, n);

  /* Print the contents of the array. */
  printf("Sorted: ");
  for(int i = 0; i < n; i++){
    printf("%d%s", pArray[i], i == n - 1 ? "\n" : " ");
  }

  return 0;
}
