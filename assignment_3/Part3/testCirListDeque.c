#include "cirListDeque.h"
#include <stdio.h>
#include <stdlib.h>

void test(int prop, char* message){
	printf("%s:\t\t", message );
	if (prop){
		printf("Success!\n");
	}else
		printf("**Failure**\n" );
}
int main(int argc, char* argv[]) {
        

	struct cirListDeque *dq = createCirListDeque();

	test(sizeCirListDeque(dq) == 0, "Just created, size should equal 0");
	test(isEmptyCirListDeque(dq), "Should be empty");
	addFrontCirListDeque(dq, 2);
	addFrontCirListDeque(dq, 5);

	test(sizeCirListDeque(dq) == 2, "Added two elts to front, 2 and 5.\n size should equal 2");
	printCirListDeque(dq);
	test(frontCirListDeque(dq) == 5, "Front should be 5");
	test(backCirListDeque(dq) == 2, "Back should be 2");

	addBackCirListDeque(dq, 3);
	addBackCirListDeque(dq, 7);

	printCirListDeque(dq);
	test(sizeCirListDeque(dq) == 4, "Added two elts to back, 3 and 7.\n Size should equal 4");
	test(backCirListDeque(dq) == 7, "Back should be 7");
	test(frontCirListDeque(dq) == 5, "Front should be 5");
	test(isEmptyCirListDeque(dq) == 0, "isEmpty should be false");

	reverseCirListDeque(dq);
	printCirListDeque(dq);
	test(frontCirListDeque(dq) == 7, "Reversed list\n. Front should be 7");
	test(backCirListDeque(dq) == 5, "Back should be 5");

	removeFrontCirListDeque(dq);
	printCirListDeque(dq);
	test(sizeCirListDeque(dq) == 3, "Removed elt from front.\n Size should be 3");
	test(frontCirListDeque(dq) == 3, "Front should be 3");

	removeBackCirListDeque(dq);
	test(sizeCirListDeque(dq) == 2, "Removed elt from back.\n Size should be 2");
	printCirListDeque(dq);






	return 0;
}


