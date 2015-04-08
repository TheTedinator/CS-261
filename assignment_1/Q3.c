/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

void sort(int* number, int n){
     /*Sort the given array number , of length n*/ 
     for (int i = 1; i < n; ++i){//insert sort
     	int j = i;
     	while (j > 0 && number[j-1] > number[j]){
     		int t = number[j-1];
     		number[j-1] = number[j];
     		number[j] = t;
     		j--;
     	}
     }    
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int *array = malloc(n*sizeof(int));
    assert(array!=0);

    /*Fill this array with random numbers between 0 and n, using rand().*/
    for (int i = 0; i < n; ++i){
    	array[i] = rand()%n;
    }
    /*Print the contents of the array.*/
    printf("Unsorted: ");
    for (int i = 0; i < n; ++i){
    	printf("%d ", array[i]);
    }

    /*Pass this array along with n to the sort() function.*/
    sort(array, n);

    /*Print the contents of the array.*/    
    printf("\nSorted:   ");
    for (int i = 0; i < n; ++i){
    	printf("%d ", array[i]);
    }
    printf("\n\n");
    return 0;
}
