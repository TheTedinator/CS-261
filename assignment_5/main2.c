#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "dynamicArray.h"
#include "toDoList.h"


/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(TYPE left, TYPE right)
{
    /*FIXME: write this*/
    assert(left != 0); // make sure left isn't NULL
    assert(right != 0); // make sure right isn't NULL
    
    // create pointers for the data
    TaskP l = left;
    TaskP r = right;
    
    // compare function
    if (l->priority < r->priority)
        return -1;
    else if (l->priority > r->priority)
        return 1;
    else
        return 0;
}

/***************************************************************
Print type function defined by user to print their specific type
****************************************************************/


void print_type(TYPE val)
{
  struct Task *v = (struct Task*) val;

  printf("Task: %s  Priority: %d\n", v->description, v->priority);
}




/*  Create a task from the description and the priority

    param:  priority    priority of the task
    param:  desc    	pointer to the description string
    pre:    none
    post:   none
	ret: 	a task with description and priority
*/
TaskP createThing (int priority, char *desc)
{
    /*FIXME: Write this */
    TaskP newTask = (struct Task *)malloc(sizeof(struct Task));
    
    strcpy(newTask->description, desc);
    newTask->priority = priority;
    
    return newTask;
}


int main(int argc, const char * argv[])
{
    TYPE thing;
    
    DynArr *mainList;
    mainList = createDynArr(10);
    
    /* create tasks - arbitrary objects I want to sort from highest to lowest
     */
    thing = createThing(9, "task 1");
    addDynArr(mainList, thing);
    
    thing = createThing(3, "task 2");
    addDynArr(mainList, thing);
    
    thing = createThing(2, "task 3");
    addDynArr(mainList, thing);
    
    thing = createThing(4, "task 4");
    addDynArr(mainList, thing);
    
    thing = createThing(5, "task 5");
    addDynArr(mainList, thing);
    
    thing = createThing(7, "task 6");
    addDynArr(mainList, thing);
    
    thing = createThing(8, "task 7");
    addDynArr(mainList, thing);
    
    thing = createThing(6, "task 8");
    addDynArr(mainList, thing);
    
    thing = createThing(1, "task 9");
    addDynArr(mainList, thing);
    
    thing = createThing(0, "task 10");
    addDynArr(mainList, thing);
    
    
    printf("Before Sort Called \n");
    printDynArr(mainList, print_type);
    
    /* sort tasks */
    sortHeap(mainList, compare);
    
    printf("After Sort Called \n");
    
    /* print sorted tasks from the dynamic array */
    printDynArr(mainList, print_type);
    
    deleteDynArr(mainList);
    
    return 0;
}