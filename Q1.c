/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student *mem = malloc(10*sizeof(struct student));
     //assert(mem!=0);
     /*return the pointer*/
     return mem;
}

void generate(struct student* students){
     /*Generate random ID and scores for 10 students, ID being between 1 and 10, scores between 0 and 100*/
     for (int i = 0; i < 10; ++i)
     {
       students[i].id = i+1;
       students[i].score = rand()%100;
     }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

      for (int i = 0; i < 10; ++i)
      {
        printf("ID%d Score%d\n", students[i].id, students[i].score);
      }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min = 100, max = 0, sum = 0;
   for (int i = 0; i < 10; ++i)
   {
     if (students[i].score > max) max = students[i].score;
     if (students[i].score < min) min = students[i].score;
     sum += students[i].score;
   }
   printf("Max: %d\n Min:%d \nAverage:%d\n", max, min, sum/10);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    srand(time(NULL));
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
