/* CS261- Assignment 1 - Q.4 */
/* Name: Keeley Abbott and Theodore Duchow-Pressley
   Date: 2014 April 6
   Solution description: Create an array of struct students, assign them all
                         randomly generated IDs and scores, then sort them from
                         smallest to largest scores. Finally print out both the
                         IDs and scores before and after sorting.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct student{
  int id;
  int score;
};

void sort(struct student* students, int n){
  /* Sort the n students based on their score */
  /* Remember, each student must be matched with their original score
     after sorting
  */
  struct student curr;

  for(int i = 0; i < n; i++){
    students[i] = curr;
    for(int j = (i + 1); j < n; j++){
      if(students[j].score < curr.score){
        students[i] = students[j];
        students[j] = curr;
        curr = students[i];
      }
    }
  }
}

int main(){
  srand(time(NULL));

  /* Declare an integer n and assign it a value. */
  int n = 20;

  /* Allocate memory for n students using malloc. */
  struct student *Students = malloc(sizeof(struct student)*n);

  /* Generate random IDs and scores for the n students, using rand(). */
  for(int i = 0; i < n; i++){
      Students[i].id = i + 1;
      Students[i].score = rand()%100;
    }

  /* Print the contents of the array of n students. */
  printf("Unsorted:\n");
  for(int i = 0; i < n; i++){
      printf("ID%d Score%d\n", Students[i].id, Students[i].score);
    }
  printf("\n");

  /* Pass this array along with n to the sort() function */
  sort(Students, n);

  /* Print the contents of the array of n students. */
  printf("Sorted:\n");
  for(int i = 0; i < n; i++){
      printf("ID%d Score%d\n", Students[i].id, Students[i].score);
    }

  return 0;
}
