/* CS261- Assignment 1 - Q.5*/
/* Name: Keeley Abbott and Theodore Duchow-Pressley
 * Date: 2015 April, 8
 * Solution description: reads a word from the keyboard using scanf
 						 converts it to StUdLy CaPs 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
