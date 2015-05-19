#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "toDoList.h"


int main (int argc, const char * argv[])
{
    TaskP newTask;
    TaskP firstTask;
    char desc[TASK_DESC_SIZE], filename[50], *nlptr;
    int priority;
    char cmd = ' ';
    FILE *filePointer;
    DynArr* mainList = createDynArr(10);

    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
               );
        /* get input command (from the keyboard) */
        cmd = getchar();
        
        /* Fixme:  Your logic goes here! */
        switch (cmd)
        {
            case 'l': // load the to-do list
                printf("Please enter the filename: ");
                if (fgets(filename, sizeof(filename), stdin) != 0)
                {
                    nlptr = strchr(filename, '\n'); // remove the trailing newline
                    if (nlptr)
                        *nlptr = '\0';
                }
                filePointer = fopen(filename, "r"); /// open the file
                if (filePointer == 0)
                {
                    fprintf(stderr, "Cannot open %s\n", filename);
                    break;
                }
                loadList(mainList, filePointer); // load the list from the file
                fclose(filePointer); // close the file
                printf("The list has been successfully loaded from the file.\n\n");
                break;
                
            case 's': // save the to-do list
                if (sizeof(mainList) > 0)
                {
                    printf("Please enter the filename: "); // get the filename from the user input
                    if (fgets(filename, sizeof(filename), stdin) != 0)
                    {
                        nlptr = strchr(filename, '\n'); // remove trailing newline
                        if (nlptr)
                            *nlptr = '\0';
                    }
                    filePointer = fopen(filename, "w");
                    if (filePointer == 0)
                    {
                        fprintf(stderr, "Cannot open %s\n", filename);
                        break;
                    }
                    saveList(mainList, filePointer); // save the list to the file
                    fclose(filePointer); // close the file
                    printf("The list has been successfully saved to the file.\n\n");
                }
                else
                    printf("Cannot save an empty list.\n\n");
                break;
                
            case 'a': // add a new task
                printf("Please enter the task description: ");
                if (fgets(desc, sizeof(desc), stdin) != 0)
                {
                    nlptr = strchr(desc, '\n'); // remove trailing newline
                    if (nlptr)
                        *nlptr = '\0';
                }
                do
                {
                    printf("Please enter the task priority (0-999): ");
                    scanf("%d", &priority);
                } while (!(priority >= 0 && priority <= 999));
                    
                newTask = createTask(priority, desc);
                addHeap(mainList, newTask, compare);
                printf("The task '%s' has been added to the list.\n\n", desc);
                break;
                
            case 'g': // get the first task to be completed
                if (sizeDynArr(mainList) > 0)
                {
                    firstTask = getMinHeap(mainList);
                    printf("The first tast to complete is: %s\n\n", firstTask->description);
                }
                else
                    printf("No tasks left to complete.\n\n");
                break;
                
            case 'r': // remove the first task
                if (sizeDynArr(mainList) > 0)
                {
                    removeMinHeap(mainList, compare);
                    printf("The first task has been completed.\n\n");
                }
                else
                    printf("No tasks left to complete.\n\n");
                break;
                
            case 'p': // print the list
                if (sizeDynArr(mainList) > 0)
                {
                    printList(mainList);
                }
                else
                    printf("Cannot print an empty list.\n\n");
                break;
                
            case 'e': // exit the program
                printf("Exiting Application...");
                break; 
                
            default:
                printf("Please try again, I didn't understand your input.\n\n"
                       "Press:\n"
                       "'l' to load to-do list from a file\n"
                       "'s' to save to-do list to a file\n"
                       "'a' to add a new task\n"
                       "'g' to get the first task\n"
                       "'r' to remove the first task\n"
                       "'p' to print the list\n"
                       "'e' to exit the program\n"
                       );
                break;
        }

      /* Note: We have provided functions called printList(), saveList() and loadList() for you
         to use.  They can be found in toDoList.c */
    }
    while(cmd != 'e');
    /* delete the list */
    deleteDynArr(mainList);

    return 0;
}
