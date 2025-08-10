// count total number of words in a string.

#include <stdio.h>
#include <string.h>

int main(){
    char s[100];  
    int i, words = 0;
 
    printf("Enter a string: ");
    gets(s);
     
    for(i = 0; s[i]; i++){
    	if(s[i] == 32) // ascii number of ' ' = 32
    	words++;
 	}
 	if(i > 0) words++;

    printf("Total number of words: %d\n", words);
}