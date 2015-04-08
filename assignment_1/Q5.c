/* CS261- Assignment 1 - Q.5*/
/* Name: 
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void studly(char* word){
     /*Convert to studly caps*/
	int len = strlen(word);
	for (int i = 0; i < len; ++i){
		if (i%2 == 0){
			word[i] = toupper(word[i]);
		}else{
			word[i] = tolower(word[i]);
		}
	}
}

int main(){
	char word[100];
    /*Read word from the keyboard using scanf*/
    printf("Enter a word no bigger than 100 characters: ");
    scanf("%s", word);
    /*Call studly*/
    studly(word);
    /*Print the new word*/
    printf("%s\n", word);
    return 0;
}
