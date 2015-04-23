#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>


void test(int prop, char* message) {
    printf("%s: ", message );
    if (prop){
        printf("Success!\n");
    }else
        printf("**Failure**\n" );
}


int main(int argc, char* argv[]) {
    
    struct linkedList *ll = createLinkedList();
    
    test(sizeLinkedList(ll) == 0, "Just created, size should be 0");
    test(isEmptyList(ll), "Should be empty as well");
    
    printf("\nTesting addBackList...\n");
    printf("Adding 4 to back...\n");
    addBackList(ll, 4);
    printf("Adding 2 to back...\n");
    addBackList(ll, 2);
    test(sizeLinkedList(ll) == 2, "Added two elements to the back");
    printf("The lists contents:\n");
    printList(ll);
    
    printf("\nTesting addFrontList...\n");
    printf("Adding 32 to front...\n");
    addFrontList(ll, 32);
    printf("Adding 7 to front...\n");
    addFrontList(ll, 7);
    test(sizeLinkedList(ll) == 4, "Added two elements to the front");
    printf("The lists contents:\n");
    printList(ll);
    
    test(frontList(ll) == 7, "\nFront should be 7");
    test(backList(ll) == 2, "Back should be 2");
    test(containsList(ll, 7), "List contains 7");
    test(containsList(ll, 32), "List contains 32");
    test(containsList(ll, 4), "List contains 4");
    test(containsList(ll, 2), "List contains 2");
    
    printf("\nTesting removeFrontList...\n");
    printf("Removing 7 from front...\n");
    removeFrontList(ll);
    test(sizeLinkedList(ll) == 3, "Removed one element");
    test(frontList(ll) == 32, "Front should be 32");
    printf("The lists contents:\n");
    printList(ll);
    
    printf("\nTesting removeBackList...\n");
    printf("Removing 2 from back...\n");
    removeBackList(ll);
    test(sizeLinkedList(ll) == 2, "Removed one element");
    test(backList(ll) == 4, "Back should be 4");
    printf("The list contents:\n");
    printList(ll);
    
    printf("\nTesting removeList...\n");
    printf("Removing 32 from list...\n");
    removeList(ll, 32);
    test(sizeLinkedList(ll) == 1, "Removed one element");
    printf("Removeing 4 from list...\n");
    removeList(ll, 4);
    test(isEmptyList(ll), "List is now empty");
    printf("Remove from empty list...\n");
    removeFrontList(ll);
    removeBackList(ll);
	return 0;
}


